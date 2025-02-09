/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 06:52:16 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/09 07:25:05 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_mutex_clear(t_dinner *table, int i)
{
	while (i--)
	{
		pthread_mutex_destroy(table->forks_lst[i]);
		table->forks_lst[i] = NULL;
	}
	free(table->forks_lst);
	table->forks_lst = 	NULL;
	return (0);
}

void	philo_memset(t_philo *philo)
{
	memset(philo, 0, (char*)&philo->all - (char*)philo);
}

void	dinner_memset(t_dinner *table)
{
	memset(table, 0, (char*)&table->philo - (char*)&table);
}