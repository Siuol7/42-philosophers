/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:38:21 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/15 23:52:24 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_dinner
{
	size_t	mutexes;
	size_t	time_to_eat;
	size_t	time_to_die;
	size_t	time_to_sleep;
	size_t	meals_cnt;
	size_t	philo_cnt;
	size_t	fork_cnt;
	size_t	philos_done;
	size_t	philo_death;
	struct s_philo	*philo;
	pthread_mutex_t	*total_meals_key;
	pthread_mutex_t	*status_key;
	pthread_mutex_t	*print_key;
	pthread_mutex_t	** mutex_key;
	pthread_mutex_t	**forks_key;
}	t_dinner;

typedef struct s_philo
{
	size_t				id;
	size_t			next_meal;
	size_t			last_meal;
	size_t			eaten;
	size_t			died;
	struct s_dinner	*all;
	struct s_philo	*left_philo;
	struct s_philo	*right_philo;
	pthread_t		thread;
	pthread_mutex_t	*philo_key;
	pthread_mutex_t	*left_key;
	pthread_mutex_t	*right_key;
}	t_philo;

typedef enum e_status_key
{
	ERROR,
	ERROR_PARSING,
	SUCCESS
}	t_status_key;

int		utilities(int ac, char **av);
int		av_parsing(int ac, char **av);
int		set_up(t_dinner *table, char **av);
int		dinner_starts(t_dinner *table);
int		dining(t_dinner *table);
int		dinner_ends(t_dinner *table, size_t limit);
int		total_mutex_clear(t_dinner *table, int i);


//_________________________Routine________________________//
void	*routine(void *philo);
int		find_death(t_philo	*philo);

//Eating//
int		forks_up(t_philo *philo);
int		forks_down(t_philo *philo);
int		eating(t_philo *philo);
//_________________________Minilibft______________________//
int		ft_atoui(char *str);
int		ft_isspace(char c);
int 	ft_strlen(char *str);
int		total_mutex_clear(t_dinner *table, int i);
int		processing(size_t time, t_philo *philo);
void	philo_memset(t_philo *philo);
void	dinner_memset(t_dinner *table);
int		system_print(t_philo *philo, char *noti);
size_t	current(void);
int		setup_error(t_dinner *table);

#endif
