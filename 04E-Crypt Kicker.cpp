#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

vector<string> dictionary;  // Lista de palabras del diccionario

// Función que intenta descifrar la línea cifrada usando backtracking
bool decrypt_line(const vector<string>& encrypted_words, unordered_map<char, char>& cipher_to_plain, unordered_map<char, char>& plain_to_cipher, int word_index, vector<string>& result) {
    if (word_index == encrypted_words.size()) {
        // Todas las palabras se han descifrado con éxito
        return true;
    }

    string encrypted_word = encrypted_words[word_index];
    int len = encrypted_word.length();

    // Intentar mapear la palabra cifrada con una palabra del diccionario de la misma longitud
    for (const string& candidate : dictionary) {
        if (candidate.length() != len) continue;  // Saltar si la longitud no coincide

        // Crear una copia temporal del mapeo actual
        unordered_map<char, char> temp_cipher_to_plain = cipher_to_plain;
        unordered_map<char, char> temp_plain_to_cipher = plain_to_cipher;
        bool valid_mapping = true;

        // Intentar asignar cada letra de la palabra cifrada a la palabra candidata
        for (int i = 0; i < len; ++i) {
            char cipher_char = encrypted_word[i];
            char plain_char = candidate[i];

            if (temp_cipher_to_plain.count(cipher_char)) {
                // Ya hay un mapeo para esta letra cifrada
                if (temp_cipher_to_plain[cipher_char] != plain_char) {
                    valid_mapping = false;
                    break;
                }
            } else if (temp_plain_to_cipher.count(plain_char)) {
                // Esta letra real ya está mapeada a otra letra cifrada
                if (temp_plain_to_cipher[plain_char] != cipher_char) {
                    valid_mapping = false;
                    break;
                }
            } else {
                // Establecer un nuevo mapeo
                temp_cipher_to_plain[cipher_char] = plain_char;
                temp_plain_to_cipher[plain_char] = cipher_char;
            }
        }

        if (valid_mapping) {
            result.push_back(candidate);
            if (decrypt_line(encrypted_words, temp_cipher_to_plain, temp_plain_to_cipher, word_index + 1, result)) {
                return true;
            }
            result.pop_back();  // Retroceder si no funciona
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    dictionary.resize(n);

    // Leer el diccionario de palabras
    for (int i = 0; i < n; ++i) {
        cin >> dictionary[i];
    }

    cin.ignore();  // Ignorar la línea en blanco antes de las líneas cifradas

    string encrypted_line;
    while (getline(cin, encrypted_line)) {
        stringstream ss(encrypted_line);
        string word;
        vector<string> encrypted_words;

        // Leer cada palabra cifrada
        while (ss >> word) {
            encrypted_words.push_back(word);
        }

        unordered_map<char, char> cipher_to_plain;
        unordered_map<char, char> plain_to_cipher;
        vector<string> result;

        if (decrypt_line(encrypted_words, cipher_to_plain, plain_to_cipher, 0, result)) {
            // Si se descifra correctamente, imprimimos la línea descifrada
            for (int i = 0; i < result.size(); ++i) {
                if (i > 0) cout << " ";
                cout << result[i];
            }
            cout << endl;
        } else {
            // Si no se encuentra una solución, imprimimos una línea de asteriscos
            for (char c : encrypted_line) {
                if (c == ' ') cout << ' ';
                else cout << '*';
            }
            cout << endl;
        }
    }

    return 0;
}
