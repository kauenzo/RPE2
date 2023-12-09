#include "funcoes.h"
#include <iostream>
#include <stdexcept>
#include <cstring>

using namespace std;

BTree::BTree() {
    root = new Node;
    root->isLeaf = true;
    root->numKeys = 0;
}

BTree::~BTree() {
    destroy(root);
}

void BTree::destroy(Node* node) {
    if (!node->isLeaf) {
        for (int i = 0; i < node->numKeys + 1; ++i) {
            destroy(node->kids[i]);
        }
    }
    delete node;
}

bool BTree::search(int key) {
    return searchInternal(root, key);
}

bool BTree::searchInternal(Node* node, int key) {
    if (node->numKeys == 0) {
        return false;
    }

    int pos = searchKey(node->numKeys, node->keys, key);

    if (pos < node->numKeys && node->keys[pos] == key) {
        return true;
    } else {
        return (!node->isLeaf && searchInternal(node->kids[pos], key));
    }
}

void BTree::insert(int key) {
    int median;
    Node* b2 = insertInternal(root, key, median, 0);

    if (b2) {
        Node* b1 = new Node;
        *b1 = *root;

        root->numKeys = 1;
        root->isLeaf = false;
        root->keys[0] = median;
        root->kids[0] = b1;
        root->kids[1] = b2;
        root->level++;
    }
}

BTree::Node* BTree::insertInternal(Node* node, int key, int& median, int level) {
    int pos = searchKey(node->numKeys, node->keys, key);

    if (pos < node->numKeys && node->keys[pos] == key) {
        return nullptr;
    }

    if (node->isLeaf) {
        memmove(&node->keys[pos + 1], &node->keys[pos], sizeof(*(node->keys)) * (node->numKeys - pos));
        node->keys[pos] = key;
        node->numKeys++;
    } else {
        Node* b2 = insertInternal(node->kids[pos], key, median, level + 1);

        if (b2) {
            memmove(&node->keys[pos + 1], &node->keys[pos], sizeof(*(node->keys)) * (node->numKeys - pos));
            memmove(&node->kids[pos + 2], &node->kids[pos + 1], sizeof(*(node->kids)) * (node->numKeys - pos));

            node->keys[pos] = median;
            node->kids[pos + 1] = b2;
            node->numKeys++;
        }
    }

    if (node->numKeys >= 4) {
        median = node->keys[node->numKeys / 2];

        Node* b2 = new Node;
        b2->numKeys = node->numKeys - node->numKeys / 2 - 1;
        b2->isLeaf = node->isLeaf;

        memmove(b2->keys, &node->keys[node->numKeys / 2 + 1], sizeof(*(node->keys)) * b2->numKeys);
        if (!node->isLeaf) {
            memmove(b2->kids, &node->kids[node->numKeys / 2 + 1], sizeof(*(node->kids)) * (b2->numKeys + 1));
        }

        node->numKeys = node->numKeys / 2;

        b2->level = level;

        return b2;
    } else {
        return nullptr;
    }
}

int BTree::searchKey(int n, const int* a, int key) {
    int lo = -1;
    int hi = n;

    while (lo + 1 < hi) {
    	int mid = (lo + hi) / 2;
    	if (a[mid] < key) {
    		lo = mid;
    	} else {
    		hi = mid;
    	}
    }
	return hi;
}

void BTree::printKeys() {
	printKeysInternal(root, 0);
	cout << endl;
}

 void BTree::printKeysInternal(Node* node, int level) {
    if (node == nullptr) return;

    for (int j = 0; j < level; ++j) {
        cout << "    ";
    }

    cout << "-->";
    cout << "[";
    for (int i = 0; i < node->numKeys; ++i) {
        cout << node->keys[i];
        if (i < node->numKeys - 1) cout << " | ";
    }
    cout << "]";
    cout << "" << endl;

    if (!node->isLeaf) {
        for (int i = 0; i <= node->numKeys; ++i) {
            printKeysInternal(node->kids[i], level + 1);
        }
    }
}