#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        swap(arr[i], arr[minIndex]);
    }
}

// Function to merge two subarrays of arr[]
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create dynamic temporary arrays for left and right subarrays
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    // Merge the two temporary arrays back into arr
    int i = 0; // Initial index of leftArr
    int j = 0; // Initial index of rightArr
    int k = left; // Initial index of merged array arr

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of leftArr and rightArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Deallocate dynamic arrays
    delete[] leftArr;
    delete[] rightArr;
}


// Function to perform Merge Sort recursively
void mergeSort(int arr[], int left, int right) {
    if (left < right) 
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// Function to print the elements of an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int size = 1000; // Increased array size to 1000
    int myList[size];

    srand(time(0)); // Seed for random number generation

    // Generate a random array of size 1000
    for (int i = 0; i < size; i++) {
        myList[i] = rand() % 10000; // Generates random numbers between 0 and 999
    }

    // Sort the original list with Selection Sort
    auto startTime = high_resolution_clock::now();
    selectionSort(myList, size);
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Time taken for Selection Sort (Original List): " << duration.count() << " microseconds" << endl;

    // Reset the array for Merge Sort
    copy(begin(myList), end(myList), begin(myList));

    // Sort the original list with Merge Sort
    startTime = high_resolution_clock::now();
    mergeSort(myList, 0, size - 1);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);

    cout << "Time taken for Merge Sort (Original List): " << duration.count() << " microseconds" << endl;


    // Sort the array in ascending order
    sort(myList, myList + size); 


    // Sort a sorted list with Selection Sort
    startTime = high_resolution_clock::now();
    selectionSort(myList, size);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Time taken for Selection Sort (Sorted List): " << duration.count() << " microseconds" << endl;

    // Reset the array for Merge Sort
    copy(begin(myList), end(myList), begin(myList));

    sort(myList, myList + size); // Sort the array in ascending order

    // Sort a sorted list with Merge Sort
    startTime = high_resolution_clock::now();
    mergeSort(myList, 0, size - 1);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Time taken for Merge Sort (Sorted List): " << duration.count() << " microseconds" << endl;


    // Sort the first half in ascending order
    int halfSortedList[size];
    for (int i = 0; i < size / 2; i++) {
        halfSortedList[i] = myList[i]; // Copy the first half
    }
    sort(halfSortedList, halfSortedList + size / 2); 


   // Sort a half-sorted list with Selection Sort
    startTime = high_resolution_clock::now();
    selectionSort(halfSortedList, size);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Time taken for Selection Sort (Half-Sorted List): " << duration.count() << " microseconds" << endl;\


    // Reset the array for Merge Sort
    copy(begin(myList), end(myList), begin(myList));

    for (int i = 0; i < size / 2; i++) {
        halfSortedList[i] = myList[i]; // Copy the first half
    }
    sort(halfSortedList, halfSortedList + size / 2); // Sort the first half in ascending order


    // Sort a half-sorted list with Merge Sort
    startTime = high_resolution_clock::now();
    mergeSort(halfSortedList, 0, size - 1);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Time taken for Merge Sort (Half-Sorted List): " << duration.count() << " microseconds" << endl;


    // Reverse the array
    int reversedList[size];
    for (int i = 0; i < size; i++) {
        reversedList[i] = myList[size - i - 1]; 
    }


    // Sort a reversed list with Selection Sort
    startTime = high_resolution_clock::now();
    selectionSort(reversedList, size);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Time taken for Selection Sort (Reversed List): " << duration.count() << " microseconds" << endl;


    // Reset the array for Merge Sort
    copy(begin(myList), end(myList), begin(myList));

    for (int i = 0; i < size; i++) {
        reversedList[i] = myList[size - i - 1]; // Reverse the array
    }

    
    // Sort a reversed list with Merge Sort
    startTime = high_resolution_clock::now();
    mergeSort(reversedList, 0, size - 1);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Time taken for Merge Sort (Reversed List): " << duration.count() << " microseconds" << endl;

    return 0;
}


// Without using random numbers 

/*int main() {
    const int size = 20; // Increased array size to 20
    int myList[size] = {64, 25, 12, 22, 11, 36, 17, 88, 47, 73, 9, 31, 68, 4, 56, 21, 52, 6, 42, 1};
    int sortedList[size] = {1, 4, 6, 9, 11, 12, 17, 21, 22, 25, 31, 36, 42, 47, 52, 56, 64, 68, 73, 88};
    int halfSortedList[size] = {9, 12, 17, 21, 22, 25, 31, 36, 42, 47, 52, 1, 4, 6, 56, 64, 68, 73, 88, 11};
    int reversedList[size] = {88, 73, 68, 64, 56, 52, 47, 42, 36, 31, 25, 22, 21, 17, 12, 11, 9, 6, 4, 1};

    cout << "Original List: ";
    printArray(myList, size);
    cout<<endl;

    // Selection Sort

    cout<<"\nSelection sort: \n"; 
    cout<<endl;
    auto startTime = high_resolution_clock::now();
    selectionSort(myList, size);
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Sorted (Original List): ";
    printArray(myList, size);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    startTime = high_resolution_clock::now();
    selectionSort(sortedList, size);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "\nSorted (Sorted List): ";
    printArray(sortedList, size);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    startTime = high_resolution_clock::now();
    selectionSort(halfSortedList, size);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "\nSorted (Half-Sorted List): ";
    printArray(halfSortedList, size);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    
    startTime = high_resolution_clock::now();
    selectionSort(reversedList, size);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "\nSorted (Reversed List): ";
    printArray(reversedList, size);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;


    // Merge Sort

    cout<<"\nMerge sort: \n"; 
    cout<<endl;
    startTime = high_resolution_clock::now();
    mergeSort(myList, 0, size - 1);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Sorted(Original List): ";
    printArray(myList, size);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    startTime = high_resolution_clock::now();
    mergeSort(sortedList, 0, size - 1);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "\nSorted (Sorted List): ";
    printArray(sortedList, size);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    startTime = high_resolution_clock::now();
    mergeSort(halfSortedList, 0, size - 1);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "\nSorted(Half-Sorted List): ";
    printArray(halfSortedList, size);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    startTime = high_resolution_clock::now();
    mergeSort(reversedList, 0, size - 1);
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    cout << "\nSorted(Reversed List): ";
    printArray(reversedList, size);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}*/


