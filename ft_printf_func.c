/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:24:25 by byeolee           #+#    #+#             */
/*   Updated: 2025/05/28 14:53:38 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(va_list args, int *count)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	(*count)++;
}

void	ft_printf_s(va_list args, int *count)
{
	char	*str;
	int		i;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	write(1, str, ft_strlen(str));
	i = 0;
	while (i < ft_strlen(str))
	{
		(*count)++;
		i++;
	}
}

void	ft_printf_p(va_list args, int *count)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
	}
	else
	{
		write(1, "0x", 2);
		(*count) += 2;
		hex_counter((unsigned long)ptr, count);
	}
}

void	ft_printf_d(va_list args, int *count)
{
	int		num;
	char	*str;
	int		i;
	int		len;

	num = va_arg(args, int);
	str = ft_itoa(num);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	write(1, str, len);
	*count += len;
	free(str);
}

void	ft_printf_i(va_list args, int *count)
{
	int		num;
	char	*str;
	int		i;

	num = va_arg(args, int);
	str = ft_itoa(num);
	if (!str)
		str = "(null)";
	write(1, str, ft_strlen(str));
	i = 0;
	while (i < ft_strlen(str))
	{
		(*count)++;
		i++;
	}
	free(str);
}
