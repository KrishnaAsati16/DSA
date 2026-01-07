#include <iostream>
using namespace std;

void shell_sort(int a[], int n)
{
    int i, j, k, temp;
    for (i = n / 2; i > 0; i = i / 2)
    {
        for (j = i; j < n; j++)
        {
            for (k = j - i; k >= 0; k = k - i)
            {
                if (a[k + i] >= a[k])
                    break;
                else
                {
                    temp = a[k];
                    a[k] = a[k + i];
                    a[k + i] = temp;
                }
            }
        }
    }
}

int main()
{
    int a[11], i;

    cout << "Enter Array to Be Sorted\n";
    for (i = 0; i < 11; i++)
        cin >> a[i];

    shell_sort(a, 11);

    cout << "\nSorted Array is\n";
    for (i = 0; i < 11; i++)
        cout << "\t" << a[i];

    return 0;
}
