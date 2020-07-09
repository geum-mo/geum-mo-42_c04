/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:49:17 by gekang            #+#    #+#             */
/*   Updated: 2020/07/09 20:54:48 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' \
	|| c == '\f' || c == '\r' || c == ' ') ? 1 : 0;
}

int	ft_is_minus(char c)
{
	return (c == '-' || c == '+') ? 1 : 0;
}

int	ft_is_numeric(char c)
{
	return (47 < c && c < 58) ? 1 : 0;
}

int	ft_power(int power)
{
	int i;
	int base;

	i = 0;
	base = 1;
	while (i < power - 1)
	{
		base *= 10;
		i++;
	}
	return (base);
}

int	ft_convert_to_int(int *array, int count, int len)
{
	int i;
	int nb;

	i = 0;
	printf("len is %d\n", len);
	while (i < len)
	{
		nb += array[i] * ft_power(len - i);
		i++;
	}
	if (count % 2 != 0)
		return (nb * -1);
	return (nb);
}

int	ft_atoi(char *str)
{
	int i;
	int j;
	int minus_count;
	int array[100];

	i = -1;
	j = 0;
	minus_count = 0;
	while (str)
	{
		i++;
		if (ft_is_space(str[i]))
			continue;
		if (ft_is_minus(str[i]))
		{
			if (str[i] == '-')
				minus_count++;
			continue;
		}
		if (ft_is_numeric(str[i]))
		{
			array[j] = str[i] - '0';
			j++;
			continue;
		}
		return (ft_convert_to_int(array, minus_count, j));
		break ;
	}
}

int main(void)
{
	char str[100] = " ---+--+1234ab567";
	printf("%d\n", ft_atoi(str));
}