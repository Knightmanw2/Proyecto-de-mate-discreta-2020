/*  PROYECTO FINAL MATEMATICA DISCRETA C++
	Sergio Alejandro Argueta Castillo 
	0901-18-17865 */
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include <iomanip>

using namespace std;

//funciones 1er PROYECTO --------------------1--------PERMUTACIONES Y COMBINACIONES
void perep(){
	long double n,r,respuesta;
	cout<<"\n\n\tPERMUTACIONES CON REPETICION"<<endl;    
	cout<<"\tIngrese el numero 'n' el cual es el numero de cosas que puede elegir"<<endl;
	cout<<"\n\t";	cin>>n;		
	cout<<"\n\n\tIngrese el numero 'r' que sera cuantas eligio de "<<n<<endl;
	cout<<"\n\t"; cin>>r;
	respuesta=(pow(n,r));	
	cout<<"\n\tLa respuesta de la permutacion con repeticion es "<<respuesta<<endl;
		system("pause");
		system("cls");
}

void pesinRE(){
	int repop;
	cout<<"\n\n\tPERMUTACIONES SIN REPETICION"<<endl; 
	cout<<"\n\t---1---Ingrese 1 si es de un tipo de permutacion sin repeticion"<<endl;
    cout<<"\t---2---Ingrese cualquier otro numero si es mas de un tipo de permutacion sin repeticion"<<endl;
    cout<<"\n\t";	cin>>repop;
    	system("pause");
	 	system("cls");	
	switch(repop){
		case 1:{
			long double n,n2,r,factorial=1,factorial2=1;
			cout<<"\n\n\tPermutaciones sin repeticion de un tipo"<<endl;
			cout<<"\tIngrese el numero 'n' el cual se le sacara factorial en el numerador\n"<<endl; 
			cout<<"\t"; cin>>n;
					cout<<"\n\tIngrese el numero 'r' el cual se le restara a "<<n<<" en el denominador\n"<<endl; 
					cout<<"\t"; cin>>r;
					for(int i=1;i<=n;i++){
						factorial = factorial * i;
					}
					n2=n-r;
					for(int i=1;i<=n2;i++){
						factorial2 = factorial2 * i;
					}					
					factorial=factorial/factorial2;
		 			cout<<"\n\tEl numero es "<<factorial<<endl; 
					system("pause");
					system("cls");		 			
			break;
		}
		case 2:{
			cout<<"\n\n\tPermutaciones sin repeticion de mas de un tipo"<<endl;
			long double res=1,fact=1,numerador,respfinal;
			int x;	
				cout<<"\n\tIngrese el numerador n"<<endl;
					cout<<"\t"; cin>>numerador;
					for(int ite=1;ite<=numerador;ite++){
						fact=fact*ite;
					}
					cout<<"\n\tEl facotorial del numerador es "<< fact<<endl;
				cout<<"\n\tIngrese el numero de ns"<<endl;
				cout<<"\t"; cin>>x;
				long double num[x];
				for(int i=0;i<x;i++){
					cout<<"\tIngrese la "<<i+1<<" n"<<endl;
					cout<<"\t"; cin>>num[i];
				}
				for(int i=0;i<x;i++){
					for(int j=1;j<=num[i];j++){
						res*=j;			
					}	
				}
				respfinal=fact/res;						
				cout<<"\n\tLa permutacion sin repeticion de mas de un tipo es "<< respfinal<<endl;
			system("pause");		
			system("cls");
			break;
		}
	}
}

void combRE(){
	long double n,r,factorial=1,fact1=1,fact2=1,ene1,resultado,resul,respuesta;
	cout<<"\n\n\tCOMBINACIONES CON REPETICION"<<endl; 
	cout<<"\n\tIngrese el numero 'n' del numerador que sera la cantidad de objetos"<<endl;				
		cout<<"\t"; cin>>n;
		cout<<"\n\tIngrese el numero 'r' el cual se le sumara a "<<n<<" en el numerador"<<endl; 
		cout<<"\n\t 'r' seran los elementos u objetos a los que se hace referencia\n"<<endl;
			cout<<"\t"; cin>>r;					
				ene1=n+r-1;	
				for(int i=1;i<=ene1;i++){
					factorial = factorial * i;
				}
				for(int i=1;i<=r;i++){
					fact2 = fact2 * i;
				}
				resultado=(n-1);				
										
				for(int i=1;i<=resultado;i++){
					fact1 = fact1 * i;
				}							
				respuesta=fact2*fact1;								
				resul=factorial/respuesta;
				cout<<"\n\tLa combinacion con repeticion es "<<resul<<endl; 
		system("pause");		
		system("cls");										
}

