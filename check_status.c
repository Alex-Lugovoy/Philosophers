#include "philo.h"

int	check_status(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < main->count_phil)
	{
		if (main->philo[i].value_eat == 0)
			j++;
		i++;
	}
	if (j == main->count_phil)
		return (1);
	return (0);
}

void	free_pthread(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->count_phil)
	{
		pthread_detach(main->philo[i].thread);
		i++;
	}
	i = 0;
	while (i < main->count_phil)
	{
		pthread_mutex_destroy(&main->forks[i]);
		i++;
	}
	free(main->forks);
	free(main->philo);
}
