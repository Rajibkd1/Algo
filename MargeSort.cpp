#include <iostream>
using namespace std;

void Merge(int *a, int low, int high, int mid)
{
    int i, j, k, temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;

    // Merging two sub-arrays
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    // Copy the remaining elements from the left sub-array
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    // Copy the remaining elements from the right sub-array
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    // Copy the merged elements back to the original array
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}

void MergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;

        // Recursively sort the left and right sub-arrays
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);

        // Merge the sorted sub-arrays
        Merge(a, low, high, mid);
    }
}

int main()
{
    int n, i;
    cout << "Enter the number of elements to be sorted: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call MergeSort to sort the array
    MergeSort(arr, 0, n - 1);

    cout << "Sorted Data: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
