//
// Created by Mendoza on 1/26/2026.
//

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    del((*alst)->content, (*alst)->content_size);
    ft_memdel((void**)alst);
}