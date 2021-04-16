/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:28:30 by bhugo             #+#    #+#             */
/*   Updated: 2021/04/16 12:53:58 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char *)malloc(sizeof(*p) * (ft_strlen(s1) + 1));
	if (p == NULL)
		return (NULL);
	ft_strcpy(p, s1);
	return (p);
}
