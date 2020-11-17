#ifndef LAB2_3_TREE_H
#define LAB2_3_TREE_H

#include "Console.h"
#include <stack>
#include <cmath>

template<class Key = int, class Value = int>
class Tree {
protected:
    class Node {
    public:
        Key key;
        Value value;
        Node *left;
        Node *right;

        explicit Node(
            Key key,
            Value value = Value(),
            Node *left = nullptr,
            Node *right = nullptr
        ) : key(key), value(value), left(left), right(right) {};

    };

    Node *root;

    int size;

    virtual void print(Node *node, int lvl);

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

    void init();

    void copy(const Node *node);

public:
    Tree();

    Tree(const Tree<Key, Value> &tree);

    virtual ~Tree();

    static void NULLIFY_COUNTER();

    static int GET_COUNTER();

    int getExternalWayLength();

    virtual bool insert(Key key, Value value);

    Value find(Key key);

    virtual bool remove(Key key);

    bool set(Key key, Value value);

    void traverse();

    void print();

    bool empty();

    int getSize();

    void clear();

    Node * getRoot();

    class Iterator {
    private:
        Tree *tree;
        Node *node;

        Node *getParent();

    public:
        explicit Iterator(Tree<Key, Value> *tree = nullptr, Node *node = nullptr);

        bool operator++(int);

        bool operator--(int);

        bool operator==(Iterator it);

        bool operator!=(Iterator it);

        Value &operator*();

    };

    class rIterator {
    private:
        Tree *tree;
        Node *node;

        Node *getParent();

    public:
        explicit rIterator(Tree<Key, Value> *tree = nullptr, Node *node = nullptr);

        bool operator++(int);

        bool operator--(int);

        bool operator==(rIterator it);

        bool operator!=(rIterator it);

        Value &operator*();

    };

    friend class Iterator;

    friend class rIterator;

    Iterator begin();

    Iterator end();

    rIterator rbegin();

    rIterator rend();

};

template<class Key, class Value>
int Tree<Key, Value>::COUNTER = 0;

template<class Key, class Value>
void Tree<Key, Value>::NULLIFY_COUNTER() {
    Tree<Key, Value>::COUNTER = 0;
}

template<class Key, class Value>
void Tree<Key, Value>::INCREMENT_COUNTER() {
    Tree<Key, Value>::COUNTER++;
}

template<class Key, class Value>
int Tree<Key, Value>::GET_COUNTER() {
    return Tree<Key, Value>::COUNTER;
}

// ################################################
//                      Iterator
// ################################################

template<class Key, class Value>
Tree<Key, Value>::Iterator::Iterator(Tree<Key, Value> *tree, Node *node) {
    this->tree = tree;
    this->node = node;
}

template<class Key, class Value>
bool Tree<Key, Value>::Iterator::operator++(int) {
    if (!node)
        return false;

    node = tree->getNext(node);
    return node;
}

template<class Key, class Value>
bool Tree<Key, Value>::Iterator::operator--(int) {
    if (!node)
        return false;

    node = tree->getPrev(node);
    return node;
}

template<class Key, class Value>
Value &Tree<Key, Value>::Iterator::operator*() {
    if (!node)
        throw exception();

    return node->value;
}


template<class Key, class Value>
bool Tree<Key, Value>::Iterator::operator==(Iterator it) {
    return node == it.node;
}

