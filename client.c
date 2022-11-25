/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:53:20 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/25 17:38:26 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/minitalk.h"

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
	free(str);
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
