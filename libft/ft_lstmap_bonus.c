/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:02:08 by nel-khad          #+#    #+#             */
/*   Updated: 2024/11/11 13:05:47 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_lst;
	t_list	*tmp;
	void	*cont;

	new_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	tmp = lst;
	while (tmp)
	{
		cont = f(tmp->content);
		new = ft_lstnew(cont);
		if (!new)
		{
			del(cont);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new);
		tmp = tmp->next;
	}
	return (new_lst);
}
