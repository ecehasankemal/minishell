/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:33:43 by hece              #+#    #+#             */
/*   Updated: 2022/09/20 11:33:46 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = NULL;
	while (lst)
	{
		begin = ft_lstnew((*f)(lst->content));
		if (!begin)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, begin);
		lst = lst->next;
	}
	return (new);
}

/*#include <stdio.h>

void    del(void *content)
{
    	free(content);
}

void *f(void *content)
{
 	((char *)content)[0] -= 32;
 	return(content);
}

int main()
{
 	t_list	*node1;
	t_list	*node2;
 	t_list	*tmp;
 	node1 = ft_lstnew(ft_strdup("442"));
 	node2 = ft_lstnew(ft_strdup("kocaeli"));
 	ft_lstadd_back(&node1, node2);
 	tmp = ft_lstmap(node1, f, del);
 	printf("**%s**", (char *)tmp->content);
 	printf("%s", (char *)tmp->next->content);
}*/
