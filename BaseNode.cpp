#include<iostream>
using namespace std;

class Node
{
	
public:
	int data; 
	Node* next;
	Node();
	Node(int data1){
		data = data1;
		next = NULL;
	}
};

void append(Node** head, int newData) {
	if (*head == NULL)
	{
		*head = new Node(newData);
	}
	else {
		Node* previousNode;
		Node* nextNode;
		previousNode = *head;
		while(previousNode->next != NULL){
			previousNode = previousNode->next;
		}
		Node* newNode = new Node(newData);
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

void split(Node** head, Node** headA, Node** headB){
	*headA = new Node(*head->data);
	Node* nextNode = *head;
	int i=0;
	do {
		if(i%2==0){
			append(&headA, nextNode->data);
		}
		else if(i%2==1){
			append(&headB, nextNode->data);
		}
		nextNode = nextNode->next;
		i++;
	}
	while(nextNode->next != NULL);
}

int main()
{
	Node* head  = NULL;
	Node* headA = NULL;
	Node* headB = NULL;


	cout<<"Enter the length of linked list"<< endl;
	int length;
	cin>>length;

	for (int i = 0; i < length; ++i)
	{
		int k;
		cin>>k;
		append(&head, k);
	}

	printList(&head);
	split(&head, &headA, &headB);

	printList(&headA);
	printList(&headB);

	return 0;
}