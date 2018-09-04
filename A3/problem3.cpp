#include<iostream>
using namespace std;

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};


void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->data  = new_data;
    new_node->next = NULL;

   if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }

    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
void dataReverse(struct Node** head_ref){
  if (*head_ref == NULL) return;

  struct Node *last = *head_ref;
  int temp;
  int count = 0;
  while (last->next != NULL){
    temp = last->data;
    last->data = last->next->data;
    last->next->data = temp;

    last = last->next;
    count = count + 1;
  }
  for(int i = count - 1; i>0; i--) {
    last = *head_ref;
    int j = i;
    while (j>0){
      temp = last->data;
      last->data = last->next->data;
      last->next->data = temp;

      last = last->next;
      j = j-1;
    }
  }
}
void reverse(struct Node** head_ref)
    {
        // Initialize current, previous and
        // next pointers
        Node *current = *head_ref;
        Node *prev = NULL, *next = NULL;


        while (current != NULL)
        {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        *head_ref = prev;
    }
void printList(struct Node *node)
{
  while (node != NULL)
  {
     cout<< node->data <<" ";
     node = node->next;
     cout<< endl;
  }
}

int main()
{
  struct Node* head = NULL;

  append(&head, 6);
  append(&head,3);
  append(&head,4);
  append(&head,5);
  append(&head,9);
  append(&head,1);
  append(&head,3);

  cout<< "Linked List is"<<endl;
  printList(head);

  dataReverse(&head);
  cout<<"on Data Reverse"<<endl;
  printList(head);
  reverse(&head);
  cout << "on Pointer Reverse"<< endl;
  printList(head);


  return 0;
}
