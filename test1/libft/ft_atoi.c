/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:38:52 by nel-khad          #+#    #+#             */
/*   Updated: 2025/02/26 21:11:10 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atoi(const char *str)
{
	int		sign;
	double	nb;
	double	dub;
	double	pow;

	nb = 0;
	dub = 0;
	sign = 1;
	pow = 1;
	while (*str == 32 || (*str <= 13 && *str >= 9))
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		pow /= 10;
		dub += (*str++ - 48) * pow;
	}
	return ((nb + dub) * sign);
}
