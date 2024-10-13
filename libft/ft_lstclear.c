/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:27:59 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:28:02 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *current;
    t_list *next;
    if (lst && del)
    {
        current = *lst;
        while (current)
        {
            next = current->next;
            ft_lstdelone(current, del);
            current = next;
        }
        *lst = NULL;
    }
}
