size = 1
all : 
	gcc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=$(size) -g  && ./a.out
bonus :
	gcc main.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=$(size) -g  && ./a.out
clean :
	rm -rf a.out.dSYM a.out
re : clean all
