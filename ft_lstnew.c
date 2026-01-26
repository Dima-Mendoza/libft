//
// Created by Mendoza on 1/26/2026.
//

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
    t_list *new_list;

    if (!(new_list = (t_list*)malloc(sizeof(t_list))))
        return (NULL);
    if (content == NULL)
    {
        new_list->content = NULL;
        new_list->content_size = 0;
    }
    else
    {
        if (!(new_list->content = malloc(sizeof(content))))
            return (NULL);
        ft_memcpy((new_list->content), content, content_size);
        new_list->content_size = content_size;
    }
    new_list->next = NULL;
    return (new_list);
}