#include "philo.h"

static int	ft_isspace(int s)
{
	if ((s == ' ' || s == '\v' || s == '\t' || s == '\f'
		|| s == '\n' || s == '\r') && s != '\0')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *s)
{
	int		i;
	int		minus;
	long int	cif;

	i = 0;
	minus = 1;
	cif = 0;
	while (1 == ft_isspace(s[i]) && s[i] != '\0')
		i++;
	if (s[i] == '-')
		minus = -1;
	if ((s[i] == '+' || s[i] == '-') && s[i] != '\0')
		i++;
	while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
	{
		cif = (cif * 10) + (s[i] - 48) * minus;
		i++;
		if (cif < 0 && minus > 0)
			return (-1);
		if (cif > 0 && minus < 0)
			return (0);
	}
	return ((int)cif);
}


static int	ft_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	argv_check(int argc, char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || ft_isdigit(argv[1]))
		return (1);
	if (ft_atoi(argv[2]) <= 0 || ft_isdigit(argv[2]))
		return (1);
	if (ft_atoi(argv[3]) <= 0 || ft_isdigit(argv[3]))
		return (1);
	if (ft_atoi(argv[4]) <= 0 || ft_isdigit(argv[4]))
		return (1);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0 || ft_isdigit(argv[5]))
			return (1);
	}
	return (0);
}
