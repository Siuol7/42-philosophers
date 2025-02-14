/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:08:37 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/14 12:55:42 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	mutex_clear(t_dinner *table, int i)
{
	pthread_mutex_destroy(table->total_meals_key);
	table->total_meals_key = NULL;
	pthread_mutex_destroy(table->status_key);
	table->status_key = NULL;
	pthread_mutex_destroy(table->print_key);
	table->print_key = NULL;
}

static void	mutex_forks_clear(t_dinner *table, int i)
{
	while (i--)
	{
		pthread_mutex_destroy(table->forks_key[i]);
		table->forks_key[i] = NULL;
	}
	free(table->forks_key);
	table->forks_key = 	NULL;
}

static void	mutex_philo_clear(t_dinner *table, int i)
{
	while (i--)
	{
		pthread_mutex_destroy(table->philo[i].philo_key);
		table->philo[i].philo_key = NULL;
	}
	free(table->philo);
	table->philo = NULL;
}

void	total_mutex_clear(t_dinner *table, int i)
{
	if (i < 6)
		mutex_clear(table, i);
	if (i == 4)
		mutex_forks_clear(table);
	if (i == 5)
		mutex_philo_clear(table);
}