#include "philo.h"

static int	philo_create(t_phil *phil, int n)
{
	int			i;
	pthread_t	t;

	i = n;
	while (i < phil->all->num_of_philos)
	{
		phil[i].p_id = i;
		phil->all->timer_on[i] = phil->all->start_sim;
		phil->all->right_fork = &phil->all->forks[i];
		phil->all->left_fork = &phil->all->forks[(i + 1)
										% phil->all->num_of_philos];
		phil[i].all = phil->all;
		if (pthread_create(&t, NULL, philo_thread, &phil[i]) != 0)
			return (1);
		i += 2;
		pthread_detach(t);
	}
	return (0);
}

int	threads_create(t_phil *phil, pthread_t *t_monitor)
{
	phil->all->is_die = 0;
	memset(phil->all->count_eat, 0, sizeof(int) * phil->all->num_of_philos);
	if (pthread_create(t_monitor, NULL, base_monitor, phil) != 0)
		return (1);
	phil->all->start_sim = get_time();
	if (philo_create(phil, ODD) != 0)
		return (1);
	usleep(10000);
	if (philo_create(phil, EVEN) != 0)
		return (1);
	return (0);
}
