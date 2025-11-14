/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:48:27 by liemi             #+#    #+#             */
/*   Updated: 2025/11/14 16:13:04 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static volatile sig_atomic_t	g_ack = 0;

static void	ack_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
}

static void	send_bit(pid_t pid, int bit)
{
	int	sig;

	sig = SIGUSR1;
	if (bit != 0)
		sig = SIGUSR2;
	if (kill(pid, sig) == -1)
		exit(1);
	usleep(120);
}

static void	send_byte(pid_t pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		send_bit(pid, (c >> i) & 1);
		i += 1;
	}
}

static void	send_message_and_wait_ack(pid_t srv, const char *msg)
{
	while (*msg != '\0')
	{
		send_byte(srv, (unsigned char)*msg);
		msg += 1;
	}
	g_ack = 0;
	send_byte(srv, '\0');
	while (g_ack == 0)
		pause();
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	pid_t				srv;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	srv = (pid_t)ft_atoi(argv[1]);
	if (srv <= 1)
	{
		ft_printf("Error: invalid PID\n");
		return (1);
	}
	act.sa_handler = ack_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, 0);
	send_message_and_wait_ack(srv, argv[2]);
	return (0);
}
