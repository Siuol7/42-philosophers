/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 07:38:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/11 14:02:32 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	find_death(t_philo	*philo)
{
	lock_mutex(philo->all->status_key);
	if (philo->all->philo_death == 1)
	{
		unlock_mutex(philo->all->status_key);
		return (0);
	}
	unlock_mutex(philo->all->status_key);
	return (1);
}

static int	philo_thinks(t_philo	*philo)
{
	system_print(philo, "is thinking");
}

static int	philo_eats(t_philo	*philo)
{
	forks_up(philo);
	eating(philo);
	forks_down(philo);
}

static int	philo_sleeps(t_philo *philo)
{
	system_print(philo, "is sleeping");
	processing(philo->all->time_to_die, philo);
}

int	routine(t_philo	*philo)
{
	if (philo->id % 2 != 0)
		usleep(philo->all->time_to_eat / 2);
	while (find_death(philo))
	{
		philo_thinks(philo);
		philo_eats(philo);
		philo_sleeps(philo);
	}
}
