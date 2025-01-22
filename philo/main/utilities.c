/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:56:51 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/23 02:42:02 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	utilities(int ac, char **av)
{
	t_dinner	table;

	if ((ac != 5 && ac != 6)
		|| !av_parsing(av, &table)
		|| !set_up(&table, av)
		|| !dinner_starts(&table, av)
		|| !dinner_ends(&table, av))
		return (0);
}
