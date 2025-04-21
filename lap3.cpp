#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

//bai 1
// string alphabet_en = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// string alphabet_vi = "AĂÂBCDĐEÊGHIKLMNOÔƠPQRSTUƯVXY";

// string shift_alphabet(const string &alphabet, int k) {
//     int n = alphabet.length();
//     string shifted = "";
//     for (int i = 0; i < n; ++i) {
//         shifted += alphabet[(i + k) % n];
//     }
//     return shifted;
// }

// string substitute(const string &text, const string &alphabet, const string &shifted, bool encrypt = true) {
//     string result = "";
//     for (char c : text) {
//         char upper = toupper(c);
//         size_t pos = alphabet.find(upper);
//         if (pos != string::npos) {
//             char newChar = encrypt ? shifted[pos] : alphabet[shifted.find(upper)];
//             result += islower(c) ? tolower(newChar) : newChar;
//         } else {
//             result += c; // ký tự không mã hóa (dấu cách, số, dấu câu...)
//         }
//     }
//     return result;
// }

// int main() {
//     int choice;
//     int key;
//     string input, result;
//     string alphabet;

//     cout << "===== CHUONG TRINH MA HOA THAY THE =====\n";
//     cout << "1. Chon bang ma tieng Anh\n";
//     cout << "2. Chon bang ma tieng Viet (khong dau)\n";
//     cout << "Chon bang ma: ";
//     cin >> choice;
//     cin.ignore();

//     if (choice == 1)
//         alphabet = alphabet_en;
//     else if (choice == 2)
//         alphabet = alphabet_vi;
//     else {
//         cout << "Lua chon khong hop le.\n";
//         return 1;
//     }

//     cout << "Nhap khoa K (so nguyen): ";
//     cin >> key;
//     cin.ignore();

//     string shifted_alphabet = shift_alphabet(alphabet, key);

//     cout << "\n1. Ma hoa\n";
//     cout << "2. Giai ma\n";
//     cout << "Chon chuc nang: ";
//     cin >> choice;
//     cin.ignore();

//     cout << "Nhap xau van ban: ";
//     getline(cin, input);

//     if (choice == 1)
//         result = substitute(input, alphabet, shifted_alphabet, true);
//     else if (choice == 2)
//         result = substitute(input, alphabet, shifted_alphabet, false);
//     else {
//         cout << "Lua chon khong hop le.\n";
//         return 1;
//     }

//     cout << "Ket qua: " << result << endl;
//     return 0;
// }

//bai 2
// int main() {
//     string text;
//     int n;

//     cout << "Nhap chuoi van ban (khong dau): ";
//     getline(cin, text);
//     n = text.length();

//     vector<int> key(n);
//     cout << "Nhap khoa hoan vi (vi du: ";
//     for (int i = 0; i < n; ++i) cout << i + 1 << " ";
//     cout << ")\n";

//     for (int i = 0; i < n; ++i) {
//         cout << "Vi tri " << i + 1 << " <- vi tri: ";
//         cin >> key[i];
//         if (key[i] < 1 || key[i] > n) {
//             cout << "Vi tri khong hop le!\n";
//             return 1;
//         }
//     }

//     string encrypted(n, ' ');
//     for (int i = 0; i < n; ++i) {
//         encrypted[i] = text[key[i] - 1]; // -1 vì mảng bắt đầu từ 0
//     }

//     cout << "Chuoi da duoc ma hoa: " << encrypted << endl;
//     return 0;
// }

//bai 3
// vector<int> getKeywordOrder(const string &keyword) {
//     vector<pair<char, int>> chars;
//     for (int i = 0; i < keyword.size(); ++i)
//         chars.push_back({keyword[i], i});

//     sort(chars.begin(), chars.end());

//     vector<int> order(keyword.size());
//     for (int i = 0; i < keyword.size(); ++i)
//         order[i] = chars[i].second;

//     return order;
// }

// int main() {
//     string plaintext, keyword;
//     cout << "Nhap chuoi can ma hoa (khong dau, khong khoang trang): ";
//     getline(cin, plaintext);

//     cout << "Nhap tu khoa (keyword): ";
//     getline(cin, keyword);

//     int cols = keyword.size();
//     int rows = (plaintext.size() + cols - 1) / cols;

//     // Padding văn bản nếu cần
//     int total = rows * cols;
//     plaintext += string(total - plaintext.size(), '_'); // dùng '_' để padding

//     // Tạo ma trận hàng x cột
//     vector<vector<char>> matrix(rows, vector<char>(cols));
//     int index = 0;
//     for (int r = 0; r < rows; ++r)
//         for (int c = 0; c < cols; ++c)
//             matrix[r][c] = plaintext[index++];

//     // Lấy thứ tự cột dựa trên keyword
//     vector<int> order = getKeywordOrder(keyword);

//     // Đọc cột theo thứ tự từ khóa đã sắp xếp
//     string ciphertext = "";
//     for (int col_idx : order) {
//         for (int r = 0; r < rows; ++r)
//             ciphertext += matrix[r][col_idx];
//     }

//     cout << "Ban ma (ciphertext): " << ciphertext << endl;
//     return 0;
// }

