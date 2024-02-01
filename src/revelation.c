/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revelation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:02:21 by vitenner          #+#    #+#             */
/*   Updated: 2024/02/01 14:32:44 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

static int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	atoi_num_only(const char *str)
{
	int		number;
	char	*ptr;

	ptr = (char *)str;
	number = 0;
	if (!ptr)
		return (-1);
	while ((*ptr))
	{
		if (!(is_digit(*ptr)))
		{
			number = -1;
			break ;
		}
		number = number * 10;
		number = number + (*ptr - 48);
		ptr++;
	}
	return (number);
}

int	revelation(int argc, char **argv)
{
	int		i;

	i = 1;
    if (argc != 6 && argc != 5)
	{
        printf("❌ Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
		return (0);
    }
	while (i < argc)
	{
		if (atoi_num_only(argv[i]) == -1)
		{
			printf("❌ Invalid argument %d: %s\n", i, argv[i]);
			return (0);
		}
		i++;
	}
	if (atoi_num_only(argv[1]) > 200)
	{
		printf("❌ number_of_philosophers must be less than or equal to 200.\n");
		return (0);
	}
    if (atoi_num_only(argv[1]) <= 0 || atoi_num_only(argv[2]) <= 0 || atoi_num_only(argv[3]) <= 0 || atoi_num_only(argv[4]) < 0)
	{
        printf("❌ All arguments except the last one must be greater than 0.\n");
		return (0);
    }
	if (argc == 6 && atoi_num_only(argv[5]) < 0)
	{
        printf("❌ All arguments except the last one must be greater than 0.\n");
		return (0);
	}
	return (1);
}