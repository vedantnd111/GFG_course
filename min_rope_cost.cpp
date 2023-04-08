#include <bits/stdc++.h>
using namespace std;

struct heap
{
    int size;
    int capacity;
    int *arr;
};

struct heap *createMinHeap(int capacity)
{
    struct heap *hp = new heap;
    hp->capacity = capacity;
    hp->size = 0;
    hp->arr = new int[capacity];
    return hp;
}

void swap(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}

void minHeapify(struct heap *hp, int i)
{
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < hp->capacity && hp->arr[smallest] > hp->arr[l])
    {
        smallest = l;
    }
    if (r < hp->capacity && hp->arr[smallest] > hp->arr[r])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(hp->arr[smallest], hp->arr[i]);
        minHeapify(hp, smallest);
    }
}

int extract_min(struct heap *hp, int n)
{
    int temp = hp->arr[0];
    hp->arr[0] = hp->arr[hp->size - 1];
    hp->size--;
    minHeapify(hp, 0);
    return temp;
}

void insertInHeap(struct heap *hp, int t)
{
    hp->size++;
    hp->arr[hp->size - 1] = t;
    minHeapify(hp, hp->size - 1);
}

struct heap *createBuildHeap(int arr1[], int n)
{
    struct heap *hp = createMinHeap(n);
    for (int i = 0; i < n; i++)
    {
        hp->arr[i] = arr1[i];
        hp->size++;
    }
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        minHeapify(hp, i);
    }
    return hp;
}

int main()
{
    int n;
    cout << "enter capacity of the heap:\n";
    cin >> n;
    int arr[n], x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = x;
    }
    createBuildHeap(arr, n);
}