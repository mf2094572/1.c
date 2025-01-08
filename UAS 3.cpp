#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(const vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr; // Basis rekursi
    }

    int pivot = arr[arr.size() / 2]; // Memilih pivot
    vector<int> left, right, equal;

    for (int num : arr) {
        if (num < pivot) {
            left.push_back(num);
        } else if (num > pivot) {
            right.push_back(num);
        } else {
            equal.push_back(num);
        }
    }

    // Menggabungkan hasil
    vector<int> sortedArray = quickSort(left);
    sortedArray.insert(sortedArray.end(), equal.begin(), equal.end());
    vector<int> rightSorted = quickSort(right);
    sortedArray.insert(sortedArray.end(), rightSorted.begin(), rightSorted.end());

    return sortedArray;
}

// Fungsi utama
int main() {
    cout << "MUHAMMAD FADHIL RIFKY "<<endl;
    vector<int> arr = {3, 6, 8, 10, 1, 2, 1};
    vector<int> sortedArr = quickSort(arr);

    cout << "Sorted Array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

