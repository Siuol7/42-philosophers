/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:38:21 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/09 08:37:23 by caonguye         ###   ########.fr       */
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
	unsigned int	time_to_eat;
	unsigned int	time_to_die;
	unsigned int	time_to_sleep;
	unsigned int	meals_cnt;
	unsigned int	philo_cnt;
	unsigned int	fork_cnt;
	unsigned int	philos_done;
	struct s_philo	*philo;
	pthread_mutex_t	*status;
	pthread_mutex_t	**forks_lst;
}	t_dinner;

typedef struct s_philo
{
	long			next_meal;
	long			last_meal;
	unsigned int	eaten;
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


//_________________________Minilibft______________________//
int		ft_atoui(char *str);
int		ft_isspace(char c);
int 	ft_strlen(char *str);
int		ft_mutex_clear(t_dinner *table, int i);
void	philo_memset(t_philo *philo);
void	dinner_memset(t_dinner *table);

#endif
