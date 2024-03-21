/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointeur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:46:43 by ielafi            #+#    #+#             */
/*   Updated: 2024/03/04 14:46:45 by ielafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	print_pointer(void *ptr)
{
	int	count;

	count = write(1, "0x", 2);
	count += ft_print_digit((unsigned long long)ptr, 16, 0);
	return (count);
}
