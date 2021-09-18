/* NAME -Shaini Dasgupta
   Roll- 16900119084
   Sem - 4th
   Dept - CSE

Q6) Heap Sort.*/



#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout <<endl;
}
void heapify(int arr[], int n, int i)
{
	int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i)
	{
      swap(arr[i], arr[largest]); //Swaps first and last node
      heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
	int pass=1;
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
	{
      swap(arr[0], arr[i]);
      if(pass<n)
      {
      	cout<<"Pass "<<pass++<<": ";
      	printArray(arr, n);
	  }
      heapify(arr, i, 0); //Creates max heap
      cout<<endl;
    }
}


int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    heapSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
}
