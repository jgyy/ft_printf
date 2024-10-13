/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:49:41 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 16:01:50 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void init_format(t_format *fmt)
{
    fmt->width = 0;
    fmt->precision = 0;
    fmt->precision_set = 0;
    fmt->left_justify = 0;
    fmt->zero_pad = 0;
    fmt->alternate_form = 0;
    fmt->space = 0;
    fmt->plus_sign = 0;
}

static const char *parse_flags(const char *format, t_format *fmt)
{
    while (*format == '-' || *format == '0' || *format == '#' || *format == ' ' || *format == '+')
    {
        if (*format == '-')
            fmt->left_justify = 1;
        else if (*format == '0')
            fmt->zero_pad = 1;
        else if (*format == '#')
            fmt->alternate_form = 1;
        else if (*format == ' ')
            fmt->space = 1;
        else if (*format == '+')
            fmt->plus_sign = 1;
        format++;
    }
    return format;
}

static const char *parse_width(const char *format, t_format *fmt, va_list *args)
{
    if (*format == '*')
    {
        fmt->width = va_arg(*args, int);
        if (fmt->width < 0)
        {
            fmt->left_justify = 1;
            fmt->width = -fmt->width;
        }
        format++;
    }
    else
    {
        fmt->width = 0;
        while (ft_isdigit(*format))
        {
            fmt->width = fmt->width * 10 + (*format - '0');
            format++;
        }
    }
    return format;
}

static const char *parse_precision(const char *format, t_format *fmt, va_list *args)
{
    if (*format == '.')
    {
        format++;
        fmt->precision_set = 1;
        if (*format == '*')
        {
            fmt->precision = va_arg(*args, int);
            format++;
        }
        else
        {
            fmt->precision = 0;
            while (ft_isdigit(*format))
            {
                fmt->precision = fmt->precision * 10 + (*format - '0');
                format++;
            }
        }
    }
    return format;
}

static int handle_conversion(const char *format, va_list *args, t_format *fmt)
{
    int result;

    if (*format == 'c')
        result = print_char(va_arg(*args, int), fmt);
    else if (*format == 's')
        result = print_string(va_arg(*args, char *), fmt);
    else if (*format == 'p')
        result = print_pointer((unsigned long long)va_arg(*args, void *), fmt);
    else if (*format == 'd' || *format == 'i')
        result = print_integer(va_arg(*args, int), fmt);
    else if (*format == 'u')
        result = print_unsigned(va_arg(*args, unsigned int), fmt);
    else if (*format == 'x' || *format == 'X')
        result = print_hex(va_arg(*args, unsigned int), *format == 'X', fmt);
    else if (*format == '%')
        result = print_percent(fmt);
    else
        result = 0;

    return result;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int count;
    t_format fmt;

    if (!format)
        return (-1);

    va_start(args, format);
    count = 0;
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            init_format(&fmt);
            format = parse_flags(format, &fmt);
            format = parse_width(format, &fmt, &args);
            format = parse_precision(format, &fmt, &args);
            if (*format)
                count += handle_conversion(format, &args, &fmt);
        }
        else
            count += ft_putchar(*format);
        if (*format)
            format++;
    }
    va_end(args);
    return (count);
}
