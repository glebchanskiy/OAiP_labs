#include <iostream>

using namespace std;


int counter=0;
struct Stack {
    int info;
    Stack *next, *prev;

} *firstElement, *endElement;


void menu();

void push_front(int);

void push_back(int);

int getSize();

void del(int);

void print_front();

void print_back();

void delAll();

void fulling();

void odd_element();

void delete_odd_element();


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
                push_front(answer);
                break;

            case 2 :
                cout << ">>> ";
                cin >> answer;
                push_back(answer);
                break;

            case 3 :
                cout << "Размер списка =  " <<  getSize() << " элементов." << endl;
                break;

            case 4 :
                cout << "Елементы списка (обратный порядок):" << endl;
                print_back();
                break;

            case 5 :
                cout << "Елементы списка:" << endl;
                print_front();
                break;

            case 6 :
                delAll();
                cout << "Список удален." << endl;
                break;

            case 7 :
                fulling();
                cout << "Выполнено" << endl;
                break;

            case 8 :
                delete_odd_element();
                cout << "Выполнено" << endl;
                break;

            case 9 :
                del(0);
                cout << "Выполнено" << endl;
                break;

            default:
                delAll();
                return 0;

        }
    }
}


void menu() {
    cout << endl;
    cout << "1 - добавить элемент в начало списка (push_front)" << endl;
    cout << "2 - добавить элемент в конец списка (push_back)" << endl;
    cout << "3 - размер списка" << endl;
    cout << "4 - вывести список в обратном порядке" << endl;
    cout << "5 - вывести список" << endl;
    cout << "6 - удалить список" << endl;
    cout << "7 - добавить в стек случайные значениями" << endl;
    cout << "8 - удалить из списка все нечетные значения" << endl;
    cout << "9 - удалить элемент из списка" << endl;
    cout << "0 - exit" << endl;
    cout << endl;
}


void push_front(int info)  {
    auto *current = new Stack;
    current -> prev = nullptr;
    current -> info = info;
    current -> next = firstElement;

    if (firstElement != nullptr)
        firstElement->prev = current;

    if (counter == 0)
        firstElement = endElement = current;
    else
        firstElement = current;

    counter++;
}


void push_back(int info)  {
    auto * current = new Stack;
    current->next = nullptr;
    current->info = info;
    current->prev = endElement;

    if(endElement != nullptr)
        endElement->next = current;

    if(counter == 0)
        firstElement = endElement = current;
    else
        endElement = current;

    counter++;
}


int getSize() {
    return counter;
}


void print_back() {
    Stack *current = endElement;

    if(current != nullptr) {
        cout << "Элементы списка: " << endl << ">>>   ";

        while (current != nullptr) {
            if (current -> prev == nullptr)
                cout << current -> info << endl;
            else
                cout << current -> info << " <-> ";

            current = current ->prev;
        }
    }
    else {
        cout << "Список пуст." << endl;
    }
}


void print_front() {
    Stack *current = firstElement;

    if(current != nullptr) {
        cout << "Элементы списк: " << endl << ">>>   ";

        while (current != nullptr) {
            if (current -> next == nullptr)
                cout << current -> info << endl;
            else
                cout << current -> info << " <-> ";

            current = current ->next;
        }
    }
    else {
        cout << "Список пуст." << endl;
    }
}


void delAll() {
    while(counter != 0)
        del(1);
}


void fulling() {
    int n;
    cout << "Введите сколько элементов добавить:\n>>> ";
    cin >> n;

    for (int i = 0; i < n; i++){
        push_front((int)random()%30);
    }
}


void odd_element() {
    Stack *current = firstElement;

    if (firstElement != nullptr) {

        int i = 0;
        while (current->next != nullptr) {

            if (current->next->info % 2 != 0) {
                del(i+2);
            }
            else {
                current = current->next;
                i++;
            }
        }


    }
    else {
        cout << "Стек пуст" << endl;
    }
}


void delete_odd_element() {
    push_front(0);
    odd_element();
    del(1);
}


void del(int position = 0) {

    if (position == 0) {
        cout << "Введите позицию извлекаемого элемента:" << endl <<  "(начиная с [1])" << endl << ">>> ";
        cin >> position;
    }

    if (position < 1 or position > counter) {
        cout << "Неверная позциция!" << endl;
        return;
    }

    Stack * delElement = firstElement;

    int i = 1;
    while (i<position) {
        delElement = delElement -> next;
        i++;
    }

    Stack * delPrev = delElement -> prev;
    Stack * delAfter = delElement -> next;

    if (delPrev != nullptr and counter != 1)
        delPrev -> next = delAfter;
    if (delAfter != nullptr and counter != 1)
        delAfter -> prev = delPrev;

    if (position == 1)
        firstElement = delAfter;
    if (position == counter)
        endElement = delPrev;

    delete delElement;

    counter--;
}