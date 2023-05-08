/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:35:11 by hece              #+#    #+#             */
/*   Updated: 2022/12/06 11:09:39 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

/*#include <stdio.h>
int    main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node3 = (t_list *)malloc(sizeof(t_list));

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	node3->content = "42 Kocaeli";

	printf("%s ",(char *)ft_lstlast(node1)->content);
	return (0);
}*/
