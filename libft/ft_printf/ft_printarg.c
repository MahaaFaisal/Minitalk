/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 08:56:20 by mafaisal          #+#    #+#             */
/*   Updated: 2023/11/23 14:14:14 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printarg(char c, va_list args)
{
	if (c == '%')
		return (ft_printchar('%'));
	else if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(args, unsigned int), c));
	else if (c == 'u')
		return (ft_printunbr(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_printstr("0x")
			+ ft_printhex((unsigned long long)va_arg(args, void *), 'x'));
	else
		return (ft_printchar(c));
}
