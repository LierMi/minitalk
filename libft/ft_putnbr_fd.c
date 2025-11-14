/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:23:45 by liemi             #+#    #+#             */
/*   Updated: 2025/08/13 22:37:59 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	digit = '0' + (nb % 10);
	write(fd, &digit, 1);
}

// int	main(void)
// {
// 	ft_putnbr_fd(42, 1);     // 输出: 42
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-2147483648, 1); // 输出: -2147483648
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(0, 1);      // 输出: 0
// 	write(1, "\n", 1);
// 	return (0);
// }