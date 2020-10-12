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

    void print(Node *node, int lvl);

    void traverse(Node *node);

    void clear(Node *node);

    void getExternalWayLength(Node *node, int &length);

    static int COUNTER;

    static void INCREMENT_COUNTER();

public:
    explicit Tree() : root(nullptr), size(0) {};

    Tree(const Tree<Key, Data> &tree);

    ~Tree();

    static void NULLIFY_COUNTER();

    static int GET_COUNTER();

    int getExternalWayLength();

    Node *getNodeByKey(Key key);

    Node *max(Node *node);

    Node *min(Node *node);

    Node *biggerParent(Node *current, Node *target);

    Node *lessParent(Node *current, Node *target);

    Node *getNodeWithMinimalKey();

    Node *getNodeWithMaximalKey();

    Node *getPrev(Node *target);

    Node *getNext(Node *target);

    bool insert(Key key, Data data = Data());

    Node *getParent(Node *node);

    Data find(Key key);

    bool remove(Key key);

    bool setData(Key key, Data data);

    void traverse();

    void print();

    bool isEmpty();

    int getSize();

    void clear();

    Node *getRoot() const;

    class Iterator {
    private:
        Tree *tree;
        Node *node;

    public:
        explicit Iterator(Tree<Key, Data> *tree = nullptr, Node *node = nullptr);

        void setTree(Tree *tree);

        bool hasNode();

        bool hasTree();

        Key getKey();

        Data getData();

        Node *getParent();

        void toMinimalKey();

        void toMaximalKey();

        bool setData(Data data);

        bool operator++(int);

        bool operator--(int);

        bool operator==(Iterator it);

        bool operator!=(Iterator it);

        Node *operator*();

    };

    class rIterator {
    private:
        Tree *tree;
        Node *node;

    public:
        explicit rIterator(Tree<Key, Data> *tree = nullptr, Node *node = nullptr);

        void setTree(Tree *tree);

        bool hasNode();

        bool hasTree();

        Key getKey();

        Data getData();

        Node *getParent();

        void toMinimalKey();

        void toMaximalKey();

        bool setData(Data data);

        bool operator++(int);

        bool operator--(int);

        bool operator==(rIterator it);

        bool operator!=(rIterator it);

        Node *operator*();

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
void Tree<Key, Data>::Iterator::setTree(Tree *tree) {
    this->tree = tree;
}

template<class Key, class Data>
Data Tree<Key, Data>::Iterator::getData() {
    if (!this->hasNode()) {
        throw runtime_error("Iterator has no node");
    }
    return node->getData();
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::hasNode() {
    return this->node;
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::operator++(int) {
    if (!this->hasNode()) {
        return false;
    }
    this->node = tree->getNext(this->node);
    return this->node;
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::operator--(int) {
    if (!this->hasNode()) {
        return false;
    }
    this->node = tree->getPrev(this->node);
    return this->node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::Iterator::operator*() {
    return node;
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::setData(Data data) {
    if (!this->hasNode()) {
        return false;
    }
    this->node->setData(data);
    return true;
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::operator==(Iterator it) {
    return this->node == it.node;
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::operator!=(Iterator it) {
    return this->node != it.node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::Iterator::getParent() {
    if (this->node == this->tree->getRoot()) {
        return nullptr;
    }
    if (!this->node) {
        throw runtime_error("Iterator has no node!");
    }
    Node *next = nullptr;
    Node *current = this->tree->getRoot();
    if (this->node->getKey() > current->getKey()) {
        next = current->getRight();
    }
    if (this->node->getKey() < current->getKey()) {
        next = current->getLeft();
    }
    while (next != this->node) {
        current = next;
        if (this->node->getKey() > current->getKey()) {
            next = current->getRight();
            continue;
        }
        if (this->node->getKey() < current->getKey()) {
            next = current->getLeft();
            continue;
        }
    }
    return current;
}

template<class Key, class Data>
Key Tree<Key, Data>::Iterator::getKey() {
    if (!this->hasNode()) {
        throw runtime_error("Iterator has no node");
    }
    return node->getKey();
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::hasTree() {
    return this->tree;
}

template<class Key, class Data>
void Tree<Key, Data>::Iterator::toMinimalKey() {
    this->node = tree->getNodeWithMinimalKey();
}

template<class Key, class Data>
void Tree<Key, Data>::Iterator::toMaximalKey() {
    this->node = tree->getNodeWithMaximalKey();
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
void Tree<Key, Data>::rIterator::setTree(Tree<Key, Data> *tree) {
    this->tree = tree;
}

template<class Key, class Data>
Data Tree<Key, Data>::rIterator::getData() {
    if (!this->hasNode()) {
        throw runtime_error("Iterator has no node");
    }
    return node->getData();
}

template<class Key, class Data>
bool Tree<Key, Data>::rIterator::hasNode() {
    return this->node;
}

template<class Key, class Data>
bool Tree<Key, Data>::rIterator::operator++(int) {
    if (!this->hasNode()) {
        return false;
    }
    this->node = tree->getPrev(this->node);
    return this->node;
}

template<class Key, class Data>
bool Tree<Key, Data>::rIterator::operator--(int) {
    if (!this->hasNode()) {
        return false;
    }
    this->node = tree->getNext(this->node);
    return this->node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::rIterator::operator*() {
    return node;
}

template<class Key, class Data>
bool Tree<Key, Data>::rIterator::setData(Data data) {
    if (!this->hasNode()) {
        return false;
    }
    this->node->setData(data);
    return true;
}

template<class Key, class Data>
bool Tree<Key, Data>::rIterator::operator==(rIterator it) {
    return this->node == it.node;
}

template<class Key, class Data>
bool Tree<Key, Data>::rIterator::operator!=(rIterator it) {
    return this->node != it.node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::rIterator::getParent() {
    if (this->node == this->tree->getRoot()) {
        return nullptr;
    }
    if (!this->node) {
        throw runtime_error("Iterator has no node!");
    }
    Node *next = nullptr;
    Node *current = this->tree->getRoot();
    if (this->node->getKey() > current->getKey()) {
        next = current->getRight();
    }
    if (this->node->getKey() < current->getKey()) {
        next = current->getLeft();
    }
    while (next != this->node) {
        current = next;
        if (this->node->getKey() > current->getKey()) {
            next = current->getRight();
            continue;
        }
        if (this->node->getKey() < current->getKey()) {
            next = current->getLeft();
            continue;
        }
    }
    return current;
}

template<class Key, class Data>
Key Tree<Key, Data>::rIterator::getKey() {
    if (!this->hasNode()) {
        throw runtime_error("Iterator has no node");
    }
    return node->getKey();
}

template<class Key, class Data>
bool Tree<Key, Data>::rIterator::hasTree() {
    return this->tree;
}

template<class Key, class Data>
void Tree<Key, Data>::rIterator::toMinimalKey() {
    this->node = tree->getNodeWithMinimalKey();
}

template<class Key, class Data>
void Tree<Key, Data>::rIterator::toMaximalKey() {
    this->node = tree->getNodeWithMaximalKey();
}

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
void Tree<Key, Data>::Node::setLeft(Node *left) {
    this->left = left;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::Node::getRight() const {
    return right;
}

template<class Key, class Data>
void Tree<Key, Data>::Node::setRight(Node *right) {
    this->right = right;
}

// ################################################
//                      Tree
// ################################################

template<class Key, class Data>
Tree<Key, Data>::~Tree() {
    if (!this->isEmpty()) {
        this->clear();
    }
}

template<class Key, class Data>
void Tree<Key, Data>::clear(Node *node) {
    if (node) {
        this->clear(node->getLeft());
        this->clear(node->getRight());
        delete node;
        this->size--;
    }
}

template<class Key, class Data>
void Tree<Key, Data>::clear() {
    this->clear(this->root);
    this->root = nullptr;
}

template<class Key, class Data>
bool Tree<Key, Data>::insert(Key key, Data data) {
    if (!this->root) {
        this->root = new Node(key, data);
    } else {
        Node *node = this->root;
        Node *nodeBefore = nullptr;
        while (node) {
            nodeBefore = node;
            Tree<Key, Data>::INCREMENT_COUNTER();
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
void Tree<Key, Data>::traverse(Node *node) {
    if (node) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        this->traverse(node->getLeft());
        Console::print(node->getKey());
        Console::print(" ");
        this->traverse(node->getRight());
    }
}

template<class Key, class Data>
void Tree<Key, Data>::traverse() {
    this->traverse(this->root);
    Console::println();
}

template<class Key, class Data>
void Tree<Key, Data>::print() {
    this->print(this->root, 0);
}

template<class Key, class Data>
void Tree<Key, Data>::print(Node *node, int lvl) {
    if (node) {
        this->print(node->getRight(), lvl + 1);
        for (int i = 0; i < lvl; ++i) {
            Console::print("    ");
        }
        Console::print(node->getKey(), static_cast<COLORS>(lvl % 8)); // TODO: auto countering of COLORS length
        Console::print("(", static_cast<COLORS>(lvl % 8));
        Console::print(node->getData(), static_cast<COLORS>(lvl % 8));
        Console::println(")", static_cast<COLORS>(lvl % 8));
        this->print(node->getLeft(), lvl + 1);
    } else {
        for (int i = 0; i < lvl; ++i) {
            Console::print("    ");
        }
        Console::println("*", static_cast<COLORS>(lvl % 8));
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

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getNodeByKey(Key key) {
    Node *node = this->root;
    while (node && key != node->getKey()) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        if (key < node->getKey()) {
            node = node->getLeft();
        } else {
            node = node->getRight();
        }
    }
    if (!node) {
        throw invalid_argument("KEY ERROR");
    }
    return node;
}

template<class Key, class Data>
Data Tree<Key, Data>::find(Key key) {
    Node *node = getNodeByKey(key);
    return node->getData();
}

template<class Key, class Data>
bool Tree<Key, Data>::remove(Key key) {
    Node *cur = this->root;
    Node *prev = nullptr;
    while (cur && key != cur->getKey()) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        prev = cur;
        if (key < cur->getKey())
            cur = cur->getLeft();
        else
            cur = cur->getRight();
    }
    if (!cur)
        return false;

    Node *x = nullptr;
    Node *y = nullptr;

    if (!cur->getLeft() && !cur->getRight()) {
        x = nullptr;
    } else if (!cur->getLeft()) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        x = cur->getRight();
    } else if (!cur->getRight()) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        x = cur->getLeft();
    } else {
        prev = cur;
        Tree<Key, Data>::INCREMENT_COUNTER();
        cur = cur->getRight();
        cur = this->min(cur);
        y = this->getParent(cur);
        prev->setKey(cur->getKey());
        prev->setData(cur->getData());
        if (y != prev)
            y->setLeft(nullptr);
        else
            prev->setRight(nullptr);
    }
    if (!prev) {
        this->root = x;
    } else if (!y) {
        if (cur->getKey() < prev->getKey()) {
            prev->setLeft(x);
        } else {
            prev->setRight(x);
        }
    }
    delete cur;
    return true;
}

template<class Key, class Data>
typename Tree<Key, Data>::Iterator Tree<Key, Data>::begin() {
    if (this->isEmpty()) {
        return Tree<Key, Data>::Iterator(this);
    }
    return Tree<Key, Data>::Iterator(this, this->getNodeWithMinimalKey());
}

template<class Key, class Data>
typename Tree<Key, Data>::Iterator Tree<Key, Data>::end() {
    return Tree<Key, Data>::Iterator(this);
}

template<class Key, class Data>
typename Tree<Key, Data>::rIterator Tree<Key, Data>::rbegin() {
    if (this->isEmpty()) {
        return Tree<Key, Data>::rIterator(this);
    }
    return Tree<Key, Data>::rIterator(this, this->getNodeWithMaximalKey());
}

template<class Key, class Data>
typename Tree<Key, Data>::rIterator Tree<Key, Data>::rend() {
    return Tree<Key, Data>::rIterator(this);
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getRoot() const {
    return root;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getParent(Node *node) {
    if (node == this->getRoot()) {
        return nullptr;
    }
    if (!node) {
        throw runtime_error("Iterator has no node!");
    }
    Node *next = nullptr;
    Node *current = this->getRoot();
    if (node->getKey() > current->getKey()) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        next = current->getRight();
    }
    if (node->getKey() < current->getKey()) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        next = current->getLeft();
    }
    while (next != node) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        current = next;
        if (node->getKey() > current->getKey()) {
            next = current->getRight();
            continue;
        }
        if (node->getKey() < current->getKey()) {
            next = current->getLeft();
            continue;
        }
    }
    return current;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::max(Node *node) {
    if (!node)
        return nullptr;
    while (node->getRight()) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        node = node->getRight();
    }
    return node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::biggerParent(Node *current, Node *target) {
    if (current == target)
        return nullptr;
    Tree<Key, Data>::INCREMENT_COUNTER();
    if (target->getKey() > current->getKey()) {
        Node *returnNode = biggerParent(current->getRight(), target);
        if (!returnNode)
            return current;
        else
            return returnNode;
    } else {
        return biggerParent(current->getLeft(), target);
    }
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::lessParent(Node *current, Node *target) {
    if (current == target)
        return nullptr;
    Tree<Key, Data>::INCREMENT_COUNTER();
    if (target->getKey() < current->getKey()) {
        Node *returnNode = lessParent(current->getLeft(), target);
        if (!returnNode)
            return current;
        else
            return returnNode;
    } else {
        return lessParent(current->getRight(), target);
    }
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getPrev(Node *target) {
    if (this->isEmpty() || !target) {
        throw runtime_error("EXCEPTION");
    }
    if (target->getLeft()) {
        return this->max(target->getLeft());
    } else {
        return biggerParent(root, target);
    }
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getNext(Node *target) {
    if (this->isEmpty() || target == nullptr) {
        throw runtime_error("EXCEPTION");
    }
    if (target->getRight()) {
        return this->min(target->getRight());
    } else {
        return lessParent(root, target);
    }
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::min(Node *node) {
    if (!node)
        return nullptr;
    while (node->getLeft()) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        node = node->getLeft();
    }
    return node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getNodeWithMinimalKey() {
    Node *node = this->root;
    while (node->getLeft()) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        node = node->getLeft();
    }
    return node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getNodeWithMaximalKey() {
    Node *node = this->root;
    while (node->getRight()) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        node = node->getRight();
    }
    return node;
}

template<class Key, class Data>
bool Tree<Key, Data>::setData(Key key, Data data) {
    try {
        Node *node = this->getNodeByKey(key);
        node->setData(data);
    } catch (const invalid_argument &ex) {
        return false;
    }
    return true;
}

template<class Key, class Data>
int Tree<Key, Data>::getExternalWayLength() {
    int length = 0;
    this->getExternalWayLength(this->root, length);
    return length;
}

template<class Key, class Data>
void Tree<Key, Data>::getExternalWayLength(Node *node, int &length) {
    if (node) {
        Tree<Key, Data>::INCREMENT_COUNTER();
        this->getExternalWayLength(node->getLeft(), length);
        this->getExternalWayLength(node->getRight(), length);
    } else {
        length++;
    }
}

template<class Key, class Data>
Tree<Key, Data>::Tree(const Tree<Key, Data> &tree) {
    this->size = 0;
    Node *node = tree.getRoot();
    while (node) {
        break;
        this->insert(node->getKey(), node->getData());
        // TODO: do this copy constructor logic
    }
}

#endif //LAB2_3_TREE_H