//bai 4
// string xorEncryptDecrypt(const string &text, char key) {
//     string result = text;
//     for (size_t i = 0; i < text.length(); ++i) {
//         result[i] = text[i] ^ key;
//     }
//     return result;
// }

// int main() {
//     string plaintext;
//     char key;

//     cout << "Nhap chuoi van ban can ma hoa: ";
//     getline(cin, plaintext);

//     cout << "Nhap mot ky tu lam khoa: ";
//     cin >> key;

//     // Mã hóa
//     string encrypted = xorEncryptDecrypt(plaintext, key);
//     cout << "Chuoi da ma hoa (dang nhi phan): ";
//     for (char c : encrypted)
//         cout << std::hex << ((int)c & 0xFF) << ' ';
//     cout << endl;

//     // Giải mã
//     string decrypted = xorEncryptDecrypt(encrypted, key);
//     cout << "Chuoi giai ma: " << decrypted << endl;

//     return 0;
// }

//bai 5
// string blockXORCipher(const string &text, const string &key, int blockSize) {
//     string result = text;
//     int len = text.length();

//     // Padding nếu cần
//     int padding = (blockSize - (len % blockSize)) % blockSize;
//     result += string(padding, '_');

//     // Mã hóa từng khối
//     for (size_t i = 0; i < result.length(); i++) {
//         result[i] = result[i] ^ key[i % blockSize];
//     }

//     return result;
// }

// int main() {
//     string plaintext, key;
//     int blockSize;

//     cout << "Nhap chuoi van ban: ";
//     getline(cin, plaintext);

//     cout << "Nhap kich thuoc khoi: ";
//     cin >> blockSize;
//     cin.ignore(); // Xử lý ký tự '\n' còn lại

//     cout << "Nhap khoa (do dai bang kich thuoc khoi): ";
//     getline(cin, key);

//     if (key.length() != blockSize) {
//         cout << "Loi: Do dai khoa phai bang kich thuoc khoi!" << endl;
//         return 1;
//     }

//     // Mã hóa
//     string encrypted = blockXORCipher(plaintext, key, blockSize);

//     cout << "\nChuoi da ma hoa (dang hex): ";
//     for (char c : encrypted)
//         cout << hex << ((int)c & 0xFF) << ' ';
//     cout << "\n";

//     // Giải mã
//     string decrypted = blockXORCipher(encrypted, key, blockSize);
//     cout << "Chuoi da giai ma: " << decrypted << endl;

//     return 0;
// }

//bai 6
string xorBinary(const string &a, const string &b) {
    string result = "";
    for (size_t i = 0; i < a.size(); ++i) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

// Hàm sinh khóa con (subkeys) từ khóa chính bằng cách dịch vòng trái
vector<string> generateSubkeys(const string &key, int rounds) {
    vector<string> subkeys;
    string temp = key;
    for (int i = 0; i < rounds; ++i) {
        // Dịch vòng trái 1 bit
        temp = temp.substr(1) + temp[0];
        subkeys.push_back(temp.substr(0, key.size())); // có thể lấy đúng bằng độ dài khóa
    }
    return subkeys;
}

void feistelEncrypt(string plaintext, string key, int rounds) {
    cout << "\n=== MA HOA (ENCRYPTION) ===\n";
    int len = plaintext.size();
    string L = plaintext.substr(0, len / 2);
    string R = plaintext.substr(len / 2);

    vector<string> subkeys = generateSubkeys(key, rounds);

    for (int i = 0; i < rounds; ++i) {
        string Li = R;
        string Ri = xorBinary(L, xorBinary(R, subkeys[i])); // F(R, Ki) = R ⊕ Ki
        L = Li;
        R = Ri;

        cout << "Round " << i + 1 << ": L = " << L << ", R = " << R << endl;
    }

    string ciphertext = L + R;
    cout << "Ciphertext: " << ciphertext << endl;

    // Lưu kết quả cuối để dùng cho giải mã
    plaintext = ciphertext;

    // ==== GIẢI MÃ ====
    cout << "\n=== GIAI MA (DECRYPTION) ===\n";
    L = plaintext.substr(0, len / 2);
    R = plaintext.substr(len / 2);

    for (int i = rounds - 1; i >= 0; --i) {
        string Ri = L;
        string Li = xorBinary(R, xorBinary(L, subkeys[i]));
        R = Ri;
        L = Li;

        cout << "Round " << rounds - i << ": L = " << L << ", R = " << R << endl;
    }

    string decrypted = L + R;
    cout << "Decrypted text: " << decrypted << endl;
}

int main() {
    string plaintext, key;
    int rounds;

    cout << "Nhap chuoi nhi phan (so bit chan): ";
    cin >> plaintext;

    cout << "Nhap khoa (dang nhi phan): ";
    cin >> key;

    cout << "Nhap so vong Feistel: ";
    cin >> rounds;

    if (plaintext.length() % 2 != 0) {
        cout << "Loi: Chuoi nhap vao phai co so bit chan!" << endl;
        return 1;
    }

    feistelEncrypt(plaintext, key, rounds);

    return 0;
}