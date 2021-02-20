/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:26:53 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/20 18:32:19 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBASM_H
# define LIBASM_H

int		ft_strlen(char *c);
char	*ft_strcpy(char *dst, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t len);
char	*test(void);

#endif