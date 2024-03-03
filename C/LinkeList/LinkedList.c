#include <stdlib.h> // MALLOC
#include <stdio.h> // PRINT


typedef struct node{
	int value;
	struct node *next;
}LinkedList;


void PrintLinkedList(LinkedList *llst);
void InitLinkedList(LinkedList **p);
void AddLast(LinkedList **llst, int value);
void AddFirst(LinkedList **p, int value);
void AddIndex(LinkedList **p, int index, int value);
int Contains(LinkedList *llst, int value);
int PeekLast(LinkedList *llst);
int PeekFirst(LinkedList *llst);
int IndexOf(LinkedList *llst, int value);
int LastIndexOf(LinkedList *llst, int value);
int Size(LinkedList *llst);
void RemoveLast(LinkedList **p);
void RemoveFirst(LinkedList **p);
void RemoveIndex(LinkedList **p, int index);
void Clear(LinkedList **p);
void FreeLinkedList(LinkedList **p);

int main(){
	LinkedList *llst = NULL;
	PrintLinkedList(llst);
	InitLinkedList(&llst);
	PrintLinkedList(llst);

	printf("\nAdding to the end of the Linked List...\n");
	for(int i=0;i<3;i++){
		AddLast(&llst, i+1);
		PrintLinkedList(llst);
	}

	printf("\nAdding to the start of the Linked List...\n");
	for(int i=3;i<6;i++){
		AddFirst(&llst, i+1);
		PrintLinkedList(llst);
	}
	
	printf("\nAdding to the Ith (3rd) index of the Linked List...\n");
	AddIndex(&llst, 3, 7);
	PrintLinkedList(llst);
	printf("\nAdding to the Ith (7th) index of the Linked List...\n");
	AddIndex(&llst, 7, 8);
	PrintLinkedList(llst);
	printf("\nAdding to the Ith (5th) index of the Linked List...\n");
	AddIndex(&llst, 5, 8);
	PrintLinkedList(llst);

	printf("\nSearching for elements (Contains):\n");
	printf("Searching for number 8: %d\n", Contains(llst, 8));
	printf("Searching for number 9: %d\n", Contains(llst, 9));	

	printf("\nPeeking First: %d\n", PeekFirst(llst));
	printf("Peeking Last: %d\n", PeekLast(llst));
	
	PrintLinkedList(llst);
	printf("\nIndex of 3: %d\n", IndexOf(llst, 3));
	printf("Index of 7: %d\n", IndexOf(llst, 7));
	printf("Index of 10: %d\n", IndexOf(llst,10));

	printf("\nAdding 2 equal numbers (2 number 11)\n");
	AddFirst(&llst, 11);
	AddLast(&llst, 11);
	PrintLinkedList(llst);
	printf("Index of 11: %d\n", IndexOf(llst, 11));
	printf("Last Index of 11: %d\n", LastIndexOf(llst, 11));

	printf("\nSize of List: %d\n", Size(llst));

	printf("\nRemoving from the Start:\n");
	RemoveFirst(&llst);
	PrintLinkedList(llst);
	printf("Removing from the End:\n");
	RemoveLast(&llst);
	PrintLinkedList(llst);
	printf("Removing index 2:\n");
	RemoveIndex(&llst, 2);
	PrintLinkedList(llst);

	printf("\nClearing the Linked List:\n");
	Clear(&llst);
	PrintLinkedList(llst);

	printf("\nAdding some more elements to the List before we Free it:\n");
	for(int i=0;i<5;i++){
		AddLast(&llst, i+1);
		PrintLinkedList(llst);
	}
	printf("\nFreeing the Linked List:\n");
	FreeLinkedList(&llst);
	PrintLinkedList(llst);

	return 0;
}

void InitLinkedList(LinkedList **p){
	LinkedList *llst = *p;
	if(llst!=NULL){
		printf("Linked List has already been initialized!\n");
		return;
	}
	LinkedList *temp = (LinkedList*) malloc(sizeof(LinkedList));
	if(temp==NULL){
		printf("Malloc Returned NULL in Init Linked List...\n");
		return;
	}
	temp->value=0;
	temp->next=NULL;
	(*p)=temp;
}

void PrintLinkedList(LinkedList *llst){
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return;
	}
	if(llst->value==0){
		printf("Linked List is Empty! Print Linked List...\n");
		return;
	}
	while(llst->next!=NULL){
		printf("%d->",llst->value);
		llst = llst->next;
	}
	printf("%d\n",llst->value);
}

void AddLast(LinkedList **p, int value){
	LinkedList *llst = *p;
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return;
	}

	LinkedList *temp = (LinkedList*) malloc(sizeof(LinkedList));
	if(temp==NULL){
		printf("Malloc Returned NULL in Add Last Linked List...\n");
		return;
	}
	temp->value=value;
	temp->next=NULL;

	while(llst->next!=NULL){
		llst = llst->next;
	}
	llst->next = temp;
	(*p)->value++;
}

