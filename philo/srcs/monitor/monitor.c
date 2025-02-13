/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:04:12 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/13 05:19:59 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	error_track(t_dinner *table)
{
	lock_mutex
}

static int	over_track(t_dinner *table, int i)
{
	if (!lock_mutex(table->philo[i].philo_key))
		return (-1);
	if (current() > table->philo[i].next_meal)
	{
		table->philo_death = 1;
		feast_over(table);
		return (1);
	}
	if (!unlock_mutex(table->philo[i].philo_key))
		return (-1);
	return (0);
}

static int	done_track(t_dinner *table)
{
	if (!lock_mutex(table->total_meals_key))
		return (-1);
	if (table->philos_done == table->philo_cnt)
	{
		feast_done(table);
		return (1);
	}
	if (!unlock_mutex(table->total_meals_key))
		return (-1);
	return (0);
}

static int	tracking(t_dinner *table)
{
	int	i;
	int error_signal;
	int over_signal;
	int done_signal;

	i = 0;
	while (++i < table->philo_cnt)
	{
		error_signal = error_track(table);
		over_signal = over_track(table, i);
		done_signal = done_track(table);

		if (!error_signal || !over_signal || !done_signal)
			i++;
		if (error_signal == 1 || over_signal == -1
					|| done_signal == -1)
			return (-1);
		if (over_signal == 1 || done_signal == 1)
			return (1);
	}
	return (1);
}

int	monitor(t_dinner *table)
{

}
