// char array (string)
#if 0
#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    char word[4];
    word[0] = 'k';
    word[1] = 'i';
    word[2] = 'w';
    word[3] = 'i';

    // print string
    for (int i = 0; i < 4; i++) {
        printf("%c", word[i]);
    }
    printf("\n");

    // print string using %s
    printf("%s", word);
    printf("\n");

    // null-terminated string
    char word2[20] = {'k', 'i', 'w', 'i', '\0', 'b', 'a', 'n', 'a', 'n', 'a', '\0'};
    printf("%s", word2);
    return 0;
}
#endif


// lowercase to uppercase
#if 0
#include <stdio.h>
int main() {
    // char arr[50] = {0};

    // printf("input>>");
    // scanf("%s", arr);

    // for (int i = 0; i < 50; i++){
    //     // lowercase -> upper case
    //     if (arr[i] >= 'a' && arr[i] <= 'z') {   // 'A' -> 65 , 'a' -> 97
    //         arr[i] -= 32;
    //     }
    // }
    // printf("%s", arr);


    
    // case 1
    char str[50] = {0};
    printf("input>>");
    scanf("%s", str);
    printf("%s\n", str);

    // case2
    char str2[50] = {0};
    char ch;
    int i = 0;
    printf("input>>");
    do {
        scanf("%c", &ch);
        str2[i] = ch;
        i++;
    } while (ch != '\n');
    str2[i] = '\0';
    printf("%s\n", str2);
    





    return 0;
}

#endif
#if 0
#include <stdio.h>

void exam_func(void) {
    int a = 20;
    printf("%d", a);
}

void double_value(int *num) {
    *num *= 2;
}
int main() {
    int a = 10;
    double_value(&a);
    printf("%d", a);
    return 0;
}
#endif

#if 0
#include <stdio.h>
int main() {
    int a = 10, b = 15, total;
    int *pa, *pb, *pt;
    double avg;
    double *pd;

    pa = &a; pb = &b; pt = &total; pd = &avg;
    *pt = *pa + *pb;
    *pd = (double)*pt / 2;

    printf("total = %d\n", *pt);
    printf("average = %.1lf\n", *pd);

    return 0;
}
#endif

//979
#if 0
#include <stdio.h>
int main() {
    double e = 2.718;
    int *pl = &e;
    printf("%lf\n", *(double *)pl);
    return 0;
}
#endif

#if 0
#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a; // value of a
    *a = *b;
    *b = temp;
}
int main() {
    int a = 10, b = 20;
    printf("%d %d\n", a, b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}
#endif

// 1045
#if 0
#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void descending(int* a, int* b, int* c) {
    if (*a < *b) swap(a, b);
    if (*a < *c) swap(a, c);
    if (*b < *c) swap(b, c);
}

int main() {
    int max, mid, min;
    scanf("%d %d %d", &max, &mid, &min);

    descending(&max, &mid, &min);

    printf("max, mid, min : %d %d %d \n", max, mid, min);

    return 0;
}
#endif

// array & pointer
#if 0
#include <stdio.h>
int main() {
    // integer array
    int arr[5] = {10, 20, 30, 40, 50};

    printf("1->%u\n", arr);        // array name, address of first element
    printf("2->%u\n", &arr);
    printf("3->%d\n", *arr);
    printf("4->%u\n", arr + 1);    // address of second element
    printf("5->%u\n", &(arr + 1));    // address of second element



    for (int i = 0; i < 5; i++) {
        printf("%u", (arr + i));      // address of each element
        printf("%d\n", *(arr + i));   // value of each element
    }

    // double array
    double arr2[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    printf("%u\n", arr2);
    printf("%u\n", arr2 + 1);

    for (int i = 0; i < 5; i++)
    {
        printf("%u\n", (arr2 + i));     // address of each element
        printf("%lf\n", *(arr2 + i));   // value of each element
    }
    
    return 0;
}
#endif

// pointer arithmetic
#if 0
#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    // printf("%d\n", *arr);   // 10

    int *p_arr = arr; // pointer to the first element
    // printf("%d\n", *p_arr); // 10
    p_arr++;
    // printf("%d\n", *p_arr); // 20

    p_arr = arr; // reset pointer to the first element
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(p_arr));
        p_arr++;
    }

    // address of arr
    printf("%u\n", arr);        // 48
    printf("%u\n", arr + 1);    // 52
    printf("%u\n", &arr);       // 48
    printf("%u\n", &arr + 1);   // 68 (48+4*5) -> entire array


    // sizeof array, p_arr
    printf("%d\n", sizeof(arr));        // 20
    printf("%d\n", sizeof(p_arr));      // 8
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", size);                // 5

    // p_arr can't get size of array
        return 0;
    }
    #endif


#if 0
#include <stdio.h>
void print_array(int *parr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *parr++);
    }
    printf("\n");
}
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, size);
    return 0;
}
#endif


#if 0
#include <stdio.h>
void input_array(int *p_arr, int size) {
    int *p_temp = p_arr;
    for (int i = 0; i < size; i++) {
        scanf("%d", p_arr++);
    }
    // reset pointer to the first element
    // p_arr -= size; 
    p_arr = p_temp;
    
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(p_arr++));
    }
    printf("\n");
}
int main() {
    int arr[5];
    printf("input >>");
    input_array(arr, 5);
    return 0;
}
#endif

// example
#if 0
#include <stdio.h>

