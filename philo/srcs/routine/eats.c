/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eats.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:58:49 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/16 19:28:18 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	can_eat(t_philo *philo)
{
	if (find_death(philo) || dinner_done(philo))
		return (1);
	pthread_mutex_lock(philo->philo_key);
	if (philo->next_meal > philo->left_philo->next_meal
		|| philo->next_meal > philo->right_philo->next_meal)
	{
		pthread_mutex_unlock(philo->philo_key);
		return (0);
	}
	pthread_mutex_unlock(philo->philo_key);
	return (1);
}

int	forks_up(t_philo *philo)
{
	pthread_mutex_lock(philo->left_key);
	if (!system_print(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->left_key);
		return (0);
	}
	if (philo->all->fork_cnt == 1)
		return (pthread_mutex_unlock(philo->left_key));
	pthread_mutex_lock(philo->right_key);
	if (!system_print(philo, "has taken a fork"))
	{
		forks_down(philo);
		return (0);
	}
	return (1);
}

void	forks_down(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_key);
	pthread_mutex_unlock(philo->right_key);
}

int	eating(t_philo *philo)
{
	size_t	time;

	time = current();
	while (!can_eat(philo))
		usleep(philo->all->time_to_eat / 10);
	if (!forks_up(philo))
		return (0);
	pthread_mutex_lock(philo->philo_key);
	philo->last_meal = time;
	philo->next_meal = time + philo->all->time_to_die
		+ philo->all->time_to_eat;
	philo->eaten++;
	pthread_mutex_unlock(philo->philo_key);
	if (!system_print(philo, "is eating"))
	{
		forks_down(philo);
		return (0);
	}
	processing(philo->all->time_to_eat, philo);
	pthread_mutex_lock(&philo->all->total_meals_key);
	if (philo->eaten == philo->all->meals_cnt)
		philo->all->philos_done++;
	pthread_mutex_unlock(&philo->all->total_meals_key);
	forks_down(philo);
	return (1);
}