template<class Key, class Value>
bool Tree<Key, Value>::Iterator::operator!=(Iterator it) {
    return node != it.node;
}

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::Iterator::getParent() {
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

template<class Key, class Value>
Tree<Key, Value>::rIterator::rIterator(Tree<Key, Value> *tree, Node *node) {
    this->tree = tree;
    this->node = node;
}

template<class Key, class Value>
bool Tree<Key, Value>::rIterator::operator++(int) {
    if (!node)
        return false;

    node = tree->getPrev(node);
    return this->node;
}

template<class Key, class Value>
bool Tree<Key, Value>::rIterator::operator--(int) {
    if (!node)
        return false;

    node = tree->getNext(node);
    return node;
}

template<class Key, class Value>
Value &Tree<Key, Value>::rIterator::operator*() {
    if (!node)
        throw exception();

    return node->value;
}

template<class Key, class Value>
bool Tree<Key, Value>::rIterator::operator==(rIterator it) {
    return node == it.node;
}

template<class Key, class Value>
bool Tree<Key, Value>::rIterator::operator!=(rIterator it) {
    return node != it.node;
}

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::rIterator::getParent() {
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


template<class Key, class Value>
Tree<Key, Value>::Tree() {
    init();
}

template<class Key, class Value>
void Tree<Key, Value>::init() {
    this->root = nullptr;
    this->size = 0;
}

template<class Key, class Value>
void Tree<Key, Value>::copy(const Node *node) {
    insert(node->key, node->value);
    if (node->left) {
        copy(node->left);
    }
    if (node->getRight()) {
        copy(node->right);
    }
}

template<class Key, class Value>
Tree<Key, Value>::Tree(const Tree<Key, Value> &tree) {
    init();
    copy(tree.root);
}

template<class Key, class Value>
Tree<Key, Value>::~Tree() {
    if (!empty())
        clear();
}

template<class Key, class Value>
void Tree<Key, Value>::clear(Node *node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
        size--;
    }
}

template<class Key, class Value>
void Tree<Key, Value>::clear() {
    clear(root);
    root = nullptr;
}

template<class Key, class Value>
bool Tree<Key, Value>::insert(Key key, Value value) {
    if (!root) {
        root = new Node(key, value);
    } else {
        Node *node = root;
        Node *nodeBefore = nullptr;
        while (node) {
            nodeBefore = node;
            Tree<Key, Value>::INCREMENT_COUNTER();
            if (key < node->key) {
                node = node->left;
            } else if (key > node->key) {
                node = node->right;
            } else {
                return false;
            }
        }
        node = new Node(key, value);
        if (key < nodeBefore->key) {
            nodeBefore->left = node;
        } else {
            nodeBefore->right = node;
        }
    }
    size++;
    return true;
}

template<class Key, class Value>
void Tree<Key, Value>::traverse(Node *node) {
    if (node) {
        Tree<Key, Value>::INCREMENT_COUNTER();
        traverse(node->left);
        Console::print(node->key);
        Console::print(" ");
        traverse(node->right);
    }
}

template<class Key, class Value>
void Tree<Key, Value>::traverse() {
    traverse(root);
    Console::println();
}

template<class Key, class Value>
void Tree<Key, Value>::print() {
    print(root, 0);
}

template<class Key, class Value>
void Tree<Key, Value>::print(Node *node, int lvl) {
    if (node) {
        print(node->right, lvl + 1);
        for (int i = 0; i < lvl; ++i) {
            Console::print("    ");
        }
        Console::print(node->key, static_cast<COLORS>(lvl % 8)); // TODO: auto countering of COLORS length
        Console::print("(", static_cast<COLORS>(lvl % 8));
        Console::print(node->value, static_cast<COLORS>(lvl % 8));
        Console::println(")", static_cast<COLORS>(lvl % 8));
        print(node->left, lvl + 1);
    } else {
        for (int i = 0; i < lvl; ++i) {
            Console::print("    ");
        }
        Console::println("*", static_cast<COLORS>(lvl % 8));
    }
}

template<class Key, class Value>
bool Tree<Key, Value>::empty() {
    return this->size == 0;
}

template<class Key, class Value>
int Tree<Key, Value>::getSize() {
    return size;
}

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::getNodeByKey(Key key) {
    Node *node = root;

    while (node && key != node->key) {
        Tree<Key, Value>::INCREMENT_COUNTER();
        if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }

    if (!node)
        throw exception();

    return node;
}

template<class Key, class Value>
Value Tree<Key, Value>::find(Key key) {
    return getNodeByKey(key)->value;
}

template<class Key, class Value>
bool Tree<Key, Value>::remove(Key key) {
    Node *cur = root;
    Node *prev = nullptr;

    while (cur && key != cur->key) {
        Tree<Key, Value>::INCREMENT_COUNTER();
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
        Tree<Key, Value>::INCREMENT_COUNTER();
        x = cur->right;
    } else if (!cur->right) {
        Tree<Key, Value>::INCREMENT_COUNTER();
        x = cur->left;
    } else {
        prev = cur;
        Tree<Key, Value>::INCREMENT_COUNTER();

        y = cur->right;
        while (y->left) {
            prev = y;
            y = y->left;
        }
        cur->key = y->key;
        cur->value = y->value;
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

template<class Key, class Value>
typename Tree<Key, Value>::Iterator Tree<Key, Value>::begin() {
    return Tree<Key, Value>::Iterator(this, getNodeWithMinimalKey());
}

template<class Key, class Value>
typename Tree<Key, Value>::Iterator Tree<Key, Value>::end() {
    return Tree<Key, Value>::Iterator(this);
}

template<class Key, class Value>
typename Tree<Key, Value>::rIterator Tree<Key, Value>::rbegin() {
    return Tree<Key, Value>::rIterator(this, getNodeWithMaximalKey());
}

template<class Key, class Value>
typename Tree<Key, Value>::rIterator Tree<Key, Value>::rend() {
    return Tree<Key, Value>::rIterator(this);
}

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::getParent(Node *node) {
    if (node == root)
        return nullptr;

    if (!node)
        throw exception();

    Node *next = nullptr;
    Node *current = root;
    if (node->key > current->key) {
        Tree<Key, Value>::INCREMENT_COUNTER();
        next = current->right;
    }
    if (node->key < current->key) {
        Tree<Key, Value>::INCREMENT_COUNTER();
        next = current->left;
    }
    while (next != node) {
        Tree<Key, Value>::INCREMENT_COUNTER();
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

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::max(Node *node) {
    if (!node)
        return nullptr;

    while (node->right) {
        Tree<Key, Value>::INCREMENT_COUNTER();
        node = node->right;
    }
    return node;
}

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::biggerParent(Node *current, Node *target) {
    if (current == target)
        return nullptr;

    Tree<Key, Value>::INCREMENT_COUNTER();
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

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::lessParent(Node *current, Node *target) {
    if (current == target)
        return nullptr;

    Tree<Key, Value>::INCREMENT_COUNTER();
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

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::getPrev(Node *target) {
    if (empty() || !target)
        throw exception();

    if (target->left) {
        return max(target->left);
    } else {
        return biggerParent(root, target);
    }
}

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::getNext(Node *target) {
    if (empty() || !target)
        throw exception();

    if (target->right) {
        return min(target->right);
    } else {
        return lessParent(root, target);
    }
}

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::min(Node *node) {
    if (!node)
        return nullptr;

    while (node->left) {
        Tree<Key, Value>::INCREMENT_COUNTER();
        node = node->left;
    }
    return node;
}

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::getNodeWithMinimalKey() {
    Node *node = root;

    while (node && node->left) {
        Tree<Key, Value>::INCREMENT_COUNTER();
        node = node->left;
    }
    return node;
}

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::getNodeWithMaximalKey() {
    Node *node = root;
    while (node && node->right) {
        Tree<Key, Value>::INCREMENT_COUNTER();
        node = node->right;
    }
    return node;
}

template<class Key, class Value>
bool Tree<Key, Value>::set(Key key, Value value) {
    try {
        Node *node = getNodeByKey(key);
        node->value = value;
    } catch (const exception &ex) {
        return false;
    }
    return true;
}

template<class Key, class Value>
int Tree<Key, Value>::getExternalWayLength() {
    int length = 0;
    getExternalWayLength(root, length);
    return length;
}

template<class Key, class Value>
void Tree<Key, Value>::getExternalWayLength(Node *node, int &length) {
    if (node) {
        Tree<Key, Value>::INCREMENT_COUNTER();
        getExternalWayLength(node->left, length);
        getExternalWayLength(node->right, length);
    } else {
        length++;
    }
}

template<class Key, class Value>
typename Tree<Key, Value>::Node *Tree<Key, Value>::getRoot() {
    return root;
}

#endif //LAB2_3_TREE_H
