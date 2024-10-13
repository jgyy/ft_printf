/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:49:59 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:48:02 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	return (ft_ultoa_base(n, 10, 0));
}

static int	get_len(unsigned long long n, int base)
{
	int	len;

	len = (n == 0);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char *ft_ultoa_base(unsigned long long n, int base, int uppercase)
{
    char *str;
    int len;
    char *digits;

    digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    len = get_len(n, base);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (n == 0)
        str[0] = '0';
    while (n)
    {
        str[--len] = digits[n % base];
        n /= base;
    }
    return (str);
}
