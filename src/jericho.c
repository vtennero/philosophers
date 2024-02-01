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

# include "philosophers.h"

static void destroy_mutexes(t_program *program, pthread_mutex_t *forks, int num_forks)
{
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);

	for (int i = 0; i < num_forks; i++)
		pthread_mutex_destroy(&forks[i]);
}

void cleanup(t_program *program, pthread_mutex_t *forks, int num_forks)
{
	// Call destroy_mutexes
	destroy_mutexes(program, forks, num_forks);

	// Additional cleanup tasks
	// For example, freeing allocated memory, closing files, etc.
}