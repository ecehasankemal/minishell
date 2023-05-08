/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:49:28 by hece              #+#    #+#             */
/*   Updated: 2022/12/07 10:50:03 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*#include <stdio.h>
void f(void *content)
{
	printf("%s ", content);
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

	node3->next = 0;
	node3->content = ft_strdup("42Kocaeli");
	
	node2->next = node3;
	node2->content = ft_strdup("43Kocaeli");

	node1->next = node2;
	node1->content = ft_strdup("44Kocaeli");

	printf("%s ", node1->next->next->content);

	ft_lstiter(node1->next->next, &f);

	return (0);
}*/
