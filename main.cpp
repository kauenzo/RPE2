#include "funcoes.h"
#include <iostream>

int main()
{
    int x,opcao, t;
    cout << "Informe o grau minimo t da arvore B: ";
    cin >> t;
    TreeB *marv = new TreeB(t); // Cria uma árvore B com grau mínimo t
    do
    {
        system("cls");
        marv->menu();
        cout<<"\n\n\tInforme a opcao desejada: ";
        cin>>opcao;
        switch(opcao) {
            case 1: // Insere elementos
                cout << "Digite o valor a ser inserido: ";
            cin >> x;
            marv->inserir(x);
            cout << "Elemento inserido.\n";
            break;

            case 2: // Buscar
                cout << "Digite o valor a ser buscado: ";
            cin >> x;
            if (marv->buscar(x) != NULL)
                cout << "Elemento encontrado.\n";
            else
                cout << "Elemento nao encontrado.\n";
            break;

            case 3: // Percorrer
                cout << "Arvore B em percurso: ";
            marv->percorrer();
            cout << "\n";
            break;

            case 0: // Sair
                cout << "Saindo...\n";
            break;

            default:
                cout << "Opção inválida!\n";
        }
        system("pause");
    } while (opcao != 0);

    delete marv; // Libera a memória alocada para a árvore
    return 0;
}