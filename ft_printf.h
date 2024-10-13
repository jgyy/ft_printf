/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:49:33 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:34:06 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);

int		print_char(int c);
int		print_string(char *s);
int		print_pointer(unsigned long long ptr);
int		print_integer(int n);
int		print_unsigned(unsigned int n);
int		print_hex(unsigned int n, int uppercase);
int		print_percent(void);

int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_uitoa(unsigned int n);
char	*ft_ultoa_base(unsigned long long n, int base, int uppercase);

#endif
