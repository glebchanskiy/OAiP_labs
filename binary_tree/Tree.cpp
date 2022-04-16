#include "Tree.h"

// конструктор узла
Tree::Node::Node(int k, std::string &fio) {
    this -> passport_ID = k;
    this -> fio = fio;
    left = right = nullptr;
}

//вставить элемент в дерево
void Tree::insert(int passport_ID, string &fio) {
    if (root == nullptr)
        root = new Node(passport_ID, fio);
    else {
        Node *prev, *current;
        bool isFind = true;
        current = root;
        while (current and isFind) {
            prev = current;
            if (passport_ID == current->passport_ID) {
                isFind = false;
//                cout << "Дубликат ключа!" << endl;
            } else {

                if (passport_ID < current->passport_ID) {
                    current = current->left;
                } else
                    current = current->right;
            }
        }
        if (isFind) {
            current = new Node(passport_ID, fio);
            if (passport_ID < prev->passport_ID)
                prev->left = current;
            else
                prev->right = current;
        }
    }
}

// удалить дерево (или поддерево)
void Tree::del_Tree(Node *temp) {
    if (temp != nullptr)  {
        del_Tree(temp -> left);
        del_Tree(temp -> right);
        del_element(temp->passport_ID);
    }
}

// обратный обход дерева
void Tree::postoder(Node* current) {
    if (current) {
        postoder(current -> left);
        postoder(current -> right);
        cout << current -> passport_ID << "  -  " << current -> fio << endl;
    }
}

// центрированный обход дерева
void Tree::inoder(Node* current) {
    if (current) {
        inoder(current -> left);
        cout << current -> passport_ID << "  -  " << current -> fio << endl;
        inoder(current -> right);
    }
}

// прямой обход дерева
void Tree::preoder(Node* current) {
    if (current) {
        cout << current -> passport_ID << "  -  " << current -> fio << endl;
        preoder(current -> left);
        preoder(current -> right);
    }
}

// вывод в виде дерева
void Tree::view_tree(Node* current, int level) {
    string str;
    if (current) {
        view_tree(current -> right, level = level + 5);
        for (int i = 0; i < level; i++)
            str += " ";
        cout << str << current -> passport_ID <<  endl;
        view_tree(current -> left, level);

    }
}

// минимальный элемент дерева
Tree::Node* Tree::min_element(Node* current) {
    while (current -> left != nullptr)
        current = current -> left;

    return current;
}

// максимальный элемент дерева
Tree::Node* Tree::max_element(Node* current) {
    while (current -> right != nullptr)
        current = current -> right;

    return current;
}

// найти элемент дерева по ключу
Tree::Node* Tree::find(int password_ID) {
    Node* temp = root;
    while (temp != nullptr and temp -> passport_ID != password_ID) {
        if (temp->passport_ID > password_ID)
            temp = temp -> left;
        else
            temp = temp -> right;
    }
    if (temp == nullptr) {
        return nullptr;
    }
    else {
        return temp;
    }
}

// удалить элемент дерева по ключу
void Tree::del_element(int del_ID) {
    Node *del, *prev_del; // удаляемый элемент и его предок
    Node *r, *prev_r;     // элемент, на который заменяется удаляемый, и его предок
    del = root;
    prev_del = nullptr;
    while (del != nullptr and del -> passport_ID != del_ID) {
        prev_del = del;
        if (del->passport_ID > del_ID)
            del = del->left;
        else
            del = del->right;
    }
    if (del == nullptr) {
        return;
    }
    if (del -> right == nullptr)
        r = del -> left;
    else if (del -> left == nullptr)
        r = del -> right;
    else {
        prev_r = del;
        r = del -> left;
        while (r -> right != nullptr) {
            prev_r = r;
            r = r -> right;
        }
        if (prev_r == del)
            r -> right = del -> right;
        else {
            r -> right = del -> right;
            prev_r -> right = r -> left;
            r -> left = del -> left;
        }


    }
    if (del == root) {
        root = r;
    }
    else if (del -> passport_ID < prev_del -> passport_ID) {
        prev_del -> left = r;
    } else
        prev_del -> right = r;
    delete del;
}

// возвращает количество элементов в дереве (поддереве)
int Tree::root_counts(Tree::Node *current){
    if (current == nullptr)
        return 0;
    return root_counts(current->right) + root_counts(current->left) + 1;
}

// балансировка дерева
void Tree::balance() {

    int id_arr_size = root_counts(root);
    int n = 0;

    int* id_arr = new int[id_arr_size];
    vector<string> surnames;
    surnames.reserve(id_arr_size);

    get_massive(root,id_arr, surnames, n);

    del_Tree(root);

    int n2 = 0;
    root = make_balance(n2,id_arr_size,id_arr, surnames);

}


void Tree::get_massive(Tree::Node *current, int *passports, vector<string> &surnames, int &n) {
    if (current != nullptr) {
        get_massive(current->left, passports, surnames, n);
        passports[n++] = current->passport_ID;
        surnames.push_back(current->fio);
        get_massive(current->right, passports, surnames, n);
    }
}


Tree::Node* Tree::make_balance(int n, int k, int *a, vector<string> &surnames) {
    int mid = (n + k)/2;
    Node* temp = new Node(a[mid], surnames[mid]);
    if (n < mid)
        temp->left = make_balance(n,mid,a, surnames);
    if (mid + 1 < k)
        temp->right = make_balance(mid+1,k,a, surnames);

    return temp;
}