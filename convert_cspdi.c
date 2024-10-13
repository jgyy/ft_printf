/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_cspdi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:50:15 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 16:11:01 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// %p The void * pointer argument has to be printed in hexadecimal format.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.

void    apply_width(char *str, t_format *fmt, int *count)
{
    int len = ft_strlen(str);
    int padding = fmt->width - len;

    if (padding > 0)
    {
        if (fmt->left_justify)
        {
            *count += ft_putstr(str);
            while (padding--)
                *count += ft_putchar(' ');
        }
        else
        {
            char pad_char = fmt->zero_pad ? '0' : ' ';
            while (padding--)
                *count += ft_putchar(pad_char);
            *count += ft_putstr(str);
        }
    }
    else
    {
        *count += ft_putstr(str);
    }
}

int print_char(int c, t_format *fmt)
{
    int count = 0;
    char str[2];

    str[0] = c;
    str[1] = '\0';
    apply_width(str, fmt, &count);
    return count;
}

int print_string(char *s, t_format *fmt)
{
    int count = 0;
    char *str;

    if (!s)
        s = "(null)";
    if (fmt->precision_set && fmt->precision < (int)ft_strlen(s))
        str = ft_substr(s, 0, fmt->precision);
    else
        str = ft_strdup(s);
    apply_width(str, fmt, &count);
    free(str);
    return count;
}

int print_pointer(unsigned long long ptr, t_format *fmt)
{
    int count = 0;
    char *str;

    if (ptr == 0 && fmt->precision_set && fmt->precision == 0)
        str = ft_strdup("0x");
    else
    {
        str = ft_ultoa_base(ptr, 16, 0);
        str = ft_strjoin("0x", str);
    }
    apply_width(str, fmt, &count);
    free(str);
    return count;
}

int print_integer(int n, t_format *fmt)
{
    int count = 0;
    char *str;
    char *temp;

    if (n == 0 && fmt->precision_set && fmt->precision == 0)
        str = ft_strdup("");
    else
        str = ft_itoa(n);
    if (fmt->plus_sign && n >= 0)
        temp = ft_strjoin("+", str);
    else if (fmt->space && n >= 0)
        temp = ft_strjoin(" ", str);
    else
        temp = ft_strdup(str);
    free(str);
    str = temp;
    apply_width(str, fmt, &count);
    free(str);
    return count;
}
