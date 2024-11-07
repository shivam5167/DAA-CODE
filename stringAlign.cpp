     #include <iostream>
using namespace std;
string x, y;
int **arr;
int delta;
int opt(int i, int j)
{
    int alpha;
    if (i == 0 || j == 0)
    {
        if (i == 0)
        {
            return j * 2;
        }
        else
        {
            return i * 2;
        }
    }
    else if (x[i - 1] == y[j - 1])
    {
        return min(min(arr[i - 1][j - 1], arr[i - 1][j] + delta), arr[i][j - 1] + delta);
    }
    else
    {
        if ((x[i - 1] == 'a' || x[i - 1] == 'e' || x[i - 1] == 'i' || x[i - 1] == 'o' || x[i - 1] == 'u') && (y[i - 1] != 'a' || y[i - 1] != 'e' || y[i - 1] != 'i' || y[i - 1] != 'o' || y[i - 1] != 'u'))
        {
            alpha = 3;
        }
        else if ((x[i - 1] != 'a' || x[i - 1] != 'e' || x[i - 1] != 'i' || x[i - 1] != 'o' || x[i - 1] != 'u') && (y[i - 1] == 'a' || y[i - 1] == 'e' || y[i - 1] == 'i' || y[i - 1] == 'o' || y[i - 1] == 'u'))
        {
            alpha = 3;
        }
        else
        {
            alpha = 1;
        }
        return min(min(arr[i - 1][j - 1] + alpha, arr[i - 1][j] + delta), arr[i][j - 1] + delta);
    }
}
int main()
{
    cout << "Enter the string x : ";
    cin >> x;
    cout << "Enter the string y : ";
    cin >> y;
    cout << "Enter the gap cost : ";
    cin >> delta;
    int l1 = x.length();
    int l2 = y.length();
    arr = new int *[l1 + 1];
    for (int i = 0; i <= l1; i++)
    {
        arr[i] = new int[l2 + 1];
    }
    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            arr[i][j] = opt(i, j);
        }
    }
    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
