#include "Tree.h"
#include "test.h"


int main() {
    string s;
    Tree t1;

    for (int i = 0; i<10; i++) {
        s = "fio" + to_string(i);
        t1.insert(i, s);
    }
    t1.view_tree(t1.root, 0);

    cout << endl << endl;
    t1.balance();
    cout << "после балансировки:" << endl;

    t1.view_tree(t1.root,0);

    t1.insert(10, s);
    cout << "Вставлен элемент 10" << endl;
    cout << endl << endl;

    t1.view_tree(t1.root,0);

    cout << endl;

    cout << "Обратный обход:" << endl;
    t1.postoder(t1.root);
    cout << endl << endl;

    cout << "Прямой обход:" << endl;
    t1.preoder(t1.root);
    cout << endl << endl;

    cout << "В порядке возрастания(центрированный):" << endl;
    t1.inoder(t1.root);
    cout << endl << endl;

    cout << "Минимальный элемент дерева: "  <<
        t1.min_element(t1.root) -> passport_ID << endl;
    cout << "Максимальный элемент дерева: " <<
        t1.max_element(t1.root) -> passport_ID << endl;

    cout << endl;

    if (t1.find(5))
        cout << "По ID 5  найдено: " << t1.find(5) -> fio << endl;
    else
        cout << "По ID 5  ничего не найдено." << endl;

    t1.del_element(5);
    cout << "удаляем элемент 5" << endl;

    if (t1.find(5))
        cout << "По ID 5  найдено: " << t1.find(5) -> fio << endl;
    else
        cout << "По ID 5  ничего не найдено." << endl;

    cout << endl;

    cout << "Количество элементов в дереве: " <<
        t1.root_counts(t1.root) << endl;
    cout << "Количество элементов в правом поддереве: " <<
        t1.root_counts(t1.root->right) << endl;

    cout << endl;

    t1.view_tree(t1.root, 0);

    cout << endl;
    t1.del_element(3); cout << "Удаляем элемент 3" << endl;
    t1.del_element(7); cout << "Удаляем элемент 7" << endl;
    t1.del_element(6); cout << "Удаляем элемент 6" << endl;

    t1.view_tree(t1.root, 0);

    cout << endl;
    t1.balance();
    cout << "Производим балансировку" << endl;

    t1.view_tree(t1.root, 0);

    test::test_program(t1);

    return 0;
}
