/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:42:34 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/25 16:42:47 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

int	whitesp(char *str, int *ptr_i)
{
	int	count;
	int	i;
	int	sign;

	i = 0;
	count = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
		count++;
	}
	*ptr_i = i;
	if (count != 0)
		return (count * sign);
	else
		return (sign);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = whitesp(str, &i);
	if (sign != -1 && sign != 1)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	res *= sign;
	return (res);
}
