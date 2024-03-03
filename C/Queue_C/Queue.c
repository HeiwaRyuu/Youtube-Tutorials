#include <stdio.h>//PRINTING
#include <stdlib.h>//MALLOC

typedef struct node{
	int value;
	struct node *next;
}Queue;


void InitQueue(Queue **p);
void PrintQueue(Queue *queue);
void Add(Queue **p, int value);
void Remove(Queue **p);
void Clear(Queue **p);
int Peek(Queue *queue);
void FreeQueue(Queue **p);

int main(){
	Queue *queue = NULL;
	PrintQueue(queue);
	InitQueue(&queue);
	PrintQueue(queue);
	printf("\nAdding elements to the Queue...\n");
	Add(&queue, 8);
	printf("Peeked Element: %d\n", Peek(queue));
	PrintQueue(queue);
	Add(&queue, 11);
	printf("Peeked Element: %d\n", Peek(queue));
	PrintQueue(queue);
	Add(&queue, 36);
	printf("Peeked Element: %d\n", Peek(queue));
	PrintQueue(queue);

	printf("\nRemoving elements from the Queue...\n");
	Remove(&queue);
	printf("Peeked Element: %d\n", Peek(queue));
	PrintQueue(queue);
	Remove(&queue);
	printf("Peeked Element: %d\n", Peek(queue));
	PrintQueue(queue);
	Remove(&queue);
	printf("Peeked Element: %d\n", Peek(queue));
	PrintQueue(queue);
	Remove(&queue);
	printf("Peeked Element: %d\n", Peek(queue));
	PrintQueue(queue);

	printf("\nAdding elements to the Queue...\n");
	Add(&queue, 12);
	PrintQueue(queue);
	Add(&queue, 89);
	PrintQueue(queue);
	Add(&queue, 27);
	PrintQueue(queue);
	printf("\nClearing the Queue...\n");
	Clear(&queue);
	PrintQueue(queue);

	printf("\nAdding elements to the Queue...\n");
	Add(&queue, 67);
	PrintQueue(queue);
	Add(&queue, 23);
	PrintQueue(queue);
	Add(&queue, 71);
	PrintQueue(queue);
	Add(&queue, 2);
	PrintQueue(queue);
	Add(&queue, 107);
	PrintQueue(queue);

	printf("\nFreeing Queue...\n");
	FreeQueue(&queue);
	PrintQueue(queue);

	return 0;
}

void InitQueue(Queue **p){
	Queue *queue = *p;
	if(queue!=NULL){
		printf("This Queue has already been initialized!\n");
		return;
	}
	Queue *temp = (Queue*) malloc(sizeof(Queue));
	if(temp==NULL){
		printf("Malloc Has Returned NULL InitQueue...\n");
		return;
	}
	temp->value=0;
	temp->next=NULL;
	(*p)=temp;
}

void PrintQueue(Queue *queue){
	if(queue==NULL){
		printf("This Queue has not been initialized!\n");
		return;
	}
	if(queue->value==0){
		printf("This Queue is empty! PrintQueue\n");
		return;
	}
	while(queue->next!=NULL){
		printf("%d->",queue->value);
		queue = queue->next;
	}
	printf("%d\n",queue->value);
}

void Add(Queue **p, int value){
	Queue *queue = *p;
	if(queue==NULL){
		printf("This Queue has not been initialized!\n");
		return;
	}

	Queue *temp = (Queue*) malloc(sizeof(Queue));
	if(temp==NULL){
		printf("Malloc Has Returned NULL Add Queue...\n");
		return;
	}
	temp->value=value;
	temp->next=NULL;

	while(queue->next!=NULL){
		queue = queue->next;
	}
	queue->next = temp;
	(*p)->value++;
}

void Remove(Queue **p){
	Queue *queue = *p;
	if(queue==NULL){
		printf("This Queue has not been initialized!\n");
		return;
	}

	if(queue->value==0){
		printf("This Queue is empty! Remove from Queue\n");
		return;
	}
	Queue *temp = queue->next;
	queue->next = temp->next;
	free(temp);
	(*p)->value--;
}

// RETURNS -1 IF IT FAILS
int Peek(Queue *queue){
	if(queue==NULL){
		printf("This Queue has not been initialized!\n");
		return -1;
	}

	if(queue->value==0){
		printf("This Queue is empty! Peek from Queue\n");
		return -1;
	}
	return queue->next->value;
}

void Clear(Queue **p){
	Queue *queue = *p;
	while(queue->next!=NULL){
		Remove(p);
	}
}

void FreeQueue(Queue **p){
	Queue *queue = *p;
	Clear(p);
	free(queue);
	(*p)=NULL;
}
