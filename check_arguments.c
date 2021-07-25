#include "philo.h"

int	is_valid_numbers(char **a, int c)
{
	int	i;
	int	j;

	i = 1;
	while (i < c)
	{
		j = 0;
		while (a[i][j] >= '0' && a[i][j] <= '9')
			j++;
		j--;
		if (j > 4 || a[i][j] < '0' || a[i][j] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments(char **argv, int c)
{
	if (c < 5 || c > 6)
		return (message_error("Invalid number of arguments") && 0);
	if (!is_valid_numbers(argv, c))
		return (message_error("Invalid arguments") && 0);
	if (ft_atoi(argv[2]) < 30 || ft_atoi(argv[3]) < 10
		|| ft_atoi(argv[4]) < 10)
		return (message_error("Invalid arguments") && 0);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (message_error("Invalid arguments") && 0);
	return (1);
}
