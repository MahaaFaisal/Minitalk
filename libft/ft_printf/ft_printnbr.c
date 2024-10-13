/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:45:01 by mafaisal          #+#    #+#             */
/*   Updated: 2023/11/23 16:01:27 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
	{
		count += ft_printchar('-');
		count += ft_printchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count += ft_printchar('-');
		n = -n;
	}
	if (n > 9)
		count += ft_printnbr(n / 10);
	ft_printchar((n % 10) + 48);
	return (count);
}
