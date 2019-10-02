#include <stdio.h>
#include <stdlib.h>


struct node{
 int data;
 struct node* next;
};



typedef struct node Node;

int main(int argc, char* argv[])
{
Node * first = (Node*) malloc (sizeof(Node));
Node * second = (Node*) malloc (sizeof(Node));
Node * third = (Node*) malloc (sizeof(Node));
Node * fourth = (Node*) malloc (sizeof(Node));

first->data = 12;
first->next = second;

second->data = 13;
second->next = third;

third->data = 14;
third->next = fourth;

fourth->data = 15;
fourth->next = NULL

;


Node* node1 = first;
while(node1!=NULL){
 printf("%d\n",node1->data);
 node1 = node1->next;
}

free(fourth);
free(third);
free(second);
free(first);

return 0;
}
