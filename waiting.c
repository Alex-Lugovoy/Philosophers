#include "philo.h"

unsigned long	ft_time(unsigned long temp)
{
	struct timeval	timezone;
	unsigned long	result;

	gettimeofday(&timezone, NULL);
	result = (timezone.tv_sec * 1000) + (timezone.tv_usec / 1000) - temp;
	return (result);
}

void	ft_wait(unsigned long waiting)
{
	unsigned long	tmp;

	tmp = ft_time(0);
	while (ft_time(0) - tmp < waiting)
		usleep(100);
}
