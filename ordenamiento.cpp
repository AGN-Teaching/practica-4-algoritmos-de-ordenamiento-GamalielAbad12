#include <iostream>
#include <fstream>
#include <functional>
#include <chrono>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void intercambiar(int A[], int x, int y) {
    int aux = A[x];
    A[x] = A[y];
    A[y] = aux;
}

void insertion_sort(int A[], int n) {
    for (int j = 1; j < n; j++) {
        int k = A[j];
        int i = j - 1;

        while (i >= 0 && A[i] > k) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = k;
    }
}

void selection_sort(int A[], int n) {
    for (int j = 0; j < n - 1; j++) {
        int menor = j;

        for (int i = j + 1; i < n; i++) {
            if (A[i] < A[menor]) {
                menor = i;
            }
        }
        intercambiar(A, j, menor);
    }
}

void bubblesort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; i < j; j--) {
            if (A[j] < A[j - 1]) {
                intercambiar(A, j, j - 1);
            }
        }
    }
}

void merge(int A[], int inicio, int medio, int fin) {
    int* aux = new int[fin - inicio + 1];
    int i = inicio;
    int j = medio + 1;
    int h = 0;

    while ((i <= medio) && (j <= fin)) {
        if (A[i] <= A[j]) {
            aux[h] = A[i];
            i += 1;
        } else {
            aux[h] = A[j];
            j += 1;
        }
        h += 1;
    }

    if (i > medio) {
        while (j <= fin) {
            aux[h] = A[j];
            j += 1;
            h += 1;
        }
    } else {
        while (i <= medio) {
            aux[h] = A[i];
            i += 1;
            h += 1;
        }
    }

    h = 0;
    for (int k = inicio; k <= fin; k++) {
        A[k] = aux[h];
        h += 1;
    }
    delete[] aux;
}

void merge_sort(int A[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        merge_sort(A, inicio, medio);
        merge_sort(A, medio + 1, fin);
        merge(A, inicio, medio, fin);
    }
}

int partition(int A[], int p, int r) {
    int pivote = A[r];
    int ultimo = p - 1;

    for (int i = p; i < r; i++) {
        if (A[i] < pivote) {
            ultimo += 1;
            intercambiar(A, ultimo, i);
        }
    }

    intercambiar(A, ultimo + 1, r);
    return ultimo + 1;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

duration<double> ejecutar_algoritmo(int A[], int n, std::function<void(int[], int)> algoritmo) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    algoritmo(A, n);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    return duration_cast<duration<double>>(fin - inicio);
}

void imprimir_tiempos(const string& algoritmo, int repeticion, double tiempo) {
    cout << algoritmo << "\tRepetición " << repeticion << "\t" << tiempo << "s\n";
}

