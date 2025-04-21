#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <sstream>
#include <vector>
#include "des.h" 
using namespace std;

// //bai 1
// Hàm XOR 2 chuỗi nhị phân
// string xorBinary(const string& a, const string& b) {
//     string result = "";
//     for (size_t i = 0; i < a.length(); ++i)
//         result += (a[i] == b[i]) ? '0' : '1';
//     return result;
// }

// // Tiny DES - Feistel Round (4 rounds)
// string tinyDES_encrypt(string data, const string& key, int rounds = 4) {
//     string L = data.substr(0, 4);
//     string R = data.substr(4, 4);

//     for (int i = 0; i < rounds; ++i) {
//         string temp = R;
//         R = xorBinary(L, xorBinary(R, key)); // F(R, K) = R ⊕ K
//         L = temp;
//         cout << "Round " << i + 1 << ": L = " << L << ", R = " << R << endl;
//     }
//     return L + R;
// }

// string tinyDES_decrypt(string data, const string& key, int rounds = 4) {
//     string L = data.substr(0, 4);
//     string R = data.substr(4, 4);

//     for (int i = 0; i < rounds; ++i) {
//         string temp = L;
//         L = xorBinary(R, xorBinary(L, key));
//         R = temp;
//         cout << "Round " << i + 1 << ": L = " << L << ", R = " << R << endl;
//     }
//     return L + R;
// }

// int main() {
//     string plaintext, key;

//     cout << "Nhap chuoi nhi phan 8 bit: ";
//     cin >> plaintext;

//     cout << "Nhap khoa nhi phan 8 bit: ";
//     cin >> key;

//     if (plaintext.length() != 8 || key.length() != 8) {
//         cout << "Loi: Chuoi va khoa phai co do dai 8 bit!" << endl;
//         return 1;
//     }

//     cout << "\n--- Ma hoa Tiny DES ---" << endl;
//     string ciphertext = tinyDES_encrypt(plaintext, key);
//     cout << "Ban ma: " << ciphertext << endl;

//     cout << "\n--- Giai ma Tiny DES ---" << endl;
//     string decrypted = tinyDES_decrypt(ciphertext, key);
//     cout << "Ban goc: " << decrypted << endl;

//     return 0;
// }

// //bai 2
// Định nghĩa các bảng hoán vị và ánh xạ trong DES
// const int IP[64] = {58, 50, 42, 34, 26, 18, 10, 2,
//     60, 52, 44, 36, 28, 20, 12, 4,
//     62, 54, 46, 38, 30, 22, 14, 6,
//     64, 56, 48, 40, 32, 24, 16, 8,
//     57, 49, 41, 33, 25, 17, 9, 1,
//     59, 51, 43, 35, 27, 19, 11, 3,
//     61, 53, 45, 37, 29, 21, 13, 5,
//     63, 55, 47, 39, 31, 23, 15, 7};

// const int FP[64] = {40, 8, 48, 16, 56, 24, 64, 32,
//     39, 7, 47, 15, 55, 23, 63, 31,
//     38, 6, 46, 14, 54, 22, 62, 30,
//     37, 5, 45, 13, 53, 21, 61, 29,
//     36, 4, 44, 12, 52, 20, 60, 28,
//     35, 3, 43, 11, 51, 19, 59, 27,
//     34, 2, 42, 10, 50, 18, 58, 26,
//     33, 1, 41, 9, 49, 17, 57, 25};

// const int E[48] = {32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9,
//    8, 9, 10, 11, 12, 13, 12, 13, 14, 15,
//    16, 17, 16, 17, 18, 19, 20, 21, 20, 21,
//    22, 23, 24, 25, 24, 25, 26, 27, 28, 29,
//    28, 29, 30, 31, 32, 1};

// const int P[32] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26,
//    5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9,
//    19, 13, 30, 6, 22, 11, 4, 25};

// const int PC1[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3,
//      60, 52, 44, 36, 28, 20, 12, 4, 61, 53, 45, 37, 29, 21, 13, 5, 62, 54, 46, 38, 30, 22, 14, 6,
//      63, 55, 47, 39, 31, 23, 15, 7};

