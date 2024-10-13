/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:24:17 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:24:23 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int count_digits(int n)
{
    int count = (n <= 0) ? 1 : 0;
    while (n)
    {
        n /= 10;
        count++;
    }
    return (count);
}

char *ft_itoa(int n)
{
    char *str;
    int len = count_digits(n);
    int is_negative = (n < 0);
    unsigned int num = (is_negative) ? -n : n;
    str = malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    while (len--)
    {
        str[len] = (num % 10) + '0';
        num /= 10;
    }
    if (is_negative)
        str[0] = '-';
    return (str);
}
