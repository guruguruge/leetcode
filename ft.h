#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>

int		my_atoi(char num[]);
char	*my_itoa(int num);
char	*my_strdup(char *str);
int		my_strncmp(char *str1, char *str2);
int		my_strlen(char *str);
size_t	my_strlcat(char *dest, const char *src, size_t size);
char	**my_split(const char *str, const char *separators);
int		count_words(const char *str, const char *separators);

#endif
