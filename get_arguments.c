#include "philo.h"

t_phil	*init_mallocs(char **argv)
{
	t_phil	*phil;
	int		n_of_phil;

	n_of_phil = ft_atoi(argv[1]);
	phil = malloc(sizeof(t_phil) * n_of_phil);
	if (!phil)
		return (NULL);
	phil->all = malloc(sizeof(t_all));
	if (!phil->all)
		return (free_all(phil));
	phil->all->forks = malloc(sizeof(pthread_mutex_t) * n_of_phil);
	if (!phil->all->forks)
		return (free_all(phil));
	phil->all->timer_on = malloc(sizeof(struct timeval) * n_of_phil);
	if (!phil->all->timer_on)
		return (free_all(phil));
	phil->all->count_eat = malloc(sizeof(int) * n_of_phil);
	if (!phil->all->count_eat)
		return (free_all(phil));
	return (phil);
}

int	get_arguments(t_phil *phil, char **argv, int c)
{
	phil->all->num_of_philos = ft_atoi(argv[1]);
	phil->all->time_to_die = ft_atoi(argv[2]);
	phil->all->time_to_eat = ft_atoi(argv[3]);
	phil->all->time_to_sleep = ft_atoi(argv[4]);
	if (c == 6)
		phil->all->num_of_times_must_eat = ft_atoi(argv[5]);
	else
		phil->all->num_of_times_must_eat = -1;
	return (1);
}
