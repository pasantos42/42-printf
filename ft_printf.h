/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasantos <pasantos <pasantos@student.42lis +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 22:48:13 by pasantos          #+#    #+#             */
/*   Updated: 2022/11/17 14:40:06 by pasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXLOW "0123456789abcdef"
# define HEXUP 	"0123456789ABCDEF"
# define DEC 	"0123456789"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/////// FT_PRINTF //////////////////////////////////////////////////

int		ft_printf(const char *str, ...);

/////// FT_PUTSOMETHING ////////////////////////////////////////////

int		ft_strlen(char *s);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbrbase(unsigned long long nbr, char *base, long len);
int		ft_putnbr(long long n);

#endif