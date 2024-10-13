/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:50:15 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:34:27 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (ft_putchar(c));
}

int	print_string(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return (ft_putstr(s));
}

int	print_pointer(unsigned long long ptr)
{
	int		count;
	char	*str;

	count = ft_putstr("0x");
	str = ft_ultoa_base(ptr, 16, 0);
	count += ft_putstr(str);
	free(str);
	return (count);
}

int	print_integer(int n)
{
	char	*str;
	int		count;

	str = ft_itoa(n);
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	print_unsigned(unsigned int n)
{
	char	*str;
	int		count;

	str = ft_uitoa(n);
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	print_hex(unsigned int n, int uppercase)
{
	char	*str;
	int		count;

	str = ft_ultoa_base(n, 16, uppercase);
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	print_percent(void)
{
	return (ft_putchar('%'));
}
