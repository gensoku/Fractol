/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 02:59:36 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/06 05:05:12 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	i = 0;
	if ((new = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
	{
		while (str[i])
		{
			new[i] = (*f)(i, str[i]);
			i++;
		}
		new[i] = '\0';
	}
	else
		new = NULL;
	return (new);
}
