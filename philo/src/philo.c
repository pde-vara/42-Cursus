/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:32:18 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/13 17:31:40 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat(t_philosopher *philo)
{
	t_table	*table;

	table = philo->table;
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(philo->left_fork);
		safe_print(table, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		safe_print(table, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		safe_print(table, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		safe_print(table, philo->id, "has taken a fork");
	}
	safe_print(table, philo->id, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time();
	philo->times_ate++;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_usleep(table->time_to_eat, table);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleep_and_think(t_philosopher *philo, t_table *table)
{
	safe_print(philo->table, philo->id, "is sleeping");
	ft_usleep(philo->table->time_to_sleep, table);
	safe_print(philo->table, philo->id, "is thinking");
}

int	wait_init_philo(t_philosopher *philo, t_table *table)
{
	wait_everyone(table);
	if (philo->id % 2 == 0)
		usleep(50);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = table->start_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (table->philo_count == 1)
	{
		safe_print(table, philo->id, "has taken left fork");
		ft_usleep(table->time_to_die, table);
		safe_print(table, philo->id, "died");
		set_int(&table->stop_simulation_mutex, 1, &table->stop_simulation);
		return (-1);
	}
	return (0);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;
	int				times_ate;

	philo = (t_philosopher *)arg;
	table = philo->table;
	if (wait_init_philo(philo, table) == -1)
		return (set_int(&table->stop_simulation_mutex, 1
				, &table->stop_simulation), NULL);
	while (!get_int(&table->stop_simulation_mutex, &table->stop_simulation))
	{
		if (philo->id % 2 == 0)
			ft_usleep(10, table);
		eat(philo);
		if (get_int(&table->stop_simulation_mutex, &table->stop_simulation))
			break ;
		pthread_mutex_lock(&philo->meal_mutex);
		times_ate = philo->times_ate;
		pthread_mutex_unlock(&philo->meal_mutex);
		if (table->meals_required > 0 && times_ate >= table->meals_required)
			break ;
		sleep_and_think(philo, table);
	}
	return (NULL);
}

int	start_simulation(t_table *table)
{
	int			i;
	pthread_t	death_thread;
	pthread_t	ate_enough_thread;

	i = 0;
	while (i < table->philo_count)
	{
		if (pthread_create(&table->philosophers[i].thread, NULL,
				philosopher_routine, &table->philosophers[i]) != 0)
		{
			printf("Error: failed to create philosopher thread%d\n", i + 1);
			return (-1);
		}
		i++;
	}
	usleep(500);
	pthread_mutex_lock(&table->start_mutex);
	table->start_time = get_time();
	table->start_signal = 0;
	pthread_mutex_unlock(&table->start_mutex);
	death_thread = 0;
	ate_enough_thread = 0;
	if (monitoring_join(table, &death_thread, &ate_enough_thread) != 0)
		return (-1);
	return (0);
}
