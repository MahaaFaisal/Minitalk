/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:46:19 by mafaisal          #+#    #+#             */
/*   Updated: 2023/11/22 10:02:51 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunbr(unsigned int n)
{
	int	count;

	count = 1;
	if (n > 9)
		count += ft_printunbr(n / 10);
	ft_printchar((n % 10) + 48);
	return (count);
}
