#include <iostream>
#include <fstream>
#include <string>

struct Address {
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;
};


void sort(Address* addresses, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (addresses[j].city > addresses[j + 1].city) {
               
                Address temp = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = temp;
            }
        }
    }
}

int main() {
    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }
    int N;
    inputFile >> N; 
    inputFile.ignore();
    Address* addresses = new Address[N]; 
    for (int i = 0; i < N; ++i) {
        std::getline(inputFile, addresses[i].city);
        std::getline(inputFile, addresses[i].street);
        inputFile >> addresses[i].houseNumber;
        inputFile >> addresses[i].apartmentNumber;
        inputFile.ignore(); 
    }
    sort(addresses, N);
    
    outputFile << N << std::endl;

    for (int i = 0; i < N; ++i) {
        outputFile << addresses[i].city << ", "
            << addresses[i].street << ", "
            << addresses[i].houseNumber << ", "
            << addresses[i].apartmentNumber << std::endl;
    }

    delete[] addresses; 
    inputFile.close();
    outputFile.close();
    return 0;
}