/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 01:31:20 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/06 23:01:56 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t init;
	size_t size_cpy;
	size_t i;
	size_t size_dest;

	size_cpy = size - ft_strlen(dest) - 1;
	init = ft_strlen(dest);
	size_dest = init;
	i = 0;
	if (size <= size_cpy)
		return (size + ft_strlen(src));
	while (i < size_cpy && src[i] != '\0')
	{
		dest[init] = src[i];
		init++;
		i++;
	}
	dest[init] = '\0';
	return (size_dest + ft_strlen(src));
}
