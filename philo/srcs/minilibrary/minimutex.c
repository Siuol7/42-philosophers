/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:08:37 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/16 02:17:19 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	mutex_clear(t_dinner *table, size_t i)
{
	while (i--)
	{
		pthread_mutex_destroy(table->mutex_key[i]);
		table->mutex_key[i] = NULL;
	}
	free(table->mutex_key);
	table->mutex_key = 	NULL;
}

static void	mutex_forks_clear(t_dinner *table, size_t i)
{
	while (i--)
	{
		pthread_mutex_destroy(table->forks_key[i]);
		table->forks_key[i] = NULL;
	}
	free(table->forks_key);
	table->forks_key = 	NULL;
}

static void	mutex_philo_clear(t_dinner *table, size_t i)
{
	while (i--)
	{
		pthread_mutex_destroy(table->philo[i].philo_key);
		table->philo[i].philo_key = NULL;
	}
	free(table->philo);
	table->philo = NULL;
}

int	total_mutex_clear(t_dinner *table, size_t i)
{
	size_t	j;

	j = i;
	if (table->mutexes > 1)
		mutex_clear(table, 3);
	if (table->mutexes > 3)
	{
		if (i == 0 || table->mutexes > 4)
			j = table->fork_cnt;
		mutex_forks_clear(table, j);
	}
	if (table->mutexes > 4)
	{
		if (i == 0)
			i = table->fork_cnt;
		mutex_philo_clear(table, i);
	}
	return (0);
}
