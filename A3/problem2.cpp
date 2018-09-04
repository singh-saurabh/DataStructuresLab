/*
Since x<=y<=z
|y-x|+ |z-y| = y-x + z-y
= z-x
To maximize z-x, we just need to find the max and min elements
*/

#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int maxOrMin (int arr[], int n, bool max){
  int currentMaximum = arr[0];
  int temp;
  for(int i = 0; i < n-1; i++){
    if((arr[i] > arr[i+1]) && max) {
      swap(&arr[i], &arr[i+1]);
    }
    else if ((arr[i] < arr[i+1]) && !max){
      swap(&arr[i], &arr[i+1]);
    }
  }
  return arr[n-1];
}

int main(){
  cout << "Enter Size of Array ";
  int n;
  std::cin >> n;
  std::cout << "Enter elements" << '\n';
  int *arr = new int [n];
  for (int i = 0; i<n; i++){
      cin >> arr[i];
  }
  int a = maxOrMin(arr, n, true) - maxOrMin(arr, n , false);
  cout << "Max of |y-x|+ |z-y| when x<=y<=z is " << a << endl;
  cout << "Where x is "<< maxOrMin(arr,n, false) << endl;
  cout << "y is ";
  for (int i = 0; i< n; i++){
    cout<<arr[i]<<" ;"
  }
  cout<<endl;
  cout << "z is "<< maxOrMin(arr,n, true) << endl;

  return 0;
}
