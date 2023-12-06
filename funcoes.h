#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;


class no
{
private:
    no *esq;
    no *dir;
    int info;
public:
    no();
    no(int info);
    ~no();
    void lista();
    no *getesq();
    void setesq(no *esq);
    no *getdir();
    void setdir(no *dir);
    int getinfo();
    void setinfo(int info);
};


class tree
{
private:
    no *arv;

public:
    tree();
    ~tree();
    no *get();
    void set(no *aux);
    no* consulta(int x);
    void insere(int x);
    void destroe(no *aux);
    void preordem(no *aux);
    void posordem(no *aux);
    void inordem(no *aux);
    void busca_remocao(int x);
    void remove(no *aux,no *pai);
    void imprimearvore();
    void decrescente( no* aux);
    int soma(no *aux, int x);
    int qtdFolha(no *aux, int x);
    int qtdInfo(no *aux, int x);
    //*****************************************
    void menu();
    //*****************************************

};

class BTreeNode {
private:
    int *keys; // Um array de chaves
    int t; // Grau mínimo
    BTreeNode **C; // Um array de ponteiros para filhos
    int n; // Número atual de chaves
    bool leaf; // Verdadeiro se for folha

public:
    BTreeNode(int _t, bool _leaf);
    // Métodos para inserção, remoção, etc. serão adicionados depois

    // Método para imprimir o nó - útil para depuração
    void traverse();

    int getKey(int idx);
    BTreeNode* getChild(int idx);
    void setKey(int idx, int key);
    void setChild(int idx, BTreeNode* child);
    int getNumKeys();
    bool isLeaf();

    // Amigo da classe para acessar membros privados
    friend class BTree;
};

class BTree {
private:
    BTreeNode *root; // Ponteiro para a raiz
    int t; // Grau mínimo

public:
    BTree(int _t) {
        root = nullptr;
        t = _t;
    }

    // Método para percorrer a árvore
    void traverse() {
        if (root != nullptr) root->traverse();
    }

    void insert(int k);
    void insertNonFull(BTreeNode *node, int k); // Adicionar esta linha
    void splitChild(BTreeNode *node, int i); // Adicionar esta linha
    // Métodos para inserção, remoção, etc. serão adicionados depois
};



