/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:48:30 by gekang            #+#    #+#             */
/*   Updated: 2020/07/14 10:05:08 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int				i;
	int				digits_rev[100];
	unsigned int	unb;

	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	unb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		unb = -nb;
	}
	i = 0;
	while (unb > 0)
	{
		digits_rev[i] = unb % 10;
		unb /= 10;
		i++;
	}
	while (i > 0)
		ft_putchar(digits_rev[--i] + '0');
}
