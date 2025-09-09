// memory allocation 
#if 0
#include <stdio.h>
#include <stdlib.h>
int main() {

    // boj -> N input
    int N;
    scanf("%d", &N);
    
    // static memory allocation
    int *array = (int*)malloc(N * sizeof(int)); // 4*N bytes, heap memory
    
    // check memory allocation success
    if (array == NULL) exit(1);

    // use the allocated memory
    for (int i = 0; i < N; i++) {
        *(array + i) = i + 1;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", *(array + i));
    }
    free(array); // free the allocated memory
    array = NULL; // avoid dangling pointer

    return 0;
}
#endif

// malloc, calloc, realloc
#if 0
#include <stdio.h>
#include <stdlib.h>
int main() {
    // malloc
    int N = 5;
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) exit(1);
    // for (int i = 0; i < N; i++) arr[i] = i + 1;
    for (int i = 0; i < N; i++) printf("%3d ", arr[i]);
    
    // calloc
    int *arr2 = (int *)calloc(N, sizeof(int));  // initialize to 0
    if (arr2 == NULL) exit(1);
    for (int i = 0; i < N; i++) printf("%3d ", arr2[i]);
    printf("\n");
    printf("intiial address: %p\n", arr2);

    // realloc
    N = 10;
    arr2 = (int *)realloc(arr2, N * sizeof(int));
    if (arr2 == NULL) exit(1);
    for (int i = 0; i < N; i++) printf("%3d ", arr2[i]);
    printf("\n");
    printf("realloc address: %p\n", arr2); // may change address


    free(arr);
    free(arr2);
    arr = NULL;
    arr2 = NULL;
    return 0;
}
#endif

// boj 10810
#if 0
#include <stdio.h>
#include <stdlib.h>
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int *basket = (int *)calloc(N, sizeof(int));
    if (basket == NULL) exit(1);
    for (int i = 0; i < M; i++) {
        int start, end, num;
        scanf("%d %d %d", &start, &end, &num);
        for (int j = start - 1; j < end; j++) {
            basket[j] = num;
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", basket[i]);
    }
    free(basket);
    basket = NULL;
    return 0;
}
#endif

// boj 10818
#if 0
#include <stdio.h>
#include <stdlib.h>
int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // initialize array 1 to N
    int *basket = (int *)malloc(N * sizeof(int));
    if (basket == NULL) exit(1);
    for (int i = 0; i < N; i++) {
        basket[i] = i + 1;
    }
    
    // swap process with M times
    for (int j = 0; j < M; j++) {
        int temp;
        int a, b;
        scanf("%d %d", &a, &b);

        temp = basket[a-1];
        basket[a-1] = basket[b-1];
        basket[b-1] = temp;
    }

    // print
    for (int i = 0; i < N; i++) {
        printf("%d ", basket[i]);
    }

    free(basket);
    basket = NULL;
    return 0;
}
#endif

// command line argument (argc, argv)
// argc: argument count
// argv: argument vector (array of strings)
// argv[0]: program name (day4.exe)
// argv[1]: first argument
// argv[2]: second argument
// ...
#if 0
#include <stdio.h>
#include <stdlib.h> // for atoi
// int main(int argc, char **argv) {
int main(int argc, char *argv[]) {
    printf("argc: %d\n", argc);
    int count = atoi(argv[1]); // convert string to integer
    int sum = 0;
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    return 0;
}
#endif

// structure data type
#if 0
#include <stdio.h>
#pragma pack(1) // disable padding, 
struct student {
    /* data */
    int num;
    double grade;

};

struct example {
    int a;      // 4 bytes
    double b;   // 8 bytes
    char c;     // 1 byte
}; 

struct introduce {
    char name[50];
    int age;
    char mbti[50];
};

int main() {
    // Type1
    struct student s1 = {1001, 4.3};
    // Type2
    struct student s2;
    s2.num = 1002;
    s2.grade = 3.9;

    printf("s1: %d, %.2f\n", s1.num, s1.grade);
    printf("s2: %d, %.2f\n", s2.num, s2.grade);
    // byte alignment
    // 4 + 8 = 12 -> 16 bytes (4 bytes padding)
    // 4 bytes padding to make the total size a multiple of the largest member size (8 bytes)
    printf("size of struct student: %d\n", sizeof(struct student)); // 12 bytes (4 + 8)
    printf("size of struct example: %d\n", sizeof(struct example)); // 24 bytes (4 + 4(padding) + 8 + 1 + 7(padding))


    struct introduce person1;
    scanf("%s %d %s", person1.name, &person1.age, person1.mbti);
    printf("name: %s, age: %d, mbti: %s\n", person1.name, person1.age, person1.mbti);

    return 0;
}
#endif

