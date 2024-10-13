/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:23:13 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:23:18 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    char *join = malloc(len1 + len2 + 1);
    if (!join)
        return (NULL);
    ft_memcpy(join, s1, len1);
    ft_memcpy(join + len1, s2, len2 + 1);
    return (join);
}
