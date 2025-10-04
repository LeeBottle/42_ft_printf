/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:27:04 by byeolee           #+#    #+#             */
/*   Updated: 2025/03/19 14:07:50 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_u(va_list args, int *count)
{
	unsigned int	num;
	char			*str;
	unsigned int	i;

	num = va_arg(args, unsigned int);
	str = ft_unsigned_itoa(num);
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
	i = 0;
	while (i < ft_strlen(str))
	{
		(*count)++;
		i++;
	}
	free(str);
}

void	ft_printf_lx(va_list args, int *count)
{
	unsigned int	ptr;

	ptr = va_arg(args, unsigned int);
	hex_counter_lower(ptr, count);
}

void	ft_printf_ux(va_list args, int *count)
{
	unsigned int	ptr;

	ptr = va_arg(args, unsigned int);
	hex_counter_upper(ptr, count);
}

void	ft_printf_per(va_list args, int *count)
{
	write(1, "%", 1);
	(*count)++;
}
