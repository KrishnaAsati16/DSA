#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n )
{
    for(int i = 0; i<=n;i++)
    {
         int mini = i;
         for(int j = i;j<=n-1;j++)
         {
            if(arr[j] <arr[mini])
            {
                mini = j;
            }
         }
         int temp = arr[mini];
         arr[mini] = arr[i];
         arr[i] = temp;
         cout << "Runs";
        
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;
    cout << "\n1. Sort array\n2. Exit\nEnter option: ";
    cin >> choice;

    if(choice == 1)
    {
        selection_sort(arr, n);
        cout << "Sorted array: ";
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    else
    {
        cout << "Exit";
    }

    return 0;
}


