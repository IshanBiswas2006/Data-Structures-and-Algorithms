#include<iostream>
using namespace std;

void Input(int arr[], int count){

    cout<<"Enter Elements: "<<endl;
    for (int i = 0; i < count; i++)
    {
        cin>>arr[i];
    }
}

int Insertion_Sort(int arr[], int count){

    for (int i = 1; i < count; i++)
    {
        int key=arr[i];
        int j=i-1;
        while (j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    return 0;
}

void Output(int arr[], int count){

    Insertion_Sort(arr,count);

    cout<<"Sorted array is: "<<endl;
    for (int i = 0; i < count; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[100];
    int n;

    cout<<"Enter size of array: ";
    cin>>n;

    Input(arr,n);

    Output(arr,n);

    return 0;
}