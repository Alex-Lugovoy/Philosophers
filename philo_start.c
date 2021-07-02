#include "philo.h"

// void forks(t_phil *philo)
// {
// 	pthread_mutex_lock(philo->output);
// 	printf("%lu ms %d is thinking\n", ft_time(philo->main->first), philo->philo_numb);
// 	pthread_mutex_unlock(philo->output);
// 	pthread_mutex_lock(philo->left_f);
// 	pthread_mutex_lock(philo->output);
// 	printf("%lu ms %d has taken a fork\n", \
// 	ft_time(philo->main->first), philo->philo_numb);
// 	pthread_mutex_unlock(philo->output);
// 	pthread_mutex_lock(philo->right_f);
// 	pthread_mutex_lock(philo->output);
// 	printf("%lu ms %d has taken a fork\n", \
// 	ft_time(philo->main->first), philo->philo_numb);
// 	pthread_mutex_unlock(philo->output);
// }

void forks(t_phil *philo)
{
	pthread_mutex_lock(philo->output);
	printf("%lu ms %d is thinking\n", ft_time(philo->st_time), philo->philo_numb);
	pthread_mutex_unlock(philo->output);
	pthread_mutex_lock(philo->left_f);
	pthread_mutex_lock(philo->output);
	printf("%lu ms %d has taken a fork\n", \
	ft_time(philo->st_time), philo->philo_numb);
	pthread_mutex_unlock(philo->output);
	pthread_mutex_lock(philo->right_f);
	pthread_mutex_lock(philo->output);
	printf("%lu ms %d has taken a fork\n", \
	ft_time(philo->st_time), philo->philo_numb);
	pthread_mutex_unlock(philo->output);
}

void lunch(t_phil *philo)
{
	philo->ti_last_eat = ft_time(philo->st_time);
	pthread_mutex_lock(philo->output);
	printf("%lu ms %d is eating\n", ft_time(philo->st_time), philo->philo_numb);
	pthread_mutex_unlock(philo->output);
	ft_wait(philo->ti_eat);
}

void put_and_sleep(t_phil *philo)
{
	pthread_mutex_unlock(philo->right_f);
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_lock(philo->output);
	printf("%lu ms %d is sleeping\n", \
	ft_time(philo->st_time), philo->philo_numb);
	pthread_mutex_unlock(philo->output);
	ft_wait(philo->ti_sleep);
	if (philo->value_eat != -1)
		philo->value_eat -= 1;
}

void *life_philo(void *str)
{
	t_phil *philo;

	philo = str;
	if (philo->even == 1)
		ft_wait(philo->ti_eat);
	while (21)
	{
		forks(philo);
		lunch(philo);
		put_and_sleep(philo);
		if (philo->value_eat == 0)
			return NULL;
	}
}

int philo_start(t_main *main, int j)
{
	while (++j < main->count_phil)
		pthread_create(&main->philo[j].thread, NULL, life_philo, &main->philo[j]);
	while (21)
	{
		j = -1;
		while (++j < main->count_phil)
		{
			if (ft_time(main->first) - main->philo[j].ti_last_eat \
			>= main->philo[j].ti_die && main->philo[j].value_eat != 0)
			{
				pthread_mutex_lock(main->philo[j].output);
				printf("%lu ms %d died\n", ft_time(main->first), main->philo[j].philo_numb);
				return (1);
			}
			else if (check_status(main))
				return (1);
		}
		usleep(1);
	}
	return (0);
}
