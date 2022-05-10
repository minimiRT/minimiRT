#ifndef TRACING_H
# define TRACING_H

# include "scene.h"
# include "enum.h"
# include "ray.h"
# include "hit_record.h"
# include "mlx.h"

void		drive_ray_tracing(t_scene *scene);
t_bool		hit_objects(t_objects *objects, t_ray ray, t_hit_record *record);
t_color3	get_color_from_phong_lighting(t_scene *scene, t_ray pixel_ray, t_hit_record record);
void		draw_pixel(t_scene *scene, t_color3 color, double u, double v);

#endif