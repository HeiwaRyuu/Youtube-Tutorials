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

void PrintGraph(UGraph *graph);
void AddNode(UGraph **p, char *node);
void ConnectNodes(UGraph *graph, char *node1, char *node2);
void RemoveConnection(UGraph **p, char *node1, char *node2);
void FreeGraph(UGraph **p);

int main(int argc, char **argsv) {
  // DEFINING Undirected Graph
  UGraph *graph = NULL;
  printf("Printing the Graph before adding any nodes:\n");
  PrintGraph(graph);
  // Adding Values to the Graph
  printf("Printing graph after adding the first node 'A':\n");
  AddNode(&graph, "A");
  PrintGraph(graph);
  printf("Printing graph after adding the first node 'B':\n");
  AddNode(&graph, "B");
  PrintGraph(graph);
  printf("Printing graph after adding the first node 'C':\n");
  AddNode(&graph, "C");
  PrintGraph(graph);
  printf("Printing graph after trying to add already existing node 'C':\n");
  AddNode(&graph, "C");
  PrintGraph(graph);
  printf("Printing graph after adding the first nodes 'D', 'E', 'F', 'G' and "
         "'H':\n");
  AddNode(&graph, "D");
  AddNode(&graph, "E");
  AddNode(&graph, "F");
  AddNode(&graph, "G");
  AddNode(&graph, "H");
  PrintGraph(graph);

  printf("Adding a connection between nodes 'A' and 'B':\n");
  ConnectNodes(graph, "A", "B");
  PrintGraph(graph);
  printf("Adding a connection between nodes 'A' and 'C':\n");
  ConnectNodes(graph, "A", "C");
  PrintGraph(graph);
  printf("Adding a connection between nodes 'A' and 'K' ('K' Does not exist in "
         "current graph):\n");
  ConnectNodes(graph, "A", "K");
  PrintGraph(graph);

  printf("Adding a connection between nodes 'A' and 'D', 'E', 'F' and"
         "'G':\n");
  ConnectNodes(graph, "A", "D");
  ConnectNodes(graph, "A", "E");
  ConnectNodes(graph, "A", "F");
  ConnectNodes(graph, "A", "G");
  PrintGraph(graph);

  printf("Trying to add a connection that already exists ('A' to 'E'):\n");
  ConnectNodes(graph, "A", "E");
  PrintGraph(graph);

  printf("Adding a connection between nodes 'B' and 'C', 'F', 'G' and"
         "'H':\n");
  ConnectNodes(graph, "B", "C");
  ConnectNodes(graph, "B", "F");
  ConnectNodes(graph, "B", "G");
  ConnectNodes(graph, "B", "H");
  PrintGraph(graph);

  printf("Adding a connection between nodes 'F' and 'G', 'H':\n");
  ConnectNodes(graph, "F", "G");
  ConnectNodes(graph, "F", "H");
  PrintGraph(graph);

  printf("Removing the connection between nodes 'A' and 'C':\n");
  RemoveConnection(&graph, "A", "C");
  PrintGraph(graph);

  printf("Trying to Double remove the connection between nodes 'A' and 'C':\n");
  RemoveConnection(&graph, "A", "C");
  PrintGraph(graph);

  printf("Removing the connection between nodes 'A' and 'K' ('K' Does not "
         "exist in the curren graph!)\n");
  RemoveConnection(&graph, "A", "K");
  PrintGraph(graph);

  printf("Freeing Up the whole graph:\n");
  FreeGraph(&graph);
  PrintGraph(graph);
  printf("Printing Graph after it has been emptied:\n%p\n", graph);

  return 0;
}

void PrintLLst(LLst *llst) {
  if (llst == NULL) {
    printf("Current Linked List is empty!(PrintLLst)\n");
    return;
  }
  while (llst->next != NULL) {
    printf("%s->", llst->value);
    llst = llst->next;
  }
  printf("%s\n", llst->value);
}

void PrintGraph(UGraph *graph) {
  if (graph == NULL) {
    printf("Current graph has no nodes!(PrintGraph)\n");
    return;
  }
  while (graph != NULL) {
    PrintLLst(graph->node_name);
    graph = graph->next;
  }
}

void InitLLst(LLst **p, char *value) {
  LLst *llst = *p;
  if (llst != NULL) {
    printf("Already initialized Linked List!(InitLLst)\n");
    return;
  }
  LLst *temp = (LLst *)malloc(sizeof(LLst));
  if (temp == NULL) {
    printf("Error in Malloc (InitLLst)\n");
    return;
  }
  temp->value = value;
  temp->next = NULL;
  (*p) = temp;
}

void InitGraphNode(UGraph **p, char *node) {
  UGraph *graph = *p;
  UGraph *temp = (UGraph *)malloc(sizeof(UGraph));
  if (temp == NULL) {
    printf("Error in Malloc (InitGraph)...\n");
    return;
  }
  temp->node_name = NULL;
  InitLLst(&temp->node_name, node);
  temp->next = NULL;
  (*p) = temp;
}

void AddNode(UGraph **p, char *node) {
  UGraph *graph = *p;
  if (graph == NULL) {
    InitGraphNode(p, node);
    return;
  }
  // ADD A NEW NODE TO AN INITIALIZED GRAPHwhile(aux->next != NULL){
  while (graph->next != NULL) {
    if (graph->node_name->value == node) {
      printf("Node %s already present in the current graph!(AddNode)\n", node);
      return;
    }
    graph = graph->next;
  }
  // CHECKING IF NODE ALREADY EXISTS IN THE LAST POSITION OF THE GRAPH (IF SO,
  // DO NOT ADD NODE!)
  if (graph->node_name->value == node) {
    printf("Node %s already present in the current graph!(AddNode)\n", node);
    return;
  }
  InitGraphNode(&graph->next, node);
}

