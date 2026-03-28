/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:46:30 by gabriel           #+#    #+#             */
/*   Updated: 2026/03/28 18:02:33 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// buffer_size definition
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// fd is the file descriptor;
// str is the string that holds the content read from the file;
// next is a pointer to the next node in the linked list.
typedef struct s_gnl
{
	int				fd;
	char			*str;
	struct s_gnl	*next;
}	t_gnl;

#endif
