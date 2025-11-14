/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:52:53 by liemi             #+#    #+#             */
/*   Updated: 2025/07/14 20:02:50 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include "libft.h"

// int	main(void)
// {
// 	ft_putchar_fd('4', 1);
// 	ft_putchar_fd('2', 1);
// 	ft_putchar_fd('\n', 1);
// 	return (0);
// }