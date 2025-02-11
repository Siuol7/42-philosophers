/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eats.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:58:49 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/11 14:54:49 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	can_eat(t_philo *philo)
{
	lock_mutex(philo->philo_key);
	if (philo->next_meal > philo->left_philo->next_meal
		|| philo->next_meal > philo->right_philo->next_meal)
	{
		unlock_mutex(philo->philo_key);
		return (0);
	}
	return (1);
}

void	forks_up(t_philo *philo)
{
	lock_mutex(philo->left_key);
	system_print(philo, "has taken a fork");
	lock_mutex(philo->right_key);
	system_print(philo, "has taken a fork");
}

void	forks_down(t_philo *philo)
{
	unlock_mutex(philo->left_key);
	unlock_mutex(philo->right_key);
}

void	eating(t_philo *philo)
{
	while (!can_eat(philo))
		usleep(philo->all->time_to_eat);
	forks_up(philo);
	lock_mutex(philo->philo_key);
	philo->last_meal = current();
	philo->next_meal = current() + philo->all->time_to_eat
								+ philo->all->time_to_die;
	philo->eaten++;
	unlock_mutex(philo->philo_key);
	processing(philo->all->time_to_eat, philo);
	system_print(philo, "is eating");
	lock_mutex(philo->all->total_meals_key);
	if (philo->eaten == philo->all->meals_cnt)
		philo->all->philos_done++;
	unlock_mutex(philo->all->total_meals_key);
	forks_down(philo);
}
