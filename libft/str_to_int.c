/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:00:09 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/25 12:16:51 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	islong(long num, char c, int sign)
{
	if ((sign == -1 && (num > 214748364
				|| (num == 214748364 && (c - '0') > 8)))
		|| (sign == 1 && (num > 214748364
				|| (num == 214748364 && (c - '0') > 7))))
		return (1);
	else
		return (0);
}

int	str_to_int(const char *str, int *error)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (str[i] < '0' || str[i] > '9')
		*error = 1;
	result = 0;
	while (str[i] != '\0')
	{
		if (islong(result, str[i], sign)
			|| str[i] < '0' || str[i] > '9')
			return (*error = 1, 0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
