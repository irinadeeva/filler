/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:58:59 by bhugo             #+#    #+#             */
/*   Updated: 2021/04/16 12:42:07 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*begin;
	t_list	*tmp;
	t_list	*new;

	tmp = f(lst);
	if (lst == NULL || f == NULL)
		return (NULL);
	new = ft_lstnew(tmp->content, tmp->content_size);
	if (new == NULL)
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!new->next)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
