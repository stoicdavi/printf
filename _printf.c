#include "main.h"
void _p_buffer(int *buf_ind, char buff);
/**
  * _printf - function that produce output according to format
  * @format: the format to be specified
  * Return:
  * @...: ellipsis
  */
int _printf(const char *format, ...)
{
	va_list ap;
	int b = 0, print_char = 0, print = 0;
	char buff[BUFF_SIZE];
	int wdth, size, p, b_index = 0, flags;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	for (b = 0; format[b] != '\0'; b++)
	{
		if (format[b] != '%')
		{
			buff[b_index++] = format[b];
			if (b_index == BUFF_SIZE)
			{
				_p_buffer(buff, &b_index);
				print_char++;
			}
		}
		else
		{
			_p_buffer(buff, &b_index);
			wdth = get_width(format, &b, ap);
			flags = get_flags(format, &b);
			p = get_precision(format, &b, ap);
			size = get_size(format, &b);
			b++;
			print = h_print(format, &b, ap, buff, flags, wdth, p, size);
			if (print == -1)
			{
				va_end(ap);
				return (-1);
			}
			print_char += print;
		}
	}
	_p_buffer(buff, &b_index);
	va_end(ap);
	return print_char;
}
