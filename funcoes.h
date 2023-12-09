#include <iostream>

using namespace std;

class BTree {
public:
    BTree();
    ~BTree();
    bool search(int key);
    void insert(int key);
    void printKeys();

private:
    struct Node {
        bool isLeaf;
        int numKeys;
        int keys[4];
        Node* kids[3];
        int level;
    };

    Node* root;

    void destroy(Node* node);
    Node* insertInternal(Node* node, int key, int& median, int level);
    bool searchInternal(Node* node, int key);
    static int searchKey(int n, const int* a, int key);
    void printKeysInternal(Node* node, int level);
};