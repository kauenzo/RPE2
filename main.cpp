#include "funcoes.h"

int main()
{
    int x,opcao;
    tree *marv = new tree;
    do
    {
        system("cls");
        marv->menu();
        cout<<"\n\n\tInforme a opcao desejada: ";
        cin>>opcao;
        switch(opcao)
        {
            case 1://insere elementos
                cout<<"Digite o valor a ser inserido: ";
            cin>>x;
            no *aux;
            aux = marv->consulta(x);
            if (aux ==NULL)
                marv->insere(x);
            else
                cout<<"Elemento já existe";
            break;

            case 2: //Remover
                if(marv!=NULL)
                {
                    cout<<"Digite valor a ser removido: ";
                    cin>>x;
                    marv->busca_remocao(x);
                }
                else
                    cout<<"Arvore Vazia";

            break;

            case 3: //Consulta em pre-Ordem
                marv->preordem(marv->get() );
            break;

            case 4: //Consulta em pos-Ordem
                marv->posordem(marv->get());
            break;

            case 5: //consulta em in-Ordem
                marv->inordem(marv->get());
            break;

            case 6: //Imprimir]
                marv->imprimearvore();
            break;

            case 7: //Imprime decrescente
                marv->decrescente(marv->get());
            break;

            case 8: // SOma elementos

                x = marv->soma(marv->get(), 0);
            cout<<"Soma dos elementos: "<<x<<"\n";
            break;

            case 9:
                x = marv->qtdInfo(marv->get(), 0);
            cout<<"Quantidade de elementos: "<<x<<"\n";
            break;

            case 10:
                x= marv->qtdFolha(marv->get(), 0);
            cout<<"Quantidade de Folhas: "<<x<<"\n";
            break;
        }
        system("pause");
    } while(opcao!=0);
    return 1;
}

