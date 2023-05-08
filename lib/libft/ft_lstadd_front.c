/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:02:39 by hece              #+#    #+#             */
/*   Updated: 2022/12/06 10:50:10 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list	**lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*#include <stdio.h>
int	main(void)
{
	t_list	*first;
	t_list	*list;

	first = (t_list *)malloc(sizeof(t_list));
	list = (t_list *)malloc(sizeof(t_list));

	first = ft_lstnew("deneme");
	list = ft_lstnew("sample");
	ft_lstadd_front(&first, list);
	printf("%s\n",(char *)first->content);
	printf("%s\n", (char *)first->next->content);
	printf("%s\n", (char *)list->content);
	printf("%s ", (char *)list->next->content);
	return (0);
}*/
