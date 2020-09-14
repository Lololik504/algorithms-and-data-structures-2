#ifndef LAB2_3_TREE_H
#define LAB2_3_TREE_H

#include "Console.h"
#include <stack>
#include <cmath>

template<class Key = int, class Data = int>
class Tree {
private:
    class Node {
    private:
        Key key;
        Data data;
        Node *left;
        Node *right;

    public:
        explicit Node(Key key, Data data = Data(), Node *left = nullptr, Node *right = nullptr)
                : key(key), data(data), left(left), right(right) {};

        Key getKey() const;

        void setKey(Key key);

        Data getData() const;

        void setData(Data data);

        Node *getLeft() const;

        void setLeft(Node *left);

        Node *getRight() const;

        void setRight(Node *right);
    };

    Node *root;
    int size;

    void print(Node *root, int lvl);

public:
    explicit Tree() : root(nullptr), size(0) {};

    bool insert(Key key, Data data = Data()) ;

    void traverse();

    void print();

    bool isEmpty();

    int getSize();
};

// ################################################
//                      Node
// ################################################

template<class Key, class Data>
Key Tree<Key, Data>::Node::getKey() const {
    return key;
}

template<class Key, class Data>
void Tree<Key, Data>::Node::setKey(Key key) {
    this->key = key;
}

template<class Key, class Data>
Data Tree<Key, Data>::Node::getData() const {
    return data;
}

template<class Key, class Data>
void Tree<Key, Data>::Node::setData(Data data) {
    this->data = data;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::Node::getLeft() const {
    return left;
}

template<class Key, class Data>
void Tree<Key, Data>::Node::setLeft(Tree::Node *left) {
    this->left = left;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::Node::getRight() const {
    return right;
}

template<class Key, class Data>
void Tree<Key, Data>::Node::setRight(Tree::Node *right) {
    Node::right = right;
}

// ################################################
//                      Tree
// ################################################


template<class Key, class Data>
bool Tree<Key, Data>::insert(Key key, Data data) {
    if (!this->root) {
        this->root = new Node(key, data);
    } else {
        Node *node = this->root;
        Node *nodeBefore = nullptr;
        while (node) {
            nodeBefore = node;
            if (key < node->getKey()) {
                node = node->getLeft();
            } else if (key > node->getKey()) {
                node = node->getRight();
            } else {
                return false;
            }
        }
        node = new Node(key, data);
        if (key < nodeBefore->getKey()) {
            nodeBefore->setLeft(node);
        } else {
            nodeBefore->setRight(node);
        }
    }
    this->size++;
    return true;
}

template<class Key, class Data>
void Tree<Key, Data>::traverse() {
    stack<Node *> nodes;
    nodes.push(this->root);
    while (!nodes.empty()) {
        Node *node = nodes.top();
        nodes.pop();
        if (node->getRight()) {
            nodes.push(node->getRight());
        }
        Console::print(node->getKey());
        Console::print(" ");
        if (node->getLeft()) {
            nodes.push(node->getLeft());
        }
    }
}

template<class Key, class Data>
void Tree<Key, Data>::print() {
    this->print(this->root, 0);
}

template<class Key, class Data>
void Tree<Key, Data>::print(Tree<Key, Data>::Node *node, int lvl) {
    if (node) {
        this->print(node->getRight(), lvl + 1);
        for (int i = 0; i < lvl; ++i) {
            Console::print("    ");
        }
        Console::println(node->getKey(), static_cast<COLORS>(lvl % 8));
        this->print(node->getLeft(), lvl + 1);
    }
}

template<class Key, class Data>
bool Tree<Key, Data>::isEmpty() {
    return this->size == 0;
}

template<class Key, class Data>
int Tree<Key, Data>::getSize() {
    return this->size;
}

#endif //LAB2_3_TREE_H
