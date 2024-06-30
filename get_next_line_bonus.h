/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:55:02 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/30 16:59:59 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <limits.h>
# include <stddef.h>
# define GET_NEXT_LINE_H
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
# endif
# if BUFFER_SIZE > SSIZE_MAX
#  undef BUFFER_SIZE
#  define BUFFER_SIZE SSIZE_MAX
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4LU
# endif

typedef struct s_fd_list
{
	int					fd;
	size_t				leftover_size;
	char				*leftovers;
	struct s_fd_list	*next;
}						t_fd_list;
char					*get_next_line(int fd);
t_fd_list				*new_fd(int fd, t_fd_list *head);
t_fd_list				*fd_picker(int fd, t_fd_list **head);
int						ft_memchr_idx(const char *s, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					ft_bzero(void *ptr, size_t n);
#endif
