/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:24:03 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/25 16:27:28 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/minitalk.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(unsigned int size)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

static int	ft_putnbr_write(int n, int intlen, int start, char *num)
{
	while (intlen > start)
	{
		num[--intlen] = (n % 10) + '0';
		n = n / 10;
	}
	return (write(1, num, ft_strlen(num)));
}

static int	ft_putnbr_intlen(long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	ft_putnbr_fd(int n)
{
	char	*num;
	int		intlen;
	int		start;
	int		ret;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	intlen = ft_putnbr_intlen(n);
	start = 0;
	num = malloc((intlen + 1) * sizeof(char));
	if (!num)
		return (-1);
	num[intlen] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		n = -n;
		start++;
	}
	ret = ft_putnbr_write(n, intlen, start, num);
	free(num);
	return (ret);
}

static int	putnbr_hexdown_fd_len(unsigned int nbr)
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

int	ft_putnbr_hexdown_fd(unsigned int nbr, int fd)
{
	int		j;
	char	*result;
	int		len;
	char	*base;

	base = "0123456789abcdef";
	len = putnbr_hexdown_fd_len(nbr);
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

static int	putptr_fd_len(unsigned long long nbr)
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
	return (i + 2);
}

int	ft_putptr_fd(unsigned long long nbr, int fd)
{
	int		j;
	char	*result;
	int		len;
	char	*base;

	len = putptr_fd_len(nbr);
	base = "0123456789abcdef";
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (-1);
	result[len] = '\0';
	while (len > 2)
	{
		j = nbr % 16;
		nbr = nbr / 16;
		result[--len] = base[j];
	}
	result[0] = '0';
	result[1] = 'x';
	len = ft_strlen(result);
	j = write(fd, result, len);
	free(result);
	return (j);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (write(fd, "(null)", 6));
	while (s[i])
	{
		i++;
	}
	return (write(fd, s, i));
}

static int	ft_putunbr_intlen(long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int		i;
	char	*num;
	int		intlen;
	int		ret;

	intlen = ft_putunbr_intlen(n);
	num = malloc((intlen + 1) * sizeof(char));
	if (!num)
		return (-1);
	num[intlen] = '\0';
	while (intlen > 0)
	{
		i = n % 10;
		n = n / 10;
		num[--intlen] = i + '0';
	}
	ret = write(fd, num, ft_strlen(num));
	free(num);
	return (ret);
}

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
	while(1)
	{
		signal(SIGUSR1, server_logic);
		signal(SIGUSR2, server_logic);
	}
}
