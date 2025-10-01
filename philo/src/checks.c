/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:55:28 by pde-vara          #+#    #+#             */
/*   Updated: 2025/04/15 12:06:06 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_all_ate_enough(t_table *table, int *all_ate_enough)
{
	int	i;

	if (table->meals_required > 0)
	{
		i = 0;
		*all_ate_enough = 1;
		while (i < table->philo_count)
		{
			pthread_mutex_lock(&table->philosophers[i].meal_mutex);
			if (table->philosophers[i].times_ate < table->meals_required)
			{
				*all_ate_enough = 0;
				pthread_mutex_unlock(&table->philosophers[i].meal_mutex);
				break ;
			}
			pthread_mutex_unlock(&table->philosophers[i].meal_mutex);
			i++;
		}
	}
}

void	update_simulation_flag(t_table *table, int all_ate_enough)
{
	if (all_ate_enough)
	{
		pthread_mutex_lock(&table->print_mutex);
		printf("All philosophers have eaten min %d times.\n",
			table->meals_required);
		pthread_mutex_unlock(&table->print_mutex);
		set_int(&table->stop_simulation_mutex, 1, &table->stop_simulation);
	}
}

void	*check_ate_enough(void *arg)
{
	t_table	*table;
	int		all_ate_enough;

	table = (t_table *)arg;
	while (!get_int(&table->stop_simulation_mutex, &table->stop_simulation))
	{
		check_all_ate_enough(table, &all_ate_enough);
		update_simulation_flag(table, all_ate_enough);
		if (get_int(&table->stop_simulation_mutex, &table->stop_simulation))
			break ;
		usleep(500);
	}
	return (NULL);
}

void	*check_death(void *arg)
{
	t_table		*table;
	int			i;
	long long	time_since_last_meal;

	table = (t_table *)arg;
	while (!get_int(&table->stop_simulation_mutex, &table->stop_simulation))
	{	
		i = -1;
		while (++i < table->philo_count)
		{
			time_since_last_meal = get_time() - get_long(&table->philosophers[i]
					.meal_mutex, &table->philosophers[i].last_meal);
			if (time_since_last_meal > table->time_to_die
				+ 10 && table->philo_count != 1)
			{
				set_int(&table->stop_simulation_mutex,
					1, &table->stop_simulation);
				return (safe_print(table
						, table->philosophers[i].id, "died"), NULL);
			}
		}
		usleep(100);
	}
	return (NULL);
}
