/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:10:46 by hece              #+#    #+#             */
/*   Updated: 2022/12/06 10:38:00 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

/*#include <stdio.h>
int	main(void)
{
	t_list	*exam;
	t_list	*sample;

	exam = ft_lstnew("abc");
	sample = ft_lstnew("test");

	ft_lstadd_back(&exam, sample);
	printf("%s\n", (char *)exam->content);
	printf("%s" , (char *)exam->next->content);
	return (0);
}*/
