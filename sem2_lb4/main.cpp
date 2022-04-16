#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct Item {
    string group;
    string brand;
    int date = 20220000;
    string state;

};
vector<Item> item_list;
vector<string> groups;


void menu();

void quicksort(int, int);

void fulling();

void del_element();

void print_simple_list();

void sort_later();

void sort_early();

void find_groups();

void print_groups();

int getDateToday();

void print_groups_today();

void search_binar();

void search_linal();


int main()
{
    int answer;

    while (true) {
        unsigned seed = time(nullptr);
        srand(seed);

        menu();
        cout << ">>> ";
        cin >> answer;

        switch (answer) {
            case 1 :
                fulling();
                break;

            case 2 :
                print_simple_list();
                break;

            case 3 :
                find_groups();
                print_groups();
                break;

            case 4 :
                find_groups();
                print_groups_today();
                break;

            case 5 :
                sort_later();
                break;

            case 6 :
                sort_early();
                break;

            case 7 :
                quicksort(0,(int)item_list.size() - 1);
                break;

            case 8 :
                search_binar();
                break;

            case 9 :
                search_linal();
                break;

            case 10 :
                del_element();
                break;

            case 0 :
                return 0;

            default:
                break;

        }
    }
}


void menu()
{
    cout << endl;
    cout << "1 - добавить квитанцию" << endl;
    cout << "2 - вывести список квитанций" << endl;
    cout << "3 - вывести список квитанций по группам" << endl;
    cout << "4 - вывести список квитанций по группам (за сегодня)" << endl;
    cout << "5 - сортировать список квитанций (новые)" << endl;
    cout << "6 - сортировать список квитанций (поздние)" << endl;
    cout << "7 - q_sort (поздние)" << endl;
    cout << "8 - поиск квитанций по дате (бинарный)" << endl;
    cout << "9 - поиск квитанций по группе (линейный)" << endl;
    cout << "10 - удалить квитанцию" << endl;
    cout << "0 - exit" << endl;
    cout << endl;
}


void del_element()
{
    if (!item_list.empty()) {
        print_simple_list();
        cout << "\nВведите номер квитанции для удаления" << endl << ">>> ";
        int index;
        cin >> index;
        if (index < item_list.size()+1)
            item_list.erase(item_list.begin() + (index - 1));
        else
            cout << "Неверный индекс" << endl;
    }
    else {
        cout << "Невозможно. Список пуст." << endl;
    }
}


void search_linal()
{
    if (!item_list.empty()) {
        string search_group;
        cout << "Введите группу изделий\n>>> ";
        cin >> search_group;

        cout << endl;
        printf(" |          Группа           |           Марка           |     Дата     |    Состояние готовности   |");
        cout << endl;

        for (auto &item: item_list) {
            if (item.group == search_group) {
                printf(" | %25s | %25s |   %8i   | %25s |\n",
                       item.group.c_str(), item.brand.c_str(), item.date, item.state.c_str());
            }
        }
        cout << endl;
    }
    else {
        cout << "Поиск невозможен. Список пуст" << endl;
    }
}


void quicksort(int first, int last)
{
    if (!item_list.empty()) {
        int mid;
        int f = first;
        int l = last;
        mid = item_list[(f + l) / 2].date;
        do {
            while (item_list[f].date < mid)
                f++;
            while (item_list[l].date > mid)
                l--;
            if (f <= l) {
                Item temp;
                temp = item_list[f];
                item_list[f] = item_list[l];
                item_list[l] = temp;
                f++;
                l--;
            }
        } while (f <= l);
        if (first < l) quicksort(first, l);
        if (f < last) quicksort(f, last);
    }
    else {
        cout << "Сортировка невозможна. Список пуст" << endl;
    }
}


void search_binar()
{
    if (!item_list.empty()) {
        sort_early();
        int search_date;
        cout << "Введите дату\n>>> ";
        cin >> search_date;

        int i_key = 0, j = (int) item_list.size(), mid;
        j--;
        while (i_key < j) {
            mid = (i_key + j) / 2;
            if (item_list[mid].date < search_date)
                i_key = mid + 1;
            else
                j = mid;
        }
        if (item_list[i_key].date != search_date)
            cout << "Ничего не найдено." << endl;
        else {
            printf(" |          Группа           |           Марка           |     Дата     |    Состояние готовности   |");
            cout << endl;
            for (auto &item: item_list) {
                if (item.date == item_list[i_key].date) {
                    printf(" | %25s | %25s |   %8i   | %25s |",
                           item.group.c_str(), item.brand.c_str(), item.date, item.state.c_str());

                    cout << endl;
                }
            }
        }
    }
    else {
        cout << "Поиск невозможен. Список пуст" << endl;
    }
}


