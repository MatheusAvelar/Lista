#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAXTAM=10;

class TipoLista // Classe Lista com vetor
{	
   private:
      string Item [MAXTAM];
      int Primeiro, Ultimo, Quantos;
      
   public:
      TipoLista (void);
      int Vazia (void);
      int Tamanho (void);
      void Inserir (string Elemento); // no fim
      void Inserir (string Elemento, int Posicao);
      void Retirar (string Elemento); // do inicio
      void Retirar (int Posicao);
      void Listar ();
}; // fim classe TipoLista

TipoLista :: TipoLista(void) //construtorpadrão
{ Primeiro = Ultimo = Quantos = 0; }
//**********************************************
int TipoLista :: Vazia(void)
{ return(Primeiro == Ultimo); }
//**********************************************
int TipoLista :: Tamanho(void)
{ return(Quantos); }
//**********************************************
void TipoLista :: Inserir(string Elemento)
{
   if (Ultimo >= MAXTAM)
      cout << "Lista cheia. \n";
   else {
      Item[Ultimo++] = Elemento;
      Quantos++;
   }
   return;
}
//**********************************************
void TipoLista :: Inserir (string Elemento, int Posicao)
{
   if (Ultimo >= MAXTAM)
      cout << "Lista cheia. \n";
   else {
      //A partir da posição informanda, jogo todos os elementos um posição para
      //trás e depois coloco o elemento informado na posição solicitada.
      for(int i = Ultimo; i >= Posicao; i--){
          Item[i+1] = Item[i];
      }
   }        
   Item[Posicao] = Elemento;
   Ultimo++;
   Quantos++;
   return;
}
//***********************************************
void TipoLista :: Retirar(string Elemento)
{
   if (Vazia( ))
      cout << "Lista vazia. \n";
   else {
      Elemento = Item[Primeiro];
      Ultimo--;
      Quantos--;
      for (int i = Primeiro; i < Ultimo; i++)
           Item[i] = Item[i+1];
   }
}
//**********************************************
void TipoLista :: Retirar (int Posicao)
{
   //A partir da posição informanda, jogo todos os elementos um posição para
   //frente.    
   if (Vazia( ))
      cout << "Lista vazia. \n";
   else {
      Ultimo--;
      Quantos--;
      for (int i = Posicao; i < Ultimo; i++){
           Item[i] = Item[i+1];
      }
   }
}
void TipoLista :: Listar ()
{	
	system("cls");
	if(Vazia())
	cout<<"Lista Vazia. \n";
	else{
		for(int i=0; i<Ultimo; i++){
			cout<<Item[i]<<" esta na posicao " << i << endl;
		}
	}
	system("pause");
}
int main(){
    int opcao, posicaoAdd, posicaoRemv;
    string elemento;
    TipoLista lista;
   	do{
   		system("cls");
        cout << " 1 - Inserir\n";
        cout << " 2 - Retirar\n";
        cout << " 3 - Inserir em determinada posicao\n";
        cout << " 4 - Retirar determinada posicao\n";
        cout << " 5 - Mostrar elementos\n";
        cout << "  ======================================\n";
        cout << "  Selecione uma opcao: ";
        cin >> opcao;
        cout << endl;
	
    //Adicionando elemtos na lista
    if(opcao==1){
		cout << "== Adicione um determinado elemento na lista ==" << endl;
		cout<<"Digite um elemento:\n";
	    cin>>elemento;
	    lista.Inserir(elemento);
		lista.Listar();	
	}
    //Removendo os elementos da lista
    if(opcao==2){
	    cout << "== Remove elemento na lista ==" << endl;   
	    lista.Retirar(elemento);
		lista.Listar();	
    	system("pause");
	}    
	
    //Adicionando elementos na segunda posicao da lista
    if(opcao==3){
		cout << "== Inserir em determinada posicao ==" << endl;
		cout<<"Digite uma posicao:\n";
		cin>>posicaoAdd;  
		cout<<"Digite um elemento para esta posicao:\n";
	    cin>>elemento;
		lista.Inserir(elemento,posicaoAdd);
		lista.Listar();	
    	system("pause");
	} 
	
    //Removendo os elementos da lista
    if(opcao==4){
	    cout << "== Retirar determinada posicao ==" << endl;
		cout<<"Digite uma posicao:\n";
		cin>>posicaoRemv; 	        
	    lista.Retirar(posicaoRemv);
		lista.Listar();	
		system("pause");
	}
	//Mostra os elementos da lista
	if(opcao==5){
		lista.Listar();
		system("pause");	
	}
	}while (opcao!=5);
	
	system("pause");
    return 0;

}

