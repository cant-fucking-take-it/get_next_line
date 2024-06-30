#!/bin/bash
for i in {0..100};
do cc -Wall -Wextra -Werror -g -c -I. main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=$(echo $i)LU
	cc -Wall -Wextra -Werror -g -I. -o get_next_line main.o get_next_line.o get_next_line_utils.o -D BUFFER_SIZE=$(echo $i)LU
	./get_next_line mytest;
done
for i in {0..100};
do cc -Wall -Wextra -Werror -g -c -I. main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=$(echo $i)00LU
	cc -Wall -Wextra -Werror -g -I. -o get_next_line main.o get_next_line.o get_next_line_utils.o -D BUFFER_SIZE=$(echo $i)00LU
	./get_next_line mytest;
done
