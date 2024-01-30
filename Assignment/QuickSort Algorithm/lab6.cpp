#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

// Partition function
int Partition(vector<int>& array, int low, int high) {
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i < j) {
            swap(array[i], array[j]);
        }
        else {
            return j;
        }
    }
}

// Selecting  the first element as the pivot --Choice 1
int ChoosePivot1(const vector<int>& array, int low, int high) {
    return low; 
}

// Selecting a random element as the pivot --Choice 2
int ChoosePivot2(const vector<int>& array, int low, int high) {
    return low + rand() % (high - low + 1); 
}

// Selecting the median of the first, middle, and last elements as Pivot --Choice 3
int ChoosePivot3(const vector<int>& array, int low, int high) {
    int mid = low + (high - low) / 2;

    // If the middle value is between the first and last values, or the last value is between the first and middle values, it indicates a potential median. In such cases, we return the index of the middle value.
    if ((array[low] <= array[mid] && array[mid] <= array[high]) || (array[high] <= array[mid] && array[mid] <= array[low]))
        return mid;

    // If the middle value is between the first and last values, we return the index of the middle value.   
    else if ((array[mid] <= array[low] && array[low] <= array[high]) || (array[high] <= array[low] && array[low] <= array[mid]))
        return low;

    // return the index of the last value as the pivot.     
    else
        return high;
}

// QuickSort Recursive Algorithm
void QuickSort(vector<int>& array, int low, int high, int (*ChoosePivot)(const vector<int>&, int, int))
 
/* Note: In the last parameter, this function pointer allows us to choose different pivot selection strategies when calling the QuickSort function. */

{
    if (low < high) {
        // Choose the pivot index using the selected pivot choice function
        int pivotIndex = ChoosePivot(array, low, high);

        // Swap the pivot element with the element at the 'low' index
        swap(array[low], array[pivotIndex]);

        // Partition the array and get the pivot index
        int partitionIndex = Partition(array, low, high);

        // Recursively applying QuickSort to the two subarrays
        QuickSort(array, low, partitionIndex, ChoosePivot);
        QuickSort(array, partitionIndex + 1, high, ChoosePivot);
    }
}

int main() {
    srand(time(0));

    vector<int> array(100000); // Create an array of 100000 random numbers
    for (int i = 0; i < 100000; ++i) {
        array[i] = rand() % 100000; // Fill the array with random numbers between 0 and 99999
    }

    // Sort with pivot choice 1
    vector<int> array1 = array;
    clock_t startTime = clock();
    QuickSort(array1, 0, array1.size() - 1, ChoosePivot1);
    clock_t endTime = clock();
    double executionTime1 = (double)(endTime - startTime) * 1000 / CLOCKS_PER_SEC;

    // Sort with pivot choice 2
    vector<int> array2 = array;
    startTime = clock();
    QuickSort(array2, 0, array2.size() - 1, ChoosePivot2);
    endTime = clock();
    double executionTime2 = (double)(endTime - startTime) * 1000 / CLOCKS_PER_SEC;

    // Sort with pivot choice 3
    vector<int> array3 = array;
    startTime = clock();
    QuickSort(array3, 0, array3.size() - 1, ChoosePivot3);
    endTime = clock();
    double executionTime3 = (double)(endTime - startTime) * 1000 / CLOCKS_PER_SEC;

    cout << "Execution Time with Pivot Choice 1: " << executionTime1 << " milliseconds\n";
    cout << "Execution Time with Pivot Choice 2: " << executionTime2 << " milliseconds\n";
    cout << "Execution Time with Pivot Choice 3: " << executionTime3 << " milliseconds\n";

    return 0;
}
