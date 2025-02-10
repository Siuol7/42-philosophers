/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 07:38:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/10 13:49:13 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	find_death(t_dinner *table)
{
	int	i;

	i = -1;
	while (i++ < table->philo_cnt)
	{
		if (table->philo[i].next_meal > current())
		{
			pthread_mutex_lock(table->status);
			table->philo_death = 1;
			pthread_mutex_unlock(table->status);
			return (0);
		}
	}
	return (1);
}

static int	philo_thinks(t_dinner *table)
{

}

static int	philo_eats(t_dinner *table)
{
	fork_up();
	eating();
	fork_down();
}

static int	philo_sleeps(t_dinner *table)
{

}

int	routine(t_dinner *table)
{
	philo_thinks(table);
	philo_eats(table);
	philo_sleeps(table);
}