void AddToEndLLst(LLst **p, char *value) {
  LLst *llst = *p;
  if (llst == NULL) {
    printf("Uninitialized Linked List!(AddToEndLLst)\n");
    return;
  }
  while (llst->next != NULL) {
    if (llst->value == value) {
      // CHECKING IF CONNECTION ALREADY EXISTS
      printf("Connection from %s to %s already exists!(AddToEndLLst)\n",
             (*p)->value, value);
      return;
    }
    llst = llst->next;
  }
  // CHECKING IF THE LAST ELEMENT IS THE EXISTING CONNECTION
  if (llst->value == value) {
    printf("Connection from %s to %s already exists!(AddToEndLLst)\n",
           (*p)->value, value);
    return;
  }
  LLst *temp = (LLst *)malloc(sizeof(LLst));
  if (temp == NULL) {
    printf("Error in Malloc (AddToEndLLst)\n");
    return;
  }
  temp->value = value;
  temp->next = NULL;
  llst->next = temp;
}

void AddConnectionLLst(UGraph *graph, char *node1, char *node2) {
  int flag_node1 = 0;
  int flag_node2 = 0;
  UGraph *n1 = NULL;
  while (graph != NULL) {
    if (graph->node_name->value == node1) {
      flag_node1 = 1;
      n1 = graph;
    }
    if (graph->node_name->value == node2) {
      flag_node2 = 1;
    }
    if (flag_node1 == 1 && flag_node2 == 1) {
      AddToEndLLst(&n1->node_name, node2);
      return;
    }
    graph = graph->next;
  }
  if (flag_node1 == 0) {
    printf(
        "There is no such node %s in the current graph!(AddConnectionLLst)\n",
        node1);
  }
  if (flag_node2 == 0) {
    printf(
        "There is no such node %s in the current graph!(AddConnectionLLst)\n",
        node2);
  }
}

void ConnectNodes(UGraph *graph, char *node1, char *node2) {
  if (graph == NULL) {
    printf("Current Graph has no nodes!(ConnectNodes)\n");
    return;
  }
  AddConnectionLLst(graph, node1, node2);
  AddConnectionLLst(graph, node2, node1);
}

void RemoveFromLLst(LLst **p, char *value) {
  LLst *llst = *p;
  if (llst == NULL) {
    printf("Current Linked List is empty!(RemoveFromLLst)\n");
    return;
  }
  while (llst->next != NULL) {
    if (llst->next->value == value) {
      LLst *temp = llst->next;
      llst->next = temp->next;
      free(temp);
      return;
    }
    llst = llst->next;
  }
  printf("No node named %s to remove from LLst!(RemoveFromLLst)\n", value);
}

void RemoveConnection(UGraph **p, char *node1, char *node2) {
  UGraph *graph = *p;
  if (graph == NULL) {
    printf("Current Graph has no nodes!(RemoveConnection)\n");
    return;
  }
  int flag_node1 = 0;
  int flag_node2 = 0;
  UGraph *n1 = NULL;
  UGraph *n2 = NULL;

  while (graph != NULL) {
    if (graph->node_name->value == node1) {
      flag_node1 = 1;
      n1 = graph;
    }
    if (graph->node_name->value == node2) {
      flag_node2 = 1;
      n2 = graph;
    }
    if (flag_node1 == 1 && flag_node2 == 1) {
      RemoveFromLLst(&n1->node_name, node2);
      RemoveFromLLst(&n2->node_name, node1);
      return;
    }
    graph = graph->next;
  }
  printf("No connection between nodes %s and %s!(RemoveConnection)\n", node1,
         node2);
}

void RemoveNode(UGraph **p, char *node) {
  UGraph *graph = *p;
  if (graph == NULL) {
    printf("Current Graph has no nodes!(RemoveNode)\n");
    return;
  }
  if (graph->node_name->value == node) {
    LLst *temp = graph->node_name;
    while (temp->next != NULL) {
      RemoveConnection(p, node, temp->next->value);
    }
    graph->node_name = NULL;
    free(temp);
    (*p) = graph->next;
    free(graph);
    return;
  }

  while (graph->next != NULL) {
    if (graph->next->node_name->value == node) {
      LLst *temp = graph->next->node_name;
      while (temp->next != NULL) {
        RemoveConnection(p, node, temp->next->value);
      }
      graph->next->node_name = NULL;
      free(temp);
      UGraph *aux = graph->next;
      graph->next = aux->next;
      free(aux);
      return;
      graph = graph->next;
    }
  }
  printf("No node named %s in current graph!(RemoveNode)\n", node);
}

void FreeGraph(UGraph **p) {
  UGraph *graph = *p;
  if (graph == NULL) {
    printf("Current Graph has no nodes!(FreeGraph)\n");
    return;
  }
  UGraph *aux = graph->next;
  while (graph->next != NULL) {
    printf("Freeing Up Node %s...\n", graph->node_name->value);
    RemoveNode(p, graph->node_name->value);
    graph = aux;
    aux = graph->next;
    // PRINTING THE GRAPH AFTER EACH ITERATION SO WE CAN SEE THE PROPAGATION ON
    // DELETION
    PrintGraph(graph);
  }
  RemoveNode(p, graph->node_name->value);
}
