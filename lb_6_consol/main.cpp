#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main() {
    while (true) {
        srand(time(NULL)); // для рандома

        int n, max_e, max_e_collum, max_e_line;
        char answer;

        cout << "Введите размерность матрицы: ";
        cin >> n;

        //int *matrix = new int[n * n];
        int **matrix;                   //-
        matrix = new int*[n];           //-
        for (int i=0;i<n;i++)           //-
            matrix[i] = new int[n];     //-
// 5x3



        cout << endl << "Заполнить матрицу автоматически?  y/n" << endl;
        cout << "n - ручной ввод" << endl;
        cout << ">>> ";
        cin >> answer;

        // авто / ручками //
        if (answer == 'y') {
            // запись матрицы авто ввод //
            cout << endl << "Полученная матрица: " << endl;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    matrix[i][j] = rand() % 100 - 50;//-
                    //matrix[j + i * n] = rand() % 100 - 50;
        } else {
            // запись матрицы ручной ввод //
            cout << "Введите  матрицу: " << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << i + 1 << " строка, " << j + 1 << " элемент >>> ";
                    //cin >> *(matrix + i * n + j);
                    cin >> matrix[i][j];//-
                }
                cout << endl;
            }
        }


        // поиск элемента с наибольшим по модулю значением //
        //max_e = matrix[0];
        max_e = matrix[0][0]; //-
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
//                 if (fabs(matrix[j + i * n]) > fabs(max_e)) {
//                    max_e = matrix[j + i * n];                 ----
//                    max_e_collum = j; // его коорды
//                    max_e_line = i;}
                if (fabs(matrix[i][j]) > fabs(max_e)) {  //-
                    max_e = matrix[i][j];                //-
                    max_e_collum = j; // его коорды      //-
                    max_e_line = i;                      //-
                }
            }
        }


        // вывод матрицы //
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //printf(" %3i", matrix[j + i * n]);
                printf(" %3i", matrix[i][j]);//-
            }
            cout << endl;
        }

        cout << endl;
        cout << "Максимальный по модулю элемент матрицы: " << max_e << "     (" << max_e_line + 1 << ","
             << max_e_collum + 1
             << ")" << endl << endl;

        // удаление строки //
        for (int i = max_e_line; i < n - 1; i++)
            for (int j = 0; j < n; j++)
                //matrix[i * n + j] = matrix[(i + 1) * n + j];
                matrix[i][j] = matrix[i+1][j];//-

        // удаление стобца //
        for (int i = 0; i < n; i++)
            for (int j = max_e_collum; j < n - 1; j++)
                //matrix[i * n + j] = matrix[i * n + j + 1];
                matrix[i][j] = matrix[i][j+1];//-

        // создание новой матрицы
        int **matrix_new;
        int new_n = n-1;
        matrix_new = new int*[new_n];
        for (int i=0;i<new_n;i++)
            matrix_new[i] = new int[new_n];

        // копирование старой матрицы в новую
        for (int i = 0; i < new_n; i++)
            for (int j = 0; j < new_n; j++)
                matrix_new[i][j] = matrix[i][j];

        // вывод новой матрицы //
        cout << "Новая матрица:" << endl;
        for (int i = 0; i < new_n; i++) {
            for (int j = 0; j < new_n; j++) {
                //printf(" %3i", matrix[j + i * n]);
                printf(" %3i", matrix_new[i][j]);
            }
            cout << endl;
        }
        int *x;
        x = matrix_new[1];
        matrix_new[1] = matrix_new[2];
        matrix_new[2] = x;
        //swap()
       //matrix_new[1], matrix_new[2] = matrix_new[2], matrix_new[1];

        cout << "Новая матрица:" << endl;
        for (int i = 0; i < new_n; i++) {
            for (int j = 0; j < new_n; j++) {
                //printf(" %3i", matrix[j + i * n]);
                printf(" %3i", matrix_new[i][j]);
            }
            cout << endl;
        }

        for (int i=0; i<n;i++)
            delete matrix[i];
        delete[] matrix;
        for (int i=0; i<new_n;i++)
            delete matrix_new[i];
        delete[] matrix_new;


        cout << endl << "Желаете повторить?  y/n" << endl;
        cout << ">>> ";
        cin >> answer;

        if (answer == 'y') continue;
        else break;
    }
    return 0;
}