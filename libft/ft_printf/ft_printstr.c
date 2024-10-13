/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:53:15 by mafaisal          #+#    #+#             */
/*   Updated: 2023/11/23 16:02:49 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(const char *s)
{
	int	i;

	if (!s)
		return (ft_printstr("(null)"));
	i = 0;
	while (s[i])
		i += ft_printchar (s[i]);
	return (i);
}
