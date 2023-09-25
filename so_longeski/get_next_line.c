/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:09:17 by amonem            #+#    #+#             */
/*   Updated: 2023/07/28 18:18:51 by amonem           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buf, char *newbuf)
{
	char	*temp;

	temp = ft_strjoin(buf, newbuf);
	free(buf);
	return (temp);
}

char	*remain(char *buf)
{
	int		i;
	char	*remain;
	int		j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	remain = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buf[i])
		remain[j++] = buf[i++];
	buf[j] = '\0';
	free(buf);
	return (remain);
}

char	*line_needed(char *buf)
{
	char	*linen;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	linen = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		linen[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		linen[i++] = '\n';
	linen[i] = '\0';
	return (linen);
}

char	*readfromfile(int fd, char *buf)
{
	int		bytesread;
	char	*newbuf;

	newbuf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, newbuf, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(newbuf);
			free(buf);
			return (NULL);
		}
		newbuf[bytesread] = 0;
		buf = ft_strjoin(buf, newbuf);
		if (ft_strchr(newbuf, '\n'))
			break ;
	}
	free(newbuf);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = readfromfile(fd, buf);
	if (!buf)
		return (NULL);
	line = line_needed(buf);
	buf = remain(buf);
	return (line);
}
