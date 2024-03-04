#include <stdio.h> // PRINT
#include <stdlib.h> // MALLOC

typedef struct node{
    int value;
    struct node *next;
}Stack;

void PrintStack(Stack *stack);
void InitStack(Stack **p);
void Push(Stack **p, int value);
int Pop(Stack **p);
int Peek(Stack *stack);
void Clear(Stack **p);
void FreeStack(Stack **p);

int main(){
    Stack *stack = NULL;
    PrintStack(stack);
    InitStack(&stack);
    PrintStack(stack);

    printf("Iserting elements (push)\n\n");
    Push(&stack, 0);
    int peeked = Peek(stack);
    printf("Peeked element: %d\n", peeked);
    PrintStack(stack);
    Push(&stack, 1);
    peeked = Peek(stack);
    printf("Peeked element: %d\n", peeked);
    PrintStack(stack);
    Push(&stack, 2);
    peeked = Peek(stack);
    printf("Peeked element: %d\n", peeked);
    PrintStack(stack);

    printf("Poping elements...\n\n");
    int last_ement = Pop(&stack);
    printf("popped element: %d\n", last_ement);
    PrintStack(stack);
    last_ement = Pop(&stack);
    printf("popped element: %d\n", last_ement);
    PrintStack(stack);
    last_ement = Pop(&stack);
    printf("popped element: %d\n", last_ement);
    PrintStack(stack);
    last_ement = Pop(&stack);
    printf("popped element: %d\n", last_ement);
    PrintStack(stack);

    printf("Iserting elements (push)\n\n");
    Push(&stack, 5);
    peeked = Peek(stack);
    printf("Peeked element: %d\n", peeked);
    PrintStack(stack);
    Push(&stack, 55);
    peeked = Peek(stack);
    printf("Peeked element: %d\n", peeked);
    PrintStack(stack);
    Push(&stack, 89);
    peeked = Peek(stack);
    printf("Peeked element: %d\n", peeked);
    PrintStack(stack);

    printf("Clearing the stack...\n\n");
    Clear(&stack);
    PrintStack(stack);

    printf("Freeing Stack...\n\n");
    FreeStack(&stack);
    PrintStack(stack);

    return 0;
}

void InitStack(Stack **p){
    Stack *stack = *p;
    if(stack!=NULL){
        printf("This stack has already been initialized!\n");
        return;
    }

    Stack *temp = (Stack*) malloc(sizeof(Stack));
    if (temp==NULL){
        printf("Malloc Returned NULL in Initializing Stack...\n");
        return;
    }
    temp->value=0;
    temp->next=NULL;
    (*p) = temp;
}

void PrintStack(Stack *stack){
    if(stack==NULL){
        printf("This stack has not been initialized!\n");
        return;
    }
    if(stack->value==0){
        printf("This stack is Empty!\n");
        return;
    }
    while(stack->next!=NULL){
        printf("%d->", stack->value);
        stack = stack->next;
    }
    printf("%d\n", stack->value);
}

void Push(Stack **p, int value){
    Stack *stack = *p;
    if(stack==NULL){
        printf("This stack has not been initialized!\n");
        return;
    }

    Stack *temp = (Stack*) malloc(sizeof(Stack));
    if (temp==NULL){
        printf("Malloc Returned NULL in Initializing Stack...\n");
        return;
    }
    temp->value=value;
    temp->next=NULL;

    while(stack->next!=NULL){
        stack = stack->next;
    }
    stack->next = temp;
    (*p)->value++;
}

// RETURN -1 UF STACK IS NULL OR EMPTY!
int Pop(Stack **p){
    Stack *stack = *p;
    if(stack==NULL){
        printf("This stack has not been initialized!\n");
        return -1;
    }
    if(stack->value==0){
        printf("The stack is empty!\n");
        return -1;
    }

    while(stack->next->next!=NULL){
        stack = stack->next;
    }
    Stack *temp = stack->next;
    int top_element = temp->value;
    stack->next=NULL;
    free(temp);
    (*p)->value--;
    return top_element;
}


int Peek(Stack *stack){
    if(stack==NULL){
        printf("This stack has not been initialized!\n");
        return 0;
    }
    if(stack->value==0){
        printf("The stack is empty!\n");
    }

    while(stack->next!=NULL){
        stack = stack->next;
    }
    return stack->value;
}


void Clear(Stack **p){
    Stack *stack = *p;
    if(stack==NULL){
        printf("This stack has not been initialized!\n");
        return;
    }
    if(stack->value==0){
        printf("The stack is empty!\n");
        return;
    }

    while(stack->next!=NULL){
        Stack *temp = stack->next;
        stack->next = temp->next;
        free(temp);
        stack->value--;
    }
}


void FreeStack(Stack **p){
    Stack *stack = *p;
    if(stack==NULL){
        printf("This stack has not been initialized!\n");
        return;
    }

    while(stack->next!=NULL){
        Stack *temp = stack->next;
        stack->next = temp->next;
        free(temp);
        stack->value--;
    }
    (*p) = NULL;
    free(stack);
}