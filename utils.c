#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long	ft_atoi(char *s)
{
	long	n;

	n = 0;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + *s - '0';
		s++;
	}
	return (n);
}

int	message_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void	eating_time(long limit)
{
	while (get_time() < limit)
		usleep(30);
}

void	sleeping_time(long limit)
{
	eating_time(limit);
}
