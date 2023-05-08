/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:52:46 by hece              #+#    #+#             */
/*   Updated: 2022/12/06 15:52:47 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone((*lst), del);
		*(lst) = tmp;
	}
}

/*void	del(void *content)
{
	free(content);
}

#include <stdio.h>
int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node3 = (t_list *)malloc(sizeof(t_list));

	node1->content = ft_strdup("42Kocaeli");
	node2->content = ft_strdup("43Kocaeli");
	node3->content = ft_strdup("44Kocaeli");

	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);

	//printf("%s ", node1->next->content);

	ft_lstclear(&node1, (void *)(*del));

	if (node2)
		printf("1\n");
	else
		printf("0\n");

	if (node1)
		printf("1\n");
	else
		printf("0\n");

	return (0);
}*/
