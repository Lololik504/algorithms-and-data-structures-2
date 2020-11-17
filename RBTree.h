#ifndef ALGORITHMS_AND_DATA_STRUCTURES_2_3_RBTREE_H
#define ALGORITHMS_AND_DATA_STRUCTURES_2_3_RBTREE_H

#include "Console.h"
#include "Tree.h"
#include <stack>
#include <cmath>

template<class Key = int, class Value = int>
class RBTree : public Tree<Key, Value> {
private:
    class RBNode : public Tree<Key, Value>::Node {
    public:
        bool red;
        explicit RBNode(Key key, Value value = Value(), bool red = false)
        : Tree<Key, Value>::Node(key, value), red(red) {};

    };
    void print(typename Tree<Key, Value>::Node *node, int lvl) override;
public:
    RBTree() : Tree<Key, Value>() {};
    ~RBTree() = default;
    bool insert(Key key, Value value) override;

};

template<class Key, class Value>
bool RBTree<Key, Value>::insert(Key key, Value value) {
    if (!this->root) {
        this->root = new RBNode(key, value);
    } else {
        RBNode *node = static_cast<RBNode*>(this->root);
        RBNode *nodeBefore = nullptr;
        while (node) {
            nodeBefore = node;
            Tree<Key, Value>::INCREMENT_COUNTER();
            if (key < node->key) {
                node = static_cast<RBNode*>(node->left);
            } else if (key > node->key) {
                node = static_cast<RBNode*>(node->right);
            } else {
                return false;
            }
        }
        node = new RBNode(key, value, static_cast<bool>(rand() % 2));
        if (key < nodeBefore->key) {
            nodeBefore->left = node;
        } else {
            nodeBefore->right = node;
        }
    }
    this->size++;
    return true;
}

template<class Key, class Value>
void RBTree<Key, Value>::print(typename Tree<Key, Value>::Node *oldnode, int lvl) {
    if (oldnode) {
        RBNode *node = static_cast<RBNode*>(oldnode);
        print(node->right, lvl + 1);
        for (int i = 0; i < lvl; ++i) {
            Console::print("    ");
        }
        Console::print(node->key, node->red ? COLORS::RED : COLORS::WHITE);
        Console::print("(", node->red ? COLORS::RED : COLORS::WHITE);
        Console::print(node->value, node->red ? COLORS::RED : COLORS::WHITE);
        Console::println(")", node->red ? COLORS::RED : COLORS::WHITE);
        print(node->left, lvl + 1);
    } else {
        for (int i = 0; i < lvl; ++i) {
            Console::print("    ");
        }
        Console::println("*", static_cast<COLORS>(lvl % 8));
    }
}

#endif //ALGORITHMS_AND_DATA_STRUCTURES_2_3_RBTREE_H
