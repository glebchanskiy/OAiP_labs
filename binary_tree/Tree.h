#ifndef BINARY_TREE_TREE_H
#define BINARY_TREE_TREE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Tree {
public:

    class Node {
    public:
        int passport_ID;
        string fio;
        Node *left;
        Node *right;

        Node(int k, string &fio);
    };

    Node *root = nullptr;

    void insert(int passport_ID, string &fio);

    void del_Tree(Node* temp);

    void postoder(Node* current);

    void inoder(Node* current);

    void preoder(Node* current);

    void view_tree(Node* current, int level);

    Node* min_element(Node* current);

    Node* max_element(Node* current);

    Node* find(int password_ID);

    void del_element(int del_ID);

    int root_counts(Node* current);

    void balance();

private:
    void get_massive(Node *current, int *M, vector<string> &surnames, int &n);

    Node* make_balance(int n, int k, int *a, vector<string> &surnames);
};


#endif //BINARY_TREE_TREE_H