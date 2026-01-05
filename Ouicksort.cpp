#include<iostream>
#include<vector>
using namespace std;

    int partition(vector<int> &arr, int start,int end)
    {
          int idx = start-1, pivot = arr[end];
          for(int j = start; j<end; j++)
          {
            if (arr[j] <= pivot)
            {
                idx++;
                swap(arr[j], arr[idx]);
            }
            
          }
                idx++;
                swap(arr[end], arr[idx]);
                return idx;
    }

         void quickSort(vector<int> &arr, int start,int end) 
{
           if(start<end)
     {
            int pivIdx = partition(arr,start,end);
            quickSort(arr, start, pivIdx-1); // lefft half
            quickSort(arr, pivIdx+1, end); // right half

     }
}

int main()
{
    vector<int> arr ={11,55,96,75,32,25,10,1,5};
    quickSort(arr,0,arr.size() -1); 
    
    for(int val : arr)
    {
        cout<< val << " ";
    }
    cout << endl;
    return 0;
}