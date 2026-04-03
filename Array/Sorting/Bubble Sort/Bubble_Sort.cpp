#include <iostream>
using namespace std;

void Input(int arr[], int count)
{
    cout << "Enter elements: " << endl;
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
}

int Bubble_Sort(int arr[], int count)
{
    int i, j;
    int swaps = 0;
    bool swapped;

    for (i = 0; i < count - 1; i++)
    {
        swapped = false;
        for (j = 0; j < count - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    return swaps;
}

void Output(int arr[], int count)
{

    int result = Bubble_Sort(arr, count);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    int arr[100];

    cout << "Enter size of array: ";
    cin >> n;

    Input(arr, n);

    Output(arr, n);

    return 0;
}