#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y);

class MinHeap
{
    int *harr;
    int capacity;
    int h_size;

public:
    MinHeap(int capacity);

    void MinHeapify(int i);

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    int extractMin();

    void decreaseKey(int i, int new_val);

    int getMin()
    {
        return harr[0];
    }

    void deleteKey(int i);

    void insertKey(int k);
};

MinHeap::MinHeap(int cap)
{
    h_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
    if (h_size == capacity)
    {
        cout << "Overflow: Could not insert key" << endl;
        return;
    }

    h_size++;
    int i = h_size - 1;
    harr[i] = k;

    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;

    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin()
{
    if(h_size <= 0){
        return INT_MAX;
    }
    if(h_size == 1){
        h_size--;
        return harr[0];
    }


    int root = harr[0];
    harr[0] = harr[h_size -1];
    h_size--;
    MinHeapify(0);
    return root;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i,INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);

    int smallest = i;
    if (l < h_size && harr[l] < harr[i])
    {
        smallest = l;
    }

    if (r < h_size && harr[r] < harr[i])
    {
        smallest = r;
    }

    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{

    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout<<h.extractMin()<<" ";
    cout<<h.getMin() << " ";
    h.decreaseKey(2,1);
    cout<<h.getMin()<<endl;

    return 0;
}