/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:36:32 by hece              #+#    #+#             */
/*   Updated: 2022/12/06 11:46:27 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

/*#include <stdio.h>
int    main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = (t_list *) malloc(sizeof(t_list));
	node2 = (t_list *) malloc(sizeof(t_list));
	node3 = (t_list *) malloc(sizeof(t_list));

	node3->content = "asd";
	node3->next = 0;

	node2->next = node3;
	node2->content = "422";

	node1->next = node2;
	node1->content = "asd";

	printf("%d ", ft_lstsize(node1));
	return (0);
}*/

/*#include <stdio.h>
int    main(void)
{
    t_list    *test;
    t_list    *temp;
    int        res;
    int        a;
    a = 0;
    res = 0;
    test = (t_list *)malloc(sizeof(t_list));
    temp = (t_list *) malloc(sizeof(t_list));
    temp->content = "string";
    temp->next = 0;
    test->next = temp;
    while (a < 2)
    {
            temp = (t_list *) malloc(sizeof(t_list));
            temp->content = "str";
            temp->next=test->next;
            test->next=temp;
        a++;
    }
    res = ft_lstsize(test);
    printf("%d ", res);
    return (0);
}*/
