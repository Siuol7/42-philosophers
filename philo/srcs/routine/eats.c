/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eats.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:58:49 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/10 16:45:10 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
	forks_up(philo);
	lock_mutex(philo->all->table_key);
	unlock_mutex(philo->all->table_key);
	system_print(philo, "is eating");
	forks_down(philo);
}
