/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:41:47 by ielafi            #+#    #+#             */
/*   Updated: 2024/03/01 09:41:49 by ielafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		ft_print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_digit(va_arg(ap, int), 10, 0);
	else if (specifier == 'u')
		count += ft_print_digit(va_arg(ap, unsigned int), 10, 0);
	else if (specifier == 'x')
		count += ft_print_digit(va_arg(ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += ft_print_digit(va_arg(ap, unsigned int), 16, 1);
	else if (specifier == '%')
		count += ft_print_char('%');
	else if (specifier == 'p')
		count += print_pointer(va_arg(ap, void *));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%' )
			count += print_format(*(++format), ap);
		else
		{
			count += write(1, format, 1);
		}
		++format;
	}
	va_end(ap);
	return (count);
}

int main()
{
	int count;
	int i;

	ft_printf("test C : %c\n", 'c');
	printf("test C : %c\n", 'c');
	
	ft_printf("test D : %d\n", 1);
	printf("test D : %d\n", 1);
	
	ft_printf("test I : %i\n", 15);
	printf("test I : %i\n", 15);
	
	ft_printf("test S : %s\n", "string");
	printf("test S : %s\n", "string");
	
	ft_printf("test U : %u\n", 1500);
	printf("test U : %u\n", 1500);
	
	ft_printf("test X : %X\n", 15000000);
	printf("test X : %X\n", 15000000);
	
	ft_printf("test x : %x\n", 15000000);
	printf("test x : %x\n", 15000000);

	ft_printf("test poucent : %%\n");
	printf("test pourcent : %%\n");

	ft_printf("L'adresse de i est : %p\n", &i);
	printf("L'adresse de i est : %p\n", &i);
	return 0;
}