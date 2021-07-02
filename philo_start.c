#include "philo.h"

void	forks(t_phil *philo)
{
	pthread_mutex_lock(philo->left_f);
	printf_mutex_fork(philo);
	pthread_mutex_lock(philo->right_f);
	printf_mutex_fork(philo);
}

void	lunch(t_phil *philo)
{
	philo->ti_last_eat = ft_time(philo->st_time);
	printf_mutex_eat(philo);
	ft_wait(philo->ti_eat);
	pthread_mutex_unlock(philo->right_f);
	pthread_mutex_unlock(philo->left_f);
}

void	put_and_sleep(t_phil *philo)
{
	printf_mutex_sleep(philo);
	printf_mutex_think(philo);
	if (philo->value_eat != -1 && philo->value_eat != 0)
		philo->value_eat -= 1;
}

void	*life_philo(void *str)
{
	t_phil	*philo;

	philo = str;
	if (philo->even == 1)
		ft_wait(philo->ti_eat);
	while (21)
	{
		forks(philo);
		lunch(philo);
		put_and_sleep(philo);
	}
}

int	philo_start(t_main *main, int j)
{
	while (++j < main->count_phil)
		pthread_create(&main->philo[j].thread, NULL,
			life_philo, &main->philo[j]);
	while (21)
	{
		j = -1;
		while (++j < main->count_phil)
		{
			if (ft_time(main->first) - main->philo[j].ti_last_eat
				>= main->philo[j].ti_die && main->philo[j].value_eat != 0)
			{
				pthread_mutex_lock(main->philo[j].output);
				printf("%lu ms %d died\n", ft_time(main->first),
					main->philo[j].philo_numb);
				return (1);
			}
			else if (check_status(main))
				return (1);
		}
		usleep(1);
	}
	return (0);
}
