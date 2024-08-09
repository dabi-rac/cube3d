/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:33:30 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:33:30 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*function_name(int fd, char *buf, char *bkp)
{
	int		readed;
	char	*temp;

	readed = 1;
	while (readed != '\0')
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
			return (0);
		else if (readed == 0)
			break ;
		buf[readed] = '\0';
		if (!bkp)
			bkp = ft_strdup("");
		temp = bkp;
		bkp = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (bkp);
}

static char	*extract(char *line)
{
	size_t	i;
	char	*bkp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	bkp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*bkp == '\0')
	{
		free(bkp);
		bkp = NULL;
	}
	line[i + 1] = '\0';
	return (bkp);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*bkp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = function_name(fd, buf, bkp);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	bkp = extract(line);
	return (line);
}
