#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
private:
    int* a;
    int size;
    int cap;

    void ensureCapacity()
    {
        if (size < cap)
        {
            return;
        }

        int newCap = cap * 2;
        int* b = new int[newCap];

        for (int i = 0; i < size; i++)
        {
            b[i] = a[i];
        }

        delete[] a;
        a = b;
        cap = newCap;
    }

    void siftUp(int idx)
    {
        while (idx > 0)
        {
            int parent = (idx - 1) / 2;

            if (a[idx] > a[parent])
            {
                int temp = a[idx];
                a[idx] = a[parent];
                a[parent] = temp;

                idx = parent;
            }
            else
            {
                break;
            }
        }
    }

    void siftDown(int idx)
    {
        while (true)
        {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;

            if (left < size && a[left] > a[largest])
            {
                largest = left;
            }

            if (right < size && a[right] > a[largest])
            {
                largest = right;
            }

            if (largest != idx)
            {
                int temp = a[idx];
                a[idx] = a[largest];
                a[largest] = temp;

                idx = largest;
            }
            else
            {
                break;
            }
        }
    }

public:
    PriorityQueue(int capacity)
    {
        cap = capacity;
        a = new int[cap];
        size = 0;
    }

    ~PriorityQueue()
    {
        delete[] a;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void insert(int x)
    {
        ensureCapacity();

        a[size] = x;
        size++;

        siftUp(size - 1);
    }

    int getMax()
    {
        if (size == 0)
        {
            return INT_MIN;
        }

        return a[0];
    }

    int extractMax()
    {
        if (size == 0)
        {
            return INT_MIN;
        }

        int ans = a[0];

        a[0] = a[size - 1];
        size--;

        if (size > 0)
        {
            siftDown(0);
        }

        return ans;
    }
};



int main()
{
    PriorityQueue pq(100);

    while (true)
    {
        int op;
        if (!(cin >> op))
        {
            break;
        }

        if (op == 1)
        {
            int x;
            cin >> x;
            pq.insert(x);
        }
        else if (op == 2)
        {
            if (pq.isEmpty())
            {
                cout << "EMPTY\n";
            }
            else
            {
                cout << pq.getMax() << "\n";
            }
        }
        else if (op == 3)
        {
            if (pq.isEmpty())
            {
                cout << "EMPTY\n";
            }
            else
            {
                cout << pq.extractMax() << "\n";
            }
        }
        else if (op == 0)
        {
            break;
        }
    }

    return 0;
}
