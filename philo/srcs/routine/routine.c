/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 07:38:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/10 16:24:10 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	find_death(t_philo	*philo)
{
	int	i;

	i = -1;
	while (i++ < philo->all->philo_cnt)
	{
		if (philo->next_meal > current())
		{
			pthread_mutex_lock(philo->all->status_key);
			philo->all->philo_death = 1;
			pthread_mutex_unlock(philo->all->status_key);
			return (0);
		}
	}
	return (1);
}

static int	philo_thinks(t_philo	*philo)
{

}

static int	philo_eats(t_philo	*philo)
{
	forks_up();
	eating();
	forks_down();
}

static int	philo_sleeps(t_philo *philo)
{

}

int	routine(t_philo	*philo)
{
	philo_thinks(philo);
	philo_eats(philo);
	philo_sleeps(philo);
}
