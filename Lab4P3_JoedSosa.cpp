using namespace std;
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
// recibe la cadena y el caractares luego la recorre para ver cuantas letras hay en la cadena
int num_repeticiones(string cadena, char letra) {
    int cont = 0;
    for (int i = 0; i < cadena.length(); i++){
        if (cadena[i] == letra) {
            cont++;
        }
    }
    return cont;
}
// recibe la cadena de ADN ingresada por el ususario, recorre la cadena para luego ver cuantas veces existe esa letra
string sequence(string cadena) {
    string sequence;
    string largeseq;
    int cont = 1;
    int largecont = 1;
    for (int i = 0; i < cadena.length(); i++) {
        if (cadena[i] == cadena[i - 1]) {
            cont++;
            sequence += cadena[i];
        }
        else {
            if (cont > largecont) {
                largecont = cont;
                largeseq = sequence;
            }
            cont = 1;
            sequence = " ";
        }
    }
    return sequence;
}
    int fact(int num){
        if (num <= 1) {
            return 1;
        }
        else {
            return num * fact(num - 1);
        }
    }

    void Permutaciones() {
        string palabra;
        cout << "Ingrese palabra para calcular permutaciones: ";
        cin >> palabra;
        if (palabra.size() < 6) {
            cout << "La palabra debe tener al menos 6 caracteres. " << endl;
        }
        cout << "Letras que se repiten: " << endl;
        vector<bool> contletras(palabra.size(), false);
        for (int i = 0; i < palabra.size(); i++) {
            if (!contletras[i]) {
                int reps = num_repeticiones(palabra, palabra[i]);
                contletras[i] = true;
                if (reps > 1) {
                    cout << palabra[i] << ": " << reps << "veces" << endl;
                }
            }
        }
        int n = palabra.size();
        int* r = new int[palabra.size()];
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (!contletras[i]) {
                int reps = num_repeticiones(palabra, palabra[i]);
                contletras[i] = true;
                r[k] = reps;
                k++;
            }
        }
        int numerador = fact(n);
        int denominador = 1;
        for (int i = 0; i < k; i++){
            denominador *= fact(r[i]);
        }
        int permutaciones = numerador / denominador;
        cout << "Numero de permutaciones de la palabra " << palabra << ": " << permutaciones << endl;

    }
// Solicita toda la informacion necesaria al usuario para luego poner a prueba el ejercicio
void nucleotidos(){
    string cadena;
    cout << "Ingrese una cadena de ADN: ";
    cin >> cadena;

    int totalnucleo = cadena.length();
    cout << "\n Analisis de la cadena de ADN: " << endl;
    cout << "-Numero total de nucleotidos: " << totalnucleo << endl;

    int A = num_repeticiones(cadena, 'A');
    int C = num_repeticiones(cadena, 'C');
    int G = num_repeticiones(cadena, 'G');
    int T = num_repeticiones(cadena, 'T');
    
    cout << "-Numero de ocurrencias de cada nucleotido: " << endl;
    cout << "A: " << A << endl;
    cout << "C: " << C << endl;
    cout << "G: " << G << endl;
    cout << "T: " << T << endl;

    double porcentaje_A =(double) A / totalnucleo * 100.0;
    double porcentaje_C = (double)C / totalnucleo * 100.0;
    double porcentaje_G = (double)G / totalnucleo * 100.0;
    double porcentaje_T = (double)T / totalnucleo * 100.0;

    cout << "-Porcentaje de caa nucleotico: " << endl;
    cout << fixed << setprecision(2);
    cout << "A: " << porcentaje_A << "%" << endl;
    cout << "C: " << porcentaje_C << "%" << endl;
    cout << "G: " << porcentaje_G << "%" << endl;
    cout << "T: " << porcentaje_T << "%" << endl;

    int longseq = 1;
    int longlargeseq = 1;
    char nucle = cadena[0];
    char freqnucle = nucle;
    for (int i = 1; i < totalnucleo; i++) {
        if (cadena[i] == nucle) {
            longseq++;
            if (longseq > longlargeseq) {
                longlargeseq = longseq;
                freqnucle = nucle;
            }
        }
        else {
            nucle = cadena[i];
            longseq = 1;
        }
    }
    cout << "-Sequencia mas larga de nucleotidos consecutivos que se repiten: ";
        for (int i = 0; i < longlargeseq; i++){
            cout << freqnucle;
        }
    cout << endl;
    
}
int menu() {
    int opcion;

    
    cout << "Seleccione una opcion:\n";
    cout << "1. Ejercicio 1: Permutaciones con repeticion \n";
    cout << "2. Ejercicio 2: Analisis de ADN\n";
    
    
    cout << "Ingrese su opcion: ";
    cin >> opcion;

    while (opcion != 1 && opcion != 2) {
        cout << "Opcion invalida. Ingrese 1 o 2: ";
        cin >> opcion;
    }

    return opcion;
}

int main() {
    int opcion = menu();

    if (opcion == 1) {
        Permutaciones();
    }
    else {
        nucleotidos();
       
    }

    return 0;
}