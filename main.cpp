#include <iostream>
#include "funcoes.h"

using namespace std;

int main()
{
    BTree b;
    int choice, key;

    while (true)
    {
        cout << "\n\n############################## MENU ##############################";
        cout << "\n#                                                                 #";
        cout << "\n#              [ 1 ] Inserir chave             [ 1 ]              #";
        cout << "\n#              [ 2 ] Buscar chave              [ 2 ]              #";
        cout << "\n#              [ 3 ] Imprimir arvore           [ 3 ]              #";
        cout << "\n#              [ 4 ] Inserir varias chaves     [ 4 ]              #";
        cout << "\n#              [ 0 ] Sair                      [ 0 ]              #";
        cout << "\n#                                                                 #";
        cout << "\n###################################################################\n";

        cout << "Escolha uma opcao:  ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Digite a chave para inserir: ";
            cin >> key;
            b.insert(key);
            cout << "Chave " << key << " inserida." << endl;
            break;

        case 2:
            cout << "Digite a chave para buscar: ";
            cin >> key;
            if (b.search(key))
            {
                cout << "Chave " << key << " encontrada." << endl;
            }
            else
            {
                cout << "Chave " << key << " nao encontrada." << endl;
            }
            break;

        case 3:
            cout << "Arvore B:" << endl;
            b.printKeys();
            break;

        case 4:
            cout << "Digite as chaves para inserir (digite 'q' para sair):" << endl;
            while (true)
            {
                string input;
                cout << "> ";
                cin >> input;

                if (input == "q" || input == "Q")
                {
                    break;
                }

                int key = stoi(input);
                b.insert(key);
                cout << "Chave " << key << " inserida." << endl;
            }
            break;

        case 0:
            cout << "Saindo..." << endl;
            return 0;

        default:
            cout << "Opção invalida. Tente novamente." << endl;
        }
    }
    return 0;
}
