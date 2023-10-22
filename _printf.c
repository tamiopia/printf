#include "main.h"

int _printf(const char *format, ...);

int main()
{
    int num = 42;
    char *str = "Hello, world!";

    printf("Number: %d\n", num);
    printf("String: %s\n", str);

    // Use _printf with your custom format
    _printf("Number: %d\n", num);
    _printf("String: %s\n", str);

    return 0;
}


/**
 * _printf - A simplified implementation of printf.
 * @format: A format string.
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    for (const char *c = format; *c; c++)
    {
        if (*c != '%')
        {
            putchar(*c);  // Print non-% character.
            printed_chars++;
        }
        else
        {
            c++;
            if (*c == 'c')
            {
                char ch = va_arg(args, int);  // Get a character from arguments.
                putchar(ch);  // Print the character.
                printed_chars++;
            }
            else if (*c == 's')
            {
                const char *str = va_arg(args, const char *);  // Get a string from arguments.
                for (; *str; str++)
                {
                    putchar(*str);  // Print each character of the string.
                    printed_chars++;
                }
            }
            else if (*c == '%')
            {
                putchar('%');  // Print a literal '%' character.
                printed_chars++;
            }
            else
            {
                putchar('%');  // Print the '%' character.
                putchar(*c);   // Print any other character after '%'.
                printed_chars += 2;  // Increment character count by 2.
            }
        }
    }

    va_end(args);

    return printed_chars;
}
