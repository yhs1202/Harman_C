// printf, format specifiers
#if 0
#include <stdio.h>

int main() {
    printf("Hello, World1!\n");  // end of line
    printf("Hello, World2!\b");  // backspace
    printf("Hello, World3!\t");  // tab
    printf("Hello, World4!\r");  // carriage return -> go to beginning of line
    printf("\a");  // alert
    return 0;
}
#endif

// integer, float, double, char, string
#if 0
#include <stdio.h>

int main() {
    int a = 5;              // 4-bytes
    printf("Integer: %d\n", a);
    printf("Size of Integer: %zu bytes\n", sizeof(a));    
    // Warning: format '%d' expects argument of type 'int', but argument 2 has type 'size_t'
    printf("Size of Integer: %d bytes\n", (int)sizeof(a)); 

    float b = 5.5;          // 4-bytes
    printf("Float: %.2f\n", b); // 5.50
    printf("Size of Float: %zu bytes\n", sizeof(b));

    double c = 5.555555;    // 8-bytes
    printf("Double: %.6f\n", c); // 5.555555
    printf("Double: %.lf\n", c); // 6 -> rounded
    printf("Size of Double: %zu bytes\n", sizeof(c));
    
    char d = 'A';           // 1-byte
    printf("Char: %c\n", d);     // A
    printf("Char_int: %d\n", d); // ASCII value (65)
    printf("Size of Char: %zu bytes\n", sizeof(d));

    char str[] = "Hello";   // 6-bytes (5 chars + null terminator)
    char *str2 = "World";   // 6-bytes (5 chars + null terminator)
    printf("String: %s\n", str);
    printf("Size of String: %zu bytes\n", sizeof(str));
    printf("String2: %s\n", str2);
    printf("Size of String2: %zu bytes\n", sizeof(str2));

    short e = 10;            // 2-bytes
    printf("Short: %hd\n", e);

    long f = 100L;           // 4-bytes
    printf("Long: %ld\n", f);

    long long g = 1000LL;    // 8-bytes
    printf("Long Long: %lld\n", g);

    // Constant
    const double pi = 3.1415926535897932;
    printf("Value of Pi: %.30lf\n", pi);

    return 0;
}
#endif

// Input/Output
#if 0
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);    // for clang
    // scanf_s("%d", &a);
    printf("You entered: %d\n", a);

    return 0;
}
#endif

// Arithmetic operations, Increment/Decrement
#if 0
#include <stdio.h>

int main() {
    int a = 5;
    int b = 3;
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);
    printf("%d // %d = %d\n", a, b, a / b);
    printf("%d %% %d = %d\n", a, b, a % b);

    int num = 10;
    printf("Num: %d\n", ++num);   // 11
    printf("Num: %d\n", num++);   // 11
    printf("Num: %d\n", num);     // 12

    return 0;
}
#endif

// Bitwise operations
#if 0
#include <stdio.h>

int main() {
    int a = 5;  // 0101
    int b = 3;  // 0011
    printf("%d & %d = %d\n", a, b, a & b);  // AND -> 0001(1)
    printf("%d | %d = %d\n", a, b, a | b);  // OR -> 0111(7)
    printf("%d ^ %d = %d\n", a, b, a ^ b);  // XOR -> 0110(6)
    printf("~%d = %d\n", a, ~a);            // NOT -> 1010 -> (-1) * (0101 + 1) -> -0110 -> -6
    printf("%d << 1 = %d\n", a, a << 1);    // Left shift -> 1010(10)
    printf("%d >> 1 = %d\n", a, a >> 1);    // Right shift -> 0010(2)

    return 0;
}

#endif

// Switch Case
#if 0
#include <stdio.h>

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        printf("300\n");
        break;
    case 2:
        printf("200\n");
        break;
    case 3:
        printf("100\n");
        break;
    
    default:
        break;
    }

    return 0;
}
#endif

// boj 10951
#if 0
#include <stdio.h>

int main() {
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF)
        printf("%d\n", a + b);
    return 0;
}
#endif

// Prime Factorization
#if 0
#include <stdio.h>

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    for (int i = 1; i <= num/2; i++) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }
    printf("%d\n", num);
    return 0;
}
#endif

// Random Number Generation
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed the random number generator

    int random_num = rand() % 100 + 1;  // Generate a random number between 1 and 100
    printf("Random Number: %d\n", random_num);
    return 0;
}
#endif

// Star
#if 0
#include <stdio.h>

int main() {
    int n=5;
    printf("(1)\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    printf("(2)\n");
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    printf("(3)\n");
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    printf("(4)\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            printf(" ");
        }
        for (int k = n; k >= i; k--) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
#endif

// fibonacci
#if 0
#include <stdio.h>

int fibonacci(int num) {
    if (num <= 2) return 1;
    else return fibonacci(num - 1) + fibonacci(num - 2);
}

double fibonacci2(double num) {
    if (num <= 2) return 1;
    double a = 1, b = 1, c;
    for (double i = 3; i <= num; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main() {
    // printf("%d\n", fibonacci(50));
    printf("%lf\n", fibonacci2(50));
    return 0;
}
#endif

// perfect number
#if 0
#include <stdio.h>
int is_divisor(int a, int b) {
    return a % b == 0;
}
int get_sum_of_divisor(int n) {
    int sum = 0;
    for (int i = 1; i<= n/2; i++) {
        if (is_divisior(n, i)) {
            sum += i;
        }
    }
    return sum;
}
int is_perfect_number(int n) {
    return get_sum_of_divisor(n) == n;
}

int main() {
    for (int i = 1; i <= 100000; i++) {
        if (i % 1000 == 0) {
            printf("Checking up to %d...\n", i);
        }
        if (is_perfect_number(i)) {
            printf("%d is a perfect number.\n", i);
        }
    }
    return 0;
}
#endif

// array
#if 1
#include <stdio.h>

int main() {
    int arr[5];
    arr[0] = 1;
    arr[1] = 2;

    int arr2[5] = {3, 7, 22, 71, 9};

    for (int i = 0; i < 5; i++) {
        if (*(arr2 + i) % 2) {
            printf("%d\n", *(arr2 + i));
        }
    }
    return 0;
}

#endif

// array sum/avg
#if 0
#include <stdio.h>

int main() {
    int scores[5] = {0};
    for (int i = 0; i < 5; i++) {
        printf("input >> ");
        scanf("%d", &scores[i]);
    }

    int sum = 0;
    double avg;
    
    for (int i = 0; i < 5; i++) {
        sum += scores[i];
    }
    avg = sum / 5.0;
    printf("sum ->%d\n", sum);
    printf("avg ->%lf\n", avg);
    return 0;
}
#endif

// lottery generator
#if 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lotto[6];
    srand(time(NULL));  // Seed the random number generator

    for (int i = 0; i < 6; i++) {
        lotto[i] = rand() % 6 + 1;  // Generate random numbers between 1 and 45
        for (int j = 0; j < i; j++) {
            if (lotto[i] == lotto[j]) {
                // If a duplicate is found, generate a new number
                lotto[i] = rand() % 6 + 1;
                j = -1;  // Restart the check
            }
        }   
    }
    printf("Lotto Numbers: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", lotto[i]);
    }
    printf("\n");

    return 0;
}
#endif