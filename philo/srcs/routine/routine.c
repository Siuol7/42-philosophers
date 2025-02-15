/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 07:38:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/15 23:54:06 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	find_death(t_philo	*philo)
{
	pthread_mutex_lock(philo->all->status_key);
	if (philo->all->philo_death == 1)
	{
		pthread_mutex_unlock(philo->all->status_key);
		return (0);
	}
	pthread_mutex_unlock(philo->all->status_key);
	return (1);
}

int	meals_done(t_philo *philo)
{
	pthread_mutex_lock()
}

static int	philo_thinks(t_philo	*philo)
{
	return (system_print(philo, "is thinking"));
}

static int	philo_eats(t_philo	*philo)
{
	if (!forks_up(philo))
		return (0);
	if (!eating(philo))
		return (0);
	return (forks_down(philo));
}

static int	philo_sleeps(t_philo *philo)
{
	if (!system_print(philo, "is sleeping"))
		return (0);
	return (processing(philo->all->time_to_die, philo));
}

void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 != 0)
		usleep(philo->all->time_to_eat / 2);
	while (find_death(philo))
	{
		if (!philo_thinks(philo))
			break;
		if (!philo_eats(philo))
			break;
		if (!philo_sleeps(philo))
			break;
	}
}
