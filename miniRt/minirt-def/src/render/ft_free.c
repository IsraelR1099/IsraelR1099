#include "../../include/miniRT.h"

t_object	*ft_free_advance(t_object *tmp)
{
	t_object	*tmp2;

	if (tmp->type == sp)
	{

			sphere = (t_sphere *)tmp;
			tmp = sphere->obj;
			free(sphere);
		}
		else if (tmp->type == pl)
		{
			plane = (t_plane *)tmp;
			tmp = plane->obj;
			free(plane);
		}
		else if (tmp->type == cy)
		{
			cyl = (t_cylinder *)tmp;
			tmp = cyl->obj;
			free(cyl);
		}
		else if (tmp->type == di)
		{
			disk = (t_disk *)tmp;
			tmp = disk->obj;
			free(disk);
		}
		else
			break ;
	}
