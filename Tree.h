#ifndef LAB2_3_TREE_H
#define LAB2_3_TREE_H

#include "Console.h"
#include <stack>
#include <cmath>

template<class Key = int, class Data = int>
class Tree {
private:
    class Node {
    public:
        Key key;
        Data data;
        Node *left;
        Node *right;
        explicit Node(Key key, Data data = Data(), Node *left = nullptr, Node *right = nullptr)
                : key(key), data(data), left(left), right(right) {};
    };

    Node *root;

    int size;

    void print(Node *node, int lvl);

    void traverse(Node *node);

    void clear(Node *node);

    void getExternalWayLength(Node *node, int &length);

    static int COUNTER;

    static void INCREMENT_COUNTER();

    Node *getNodeByKey(Key key);

    Node *max(Node *node);

    Node *min(Node *node);

    Node *biggerParent(Node *current, Node *target);

    Node *lessParent(Node *current, Node *target);

    Node *getNodeWithMinimalKey();

    Node *getNodeWithMaximalKey();

    Node *getPrev(Node *target);

    Node *getNext(Node *target);

    Node *getParent(Node *node);

public:
    explicit Tree() : root(nullptr), size(0) {};

    Tree(const Tree<Key, Data> &tree);

    ~Tree();

    static void NULLIFY_COUNTER();

    static int GET_COUNTER();

    int getExternalWayLength();

    bool insert(Key key, Data data = Data());

    Data find(Key key);

    bool remove(Key key);

    bool set(Key key, Data data);

    void traverse();

    void print();

    bool empty();

    int getSize();

    void clear();


    class Iterator {
    private:
        Tree *tree;
        Node *node;

        Node *getParent();

    public:
        explicit Iterator(Tree<Key, Data> *tree = nullptr, Node *node = nullptr);

        bool operator++(int);

        bool operator--(int);

        bool operator==(Iterator it);

        bool operator!=(Iterator it);

        Data &operator*();

    };

    class rIterator {
    private:
        Tree *tree;
        Node *node;

        Node *getParent();

    public:
        explicit rIterator(Tree<Key, Data> *tree = nullptr, Node *node = nullptr);

        bool operator++(int);

        bool operator--(int);

        bool operator==(rIterator it);

        bool operator!=(rIterator it);

        Data &operator*();

    };

    friend class Iterator;

    friend class rIterator;

    Iterator begin();

    Iterator end();

    rIterator rbegin();

    rIterator rend();

};

template<class Key, class Data>
int Tree<Key, Data>::COUNTER = 0;

template<class Key, class Data>
void Tree<Key, Data>::NULLIFY_COUNTER() {
    Tree<Key, Data>::COUNTER = 0;
}

template<class Key, class Data>
void Tree<Key, Data>::INCREMENT_COUNTER() {
    Tree<Key, Data>::COUNTER++;
}

template<class Key, class Data>
int Tree<Key, Data>::GET_COUNTER() {
    return Tree<Key, Data>::COUNTER;
}

// ################################################
//                      Iterator
// ################################################

