#include <iostream>
using namespace std;

void Input(int n, int arr[]){
    cout << "Enter numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void Output(int arr[] , int n){
    cout << "The Sorted array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int Selection_Sort(int arr[],int n){

    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
    return 1;
}

int main()
{
    int arr[100];
    int n, i, j;

    cout << "Enter size of array: ";
    cin >> n;

    Input(n,arr);

    int result=Selection_Sort(arr,n);

    if(result == 1) {
        cout << "Sorted array:\n";
        Output(arr, n);
    }

    return 0;
}