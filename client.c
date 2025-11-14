/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:51:58 by liemi             #+#    #+#             */
/*   Updated: 2025/10/22 22:42:28 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bit(pid_t pid, int bit)
{
	int	sig;

	sig = SIGUSR1;
	if (bit != 0)
		sig = SIGUSR2;
	if (kill(pid, sig) == -1)
		exit(1);
	usleep(400);
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

static void	send_message(pid_t srv, const char *msg)
{
	while (*msg != '\0')
	{
		send_byte(srv, (unsigned char)*msg);
		msg += 1;
	}
	send_byte(srv, '\0');
}

static int	print_usage(const char *prog)
{
	ft_printf("Usage: %s <server_pid> <message>\n", prog);
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t		srv;
	const char	*msg;

	if (argc != 3)
		return (print_usage(argv[0]));
	srv = (pid_t)ft_atoi(argv[1]);
	if (srv <= 1)
	{
		ft_printf("Error: invalid PID\n");
		return (1);
	}
	msg = argv[2];
	send_message(srv, msg);
	return (0);
}
