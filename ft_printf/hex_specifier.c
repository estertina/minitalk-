/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:46:34 by esttina           #+#    #+#             */
/*   Updated: 2025/12/06 21:57:25 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned long num)
{
	int		count;
	int		check;
	char	*str;

	count = 0;
	str = "0123456789abcdef";
	if (num >= 16)
	{
		check = ft_hex(num / 16);
		if (check == -1)
			return (-1);
		count += check;
	}
	if (write(1, &str[num % 16], 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_hex_upper(unsigned int num)
{
	int		count;
	int		check;
	char	*str;

	count = 0;
	str = "0123456789ABCDEF";
	if (num >= 16)
	{
		check = ft_hex_upper(num / 16);
		if (check == -1)
			return (-1);
		count += check;
	}
	if (write(1, &str[num % 16], 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_ptr(void *ptr)
{
	int	count;
	int	check;

	count = 0;
	if (!ptr)
		return (write(1, PTR_NULL, PTR_NULL_LEN));
	if (write(1, "0x", 2) == -1)
		return (-1);
	count += 2;
	check = ft_hex((unsigned long)ptr);
	if (check == -1)
		return (-1);
	return (count + check);
}
