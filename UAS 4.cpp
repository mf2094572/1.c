#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi untuk melakukan counting sort yang digunakan dalam radix sort
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Array output
    int count[10] = {0}; // Inisialisasi count

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Fungsi untuk melakukan radix sort
void radixSort(int arr[], int n) {
    int maxVal = *max_element(arr, arr + n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// Fungsi untuk melakukan quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk melakukan merge sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L; // Menghapus memori yang dialokasikan
    delete[] R; // Menghapus memori yang dialokasikan
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
	cout << "MUHAMMAD FADHIL RIFKY"<<endl;
    int arr1[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[n]; // Copy untuk quick sort
    int arr3[n]; // Copy untuk merge sort

    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    radixSort(arr1, n);
    cout << "Sorted array using Radix Sort: ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << endl;

    quickSort(arr2, 0, n - 1);
    cout << "Sorted array using Quick Sort: ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;

    mergeSort(arr3,  0, n - 1);
    cout << "Sorted array using Merge Sort: ";
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";
    cout << endl;

    return 0;
}
