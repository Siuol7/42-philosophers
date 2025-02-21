/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:32:27 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/21 10:14:16 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	feast_done(t_dinner *table)
{
	pthread_mutex_lock(&table->print_key);
	printf("Every philosopher has done %zu meals\n", table->meals_cnt);
	pthread_mutex_unlock(&table->print_key);
}

void	feast_over(t_philo *philo)
{
	size_t	time;

	time = current() - philo->all->start_time - 5000;
	pthread_mutex_lock(&philo->all->print_key);
	printf("%zu %zu %s\n", time, philo->id, "died");
	pthread_mutex_unlock(&philo->all->print_key);
}

int	dinner_starts(t_dinner *table)
{
	size_t	i;

	i = 0;
	while (i < table->philo_cnt)
	{
		if (pthread_create(&table->philo[i].thread
				, NULL, &routine, &table->philo[i]))
		{
			dinner_ends(table, i);
			printf("Creating threads failed\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	dinner_ends(t_dinner *table, size_t limit)
{
	size_t	i;

	i = 0;
	while (i < limit)
	{
		if (pthread_join(table->philo[i].thread, NULL))
		{
			printf("Joining threads failed\n");
			return (0);
		}
		i++;
	}
	total_mutex_clear(table, 0);
	return (1);
}