void combsiRE(){
		long double n,r,factorial=1,fact2=1,fact3=1,respuesta,resultado,resul; 
		cout<<"\n\n\tCOMBINACIONES SIN REPETICION"<<endl; 
			cout<<"\n\tIngrese el numero 'n' del numerador que sera la cantidad de objetos"<<endl;			
				cout<<"\t";	 cin>>n;
			cout<<"\n\tIngrese el numero 'r' seran los elementos u objetos a los que se hace referencia\n"<<endl; 
				cout<<"\t"; cin>>r;					
					for(int i=1;i<=n;i++){
						factorial = factorial * i;
					}
					for(int i=1;i<=r;i++){
						fact2 = fact2 * i;
					}					
					respuesta=(n-r);	
					for(int i=1;i<=respuesta;i++){
						fact3 = fact3 * i;
					}
					resultado=fact2*fact3;				
					resul=factorial/resultado;
		 	cout<<"\n\tLa combinacion sin repeticion es "<<resul<<endl; 
		system("pause");		
		system("cls");
}

//funciones 2do PROYECTO --------------------2--------Arboles binarios

struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *AB;

AB crearNodo(int x)
{
     AB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(AB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void anchura(AB arbol)
{
     if(arbol!=NULL)
     {   	
     	  anchura(arbol->der);
     	  cout << arbol->nro <<" ";
     	  anchura(arbol->izq);                		     
     }
}

void preOrden(AB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(AB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

void postOrden(AB arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

void verArbol(AB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<<arbol->nro<<endl;

     verArbol(arbol->izq, n+1);
}

void arboles(){
		cout<<"\n\nPROYECTO ARBOLES BINARIOS RECORRIDOS"<<endl;
		AB arbol = NULL;
		int n,x; 
		cout<<"\nIngrese el numero total de nodos"<<endl;
			cin>>n;  cout<<endl;			
			    for(int i=0; i<n; i++)
			    {
			        cout<<"Numero del nodo " << i+1 << ": ";
			        cin>>x;
			        insertar( arbol, x);
			    }			
			    cout<<"\nMostrando ARBOL BINARIO"<<endl;
			    verArbol( arbol, 0);			
			    cout<<"\nRecorridos del ARBOL BINARIO"<<endl;
			    
				cout<< "\n\nAchura     :  ";   anchura(arbol);
			    cout<< "\n\nEn orden   :  ";   enOrden(arbol);
			    cout<< "\n\nPre Orden  :  ";   preOrden(arbol);
			    cout<< "\n\nPost Orden :  ";   postOrden(arbol);
			
			    cout<<endl<<endl;
			
		system("pause");
		system("cls");
}

//funciones 3er PROYECTO --------------------3--------Triangulo de Pascal

const int tam=15;
int draw=58,nivel=0; int matriz[tam][tam+1];

void triangulo_pascal(){
	for(int i=0;i<nivel;i++)
		{
			 matriz[i][0] = 1;
			 matriz[i][i+1] = 1;
				cout << "\n\n" << setw(draw-i*4);
			for(int j=0;j<i+2;j++)
			{
				matriz[i+1][j+1] = matriz[i][j] + matriz[i][j+1];
					cout << matriz[i][j] << setw(8);
			}
		}
}

//funciones 4to FINAL PROYECTO --------------------4--------INDUCCION MATEMATICA
int Euclides(int, int);

void producto(){
	int x;
	cout<<"\n\n\tPRODUCTO DE FACTORES PRIMOS"<<endl;
	do{
		cout<<"\n\n\tIngrese un numero"<<endl;
		cout<<"\n\t"; cin>>x;
	}while(x<=0);	
				cout<<"\n\tLos factores son:\n\t";
				for(int i=2;1<x;i++){ 
					while(x % i == 0){ 
					cout<<i;
					x/=i;
					if(1<x)
					cout<<"*";	}	 						
				}			
				cout<<"\n\n\t"<<endl;	
	system("pause");
	system("cls");
}

void MCD(){
	int numeros,n,mcd,resi;
	cout<<"\n\n\tMAXIMO COMUN DIVISOR"<<endl;
	do{
		cout<<"\n\n\tIngrese la cantidad de numeros a los que sacara el maximo comun divisor"<<endl;
		cout<<"\n\t";	cin>>numeros;	
	}while(numeros<=0);	
	for(int i=0;i<numeros;i++){
		do{
			cout<<"\n\tIngrese el "<<i+1<<" numero"<<endl;
			cout<<"\n\t"; cin>>n;
		}while(n<=0);
		if(i==0){
			mcd=n;
		}
		do{		
			resi=mcd%n;			
			mcd=n;
			n=resi;
		}while(resi!=0);
	}
	cout<<"\n\tEl mcd de los numeros es: "<<mcd<<endl;
	system("pause");
	system("cls");
}

void division(){
	int a,b,q,pr,r,res;	
	cout<<"\n\n\tALGORITMO DE LA DIVISION"<<endl;	
	cout<<"\n\n\tIngrese un dividendo a"<<endl;
		cout<<"\n\t";	cin>>a;
	cout<<"\n\n\tIngrese un divisor b"<<endl;
		cout<<"\n\t";	cin>>b;		
	res=a%b; 
	q=a/b;	
	 if(res!=0){
	 	pr=q*b;
		r=a-pr;	
		cout<<"\n\n\t a = bq + r"<<endl; 
		cout<<"\n\n\t"<<a<<" = "<<"("<<b<<" * "<<q<<")"<<" + "<<r<<endl;
	 }
	 else{
	 	q-=res;
	 	pr=q*b;	
		r=a-pr;	
		cout<<"\n\n\t a = bq + r"<<endl;
		cout<<"\n\n\t"<<a<<" = "<<"("<<b<<" * "<<q<<")"<<" + "<<r<<endl;
	 }		
	 cout<<"\n\n\t";
	system("pause");
	system("cls");
}

void euclides(){
	int a,b;
    char opc;
   	cout<<"\n\n\tALGORITMO DE EUCLIDES"<<endl;
        cout<<"\n\n\tIngrese un dividendo"<<endl;
		cout<<"\n\t";
            cin>>a;
        cout<<"\n\n\tIngrese un divisor"<<endl;
		cout<<"\n\t";
            cin>>b;
        if(b<0){
            b=-b;
        }
        if(a<0){
            a=-a; 
        }
        if(b>a){ 
            int aux; 
            aux=a;  
            a=b;	
            b=aux;	
        }
        cout<<"\n\n\tEl maximo comun divisor es: "<<Euclides(a,b); 
		cout<<"\n\n\t"; 
		system("pause");
		system("cls");   
}

int Euclides(int a, int b){
    if(b==0){ 
        return a; 
    }
    else{ 
        return Euclides(b,a%b);
    }
}

void inicio(){
	cout<<"\n\n\tUNIVERSIDAD MARIANO GALVEZ"<<endl;
	cout<<"\tcurso: Matematica Discreta"<<endl;
	cout<<"\n\n\tIng. Bettina Ardiano"<<endl;
	cout<<"\n\n\tNombre: Sergio Alejandro Argueta Castillo"<<endl;
	cout<<"\tCarnet: 0901-18-17865"<<endl;
	cout<<"\n\n";
	system("pause");
	system("cls");
}

//CUERPO DEL PROYECTO -------------------------------------------MENU PRINCIPAL----------------------------------------------------------------------

int main(int argc,char**argv){
int opcMP,opcPECO,opcARB,opcTRI,opcIND;
inicio();
cout<<"\n\n\tBienvenido al Proyecto final"<<endl;
do{
	cout<<"\n\n\tPROYECTO FINAL MATEMATICA DISCRETA"<<endl;	
	cout<<"\n\tMENU PRINCIPAL"<<endl;
	cout<<"\n\n\t--1--PROYECTO PERMUTACIONES Y COMBINACIONES"<<endl;
	cout<<"\t--2--PROYECTO RECORRIDOS DE ARBOLES"<<endl;
	cout<<"\t--3--PROYECTO TRIANGULO DE PASCAL"<<endl;
	cout<<"\t--4--PROYECTO INDUCCION MATEMATICA"<<endl;
	cout<<"\t--5--SALIR DEL PROGRAMA"<<endl;
	cout<<"\n\t"; cin>>opcMP;
	system("pause");
	system("cls");
	switch(opcMP){
		case 1:{			
			cout<<"\n\n\tBienvenido"<<endl;	
			do{
				cout<<"\n\n\tPROYECTO PERMUTACIONES Y COMBINACIONES"<<endl;	
				cout<<"\n\n\t---1---PERMUTACIONES CON REPETICION"<<endl;
				cout<<"\t---2---PERMUTACIONES SIN REPETICION"<<endl;
				cout<<"\t---3---COMBINACIONES CON REPETICION"<<endl;	
				cout<<"\t---4---COMBINACIONES SIN REPETICION"<<endl;
				cout<<"\t---5---VOLVER AL MENU PRINCIPAL"<<endl;
				cout<<"\n\t"; cin>>opcPECO;	
					system("pause");
					system("cls");
				switch(opcPECO){
					case 1:
						perep();
						break;				
					case 2:
						pesinRE();
						break;
					case 3:
						combRE();
						break;
					case 4:
						combsiRE();
						break;
					case 5:
					cout<<"\n\tVolviendo..."<<endl;							
						break;
					default:
					cout<<"\n\tIngrese una opcion correcta"<<endl;	
						system("pause");
						system("cls");					
						break;
				}
			}while(opcPECO!=5);
			system("pause");
			system("cls");
			break;
		}
		case 2:{
			arboles();			
			break;
		}
		case 3:{
			cout<<"\n\nPROYECTO TRIANGULO DE PASCAL"<<endl;
				cout<<"Ingrese un nivel del 1 al 15\n\n";
				while(cout << ("Ingrese Nivel: "),cin >>(nivel),nivel<1|nivel>tam);
				triangulo_pascal();
				cout<<"\n\n";
			system("pause");
			system("cls");
			break;
		}
		case 4:{
				cout<<"\n\tBienvenido"<<endl;
				do{
				cout<<"\n\n\tPROYECTO INDUCCION MATEMATICA"<<endl;	
				cout<<"\n\t---1---PRODUCTO DE FACTORES PRIMOS"<<endl;
				cout<<"\t---2---MAXIMO COMUN DIVISOR"<<endl;
				cout<<"\t---3---ALGORITMO DE LA DIVISION"<<endl;
				cout<<"\t---4---ALGORITMO DE EUCLIDES"<<endl;
				cout<<"\t---5---VOLVER AL MENU PRINCIPAL"<<endl;
				cout<<"\n\n\t";	cin>>opcIND;
				cout<<"\n\n\t";
				system("pause");
				system("cls");	
					switch(opcIND){
						case 1:
							producto();				
							break;
						case 2:
							MCD();
							break;
						case 3:
							division();
							break;
						case 4:
							euclides();				
							break;
						case 5:
							cout<<"\n\tVolviendo..."<<endl;	
							break;
						default:
							cout<<"\n\n\tIngrese una opcion valida\n\n\t"<<endl;
							system("pause");
							system("cls");
							break;
					}		
				}while(opcIND!=5);
			break;
		}
		case 5:
			cout<<"\ncerrando programa\n\n";
			system("pause");
			system("cls");
			break;
		default:
			cout<<"\n\tIngrese una opcion correcta"<<endl;
			system("pause");
			system("cls");
			break;		
	}
}while(opcMP!=5);
}
