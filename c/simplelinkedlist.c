#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}_node;


_node* create_node(){
   return (_node*)malloc(sizeof(_node));
}

bool delete_node(_node* ptr){
   if(ptr==NULL){
        return false;
   }
   free(ptr);  
   return true; 
}


void insert_node(_node * ptr_src, int data, _node * ptr_dst){
  ptr_src->data = data;
  ptr_src->next = ptr_dst;
}

void display_list(_node * ptr){
  while(ptr != NULL){
    printf("[%d]",ptr->data);
    ptr = ptr->next;
  }
}

int main(int argc, char* argv[]){

   _node* head = NULL;
   _node* tail = NULL;
   _node* first = create_node();
   _node* second = create_node();
   _node* third = create_node();
   _node* fourth = create_node();
 
  //Init the list
   head = first;

   insert_node(first, 10, second);
   insert_node(second, 20, third);
   insert_node(third, 30, fourth);
   insert_node(fourth, 40, tail);

   display_list(head);

   delete_node(first);
   delete_node(second);
   delete_node(third);
   delete_node(fourth);

return 0;
}
