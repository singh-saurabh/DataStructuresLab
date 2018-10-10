#include <bits/stdc++.h>
using namespace std;
struct node
{
	int size,data;
	node *left;
	node *right;
};
void build(node **curr, std::vector<int>& a, int l, int r)
{
	(*curr)->data=a[(l+r)/2];
	if(l==r)
		(*curr)->size=1;
	else
	{
		(*curr)->size=r-l+1;
		(*curr)->left=new node();
		build(&((*curr)->left),a,l,(l+r)/2);
		(*curr)->right=new node();
		build(&((*curr)->right),a,(l+r)/2+1,r);
	}
}
int count(node (*curr), int a, int b,int lbound,int rbound)
{
	if(lbound>a&&rbound<b)
		return curr->size;
	int size=0;
	if(curr->left!=NULL)
		size+=count(curr->left,a,b,lbound,curr->data);
	if(curr->right!=NULL)
		size+=count(curr->right,a,b,curr->data,rbound);
	if(curr->left==NULL&&curr->right==NULL)
		if(curr->data>a&&curr->data<b)
			return curr->size;
	return size;
}
void Delete(node **curr, int i)
{
	if((*curr)->size==1)
	{
		(*curr)->size--;
		return;
	}
	if((*curr)->data<i)
	{
		Delete(&((*curr)->right), i);
		if((*curr)->right->size==0)
			(*curr)->right=NULL;
	}
	else
	{
		Delete(&((*curr)->left), i);
		if((*curr)->left->size==0)
			(*curr)->left=NULL;
	}
	(*curr)->size--;
}
class greytree
{
public:
	node *top;
	greytree(std::vector<int>& a)
	{
		top=new node();
		build(&top,a,0,a.size()-1);
	}
	int Count(int a,int b)
	{
		return count(top,a,b,a,b);
	}
	void DeleteElem(int i)
	{
		Delete(&top, i);
	}
};
int main()
{
	cout << ("Enter no. of elements: ");
	int n;
	cin >> n;
	cout << ("Enter elements: ") << endl;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	sort(a.begin(), a.end());
	greytree g(a);
	while(true)
	{
		cout << ("Enter choice:");
		cout << "\n";
		cout << ("1.Count no. elements between a and b (exclusive)");
		cout << "\n";
		cout << ("2.Delete an element");
		cout << "\n";
		cout << ("3.Exit");
		cout << "\n";
		int te;
		cin >> te;
		if(te==1)
		{
			cout << ("Enter a and b:");
			cout << "\n";
			int ae,be;
			cin >> ae >> be;
			cout << "count is:\t" << g.Count(ae, be);
			cout << "\n";
		}
		else if(te==2)
		{
			cout << ("Enter element to delete(element must be present):");
			cout << "\n";
			int tem;
			cin >> tem;
			g.DeleteElem(tem);
			cout << ("Element deleted\n");
		}
		else
		{
			break;
		}
	}
}
