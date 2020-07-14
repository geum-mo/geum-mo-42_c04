/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:56:42 by gekang            #+#    #+#             */
/*   Updated: 2020/07/14 10:03:22 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

int					ft_getlen(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int					ft_check_base(char *base)
{
	int				i;
	int				j;

	i = 0;
	j = i + 1;
	if (base[0] == '\0')
		return (0);
	while (base)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void				ft_putnbr_base(int nbr, char *base)
{
	char			digits_rev[1024];
	unsigned int	unbr;
	int				i;
	int				base_num;

	unbr = (unsigned)nbr;
	i = 0;
	base_num = ft_getlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		unbr = nbr * -1;
	}
	while (unbr > 0)
	{
		digits_rev[i] = base[unbr % base_num];
		unbr /= base_num;
		i++;
	}
	while (i > 0)
	{
		ft_putchar(digits_rev[i - 1]);
		i--;
	}
}
