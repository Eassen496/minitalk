/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:24:03 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/25 16:56:53 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/minitalk.h"

void	server_convert(char *str)
{
	int		i;
	char	result;
	int		tmp;

	i = 1;
	tmp = 7;
	result = 0;
	while (tmp >= 0)
	{
		result += i * (str[tmp] - 48);
		i *= 2;
		tmp--;
	}
	free(str);
	ft_printf("%c", result);
}

void	server_logic(int sig)
{
	static char		*str;
	static int		i = 0;
	char			c;

	if (sig == 30 || sig == 10 || sig == 16)
		c = 48;
	else if (sig == 31 || sig == 12 || sig == 17)
		c = 49;
	if (i <= 8)
	{
		if (i == 0)
			str = ft_calloc(9);
		str[i] = c;
		i++;
	}
	if (i == 8)
	{
		server_convert(str);
		i = 0;
	}
}

void	server(void)
{
	int	pid;

	pid = getpid();
	ft_printf("SERVER STARTED\nPID: %d\n", pid);
}

int	main(void)
{
	server();
	while (1)
	{
		signal(SIGUSR1, server_logic);
		signal(SIGUSR2, server_logic);
	}
}
