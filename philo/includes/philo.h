/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:58:47 by pde-vara          #+#    #+#             */
/*   Updated: 2025/03/18 12:24:27 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define NUM_PHILOSOPHERS 5

typedef struct s_table	t_table;

typedef struct s_philosopher
{
	int				id;
	int				times_ate;
	pthread_mutex_t	meal_mutex;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
}	t_philosopher;

typedef struct s_table
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	int				stop_simulation;
	pthread_mutex_t	stop_simulation_mutex;
	pthread_mutex_t	start_mutex;
	int				start_signal;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	t_philosopher	*philosophers;
}	t_table;

/* Parsing */
void		ft_bzero(void *s, size_t n);
int			ft_isnum(char *num);
ssize_t		ft_atoi(const char *nptr);
int			is_valid_input(int ac, char **av);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/* Init */
long long	get_time(void);
int			allocate_memory(t_table *table);
int			init_forks(t_table *table);
int			init_philosophers(t_table *table);
int			init_table(t_table *table, int ac, char **av);

/* Philo */
void		eat(t_philosopher *philo);
void		sleep_and_think(t_philosopher *philo, t_table *table);
void		*philosopher_routine(void *arg);
int			start_simulation(t_table *table);

/* Checks */
void		*check_ate_enough(void *arg);
void		*check_death(void *arg);

/* Utils */
void		wait_everyone(t_table *table);
void		ft_usleep(long long time_sleep_ms, t_table *table);
void		set_int(pthread_mutex_t *mutex, int valeur, int *destination);
int			get_int(pthread_mutex_t *mtx, int *src);
long long	get_long(pthread_mutex_t *mtx, long long *src);
void		safe_print(t_table *table, int id, char *msg);

int			monitoring_join(t_table *table,
				pthread_t *death_thread, pthread_t *ate_enough_thread);

#endif
