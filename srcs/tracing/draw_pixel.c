#include "tracing.h"

int	get_hex_color(t_color3 color)
{
	int	hex_color;
	int	red;
	int	green;
	int	blue;

	red = (int)(color.x);
	green = (int)(color.y);
	blue = (int)(color.z);
	hex_color = (red << 16) | (green << 8) | blue;
	return (hex_color);
}

void	draw_pixel(t_scene *scene, t_color3 color, double u, double v)
{
	int	*img;
	int	x_coord;
	int	y_coord;
	int	hex_color;

	img = (int *)(scene->mlx_info.data_addr);
	x_coord = u * (double)(scene->canvas.width - 1);
	y_coord = v * (double)(scene->canvas.height - 1);
	hex_color = get_hex_color(color);
	img[(y_coord * scene->canvas.width) + x_coord] = hex_color;
}
