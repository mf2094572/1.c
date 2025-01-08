#include <iostream>
#include <cmath>

using namespace std;

// Fungsi untuk menggambar Sierpinski Triangle secara rekursif
void drawSierpinski(int x, int y, int size, int depth, char** canvas) {
    if (depth == 0) {
        // Gambar segitiga
        for (int i = 0; i < size; i++) {
            for (int j = 0; j <= i; j++) {
                canvas[y - i][x + j] = '*'; // Garis kiri
                canvas[y - i][x - j + size] = '*'; // Garis kanan
            }
        }
    } else {
        // Panggil fungsi untuk tiga segitiga yang lebih kecil
        drawSierpinski(x, y, size / 2, depth - 1, canvas);
        drawSierpinski(x + size / 2, y, size / 2, depth - 1, canvas);
        drawSierpinski(x + size / 4, y - (size / 2), size / 2, depth - 1, canvas);
    }
}

// Fungsi untuk mencetak canvas
void printCanvas(char** canvas, int height) {
    for (int i = 0; i < height; i++) {
        cout << canvas[i] << endl;
    }
}

int main() {
	cout<<"MUHAMMAD FADHIL RIFKY"<<endl;
    int depth = 5; // Kedalaman rekursi
    int size = pow(2, depth); // Ukuran segitiga (harus pangkat dua)
    int height = size; // Tinggi segitiga

    // Alokasikan canvas
    char** canvas = new char*[height];
    for (int i = 0; i < height; i++) {
        canvas[i] = new char[2 * size + 1]; // Lebar untuk menampung segitiga
        for (int j = 0; j < 2 * size + 1; j++) {
            canvas[i][j] = ' '; // Inisialisasi dengan spasi
        }
        canvas[i][2 * size] = '\0'; // Akhiri string
    }

    // Gambar Sierpinski Triangle
    drawSierpinski(size / 2, height - 1, size, depth, canvas);

    // Cetak canvas
    printCanvas(canvas, height);

    // Bebaskan memori
    for (int i = 0; i < height; i++) {
        delete[] canvas[i];
    }
    delete[] canvas;

    return 0;
}
