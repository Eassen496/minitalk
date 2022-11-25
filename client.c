/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:53:20 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/25 16:42:02 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/minitalk.h"

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

char	*ft_putnbr_binary(unsigned char chr)
{
	char	j;
	char	*result;
	int		len;
	char	*base;

	base = "01";
	len = 8;
	result = ft_calloc((9) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len > 0)
	{
		j = chr % 2;
		chr = chr / 2;
		result[--len] = base[(int)j];
	}
	return (result);
}

int	client_send(int pid, char *str)
{
	int	i;
	int	err;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 48)
			err = kill(pid, SIGUSR1);
		if (str[i] == 49)
			err = kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
	return (ft_strlen(str));
}

int	client_logic(char *strpid, char *msg)
{
	int		i;
	int		pid;
	char	*result;
	char	*binary;

	i = 0;
	pid = ft_atoi(strpid);
	result = ft_calloc(1);
	if (!result)
		return (-1);
	while (msg[i])
	{
		binary = ft_putnbr_binary(msg[i]);
		if (!binary)
		{
			free(result);
			return (-1);
		}
		result = ft_strjoin(result, binary);
		i++;
	}
	return (client_send(pid, result));
}

int	main(int argc, char **argv)
{
	int	i;
	int	test;

	i = 0;
	if (argc != 3)
		return (0);
	else
	{
		test = client_logic(argv[1], argv[2]);
		if (test == -1)
			return (1);
	}
}
