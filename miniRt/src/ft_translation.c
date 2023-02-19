#include "../include/miniRT.h"

double	ft_translationX(t_vector cameraPos, t_vector direction)
{
	double		translationX;
	t_vector	rightVector;
	t_vector	tmpUpVector;
	t_vector	forwardVector;

	tmpUpVector.x = 0;
	tmpUpVector.y = 1;
	tmpUpVector.z = 0;
	forwardVector = ft_forwardVector(cameraPos, direction);
	rightVector = ft_rightAxis(tmpUpVector, forwardVector);
	translationX = ft_dot_product_vect(cameraPos, rightVector);
	return (translationX);
}

double	ft_translationY(t_vector cameraPos)
{
	double	translationY;

	translationY = ft_dot_product_vect(cameraPos, UpVector);
	return (translationY);
}

double	ft_translationZ(t_vector cameraPos)
{
	double	translationZ;

	translationZ = ft_dot_product_vect(cameraPos, forwardVector);
	return (translationZ);
}
