/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:08:37 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/10 14:06:03 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_mutex_clear(t_dinner *table, int i)
{
	while (i--)
	{
		pthread_mutex_destroy(table->forks_key[i]);
		table->forks_key[i] = NULL;
	}
	free(table->forks_key);
	table->forks_key = 	NULL;
	return (0);
}

void	lock_mutex(pthread_mutex_t *mt)
{
	if (!pthread_mutex_lock(mt))
		printf("Locking mutex failed\n");
	exit(1);
}

void	unlock_mutex(pthread_mutex_t *mt)
{
	if (!pthread_mutex_unlock(mt))
		printf("Unlocking mutex failed\n");
	exit(1);
}
