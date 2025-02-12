/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:32:27 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/13 05:17:28 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	dinner_starts(t_dinner *table, int i)
{

	if (pthread_create(&table->philo[i].thread, NULL, &routine, &table->philo[i]))
	{
		printf("Creating threads failed");
		return (0);
	}
	return (1);
}

int	dinner_ends(t_dinner *table, int i)
{
	if (pthread_join(&table->philo[i].thread, NULL))
	{
		printf("Joining threads failed");
		return (0);
	}
	return (1);
}
