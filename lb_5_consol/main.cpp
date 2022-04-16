#include <iostream>
#include <cmath>

using namespace std;


void array_fulling(int array[], int array_size);

void auto_array_fulling(int array[], int array_size);

int array_max(int array[], int array_size);


int main() {
    while (true) {
        int array_size, max, summary = 0;
        char answer;

        cout << endl << "Введите размер массива: ";
        cin >> array_size;

        int *array = new int[array_size];

        cout << endl << "Заполнить массив автоматически?  y/n" << endl;
        cout << "n - ручной ввод" << endl;
        cout << ">>> ";
        cin >> answer;

        if (answer == 'y') {
            auto_array_fulling(array, array_size);
            cout << "Полученный массив: [";
            for (int i = 0; i < array_size; i++)
                cout << "  " << array[i];
            cout << "  ]" << endl;
        } else
            array_fulling(array, array_size);

        max = array_max(array, array_size);

        cout << endl << "Элементы удовлетворяющие условию:";

        int i = 0;
        while (array[i] != max) {
            if (array[i] > 0) {
                summary += array[i];
                cout << " " << array[i];
            }
            i++;
        }

        cout << ";   при max=" << max << endl;
        cout << "(все положительные элементы массива расположенные до максимального)" << endl << endl;
        cout << "Результат сложения: " << summary << endl;

        delete[] array;

        cout << endl << "---------------------------------------------------------" << endl;

        cout << endl << "Желаете повторить?  y/n" << endl;
        cout << ">>> ";
        cin >> answer;

        if (answer == 'y') continue;
        else break;
    }
    return 0;
}


void array_fulling(int array[], int array_size) {
    cout << endl << "Заполните массив элементами: " << endl;
    for (int i = 0; i < array_size; i++) {
        cout << "Введите " << i + 1 << " элемент массива >>> ";
        cin >> array[i];
    }
}


int array_max(int array[], int array_size) {
    int max = array[0];

    for (int i = 0; i < array_size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}


void auto_array_fulling(int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        array[i] = -50 + random()%100;
    }
}