// const int PC2[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
//      41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

// const int SHIFT[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2};

// // Hàm hoán vị chuỗi nhị phân theo bảng
// bitset<64> permute(const bitset<64>& input, const int* table, int table_size) {
// bitset<64> output;
// for (int i = 0; i < table_size; i++) {
// output[i] = input[table[i] - 1];
// }
// return output;
// }

// // Hàm chia khóa chính thành 16 khóa con
// vector<bitset<48>> generateKeys(const bitset<56>& key) {
// vector<bitset<48>> keys(16);
// bitset<56> permuted_key = permute(key, PC1, 56);
// bitset<28> left = permuted_key.to_ulong() >> 28;
// bitset<28> right = permuted_key.to_ulong();

// for (int round = 0; round < 16; round++) {
// left = left << SHIFT[round];
// right = right << SHIFT[round];

// bitset<56> combined = (left.to_ulong() << 28) | right.to_ulong();
// keys[round] = permute(combined, PC2, 48);
// }
// return keys;
// }

// // Hàm mã hóa DES
// bitset<64> desEncrypt(const bitset<64>& input, const bitset<56>& key) {
// vector<bitset<48>> roundKeys = generateKeys(key);

// bitset<64> data = permute(input, IP, 64);
// bitset<32> left = data.to_ulong() >> 32;
// bitset<32> right = data.to_ulong();

// for (int round = 0; round < 16; round++) {
// bitset<32> temp = left;
// left = right;
// right = temp ^ roundKeys[round];
// }

// bitset<64> result = (left.to_ulong() << 32) | right.to_ulong();
// return permute(result, FP, 64);
// }

// int main() {
// string inputText = "12345678"; // Chuỗi dữ liệu cần mã hóa
// string keyText = "ABCDEFGH";  // Khóa DES

// bitset<64> input(inputText);
// bitset<56> key(keyText);

// bitset<64> ciphertext = desEncrypt(input, key);

// cout << "Ciphertext: " << ciphertext << endl;

// return 0;
// }

//bai 3
// #pragma comment(lib, "ws2_32.lib")

// // Định nghĩa các hàm mã hóa và giải mã DES từ phần trước
// bitset<64> desEncrypt(const bitset<64>& input, const bitset<56>& key);
// bitset<64> desDecrypt(const bitset<64>& input, const bitset<56>& key);

// // Hàm mã hóa và giải mã tin nhắn
// string encryptMessage(const string& message, const string& key) {
//     bitset<64> messageBitset(message);
//     bitset<56> keyBitset(key);
//     return desEncrypt(messageBitset, keyBitset).to_string();
// }

// string decryptMessage(const string& cipher, const string& key) {
//     bitset<64> cipherBitset(cipher);
//     bitset<56> keyBitset(key);
//     return desDecrypt(cipherBitset, keyBitset).to_string();
// }

// int main() {
//     // Khởi tạo socket
//     WSADATA wsa;
//     SOCKET server_socket, client_socket;
//     sockaddr_in server_addr, client_addr;
//     int client_len = sizeof(client_addr);

//     WSAStartup(MAKEWORD(2, 2), &wsa);

//     // Tạo socket server
//     server_socket = socket(AF_INET, SOCK_STREAM, 0);
//     if (server_socket == INVALID_SOCKET) {
//         cout << "Socket creation failed!" << endl;
//         return 1;
//     }

//     server_addr.sin_family = AF_INET;
//     server_addr.sin_port = htons(8080);
//     server_addr.sin_addr.s_addr = INADDR_ANY;

//     // Liên kết socket với địa chỉ IP và port
//     if (bind(server_socket, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
//         cout << "Bind failed!" << endl;
//         return 1;
//     }

//     // Lắng nghe kết nối
//     listen(server_socket, 3);

//     cout << "Server is waiting for incoming connections..." << endl;

//     // Chấp nhận kết nối từ client
//     client_socket = accept(server_socket, (sockaddr*)&client_addr, &client_len);
//     if (client_socket == INVALID_SOCKET) {
//         cout << "Client connection failed!" << endl;
//         return 1;
//     }

//     cout << "Client connected." << endl;

