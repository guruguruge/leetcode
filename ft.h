#ifndef FT_H
# define FT_H

# include <stdio.h> //for debug
# include <stdlib.h>
# include <unistd.h>

int		my_atoi(char num[]);

int		my_strcmp(char *str1, char *str2);
void	my_strswp(char *str1, char *str2);
int		my_strlen(char *str);
char	*my_strdup(char *str);
void	*my_memset(void *str, int c, size_t n);
void	*my_calloc(size_t nmeb, size_t size);

int		str_partition(char arr[], int low, int high);
void	quicksort_str(char arr[], int low, int high);
void	my_strsort(char *str);

char	*my_itoa(int num);
size_t	my_strlcat(char *dest, const char *src, size_t size);
char	**my_split(const char *str, const char *separators);
int		count_words(const char *str, const char *separators);

#endif
