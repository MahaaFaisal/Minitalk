/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:13:47 by mafaisal          #+#    #+#             */
/*   Updated: 2023/11/23 15:51:33 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printarg(char c, va_list args);
int	ft_printchar(char c);
int	ft_printstr(const char *s);
int	ft_printnbr(int n);
int	ft_printunbr(unsigned int n);
int	ft_printhex(unsigned long long num, char hex);

#endif
