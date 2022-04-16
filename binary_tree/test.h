#include "Tree.h"
#include <fstream>

namespace test {

    void read(string &name, Tree &t) {

        ifstream file;

        int pass_id;
        string fio;

        int counter=0;

        file.open("/Users/glebchanskiy/Desktop/"+name);

        if (file.is_open()) {
            while (true) {
                file >> pass_id;
                file >> fio;

                if(file.eof())
                    break;

                if (!t.find(pass_id)) {
                    t.insert(pass_id, fio);
                    counter++;
                }
                else
                    cout << "паспорт с номером " << pass_id << " (" << fio << "), уже занесен в дерево." << endl;
            }
            file.close();
            t.balance();
            cout << "добавлено " << counter << " паспортов" << endl;
        }
        else
            cout << "Файл не найден." << endl;

        file.close();
    }

    int test_program(Tree &t2) {
        int answer, num;
        string line;

        while (true) {
            cout << endl;
            cout << "1 - добавить паспорт" << endl;
            cout << "2 - вывести дерево (4 способа)" << endl;
            cout << "3 - удаление паспорта" << endl;
            cout << "4 - крайний номер справа(max)" << endl;
            cout << "5 - крайний номер слева(min)" << endl;
            cout << "6 - найти ФИО по номеру" << endl;
            cout << "7 - балансировать дерево" << endl;
            cout << "8 - количество элементов в правом поддереве (вариант)" << endl;
            cout << "9 - читать из файла" << endl;
            cout << "0 - exit" << endl;
            cout << endl;

            cout << ">>> ";
            cin >> answer;

            switch (answer) {
                case 1 :
                    cout << "(номер паспорта)>>> ";

                    if (cin >> num) {
                        fflush(stdin);
                        cout << "(ФИО)>>> ";
                        getline(cin, line);
                        t2.insert(num, line);
                    }
                    else
                        cout << "неверный ввод." << endl;

                    cin.clear();
                    fflush(stdin);
                    break;

                case 2 :
                    cout << endl << "Выберите способ обхода:" << endl;
                    cout << "1 - прямой обход" << endl;
                    cout << "2 - обратный обход" << endl;
                    cout << "3 - в порядке возрастания ключа" << endl;
                    cout << "4 - в виде дерева" << endl << ">>> ";
                    cin >> num;
                    switch (num) {
                        case 1 :
                            t2.preoder(t2.root);
                            break;
                        case 2 :
                            t2.postoder(t2.root);
                            break;
                        case 3 :
                            t2.inoder(t2.root);
                            break;
                        case 4 :
                            t2.view_tree(t2.root, 0);
                            break;
                        default:
                            cout << "Неверное значение!" << endl;
                            break;
                    }
                    break;

                case 3 :
                    cout << "(номер паспорта)>>> ";

                    if (cin >> num) {
                        fflush(stdin);
                        t2.del_element(num);
                    }
                    else
                        cout << "неверный ввод." << endl;

                    cin.clear();
                    fflush(stdin);
                    break;

                case 4 :
                    cout << "Крайний номер справа(max): " << t2.max_element(t2.root)->passport_ID <<
                         " :  " << t2.max_element(t2.root)->fio << endl;
                    break;

                case 5 :
                    cout << "Крайний номер слева(min): " << t2.min_element(t2.root)->passport_ID <<
                         " :  " << t2.min_element(t2.root)->fio << endl;
                    break;

                case 6 :
                    cout << "(номер паспорта)>>> ";
                    if (cin >> num) {
                        fflush(stdin);

                        if (t2.find(num))
                            cout << "По номеру " << num << " найдено: " << t2.find(num)->fio << endl;
                        else
                            cout << "По номеру " << num << " ничего не найден. " << endl;
                        break;
                    }
                    else
                        cout << "неверный ввод." << endl;

                    cin.clear();
                    fflush(stdin);
                    break;

                case 7:
                    t2.balance();
                    break;

                case 8:
                    cout << endl << "   " << t2.root_counts(t2.root->right) << endl;
                    break;

                case 9: {
                    string nam;
                    cin.ignore();
                    cout << "введите имя файла:\n/Users/glebchanskiy/Desktop/";
                    getline(cin, line);
                    read(line, t2);
                    break;
                }
                case 0:
                    t2.del_Tree(t2.root);
                    return 0;

                default:
                    cout << " - " << endl;
                    break;
            }
        }
    }
}