// pointer structure
#if 0
#include <stdio.h>
#include <stdlib.h>
struct intro {
    char *name;
    int age;
    char *mbti;
};
int main() {
    struct intro person1;
    person1.name = (char *)malloc(50 * sizeof(char));
    person1.mbti = (char *)malloc(50 * sizeof(char));
    if (person1.name == NULL || person1.mbti == NULL) exit(1);

    scanf("%s %d %s", person1.name, &person1.age, person1.mbti);
    printf("name: %s, age: %d, mbti: %s\n", person1.name, person1.age, person1.mbti);
    return 0;
}
#endif

// nested structure
#if 0
#include <stdio.h>
struct profile {
    char name[50];
    int age;
    char mbti[50];
};

struct student {
    int num;
    double grade;

    struct profile p; // nested structure
};

int main() {
    struct student s1 = {1001, 4.3, {"Alice", 20, "INTJ"}};
    struct student s2;
    s2.num = 1002;
    s2.grade = 3.9;
    s2.p.age = 21;
    snprintf(s2.p.name, sizeof(s2.p.name), "Bob");
    snprintf(s2.p.mbti, sizeof(s2.p.mbti), "ENTP"); 
    return 0;
}
#endif

// structure array
#if 0
#include <stdio.h>
struct student {
    int num;
    char name[50];
    double grade;
};
int main() {
    struct student class[3] = {
        {1001, "Alice", 4.3},
        {1002, "Bob", 3.9},
        {1003, "Charlie", 4.0}
    };

    double total = 0.0;
    for (int i = 0; i < 3; i++) {
        total += class[i].grade;
    }
    printf("average grade: %.2f\n", total / 3);
    return 0;
}
#endif

// structure pointer
#if 0
#include <stdio.h>
struct student {
    int num;
    double grade;
};
int main() {
    struct student s1 = {1001, 4.3};
    struct student *ps = &s1; // pointer to structure

    printf("num: %d, grade: %.2f\n", s1.num, s1.grade); // access structure members using pointer
    printf("num: %d, grade: %.2f\n", ps->num, ps->grade); // access structure members using pointer
    printf("num: %d, grade: %.2f\n", (*ps).num, (*ps).grade); // same as above

    return 0;
}
#endif

// Linked list
// self-referential structure
#if 0
struct node {
    int data;
    struct node *next; // pointer to next node
};
#include <stdio.h>
int main() {
    struct node a, b, c;
    a.data = 10;
    a.next = &b; // a points to b
    b.data = 20;
    b.next = &c; // b points to c
    c.data = 30;
    c.next = NULL; // c is the last node

    struct node *head = &a; // pointer to the first node
    struct node *current = head;
    while (current) {
        printf("%d -> ", current->data); // print data of the first node
        current = current -> next; // move to next node
    }
    return 0;
}
#endif

// union
// requires less memory than struct -> useful for memory optimization
// all members share the same memory location
// size of union is the size of the largest member
// only one member can be used at a time
// used in low-level programming, such as device drivers, protocol packets, etc.
#if 0
#include <stdio.h>
union data {
    int i;
    double d;
};

int main() {
    union data value;
    value.i = 50;
    printf("int: %d\n", value.i); // 50
    value.d = 3.14;
    printf("double: %lf\n", value.d); // 3.14
    printf("int: %d\n", value.i); // garbage value, because memory is shared
    printf("size of union: %d\n", sizeof(union data)); // 8 bytes (max of int and double)
    return 0;
}
#endif

// enum
// used to define a set of named integer constants
// improves code readability
// default value starts from 0 and increments by 1
// can assign specific values to enum members
#if 0
#include <stdio.h>
enum discount { 
    NONE,
    SILVER = 5,
    GOLD = 10,
    PLATINUM = 15
};
int main() {
    enum discount my_discount = GOLD;
    int price = 10000;
    int final_price = price - (price * my_discount / 100);
    switch (my_discount) {
        case NONE:
            printf("No discount\n");
            break;
        case SILVER:
            printf("Silver discount: %d%%\n", SILVER);
            break;
        case GOLD:
            printf("Gold discount: %d%%\n", GOLD);
            break;
        case PLATINUM:
            printf("Platinum discount: %d%%\n", PLATINUM);
            break;
        default:
            printf("Invalid discount\n");
            break;
    }
    printf("Final price: %d\n", final_price);
    return 0;
}
#endif

