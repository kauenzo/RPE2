#include <iostream>
// #include <cstdlib>
// #include <stack>
#include <vector>

using namespace std;


/*class no
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
};*/


/*class tree
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

};*/

class NoB {
private:
    vector<int> chaves; // Chaves armazenadas no nó
    vector<NoB*> filhos; // Ponteiros para os filhos
    bool folha; // Indica se o nó é uma folha
    int t; // Grau mínimo (cada nó deve ter pelo menos t-1 e no máximo 2t-1 chaves)

public:
    NoB(int _t, bool _folha);

    // Métodos para inserir uma nova chave no nó não-cheio
    void inserirNaoCheio(int k);

    // Métodos para dividir o filho y deste nó. i é índice de y em filho[]
    void dividirFilho(int i, NoB *y);

    // Função para percorrer todos os nós em uma subárvore enraizada com este nó
    void percorrer();

    // Função para buscar chave k na subárvore enraizada com este nó
    NoB *buscar(int k);

    friend class TreeB;
};

class TreeB {
private:
    NoB *raiz; // Ponteiro para a raiz
    int t; // Grau mínimo
public:
    TreeB(int _t) {
        raiz = nullptr;
        t = _t;
    }

    // Função para percorrer a árvore
    void percorrer() {
        if (raiz != nullptr) raiz->percorrer();
    }

    // Função para buscar chave na árvore
    NoB* buscar(int k) {
        return (raiz == nullptr) ? nullptr : raiz->buscar(k);
    }

    // A função principal que insere uma nova chave nesta árvore B
    void inserir(int k);
    void menu();

    // Implementar outras funções aqui...
};