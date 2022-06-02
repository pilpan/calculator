// Copyright 2022 <lesaleat><stumptow><valeryje>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int length;
    int capacity;
} Stack;

Stack stack_create() {
    Stack st;
    st.capacity = 0;
    st.length = 0;
    st.data = NULL;
    return st;
}

int input(char *arr,int lenght) {
    char tmp;
    while (tmp != '\n') {
        scanf("%c", &tmp);
        arr[lenght] = tmp;
        lenght++;
        arr = realloc(arr,sizeof(char));
    }
    return lenght;
}

void stack_print (Stack *st) {
    for (int i = 0; i < st->length; i++) {
        printf("%c", st->data[i]);
    }
    printf("\n");
}

void stack_push(Stack *st, char data) {
    if (st->data == NULL || st->length == st->capacity) {
        st->capacity = (st->capacity + 1) + 10;
        st->data = (char*)realloc(st->data,sizeof(char)*st->capacity);
    }
    st->data[st->length] = data;
    st->length += 1;
}

char stack_pop(Stack *st) {
    st->length -= 1;
    return  st->data[st->length];
}

void stack_free(Stack *st) {
    if (st->data != NULL)
    free(st->data);
    st->capacity = 0;
    st->length = 0;
}

void rewrite(char *arr, int length, char *polish, int *prior, Stack opera) {
    char tmp;
    int count = 0;

    for (int i = 0; i < length-1; i++) {
        if (arr[i] >= '0' && arr[i] <= '9') {
            polish = realloc(polish, sizeof(char));
            polish[i-count] = arr[i];
            count++;
            if (i > 0 ) {
                stack_pop(&opera);
            }
        } else {
            tmp = arr[i];

            if (tmp == '+' || tmp == '-') {
                prior = realloc(prior, sizeof(int));
                prior[i-count] = 1;
            }

            if (tmp == '*' || tmp == '/') {
                prior = realloc(prior, sizeof(int));
                prior[i-count] = 2;
            }

            if (tmp == '^') {
                prior = realloc(prior, sizeof(int));
                prior[i-count] = 3;
            }
        }

        for (int j = 0; j < i-count; j++) {
            if (prior[i-count] < prior[i-count-1]) {
                polish = realloc(polish, sizeof(char) + 1);
                count--;
                polish[i-count] = stack_pop(&opera);
                prior[i-count-1] = prior[i-count];
                prior = realloc(prior, sizeof(int) - 1);
            }
        }
        printf("POLISH %s, i = %d\n", polish, i);
        stack_print(&opera);
        printf("\n");
        printf("PRIORY\n");
        for (int i=0; i < length; i++) {
            printf("%d ", prior[i]);
        }
        printf("\nAFTER PUSH\n");
        stack_push(&opera, tmp);
        stack_print(&opera);
        printf("\n\n");
    }

    for (int i = 0; i < opera.length; i++) {
        polish = realloc(polish, sizeof(char)+1);
        printf("\n Длина полиш = %lu\n", strlen(polish));
        polish[strlen(polish)] = stack_pop(&opera);
    }

    printf("POLISH %s\n", polish);
        // stack_print(&opera);
        // printf("\n");
        // printf("PRIORY\n");
        // for (int i=0; i < length; i++) {
        //     printf("%d ", prior[i]);
        // }
        // printf("\nAFTER PUSH\n");
        // stack_push(&opera, tmp);
        // stack_print(&opera);
        // printf("\n\n");
    // stack_pop(&opera);
    // stack_print(&opera);
    for (int i=0; i < strlen(polish) - 1; i++) {
        printf("%c ", polish[i]);
    }
}

int calc(char* polish) {
     int stack[1000];
     int sp =0;
     for (int i = 0; i < strlen(polish); i++) {
         int x;
         switch (polish[i]) {
             case  ' ':
             case '\n':
                 break;
             case '=':
                 printf("Result = %d\n", stack[sp - 1]);  sp--;
                 break;
             case '+':
                stack[sp-2] = stack[sp-2] + stack[sp-1];  sp--;
                break;
             case '-':
                stack[sp-2] = stack[sp-2] - stack[sp-1];  sp--;
                break;
             case '*':
                stack[sp-2] = stack[sp-1] * stack[sp-2];  sp--;
                break;
             case '/':
               stack[sp-2] = stack[sp-2] / stack[sp-1];   sp--;
                break;
         }
     }

     return stack[sp-1];
 }

int makeField() {
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            double i = x*M_PI/20;
            double j = 0.5;
            i = i+1;
            j = round(j*12 + 12);
            if (y == j) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}

int main() {
    int length = 0;
    char *arr;
    char *polish;
    int *prior;

    Stack opera = stack_create();

    arr = malloc(length * sizeof(char));
    polish = malloc(length * sizeof(char));
    prior = malloc(length * sizeof(int));

    length = input(arr, length);

    rewrite(arr, length, polish, prior, opera);

    printf("\n")
    float result = calc(polish);
    printf("result = %f\n", result);
    printf("\n")

    stack_free(&opera);
    makeField();
    free(arr);
    free(polish);
    free(prior);
}
