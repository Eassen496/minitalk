/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:08:52 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/25 13:50:49 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <stdarg.h>

int		putnbr_binary_len(unsigned char chr);
char    *ft_putnbr_binary(unsigned char chr);
int		client_send(int pid, char *str);
int		client_logic(char *strpid, char *msg);
size_t	ft_strlen(char *str);
void	*ft_calloc(unsigned int size);
char	*ft_strjoin(char *s1, char *s2);
int		whitesp(char *str, int *ptr_i);
int		ft_atoi(char *str);
int     ft_putchar_fd(char c, int fd);
int     ft_putnbr_fd(int n);
int     ft_putstr_fd(char *s, int fd);
int     ft_putnbr_hexup_fd(unsigned int nbr, int fd);
int     ft_putnbr_hexdown_fd(unsigned int nbr, int fd);
int     ft_putunbr_fd(unsigned int n, int fd);
size_t  ft_strlen(char *str);
int     ft_printf(const char *main, ...);
int     ft_putptr_fd(unsigned long long int nbr, int fd);

#endif