void generar_y_ordenar_arreglos(int n, int m, const string& output_filename) {
    ofstream archivo_salida(output_filename);

   vector<double> tiempos_is;
    vector<double> tiempos_ss;
    vector<double> tiempos_bs;
    vector<double> tiempos_ms;
    vector<double> tiempos_qs;

    for (int i = 1; i <= m; i++) {
        int* Ai = new int[n];
        for (int j = 0; j < n; j++) {
            Ai[j] = rand() % (10 * n) + 1;
        }

        // Insertion Sort
        int* Bi_is = new int[n];
        copy(Ai, Ai + n, Bi_is);
        duration<double> tiempo_is = ejecutar_algoritmo(Bi_is, n, insertion_sort);
        tiempos_is.push_back(tiempo_is.count());
        imprimir_tiempos("Insertion Sort", i, tiempo_is.count());
        delete[] Bi_is;

        // Selection Sort
        int* Bi_ss = new int[n];
        copy(Ai, Ai + n, Bi_ss);
        duration<double> tiempo_ss = ejecutar_algoritmo(Bi_ss, n, selection_sort);
        tiempos_ss.push_back(tiempo_ss.count());
        imprimir_tiempos("Selection Sort", i, tiempo_ss.count());
        delete[] Bi_ss;

        // Bubblesort
        int* Bi_bs = new int[n];
        copy(Ai, Ai + n, Bi_bs);
        duration<double> tiempo_bs = ejecutar_algoritmo(Bi_bs, n, bubblesort);
        tiempos_bs.push_back(tiempo_bs.count());
        imprimir_tiempos("Bubblesort", i, tiempo_bs.count());
        delete[] Bi_bs;

        // Merge Sort
        int* Bi_ms = new int[n];
        copy(Ai, Ai + n, Bi_ms);
        duration<double> tiempo_ms = ejecutar_algoritmo(Bi_ms, n, [=](int A[], int size) { merge_sort(A, 0, size - 1); });
        tiempos_ms.push_back(tiempo_ms.count());
        imprimir_tiempos("Merge Sort", i, tiempo_ms.count());
        delete[] Bi_ms;

        // Quicksort
        int* Bi_qs = new int[n];
        copy(Ai, Ai + n, Bi_qs);
        duration<double> tiempo_qs = ejecutar_algoritmo(Bi_qs, n, [=](int A[], int size) { quicksort(A, 0, size - 1); });
        tiempos_qs.push_back(tiempo_qs.count());
        imprimir_tiempos("Quicksort", i, tiempo_qs.count());
        delete[] Bi_qs;

        delete[] Ai;
    }

    // Calcular promedio
    double promedio_is = accumulate(tiempos_is.begin(), tiempos_is.end(), 0.0) / tiempos_is.size();
    double promedio_ss = accumulate(tiempos_ss.begin(), tiempos_ss.end(), 0.0) / tiempos_ss.size();
    double promedio_bs = accumulate(tiempos_bs.begin(), tiempos_bs.end(), 0.0) / tiempos_bs.size();
    double promedio_ms = accumulate(tiempos_ms.begin(), tiempos_ms.end(), 0.0) / tiempos_ms.size();
    double promedio_qs = accumulate(tiempos_qs.begin(), tiempos_qs.end(), 0.0) / tiempos_qs.size();

    // Calcular desviación estándar
    double sum_sq_is = inner_product(tiempos_is.begin(), tiempos_is.end(), tiempos_is.begin(), 0.0);
    double desviacion_is = sqrt(sum_sq_is / tiempos_is.size() - promedio_is * promedio_is);

    double sum_sq_ss = inner_product(tiempos_ss.begin(), tiempos_ss.end(), tiempos_ss.begin(), 0.0);
    double desviacion_ss = sqrt(sum_sq_ss / tiempos_ss.size() - promedio_ss * promedio_ss);

    double sum_sq_bs = inner_product(tiempos_bs.begin(), tiempos_bs.end(), tiempos_bs.begin(), 0.0);
    double desviacion_bs = sqrt(sum_sq_bs / tiempos_bs.size() - promedio_bs * promedio_bs);

    double sum_sq_ms = inner_product(tiempos_ms.begin(), tiempos_ms.end(), tiempos_ms.begin(), 0.0);
    double desviacion_ms = sqrt(sum_sq_ms / tiempos_ms.size() - promedio_ms * promedio_ms);

    double sum_sq_qs = inner_product(tiempos_qs.begin(), tiempos_qs.end(), tiempos_qs.begin(), 0.0);
    double desviacion_qs = sqrt(sum_sq_qs / tiempos_qs.size() - promedio_qs * promedio_qs);

    // Imprimir resultados
    cout << "\nResultados Finales:\n";
    cout << "Algoritmo\tPromedio\tDesviación Estándar\n";
    cout << "Insertion Sort\t" << promedio_is << "s\t" << desviacion_is << "s\n";
    cout << "Selection Sort\t" << promedio_ss << "s\t" << desviacion_ss << "s\n";
    cout << "Bubblesort\t" << promedio_bs << "s\t" << desviacion_bs << "s\n";
    cout << "Merge Sort\t" << promedio_ms << "s\t" << desviacion_ms << "s\n";
    cout << "Quicksort\t" << promedio_qs << "s\t" << desviacion_qs << "s\n";

    archivo_salida << "\nResultados Finales:\n";
    archivo_salida << "Algoritmo\tPromedio\tDesviación Estándar\n";
    archivo_salida << "Insertion Sort\t" << promedio_is << "s\t" << desviacion_is << "s\n";
    archivo_salida << "Selection Sort\t" << promedio_ss << "s\t" << desviacion_ss << "s\n";
    archivo_salida << "Bubblesort\t" << promedio_bs << "s\t" << desviacion_bs << "s\n";
    archivo_salida << "Merge Sort\t" << promedio_ms << "s\t" << desviacion_ms << "s\n";
    archivo_salida << "Quicksort\t" << promedio_qs << "s\t" << desviacion_qs << "s\n";

    archivo_salida.close();
}

int main() {
    // Llama a tu función con los parámetros necesarios
    generar_y_ordenar_arreglos(500000, 3, "resultados.txt");

    return 0;
}
