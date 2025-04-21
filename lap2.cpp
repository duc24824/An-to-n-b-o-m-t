#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// bai 1
int main() {
    int n;
    cout << "Nhap so luong ky tu: ";
    cin >> n;

    vector<double> probabilities(n);
    double entropy = 0.0;

    for (int i = 0; i < n; ++i) {
        cout << "Nhap xac suat ky tu thu " << i + 1 << ": ";
        cin >> probabilities[i];

        if (probabilities[i] > 0)
            entropy += -probabilities[i] * log2(probabilities[i]);
        else
            cout << "Xac suat phai lon hon 0!" << endl;
    }

    cout << "Entropy cua nguon tin la: " << entropy << " bits" << endl;
    return 0;
}

//bai 2
// int main() {
//     int n;
//     cout << "Nhap so ky tu: ";
//     cin >> n;

//     double p, entropy = 0.0;
//     for (int i = 0; i < n; ++i) {
//         cout << "Nhap xac suat ky tu thu " << i + 1 << ": ";
//         cin >> p;
//         if (p > 0) {
//             entropy += -p * log2(p);
//         }
//     }

//     cout << "Entropy cua nguon tin la: " << entropy << endl;
//     return 0;
// }

//bai 3
// bool isPrime(int n) {
//     if (n <= 1) return false;
//     for (int i = 2; i * i <= n; ++i)
//         if (n % i == 0) return false;
//     return true;
// }

// int main() {
//     int num;
//     cout << "Nhap so nguyen: ";
//     cin >> num;

//     if (isPrime(num))
//         cout << num << " la so nguyen to.\n";
//     else
//         cout << num << " khong la so nguyen to.\n";

//     return 0;
// }

//bai 4
// int gcd(int a, int b) {
//     while (b != 0) {
//         int r = a % b;
//         a = b;
//         b = r;
//     }
//     return a;
// }

// int main() {
//     int a, b;
//     cout << "Nhap hai so nguyen: ";
//     cin >> a >> b;

//     cout << "GCD la: " << gcd(a, b) << endl;
//     return 0;
// }

//bai 5
// int extendedGCD(int a, int b, int &x, int &y) {
//     if (b == 0) {
//         x = 1; y = 0;
//         return a;
//     }
//     int x1, y1;
//     int d = extendedGCD(b, a % b, x1, y1);
//     x = y1;
//     y = x1 - (a / b) * y1;
//     return d;
// }

// int modInverse(int a, int m) {
//     int x, y;
//     int g = extendedGCD(a, m, x, y);
//     if (g != 1) {
//         cout << "Khong co nghich dao modulo (a va m khong nguyen to cung nhau).\n";
//         return -1;
//     } else {
//         return (x % m + m) % m; // Đảm bảo kết quả dương
//     }
// }

// int main() {
//     int a, m;
//     cout << "Nhap a va modulo m: ";
//     cin >> a >> m;

//     int inverse = modInverse(a, m);
//     if (inverse != -1)
//         cout << "Nghich dao modulo la: " << inverse << endl;

//     return 0;
// }
