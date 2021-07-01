#include "philo.h"

int memory_alloc(char **arg, t_main *main)
{
	main->count_phil = ft_atoi(arg[1]);
	if (main->count_phil <= 0)
	{
		printf("Wrong argument\n");
		return (1);
	}
	main->philo = (t_phil *)malloc(sizeof(t_phil) * main->count_phil);
	main->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
		* main->count_phil);
	if (!main->philo)
	{
		printf("I didn't have enough memory\n");
		return (1);
	}
	if (!main->forks)
	{
		printf("I didn't have enough memory\n");
		return (1);
	}
	return (0);
}
