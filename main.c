/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:13:02 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/21 20:37:32 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

/*
** https://www-numi.fnal.gov/offline_software/srt_public_context/WebDocs/Errors/unix_system_errors.html - error codes
** https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master - syscalls
** https://www.notion.so/LibASM-ddd4ac8ffb834c19a9e85ee1b1ca685b#78266914c2614a29897ed769b8a35b59 - the best tips for libasm
*/

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

	str2 = "555555555555";
	if (!(str1 = malloc(ft_strlen(str2))))
		return (0);
	printf("\n______________________copy string_______________\n");
	ft_strcpy(str1, 0);
	printf("ft_strcpy - %s\n", str1);
	ft_strcpy(str1, str2);
	printf("ft_strcpy - %s\n", str1);
	printf("\n__________________________________________________\n");
	free(str1);
	return (1);
}

void	check_ft_strlen(void)
{
	char	*str;
	int		len;
	
	str = "hello world\n";
	len = ft_strlen("112131238943589438934984389743578994357889457897459784587945789879548794587954879547895487954879879458795487945789547894578954789978458794587945788457678654785438903903490980434985468974859390");
	printf("long ft_strlen - %d\n", len);
	len = ft_strlen(0);
	printf("no value ft_strlen - %d\n", len);
}

void	check_read(void)
{
	int fd;
	char u[50];
	int k;

	fd = open("ft_read.s", O_RDONLY);
	k = ft_read(fd, u, 5);
	printf("\n___________________READ_____________\n");
	printf("read_vaild_fd\n");
	printf("string - %s, return - %d\n\n", u, k);
	k = ft_read(-5, u, 6);
	printf("______________read_NOT_vaild_fd_______\n");
	printf("%s, error - %d, return - %d\n\n", u, errno, k);
	k = ft_read(0, u, 100);
	printf("______________read_STD_IN_______\n");
	printf("string - %s, return - %d\n\n", u, k);

}

void	check_write(void)
{
	int	fd;
	int k;

	fd = open("write_here.txt", O_WRONLY | O_CREAT, 0755 | O_TRUNC | O_APPEND);
	printf("\n~~~~~~~~~~~~~~write~~~~~~~~~~~~~~\n");
	k = ft_write(0, "using write", 11);
	printf("\nk = %d\n", k);
	k = ft_write(-1, "using write", 11);
	printf("errno - %d\n", errno);
	printf("\nk = %d", k);
	ft_write(fd, "i'm typing here", 15);
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
	new = check_ft_strdup("123554358934732894923044208453492085797547643957694935479439375");
	int i;
	i = 0;
	while (new[i] != '\0')
	{
		printf("new[i] = %c\n", new[i]);
		i++;
	}
	printf("new string - %s\n", new);
	return (0);
}
