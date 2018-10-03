#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll a[12] = {9, 17, 89, 103, 211, 64, 516, 81, 32, 76, 21, 137};
	ll b[12] ;
	for(ll i=0;i<12;i++)
		b[i] = -1;
	for(ll i=0;i<12;i++)
	{   
        ll t = (3*a[i]+4)%12;
		while(1)
		{   
			if(a[i]%2==0)
			{
			if(b[t] == -1)
			{   
				if(t==0)
				{
					if((b[(t+1)%12]%2)!=0)
					{
						b[t%12] = a[i];
				        break;
					}
					else
					{
						t= (t+1) %12;
					}
				}
				else if(t==11)
				{
					if((b[(t-1)%12]%2)!=0)
					{
						b[t%12] = a[i];
				        break;
					}
					else
					{
						t= (t+1) %12;
					}
				}
				else
				{
					if((b[(t+1)%12]%2)!=0 && (b[(t-1+ 12)%12]%2)!=0)
					{
						b[t%12] = a[i];
				        break;
					}
					else
					{
						t= (t+1) %12;
					}
				}
				
			  
			}
			else
			{
				t= (t+1) %12;
			}
		}
		else
		{
			if(b[t] == -1)
			{
               b[t%12] = a[i];
				        break;
					}
					else
					{
						t= (t+1) %12;
					}

		}
		}
		
	}
	cout<<"The list: ";
	for(ll i=0;i<12;i++)
		cout<<" -> "<<b[i] ;
	cout<<endl;
}