// Scope of variables
#if 0
#include <stdio.h>
void assign(void) {
    int a = 30; // local variable
    printf("a in assign(): %d\n", a);
}
void assign_10to500(void) {
    static int b = 10; // static variable
    b = 500;
    printf("b in assign_10to500(): %d\n", b);
}
int plus1(int num) {
    num++;
    printf("num in plus1(): %d\n", num);
    return num;
}
int main() {
    // local variable
    auto int a = 10; // auto is optional
    printf("a in main(): %d\n", a); // 10
    assign();                       // 30
    printf("a in main(): %d\n", a); // 10
    {
        int a = 20; // local variable
        printf("a in block: %d\n", a); // 20
    }
    printf("a in main(): %d\n", a); // 10

    // global variable
    static int b = 10; // static variable
    printf("b in main(): %d\n", b); // 10
    b++;
    printf("b in main(): %d\n", b); // 11
    assign_10to500();               // 500
    printf("b in main(): %d\n", b); // 11
    plus1(b);                       // 12
    printf("b in main(): %d\n", b); // 11

    return 0;
}
#endif


// Static variable in function
#if 0
#include <stdio.h>
void static_click(void) {
    static int count = 0; // static variable
    count++;
    printf("count: %d\n", count);
}
int main() {
    static int count; // local variable
    for (int i = 0; i < 5; i++) {
        static_click();
    }
    printf("count in main(): %d\n", count); // error
    return 0;
}
#endif


// Register variable
#if 0
#include <stdio.h>
#include <time.h>
int main() {
    register long long sum = 0;
    long long num = 2000000000;
    long start = clock();
    for (long long i = 0; i < num; i++) {
        sum += i;
    }
    long end = clock();
    printf("sum: %lld, time: %lf ms\n", sum, (double)(end - start) / CLOCKS_PER_SEC);
    
    return 0;
}
#endif


// Call by Value vs Call by Reference
#if 0
#include <stdio.h>
int add_10(int num) {
    return num + 10;
}
void double_value(int *num) {
    *num *= 2;
}
int main() {
    int a = 10;
    printf("a before add_10(): %d\n", a); // 10
    a = add_10(a);
    printf("result of add_10(): %d\n", a); // 20

    double_value(&a);
    printf("a after double_value(): %d\n", a); // 20
    return 0;
}
#endif


// address return
#if 0
#include <stdio.h>
int sum(int a, int b) {
    return a + b;
}
int* sum2(int a, int b) {
    // int *result = (int *)malloc(sizeof(int));
    int result = a + b; // local variable
    return &result; // local variable address return (dangerous, use static or malloc)
}
int main() {
    int result = sum(10, 20);
    printf("result: %d\n", result); // 30
    int *p_result;
    p_result = sum2(10, 20);
    printf("result: %d\n", *p_result); // 30
    printf("result: %d\n", *p_result); // garbage value if not static or malloc
    return 0;
}
#endif


// Function pointer
#if 0
#include <stdio.h>
int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int div(int a, int b) {
    return a / b;
}
int main() {
    int (*p_func)(int, int); // function pointer declaration
    p_func = add; // assign function to pointer
    printf("add: %d\n", p_func(10, 5)); // 15
    p_func = sub;
    printf("sub: %d\n", p_func(10, 5)); // 5
    p_func = mul;
    printf("mul: %d\n", p_func(10, 5)); // 50
    p_func = div;
    printf("div: %d\n", p_func(10, 5)); // 2

    return 0;
}
#endif


// multi dimensional array
#if 0
#include <stdio.h>
int main() {

    int score1[4] = {1, 2, 3, 4};
    int score2[4] = {5, 6, 7, 8};
    int score3[4] = {9, 10, 11, 12};
    int* arr[3] = {score1, score2, score3};
    printf("%d\n", arr[0][0]); // 1
    printf("%d\n", *(arr[0] + 0)); // 1
    printf("%d\n", arr[1][2]); // 7
    printf("%d\n", arr[4]); // 11??
    printf("%d\n", arr[2][3]); // 12
    // int (*p_arr)[4] = arr; // pointer to array of 4 integers
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", *(*(arr + i) + j)); // arr[i][j]
        }
        printf("\n");
    }
    return 0;
}
#endif


