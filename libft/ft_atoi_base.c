/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:11:18 by mgrass            #+#    #+#             */
/*   Updated: 2021/04/16 12:25:15 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_base(const char c)
{
	int		nb;

	if (c >= '0' && c <= '9')
		nb = c - '0';
	else if (c >= 'a' && c <= 'z')
		nb = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		nb = c - 'A' + 10;
	else
		nb = -1;
	return (nb);
}

int	check_sing(int neg, int nb)
{
	if (neg == 1)
		return (-nb);
	return (nb);
}

int	ft_atoi_base(const char *str, int base)
{
	int		neg;
	int		nb;
	int		i;

	nb = 0;
	neg = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '-' || *str == '+')
		str++;
	i = test_base(*str);
	while (i >= 0 && i < base)
	{
		nb = nb * base + i;
		str++;
		i = test_base(*str);
	}
	return (check_sing(neg, nb));
}
