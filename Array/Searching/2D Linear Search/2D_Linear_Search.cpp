#include <iostream>
using namespace std;

void Input(int arr[][50], int col, int row)
{
    cout << "Enter elements: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void Show(int arr[][50], int row, int col)
{
    cout << "The 2D array:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int Linear_Search(int arr[][50], int key, int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == key)
            {
                return i * col + j;
            }
        }
    }
    return -1;
}

void Output(int arr[][50], int col, int row, int key)
{
    int result = Linear_Search(arr, key, col, row);

    if (result != -1)
    {
        int r = result / col;
        int c = result % col;
        cout << "The element in index: (" << r << " , " << c << ")";
    }
    else
    {
        cout << "Element not found";
    }
}

int main()
{

    int arr[50][50];
    int c, r, key;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    Input(arr, c, r);

    Show(arr,r,c);

    cout << "Enter the element to search: ";
    cin >> key;

    Output(arr, c, r, key);

    return 0;
}