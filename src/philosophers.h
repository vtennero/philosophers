/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:18:25 by vitenner          #+#    #+#             */
/*   Updated: 2024/02/01 14:35:34 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philo
{
	pthread_t thread;
	int id;
	int eating;
	int meals_eaten;
	size_t last_meal;
	size_t time_to_die;
	size_t time_to_eat;
	size_t time_to_sleep;
	size_t start_time;
	int num_of_philos;
	int num_times_to_eat;
	int *dead;
	pthread_mutex_t *r_fork;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *write_lock;
	pthread_mutex_t *dead_lock;
	pthread_mutex_t *meal_lock;
} t_philo;

typedef struct s_program
{
	int dead_flag;
	pthread_mutex_t dead_lock;
	pthread_mutex_t meal_lock;
	pthread_mutex_t write_lock;
	t_philo *philos;
} t_program;

int revelation(int argc, char **argv);
int atoi_num_only(const char *str);

void init_program(t_program *program, t_philo *philos);
void init_philosophers(t_program *program, t_philo *philos, char **argv, pthread_mutex_t *forks);
void spawn_philos(t_philo *philos, void *(*life)(void *));
void spawn_forks(pthread_mutex_t *forks, int num_forks);

void cleanup(t_program *program, pthread_mutex_t *forks, int num_forks);

size_t get_current_time(void);
// debug
void print_philo_vars(t_philo *philo);
void print_all_philos(t_program *program);

// utils
size_t get_current_time(void);
int ft_usleep(size_t milliseconds);

void bethlehem(t_philo *philo);
void gethsemane(t_philo *philo);
void mountsinai(t_philo *philo);

#endif