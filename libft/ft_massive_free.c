/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_massive_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:02:24 by bhugo             #+#    #+#             */
/*   Updated: 2019/06/19 15:03:35 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_massive_free(char **p, size_t k)
{
	while (k--)
		ft_strdel(&(p[k]));
	free(*p);
	free(p);
	p = NULL;
}
