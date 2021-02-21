/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:13:02 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/21 17:13:04 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"
#include <stdlib.h>
#include <fcntl.h>

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

void	check_read(void)
{
	int fd;
	char u[50];

	fd = open("ft_read.s", O_RDONLY);
	ft_read(fd, u, 5);
	printf("______________read____________\n%s\n______________________________\n", u);
}

void	check_write(void)
{
	int k;
	printf("\n~~~~~~~~~~~~~~write~~~~~~~~~~~~~~\n");
	k = ft_write(0, "using write", 11);
	printf("\nk = %d\n", k);
	k = ft_write(-1, "using write", 11);
	printf("\nk = %d", k);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

char	*check_ft_strdup(char *a)
{
	ft_strdup(a);
	return (a);	
}

int main()
{
	char	*new;
	check_ft_strcmp();
	check_ft_strcpy();
	check_ft_strlen();
	check_read();
	check_write();
	new = check_ft_strdup("123");
	printf("new string - %s\n", new);
	return (0);
}