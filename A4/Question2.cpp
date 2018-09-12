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

bool checkforthree(Node* current){
	int i=1;
	Node* curr = current;
	if(curr!=NULL){
		while(curr->next != NULL && i<=3){
		i++;
		curr = curr->next;
	}
	if(i>=3) return true;
	else return false;
	}
	else return false;

}

void swapthree(Node* current){
	Node* first= current;
	Node* second= first->next;
	Node* third= second->next;
	int copyOfFirst= first->data;

	first->data = third->data;
	third->data = copyOfFirst;

}
int main()
{
	Node* head  = NULL;

	cout<<"Enter the length of linked list"<< endl;
	int length;
	cin>>length;
	cout<<"Enter the values"<< endl;

	for (int i = 0; i < length; ++i)
	{
		int k;
		cin>>k;
		append(&head, k);
	}

	Node* current = head;
	while(checkforthree(current)){
		swapthree(current);
		current = current->next->next->next;
	}

	printList(&head);
	

	return 0;
}