#include "philo.h"

static void	*timer_to_die(void *arg)
{
	t_phil	*phil;

	phil = (t_phil *)arg;

	while (get_time()
		< phil->all->timer_on[phil->p_id] + phil->all->time_to_die)
			usleep(100);
	pthread_mutex_lock(&phil->all->mutex_print);
	printf("%07ld   #%-5d died\n", get_time() - phil->all->start_sim,
		phil->p_id + 1);
	phil->all->is_die = 1;
	return (NULL);
}



static void	*message_error_null(char *msg)
{
	printf("%s\n", msg);
	return (NULL);
}


void	*philo_thread(void *arg)
{
	t_phil		*phil;
	pthread_t	t;
	long		limit;

	phil = (t_phil *)arg;
	if (pthread_create(&t, NULL, &timer_to_die, phil) != 0)
		return (message_error_null("Error: pthread_create"));
	pthread_detach(t);
	while (1)
	{
		pthread_mutex_lock(&phil->all->mutex_print);
		printf("%07ld   #%-5d is thinking\n", get_time() - phil->all->start_sim,
			phil->p_id + 1);
		pthread_mutex_unlock(&phil->all->mutex_print);

		pthread_mutex_lock(phil->all->left_fork);
		pthread_mutex_lock(&phil->all->mutex_print);
		printf("%07ld   #%-5d has taken fork\n", get_time()
			- phil->all->start_sim, phil->p_id + 1);
		pthread_mutex_unlock(&phil->all->mutex_print);

		pthread_mutex_lock(phil->all->right_fork);
		pthread_mutex_lock(&phil->all->mutex_print);
		printf("%07ld   #%-5d has taken fork\n", get_time()
			- phil->all->start_sim, phil->p_id + 1);
		pthread_mutex_unlock(&phil->all->mutex_print);

		pthread_mutex_lock(&phil->all->mutex_print);
		phil->all->timer_on[phil->p_id] = get_time();
		printf("%07ld   #%-5d is eating\n", phil->all->timer_on[phil->p_id]
			- phil->all->start_sim, phil->p_id + 1);
		pthread_mutex_unlock(&phil->all->mutex_print);
		if (phil->all->num_of_times_must_eat >= 0)
			phil->all->count_eat++;
		phil->all->count_eat++;
		limit = phil->all->timer_on[phil->p_id] + phil->all->time_to_eat;
		eating_time(limit);

		pthread_mutex_unlock(phil->all->right_fork);
		pthread_mutex_unlock(phil->all->left_fork);

		pthread_mutex_lock(&phil->all->mutex_print);
		limit = get_time();
		printf("%07ld   #%-5d is sleeping\n", limit - phil->all->start_sim,
			phil->p_id + 1);
		pthread_mutex_unlock(&phil->all->mutex_print);
		limit += phil->all->time_to_sleep;
		sleeping_time(limit);
	}
}

int	main(int argc, char **argv)
{
	t_phil		*phil;
	pthread_t	t_monitor;

	if (!check_arguments(argv, argc))
		return (message_error("Error: argumets"));
	phil = init_mallocs(argv);
	if (!phil)
		return (message_error("Error: malloc"));
	get_arguments(phil, argv, argc);
	if (mutexes_init(phil) != 0)
		return (message_error("Error: mutex"));
	if (threads_create(phil, &t_monitor) != 0)
		return (message_error("Error! thread create"));
	pthread_join(t_monitor , NULL);
	destroy_mutexes(phil);
	free_all(phil);
}
