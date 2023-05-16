#include "geometricobj.h"

//a = d.x² + d.z²
static double	ft_calc_a(t_ray *ray)
{
	double	first;
	double	second;

	first = ray->direction.x * ray->direction.x;
	second = ray->direction.z * ray->direction.z;
	return (first + second);
}

//2 * (origin.x² + origin.z²)
static double	ft_calc_b(t_ray *ray)
{
	double	first;
	double	second;

	first = ray->origin.x * ray->direction.x;
	second = ray->origin.z * ray->direction.z;
//	printf("first es %f second %f\n", first, second);
	return (2.0 * (first + second));
}

//origin.x² + origin.z² - radius²
static double	ft_calc_c(t_cylinder *cyl, t_ray *ray)
{
	double	radius;
	double	first;
	double	second;

	first = ray->origin.x * ray->origin.x;
	second = ray->origin.z * ray->origin.z;
	radius = cyl->diameter / 2;
	return (first + second - (radius * radius));
}

static double	ft_check(double scalar_a, double scalar_b, double scalar_c)
{
	double	first;
	double	second;
	double	check;

	first = scalar_b * scalar_b;
	second = 4.0 * scalar_a * scalar_c;
	check = first - second;
	if (check >= 0)
	{
		check = ((-1 * scalar_b) - sqrt(first - second)) / (2.0 * scalar_a);
		if (check > 0.0001)
			return (check);
		check = ((-1 * scalar_b) + sqrt(first - second)) / (2.0 * scalar_a);
		if (check > 0.0001)
			return (check);
	}
	return (0);
}

double	ft_check_cyl(t_cylinder *cyl, t_ray *ray)
{
	double	scalar_a;
	double	scalar_b;
	double	scalar_c;
	double	t;

	scalar_a = ft_calc_a(ray);
	scalar_b = ft_calc_b(ray);
	scalar_c = ft_calc_c(cyl, ray);
//	printf("scalar a %f, b %f, c %f\n", scalar_a, scalar_b, scalar_c);
	t = ft_check(scalar_a, scalar_b, scalar_c);
	if (t <= 0)
		return (0);
	return (t);
}
