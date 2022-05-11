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

void	draw_pixel(t_scene *scene, t_color3 color, double u, double v, int x, int y)
{
	int	*img;
	int	x_coord;
	int	y_coord;
	int	hex_color;

	img = (int *)(scene->mlx_info.data_addr);
	// x_coord = u * (double)(scene->canvas.width - 1);
	// y_coord = v * (double)(scene->canvas.height - 1);
	hex_color = get_hex_color(color);
	img[(y * scene->canvas.width) + x] = hex_color;
}
