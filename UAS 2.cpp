#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void findPairsWithSum(const vector<int>& arr1, const vector<int>& arr2, int K) {
    unordered_map<int, int> hashMap;

    // Menyimpan elemen dari array pertama ke dalam hash map
    for (int num : arr1) {
        hashMap[num] = 1; // Nilai tidak penting, hanya untuk kehadiran
    }
    cout << "MUHAMMAD FADHIL RIFKY " << endl;
    cout << "Pasangan yang jumlahnya sama dengan " << K << ":\n";
    // Mencari pasangan dari array kedua
    for (int num : arr2) {
        int complement = K - num;
        if (hashMap.find(complement) != hashMap.end()) {
            cout << "(" << complement << ", " << num << ")\n";
        }
    }
}

// Fungsi utama
int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {6, 5, 4, 3, 2};
    int K = 7;

    findPairsWithSum(arr1, arr2, K);

    return 0;
}
