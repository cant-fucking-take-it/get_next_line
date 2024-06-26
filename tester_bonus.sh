#!/bin/bash
for i in {0..100};
	do cc -Wall -Wextra -Werror -g -c -I. main.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=$i
	cc -Wall -Wextra -Werror -g -I. -o get_next_line_bonus main.o get_next_line_bonus.o get_next_line_utils_bonus.o -D BUFFER_SIZE=$i
	./get_next_line_bonus testfile.txt;
done
