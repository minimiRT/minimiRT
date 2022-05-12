#include "tracing.h"

int	get_hex_color(t_color3 color)
{
	int	hex_color;
	int	red;
	int	green;
	int	blue;

	hex_color = 0;
	red = (int)(color.x * 255.999);
	green = (int)(color.y * 255.999);
	blue = (int)(color.z * 255.999);
	hex_color |= (red << 16) | (green << 8) | blue;
	return (hex_color);
}

void	draw_pixel(t_scene *scene, t_pixel *pixel)
{
	int	*img;
	int	hex_color;

	img = (int *)(scene->mlx_info.data_addr);
	hex_color = get_hex_color(pixel->color);
	img[(((scene->canvas.height - 1) - pixel->y_coord) * scene->canvas.width) \
		+ pixel->x_coord] = hex_color;
}
