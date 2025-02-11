/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:04:12 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/11 17:25:37 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	stop_call(t_dinner *table)
{
	int	i;

	i = 0;
	while (i < table->philo_cnt)
	{
		if (!lock_mutex(table->total_meals_key))
			return (0);
		if (table->philos_done == table->philo_cnt)
			feast_done(table);
		if (!unlock_mutex(table->total_meals_key))
			return (0);
		if (!lock_mutex(table->philo[i].philo_key))
			return (0);
		if (current() > table->philo[i].next_meal)
		{
			table->philo_death = 1;
			feast_over(table);
		}
		if (!unlock_mutex(table->philo[i].philo_key))
			return (0);
	}
	return (1);
}

void	tracking(t_dinner *table)
{

}