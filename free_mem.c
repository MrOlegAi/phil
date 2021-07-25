#include "philo.h"

void	*free_all(t_phil *phil)
{
	if (phil->all->count_eat)
		free(phil->all->count_eat);
	if (phil->all->forks)
		free(phil->all->forks);
	if (phil->all->timer_on)
		free(phil->all->timer_on);
	if (phil->all)
		free(phil->all);
	if (phil)
		free(phil);
	return (NULL);
}

void	destroy_mutexes(t_phil *phil)
{
	int	i;

	i = 0;
	// check for errors
	while (i < phil->all->num_of_philos)
		pthread_mutex_destroy(&phil->all->forks[i++]);
	pthread_mutex_destroy(&phil->all->mutex_print);
}
