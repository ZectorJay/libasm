/*
** nasm -f macho64 ft_strlen.s && gcc -o exec main.c ft_strlen.o && ./exec  
*/

#include <stdio.h>
#include "libasm.h"
#include <stdlib.h>

void	check_ft_strcmp(void)
{
	char	*str1;
	char	*str2;
	int		diff;

	str1 = "123";
	str2 = "125";
	diff = ft_strcmp(str1, str2);
	printf("ft_strcmp - %d\n", diff);
}

int		check_ft_strcpy(void)
{
	char *str1;
	char *str2;

	str2 = "555";
	if (!(str1 = malloc(ft_strlen(str2))))
		return (0);
	ft_strcpy(str1, str2);
	printf("ft_strcpy - %s\n", str1);
	free(str1);
	return (1);
}

void	check_ft_strlen(void)
{
	char	*str;
	int		len;
	
	str = "hello world\n";
	len = ft_strlen(str);
	printf("ft_strlen - %d\n", len);
}

int main()
{
	int k;
	check_ft_strcmp();
	check_ft_strcpy();
	check_ft_strlen();
	return (0);
}