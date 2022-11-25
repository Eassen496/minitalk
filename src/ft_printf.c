/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:54:30 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/25 17:09:40 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static int	ft_printf_handler(char c, va_list arg)
{
	int	len;

	len = -1;
	if (c == 'c')
		len = ft_putchar_fd(va_arg(arg, int), 1);
	else if (c == 's')
		len = ft_putstr_fd(va_arg(arg, char *), 1);
	else if (c == 'p')
		len = ft_putptr_fd(va_arg(arg, unsigned long long), 1);
	else if (c == 'd' || c == 'i')
		len = ft_putnbr_fd(va_arg(arg, int));
	else if (c == 'u')
		len = ft_putunbr_fd(va_arg(arg, unsigned int), 1);
	else if (c == 'x')
		len = ft_putnbr_hexdown_fd(va_arg(arg, unsigned int), 1);
	else if (c == 'X')
		len = ft_putnbr_hexup_fd(va_arg(arg, unsigned int), 1);
	else if (c == '%')
		len = write(1, "%", 1);
	if (len == -1)
		len = -2147483648;
	return (len);
}

int	ft_printf(const char *main, ...)
{
	int		i;
	va_list	arg;
	int		ret;
	int		verif;

	ret = 0;
	i = 0;
	verif = 0;
	va_start(arg, main);
	while (main[i])
	{
		if (main[i] == '%')
			ret += ft_printf_handler(main[++i], arg);
		else
			ret += write(1, &main[i], 1);
		i++;
		if (ret < 0)
			return (-1);
	}
	va_end(arg);
	return (ret);
}
