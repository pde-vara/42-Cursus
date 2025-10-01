/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:31:15 by pde-vara          #+#    #+#             */
/*   Updated: 2025/03/18 12:01:45 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	allocate_memory(t_table *table)
{
	table->philosophers = malloc(sizeof(t_philosopher) * table->philo_count);
	if (!table->philosophers)
		return (printf("Error: memory allocation failed\n"), -1);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_count);
	if (!table->forks)
	{
		free(table->philosophers);
		table->philosophers = NULL;
		return (printf("Error: memory allocation failed\n"), -1);
	}
	return (0);
}

int	init_forks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_count)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&table->forks[i]);
			printf("Error: fork mutex initialization failed\n");
			return (1);
		}
		if (pthread_mutex_init(&table->philosophers[i].meal_mutex, NULL) != 0)
		{
			pthread_mutex_destroy(&table->forks[i]);
			while (--i >= 0)
			{
				pthread_mutex_destroy(&table->forks[i]);
				pthread_mutex_destroy(&table->philosophers[i].meal_mutex);
			}
			printf("Error: meal mutex initialization failed\n");
			return (1);
		}
	}
	return (0);
}

int	init_philosophers(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		table->philosophers[i].id = i + 1;
		if (i % 2 == 1)
		{
			table->philosophers[i].left_fork = &table->forks[i];
			table->philosophers[i].right_fork = &table->forks[(i + 1)
				% table->philo_count];
		}
		else
		{
			table->philosophers[i].right_fork = &table->forks[i];
			table->philosophers[i].left_fork = &table->forks[(i + 1)
				% table->philo_count];
		}
		table->philosophers[i].last_meal = table->start_time;
		table->philosophers[i].times_ate = 0;
		table->philosophers[i].table = table;
		i++;
	}
	return (0);
}

int	init_table(t_table *table, int ac, char **av)
{
	ft_bzero(table, sizeof(t_table));
	table->start_time = get_time();
	table->philo_count = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		table->meals_required = ft_atoi(av[5]);
		if (table->meals_required < 1)
			return (-1);
	}
	if (allocate_memory(table) != 0)
		return (-1);
	if (init_forks(table) != 0 || init_philosophers(table) != 0)
		return (-1);
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&table->stop_simulation_mutex, NULL) != 0)
		return (-1);
	table->stop_simulation = 0;
	if (pthread_mutex_init(&table->start_mutex, NULL) != 0)
		return (-1);
	table->start_signal = 1;
	return (0);
}
