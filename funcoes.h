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


