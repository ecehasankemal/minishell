/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:52:58 by hece              #+#    #+#             */
/*   Updated: 2022/12/06 15:52:59 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

/*void	del(void *content)
{
	free(content);
	//printf("free\n");
}

#include <stdio.h>
int	main(void)
{
	t_list	*node1;
	t_list	*node2;

	node1 = (t_list *) malloc(sizeof(t_list));
	node2 = (t_list *) malloc(sizeof(t_list));

	node2->content = ft_strdup("Kocaeli");
	node2->next = NULL;

	node1->content = ft_strdup("42");
	node1->next = node2;

	printf("%s\n", (char *)node1->next->content);

	//ft_lstdelone(node2, (*del)(void *));
	ft_lstdelone(node1->next, del);

	printf("%s\n", (char *)node1->next->content);

	return (0);
}*/
