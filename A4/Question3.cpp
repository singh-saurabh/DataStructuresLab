#include<iostream>
using namespace std;

class Node
{
	
public:
	int data; 
	Node* next;
	Node* prev;
	Node();
	Node(int data1, Node* previousNode){
		data = data1;
		next = NULL;
		prev = previousNode;
	}
};

void append(Node** head, int newData) {
	if (*head == NULL)
	{
		*head = new Node(newData, NULL);
	}
	else {
		Node* previousNode;
		Node* nextNode;
		previousNode = *head;
		while(previousNode->next != NULL){
			previousNode = previousNode->next;
		}
		Node* newNode = new Node(newData, previousNode);
		previousNode->next = newNode;
	}
}

void printList(Node** head) {
	Node* nextNode;
	nextNode = *head;

	cout<< "The list is"<<endl;

	while(nextNode != NULL){
		cout << nextNode->data << endl;
		nextNode = nextNode->next;
	}
}


//Functions for the DEQUE
void insertFront(int data, Node** oldHead, Node** oldTail){
	Node* head= *oldHead;
	Node* newHead = new Node(data, NULL);
	newHead->next = head;
	if(head!= NULL) head->prev = newHead;
	*oldHead = newHead;

	if((*oldTail)== NULL){
		*oldTail = newHead;
	}
}
void insertLast(int data, Node** oldHead, Node** oldTail){
	Node* newTail = new Node(data, (*oldTail));
	if((*oldTail)!=NULL){
		(*oldTail)->next = newTail;
	}
	*oldTail = newTail;

	if((*oldHead)== NULL){
		*oldHead=newTail;
	}
}
void deleteFront(Node** head, Node** tail){
	if((*head)!=NULL && (*head)->next == NULL) {
		*tail = NULL;
		*head = NULL;
	}
	else if((*head)!=NULL){
		*head= (*head)->next;
		(*head)->prev=NULL;
	}
}
void deleteLast(Node** head, Node** tail){
	if((*tail)!= NULL && (*tail)->prev == NULL) {
		*head = NULL;
		*tail = NULL;
	}
	else if((*tail)!= NULL) {
		*tail = (*tail)->prev;
		(*tail)->next = NULL;
	}
}

void showPrompt(){
	cout<<endl;
	cout<<"Press 1 to Show List"<<endl;
	cout<<"Press 2 to Insert at Front"<<endl;
	cout<<"Press 3 to Insert at End"<<endl;
	cout<<"Press 4 to Delete at Front"<<endl;
	cout<<"Press 5 to Delete at End"<<endl;
	cout<<"Press 0 to exit"<<endl;
}

int main()
{
	Node* head  = NULL;
	Node* tail = NULL;
	while(true){
		showPrompt();
		int c;
		cin>>c;
		cout<<endl;
		if (c==1){
			printList(&head);
		}
		else if (c==2){
			cout<<"Enter Data"<<endl;
			int data;
			cin>>data;
			insertFront(data,&head,&tail);

		}
		else if (c==3){
			cout<<"Enter Data"<<endl;
			int data;
			cin>>data;
			insertLast(data,&head,&tail);
		}
		else if (c==4){
			deleteFront(&head,&tail);
		}
		else if (c==5){
			deleteLast(&head,&tail);

		}
		else if(c==0){
			break;
		}
		else {
			cout<<"Enter a valid number"<<endl;
		}
	}
	

	return 0;
}