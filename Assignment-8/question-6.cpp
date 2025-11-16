#include <bits/stdc++.h>
using namespace std;

struct PQueue
{
    int* a;
    int size;
    int cap;
    bool isMax; 

    PQueue(int capacity, bool maxHeap)
    {
        cap = capacity;
        a = new int[cap];
        size = 0;
        isMax = maxHeap;
    }

    ~PQueue()
    {
        delete[] a;
    }

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

    bool compare(int x, int y)
    {
        if (isMax)
        {
            return x > y;
        }
        else
        {
            return x < y;
        }
    }

    void siftUp(int idx)
    {
        while (idx > 0)
        {
            int parent = (idx - 1) / 2;

            if (compare(a[idx], a[parent]))
            {
                int tmp = a[idx];
                a[idx] = a[parent];
                a[parent] = tmp;
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
            int best = idx;

            if (left < size && compare(a[left], a[best]))
            {
                best = left;
            }

            if (right < size && compare(a[right], a[best]))
            {
                best = right;
            }

            if (best != idx)
            {
                int tmp = a[idx];
                a[idx] = a[best];
                a[best] = tmp;
                idx = best;
            }
            else
            {
                break;
            }
        }
    }

    void insert(int x)
    {
        ensureCapacity();
        a[size] = x;
        size++;
        siftUp(size - 1);
    }

    int peek()
    {
        if (size == 0)
        {
            return INT_MIN;
        }

        return a[0];
    }

    int extract()
    {
        if (size == 0)
        {
            return INT_MIN;
        }

        int top = a[0];
        a[0] = a[size - 1];
        size--;
        if (size > 0)
        {
            siftDown(0);
        }

        return top;
    }

    bool empty()
    {
        return size == 0;
    }
};



int main()
{
    int mode;
    cin >> mode;

    int initialCap = 100;
    bool isMax = (mode == 1);

    PQueue pq(initialCap, isMax);

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
            if (pq.empty())
            {
                cout << "EMPTY\n";
            }
            else
            {
                int val = pq.peek();
                cout << val << "\n";
            }
        }
        else if (op == 3)
        {
            if (pq.empty())
            {
                cout << "EMPTY\n";
            }
            else
            {
                int val = pq.extract();
                cout << val << "\n";
            }
        }
        else if (op == 0)
        {
            break;
        }
    }

    return 0;
}
