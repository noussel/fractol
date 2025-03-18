/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:39:53 by nel-khad          #+#    #+#             */
/*   Updated: 2024/11/09 11:01:35 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	c = (char *)malloc(sizeof(char) * (len((char *)s1) + len((char *)s2) + 1));
	if (!c)
		return (NULL);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		c[i++] = s2[j++];
	}
	c[i] = '\0';
	return (c);
}
