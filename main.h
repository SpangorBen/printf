#ifndef PRINTF_MAIN_H
#define PRINTF_MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/* --- MACROS --- */
#define BUFFER_SIZE 1024
#define BINARY_BASE "01"
#define OCTAL_BASE "01234567"
#define DECIMAL_BASE "0123456789"
#define HEXADECIMAL_BASE_UPPER "0123456789ABCDEF"
#define HEXADECIMAL_BASE_LOWER "0123456789abcdef"
#define PRINT_VAR_NAME(var) printf(#var " = %d\n", var)

#define CHECK_RIGHT_JUSTIFICATION(value, format, count, justifier_func) \
	{ \
		if (!in_flags('-', format.flags)) \
			justifier_func(value, format, count); \
	}

#define CHECK_LEFT_JUSTIFICATION(value, format, count, justifier_func) \
	{ \
		if (in_flags('-', format.flags)) \
			justifier_func(value, format, count); \
	}

#define ABS(x) ((x) < 0 ? -(x) : (x))

#define UNUSED(x) (void)(x)

/** --- STRUCTURES --- */

/**
 * struct format_s - all the format information
 * @flags: flags
 * @width: width
 * @precision: precision
 * @length: length
 * @specifier: specifier
 */
typedef struct format_s
{
	char *flags;
	int width;
	int precision;
	int length;
	char specifier;
} format_t;

/**
 * struct format_specifier_s - format specifier
 * @specifier: specifier
 * @function: function to print the specifier
 */
typedef struct format_specifier_s
{
	char *specifier;
	void (*function)(va_list, format_t, void *);
} format_specifier;

/* --- FUNCTION PROTOTYPES --- */
void print_char(va_list, format_t, void *);
void print_string(va_list, format_t, void *);
void print_percent(va_list, format_t, void *);
void print_integer(va_list, format_t, void *);
void print_binary(va_list, format_t, void *);
void print_octal(va_list, format_t, void *);
void print_hex(va_list, format_t, void *);
void print_unsigned(va_list, format_t, void *);
void print_reverse(va_list, format_t, void *);
void print_rot13(va_list, format_t, void *);
void print_address(va_list, format_t, void *);
void print_string_non_printable(va_list, format_t, void *);


/* --- Get format functions --- */
int in_flags(char c, const char *flags);
char *get_flags(const char **);
int get_width(const char **);
int get_precision(const char **);
int get_length(const char **);
char get_specifier(const char **);
format_t get_format(const char **);


int get_number_length(int);
void justifier(char *, format_t, void *);

int _printf(const char *format, ...);
void _puts(char *, void *);
void _putchar(char, void *);

int _strlen(const char *);
int _atoi(const char *);
char *_itoa(ssize_t, char *);
char *_utoa(size_t, char *);
char *_strdup(char *);

void print_hex_helper(unsigned long int number, char *base, void *count);

#endif /* PRINTF_MAIN_H */
