/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 00:11:49 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/16 16:09:23 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	find_death(t_philo	*philo)
{

	pthread_mutex_lock(&philo->all->status_key);
	if (philo->all->philo_death == 1)
	{
		pthread_mutex_unlock(&philo->all->status_key);
		return (1);
	}
	pthread_mutex_unlock(&philo->all->status_key);
	return (0);
}

int	meals_done(t_philo *philo)
{
	if ((int)philo->all->meals_cnt == -1)
		return (0);
	pthread_mutex_lock(&philo->all->total_meals_key);
	if (philo->all->philos_done == philo->all->philo_cnt)
	{
		pthread_mutex_unlock(&philo->all->total_meals_key);
		return (1);
	}
	pthread_mutex_unlock(&philo->all->total_meals_key);
	return (0);
}
