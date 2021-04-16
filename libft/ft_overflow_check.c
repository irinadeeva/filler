/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overflow_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 21:26:31 by bhugo             #+#    #+#             */
/*   Updated: 2021/04/16 12:51:06 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_overflow_check(long int rez, char num, int sign)
{
	if (sign == 0)
	{
		if ((rez * 10 + num - '0') < 0)
			return (-1);
	}
	else
	{
		if (rez * -1 * 10 - (num - '0') > 0)
			return (0);
	}
	return (1);
}
