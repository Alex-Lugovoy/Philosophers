#include "philo.h"

void	printf_mutex_fork(t_phil *philo)
{
	pthread_mutex_lock(philo->output);
	printf("%lu ms %d has taken a fork\n", \
	ft_time(philo->st_time), philo->philo_numb);
	pthread_mutex_unlock(philo->output);
}

void	printf_mutex_eat(t_phil *philo)
{
	pthread_mutex_lock(philo->output);
	printf("%lu ms %d is eating\n", ft_time(philo->st_time), philo->philo_numb);
	pthread_mutex_unlock(philo->output);
}

void	printf_mutex_sleep(t_phil *philo)
{
	pthread_mutex_lock(philo->output);
	printf("%lu ms %d is sleeping\n", \
	ft_time(philo->st_time), philo->philo_numb);
	pthread_mutex_unlock(philo->output);
	ft_wait(philo->ti_sleep);
}

void	printf_mutex_think(t_phil *philo)
{
	pthread_mutex_lock(philo->output);
	printf("%lu ms %d is thinking\n", ft_time(philo->st_time),
		philo->philo_numb);
	pthread_mutex_unlock(philo->output);
	ft_wait(philo->ti_eat);
}
