#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
typedef struct s_all
{
	int	philo_nb;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	meals_nb;
}	t_all;

int	check_args(int ac, char **av);
int	convert(t_all *all, char **av);
int	ft_atoi(char *str);

#endif