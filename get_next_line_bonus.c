/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:07:13 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/26 15:53:07 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// removes an element from the list. returns 0 to save lines further down
void	*pop_fd(int fd, t_fd_list **head)
{
	t_fd_list	*list_iter;
	t_fd_list	*prev;

	if (!*head)
		return (NULL);
	list_iter = *head;
	if (list_iter->fd == fd)
	{
		prev = list_iter->next;
		free(*head);
		*head = prev;
		return (NULL);
	}
	while (list_iter->next)
	{
		prev = list_iter;
		list_iter = list_iter->next;
		if (list_iter->fd == fd)
		{
			prev->next = list_iter->next;
			free(list_iter);
			return (NULL);
		}
	}
	return (NULL);
}

// grows a buffer by appending a new buffer to it.
char	*grow_buf(char *old_buf, char *new_buf, size_t buf_size,
		size_t extra_size)
{
	char	*buf;

	if (!old_buf)
		buf_size = 0;
	if (extra_size < 1)
		return (old_buf);
	buf = malloc(buf_size + extra_size);
	if (!buf)
		return (NULL);
	if (old_buf)
		ft_memcpy(buf, old_buf, buf_size);
	ft_memcpy(&(buf[buf_size]), new_buf, extra_size);
	free(old_buf);
	return (buf);
}

// reads in BUFFER_SIZE'd chunks from fd, until a \n is read (or file ends)
// writes to leftovers and updates it's size
// returns 0 if everything is ok, 1 on file error/end, 2 on malloc error.
int	get_next_buffer(int fd, char **leftovers, size_t *leftover_size)
{
	char	*new_buf;
	ssize_t	rb;

	rb = BUFFER_SIZE;
	new_buf = malloc(BUFFER_SIZE);
	if (!new_buf)
		return (1);
	while (ft_memchr_idx(new_buf, '\n', rb) == -1 && rb == BUFFER_SIZE)
	{
		rb = read(fd, new_buf, BUFFER_SIZE);
		if (rb <= 0)
		{
			free(new_buf);
			return (1);
		}
		*leftovers = grow_buf(*leftovers, new_buf, *leftover_size, rb);
		if (!*leftovers)
		{
			free(new_buf);
			return (2);
		}
		*leftover_size += rb;
	}
	free(new_buf);
	return (0);
}

// handles the leftovers after a line is selected to be printed.
// if there are no leftovers, it frees them. otherwise it copies them to
// the start of the leftover accomulator.
// returns 1 on error.
int	manage_leftovers(char **leftovers, size_t leftover_size, int line_len)
{
	char	*tempovers;

	if (leftover_size == 0)
	{
		free(*leftovers);
		*leftovers = NULL;
	}
	else
	{
		tempovers = ft_memcpy(malloc(leftover_size), *leftovers + line_len,
				leftover_size);
		free(*leftovers);
		*leftovers = tempovers;
		if (!tempovers)
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_fd_list	*lst_head = NULL;
	t_fd_list			*node;
	char				*line;
	int					line_len;

	if (fd < 0)
		return (NULL);
	node = fd_picker(fd, &lst_head);
	if (!node)
		return (NULL);
	if (!node->leftovers || node->leftover_size == 0
		|| ft_memchr_idx(node->leftovers, '\n', node->leftover_size) == -1)
	{
		if (get_next_buffer(fd, &node->leftovers,
				(size_t *)&node->leftover_size) > 0)
			return (pop_fd(fd, &lst_head));
	}
	line_len = ft_memchr_idx(node->leftovers, '\n', node->leftover_size) + 1;
	if (line_len == 0)
		line_len = node->leftover_size;
	line = ft_memcpy(malloc(line_len), node->leftovers, line_len);
	line = grow_buf(line, "\0", line_len, 1);
	node->leftover_size -= line_len;
	if (manage_leftovers(&node->leftovers, node->leftover_size, line_len) != 0)
		return (pop_fd(fd, &lst_head));
	return (line);
}