// multi dimensional array 2
#if 0
#include <stdio.h>
int main() {
    int arr[3][4] = {
        {72, 80, 95, 60},
        {68, 98, 83, 90},
        {76, 72, 84, 90}
    };
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == 2) sum += arr[i][j];
        }
    }
    double avg = (double)sum / 3;
    printf("sum: %d, avg: %.2f\n", sum, avg);
    return 0;
}
#endif


// array initialization
#if 0
#include <stdio.h>
void print_array(int rows, int cols, int (*parr)[cols]) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", parr[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6},
        {9, 11, 12}
    };
    print_array(arr);
    
    int arr2[3][4];
    print_array(arr2, 3);

    int arr3[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    print_array(arr3, 3);
    return 0;
}
#endif


// string array
#if 0
#include <stdio.h>
void print_str_array(char arr[5][20]) {
    for (int i = 0; i < 5; i++) {
        printf("%s\n", arr[i]);
    }
}
int main() {
    // review
    char str1[] = "apple";
    char str2[] = {'a', 'p', 'p', 'l', 'e', '\0'};
    char* str3 = "apple";
    
    
    char word[5][10] = {
        "apple",
        "banana",
        "kiwi",
        "grape",
        "peach"
    };

    for (int i = 0; i < 5; i++) {
        printf("%s\n", word[i]);
    }
    for (int i = 0; i < 5; i++) {
        while (*word[i]) printf("%c", (*word[i])++);
        printf("\n");
    }
    
    return 0;
}
#endif


