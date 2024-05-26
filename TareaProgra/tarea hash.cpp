#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

struct TokenInfo {
    string token;
    pair<int, int> position;
};

// Función para dividir una cadena por espacios
vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Función para procesar el input y llenar la tabla hash
void processInput(const string &input, unordered_map<string, TokenInfo> &hashTable) {
    istringstream stream(input);
    string line;
    int row = 0;

    while (getline(stream, line)) {
        vector<string> tokens = split(line, ' ');
        int col = 0;
        for (const string &token : tokens) {
            if (!token.empty()) {
                string key = to_string(row) + "," + to_string(col);
                hashTable[key] = {token, {row, col}};
                col++;
            }
        }
        row++;
    }
}

// Función para imprimir la tabla hash
void printHashTable(const unordered_map<string, TokenInfo> &hashTable) {
    for (const auto &pair : hashTable) {
        cout << "Clave: " << pair.first << " -> Token: " << pair.second.token
             << " (Fila: " << pair.second.position.first
             << ", Columna: " << pair.second.position.second << ")" << endl;
    }
}

int main() {
    unordered_map<string, TokenInfo> hashTable;
    string multilineInput = "int suma = 0;\nsuma = 54 + 20;";
    processInput(multilineInput, hashTable);

    int choice;
    do {
        cout << "Bienvenido al programa de procesamiento de tokens en C++" << endl;
        cout << "Por favor elija una opción:" << endl;
        cout << "1. Visualizar tabla hash" << endl;
        cout << "2. Salir" << endl;
        cout << "Ingrese su elección: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Tabla Hash:" << endl;
                printHashTable(hashTable);
                break;
            case 2:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }
    } while (choice != 2);

    return 0;
}
