#include <iostream>


int find_max_rec(int array[], int l, int r) {
    if (l == r)
        return array[r];

    int left = find_max_rec(array, l, (l+r)/2);
    int right = find_max_rec(array, (l+r)/2 + 1, r);

    return (left > right) ? left : right;
}


int find_max_not_rec(const int array[], int arraySize) {
    int max = array[0];

    for (int i = 0; i < arraySize; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}


void array_fulling(int array[], int arraySize) {
    std::cout << std::endl << "Заполните массив элементами" << "[" << arraySize << "]:" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Введите " << i + 1 << " элемент массива >>> ";
        std::cin >> array[i];
    }
}


void auto_array_fulling(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        array[i] = (int)rand()%100 - 50;
    }
}


void array_print(const int array[], int arraySize) {
    std::cout << "{";
    for (int i = 0; i < arraySize; i++){

        if (i == arraySize - 1) {
            std::cout << array[i];
        }
        else {
            std::cout << array[i] << ", ";
        }
    }
    std::cout << "}" << std::endl;
}
