#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

void test_printf(const char *test_name, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    char printf_buffer[1000];
    va_list args_copy;
    va_copy(args_copy, args);
    int printf_result = vsnprintf(printf_buffer, sizeof(printf_buffer), format, args_copy);
    va_end(args_copy);

    char ft_printf_buffer[1000];
    int saved_stdout = dup(STDOUT_FILENO);
    int pipe_fd[2];
    pipe(pipe_fd);
    dup2(pipe_fd[1], STDOUT_FILENO);
    close(pipe_fd[1]);

    va_list args_copy2;
    va_copy(args_copy2, args);
    int ft_printf_result = ft_printf(format, args_copy2);
    va_end(args_copy2);

    fflush(stdout);
    read(pipe_fd[0], ft_printf_buffer, sizeof(ft_printf_buffer));
    dup2(saved_stdout, STDOUT_FILENO);

    if (printf_result == ft_printf_result && ft_strcmp(printf_buffer, ft_printf_buffer) == 0) {
        printf(GREEN "PASS" RESET " %s\n", test_name);
    } else {
        printf(RED "FAIL" RESET " %s\n", test_name);
        printf("Expected: %d, \"%s\"\n", printf_result, printf_buffer);
        printf("Got     : %d, \"%s\"\n", ft_printf_result, ft_printf_buffer);
    }

    va_end(args);
}

int main()
{
    test_printf("Basic string", "Hello, world!");
    test_printf("Multiple conversions", "Int: %d, String: %s, Char: %c", 42, "test", 'X');

    test_printf("Character - ASCII", "%c", 'A');
    test_printf("Character - Number", "%c", 42);
    test_printf("Character - NULL", "%c", 0);

    test_printf("String - Basic", "%s", "Hello, world!");
    test_printf("String - Empty", "%s", "");
    test_printf("String - NULL", "%s", NULL);

    test_printf("Integer - Positive", "%d", 42);
    test_printf("Integer - Negative", "%d", -42);
    test_printf("Integer - Zero", "%d", 0);
    test_printf("Integer - INT_MAX", "%d", INT_MAX);
    test_printf("Integer - INT_MIN", "%d", INT_MIN);

    test_printf("Unsigned - Basic", "%u", 42);
    test_printf("Unsigned - Zero", "%u", 0);
    test_printf("Unsigned - UINT_MAX", "%u", UINT_MAX);

    test_printf("Hexadecimal - Lowercase", "%x", 0xabcdef);
    test_printf("Hexadecimal - Uppercase", "%X", 0xABCDEF);
    test_printf("Hexadecimal - Zero", "%x", 0);

    int n = 42;
    test_printf("Pointer", "%p", (void *)&n);
    test_printf("Pointer - NULL", "%p", NULL);

    test_printf("Percent sign", "%%");

    test_printf("Mixed - 1", "Hello %s, you are %d years old and your favorite letter is %c", "John", 25, 'Z');
    test_printf("Mixed - 2", "Hex: %x, Pointer: %p, Unsigned: %u", 0xdecaf, (void *)&n, 123456);

    test_printf("Edge - Empty format string", "");
    test_printf("Edge - Only conversion specifiers", "%d%s%c%u%x%X%p%%");

    return 0;
}
