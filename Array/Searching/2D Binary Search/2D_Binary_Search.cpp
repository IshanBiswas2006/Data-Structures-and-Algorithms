#include <iostream>
using namespace std;

void Input(int arr[][50], int row, int col)
{
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
}

pair<int, int> Binary_Search(const int arr[][50], int row, int col, int key)
{
    int start = 0;
    int end = row * col - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int r = mid / col;
        int c = mid % col;
        if (arr[r][c] == key)
        {
            return {r, c};
        }
        else if (arr[r][c] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return {-1, -1};
}

void Show(int arr[][50], int row, int col)
{
    cout << "The 2D array is : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Output(int arr[][50], int row, int col, int key)
{
    pair<int, int> result = Binary_Search(arr, row, col, key);
    if (result.first != -1)
    {
        cout << "The element found in index: ( " << result.first << " , " << result.second << " )";
    }
    else
    {
        cout << "The element is not found";
    }
}

int main()
{
    int arr[50][50];
    int row, col, key;

    cout << "Enter row and col: ";
    cin >> row >> col;

    if (row <= 0 || col <= 0 || row > 50 || col > 50)
    {
        cout << "Invalid matrix size!" << endl;
        return 0;
    }

    Input(arr, row, col);

    Show(arr, row, col);

    cout << "Enter the element to search: ";
    cin >> key;

    Output(arr, row, col, key);
    return 0;
}