#include <stdio.h>

#include <stdlib.h>

typedef struct node {
  char letter;
  struct node *next;
} node;

// returns number of nodes in the linkedList.
int length(node *head) {
  int nCount = 0;
  node *temp = head;

  while (temp != NULL) {
    nCount++;
    temp = temp->next;
  }

  return nCount;
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"

char *toCString(node *head) {
  node *traverse = head;
  // allocating memory for the character array (string) called temp that is
  // equal to the size of the linked list
  char *temp = malloc((length(head) + 1) * sizeof(char));

  // going through each node in the linked list, until the size of the linked
  // list is reached
  for (int i = 0; i < length(head); i++) {
    // for the first element of the character array, make it equal to the
    // character stored in letter
    temp[i] = traverse->letter;
    traverse = traverse->next;
  }
  temp[length(head)] = '\0';

  return temp;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c) {
  // temp pointer points to the address that pointer head points to (the
  // beginning of the list)
  node *temp = *pHead;
  node *insert = malloc(sizeof(node));
  insert->letter = c;
  insert->next = NULL;
  if(*pHead == NULL)
    *pHead = insert;
  else{
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = insert;
  }  
}

// deletes all nodes in the linkedList.
void deleteList(node **pHead) {
  node *temp;

  while (temp != NULL) {
    node* next = temp->next;
    free(temp);
    temp = next;
  }
  *pHead = NULL;
}

int main(void) {
  int i, strLen, numInputs;
  node *head = NULL;
  char *str;
  char c;
  FILE *inFile = fopen("input.txt", "r");
  fscanf(inFile, " %d\n", &numInputs);
  while (numInputs-- > 0) {
    fscanf(inFile, " %d\n", &strLen);
    for (i = 0; i < strLen; i++) {
      fscanf(inFile, " %c", &c);
      insertChar(&head, c);
    }
    str = toCString(head);
    printf("String is : %s\n", str);
    free(str);
    deleteList(&head);
    if (head != NULL) {
      printf("deleteList is not correct!");
      break;
    }
  }
  fclose(inFile);
}