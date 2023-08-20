#include "main.h"
/**
  * _printf - function that produce output according to format
  * @format: the format to be specified
  * Return:
  * @...: ellipsis
  */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, format);
	while (format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int character = va_arg(ap, int);

				putchar(character);
				i++;
			}
			else if (*format == 's')
			{
				char *st = va_arg(ap, char*);

				while (*st)
				{
					putchar(*st);
					st++;
					i++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				i++;
			}
			else
			{
				putchar(*format);
				i++;
			}
			format++;
		}
	}
	va_end(ap);
	return i;
}