template<class Key, class Data>
Tree<Key, Data>::Iterator::Iterator(Tree<Key, Data> *tree, Node *node) {
    this->tree = tree;
    this->node = node;
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::operator++(int) {
    if (!node)
        return false;

    node = tree->getNext(node);
    return node;
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::operator--(int) {
    if (!node)
        return false;

    node = tree->getPrev(node);
    return node;
}

template<class Key, class Data>
Data &Tree<Key, Data>::Iterator::operator*() {
    if (!node)
        throw exception();

    return node->data;
}


template<class Key, class Data>
bool Tree<Key, Data>::Iterator::operator==(Iterator it) {
    return node == it.node;
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::operator!=(Iterator it) {
    return node != it.node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::Iterator::getParent() {
    if (node == tree->root)
        return nullptr;

    if (!node)
        throw exception();

    Node *next = nullptr;
    Node *current = tree->root;

    if (node->key > current->key)
        next = current->right;

    if (node->key < current->key)
        next = current->left;

    while (next != node) {
        current = next;
        if (node->key > current->key) {
            next = current->right;
            continue;
        }
        if (node->key < current->key) {
            next = current->left;
            continue;
        }
    }
    return current;
}

// ################################################
//                      rIterator
// ################################################

template<class Key, class Data>
Tree<Key, Data>::rIterator::rIterator(Tree<Key, Data> *tree, Node *node) {
    this->tree = tree;
    this->node = node;
}

template<class Key, class Data>
bool Tree<Key, Data>::rIterator::operator++(int) {
    if (!node)
        return false;

    node = tree->getPrev(node);
    return this->node;
}

template<class Key, class Data>
bool Tree<Key, Data>::rIterator::operator--(int) {
    if (!node)
        return false;

    node = tree->getNext(node);
    return node;
}

template<class Key, class Data>
Data &Tree<Key, Data>::rIterator::operator*() {
    if (!node)
        throw exception();

    return node->data;
}

template<class Key, class Data>
bool Tree<Key, Data>::rIterator::operator==(rIterator it) {
    return node == it.node;
}

template<class Key, class Data>
bool Tree<Key, Data>::rIterator::operator!=(rIterator it) {
    return node != it.node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::rIterator::getParent() {
    if (node == tree->root)
        return nullptr;

    if (!node)
        throw exception();

    Node *next = nullptr;
    Node *current = tree->root;
    if (node->key > current->key) {
        next = current->right;
    }
    if (node->key < current->key) {
        next = current->left;
    }
    while (next != node) {
        current = next;
        if (node->key > current->key) {
            next = current->right;
            continue;
        }
        if (node->key < current->key) {
            next = current->left;
            continue;
        }
    }
    return current;
}

// ################################################
//                      Tree
// ################################################

template<class Key, class Data>
Tree<Key, Data>::~Tree() {
    if (!empty())
        clear();
}

template<class Key, class Data>
void Tree<Key, Data>::clear(Node *node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
        size--;
    }
}

template<class Key, class Data>
void Tree<Key, Data>::clear() {
    clear(root);
    root = nullptr;
}

template<class Key, class Data>
bool Tree<Key, Data>::insert(Key key, Data data) {
    if (!root) {
        root = new Node(key, data);
    } else {
        Node *node = root;
        Node *nodeBefore = nullptr;
        while (node) {
            nodeBefore = node;
            Tree<Key, Data>::INCREMENT_COUNTER();
            if (key < node->key) {
                node = node->left;
            } else if (key > node->key) {
                node = node->right;
            } else {
                return false;
            }
        }
        node = new Node(key, data);
        if (key < nodeBefore->key) {
            nodeBefore->left = node;
        } else {
            nodeBefore->right = node;
        }
    }
    size++;
    return true;
}

template<class Key, class Data>
void Tree<Key, Data>::traverse(Node *node) {
    if (node) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        traverse(node->left);
        Console::print(node->key);
        Console::print(" ");
        traverse(node->right);
    }
}

template<class Key, class Data>
void Tree<Key, Data>::traverse() {
    traverse(root);
    Console::println();
}

template<class Key, class Data>
void Tree<Key, Data>::print() {
    print(root, 0);
}

template<class Key, class Data>
void Tree<Key, Data>::print(Node *node, int lvl) {
    if (node) {
        print(node->right, lvl + 1);
        for (int i = 0; i < lvl; ++i) {
            Console::print("    ");
        }
        Console::print(node->key, static_cast<COLORS>(lvl % 8)); // TODO: auto countering of COLORS length
        Console::print("(", static_cast<COLORS>(lvl % 8));
        Console::print(node->data, static_cast<COLORS>(lvl % 8));
        Console::println(")", static_cast<COLORS>(lvl % 8));
        print(node->left, lvl + 1);
    } else {
        for (int i = 0; i < lvl; ++i) {
            Console::print("    ");
        }
        Console::println("*", static_cast<COLORS>(lvl % 8));
    }
}

template<class Key, class Data>
bool Tree<Key, Data>::empty() {
    return this->size == 0;
}

template<class Key, class Data>
int Tree<Key, Data>::getSize() {
    return size;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getNodeByKey(Key key) {
    Node *node = root;

    while (node && key != node->key) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }

    if (!node)
        throw exception();

    return node;
}

template<class Key, class Data>
Data Tree<Key, Data>::find(Key key) {
    return getNodeByKey(key)->data;
}

template<class Key, class Data>
bool Tree<Key, Data>::remove(Key key) {
    Node *cur = root;
    Node *prev = nullptr;

    while (cur && key != cur->key) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        prev = cur;
        if (key < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (!cur)
        return false;

    Node *x = nullptr;
    Node *y = nullptr;

    if (!cur->left && !cur->right) {
        x = nullptr;
    } else if (!cur->left) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        x = cur->right;
    } else if (!cur->right) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        x = cur->left;
    } else {
        prev = cur;
        Tree<Key, Data>::INCREMENT_COUNTER();

        y = cur->right;
        while (y->left) {
            prev = y;
            y = y->left;
        }
        cur->key = y->key;
        cur->data = y->data;
        x = y->right;
        cur = y;
    }

    if (!prev) {
        root = x;
    } else if (cur->key < prev->key) {
        prev->left = x;
    } else {
        prev->right = x;
    }

    delete cur;
    this->size--;
    return true;
}

template<class Key, class Data>
typename Tree<Key, Data>::Iterator Tree<Key, Data>::begin() {
    return Tree<Key, Data>::Iterator(this, getNodeWithMinimalKey());
}

template<class Key, class Data>
typename Tree<Key, Data>::Iterator Tree<Key, Data>::end() {
    return Tree<Key, Data>::Iterator(this);
}

template<class Key, class Data>
typename Tree<Key, Data>::rIterator Tree<Key, Data>::rbegin() {
    return Tree<Key, Data>::rIterator(this, getNodeWithMaximalKey());
}

template<class Key, class Data>
typename Tree<Key, Data>::rIterator Tree<Key, Data>::rend() {
    return Tree<Key, Data>::rIterator(this);
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getParent(Node *node) {
    if (node == root)
        return nullptr;

    if (!node)
        throw exception();

    Node *next = nullptr;
    Node *current = root;
    if (node->key > current->key) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        next = current->right;
    }
    if (node->key < current->key) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        next = current->left;
    }
    while (next != node) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        current = next;
        if (node->key > current->key) {
            next = current->right;
            continue;
        }
        if (node->key < current->key) {
            next = current->left;
            continue;
        }
    }
    return current;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::max(Node *node) {
    if (!node)
        return nullptr;

    while (node->right) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        node = node->right;
    }
    return node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::biggerParent(Node *current, Node *target) {
    if (current == target)
        return nullptr;

    Tree<Key, Data>::INCREMENT_COUNTER();
    if (target->key > current->key) {
        Node *returnNode = biggerParent(current->right, target);
        if (!returnNode)
            return current;
        else
            return returnNode;
    } else {
        return biggerParent(current->left, target);
    }
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::lessParent(Node *current, Node *target) {
    if (current == target)
        return nullptr;

    Tree<Key, Data>::INCREMENT_COUNTER();
    if (target->key < current->key) {
        Node *returnNode = lessParent(current->left, target);
        if (!returnNode)
            return current;
        else
            return returnNode;
    } else {
        return lessParent(current->right, target);
    }
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getPrev(Node *target) {
    if (empty() || !target)
        throw exception();

    if (target->left) {
        return max(target->left);
    } else {
        return biggerParent(root, target);
    }
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getNext(Node *target) {
    if (empty() || !target)
        throw exception();

    if (target->right) {
        return min(target->right);
    } else {
        return lessParent(root, target);
    }
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::min(Node *node) {
    if (!node)
        return nullptr;

    while (node->left) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        node = node->left;
    }
    return node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getNodeWithMinimalKey() {
    Node *node = root;

    while (node && node->left) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        node = node->left;
    }
    return node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getNodeWithMaximalKey() {
    Node *node = root;
    while (node && node->right) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        node = node->right;
    }
    return node;
}

template<class Key, class Data>
bool Tree<Key, Data>::set(Key key, Data data) {
    try {
        Node *node = getNodeByKey(key);
        node->data = data;
    } catch (const exception &ex) {
        return false;
    }
    return true;
}

template<class Key, class Data>
int Tree<Key, Data>::getExternalWayLength() {
    int length = 0;
    getExternalWayLength(root, length);
    return length;
}

template<class Key, class Data>
void Tree<Key, Data>::getExternalWayLength(Node *node, int &length) {
    if (node) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        getExternalWayLength(node->left, length);
        getExternalWayLength(node->right, length);
    } else {
        length++;
    }
}

template<class Key, class Data>
Tree<Key, Data>::Tree(const Tree<Key, Data> &tree) {
    size = 0;
    Node *node = tree.root;
    while (node) {
        break;
        this->insert(node->key, node->getData());
        // TODO: do this copy constructor logic
    }
}

#endif //LAB2_3_TREE_H
