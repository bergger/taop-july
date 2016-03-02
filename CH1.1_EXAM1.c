#include "stdio.h"
#include "stdlib.h"

#ifndef NODE
#define NODE struct Node
#endif

NODE
{
  int val;
  NODE *next;
};

NODE *head = NULL;
NODE *tail = NULL;
NODE *left = NULL;

void leftRotateList(int total, int count);
void reverseList(int count);
void printList();
void add_to_list(int val);
void create_list(int val);
NODE * create_node(int val);

int main(int argc, char const *argv[])
{
  int total;
  int count;

  printf("input two numbers separated by comma(,) :\n");
  scanf("%d,%d",&total, &count);

  // printf("%i\n", total);
  // printf("%i\n", count);

  for (int i = 1; i <= total; ++i)
  {
    add_to_list(i);
  }

  printList();

  leftRotateList(total, count);

  return 0;
}

void add_to_list(int val) {
  if (head == NULL)
  {
    create_list(val);
    return;
  }

  NODE *node = create_node(val);
  if (node == NULL)
  {
    return;
  }

  tail->next = node;
  tail = node;
}

void create_list(int val) {
  NODE *node = create_node(val);

  if (node == NULL)
  {
    return;
  }

  head = tail = node;
}

NODE * create_node(int val) {
  NODE *node = (NODE *)malloc(sizeof(NODE));

  if (node == NULL)
  {
    printf("Node created failed\n");
    return NULL;
  }
  node->val = val;
  node->next = NULL;

  return node;
}

void printList() {
  NODE *node = head;
  while(node != NULL ) {
    if (node -> next != NULL)
    {
      printf("%i -> ", node -> val);
    } else {
      printf("%i \n", node -> val);
    }

    node = node -> next;
  }
}

void leftRotateList(int total, int count) {
  
  reverseList(count);
  printList();
  // printf("%i\n", left -> val);
  // printf("%i\n", tail -> val);

  tail -> next = head;
  head = left -> next;
  left -> next = NULL;

  printList();
}

void reverseList(int count) {
  tail = head;
  NODE *pre = NULL; NODE *next = head -> next;
  while(next != NULL) {
    head -> next = pre;
    pre = head;
    head = next;
    next = head -> next;
    if (count-- == 0)
    {
      left = pre;
    }
  }
  head -> next = pre;


}
