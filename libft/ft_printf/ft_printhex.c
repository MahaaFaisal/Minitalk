/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:17:49 by mafaisal          #+#    #+#             */
/*   Updated: 2023/11/22 10:03:08 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long long num, char hex)
{
	char	*lower_x;
	char	*upper_x;
	int		count;

	lower_x = "0123456789abcdef";
	upper_x = "0123456789ABCDEF";
	count = 1;
	if (num > 15)
		count += ft_printhex(num / 16, hex);
	if (hex == 'X')
		ft_printchar(upper_x[num % 16]);
	else if (hex == 'x')
		ft_printchar(lower_x[num % 16]);
	return (count);
}
