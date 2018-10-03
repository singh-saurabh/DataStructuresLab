#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
	Node* next;
	ll data;
};

class SLL
{
  private:
  	Node* head;
  public:
  	 SLL (){ head = NULL; }  

  	 void appendNode (ll data)
  	 {
  	 	Node* newNode = new Node;
  	 	Node* tmpNode;
  	 	newNode->data = data;
  	 	newNode->next = NULL;

  	 	if(head == NULL)
  	 	{
            head = newNode;
  	 	}
  	 	else
  	 	{
  	 		tmpNode = head;
  	 		while(tmpNode->next!=NULL)
  	 			tmpNode = tmpNode->next;
  	 		tmpNode->next =newNode;
  	 	}
  	 }
  	 void displayList()
  	 {
  	 	Node* tmpNode = head;
  	 	while(tmpNode!=NULL)
  	 	{
  	 		cout<<tmpNode->data<<"  ";
  	 		tmpNode = tmpNode->next;
  	 	}
  	 }
     ll listSize()
     {
      Node* tmp = head;
      ll tp = 0;
        while(tmp!=NULL)
      {
       tp++;
       tmp = tmp->next;
      }
      return tp;
     }
  	 
};


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  SLL list[6];
  ll a[12] = {9, 17, 89, 103, 211, 64, 516, 81, 32, 76, 21, 137};
  for(ll i=0;i<12;i++)
  {
    ll tmp = (3*a[i] + 4) % 6;
    list[tmp].appendNode(a[i]);
  }
  
  for(ll i=0;i<6;i++)
  {
    cout<<"List "<<i<<" is: ";
    list[i].displayList();
    cout<<endl;
  }

  ll max = list[0].listSize();
  ll index = 0;
  for(ll i=1;i<6;i++)
  {
    if(list[i].listSize()>max)
    {
      max = list[i].listSize();
      index = i;
    }
  }
  cout<<"Largest sequence is created at index "<<index<<" and has size "<<max;
  cout<<endl;

}