#include <bits/stdc++.h>
using namespace std;

void heapifyMax(int* a, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }

    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        int tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;

        heapifyMax(a, n, largest);
    }
}



void heapifyMin(int* a, int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[smallest])
    {
        smallest = l;
    }

    if (r < n && a[r] < a[smallest])
    {
        smallest = r;
    }

    if (smallest != i)
    {
        int tmp = a[i];
        a[i] = a[smallest];
        a[smallest] = tmp;

        heapifyMin(a, n, smallest);
    }
}



void heapSortIncreasing(int* a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMax(a, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        heapifyMax(a, i, 0);
    }
}



void heapSortDecreasing(int* a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMin(a, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        heapifyMin(a, i, 0);
    }
}



int main()
{
    int n;
    if (!(cin >> n))
    {
        return 0;
    }

    int* a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mode;
    cin >> mode;

    if (mode == 1)
    {
        heapSortIncreasing(a, n);
    }
    else
    {
        heapSortDecreasing(a, n);
    }

    for (int i = 0; i < n; i++)
    {
        if (i) cout << " ";
        cout << a[i];
    }

    cout << "\n";

    delete[] a;

    return 0;
}
