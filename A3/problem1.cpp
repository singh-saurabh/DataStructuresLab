//Sorting is done by quicksort: Complexity nlogn.
//Then n-1/2 th element is printed for odd length Array
//and mean of n/2 and n/2 -1 th element is printed otherwise

#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
  cout << "Enter Size of Array ";
  int n;
  std::cin >> n;
  std::cout << "Enter elements" << '\n';
  int *arr = new int [n];
  for (int i = 0; i<n; i++){
      cin >> arr[i];
  }
  float mean;
  quickSort(arr, 0, n-1);
  if (n%2 == 1) {
      mean = arr[(n-1)/2];
  }
  else if (n%2 == 0) {
    mean = (float) (arr[(n/2) - 1] + arr[n/2])/2;
  }
  cout << "Mean is " << mean;
  return 0;
}
