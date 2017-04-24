#include "../../incl/lem-in.h"

int	only_numbers(char *s)
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
