#!/bin/bash
for i in {0..100};
	do cc -Wall -Wextra -Werror -g -c -I. main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=$(echo $i)LU
	cc -Wall -Wextra -Werror -g -I. -o get_next_line_bonus main_bonus.o get_next_line_bonus.o get_next_line_utils_bonus.o -D BUFFER_SIZE=$(echo $i)LU
	./get_next_line_bonus mytest get_next_line_bonus.c;
done
for i in {0..100};
	do cc -Wall -Wextra -Werror -g -c -I. main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=$(echo $i)00LU
	cc -Wall -Wextra -Werror -g -I. -o get_next_line_bonus main_bonus.o get_next_line_bonus.o get_next_line_utils_bonus.o -D BUFFER_SIZE=$(echo $i)00LU
	./get_next_line_bonus mytest get_next_line_bonus.c;
done
