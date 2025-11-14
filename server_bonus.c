/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:06:52 by liemi             #+#    #+#             */
/*   Updated: 2025/10/22 22:45:10 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static t_state	g_s = {0, 0, 0};

static void	handler3(int sig, siginfo_t *info, void *ucontext)
{
	unsigned char	c;

	(void)ucontext;
	if (g_s.cli == 0 && info != 0)
		g_s.cli = (sig_atomic_t)info->si_pid;
	if (sig == SIGUSR2)
		g_s.byte |= (1 << g_s.bits);
	g_s.bits += 1;
	if (g_s.bits == 8)
	{
		c = (unsigned char)g_s.byte;
		write(1, &c, 1);
		if (c == '\0')
		{
			write(1, "\n", 1);
			if (g_s.cli != 0)
				kill((pid_t)g_s.cli, SIGUSR1);
			g_s.cli = 0;
		}
		g_s.bits = 0;
		g_s.byte = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("PID: %d\n", getpid());
	act.sa_sigaction = handler3;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
