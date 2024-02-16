/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jericho.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:29:30 by vitenner          #+#    #+#             */
/*   Updated: 2024/02/01 14:32:50 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	cleanup(t_program *program, pthread_mutex_t *forks, int num_forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	while (i < num_forks)
		pthread_mutex_destroy(&forks[i++]);
}
