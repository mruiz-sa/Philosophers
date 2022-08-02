#include "./include/philisophers.h"
#include<stdio.h>
#include<stdlib.h>

int	convert(t_all *all, char **av)
{
	all->philo_nb = ft_atoi(av[1]);
	all->time_to_die = ft_atoi(av[2]);
	all->time_to_eat = ft_atoi(av[3]);
	all->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		all->meals_nb = ft_atoi(av[5]);
	else
		all->meals_nb = -1;
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Expected: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [number_of_meals]\n");
		return (0);
	}
	else
	{
		while (av[i])
		{
			if (is_digit(av[i]) == 0)
			{
				printf("Invalid argument\n");
				return (0);
			}
			i++;
		}
		return (1);
	}
}