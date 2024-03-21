/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:46:43 by ielafi            #+#    #+#             */
/*   Updated: 2024/03/04 14:46:45 by ielafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

int	ft_print_digit(long n, int base, int uppercase)
{
	char	*symbols;

	if (uppercase)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	return (print_digit_helper(symbols, n, base, 0));
}

int	print_digit_helper(char *symbols, long n, int base, int count)
{
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n < base)
	{
		return (count + ft_print_char(symbols[n]));
	}
	else
	{
		count = print_digit_helper(symbols, n / base, base, count);
		return (print_digit_helper(symbols, n % base, base, count));
	}
}
