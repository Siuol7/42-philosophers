/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:01:44 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/14 14:17:50 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

size_t	current(void)
{
	struct timeval	time;
	if (gettimeofday(&time, NULL) < 0)
	{
		write(2, "Get time error\n", 19);
		return (-1);
	}
	return (time.tv_sec * 1000 + time.tv_usec/1000);
}

int	system_print(t_philo *philo, char *noti)
{
	pthread_mutex_lock(philo->all->print_key);
	if (!find_death(philo))
		return (0);
	printf("%zu %d %s", current(), philo->id, noti);
	pthread_mutex_unlock(philo->all->print_key);
	return (1);
}

int	processing(size_t time, t_philo *philo)
{
	size_t	deadline;

	deadline = current() + time;
	while (current() < deadline)
	{
		if (find_death(philo) == 1)
			return (0);
	}
	usleep(time / 10);
	return (1);
}

int	setup_error(t_dinner *table, int i)
{
	if (table->philo)
	{
		free(table->philo);
		table->philo = NULL;
	}
	if (table->forks_key)
	{
		while (table->fork_cnt--)
		{
			free(table->forks_key[table->fork_cnt]);
			table->forks_key[table->fork_cnt] = NULL;
		}
		free (table->forks_key);
	}
	if (table->mutex_key)
	{
		while (i--)
		{
			free(table->mutex_key[i]);
			table->mutex_key[i] = NULL;
		}
		free (table->forks_key);
	}
	if (table->mutexes != 0)
		total_mutex_clear(table, 0);
}
