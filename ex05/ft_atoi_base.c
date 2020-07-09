/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:11:48 by gekang            #+#    #+#             */
/*   Updated: 2020/07/10 08:27:17 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' \
	|| c == '\f' || c == '\r' || c == ' ') ? 1 : 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_getlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = i + 1;
	if (base[0] == '\0')
		return (0);
	while (base)
	{
		if (base[i] == '-' || base[i] == '+' || ft_is_space(base[i]))
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


void ft_putnbr_base(int nbr, char *base)
{
	char digits_rev[1024];
	unsigned int unbr;
	int i;
	int base_num;

	unbr = (unsigned)nbr;
	i = 0;
	base_num = ft_getlen(base);
	// printf("base num is %d\n", base_num);
	if (nbr < 0)
	{
		ft_putchar('-');
		unbr = nbr * -1;
	}
	// printf("base num is %c\n", base[unbr % base_num]);
	while (unbr > 0)
	{
		digits_rev[i] = base[unbr % base_num];
		// printf("the element is %c\n", digits_rev[i]);
		unbr /= base_num;
		// printf("the number is divided to %d\n", unbr);
		i++;
	}
	while (i > 0)
	{
		// printf("the element is %c\n", digits_rev[i - 1]);
		ft_putchar(digits_rev[i - 1]);
		i--;
	}
}

int main(void)
{
	int nbr = 15;

	char base10[] = "0123456789";
	char base2[] = "01";
	char base16[] = "0123456789ABCDEF";
	char base8[] = "poneyvif";
	ft_putnbr_base(nbr, base16);
}
