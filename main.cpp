#include <iostream>
#include <cassert>
#include "funcoes.h" // Substitua pelo nome correto do seu arquivo de cabeçalho

using namespace std;

int main() {
    BTree b;
    int choice, key;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Inserir chave" << endl;
        cout << "2. Buscar chave" << endl;
        cout << "3. Imprimir arvore" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Digite a chave para inserir: ";
            cin >> key;
            b.insert(key);
            cout << "Chave inserida." << endl;
            break;

            case 2:
                cout << "Digite a chave para buscar: ";
            cin >> key;
            if (b.search(key)) {
                cout << "Chave encontrada." << endl;
            } else {
                cout << "Chave nao encontrada." << endl;
            }
            break;

            case 3:
                cout << "Arvore B:" << endl;
            b.printKeys();
            break;

            case 4:
                cout << "Saindo..." << endl;
            return 0;

            default:
                cout << "Opção invalida. Tente novamente." << endl;
        }
    }

    return 0;
}
