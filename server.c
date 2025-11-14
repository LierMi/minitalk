/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:25:46 by liemi             #+#    #+#             */
/*   Updated: 2025/11/14 17:44:55 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_state	g_s = {0, 0};

static void	handler(int sig)
{
	unsigned char	c;

	if (sig == SIGUSR2)
		g_s.byte |= (1 << g_s.bits);
	g_s.bits += 1;
	if (g_s.bits == 8)
	{
		c = (unsigned char)g_s.byte;
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		g_s.bits = 0;
		g_s.byte = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("PID: %d\n", getpid());
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
