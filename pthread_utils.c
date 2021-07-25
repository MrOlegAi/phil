#include "philo.h"

int	mutexes_init(t_phil *phil)
{
	int	i;

	if (pthread_mutex_init(&phil->all->mutex_print, NULL) != 0)
		return (1);

	i = 0;
	while (i < phil->all->num_of_philos)
		if (pthread_mutex_init(&phil->all->forks[i++], NULL) != 0)
		return (1);
	return (0);
}

void	*base_monitor(void *arg)
{
	t_phil	*phil;
	int		i;

	phil = (t_phil *)arg;
	while (phil->all->is_die == 0)
	{
		i = 0;
		while (phil->all->count_eat[i] >= phil->all->num_of_times_must_eat)
			i++;
		if (i == phil->all->num_of_philos)
			break;
		usleep(1000);
	}
	return (NULL);
}
/*
void	put_stopsim(pthread_mutex_t mutex, int *stop_sim)
{
	pthread_mutex_lock(&mutex);
	(*stop_sim)++;
	pthread_mutex_unlock(&mutex);
}
*/