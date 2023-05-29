#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int count = 0;
	char c;
	char *s;
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = (char)va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				if (s != NULL)
				{
                    			while (*s != '\0')
                    			{
                        			putchar(*s);
                        			s++;
                        			count++;
                    			}
                		}
            		}
			else if (*format == '%')
            		{
                		putchar('%');
                		count++;
            		}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return count;
}
