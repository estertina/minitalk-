/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:02:44 by esttina           #+#    #+#             */
/*   Updated: 2025/12/06 22:15:17 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_char(va_arg(args, int));
	else if (specifier == 's')
		count += ft_string(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_ptr(va_arg(args, void *));
	else if (specifier == 'x')
		count += ft_hex(va_arg(args, unsigned int));
	else if (specifier == 'u')
		count += ft_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'i' || specifier == 'd')
		count += ft_num(va_arg(args, int));
	else if (specifier == 'X')
		count += ft_hex_upper(va_arg(args, unsigned int));
	else if (specifier == '%')
		count += ft_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		res;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			res = handle_specifier(format[i], args);
			if (res == -1)
				return (va_end(args), -1);
			count += res;
		}
		else
			count += ft_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int i = ft_printf("my printf: %%");
// 	printf("\nog printf: %%");
// 	printf("\n%d\n", i);
// }
