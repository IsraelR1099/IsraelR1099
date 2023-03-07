#ifndef MATHS_H
# define MATHS_H

# include <math.h>
# include "../parser/parser.h"

double		ft_dot_product_vect(t_vector3d vector_left, t_vector3d vector_right);
t_vector3d	ft_vectorial_product(t_vector3d vector_left, t_vector3d
vector_right);
t_vector3d	ft_rest_vect(t_vector3d origin, t_vector3d obj);
t_vector3d	ft_sum_vect(t_vector3d first, t_vector3d second);
t_vector3d	ft_product_vect_scalar(t_vector3d vector, double scalar);

#endif
