/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:53:20 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/25 00:00:16 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/client.h"

static int	putnbr_binary_len(unsigned char chr)
{
	int	i;

	i = 0;
	if (chr == 0)
		i++;
	while (chr > 0)
	{
		i++;
		chr = chr / 2;
	}
	return (i);
}

char	*ft_putnbr_binary(unsigned char chr)
{
	char	j;
	char	*result;
	int		len;
	char	*base;

	base = "01";
	len = putnbr_binary_len(nbr);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len > 0)
	{
		j = chr % 2;
		chr = chr / 2;
		result[--len] = base[j];
	}
	return (result);
}

int	client_send(int pid, char *str)
{
	int	i;
	int	err;

	i = 0;
	while (str[i])
	{
		if (str[i] == 0)
			err = kill(pid, SIGUSR1);
		else
			err = kill(pid, SIGUSR2);
		i++;
		if (err == -1)
			return (err);
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
		return (NULL);
	while (msg[i])
	{
		binary = ft_putnbr_binary(msg[i]);
		if (!binary)
		{
			free(result);
			return (NULL);
		}
		result = ft_strjoin(result, binary);
		i++;
	}
	return (client_send(pid, result));
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (0);
	else
	{

