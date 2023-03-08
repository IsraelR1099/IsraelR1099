#include "world.h"

void	ft_set_world(t_ambient *amb, t_world *world)
{
	world->camera = ft_build_camera(amb);
}
