#include "functions.h"

using namespace std;


int main() {
//
//            лаб #3, задание 8, "Найти максимальный элемент в массиве", рекурсивный способ
//
//
    while(true) {
        time_t now = time(nullptr);
        unsigned seed = now;
        srand(seed);


        int *array;
        int arraySize = 0;

        int n_answer;
        char answer;


        cout << "\nВведите размер массива: ";
        while (arraySize == 0) {
            if (cin >> arraySize) {
                if (arraySize > 0)
                    array = new int[arraySize];
                else {
                    cout << "Введите натуральное число: ";
                    arraySize = 0;
                }
            }
            else {
                cout << "Введите натуральное число: ";
            }
            cin.clear();
            fflush(stdin);
        }


        cout << endl << "Заполнить массив автоматически?" <<endl <<
                        "да  -  y" << endl <<
                        "нет -  любой другой символ" << endl <<
                        ">>> ";

        cin >> answer;
        fflush(stdin);


        if (answer == 'y') {
            auto_array_fulling(array, arraySize);
            cout << endl << "Полученный массив: ";
            array_print(array, arraySize);
        }
        else {
            array_fulling(array, arraySize);
            cout << endl << "Полученный массив: ";
            array_print(array, arraySize);
        }


        cout << endl << "Выполнить программу\n"
                         "1 - рекурсивным способом\n"
                         "2 - не рекурсивным\n"
                         ">>> ";


        bool isDone = false;
        while (!isDone) {
            if (cin >> n_answer) {
                switch (n_answer) {
                    case 1 :
                        cout << endl << "Максимальный элемент массива: " << find_max_rec(array, 0, arraySize - 1) << endl;
                        isDone = true;
                        break;
                    case 2 :
                        cout << endl << "Максимальный элемент массива: " << find_max_not_rec(array, arraySize) << endl;
                        isDone = true;
                        break;
                    default:
                        cout << "Введено неправильное значение: " << n_answer << endl;
                        cout << "[1/2] >>> ";
                        break;
                }
            }
            else {
                cout << "Введено неправильное значение: строка" << endl;
                cout << "[1/2] >>> ";
            }
            cin.clear();
            fflush(stdin);
        }

        cout << "---------------------------------" << endl;


        cout << endl << "Желаете повторить?  y/n" << endl;
        cout << ">>> ";

        cin >> answer;
        cin.clear();
        fflush(stdin);

        if (answer != 'y')
            break;
    }
    return 0;
}