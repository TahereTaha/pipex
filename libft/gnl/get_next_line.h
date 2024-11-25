/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:03:34 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/15 14:05:57 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <aio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 70
# endif
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*gnl_strcpy(char *dest, char *src, size_t len);
char	*gnl_strchr(char *str, char c);
size_t	gnl_strlen(char *str);
char	*gnl_strdup(char *str);
char	*gnl_substr(char *str, size_t statrt, size_t len);
char	*get_next_line(int fd);

#endif
