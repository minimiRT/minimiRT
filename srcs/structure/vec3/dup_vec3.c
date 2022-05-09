#include "vec3.h"
#include "utils.h"
#include <stdlib.h>

t_vec3	*dup_vec3(t_vec3 vec)
{
	t_vec3	*duped;

	duped = malloc(sizeof(t_vec3));
	ft_assert(duped != NULL, "Assert: malloc failed in dup_vec3\n");
	duped->x = vec.x;
	duped->y = vec.y;
	duped->z = vec.z;
	return (duped);
}
