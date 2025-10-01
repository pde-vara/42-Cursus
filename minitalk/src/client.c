/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:54:24 by pde-vara          #+#    #+#             */
/*   Updated: 2025/03/04 11:26:56 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_reception(int sig)
{
	if (sig == SIGUSR1)
		g_finish_flag = 0;
	if (sig == SIGUSR2)
	{
		ft_printf("Message received\n");
		exit(0);
	}
}

static void	ft_send_char(int pid, char c)
{
	int	i;
	int	res_kill;

	i = 7;
	res_kill = 0;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			res_kill = kill(pid, SIGUSR2);
		else
			res_kill = kill(pid, SIGUSR1);
		if (res_kill == -1)
		{
			ft_putendl_fd("Le signal non recu, verifier le PID", STDERR_FILENO);
			exit(0);
		}
		usleep(400);
		i--;
		while (g_finish_flag)
			sleep(1);
		g_finish_flag = 1;
	}
}

static void	send_string(int pid, char *message)
{
	int	i;

	i = 0;
	while (message && message[i])
	{
		ft_send_char(pid, message[i]);
		i++;
	}
	ft_send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*message;
	struct sigaction	sig;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("\033[91mError try with: %s <PID> <message>\033[0m\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
		return (ft_putendl_fd("Invalid PID !", STDERR_FILENO), 1);
	message = argv[2];
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_handler = ft_reception;
	if (sigaction(SIGUSR1, &sig, NULL) < 0)
		exit(1);
	if (sigaction(SIGUSR2, &sig, NULL) < 0)
		exit(1);
	send_string(pid, message);
	return (0);
}
