/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:46:23 by asaouab           #+#    #+#             */
/*   Updated: 2023/07/16 16:11:18 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void    signals_handler(int signum, siginfo_t *info, void *extra)
{
    static int              track_pid;
    static unsigned char    s;
    static int              i;
    int                     sign;

    sign = 0;
    (void) extra;
    if (track_pid != info->si_pid)
	{
        s = '\0';
        i = 0;
        track_pid = info->si_pid;
	}
    if (signum == SIGUSR2)
    {
        sign = 0;
        s = (s << 1) | sign;
        i++;
    }
    else if (signum == SIGUSR1)
    {
        sign = 1;
        s = (s << 1) | sign;
        i++;
    }
    if (i == 8)
    {
        write (1, &s, 1);
        i = 0;
        s = '\0';
    }
}

int main(void)
{
	struct sigaction	server;

	ft_putnbr(getpid());
	write(1, "\n", 1);
	server.sa_sigaction = &signals_handler;
	server.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &server, NULL);
	sigaction(SIGUSR2, &server, NULL);
	while (1)
		pause();
}
