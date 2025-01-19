/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:08:28 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/09 11:25:30 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nu;

	nu = n;
	if (nu < 0)
	{
		nu = nu * (-1);
		write (fd, "-", 1);
	}
	if (nu > 9)
	{
		ft_putnbr_fd(nu / 10, fd);
		ft_putnbr_fd(nu % 10, fd);
	}
	else
		ft_putchar_fd(nu + 48, fd);
}
