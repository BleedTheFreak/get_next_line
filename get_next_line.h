#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char				*get_next_line(int fd);
int					 ft_get_newline(char *str);
size_t				 ft_strlen(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);

#endif
