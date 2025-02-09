/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:38:21 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/09 12:16:13 by caonguye         ###   ########.fr       */
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
	size_t	time_to_eat;
	size_t	time_to_die;
	size_t	time_to_sleep;
	size_t	meals_cnt;
	size_t	philo_cnt;
	size_t	fork_cnt;
	size_t	philos_done;
	size_t	philo_death;
	struct s_philo	*philo;
	pthread_mutex_t	*death;
	pthread_mutex_t	**forks_lst;
}	t_dinner;

typedef struct s_philo
{
	size_t			next_meal;
	size_t			last_meal;
	size_t	eaten;
	struct s_dinner	*all;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef enum e_status
{
	ERROR,
	SUCCESS,
	RUNNING,
	FINNISH
}	t_status;

int		utilities(int ac, char **av);
int		av_parsing(int ac, char **av);


//_________________________Routine________________________//
void	routine(table, philo);

//_________________________Minilibft______________________//
int		ft_atoui(char *str);
int		ft_isspace(char c);
int 	ft_strlen(char *str);
int		ft_mutex_clear(t_dinner *table, int i);
void	philo_memset(t_philo *philo);
void	dinner_memset(t_dinner *table);
size_t	current(void);

#endif
