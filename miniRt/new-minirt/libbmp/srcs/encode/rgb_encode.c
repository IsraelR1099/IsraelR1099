#include "../../includes/libbmp.h"

static int		create_bitmap_data(t_uchar *img,
				int i, t_bitmap_data **data,
	t_bitmap_data **ptr)
{
	if (!(*data))
	{
		if (!((*data) = new_bitmapdata_node((t_uchar)img[i],
		(t_uchar)img[i + 1], (t_uchar)img[i + 2])))
			return (0);
		(*ptr) = (*data);
	}
	else
	{
		if (!((*ptr)->next = new_bitmapdata_node((t_uchar)img[i],
		(t_uchar)img[i + 1], (t_uchar)img[i + 2])))
			return (0);
		(*ptr) = (*ptr)->next;
	}
	return (1);
}

int				fill_imagedata(t_bmp *bmp, t_uchar *img,
				int width, int height)
{
	t_bitmap_data	*ptr;
	int				i;
	int				j;
	int				k;

	k = 0;
	j = width * height * 4;
	i = j - (width * 4);
	ptr = NULL;
	while (j > 0)
	{
		while (i < j)
		{
			if (!(create_bitmap_data(img, i, &bmp->data, &ptr)))
				return (0);
			i += 4;
		}
		bmp->row_ptr[k] = ptr;
		k++;
		j -= width * 4;
		i = j - (width * 4);
	}
	return (1);
}

static void		get_row(t_bitmap_data **data, char *row, t_uint len)
{
	t_uint	i;

	i = 0;
	while (i < len)
	{
		row[i] = (*data)->rgb.color[0];
		row[i + 1] = (*data)->rgb.color[1];
		row[i + 2] = (*data)->rgb.color[2];
		(*data) = (*data)->next;
		i += 3;
	}
}

int				write_rgb(t_bmp *bmp)
{
	int				i;
	char			*row;
	t_uint			len;
	t_bitmap_data	*ptr;

	i = bmp->info_header->height - 1;
	len = bmp->info_header->width * 3;
	ptr = bmp->data;
	if (!(row = (char*)malloc(sizeof(char) * len)))
		return (0);
	while (i != -1)
	{
		get_row(&ptr, row, len);
		write(bmp->fd, row, len);
		if (bmp->padding > 0)
			write(bmp->fd, "\0", bmp->padding);
		i--;
	}
	free(row);
	return (1);
}
