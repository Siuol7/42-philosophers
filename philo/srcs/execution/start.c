/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:32:27 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/13 01:28:17 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	gen_thread(t_dinner *table, int i)
{

	if (pthread_create(&table->philo[i].thread, NULL, &routine, &table->philo[i]))
		return (0);
	return (1);
}

static int	wait_thread(t_dinner *table)
{
	pthread_join(&table->philo[i].thread, NULL);
}

int	dinner_starts(t_dinner *table)
{

}