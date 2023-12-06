#include "funcoes.h"

//metodos classe no

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

// metodos da classe Btree

BTreeNode::BTreeNode(int _t, bool _leaf) {
	t = _t;
	leaf = _leaf;

	keys = new int[2 * t - 1];
	C = new BTreeNode *[2 * t];

	n = 0;
}

// Método para percorrer os nós
void BTreeNode::traverse() {
	// Implementação básica para percorrer e imprimir chaves
	int i;
	for (i = 0; i < n; i++) {
		if (!leaf)
			C[i]->traverse();
		cout << " " << keys[i];
	}

	if (!leaf)
		C[i]->traverse();
}

int BTreeNode::getKey(int idx) {
	if (idx >= 0 && idx < n) {
		return keys[idx];
	} else {
		// Lançar exceção ou tratar erro
	}
}

BTreeNode* BTreeNode::getChild(int idx) {
	if (idx >= 0 && idx <= n) {
		return C[idx];
	} else {
		// Lançar exceção ou tratar erro
	}
}

void BTreeNode::setKey(int idx, int key) {
	if (idx >= 0 && idx < n) {
		keys[idx] = key;
	} else {
		// Lançar exceção ou tratar erro
	}
}

void BTreeNode::setChild(int idx, BTreeNode* child) {
	if (idx >= 0 && idx <= n) {
		C[idx] = child;
	} else {
		// Lançar exceção ou tratar erro
	}
}

int BTreeNode::getNumKeys() {
	return n;
}

bool BTreeNode::isLeaf() {
	return leaf;
}

void BTree::insert(int k) {
	// Se a árvore está vazia
	if (root == nullptr) {
		root = new BTreeNode(t, true);
		root->keys[0] = k;  // Inserir chave
		root->n = 1;  // Atualizar número de chaves no nó
	} else {
		// Se o nó está cheio, ele deve ser dividido
		if (root->n == 2 * t - 1) {
			// Implementar a lógica de divisão aqui
		} else {
			// Inserir em um nó que não está cheio
			insertNonFull(root, k);
		}
	}
}

void BTree::splitChild(BTreeNode *node, int i) {
	BTreeNode *fullNode = node->C[i];
	BTreeNode *newNode = new BTreeNode(fullNode->t, fullNode->leaf);
	newNode->n = t - 1;

	// Copia as últimas (t-1) chaves de fullNode para newNode
	for (int j = 0; j < t - 1; j++) {
		newNode->keys[j] = fullNode->keys[j + t];
	}

	// Copia os últimos t filhos de fullNode para newNode, se não for folha
	if (!fullNode->leaf) {
		for (int j = 0; j < t; j++) {
			newNode->C[j] = fullNode->C[j + t];
		}
	}

	fullNode->n = t - 1; // Reduz o número de chaves em fullNode

	// Move os filhos de node para dar espaço ao novo filho
	for (int j = node->n; j >= i + 1; j--) {
		node->C[j + 1] = node->C[j];
	}

	// Linka o novo filho a node
	node->C[i + 1] = newNode;

	// Move as chaves de node para dar espaço à nova chave
	for (int j = node->n - 1; j >= i; j--) {
		node->keys[j + 1] = node->keys[j];
	}

	// Copia a chave do meio de fullNode para node
	node->keys[i] = fullNode->keys[t - 1];

	// Incrementa o número de chaves em node
	node->n = node->n + 1;
}

void BTree::insertNonFull(BTreeNode *node, int k) {
	int i = node->n - 1;

	if (node->leaf) {
		while (i >= 0 && node->keys[i] > k) {
			node->keys[i + 1] = node->keys[i];
			i--;
		}
		node->keys[i + 1] = k;
		node->n = node->n + 1;
	} else {
		while (i >= 0 && node->keys[i] > k) {
			i--;
		}

		// Verifica se o filho encontrado está cheio
		if (node->C[i + 1]->n == 2 * t - 1) {
			splitChild(node, i + 1);

			if (k > node->keys[i + 1]) {
				i++;
			}
		}
		insertNonFull(node->C[i + 1], k);
	}
}




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

