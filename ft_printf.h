/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:49:33 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 16:11:11 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_format
{
    int width;
    int precision;
    int precision_set;
    int left_justify;
    int zero_pad;
    int alternate_form;
    int space;
    int plus_sign;
} t_format;

void    apply_width(char *str, t_format *fmt, int *count);
int print_char(int c, t_format *fmt);
int print_string(char *s, t_format *fmt);
int print_pointer(unsigned long long ptr, t_format *fmt);
int print_integer(int n, t_format *fmt);
int print_unsigned(unsigned int n, t_format *fmt);
int print_hex(unsigned int n, int uppercase, t_format *fmt);
int print_percent(t_format *fmt);

int ft_putchar(char c);
int ft_putstr(char *s);
char *ft_uitoa(unsigned int n);
char *ft_ultoa_base(unsigned long long n, int base, int uppercase);

int ft_printf(const char *format, ...);

#endif
