/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:13:23 by byeolee           #+#    #+#             */
/*   Updated: 2025/03/19 14:07:19 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_printf_percent(va_list args, const char **format, int *count);
size_t	ft_strlen(const char *s);
void	ft_printf_c(va_list args, int *count);
void	ft_printf_s(va_list args, int *count);
void	ft_printf_p(va_list args, int *count);
void	ft_printf_d(va_list args, int *count);
void	ft_printf_i(va_list args, int *count);
void	ft_printf_u(va_list args, int *count);
void	ft_printf_lx(va_list args, int *count);
void	ft_printf_ux(va_list args, int *count);
void	ft_printf_per(va_list args, int *count);
void	hex_counter(unsigned long ptr, int *count);
void	hex_counter_lower(unsigned int ptr, int *count);
void	hex_counter_upper(unsigned int ptr, int *count);
char	*ft_unsigned_itoa(unsigned int n);

#endif