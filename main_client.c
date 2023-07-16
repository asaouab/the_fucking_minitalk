/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:55:29 by asaouab           #+#    #+#             */
/*   Updated: 2023/07/16 16:10:47 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	send_message(int pid, char *str)
{
	int	i;
	int	shift;
	int	a;

	i = 0;
	while (str[i])
	{
		shift = 0;
		while (shift < 8)
		{
			a = 128 >> shift;
			if ((a & str[i]) == 0)
			{
				kill(pid, SIGUSR2);
			}
			else if ((a & str[i]) != 0)
			{
				kill(pid, SIGUSR1);
			}
			shift++;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "please enter a suitable arg\n", 29);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(1, "please enter a positive number\n", 32);
		exit(1);
	}
	send_message(pid, argv[2]);
}
