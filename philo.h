#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_phil
{
	int					philo_numb;
	int					even;
	int					value_eat;
	unsigned long long	st_time;
	unsigned long long	ti_eat;
	unsigned long long	ti_die;
	unsigned long long	ti_sleep;
	unsigned long long	ti_last_eat;
	pthread_mutex_t		*left_f;
	pthread_mutex_t		*right_f;
	pthread_mutex_t		*output;
	pthread_t			thread;
}						t_phil;

typedef struct s_main
{
	int						count_phil;
	t_phil					*philo;
	unsigned long long		first;
	pthread_mutex_t			output;
	pthread_mutex_t			*forks;
}						t_main;

int				argv_check(int argc, char **argv);
int				ft_atoi(const char *s);
int				memory_alloc(char **arg, t_main *main, int argc);
int				philo_start(t_main *main, int j);
unsigned long	ft_time(unsigned long temp);
void			ft_wait(unsigned long waiting);
void			free_pthread(t_main *main);
int				check_status(t_main *main);
int				fill_philo(char **arg, t_main *main);
void			printf_mutex_fork(t_phil *philo);
void			printf_mutex_eat(t_phil *philo);
void			printf_mutex_sleep(t_phil *philo);
void			printf_mutex_think(t_phil *philo);

#endif
