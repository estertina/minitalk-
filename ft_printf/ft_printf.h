/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:03:09 by esttina           #+#    #+#             */
/*   Updated: 2025/12/06 22:24:04 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef __APPLE__
#  define PTR_NULL "0x0"
#  define PTR_NULL_LEN 3
# else
#  define PTR_NULL "(nil)"
#  define PTR_NULL_LEN 5
# endif

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	handle_specifier(char specifier, va_list args);
int	ft_char(char c);
int	ft_string(char *s);
int	ft_unsigned(unsigned int num);
int	ft_num(int n);
int	ft_hex(unsigned long num);
int	ft_hex_upper(unsigned int num);
int	ft_ptr(void *ptr);

#endif