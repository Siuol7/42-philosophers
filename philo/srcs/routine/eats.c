/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eats.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:58:49 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/14 11:29:18 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	can_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->philo_key);
	if (philo->next_meal > philo->left_philo->next_meal
		|| philo->next_meal > philo->right_philo->next_meal)
	{
		pthread_mutex_unlock(philo->philo_key);
		return (0);
	}

	return (1);
}

void	forks_up(t_philo *philo)
{
	pthread_mutex_lock(philo->left_key);
	system_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_key);
	system_print(philo, "has taken a fork");
}

void	forks_down(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_key);
	pthread_mutex_unlock(philo->right_key);
}

void	eating(t_philo *philo)
{
	while (!can_eat(philo))
		usleep(philo->all->time_to_eat);
	forks_up(philo);
	pthread_mutex_lock(philo->philo_key);
	philo->last_meal = current();
	philo->next_meal = current() + philo->all->time_to_eat
								+ philo->all->time_to_die;
	philo->eaten++;
	pthread_mutex_unlock(philo->philo_key);
	processing(philo->all->time_to_eat, philo);
	system_print(philo, "is eating");
	pthread_mutex_lock(philo->all->total_meals_key);
	if (philo->eaten == philo->all->meals_cnt)
		philo->all->philos_done++;
	pthread_mutex_unlock(philo->all->total_meals_key);
	forks_down(philo);
}
