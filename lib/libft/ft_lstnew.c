/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:32:49 by hece              #+#    #+#             */
/*   Updated: 2022/12/06 17:05:01 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*#include <stdio.h>
int	main(void)
{
	char	content[] = "content";
	t_list	*res;

	res = ft_lstnew(content);

	t_list *ali;
	ali = (t_list *)malloc(sizeof(t_list));
	ali->content = "ali";
	ali->next = NULL;
	res->next = ali;
	printf("%s", res->next->content);
}*/

/*#include <stdio.h>
int	main(void)
{
	char	content[] = "content";
	t_list	*res;

	res = ft_lstnew(content);
	printf("%s ", res->content);
	return (0);
}*/

/*#include <stdio.h>
int	main(void)
{
	printf("%s ", (char *)ft_lstnew("hece")->content);
}*/
