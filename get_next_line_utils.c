/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:14:57 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/14 17:15:51 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*dest;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
		if (dest == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			dest[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			dest[s1_len] = s2[i];
			s1_len++;
		}
		dest[s1_len] = '\0';
		return (dest);
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
