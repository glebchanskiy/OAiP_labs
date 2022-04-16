#include <iostream>

using namespace std;

int counter=0;
struct Stack {
    int info;
    Stack *next;

} *firstElement;


void menu();

void push(int);

int pop();

int peek();

void delete_stack();

void view();

void delete_odd_element();

void fulling();

void sort_ptr();

void sort_info();


int main() {

    int answer;

    while (true) {
        unsigned seed = time(nullptr);
        srand(seed);

        menu();
        cout << ">>> ";
        cin >> answer;

        switch (answer) {
            case 1 :
                cout << ">>> ";
                cin >> answer;
                push(answer);
                break;

            case 2 :
                cout << "Элемент " << pop() << " был извлечен из стека." << endl;
                break;

            case 3 :
                cout << "Элемент - " <<  peek() << " первый в стеке." << endl;
                break;

            case 4 :
                delete_odd_element();
                cout << "Все нечетные элементы удалены. " << endl;
                break;

            case 5 :
                cout << "Элементы стека:" << endl;
                view();
                break;

            case 6 :
                delete_stack();
                cout << "Стек удален." << endl;
                break;

            case 7 :
                fulling();
                break;

            case 8 :
                sort_ptr();
                break;

            case 9 :
                sort_info();
                break;

            default:
                delete_stack();
                return 0;

        }
    }
}


void menu() {
    cout << endl;
    cout << "1 - добавить элемент (push)" << endl;
    cout << "2 - взять первый элемент (pop)" << endl;
    cout << "3 - вывести первый элемент (peek)" << endl;
    cout << "4 - удалить нечетные элементы" << endl;
    cout << "5 - вывести стек" << endl;
    cout << "6 - удалить стек" << endl;
    cout << "7 - добавить в стек случайные значениями" << endl;
    cout << "8 - сортировка перестановкой адресов" << endl;
    cout << "9 - сортировка обменом информации" << endl;
    cout << "0 - exit" << endl;
    cout << endl;
}


void push(int data) {
    auto *current = new Stack;

    current -> info = data;

    if (counter == 0)
        current -> next = nullptr;
    else
        current -> next = firstElement;

    firstElement = current;
    counter++;

}


int pop() {
    if (firstElement != nullptr) {
        Stack *secondElement = firstElement->next;
        int data = firstElement->info;

        delete firstElement;

        firstElement = secondElement;
        counter--;

        return data;
    }
    throw std::runtime_error("Попытка извлечь элемент из нулевого стека");
}


int peek() {
    if (firstElement != nullptr)
        return firstElement -> info;
    else
        throw std::runtime_error("Попытка вывести информацию из нулевого стека");

}


void delete_stack() {
    while (firstElement != nullptr) {
        Stack *temp = firstElement;
        firstElement = firstElement -> next;
        delete temp;
    }
}

void view() {
    if (firstElement != nullptr) {
        Stack *current = firstElement;

        while (current != nullptr) {
            printf("%10i\n", current->info);
            current = current->next;
        }
    }
    else {
        cout << "Стек пуст" << endl;
    }
}


void delete_odd_element() {
    if (firstElement != nullptr) {
        push(0);
        Stack *current = firstElement;

        while (current->next != nullptr) {
            if (current->next->info % 2 != 0) {
                Stack *temp = current->next->next;
                delete current->next;
                current->next = temp;
            }
            else
                current = current->next;
        }
        pop();
    }
    else {
        cout << "Стек пуст" << endl;
    }
}


void fulling() {
    int n;
    cout << "Введите сколько элементов добавить:\n>>> ";
    cin >> n;

    for (int i = 0; i < n; i++){
        push((int)random()%20);
    }
}


void sort_ptr() {
    if (firstElement != nullptr) {

        push(0);
        Stack *current = firstElement;
        Stack *null_ptr = nullptr;
        Stack *it, *temp;

        while (current->next->next != null_ptr) {
            for (it = current; it->next->next != null_ptr; it = it->next) {
                if (it->next->info > it->next->next->info) {
                    temp = it->next->next;
                    it->next->next = temp->next;
                    temp->next = it->next;
                    it->next = temp;
                }
            }
            null_ptr = it->next;
        }
        pop();
    }
    else {
        cout << "Стек пуст" << endl;
    }

}

void sort_info() {
    if (firstElement != nullptr) {

        push(0);
        Stack *current = firstElement;
        Stack *null_ptr = nullptr;
        Stack *it;
        int temp;

        while (current->next != null_ptr) {
            for (it = current; it->next != null_ptr; it = it->next) {
                if (it->info > it->next->info) {
                    temp = it->info;
                    it->info = it->next->info;
                    it->next->info = temp;
                }

            }
            null_ptr = it;
        }
        pop();
    }
    else {
        cout << "Стек пуст" << endl;
    }
}