#include <unistd.h>
#include <stdio.h>

typedef struct s_point3d
{
	double	x;
	double	y;
	double	z;
}	t_point3d;


typedef struct s_vector3d
{
	double	x;
	double	y;
	double	z;
}	t_vector3d;

void	print(t_vector3d *p)
{
	printf("x %f, y %f, z %f\n", p->x, p->y, p->z);
}

int	main(void)
{
	t_point3d	p;
	t_vector3d	v;

	p.x = 5;
	p.y = 15;
	p.z = 25;
	print((t_vector3d *)&p);
	return (0);
}
