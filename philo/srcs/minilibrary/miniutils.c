/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:01:44 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/17 16:22:29 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

size_t	current(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
	{
		write(2, "Get time error\n", 15);
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	system_print(t_philo *philo, char *noti)
{
	pthread_mutex_lock(&philo->all->print_key);
	if (find_death(philo) || dinner_done(philo))
	{
		pthread_mutex_unlock(&philo->all->print_key);
		return (0);
	}
	printf("%zu %zu %s\n", current() - philo->all->start_time, philo->id, noti);
	pthread_mutex_unlock(&philo->all->print_key);
	return (1);
}

int	processing(size_t deadline, t_philo *philo)
{
	size_t	time;

	time = current();
	while (current() - time < deadline)
	{
		if (find_death(philo) || dinner_done(philo))
			return (0);
		usleep(500);
	}
	return (1);
}

static void	ft_free_2d(void **arr, int i)
{
	while (i--)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free (arr);
}

int	setup_error(t_dinner *table)
{
	if (table->philo)
	{
		free(table->philo);
		table->philo = NULL;
	}
	if (table->forks_key)
		ft_free_2d((void **)table->forks_key, table->fork_cnt);
	if (table->mutex_key)
		ft_free_2d((void **)table->mutex_key, 3);
	if (table->mutexes != 0)
		total_mutex_clear(table, 0);
	return (0);
}
