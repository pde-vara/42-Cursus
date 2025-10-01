/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:59:58 by pde-vara          #+#    #+#             */
/*   Updated: 2025/03/18 12:24:13 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_long(pthread_mutex_t *mtx, long long *src)
{
	long long	value;

	pthread_mutex_lock(mtx);
	value = *src;
	pthread_mutex_unlock(mtx);
	return (value);
}

int	monitoring_join(t_table *table, pthread_t *death_thread
	, pthread_t *ate_enough_thread)
{
	int	i;

	if (pthread_create(death_thread, NULL, check_death, table) != 0)
		return (printf("Error: failed to create death thread\n"), -1);
	if (table->meals_required > 0)
	{
		if (pthread_create(ate_enough_thread, NULL
				, check_ate_enough, table) != 0)
		{
			set_int(&table->stop_simulation_mutex, 1, &table->stop_simulation);
			pthread_join(*death_thread, NULL);
			return (printf("Error: failed to create ate_enough thread\n"), -1);
		}
		pthread_join(*ate_enough_thread, NULL);
	}
	pthread_join(*death_thread, NULL);
	set_int(&table->stop_simulation_mutex, 1, &table->stop_simulation);
	usleep(500);
	i = -1;
	while (++i < table->philo_count)
	{
		if (pthread_join(table->philosophers[i].thread, NULL) != 0)
			printf("Error: Failed to join philosopher thread %d\n", i + 1);
	}
	return (0);
}

void	free_table(t_table *table)
{
	int	i;

	if (!table)
		return ;
	i = 0;
	if (table->forks)
	{
		while (i < table->philo_count)
		{
			pthread_mutex_destroy(&table->forks[i]);
			pthread_mutex_destroy(&table->philosophers[i].meal_mutex);
			i++;
		}
		free(table->forks);
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->stop_simulation_mutex);
	pthread_mutex_destroy(&table->start_mutex);
	if (table->philosophers)
		free(table->philosophers);
	free(table);
}

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac < 5 || ac > 6)
		return (printf("usage: ./philo <nb_of_philo> "
				"<time_to_die> <time_to_eat> <time_to_sleep> "
				"[number_of_times_each_philosopher_must_eat]\n"), -1);
	if (is_valid_input(ac, av) < 0)
		return (-1);
	table = malloc(sizeof(t_table));
	if (!table)
		return (printf("Malloc error"), -1);
	if (init_table(table, ac, av) != 0)
		return (free(table), printf("Init error"), 1);
	if (start_simulation(table) == -1)
		return (free_table(table), -1);
	free_table(table);
	return (0);
}
