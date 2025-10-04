/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:39:44 by byeolee           #+#    #+#             */
/*   Updated: 2025/03/19 14:07:22 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_counter(unsigned long ptr, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (ptr >= 16)
		hex_counter(ptr / 16, count);
	write(1, &hex[ptr % 16], 1);
	(*count)++;
}

void	hex_counter_lower(unsigned int ptr, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (ptr >= 16)
		hex_counter_lower(ptr / 16, count);
	write(1, &hex[ptr % 16], 1);
	(*count)++;
}

void	hex_counter_upper(unsigned int ptr, int *count)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (ptr >= 16)
		hex_counter_upper(ptr / 16, count);
	write(1, &hex[ptr % 16], 1);
	(*count)++;
}

static void	input_char(char *str, unsigned int n, int len)
{
	if (!str)
		return ;
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

char	*ft_unsigned_itoa(unsigned int n)
{
	int				len;
	unsigned int	i;
	char			*ptr;

	len = 0;
	if (n == 0)
	{
		ptr = (char *)malloc(sizeof(char) * 2);
		if (!ptr)
			return (NULL);
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	i = n;
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	input_char(ptr, n, len);
	return (ptr);
}
