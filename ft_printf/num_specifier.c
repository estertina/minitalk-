/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:18:11 by esttina           #+#    #+#             */
/*   Updated: 2025/12/05 01:10:17 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_recursive(unsigned int num)
{
	int		count;
	char	*str;
	int		check;

	count = 0;
	str = "0123456789";
	if (num > 9)
	{
		check = ft_recursive(num / 10);
		if (check == -1)
			return (-1);
		count += check;
	}
	if (write(1, &str[num % 10], 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_unsigned(unsigned int num)
{
	return (ft_recursive(num));
}

int	ft_num(int n)
{
	int			count;
	int			check;
	long long	num;

	num = n;
	count = 0;
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		num = -num;
		count++;
	}
	check = ft_recursive((unsigned int)num);
	if (check == -1)
		return (-1);
	return (count + check);
}
