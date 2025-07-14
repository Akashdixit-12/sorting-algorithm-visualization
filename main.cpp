#include <iostream>
#include <vector>
#include <cstdlib>     // for system("cls") / system("clear")
#include <unistd.h>    // for usleep (Linux/macOS), use Sleep in Windows
#include <ctime>       // for random seed
using namespace std;

// Function to print the array as bars
void printArray(const vector<int>& arr, int i = -1, int j = -1) {
    system("clear");  // Use "cls" if you're on Windows
    for (int k = 0; k < arr.size(); ++k) {
        // Highlight the compared elements
        if (k == i || k == j) cout << "[" << arr[k] << "] ";
        else cout << " " << arr[k] << "  ";
    }
    cout << endl;
    usleep(200000); // 200ms delay
}

// Bubble Sort with visualization
void bubbleSortVisual(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            printArray(arr, j, j+1);

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    printArray(arr);  // Final sorted array
    cout << "\nSorting Complete!" << endl;
}

int main() {
    srand(time(0));
    int size;
    cout << "Enter size of array (5-20 recommended): ";
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 100;

    cout << "\nInitial Array:\n";
    printArray(arr);
    usleep(1000000); // 1 sec pause

    bubbleSortVisual(arr);

    return 0;
}