void print_arr(int arr[5]) {
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_arr2(int *arr, int size) {
    for (int i = 0; i < size; i++)
    {
        // printf("arr[i] -> %d \n", arr[i]);
        printf("*arr -> %d \n", *arr++);
    }
    printf("\n");

}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    print_arr(arr);
    print_arr2(arr, 5);
    
    return 0;
}
#endif

// bubble sort (boj 2750)
#if 0
#include <stdio.h>
// bubble sort
void sort(int *pa, int size) {
    int *p_head = pa;

    /*
    // step 1
    if (*(pa + 0) > *(pa + 1)) swap(pa + 0, pa + 1);
    if (*(pa + 1) > *(pa + 2)) swap(pa + 1, pa + 2);
    // ...
    
    for (int i = 0; i < size - 1; i++)
    {
        if (*(pa + i) > *(pa + i+1))
        {
            swap(pa + i, pa + i+1);
        }
        
    }

    // step 2
    for (int i = 0; i < size - 2; i++)
    {
        if (*(pa + i) > *(pa + i+1))
        {
            swap(pa + i, pa + i+1);
        }
        
    }
    // ... 
    */

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i; j++) {
            if (*(pa + j) > *(pa +j+1)) {
                swap(pa + j, pa + j + 1);
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void print_arr(int *pa, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", *pa++);
    }
}
int main() {
    // int arr[5] = {79, 2, 34, 55, 10};
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, N);
    print_arr(arr, N);
    return 0;
}
#endif

// Quick Sort
#if 0
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
int compare(int *pa, int*pb) {
    return *pa - *pb; // ascending order
    // return *pb - *pa; // descending order
}

int main() {
    int arr[5] = {79, 2, 34, 55, 10};
    // qsort(arr_address, size, sizeof(int), compare);
    qsort(arr, 5, sizeof(int), compare);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
#endif

// getchar
#if 0
#include <stdio.h>
int main() {
    // int ch;
    // ch = getchar(); // read a character from standard input
    // putchar(ch); // write a character to standard output


    // char word[5];
    // for (int i = 0; i < 5; i++) {
    //     word[i] = getchar();
    // }
    // word[4] = '\0';
    // printf("%s\n", word);


    char word2[1000];
    int index = 0;
    while (1) {
        char ch = getchar();
        if (ch == '\n') break;
        word2[index++] = ch;
    }
    word2[index] = '\0';
    printf("%s\n", word2);


    return 0;
}
#endif

#if 0
#include <stdio.h>
int main() {
    int num, grade;
    printf("enter stdent num>>");
    scanf("%d", &num);

    // clean the newline character in buffer left by scanf
    getchar();

    printf("enter grade>>");
    grade = getchar(); // read a character from standard input

    printf("student num: %d, grade: %c\n", num, grade);

    return 0;
}
#endif

// string
#if 0
#include <stdio.h>
int main() {
    // ex1
    char word[6] = {'a', 'p', 'p', 'l', 'e', '\0'};
    char *pw = word;

    while (*pw != '\0') {
        printf("%c", *pw++);
    }
    printf("\n");

    // ex2
    char fruit[10] = "banana";
    char *pf = fruit;
    while (*pf != '\0') {
        printf("%c", *pf++);
    }
    printf("\n");

    // ex3 (most concise)
    char *menu = "pizza";
    while (*menu) printf("%c", *menu++);
    printf("\n");
    return 0;
}
#endif


// string copy
#if 0
#include <stdio.h>
#include <string.h> // strcpy()
void my_strcpy(char *dest, char *src) {
    while (*src) *dest++ = *src++;
    *dest = '\0';
}

int main() {
    char fruit1[80] = "apple";
    char fruit2[80] = "banana";

    printf("%s, %s\n", fruit1, fruit2);

    strcpy(fruit1, fruit2);
    printf("%s, %s\n", fruit1, fruit2);

    my_strcpy(fruit1, "dio");
    printf("%s, %s\n", fruit1, fruit2);

    return 0;
}
#endif

// string length
#if 0
#include <stdio.h>
#include <string.h>

int my_strlen(char *pa) {
    int len = 0;
    while (*pa++) len++;
    return len;
}

int main() {
    char word[80] = "semicon";
    printf("len: %zu\n", strlen(word));
    printf("my_len: %d\n", my_strlen(word));
    return 0;
}
#endif


// String Concatenation
#if 0
#include <stdio.h>
#include <string.h>
void my_strcat(char *dest, const char *src) {
    while (*dest) dest++;
    while (*src) *dest++ = *src++;
    *dest = '\0';
}

int main() {
    char str1[100] = "Hello, ";
    char str2[100] = "World!";
    strcat(str1, str2);
    printf("%s\n", str1);
    my_strcat(str1, " How are you?");
    printf("%s\n", str1);
    
    
    return 0;
}
#endif


// String Comparison
#if 1
#include <stdio.h>
#include <string.h>
int my_strcmp(const char *lh, const char *rh) {
    while (*lh && *rh) {
        if (*lh != *rh) {
            return *lh - *rh;
        }
        lh++; rh++;
    }
    return 0;
}
int main() {
    int res;
    char str1[80] = "pear";
    char str2[80] = "peach";
    
    // res > 0 : str1 > str2
    // res < 0 : str1 < str2
    // res = 0 : str1 == str2
    res = strcmp(str1, str2);
    printf("strcmp: %d\n", res);
    res = my_strcmp(str1, str2);
    printf("my_strcmp: %d\n", res);


    return 0;
}
#endif

