#include "philo.h"

void complete_philo(t_main *main, char **arg, int i)
{
	unsigned long long temp;

	temp = ft_time(0);
	main->first = temp;
	while (++i < main->count_phil)
	{
		main->philo[i].philo_numb = i + 1;
		if (main->philo[i].philo_numb % 2 == 0)
			main->philo[i].even = 1;
		else
			main->philo[i].even = 0;
		main->philo[i].ti_die = ft_atoi(arg[2]);
		main->philo[i].ti_eat = ft_atoi(arg[3]);
		main->philo[i].ti_sleep = ft_atoi(arg[4]);
		main->philo[i].ti_last_eat = 0;
		if (arg[5])
			main->philo[i].value_eat = ft_atoi(arg[5]);
		main->philo[i].left_f = &main->forks[i];
		main->philo[i].right_f = &main->forks[(i + 1) % main->count_phil];
		main->philo[i].output = &main->output;
		main->philo[i].st_time = temp;
	}
}

int fill_philo(char **arg, t_main *main)
{
	int j;

	if (memory_alloc(arg, main))
		return (1);
	j = 0;
	while (j < main->count_phil)
	{
		pthread_mutex_init(&main->forks[j], NULL);
		j++;
	}
	pthread_mutex_init(&main->output, NULL);
	complete_philo(main, arg, -1);
	return (0);
}

int main(int argc, char **argv)
{
	t_main main;

	if (argc == 5 || argc == 6)
	{
		if (argv_check(argc, argv))
		{
			printf("You entered incorrect data, I hope you will not do\
 this anymore\n");
			return (1);
		}
		if(fill_philo(argv, &main))
			return (1);
	}
	else
	{
		printf("You entered incorrect data, I hope you will not do\
 this anymore\n");
		return (1);
	}
	philo_start(&main, -1);
	free_pthread(&main);
	return (0);
}
