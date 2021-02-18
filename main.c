/*
** nasm -f macho64 ft_strlen.s && gcc -o exec main.c ft_strlen.o && ./exec  
*/

int		ft_strlen(char *c);

#include <stdio.h>
#include "libasm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	printf("%d\n", ft_strlen("hell"));
	printf("%s\n", ft_strcpy("pizda", "huy"));
	return (0);
}