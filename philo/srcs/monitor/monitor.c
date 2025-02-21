/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:04:12 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/21 02:12:47 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	over_track(t_dinner *table, size_t i)
{
	pthread_mutex_lock(table->philo[i].philo_key);

	if (current() - table->philo[i].last_meal >= table->time_to_die)
	{
		pthread_mutex_lock(&table->status_key);
		table->philo_death = 1;
		pthread_mutex_unlock(&table->status_key);
		feast_over(&table->philo[i]);
		pthread_mutex_unlock(table->philo[i].philo_key);
		return (1);
	}
	pthread_mutex_unlock(table->philo[i].philo_key);
	return (0);
}

static int	done_track(t_dinner *table)
{
	pthread_mutex_lock(&table->total_meals_key);
	if (table->philos_done == table->philo_cnt)
	{
		pthread_mutex_unlock(&table->total_meals_key);
		feast_done(table);
		return (1);
	}
	pthread_mutex_unlock(&table->total_meals_key);
	return (0);
}

static int	tracking(t_dinner *table)
{
	size_t	i;
	int		over_signal;
	int		done_signal;

	i = 0;
	while (i < table->philo_cnt)
	{
		over_signal = over_track(table, i);
		done_signal = done_track(table);
		if (over_signal == 1 || done_signal == 1)
			return (1);
		i++;
	}
	usleep(100);
	return (0);
}

int	dining(t_dinner *table)
{
	usleep(5000000);
	//printf("MONITOR AT %zu\n", current());
	while (1)
	{
		if (tracking(table))
			break ;
	}
	return (1);
}
