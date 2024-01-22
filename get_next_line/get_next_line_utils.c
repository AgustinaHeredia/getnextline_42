/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustinaheredia <agustinaheredia@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:11:47 by agheredi          #+#    #+#             */
/*   Updated: 2023/06/19 18:36:30 by agustinaher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = (void *) malloc(size * count);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nwstr;
	size_t	j;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	nwstr = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!nwstr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		nwstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		nwstr[i + j] = s2[j];
		j++;
	}
	nwstr[i + j] = '\0';
	return (nwstr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*chr;

	i = 0;
	chr = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			chr = (char *)&s[i];
			return (chr);
		}
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)&s[i]);
	return (chr);
}
