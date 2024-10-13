/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:13:04 by mafaisal          #+#    #+#             */
/*   Updated: 2023/11/23 08:24:23 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// remove clean from all in makefile
int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed;
	va_list	args;

	printed = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			printed += ft_printarg(format[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			printed++;
			i++;
		}
	}
	va_end(args);
	return (printed);
}