void print_simple_list()
{
    if (!item_list.empty()) {
        int counter = 1;

        cout << endl;
        printf("   |          Группа           |           Марка           |     Дата     |    Состояние готовности   |");
        cout << endl;

        for (auto &it: item_list) {
            printf("%2i | %25s | %25s |   %8i   | %25s |",
                   counter, it.group.c_str(), it.brand.c_str(), it.date, it.state.c_str());
            cout << endl;

            counter++;
        }
    }
    else {
        cout << "Список пуст" << endl;
    }
}


void print_groups() {
    if (!item_list.empty()) {
        cout << "Имеющиеся группы: ";
        for (auto &i: groups) {
            if (i == groups.back())
                cout << i << "." << endl;
            else
                cout << i << ", ";
        }
        printf("                 |          Группа           |           Марка           |     Дата     |    Состояние готовности   |");
        cout << endl;
        for (auto &group: groups) {
            cout << "Группа " << group << ":" << endl;
            for (auto &it: item_list) {
                if (group == it.group) {
                    printf("                 | %25s | %25s |   %8i   | %25s |",
                           it.group.c_str(), it.brand.c_str(), it.date, it.state.c_str());

                    cout << endl;
                }
            }
            cout << endl;
        }
    }
    else {
        return;
    }
}


void print_groups_today()
{
    if (!item_list.empty()) {
        cout << "Имеющиеся группы: ";
        for (auto &i: groups) {
            if (i == groups.back())
                cout << i << "." << endl;
            else
                cout << i << ", ";
        }
        printf("                 |          Группа           |           Марка           |     Дата     |    Состояние готовности   |");
        cout << endl;
        for (auto &group: groups) {
            cout << "Группа " << group << ":" << endl;
            for (auto &it: item_list) {
                if (group == it.group and it.date == getDateToday()) {
                    printf("                 | %25s | %25s |   %8i   | %25s |",
                           it.group.c_str(), it.brand.c_str(), it.date, it.state.c_str());

                    cout << endl;
                }
            }
            cout << endl;
        }
    }
    else {
        return;
    }
}


int getDateToday()
{
    const time_t tm = time(nullptr);
    string date;
    char buf[64];

    strftime(buf, 64, "%d.%m.%Y", localtime(&tm));

    date += buf[6];
    date += buf[7];
    date += buf[8];
    date += buf[9];
    date += buf[3];
    date += buf[4];
    date += buf[0];
    date += buf[1];

    return stoi(date);
}


void find_groups()
{
    if (!item_list.empty()) {
        if (groups.empty())
            groups.push_back(item_list[0].group);

        for (auto &i: item_list) {
            string temp = i.group;
            for (auto &j: groups) {
                if (temp != j) {
                    if (j == groups.back())
                        groups.push_back(temp);

                } else
                    break;
            }


        }
    }
    else {
        cout << "Список пуст" << endl;
    }
}


void fulling()
{
    Item temp_item;

    cin.ignore();
    cout << "Заполнение квитанции:" << endl << endl;

    cout << "Наименование группы изделия:" << endl << ">>> ";
    getline(cin,temp_item.group);

    cout << "Марка изделия:" << endl << ">>> ";
    getline(cin,temp_item.brand);

    cout << "дата приемки (в формате yyyy/mm/dd):" << endl << ">>> ";
    int date;
    cin >> date;
    temp_item.date = date;
    cin.ignore();

    cout << "состояние готовности:" << endl << ">>> ";
    getline(cin,temp_item.state);

    item_list.push_back(temp_item);
}


void sort_early()
{
    if (!item_list.empty()) {
        for (int i=0; i < item_list.size()-1; i++) {
            for (int j = i+1; j < item_list.size(); j++) {

                if (item_list[i].date > item_list[j].date) {
                    Item temp;
                    temp = item_list[i];
                    item_list[i] = item_list[j];
                    item_list[j] = temp;

                }
            }
        }
    }
    else {
        cout << "Сортировка невозможна. Список пуст" << endl;
    }

}


void sort_later()
{
    if (!item_list.empty()) {
        for (int i = 0; i < item_list.size() - 1; i++) {
            for (int j = i + 1; j < item_list.size(); j++) {
                if (item_list[i].date < item_list[j].date) {
                    Item temp;
                    temp = item_list[i];
                    item_list[i] = item_list[j];
                    item_list[j] = temp;
                }
            }
        }
    }
    else {
        cout << "Сортировка невозможна. Список пуст" << endl;
    }
}