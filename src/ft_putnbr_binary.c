/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:43:23 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/25 16:43:44 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

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
