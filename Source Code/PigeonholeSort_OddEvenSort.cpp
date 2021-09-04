#include <bits/stdc++.h>
using namespace std;

void pigeonholeSort(int arr[], int n)
{
	// Find min and max
	int min = arr[0], max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	int range = max - min + 1; // Find range
 
	// Create holes that
	// are going to contain matching elements.
	vector<int> holes[range];
 
	// Put every element in its respective hole
	for (int i = 0; i < n; i++)
		holes[arr[i]-min].push_back(arr[i]);
 
	// Traverse through all holes one by one. 
	// For every hole, take its elements and put in array
	int index = 0;  // index in sorted array
	for (int i = 0; i < range; i++)
	{
	   vector<int>::iterator it;
	   for (it = holes[i].begin(); it != holes[i].end(); ++it)
			arr[index++]  = *it;
	}
}

void oddEvenSort(int arr[], int n)
{
	bool isSorted = false; // Initially array is unsorted
	while (!isSorted)
	{
		isSorted = true;
		// Bubble sort on odd indexed element
		for (int i = 1; i <= n - 2; i += 2)
		{
			if (arr[i] > arr[i+1])
			 {
				swap(arr[i], arr[i+1]);
				isSorted = false;
			  }
		}

		// Bubble sort on even indexed element
		for (int i = 0; i <= n - 2; i += 2)
		{
			if (arr[i] > arr[i+1])
			{
				swap(arr[i], arr[i+1]);
				isSorted = false;
			}
		}
	}
	return;
}

void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
       cout << arr[i] << " ";
   cout << "\n";
}

int main()
{
	cout << "Pigeonhole Sort:\n";
	int arr[] = {8, 3, 1, 7, 5, 6, 8, 12, 39, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Given array: ";
	printArray(arr, n);
	pigeonholeSort(arr, n);
	cout << "Sorted array: ";
	printArray(arr, n);

  	cout << "\n\nOdd-Even Sort:\n";
 	int arr2[] = {5, 1, 12, 55, 12, 0, 6, 19, 77, 3};
	n = sizeof(arr)/sizeof(arr[0]);
	cout << "Given array: ";
	printArray(arr2, n);
	oddEvenSort(arr2, n);
	cout << "Sorted array: ";
	printArray(arr2, n);
	return 0;
}