//
// Created by Mendoza on 1/26/2026.
//
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
    t_list *new_list;

    if (lst)
    {
        if (!(new_list = (t_list*)malloc(sizeof(lst))))
            return (NULL);
        new_list = f(lst);
        new_list->next = ft_lstmap(lst->next, f);
        return (new_list);
    }
    return (NULL);
}