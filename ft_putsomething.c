/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsomething.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasantos <pasantos <pasantos@student.42lis +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:22:24 by pasantos          #+#    #+#             */
/*   Updated: 2022/11/17 14:13:42 by pasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_putnbrbase(unsigned long long nbr, char *base, long len)
{
	size_t	baselen;

	baselen = ft_strlen(base);
	if (len == -1)
	{
		if (!nbr)
			return (ft_putstr("(nil)"));
		len = ft_putstr("0x");
	}
	if (nbr >= baselen)
		len = ft_putnbrbase(nbr / baselen, base, len);
	ft_putchar(base[nbr % baselen]);
	return (++len);
}

int	ft_putnbr(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{	
		n *= -1;
		len = ft_putchar('-');
	}
	return (len + ft_putnbrbase(n, DEC, 0));
}
