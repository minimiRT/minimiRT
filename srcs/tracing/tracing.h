#ifndef TRACING_H
# define TRACING_H

# include "scene.h"
# include "enum.h"
# include "pixel.h"
# include "mlx.h"

// t_tracing
// hit_objects for considering light hit

void		drive_ray_tracing(t_scene *scene);

t_bool		hit_objects(t_objects *objects, t_trace *tracing);
t_color3	get_color_from_phong_lighting(t_scene *scene, t_trace *tracing);
void		draw_pixel(t_scene *scene, t_pixel *pixel);

//t_bool		hit_plane(t_object *object, t_ray ray, t_hit_record *record);
t_bool		hit_plane(t_object *object, t_trace *tracing);

#endif