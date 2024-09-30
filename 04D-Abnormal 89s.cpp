#include <iostream>
#include <cstring>
#define MaxL 200005

using namespace std;

char A[MaxL], B[MaxL];
int P[MaxL];

// Función para construir la tabla KMP (prefijo-sufijo)
void KMPTable(char *pattern) {
    int patternLength = strlen(pattern);
    int i = 1, j = -1;
    P[0] = -1;
    
    while (i < patternLength) {
        // Ajustar j usando la tabla de prefijos
        while (j >= 0 && pattern[j + 1] != pattern[i])
            j = P[j];
        
        // Si hay coincidencia, incrementar j
        if (pattern[j + 1] == pattern[i])
            j++;
        
        P[i++] = j;
    }
}

// Función para buscar coincidencias usando el algoritmo KMP
int KMPMatching(char text[], char pattern[]) {
    KMPTable(pattern);
    
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int i = 0, j = -1;
    int matchPosition = -1;
    
    while (i + (patternLength - (j + 1)) <= textLength) {
        // Ajustar j usando la tabla de prefijos
        while (j >= 0 && pattern[j + 1] != text[i])
            j = P[j];
        
        // Si hay coincidencia, incrementar j
        if (pattern[j + 1] == text[i])
            j++;
        
        // Si se encuentra una coincidencia completa
        if (j == patternLength - 1) {
            int currentMatchPosition = i - patternLength + 1;
            
            // Si la posición de coincidencia no es el inicio
            if (currentMatchPosition != 0)
                return currentMatchPosition;
            
            matchPosition = 0;
            j = P[j];
        }
        
        i++;
    }
    
    return matchPosition;
}

// Función para verificar si una cadena es un palíndromo
bool isPalindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Función para resolver el problema dado
void Solve(char A[]) {
    int A_len = strlen(A);
    
    // Verificar si A se puede dividir en dos palíndromos
    for (int i = 1; i < A_len; i++) {
        if (isPalindrome(A, 0, i - 1) && isPalindrome(A, i, A_len - 1)) {
            cout << "alindrome" << endl;
            return;
        }
    }

    // Verificar si A ya es un palíndromo
    if (isPalindrome(A, 0, A_len - 1)) {
        cout << "palindrome" << endl;
        return;
    }
    
    cout << "simple" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> A;
        Solve(A);
    }
    return 0;
}
