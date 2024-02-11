/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:46:54 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/29 14:52:28 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_philo_vars(t_philo *philo)
{
    printf("Philo ID: %d\n", philo->id);
    printf("Eating: %d\n", philo->eating);
    printf("Meals Eaten: %d\n", philo->meals_eaten);
    printf("Last Meal: %zu\n", philo->last_meal);
    printf("Time to Die: %zu\n", philo->time_to_die);
    printf("Time to Eat: %zu\n", philo->time_to_eat);
    printf("Time to Sleep: %zu\n", philo->time_to_sleep);
    printf("Start Time: %zu\n", philo->start_time);
    printf("Number of Philos: %d\n", philo->num_of_philos);
    printf("Number of Times to Eat: %d\n", philo->num_times_to_eat);
    printf("Dead Flag: %d\n", *(philo->dead));
}

void print_all_philos(t_program *program)
{
    int i;
    int num_philos;

    i = 0;
    num_philos = program->philos[0].num_of_philos;
    printf("[DEBUG] print_all_philos\n");
    printf("[DEBUG] print_all_philos: num_philos = %d\n", num_philos);
    while (i < num_philos)
    {
        printf("Philo %d:\n", i + 1);
        print_philo_vars(&program->philos[i]);
        printf("\n");
        i++;
    }
}

void	print_params(int argc, char **argv)
{
    printf("[DEBUG] Program Parameters\n");
    if (argc == 5 || argc == 6)
	{
		printf("number_of_philosophers = %d\n", atoi_num_only(argv[1]));
		printf("time_to_die = %d\n",  atoi_num_only(argv[2]));
		printf("time_to_eat = %d\n",  atoi_num_only(argv[3]));
		printf("time_to_sleep = %d\n",  atoi_num_only(argv[4]));
	}
    if (argc == 6)
		printf("number_of_times_each_philosopher_must_eat = %d\n", atoi_num_only(argv[5]));
    printf("--------------------\n");
}
