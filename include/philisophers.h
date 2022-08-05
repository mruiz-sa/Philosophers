#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include<phtread.h>

typedef struct s_philo
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_nb;
	int				last_meal;
	int				id;
	int				is_eating;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_all
{
	int				philo_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_nb;
	int				philo_dead;
	pthread_mutex_t	mutex;
	pthread_mutex_t	fork_mutex;
	t_philo			philo;
}	t_all;

int	check_args(int ac, char **av);
int	convert(t_all *all, char **av);
int	ft_atoi(char *str);

#endif