// typedef
// used to create new data type names (aliases)
// improves code readability
// commonly used for struct, union, enum

#if 0
#include <stdio.h>
typedef struct {
    int num;
    double grade;
} Student; // alias for struct student

// same as above
struct student_ {
    int num;
    double grade;
};
typedef struct student_ Student_;

int main() {
    Student s1 = {1001, 4.3};
    Student_ s2 = {1002, 3.9};
    return 0;
}
#endif

// file I/O
// file pointer: FILE *
// fopen, fclose, fprintf, fscanf, fread, fwrite
// file modes: "r", "w", "a", "rb", "wb", "ab"
// r: read, w: write (overwrite), a: append, b: binary mode
// r+: read and write (does not overwrite existing file)
// w+: write and read (overwrites existing file or creates a new file)
// a+: append and read (creates a new file if it doesn't exist)
// a+ -> write at the end of the file

// NULL pointer: indicates an error in file operations
// always check if file is opened successfully
// always close the file after operations

#if 0
#include <stdio.h>
int main() {
    // open file
    char *path = "./test.txt";
    FILE *fp = fopen(path, "r+"); // read and append mode
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    printf("File opened successfully\n");
    // read, write, append operations
    fprintf(fp, "Hello, World!\n");
    fprintf(fp, "This is a test file.\n");
    fprintf(fp, "File I/O in C.\n");

    int ch;
    // read character by character until EOF
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch); // print to console
    }
    printf("\n");

    // close file
    fclose(fp);
    printf("File closed successfully\n");

    return 0;
}
#endif

// file write
#if 0
#include <stdio.h>
int main() {
    char *path = "./test.txt";
    FILE *fp = fopen(path, "w"); // write mode
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    char *str = "Hello, File I/O in C!\n";
    fputs(str, fp); // write string to file
    fclose(fp);

    return 0;
}
#endif

// header file
// #include "myheader.h"
// #include <myheader.h>
// use double quotes for user-defined headers
// use angle brackets for standard library headers
// avoid multiple inclusions using include guards
// #ifndef MYHEADER_H
// #define MYHEADER_H
// ... header file content ...
// #endif
#if 0
#include <stdio.h>
#include "calc.h"
#include "coordinate.h"
int main() {
    int a = 10, b = 20;
    printf("add: %d\n", add(a, b));
    Coordinate p1 = {10, 20};
    Coordinate p2 = {30, 40};
    printf("slope: %.2f\n", (double)(p2.y - p1.y) / (p2.x - p1.x));
    return 0;
}
#endif

// macro
// #define NAME value
// used for constants, function-like macros, conditional compilation
// avoid using macros for complex expressions due to lack of type checking
// use parentheses to avoid precedence issues
#if 0
#include <stdio.h>
#define PI 3.14159
#define SQUARE(x) ((x) * (x)) // function-like macro
#define MAX(a, b) ((a) > (b) ? (a) : (b)) // function-like macro
#define DEBUG // conditional compilation
#define NAME_CAT(first, last) (first ## last) // token pasting
#define PRINT_CAL(x) printf("Value of " #x " is %d\n", x) // stringizing in macro
#define STR(s) #s // stringizing
int main() {
    double radius = 5.0;
    printf("Area of circle: %.2f\n", PI * SQUARE(radius));
    int a = 10, b = 20;
    printf("Max of %d and %d is %d\n", a, b, MAX(a, b));
#ifdef DEBUG
    printf("Debug mode is ON\n");
#endif

    printf("File: %s\n", __FILE__);
    printf("Function: %s\n", __func__);
    printf("Line: %d\n", __LINE__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    printf("Standard: %ld\n", __STDC_VERSION__); // C standard version
    int n4 = 4;
    printf("%d\n", NAME_CAT(n, 4)); // token pasting
    printf("%s\n", STR(Hello World)); // stringizing
    PRINT_CAL(a); // stringizing in macro
    

    return 0;
}
#endif