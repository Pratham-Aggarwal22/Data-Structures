#include <iostream>
using namespace std;

class Heap
{
public:
    int Arr[100];
    int heapSize; 

    // Constructor
    Heap()
    {
        heapSize = 0;
    }

    // Function to print the array
    void printArray(int Arr[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << Arr[i] << " ";
        cout << endl;
    }


    // Max Heap Operations


    // Function to modify a value in a max heap.
    void modifyValMax(int i, int val)
    {
        if (i < heapSize)
        {
            Arr[i] = val;
            max_heapify(i);
        }
    }


    // Function to insert a value into a max heap.
    void insert_value_maxHeap(int val)
    {
        if (heapSize < 100)
        {
            Arr[heapSize] = val;
            int current = heapSize;
            while (current > 0 && Arr[current] > Arr[(current - 1) / 2])
            {
                swap(Arr[current], Arr[(current - 1) / 2]);
                current = (current - 1) / 2;
            }
            heapSize++;
        }
    }

    //Function to maintain the max heap property starting from index i.
    void max_heapify(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heapSize && Arr[left] > Arr[largest])
            largest = left;
        if (right < heapSize && Arr[right] > Arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(Arr[i], Arr[largest]);
            max_heapify(largest);
        }
    }


    // Function to extract the maximum element from the max heap.
    int extract_maximum()
    {
        if (heapSize == 0)
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int maxVal = Arr[0];
        Arr[0] = Arr[heapSize - 1];
        heapSize--;
        max_heapify(0);
        return maxVal;
    }

    // Function to perform ascending heap sort.
    void ascendingHeapSort()
    {
        int size = heapSize;
        while (heapSize > 0)
        {
            heapSize--;
            swap(Arr[0], Arr[heapSize]);
            max_heapify(0);
        }
        heapSize = size; // Restore heap size
    }

    // Function to build a max heap from an array.
    void buildMaxHeap()
    {
        for (int i = heapSize / 2; i >= 0; i--) 
        {
            max_heapify(i);
        }
    }


    // Min Heap Operations


    void modifyValMin(int i, int val)
    {
        if (i < heapSize)
        {
            Arr[i] = val;
            min_heapify(i);
        }
    }

    void insert_value_minHeap(int val)
    {
        if (heapSize < 100)
        {
            Arr[heapSize] = val;
            int current = heapSize;
            while (current > 0 && Arr[current] < Arr[(current - 1) / 2])
            {
                swap(Arr[current], Arr[(current - 1) / 2]);
                current = (current - 1) / 2;
            }
            heapSize++;
        }
    }

    void min_heapify(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heapSize && Arr[left] < Arr[smallest])
            smallest = left;
        if (right < heapSize && Arr[right] < Arr[smallest])
            smallest = right;

        if (smallest != i)
        {
            swap(Arr[i], Arr[smallest]);
            min_heapify(smallest);
        }
    }

    int extract_minimum()
    {
        if (heapSize == 0)
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int minVal = Arr[0];
        Arr[0] = Arr[heapSize - 1];
        heapSize--;
        min_heapify(0);
        return minVal;
    }

    void descendingHeapSort()
    {
        int size = heapSize;
        while (heapSize > 0)
        {
            heapSize--;
            swap(Arr[0], Arr[heapSize]);
            min_heapify(0);
        }
        heapSize = size; // Restore heap size
    }

    void buildMinHeap()
    {
        for (int i = (heapSize / 2); i >= 0; i--)
        {
            min_heapify(i);
        }
    }
};

int main()
{
    Heap maxHeap, minHeap; // Instances

    int n, choice;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        maxHeap.insert_value_maxHeap(num);
        minHeap.insert_value_minHeap(num);
    }

    cout << "Enter 0 for descending and 1 for ascending order: ";
    cin >> choice;

    if (choice == 0)
    {
        cout << "Input array: ";
        maxHeap.printArray(maxHeap.Arr, maxHeap.heapSize);
        cout << "Input element: ";
        int val;
        cin >> val;
        maxHeap.insert_value_maxHeap(val);
        cout << "Sorted heap: ";
        maxHeap.buildMaxHeap();
        maxHeap.printArray(maxHeap.Arr, maxHeap.heapSize);
        cout << "On calling extract_minimum: " << minHeap.extract_minimum() << endl;
        cout << "Sorted heap is:" << endl;
        maxHeap.printArray(maxHeap.Arr, maxHeap.heapSize);
    }
    else if (choice == 1)
    {
        cout << "Input array: ";
        minHeap.printArray(minHeap.Arr, minHeap.heapSize);
        cout << "Input element: ";
        int val;
        cin >> val;
        minHeap.insert_value_minHeap(val);
        cout << "Sorted heap: ";
        minHeap.buildMinHeap();
        minHeap.printArray(minHeap.Arr, minHeap.heapSize);
        cout << "On calling extract_maximum: " << maxHeap.extract_maximum() << endl;
        cout << "Sorted heap is:" << endl;
        minHeap.printArray(minHeap.Arr, minHeap.heapSize);
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
