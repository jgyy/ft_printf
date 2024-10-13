/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:28:27 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:28:35 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list = NULL;
    t_list *new_elem;
    void *content;
    while (lst)
    {
        content = f(lst->content);
        new_elem = ft_lstnew(content);
        if (!new_elem)
        {
            ft_lstclear(&new_list, del);
            del(content);
            return (NULL);
        }
        ft_lstadd_back(&new_list, new_elem);
        lst = lst->next;
    }
    return (new_list);
}
