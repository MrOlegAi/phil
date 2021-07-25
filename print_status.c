#include "philo.h"
/*
void	print_status_thinking(t_all *all, int p_id)
{
	pthread_mutex_lock(&all->mutex_print);
	printf("%06ld  #%-5d is thinking\n", get_time() - all->start_sim,
		p_id + 1);
	pthread_mutex_unlock(&all->mutex_print);
}
*/
/*
void	print_status_takefork(t_all *all, int p_id)
{
	pthread_mutex_lock(&all->mutex_print);
	printf("%06ld  #%-5d has taken fork\n", get_time() - all->start_sim,
		p_id + 1);
	pthread_mutex_unlock(&all->mutex_print);
}
*/
/*
long	print_status_eating(t_all *all, int p_id)
{
	pthread_mutex_lock(&all->check_die);

	pthread_mutex_lock(&all->mutex_print);
	all->timer_on[p_id] = get_time();

	printf("%06ld  #%-5d is eating\n", all->timer_on[p_id]
		- all->start_sim, p_id + 1);
	pthread_mutex_unlock(&all->mutex_print);
	if (all->num_of_times_must_eat > 0)
		all->count_eat++;
	return (all->timer_on[p_id]);
}
*/

/*
long	print_status_sleeping(t_all *all, int p_id)
{
	long	time;

	pthread_mutex_lock(&all->mutex_print);
	time = get_time();
	printf("%06ld  #%-5d is sleeping\n", time - all->start_sim, p_id + 1);
	pthread_mutex_unlock(&all->mutex_print);
	return (time);
}
*/