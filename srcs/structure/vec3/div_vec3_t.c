#include "vec3.h"
#include "utils.h"

t_vec3	div_vec3_t(t_vec3 vec, double t)
{
	ft_assert(t != 0, "Assert: division by zero in div_vec3_t\n");
	vec.x /= t;
	vec.y /= t;
	vec.z /= t;
	return (vec);
}
