/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:24:29 by aule-bre          #+#    #+#             */
/*   Updated: 2025/03/31 14:42:00 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#  define _POSIX_C_SOURCE 199309L
// # ifndef _DEFAULT_SOURCE
// #  define _DEFAULT_SOURCE
// # endif

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "libft.h"

static int	g_finish_flag = 1;

/* client */
// static void	send_string(int pid, char *message);
// static void	ft_send_char(int pid, char c);
void		ft_reception(int sig);

/* server */

// static void	signal_handler(int sig, siginfo_t *info, void *context);
// static char	*ft_append(char *message, char c);
// static void	ft_exit(char *message);
// static void	ft_print_msg(char *message, siginfo_t *info);

#endif