//     // Nhận và gửi tin nhắn
//     char buffer[1024];
//     string client_message, server_response;
//     string key = "ABCDEFGH";  // Định nghĩa khóa cho mã hóa DES

//     while (true) {
//         memset(buffer, 0, sizeof(buffer));
//         int recv_size = recv(client_socket, buffer, sizeof(buffer), 0);
//         if (recv_size == SOCKET_ERROR) {
//             cout << "Failed to receive message from client!" << endl;
//             break;
//         }

//         client_message = string(buffer);

//         cout << "Client: " << client_message << endl;

//         // Mã hóa tin nhắn từ client
//         server_response = encryptMessage(client_message, key);

//         // Gửi phản hồi (tin nhắn mã hóa) đến client
//         send(client_socket, server_response.c_str(), server_response.size(), 0);

//         // Nếu nhận được "bye", kết thúc kết nối
//         if (client_message == "bye") {
//             break;
//         }
//     }

//     // Đóng kết nối
//     closesocket(client_socket);
//     closesocket(server_socket);
//     WSACleanup();

//     return 0;
// }

//bai 4
// string readFile(const string& filename) {
//     ifstream file(filename, ios::in | ios::binary);
//     if (!file) {
//         cerr << "File not found!" << endl;
//         exit(1);
//     }
    
//     stringstream buffer;
//     buffer << file.rdbuf();
//     return buffer.str();
// }

// // Ghi dữ liệu vào file
// void writeFile(const string& filename, const string& data) {
//     ofstream file(filename, ios::out | ios::binary);
//     if (!file) {
//         cerr << "Unable to open file!" << endl;
//         exit(1);
//     }
//     file.write(data.c_str(), data.size());
//     file.close();
// }

// // Hàm mã hóa DES
// string encryptFileData(const string& inputData, const string& key) {
//     string encryptedData;
//     bitset<56> keyBitset(key);
    
//     // Chia nhỏ inputData thành các khối 64-bit và mã hóa
//     for (size_t i = 0; i < inputData.size(); i += 8) {
//         bitset<64> dataBlock;
//         for (size_t j = 0; j < 8 && i + j < inputData.size(); ++j) {
//             dataBlock[j * 8] = inputData[i + j];
//         }
//         encryptedData += desEncrypt(dataBlock, keyBitset).to_string();
//     }
//     return encryptedData;
// }

// // Hàm giải mã DES
// string decryptFileData(const string& encryptedData, const string& key) {
//     string decryptedData;
//     bitset<56> keyBitset(key);
    
//     // Chia nhỏ encryptedData thành các khối 64-bit và giải mã
//     for (size_t i = 0; i < encryptedData.size(); i += 64) {
//         bitset<64> encryptedBlock(encryptedData.substr(i, 64));
//         decryptedData += desDecrypt(encryptedBlock, keyBitset).to_string();
//     }
//     return decryptedData;
// }

// int main() {
//     string filename = "input.txt";   // Tên file đầu vào chứa dữ liệu
//     string encryptedFilename = "encrypted.txt";  // Tên file chứa dữ liệu mã hóa
//     string decryptedFilename = "decrypted.txt";  // Tên file chứa dữ liệu giải mã
//     string key = "ABCDEFGH";   // Khóa DES (8-bit)

//     // Đọc nội dung từ file
//     string inputData = readFile(filename);
//     cout << "Original Data: " << inputData << endl;

//     // Mã hóa dữ liệu từ file và ghi vào file mã hóa
//     string encryptedData = encryptFileData(inputData, key);
//     writeFile(encryptedFilename, encryptedData);
//     cout << "Data encrypted and written to file: " << encryptedFilename << endl;

//     // Đọc dữ liệu mã hóa từ file
//     string encryptedFileData = readFile(encryptedFilename);
//     cout << "Encrypted Data: " << encryptedFileData << endl;

//     // Giải mã dữ liệu từ file
//     string decryptedData = decryptFileData(encryptedFileData, key);
//     writeFile(decryptedFilename, decryptedData);
//     cout << "Data decrypted and written to file: " << decryptedFilename << endl;

//     return 0;
// }