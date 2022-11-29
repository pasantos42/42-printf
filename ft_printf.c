/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasantos <pasantos <pasantos@student.42lis +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:17:22 by pasantos          #+#    #+#             */
/*   Updated: 2022/11/17 14:28:08 by pasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(char definer, va_list args)
{
	int	len;

	len = 0;
	if (definer == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (definer == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (definer == 'p')
		len = ft_putnbrbase(va_arg(args, unsigned long long), HEXLOW, -1);
	else if (definer == 'd')
		len = ft_putnbr(va_arg(args, int));
	else if (definer == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (definer == 'u')
		len = ft_putnbrbase(va_arg(args, unsigned int), DEC, 0);
	else if (definer == 'x')
		len = ft_putnbrbase(va_arg(args, unsigned int), HEXLOW, 0);
	else if (definer == 'X')
		len = ft_putnbrbase(va_arg(args, unsigned int), HEXUP, 0);
	else if (definer == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += convert(str[i++ + 1], args);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
