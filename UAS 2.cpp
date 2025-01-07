#include <iostream>

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Menggabungkan kedua array
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k] = arr1[i]; // Tambahkan elemen dari arr1
            i++; // Geser pointer arr1
        } else {
            merged[k] = arr2[j]; // Tambahkan elemen dari arr2
            j++; // Geser pointer arr2
        }
        k++; // Geser pointer merged
    }

    // Menambahkan sisa elemen dari arr1 jika ada
    while (i < size1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // Menambahkan sisa elemen dari arr2 jika ada
    while (j < size2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    // Mendeklarasikan dua array yang sudah terurut
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};

    // Ukuran dari kedua array
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Array untuk menyimpan hasil penggabungan
    int merged[size1 + size2];

    // Menggabungkan kedua array
    mergeSortedArrays(arr1, size1, arr2, size2, merged);

    // Menampilkan hasil penggabungan
    std::cout << "NAMA:MUHAMMAD FADHIL RIFKY "<< std::endl;
    std::cout << "UAS Ganjil 2024/2025 "<< std::endl;
    std::cout << "Array yang digabungkan: ";
    for (int i = 0; i < size1 + size2; ++i) {
        std::cout << merged[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
