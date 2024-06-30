/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:22:39 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/30 16:51:54 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		file_end;
	int		i;

	i = 1;
	line = NULL;
	if (argc < 2)
	{
		printf("Not enough arguments. Usage: "
				"%s filename [filename...]\n",
				argv[0]);
		return (1);
	}
	printf("Buffer Size is %lu.\n", BUFFER_SIZE);
	while (i < argc)
	{
		file_end = 0;
		if (strlen(argv[i]) == 1 && (argv[i][0] == '0' || argv[i][0] == '1'
				|| argv[i][0] == '2'))
			fd = argv[i][0] - '0';
		else
			fd = open(argv[i], O_RDONLY);
		printf("Reading from %d.\n", fd);
		while (!file_end)
		{
			line = get_next_line(fd);
			if (line)
				printf("línia:\t\t %s", line);
			else
				file_end = 1;
			free(line);
		}
		close(fd);
		printf("\nwe are so fucking done.\n");
		i++;
	}
}
