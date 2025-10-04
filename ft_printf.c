/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:13:27 by byeolee           #+#    #+#             */
/*   Updated: 2025/03/19 14:07:21 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_percent(va_list args, const char **format, int *count)
{
	(*format)++;
	if (**format == 'c')
		ft_printf_c(args, count);
	else if (**format == 's')
		ft_printf_s(args, count);
	else if (**format == 'p')
		ft_printf_p(args, count);
	else if (**format == 'd')
		ft_printf_d(args, count);
	else if (**format == 'i')
		ft_printf_i(args, count);
	else if (**format == 'u')
		ft_printf_u(args, count);
	else if (**format == 'x')
		ft_printf_lx(args, count);
	else if (**format == 'X')
		ft_printf_ux(args, count);
	else if (**format == '%')
		ft_printf_per(args, count);
	else
		write(1, "", 0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start (args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			ft_printf_percent(args, &format, &count);
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
