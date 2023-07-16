/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   used_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:40:08 by asaouab           #+#    #+#             */
/*   Updated: 2023/07/16 14:03:15 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"
void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar ('-');
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr (nb / 10);
	ft_putchar ((nb % 10) + 48);
}

void	ft_putchar (char c)
{
	write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '\0')
		return (i);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] != '\0')
	{
		printf("error \n");
		exit (0);
	}
	return (num * sign);
}
