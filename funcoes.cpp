#include "funcoes.h"

//metodos classe no

/*
no::no()
{

}

no::no(int info)
{
    dir = NULL;
    esq = NULL;
    this->info = info;

}

no::~no()
{
    cout<<"Valor excluído: "<<info;
}

void no::lista()
{
    cout<<info<<"\n";
}

no *no::getesq()
{
    return esq;
}

void no::setesq(no *esq)
{
    this->esq = esq;
}

no *no::getdir()
{
    return dir;
}

void no::setdir(no *dir)
{
    this->dir=dir;
}

int no::getinfo()
{
    return info;
}

void no::setinfo(int info)
{
    this->info = info;
}
*/

// metodos da classe Btree

/*
//metodos classe tree


tree::tree()
{
    arv=NULL;
}

tree::~tree()
{

}

no *tree::get()
{
    return arv;
}

void tree::set(no *aux)
{
    this->arv=aux;
}


no* tree::consulta(int x) {
	no *atual = arv;
	while (atual != NULL) {
		if (x < atual->getinfo())
			atual = atual->getesq();
		else if (x > atual->getinfo())
			atual = atual->getdir();
		else
			return atual;  // Valor encontrado
	}
	return NULL;  // Valor não encontrado
}


void tree::destroe(no *aux)
{
}

void tree::insere(int x) {
	no *novoNo = new no(x);
	if (arv == NULL) {
		arv = novoNo;
	} else {
		no *atual = arv;
		no *pai;
		while (true) {
			pai = atual;
			if (x < atual->getinfo()) {
				atual = atual->getesq();
				if (atual == NULL) {
					pai->setesq(novoNo);
					return;
				}
			} else {
				atual = atual->getdir();
				if (atual == NULL) {
					pai->setdir(novoNo);
					return;
				}
			}
		}
	}
}




void tree::preordem(no *aux)
    {
          if(aux!=NULL)
            {aux->lista();
            preordem(aux->getesq());
            preordem(aux->getdir());
            }


}

void tree::posordem(no *aux)
{
     	          if(aux!=NULL)
     	          {
	           	          posordem(aux->getesq());
	           	          posordem(aux->getdir());
	           	          aux->lista();
		          }
}

void tree::inordem(no *aux)
{
     	         if(aux!=NULL)
     	         {
	          	         inordem(aux->getesq());
	          	         aux->lista();
	          	         inordem(aux->getdir());
		         }
}

void tree::busca_remocao(int x)
{
      no *aux, *pai;
      pai=NULL;
      aux = arv;
      while(aux!=NULL && x!=aux->getinfo())
      {
           pai = aux;
           if (x<aux->getinfo())
           	 aux=aux->getesq();
           else
              aux=aux->getdir();
      }
      if(aux!=NULL)
          remove(aux, pai);
      else
         cout<<"Valor não encontrado na arvore";

}

void tree::remove(no *aux,no *pai)
{
     no *mm;
     if(aux->getdir()==NULL && aux->getdir()==NULL)
     {
            if (pai==NULL) // Pode ser Pai== ARV;.. pois pai é o primeiro no da arvore
              arv==NULL;
            else
               if(aux->getinfo() < pai->getinfo())
                  pai->setesq(NULL);
               else
                  pai->setdir(NULL);
            delete(aux);
      }
      else
      {
            if(aux->getdir()==NULL)
            {
                 if(pai==NULL)
                     arv=arv->getesq();
                 else
                     if(aux->getinfo() < pai-> getinfo())
                        pai->setesq(aux->getesq());
                     else
                        pai->setdir(aux->getesq());
                 delete(aux);
            }
            else
            if(aux->getesq()==NULL)
            {
                 if(pai == NULL)
	        arv = arv-> getdir();
                 else
                     if(aux->getinfo() < pai-> getinfo())
                        pai->setesq(aux->getdir());
                     else
                        pai->setdir(aux->getdir());
                 delete(aux);
	}
            else
           {
             pai = aux;
	mm = aux->getesq();
	while(mm->getdir()!=NULL)
	{
	    pai = mm;
	    mm = mm->getdir();
             }
             aux->setinfo(mm->getinfo());
             if(mm->getinfo() > pai->getinfo())
                   pai->setdir(mm->getesq());
             else
                  pai->setesq(mm->getesq());

           }
       }


}
//-------------------------------------------------------------
void tree::imprimearvore()
{
      stack<no*> globalStack;
      globalStack.push(arv);
      int nBlanks = 32;
      bool isRowEmpty = false;

      cout << "......................................................";
      cout << endl;
      while(isRowEmpty==false)
         {
         stack<no*> localStack;
         isRowEmpty = true;

         for(int j=0; j<nBlanks; j++)
            cout << ' ';

         while(globalStack.empty()==false)
            {
            no* temp = globalStack.top();
            globalStack.pop();
            if(temp != NULL)
               {
               cout << temp->getinfo();
               localStack.push(temp->getesq());
               localStack.push(temp->getdir());

               if(temp->getesq() != NULL ||  temp->getdir() != NULL)
                  isRowEmpty = false;
               }
            else
               {
               cout << "--";
               localStack.push(NULL);
               localStack.push(NULL);
               }
            for(int j=0; j<nBlanks*2-2; j++)
               cout << ' ';
            }  //end while globalStack não está vazio
         cout << endl;
         nBlanks /= 2;
         while(localStack.empty()==false)
            {
            globalStack.push( localStack.top() );
            localStack.pop();
            }
         }  //end-while isRowEmpty é falso
      cout << "......................................................";
      cout << endl;
}  //end displayTree()

void tree::decrescente( no* aux){
	      	      if(aux!=NULL)
	      	      {
		       	      decrescente(aux->getdir());
		       	      aux->lista();
		       	      decrescente(aux->getesq());
			      }
}
         int tree::soma(no *aux, int x){

         	        	 if(aux!=NULL){
		  x = soma(aux->getesq(), x);
		  x=x+aux->getinfo();
	            	 x= soma(aux->getdir(), x);



           }
           return x;

}

       int tree::qtdInfo(no *aux, int x){

           	         if(aux!=NULL){
		  x = qtdInfo(aux->getesq(), x);
		  x++;
	            	 x = qtdInfo(aux->getdir(), x);
		 }
return x;
}

int tree::qtdFolha(no *aux, int x)
{

	        if(aux!=NULL){
		  x = qtdFolha(aux->getesq(), x);
		 x = qtdFolha(aux->getdir(), x);
		 if(aux->getdir()==NULL && aux->getesq()==NULL)
		 x++;
		 }
return x;
}


void tree::menu()
{
    cout<<"\n\n########################### MENU ####################################";
    cout<<"\n#                                                                   #";
    cout<<"\n#            [ 1 ] Inserir                 [ 1 ]                    #";
    cout<<"\n#            [ 2 ] Remover                 [ 2 ]                    #";
    cout<<"\n#            [ 3 ] Consultar em Pre-Ordem  [ 3 ]                    #";
    cout<<"\n#            [ 4 ] Consultar em Pos-Ordem  [ 4 ]                    #";
    cout<<"\n#            [ 5 ] Consultar em In-Ordem   [ 5 ]                    #";
    cout<<"\n#            [ 6 ] Imprime                 [ 6 ]                    #";
    cout<<"\n#            [ 7 ] Consulta decrescente    [ 7 ]                    #";
    cout<<"\n#            [ 8 ] Somar                   [ 8 ]                    #";
    cout<<"\n#            [ 9 ] Quantidade de elementos [ 9 ]                    #";
    cout<<"\n#            [ 10] Quantidade de folhas    [ 10]                    #";
    cout<<"\n#            [ 0 ] Sair                    [ 0 ]                    #";
    cout<<"\n#                                                                   #";
    cout<<"\n#####################################################################";
}
*/

