/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustinaheredia <agustinaheredia@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:10:42 by agheredi          #+#    #+#             */
/*   Updated: 2023/06/19 20:44:39 by agustinaher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *buffer, char *str)
{
	char	*temp;

	temp = ft_strjoin(buffer, str);
	free(buffer);
	return (temp);
}

char	*ft_read_file(int fd)
{
	int		b_read;
	char	*buffer;
	char	*str;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	str = NULL;
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[b_read] = 0;
		str = ft_free(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*ft_readed_line(char *str)
{
	char	*line;
	int		i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	line = (char *) malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*ft_move_line(char *strbuff)
{
	int		i;
	int		j;
	char	*nwstr;

	i = 0;
	if (!strbuff)
		return (NULL);
	while (strbuff[i] && strbuff[i] != '\n')
		i++;
	if (!strbuff[i])
	{
		free(strbuff);
		return (NULL);
	}
	nwstr = (char *)ft_calloc((ft_strlen(strbuff) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (strbuff[i])
		nwstr[j++] = strbuff[i++];
	free(strbuff);
	return (nwstr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[OPEN_MAX];

	if (fd == 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = ft_read_file(fd);
	if (!buffer[fd])
		return (NULL);
	line = ft_readed_line(buffer[fd]);
	buffer[fd] = ft_move_line(buffer[fd]);
	free(buffer[fd]);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("tests/test.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
	}
	close(fd1);
	return (0);
}
*/