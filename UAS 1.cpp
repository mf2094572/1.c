#include <iostream>
#include <vector>
#include <algorithm> // Untuk std::sort

// Fungsi Linear Search
int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

// Fungsi Binary Search
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Menghindari overflow
        if (arr[mid] == target) {
            return mid; // Mengembalikan indeks jika ditemukan
        } else if (arr[mid] < target) {
            left = mid + 1; // Mencari di bagian kanan
        } else {
            right = mid - 1; // Mencari di bagian kiri
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

int main() {
    // Menggunakan array biasa
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 23; //target pencarian
	std::cout << "Muhammad Fadhil Rifky " << std::endl;
	std::cout << "UAS Ganjil 2024/2025 " << std::endl;
    // Menggunakan Linear Search
    int linearResult = linearSearch(std::vector<int>(data, data + size), target);
    if (linearResult != -1) {
        std::cout << "Linear Search: Elemen " << target << " ditemukan di indeks " << linearResult << std::endl;
    } else {
        std::cout << "Linear Search: Elemen " << target << " tidak ditemukan." << std::endl;
    }

    // Menggunakan Binary Search
    // Pastikan data terurut sebelum menggunakan Binary Search
    std::sort(data, data + size);
    int binaryResult = binarySearch(std::vector<int>(data, data + size), target);
    if (binaryResult != -1) {
        std::cout << "Binary Search: Elemen " << target << " ditemukan di indeks " << binaryResult << std::endl;
    } else {
        std::cout << "Binary Search: Elemen " << target << " tidak ditemukan." << std::endl;
    }

    return 0;
}