// example
#if 0
#include <stdio.h>
int main() {
    char mark[5][5] =  {'0', };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mark[i][j] = ' ';
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // if (i == j) mark[i][j] = 'X';
            // if (i == j || i + j == 4) mark[i][j] = 'X';
            if (!((i + j) % 2)) mark[i][j] = 'X';
            printf("%2c", mark[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#endif


// pointer array
#if 0
#include <stdio.h>
int main() {
    int score1[4] = {1, 2, 3, 4};
    int score2[4] = {5, 6, 7, 8};
    int score3[4] = {9, 10, 11, 12};
    int* p_arr1 = score1;
    int* p_arr2 = score2;
    int* p_arr3 = score3;
    int* p_arrs[3] = {p_arr1, p_arr2, p_arr3};
    int* p_arrs2[3] = {score1, score2, score3};   // same as above

    int val7 = *(p_arrs[1] + 2); // 7
    int val7_2 = *(*(p_arrs + 1) + 2); // 7


    char* animals[5] = {
        "cat",
        "dog",
        "elephant",
        "tiger",
        "lion"
    };
    printf("%s\n", animals[2]); // elephant
    printf("%c\n", *(animals[1] + 1)); // d'o'g
    printf("%c\n", *(*(animals + 3) + 2)); // ti'g'`er

    return 0;
}
#endif



#if 0
#include <stdio.h>
void print_arr(int arr[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void print_arr2(int arr[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", arr[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}
void print_arr3(int arr[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 4; j >= 0; j--) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void print_arr4(int arr[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 4; j >= 0; j--) {
            printf("%2d ", arr[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}
void print_arr5(int arr[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%2d ", !(i%2) ? arr[i][j] : arr[i][4-j]);
        printf("\n");
    }
    printf("\n");
}
void input_arr(int arr[5][5]) {
    int val = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
            arr[i][j] = val++;
        }
    }
    printf("\n");
}
int main() {
    int arr[5][5];
    input_arr(arr);
    print_arr(arr);
    print_arr2(arr);
    print_arr3(arr);
    print_arr4(arr);
    print_arr5(arr);
    return 0;
}
#endif


// double pointer
#if 0
#include <stdio.h>
int main() {
    int a = 10;
    int *p = &a;
    int **pp = &p;  // pointer to pointer


    // p = &a
    // pp = &p = &&a (not valid)
    // *pp = *(&p) = p = &a
    // **pp = *( *(&p) ) = *p = a

    printf("a: %d\n", a);       // 10
    printf("*p: %d\n", p);      // address of a
    printf("**pp: %d\n", pp);   // address of p

    printf("&a: %d\n", &a);     // address of a
    printf("*pp: %d\n", *pp);   // address of a
    printf("&p: %d\n", &p);     // address of p

    printf("*p: %d\n", *p);     // 10
    printf("**pp: %d\n", **pp); // 10
    printf("sizeof(a): %d\n", sizeof(a));       // 4
    printf("sizeof(p): %d\n", sizeof(p));       // 8
    printf("sizeof(pp): %d\n", sizeof(pp));     // 8
    
    return 0;
}
#endif


// double pointer 2
#if 0
#include <stdio.h>
#include <string.h>
void swap_str(char **ppa, char **ppb) {
    printf("*pa: %s, *pb: %s\n", *ppa, *ppb);
    // *ppa, *ppb -> string
    char *temp = *ppa;
    *ppa = *ppb;
    *ppb = temp;
    printf("*pa: %s, *pb: %s\n", *ppa, *ppb);
}
int main() {
    char *pw1 = "success";
    char *pw2 = "failure";

    printf("pw1: %s\n", pw1); // success
    printf("pw2: %s\n", pw2); // failure
    printf("\n");

    swap_str(&pw1, &pw2);
    // char temp[80] = {0,};
    // strcpy(temp, pw1);
    // strcpy(pw1, pw2); // error, string literal is read-only
    // strcpy(pw2, temp);
    // printf("pw1: %s\n", pw1); // failure
    // printf("pw2: %s\n", pw2); // success
    // printf("\n");
    
    char **ppw = &pw1; // pointer to pointer
    // printf("ppw: %s\n", *ppw); // success
    ppw = &pw2;
    // printf("ppw: %s\n", *ppw); // failure
    return 0;
}
#endif


// string array
#if 0
#include <stdio.h>
void print_str_array(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]); // pointer 로 받은 변수 -> arr[i] 로 접근 가능
        // printf("%s\n", *(arr + i));
        // printf("%s\n", (*arr)[i]);
    }
}
int main() {
    char *animals[] = {
        "cat",
        "dog",
        "elephant",
        "tiger",
        "lion"
    };
    int size = sizeof(animals) / sizeof(animals[0]);
    print_str_array(animals, size);
    return 0;
}
#endif


// 2차원 배열 출력
#if 0
#include <stdio.h>
// original
void print_arr(int arr[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// 2nd array parameter
// 2차원 배열을 가리치는 2중 포인터를 매개변수로 사용
// -> 차원을 하나 낮춰서 대입해서 사용

// int **ppa <<
// int (*pa)[5]
// int arr[5][5]
void print_arr2(int** arr) {
    int (*pa)[5];
    pa = arr;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", pa[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_arr3(int (*arr)[5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
    int arr[5][5] = {0,};
    int count = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = count++;
        }
    }
    print_arr(arr);
    print_arr2(arr);
    print_arr3(arr);


    return 0;
}
#endif


// function pointer
#if 0
#include <stdio.h>
int sum(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int div(int a, int b) {
    return a / b;
}
int main() {
    int result = sum(10, 20);
    printf("result: %d\n", result); // 30

    int (*fp) (int, int); // function pointer
    // int result2 = fp(10, 20);
    // printf("result2: %d\n", result2); // 30


    printf("input >> ");
    int a, b;
    char op;
    scanf("%d %c %d", &a, &op, &b);
    if (op == '+') fp = sum;
    else if (op == '-') fp = sub;
    else if (op == '*') fp = mul;
    else if (op == '/') fp = div;
    else {
        printf("Invalid operator\n");
        fp = sum;
        return -1;
    }
    int result2 = fp(a, b);
    printf("result: %d\n", result2); // 30
    
    return 0;
}
#endif


// void pointer
#if 0
#include <stdio.h>
int main() {
    int a = 10;
    int *pa = &a;
    double b = 3.14;
    double *pb = &b;


    void *vp = pa; // void pointer
    printf("a: %d\n", *(int *)vp); // type casting
    vp = pb;
    printf("b: %lf\n", *(double *)vp); // type casting

    
    return 0;
}
#endif