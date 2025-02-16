/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:32:27 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/16 03:48:49 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	feast_done(t_dinner *table)
{
	pthread_mutex_lock(&table->print_key);
	printf("Every philosophers has done their dinner");
	pthread_mutex_unlock(&table->print_key);
}

void	feast_over(t_philo *philo)
{
	system_print(philo, "died");
}

int	dinner_starts(t_dinner *table)
{
	size_t	i;

	i = 0;
	while (i < table->philo_cnt)
	{
		if (pthread_create(&table->philo[i].thread, NULL, &routine, &table->philo[i]))
		{
			dinner_ends(table, i);
			printf("Creating threads failed");
			return (0);
		}
		printf("Created\n");
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
			printf("Joining threads failed");
			return (0);
		}
		i++;
	}
	total_mutex_clear(table, 0);
	return (1);
}
