#include <stdio.h>
#include "ft_printf.h"

int main(void) {
    char c = 'A';
    printf("Expected output: A\n");
    ft_printf("Actual output: %c\n", c);

    char *str = "Hello, World!";
    printf("Expected output: Hello, World!\n");
    ft_printf("Actual output: %s\n", str);

    int num = 42;
    printf("Expected output: %p\n", &num);
    ft_printf("Actual output: %p\n", &num);

    int decimal = 1234;
    printf("Expected output: 1234\n");
    ft_printf("Actual output: %d\n", decimal);

    int integer = -5678;
    printf("Expected output: -5678\n");
    ft_printf("Actual output: %i\n", integer);

    unsigned int u = 3000000000U;
    printf("Expected output: 3000000000\n");
    ft_printf("Actual output: %u\n", u);

    int hex_lower = 255;
    printf("Expected output: ff\n");
    ft_printf("Actual output: %x\n", hex_lower);

    int hex_upper = 255;
    printf("Expected output: FF\n");
    ft_printf("Actual output: %X\n", hex_upper);

    printf("Expected output: %%\n");
    ft_printf("Actual output: %%\n");

    printf("Expected output: '   42'\n");
    ft_printf("Actual output: '%5d'\n", 42);

    printf("Expected output: '42   '\n");
    ft_printf("Actual output: '%-5d'\n", 42);

    printf("Expected output: '00042'\n");
    ft_printf("Actual output: '%05d'\n", 42);

    printf("Expected output: '  3.14'\n");
    ft_printf("Actual output: '%7.2f'\n", 3.14159);

    printf("Expected output: ' 42'\n");
    ft_printf("Actual output: '% d'\n", 42);

    printf("Expected output: '+42'\n");
    ft_printf("Actual output: '%+d'\n", 42);

    printf("Expected output: '0x2a'\n");
    ft_printf("Actual output: '%#x'\n", 42);
    printf("Expected output: '0X2A'\n");
    ft_printf("Actual output: '%#X'\n", 42);

    printf("Expected output: '0x0002a'\n");
    ft_printf("Actual output: '%#07x'\n", 42);

    return 0;
}
