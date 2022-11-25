/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexup_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:50:45 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/25 16:57:29 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static int	putnbr_hexup_fd_len(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr > 0)
	{
		i++;
		nbr = nbr / 16;
	}
	return (i);
}

int	ft_putnbr_hexup_fd(unsigned int nbr, int fd)
{
	int		j;
	char	*result;
	int		len;
	char	*base;

	base = "0123456789ABCDEF";
	len = putnbr_hexup_fd_len(nbr);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (-1);
	result[len] = '\0';
	while (len > 0)
	{
		j = nbr % 16;
		nbr = nbr / 16;
		result[--len] = base[j];
	}
	len = ft_strlen(result);
	j = write(fd, result, len);
	free(result);
	return (j);
}
