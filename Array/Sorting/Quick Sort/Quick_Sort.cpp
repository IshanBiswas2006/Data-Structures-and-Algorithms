#include <iostream>
using namespace std;

void Input(int arr[], int n)
{
    cout << "Enter Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void Show(int arr[], int n)
{
    cout << "Before Sorted: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int Partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotindex = start + count;
    swap(arr[pivotindex], arr[start]);

    int i = start, j = end;
    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotindex;
}

void Quick_Sort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int p = Partition(arr, start, end);
    Quick_Sort(arr, start, p - 1);
    Quick_Sort(arr, p + 1, end);
}

void Output(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    Quick_Sort(arr, start, end);
    cout << "The Sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}

int main()
{

    int arr[100];
    int n;

    cout << "Enter Size of array: ";
    cin >> n;

    Input(arr, n);

    Show(arr, n);

    Output(arr, n);

    return 0;
}