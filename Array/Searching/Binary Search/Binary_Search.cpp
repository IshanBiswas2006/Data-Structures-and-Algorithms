#include<iostream>
using namespace std;

void Input(int arr[],int count){
    cout<<"Enter sorted elements"<<endl;
    for (int i = 0; i < count; i++)
    {
        cin>>arr[i];
    }
}

int Binary_Search(int arr[],int key,int count){
    int start=0;
    int end=count-1;
    while (start<=end)
    {
        int mid=(start+end)/2;
        if (arr[mid]==key)
        {
            return mid;
        }
        else if (arr[mid]<key)
        {
           start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return -1;
}

void Output(int arr[],int count,int key){
    int result=Binary_Search(arr,key,count);
    if (result != -1)
    {
        cout<<"Element found in index: "<<result;
    }
    else
    {
        cout<<"Element not found";
    }
}

int main() {

    int count,key;
    int arr[100];

    cout<<"Enter size of array: ";
    cin>>count;

    Input(arr,count);
    
    cout<<"Enter a Element to found: ";
    cin>>key;

    Output(arr,count,key);

    return 0;
}