/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:48:19 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/23 03:18:15 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	set_up(t_dinner *table, char **av)
{
	table->philo_cnt = av[1];
	table->fork_cnt = av[1];
	table->time_to_die = av[2];
	table->time_to_eat = av[3];
	table->time_to_sleep = av[4];
	table->meals_cnt
}