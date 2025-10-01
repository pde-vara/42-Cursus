/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:12:16 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/13 17:27:44 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	wait_everyone(t_table *table)
{	
	while (get_int(&table->start_mutex, &table->start_signal) != 0)
		usleep(1);
}

void	ft_usleep(long long time_sleep_ms, t_table *table)
{
	long long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time_sleep_ms)
	{
		if (get_int(&table->stop_simulation_mutex, &table->stop_simulation))
			return ;
		usleep(100);
	}
}

void	set_int(pthread_mutex_t *mutex, int valeur, int *destination)
{
	pthread_mutex_lock(mutex);
	*destination = valeur;
	pthread_mutex_unlock(mutex);
}

int	get_int(pthread_mutex_t *mtx, int *src)
{
	int	value;

	pthread_mutex_lock(mtx);
	value = *src;
	pthread_mutex_unlock(mtx);
	return (value);
}

void	safe_print(t_table *table, int id, char *msg)
{
	long int		time;
	int				should_print;

	time = get_time() - table->start_time;
	pthread_mutex_lock(&table->stop_simulation_mutex);
	if (!table->stop_simulation || (ft_strncmp(msg, "died", 4) == 0))
		should_print = 1;
	else
		should_print = 0;
	pthread_mutex_unlock(&table->stop_simulation_mutex);
	if (time >= 0 && should_print)
	{
		pthread_mutex_lock(&table->print_mutex);
		printf("%ld %d %s\n", time, id, msg);
		pthread_mutex_unlock(&table->print_mutex);
	}
}
