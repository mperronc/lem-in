/* 42 Header */

#include "../../incl/lem-in.h"

static int	only_numbers(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int		get_ants(char *nants)
{
	int		ants;

	if (only_numbers(nants))
	{
		ants = ft_atoi(nants);
		if (ants > 0)
			return ants;
	}
	ft_putstr("ERROR\n");
	exit(EXIT_FAILURE);
}
