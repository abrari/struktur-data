#include <stdio.h>
#include <stdlib.h>

struct stack {
    int *data;
    int top;
    int capacity;
};
typedef struct stack stack;

// Inisiasi stack
void stack_init(stack *s, int capacity)
{
    s->data = (int*) malloc(capacity * sizeof(int));
    s->top = -1;
    s->capacity = capacity;
}

// Cek apakah stack kosong
int stack_empty(stack *s)
{
    return (s->top == -1);
}

// Cek apakah stack penuh
int stack_full(stack *s)
{
    return (s->top == s->capacity - 1);
}

// Memasukkan data (PUSH)
void stack_push(stack *s, int newdata)
{
    if (stack_full(s)) {
        printf("Error: stack overflow\n");
    } else {
        s->top++;
        s->data[s->top] = newdata;        
    }
}

// Mengambil data (POP)
int stack_pop(stack *s)
{
    if (stack_empty(s)) {
        printf("Error: stack empty\n");
        return -1;
    } else {
        return s->data[s->top];
        s->top--;
    }
}

// Mendapatkan top of stack
int stack_top(stack *s)
{
    if (stack_empty(s)) {
        printf("Error: stack empty\n");
        return -1;
    } else {
        return s->data[s->top];
    }    
}

// Hapus seluruh isi stack
void stack_clear(stack *s)
{
    s->top = -1;
}

// Cetak isi stack
void stack_print(stack *s)
{
    int i;
    printf("Stack: (%d data)\n", s->top + 1);
    for (i = s->top; i >= 0; i--) {
        printf("%5d\n", s->data[i]);
    }
}

int main()
{
    stack *mystack = malloc(sizeof(stack));
    stack_init(mystack, 5);
    
    stack_push(mystack, 10);
    stack_push(mystack, 20);
    stack_push(mystack, 30);
    stack_push(mystack, 40);
    stack_push(mystack, 50);
    
    stack_print(mystack);
    
    int d = stack_pop(mystack);
    printf("Pop data: %d\n", d);
    
    stack_print(mystack);
    
	return 0;
}

