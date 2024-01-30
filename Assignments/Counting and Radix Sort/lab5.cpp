#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// maximum element from the array
int findMax(const vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting Sort
vector<int> countingSort(const vector<int>& arr) {
    int max = findMax(arr); // Findind maximum element
    vector<int> count(max + 1, 0); // Creating vector with size of (maximum element)+1 and setting all the elements to 0.
    vector<int> output(arr.size()); // Output vector

    // Count the occurrences of each element
    for (int i = 0; i < arr.size(); ++i) {
        count[arr[i]]++;
    }

    // Cumulative sum of count array
    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    return output;
}

// Radix Sort
void radixSort(vector<int>& arr) {
    int max = findMax(arr); // finding mazimum element in array
    int d = 0;
    while (max > 0) {
        max /= 10;
        d++;
    }

    int exp = 1;
    vector<int> output(arr.size()); // Output vector

    for (int i = 0; i < d; ++i) {
        vector<int> count(10, 0);

        // Count the occurrences of each digit
        for (int j = 0; j < arr.size(); ++j) {
            int digit = (arr[j] / exp) % 10;
            count[digit]++;
        }

        // Cumulative sum of count array
        for (int j = 1; j < 10; ++j) {
            count[j] += count[j - 1];
        }

        // Build the output array
        for (int j = arr.size() - 1; j >= 0; --j) {
            int digit = (arr[j] / exp) % 10;
            output[count[digit] - 1] = arr[j];
            count[digit]--;
        }

        // Update the original array with sorted values
        for (int j = 0; j < arr.size(); ++j) {
            arr[j] = output[j];
        }

        exp *= 10; // To move to the next digit position
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = arr.size();
    const int numIterations = 1000; // Number of iterations for timing

    // Initializing time for both sorting algorithms to 0 milliseconds
    double total_elapsed_time_counting = 0.0;
    double total_elapsed_time_radix = 0.0;

    for (int i = 0; i < numIterations; ++i) {
        // Measure execution time for Counting Sort
        clock_t start_time = clock();
        vector<int> result_counting = countingSort(arr);
        clock_t end_time = clock();
        total_elapsed_time_counting += double(end_time - start_time) / CLOCKS_PER_SEC * 1000;

        // Measure execution time for Radix Sort
        start_time = clock();
        radixSort(arr);
        end_time = clock();
        total_elapsed_time_radix += double(end_time - start_time) / CLOCKS_PER_SEC * 1000;
        
        if (i == 0) {
            cout << "Counting Sort Result (first iteration): ";
            for (int i = 0; i < result_counting.size(); ++i) {
                cout << result_counting[i] << " ";
            }
            cout << endl;

            cout << "Radix Sort Result (first iteration): ";
            for (int i = 0; i < arr.size(); ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    // Calculate average execution times
    double average_elapsed_time_counting = total_elapsed_time_counting / numIterations;
    double average_elapsed_time_radix = total_elapsed_time_radix / numIterations;

    cout << "Average Time taken for Counting Sort (over 1000 iterations): " << average_elapsed_time_counting << " milliseconds" << endl;
    cout << "Average Time taken for Radix Sort (over 1000 iterations): " << average_elapsed_time_radix << " milliseconds" << endl;

    return 0;
}