NoB::NoB(int _t, bool _folha) {
	t = _t;
	folha = _folha;

	// Reserva espaço para o número máximo de chaves e filhos possíveis
	chaves.resize(2*t-1);
	filhos.resize(2*t);
}

// Método para inserir uma chave em um nó não-cheio
void NoB::inserirNaoCheio(int k) {
    int i = chaves.size() - 1;

    if (folha) {
        // Encontra a localização da nova chave e move todas as chaves maiores um espaço à frente
        while (i >= 0 && chaves[i] > k) {
            chaves[i + 1] = chaves[i];
            i--;
        }

        // Insere a nova chave no local encontrado
        chaves[i + 1] = k;
    } else {
        // Encontra o filho que vai ter a nova chave
        while (i >= 0 && chaves[i] > k)
            i--;

        // Verifica se o filho encontrado está cheio
        if (filhos[i + 1]->chaves.size() == 2 * t - 1) {
            // Se o filho está cheio, então divide-o
            dividirFilho(i + 1, filhos[i + 1]);

            // Depois da divisão, o filho do meio de filhos[i] sobe e filhos[i] é dividido em dois.
            // Vê qual dos dois vai ter a nova chave
            if (chaves[i + 1] < k)
                i++;
        }
        filhos[i + 1]->inserirNaoCheio(k);
    }
}

