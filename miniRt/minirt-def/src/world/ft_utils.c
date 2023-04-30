#include "world.h"

void	ft_set_init(t_light **lights, t_ambient *amb)
{
	int	i;
	int	count;

	i = 0;
	count = ft_count_light(amb);
	while (i < count)
	{
		lights[i] = NULL;
		i++;
	}
}
