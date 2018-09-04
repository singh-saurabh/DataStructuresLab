#include<iostream>
using namespace std;
struct sequential_queue{
	int size1,size2;
	int *a1;
	int *a2;
};
void enqueue(sequential_queue *q1,int n){
	int a[q1->size2+1];
	for (int i=0;i<q1->size2;i++)
	a[i]=q1->a2[i];
	a[q1->size2]=n;
	q1->size2++;
	delete(q1->a2);
	q1->a2=(int*)malloc(sizeof(int) * q1->size2);
	for (int i=0;i<q1->size2;i++)
	q1->a2[i]=a[i];
}
void dequeue(sequential_queue *q1){

	q1->size1=q1->size2;
	q1->a1=(int*)malloc(sizeof(int) * q1->size1);
	for (int i=0;i<q1->size2;i++)
	q1->a1[i]=q1->a2[q1->size2-i-1];

	delete(q1->a2);
	q1->size2=0;


	int n[q1->size1-1];
	q1->size1--;
	for (int i=0;i<q1->size1;i++)
	n[i]=q1->a1[i];
	int k=q1->a1[q1->size1];
	delete(q1->a1);
	q1->a1=(int*)malloc(sizeof(int) * q1->size1);
	for (int i=0;i<q1->size1;i++)
	q1->a1[i]=n[i];
	cout<<k<<endl;
}
int main() {
	// your code goes here
	sequential_queue q;
	q.size1=0;q.size2=0;
	q.a1=(int*)malloc(sizeof(int) * q.size1);
	q.a2=(int*)malloc(sizeof(int) * q.size2);
	for (int i=0;i<3;i++)
	{
		enqueue(&q,i+1);
	}
	for (int i=0;i<3;i++)
	{
		cout<<q.a2[i]<<" ";
	}
	cout<<endl;
	enqueue(&q,4);
	enqueue(&q,5);
	for (int i=0;i<q.size2;i++)
	{
		cout<<q.a2[i]<<" ";
	}
	cout<<endl;
	dequeue(&q);
	for (int i=0;i<q.size1;i++)
	{
		cout<<q.a1[i]<<" ";
	}
	cout<<endl;

	return 0;
}


/*
b)
Both can be possible but independent implementation is much more simpler.
I have first extended a1[],copied the reversed the a2[] in a1[] and then shrunk it

c)
Same thing can also be implemented using linked list just that complexity will get reduced and much simpler implementation
since memory allocation is much simpler using linked list than array.
*/
