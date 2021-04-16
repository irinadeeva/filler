/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issymbol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:36:49 by bhugo             #+#    #+#             */
/*   Updated: 2021/04/16 12:37:23 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_issymbol(char const *str, char c)
{
	int	symbol;

	symbol = 0;
	while (*str && *str == c)
	{
		str++;
		symbol++;
	}
	return (symbol);
}
