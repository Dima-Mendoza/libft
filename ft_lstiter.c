//
// Created by Mendoza on 1/26/2026.
//
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
    if ((lst->next) != NULL)
        (ft_lstiter(lst->next, f));
    f(lst);
}