void AddFirst(LinkedList **p, int value){
	LinkedList *llst = *p;
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return;
	}

	LinkedList *temp = (LinkedList*) malloc(sizeof(LinkedList));
	if(temp==NULL){
		printf("Malloc Returned NULL in Add First Linked List...\n");
		return;
	}
	temp->value=value;
	temp->next=llst->next;
	llst->next=temp;
	(*p)->value++;
}


void AddIndex(LinkedList **p, int index, int value){
	LinkedList *llst = *p;
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return;
	}
	if(llst->next==0 && index==0){
		AddFirst(p, value);
		return;
	}
	if(index<0 || index>=llst->value){
		printf("Invalid Index! Current Linked List only has %d indexes...\n", (llst->value==0) ? llst->value : llst->value-1);
		return;
	}
	for(int i=0;i<index;i++){
		llst = llst->next;
	}

	LinkedList *temp = (LinkedList*) malloc(sizeof(LinkedList));
	if(temp==NULL){
		printf("Malloc Returned NULL in Add Index Linked List...\n");
		return;
	}
	temp->value=value;
	temp->next=llst->next;
	llst->next=temp;
	(*p)->value++;
}

// RETURN 1 IF FOUND 0 IF NOT FOUND
int Contains(LinkedList *llst, int value){
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return 0;
	}
	if(llst->value==0){
		printf("Linked List is Empty! Print Linked List...\n");
		return 0;
	}
	llst = llst->next;
	while(llst->next!=NULL){
		if(llst->value==value){
			return 1;
		}
		llst = llst->next;
	}
	if(llst->value==value){
		return 1;
	}

	return 0;
}

int PeekFirst(LinkedList *llst){
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return 0;
	}
	if(llst->value==0){
		printf("Linked List is Empty! Print Linked List...\n");
		return 0;
	}
	return llst->next->value;
}

int PeekLast(LinkedList *llst){
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return 0;
	}
	if(llst->value==0){
		printf("Linked List is Empty! Print Linked List...\n");
		return 0;
	}
	while(llst->next!=NULL){
		llst = llst->next;
	}
	return llst->value;
}

// RETURNS -1 IF FAILS
int IndexOf(LinkedList *llst, int value){
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return -1;
	}
	if(llst->value==0){
		printf("Linked List is Empty! Print Linked List...\n");
		return -1;
	}
	
	llst = llst->next;
	int index=0;
	while(llst->next!=NULL){
		if(llst->value==value){
			return index;
		}
		llst = llst->next;
		index++;
	}
	if(llst->value==value){
		return index;
	}

	return -1;
}


// RETURNS -1 IF FAILS
int LastIndexOf(LinkedList *llst, int value){
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return -1;
	}
	if(llst->value==0){
		printf("Linked List is Empty! Print Linked List...\n");
		return -1;
	}
	
	llst = llst->next;
	int index=0;
	int last_index = -1;
	while(llst->next!=NULL){
		if(llst->value==value){
			last_index = index;
		}
		llst = llst->next;
		index++;
	}
	if(llst->value==value){
		last_index = index;
	}

	return last_index;
}

int Size(LinkedList *llst){
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return -1;
	}
	return llst->value;
}

void RemoveFirst(LinkedList **p){
	LinkedList *llst = *p;
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return;
	}
	if(llst->value==0){
		printf("Linked List is Empty! Print Linked List...\n");
		return;
	}
	LinkedList *temp = llst->next;
	llst->next = temp->next;
	free(temp);
	(*p)->value--;
}

void RemoveLast(LinkedList **p){
	LinkedList *llst = *p;
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return;
	}
	if(llst->value==0){
		printf("Linked List is Empty! Print Linked List...\n");
		return;
	}
	while(llst->next->next!=NULL){
		llst = llst->next;
	}
	LinkedList *temp = llst->next;
	llst->next = NULL;
	free(temp);
	(*p)->value--;
}

void RemoveIndex(LinkedList **p, int index){
	LinkedList *llst = *p;
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return;
	}
	if(llst->next==0 && index==0){
		RemoveFirst(p);
		return;
	}
	if(index<0 || index>=llst->value){
		printf("Invalid Index! Current Linked List only has %d indexes...\n", (llst->value==0) ? llst->value : llst->value-1);
		return;
	}
	for(int i=0;i<index;i++){
		llst = llst->next;
	}
	LinkedList *temp = llst->next;
	llst->next = temp->next;
	free(temp);
	(*p)->value--;
}

void Clear(LinkedList **p){
	LinkedList *llst = *p;
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return;
	}
	while(llst->next!=NULL){
		RemoveFirst(p);
	}
}

void FreeLinkedList(LinkedList **p){
	LinkedList *llst = *p;
	if(llst==NULL){
		printf("Linked List has not been initialized!\n");
		return;
	}
	Clear(p);
	free(llst);
	(*p)=NULL;
}
