/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:01:25 by esttina           #+#    #+#             */
/*   Updated: 2026/03/16 00:40:41 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_bits(int pid, char c)
{
	int	bit_counter = 0;
	
	while (bit_counter < 8)
	{
		if ((c >> bit_counter) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		bit_counter++;
	}
}

int	main(int argc, char **argv)
{
	int pid;
	int i;

	if (argc != 3)
		return (1);
	
	pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_bits(pid, argv[2][i]);
		i++;
	}
	send_bits(pid, '\0');
	return (0);
}
