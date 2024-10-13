/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:23:53 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:24:02 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int count_words(char const *s, char c)
{
    int count = 0;
    int in_word = 0;
    while (*s)
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

char **ft_split(char const *s, char c)
{
    char **result;
    int word_count = count_words(s, c);
    int i = 0;
    result = malloc((word_count + 1) * sizeof(char *));
    if (!result)
        return (NULL);
    while (*s)
    {
        if (*s != c)
        {
            const char *word_start = s;
            while (*s && *s != c)
                s++;
            result[i++] = ft_substr(word_start, 0, s - word_start);
        }
        else
            s++;
    }
    result[i] = NULL;
    return (result);
}
