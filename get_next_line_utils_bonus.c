/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:15:21 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/01 10:50:10 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

// creates a new node and adds it to the front of the list
t_fd_list	*new_fd(int fd, t_fd_list *head)
{
	t_fd_list	*my_node;

	my_node = malloc(sizeof(t_fd_list));
	if (!my_node)
		return (NULL);
	my_node->fd = fd;
	my_node->leftovers = NULL;
	my_node->leftover_size = 0;
	my_node->next = head;
	return (my_node);
}

t_fd_list	*fd_picker(int fd, t_fd_list **head)
{
	t_fd_list	*list_iter;

	if (!*head)
	{
		*head = new_fd(fd, *head);
		return (*head);
	}
	list_iter = *head;
	while (list_iter->next)
	{
		if (list_iter->fd == fd)
			return (list_iter);
		list_iter = list_iter->next;
	}
	if (list_iter->fd == fd)
		return (list_iter);
	*head = new_fd(fd, *head);
	return (*head);
}

int	ft_memchr_idx(const char *s, int c, size_t n)
{
	int				idx;
	int				len;
	char			*my_str;
	unsigned char	my_chr;

	len = (int)n;
	idx = 0;
	if (!s)
		return (-1);
	my_str = (char *)s;
	my_chr = (unsigned char)c;
	while (idx < len)
	{
		if (my_str[idx] == my_chr)
			return (idx);
		else
			idx++;
	}
	return (-1);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*my_src;
	char	*my_dest;

	if (!dest || !src)
		return (dest);
	my_src = (char *)src;
	my_dest = dest;
	i = 0;
	while (i < n)
	{
		my_dest[i] = my_src[i];
		i++;
	}
	return (dest);
}

void	*ft_bzero(void *ptr, size_t n)
{
	size_t	i;
	char	*my_ptr;

	if (!ptr)
		return (NULL);
	i = 0;
	my_ptr = ptr;
	while (i < n)
		my_ptr[i++] = 0;
	return (my_ptr);
}
