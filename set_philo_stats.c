#include "./include/philisophers.h"

int	set_philo_stats(t_all *all)
{
	int	i;

	i = 0;
	all->philo = malloc(sizeof(t_philo) * all->philo_nb);
	if (!all->philo)
	{
		free(all->philo);
		return (0);
	}
	while (i < all->philo_nb)
	{
		all->philo[i].time_to_die = all->time_to_die;
		all->philo[i].time_to_eat = all->time_to_eat;
		all->philo[i].time_to_sleep = all->time_to_sleep;
		all->philo[i].last_meal = 0;
		all->philo[i].is_eating = 0;
		all->philo[i].meals_nb = 0;
		all->philo[i].id = i;
		all->philo[i].left_fork = &all->fork_mutex[i];
		all->philo[i].right_fork = &all->fork_mutex[(i + 1) % all->philo_nb];
		i++;
	}
	return (1);
}