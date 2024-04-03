#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char *value;
  struct Node *next;
} LLst;

typedef struct NodeG {
  LLst *node_name;
  struct NodeG *next;
} UGraph;

void PrintLLst(LLst *llst);
void PrintGraph(UGraph *graph);
void InitLLst(LLst **p, char *value);
void InitGraphNode(UGraph **p, char *node_name);
void AddNode(UGraph **p, char *node_name);
int CheckIfNodeExists(UGraph *graph, char *node);
void ConnectNodes(UGraph *graph, char *node1, char *node2);
void ConnectNodes(UGraph *graph, char *node1, char *node2);

int main(int argc, char **argsv) {
  // DEFINING Undirected Graph
  UGraph *graph = NULL;
  printf("Printing Graph before adding any nodes:\n");
  PrintGraph(graph);
  // Adding a Value to the Graph
  AddNode(&graph, "A");
  printf("Printing graph after adding first node 'A':\n");
  PrintGraph(graph);
  AddNode(&graph, "B");
  printf("Printing graph after adding node 'B':\n");
  PrintGraph(graph);
  AddNode(&graph, "C");
  printf("Printing graph after adding node 'C':\n");
  PrintGraph(graph);

  printf("Adding a Connection Between nodes 'A' and 'B':\n");
  ConnectNodes(graph, "A", "B");
  PrintGraph(graph);
  printf("Adding a Connection Between nodes 'A' and 'C':\n");
  ConnectNodes(graph, "A", "C");
  PrintGraph(graph);
  printf("Adding a Connection Between nodes 'A' and 'D' ('D' Does not exist in "
         "current graph!):\n");
  ConnectNodes(graph, "A", "D");
  PrintGraph(graph);

  return 0;
}

void PrintLLst(LLst *llst) {
  if (llst == NULL) {
    printf("Current Linked List is empty!");
    return;
  }
  while (llst->next != NULL) {
    printf("%s->", llst->value);
    llst = llst->next;
  }
  printf("%s", llst->value);
}

void PrintGraph(UGraph *graph) {
  if (graph == NULL) {
    printf("Current graph has no nodes!\n");
    return;
  }
  while (graph->next != NULL) {
    PrintLLst(graph->node_name);
    graph = graph->next;
    printf("\n");
  }
  PrintLLst(graph->node_name);
  printf("\n");
}

void InitLLst(LLst **p, char *value) {
  LLst *llst = *p;
  if (llst != NULL) {
    printf("Already initialized LinkedList!\n");
    return;
  }
  LLst *temp = (LLst *)malloc(sizeof(LLst));
  if (temp == NULL) {
    printf("Error in Malloc InitLLst\n");
    return;
  }
  temp->value = value;
  temp->next = NULL;
  *p = temp;
}

void InitGraphNode(UGraph **p, char *node_name) {
  UGraph *graph = *p;
  UGraph *temp = (UGraph *)malloc(sizeof(UGraph));
  if (temp == NULL) {
    printf("Error in Malloc InitGraph...\n");
    return;
  }
  temp->node_name = NULL;
  InitLLst(&temp->node_name, node_name);
  temp->next = NULL;
  *p = temp;
}

void AddNode(UGraph **p, char *node_name) {
  UGraph *graph = *p;
  if (graph == NULL) {
    InitGraphNode(p, node_name);
    return;
  }
  // ADD A NEW NODE TO INITIALIZED GRAPH
  UGraph *aux = graph;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  InitGraphNode(&aux->next, node_name);
}

int CheckIfNodeExists(UGraph *graph, char *node) {
  if (graph == NULL) {
    printf("Current Graph has no nodes! (CheckIfNodeExists)\n");
    return 0;
  }
  while (graph != NULL) {
    if (graph->node_name->value == node) {
      return 1;
    }
    graph = graph->next;
  }
  return 0;
}

void AddToEndLLst(LLst **p, char *value) {
  LLst *llst = *p;
  if (llst == NULL) {
    printf("Uninitialized LinkedList! (AddToEndLLst)\n");
    return;
  }

  LLst *aux = llst;
  while (aux->next != NULL) {
    aux = aux->next;
  }

  LLst *temp = (LLst *)malloc(sizeof(LLst));
  if (temp == NULL) {
    printf("Error in Malloc InitLLst\n");
    return;
  }
  temp->value = value;
  temp->next = NULL;
  aux->next = temp;
}

void AddConnectionLLst(UGraph *graph, char *node1, char *node2) {
  while (graph != NULL) {
    if (graph->node_name->value == node1) {
      AddToEndLLst(&graph->node_name, node2);
      return;
    }
    graph = graph->next;
  }
}

void ConnectNodes(UGraph *graph, char *node1, char *node2) {
  if (graph == NULL) {
    printf("Current Graph has no nodes! (ConnectNodes)\n");
    return;
  }
  if (!CheckIfNodeExists(graph, node1)) {
    printf("There is no node '%s' in the current graph! (ConnectNodes)\n",
           node1);
    return;
  }
  if (!CheckIfNodeExists(graph, node2)) {
    printf("There is no node '%s' in the current graph! (ConnectNodes)\n",
           node2);
    return;
  }
  // EFFECTIVELY CONNECTING THE NODES
  AddConnectionLLst(graph, node1, node2);
  AddConnectionLLst(graph, node2, node1);
}