// Método para dividir o filho y de um nó. i é o índice de y no vetor filho.
void NoB::dividirFilho(int i, NoB *y) {
    // Cria um novo nó que vai armazenar (t-1) chaves de y
    NoB *z = new NoB(y->t, y->folha);
    z->chaves.resize(t - 1);

    // Copia as últimas (t-1) chaves de y para z
    for (int j = 0; j < t - 1; j++)
        z->chaves[j] = y->chaves[j + t];

    // Copia os últimos t filhos de y para z, se y não for folha
    if (!y->folha) {
        z->filhos.resize(t);
        for (int j = 0; j < t; j++)
            z->filhos[j] = y->filhos[j + t];
    }

    // Reduz o número de chaves em y
    y->chaves.resize(t - 1);

    // Cria espaço para o novo filho
    filhos.insert(filhos.begin() + i + 1, z);

    // Move a chave do meio de y para este nó
    chaves.insert(chaves.begin() + i, y->chaves[t - 1]);

    // Remove a chave do meio de y, já que ela foi movida para o nó pai
    y->chaves.erase(y->chaves.begin() + t - 1);
}

// Método para percorrer todos os nós em uma subárvore enraizada com este nó
void NoB::percorrer() {
    // Há n chaves e n+1 filhos, percorre através de n chaves e os primeiros n filhos
    int i;
    for (i = 0; i < chaves.size(); i++) {
        // Se este não for folha, antes de imprimir chaves[i], percorre a subárvore enraizada com filho[i].
        if (!folha)
            filhos[i]->percorrer();
        cout << " " << chaves[i];
    }

    // Imprime a subárvore enraizada com o último filho
    if (!folha)
        filhos[i]->percorrer();
}

// Método para buscar uma chave na subárvore enraizada com este nó
NoB *NoB::buscar(int k) {
    // Encontra a primeira chave maior ou igual a k
    int i = 0;
    while (i < chaves.size() && k > chaves[i])
        i++;

    // Se a chave encontrada é igual a k, retorna este nó
    if (i < chaves.size() && chaves[i] == k)
        return this;

    // Se a chave não foi encontrada e este é um nó folha
    if (folha)
        return NULL;

    // Vai para o filho apropriado
    return filhos[i]->buscar(k);
}

// Método para inserir uma chave na árvore
void TreeB::inserir(int k) {
	// Se a árvore está vazia
	cout << "DEBUG 1 - raiz: " << raiz <<endl;
	if (raiz == NULL) {
		// Aloca memória para raiz
		raiz = new NoB(t, true);
		raiz->chaves[0] = k; // Insere chave
	} else {
		cout << "DEBUG 2 - raiz: " << raiz <<endl;
		// Se a raiz estiver cheia, então a árvore cresce em altura
		if (raiz->chaves.size() == 2 * t - 1) {
			cout << "DEBUG 3 - raiz cheia, arvore crescendo em altura"  <<endl;
			// Aloca memória para novo nó
			NoB *s = new NoB(t, false);

			// Torna a antiga raiz como filha do novo nó
			s->filhos[0] = raiz;

			cout << "DEBUG 4 - s->filhos[0]: " << s->filhos[0] <<endl;
			// Divide a antiga raiz e move uma chave para o novo nó
			s->dividirFilho(0, raiz);

			// A nova raiz tem dois filhos. Move a chave do meio de raiz para s. Decide qual dos dois filhos vai ter a nova chave e o insere
			int i = 0;
			if (s->chaves[0] < k)
				i++;
			s->filhos[i]->inserirNaoCheio(k);

			// Muda a raiz
			raiz = s;
			cout << "DEBUG 5 - raiz alterada: " << raiz <<endl;
		} else {
			cout << "DEBUG 6 - raiz nao ta cheia, inserir normal" <<endl;
			// Se a raiz não estiver cheia, chama inserirNaoCheio para a raiz
			raiz->inserirNaoCheio(k);
		}
	}
}

void TreeB::menu()
{
	cout<<"\n\n########################### MENU ####################################";
	cout<<"\n#                                                                   #";
	cout<<"\n#            [ 1 ] Inserir                 [ 1 ]                    #";
	cout<<"\n#            [ 2 ] Buscar                  [ 2 ]                    #";
	cout<<"\n#            [ 3 ] Percorerr				[ 3 ]                    #";
	cout<<"\n#            [ 0 ] Sair                    [ 0 ]                    #";
	cout<<"\n#                                                                   #";
	cout<<"\n#####################################################################";
}
