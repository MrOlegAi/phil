#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

# define EVEN 1
# define ODD  0

typedef struct s_all
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t *right_fork;
	long			*timer_on;
	long			start_sim;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				is_die;
	int				num_of_times_must_eat;
	int				*count_eat;
}	t_all;

typedef struct s_phil
{
	int		p_id;
	t_all	*all;
}	t_phil;

long	ft_atoi(char *s);
int		message_error(char *msg);
int		check_arguments(char **argv, int argc);
int		get_arguments(t_phil *phil, char **argv, int argc);
void	*free_all(t_phil *phil);
void	destroy_mutexes(t_phil *phil);
int		mutexes_init(t_phil *phil);
int		threads_create(t_phil *phil, pthread_t *t_monitor);
void	*philo_thread(void *arg);
long	get_time(void);
void	sleeping_time(long limit);
void	eating_time(long limit);
//void	print_status_thinking(t_all *all, int p_id);
//void	print_status_takefork(t_all *all, int p_id);
//long	print_status_eating(t_all *all, int p_id);
//long	print_status_sleeping(t_all *all, int p_id);
t_phil	*init_mallocs(char **argv);
void	*base_monitor(void *arg);

#endif
