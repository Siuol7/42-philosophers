/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 07:38:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/09 12:32:40 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	find_death(t_dinner *table, t_philo *philo)
{
	int	i;

	i = -1;
	while (i++ < table->philo_cnt)
	{
		if (table->philo[i].next_meal > current())
		{
			pthread_mutex_lock(table->death);
			table->philo_death = 1;
			pthread_mutex_unlock(table->death);
			return (0);
		}
	}
	return (1)
}

void	philo_thinks(t_dinner *table, t_philo *philo)
{

}

void	routine(table, philo)
{
	philo_thinks(table, philo);
	philo_eats(table, philo);
	philo_sleeps(table, philo);
}
