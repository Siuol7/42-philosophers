/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:38:21 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/23 03:21:59 by caonguye         ###   ########.fr       */
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
	pthread_t		philo_cnt;
	pthread_t		fork_cnt;
	struct s_philo	*philo;
	pthread_mutex_t	*thread;
	pthread_mutex_t	*status;
	pthread_mutex_t	**forks_lst;
}	t_dinner;

typedef struct s_philo
{
	long			next_meal;
	long			last_meal;
	unsigned int	eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

#endif
