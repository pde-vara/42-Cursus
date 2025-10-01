/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:54:40 by pde-vara          #+#    #+#             */
/*   Updated: 2025/03/04 12:04:01 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_print_msg(char *message, siginfo_t *info)
{
	ft_printf("Message complet reçu : %s\n", message);
	g_finish_flag = 1;
	kill(info->si_pid, SIGUSR2);
}

static void	ft_exit(char *message)
{
	if (message && !ft_strncmp(message, "EXIT", 5))
	{
		free(message);
		ft_printf("Exit command\n");
		exit(0);
	}
	if (message)
		free(message);
	return ;
}

static char	*ft_append(char *message, char c)
{
	char	*tmp;
	size_t	len;

	len = 0;
	if (message)
		len = ft_strlen(message);
	tmp = ft_calloc(len + 2, sizeof(char));
	if (!tmp)
	{
		return (NULL);
	}
	if (message)
	{
		ft_memcpy(tmp, message, len);
		free(message);
	}
	tmp[len] = c;
	return (tmp);
}

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int		bit = 7;
	static char		c = 0;
	static char		*message = NULL;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << bit);
	bit--;
	if (bit < 0)
	{
		bit = 7;
		if (c == '\0')
		{
			ft_print_msg(message, info);
			ft_exit(message);
			message = NULL;
			return ;
		}
		message = ft_append(message, c);
		if (!message)
			(ft_putendl_fd("Malloc error", STDERR_FILENO));
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("Serveur PID: %d\n", getpid());
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = signal_handler;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
