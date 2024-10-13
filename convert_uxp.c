/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uxp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:50:15 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 16:02:52 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign.

int print_unsigned(unsigned int n, t_format *fmt)
{
    int count = 0;
    char *str;

    if (n == 0 && fmt->precision_set && fmt->precision == 0)
        str = ft_strdup("");
    else
        str = ft_uitoa(n);
    apply_width(str, fmt, &count);
    free(str);
    return count;
}

int print_hex(unsigned int n, int uppercase, t_format *fmt)
{
    int count = 0;
    char *str;
    char *temp;

    if (n == 0 && fmt->precision_set && fmt->precision == 0)
        str = ft_strdup("");
    else
        str = ft_ultoa_base(n, 16, uppercase);
    if (fmt->alternate_form && n != 0)
    {
        temp = ft_strjoin(uppercase ? "0X" : "0x", str);
        free(str);
        str = temp;
    }
    apply_width(str, fmt, &count);
    free(str);
    return count;
}

int print_percent(t_format *fmt)
{
    int count = 0;
    char str[2];

    str[0] = '%';
    str[1] = '\0';
    apply_width(str, fmt, &count);
    return count;
}
