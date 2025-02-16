/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:56:51 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/16 17:51:23 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	utilities(int ac, char **av)
{
	t_dinner	table;

	if ((ac != 5 && ac != 6)
		|| !av_parsing(ac, av))
		return (ERROR_PARSING);
	if (!set_up(&table, av)
		|| !dinner_starts(&table)
		|| !dining(&table)
		|| !dinner_ends(&table, table.philo_cnt))
		return (ERROR);
	return (SUCCESS);
}
