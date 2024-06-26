#!/bin/bash
for i in {0..100};
	do cc -Wall -Wextra -Werror -g -c -I. main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=$i
	cc -Wall -Wextra -Werror -g -I. -o get_next_line main.o get_next_line.o get_next_line_utils.o -D BUFFER_SIZE=$i
	./get_next_line testfile.txt;
done
