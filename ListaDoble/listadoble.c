#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct info{
	int dni;
	char sexo;
	char *nombre;
	
};

struct nodo{
	struct nodo *psig;
	struct nodo *pant;
	struct info *Info;
};

int InsertarNodo (struct nodo **,struct info *);
int MostrarLista (struct nodo *);
struct info * GenerarNodo(int,char,char *);

int main (){
	srandom(time(NULL));
	struct nodo *pinicio = 0 ;
	int i=0;


	for(i=5;i>0;i--)
	{
	printf("Ingrese numero\n");	
	InsertarNodo(&pinicio,GenerarNodo(random()%100,'M',0));
	}
	printf("lista llena\n");
	MostrarLista(pinicio);
	
	
	
	return 0;
}

int InsertarNodo (struct nodo **Pini,struct info *dato){
	struct nodo *aux = *Pini  ;
	struct nodo *aux2=*Pini;
	

	if(*Pini == NULL ){
			//printf("Lista vacia\n");
		//si entro a este if es por que la lista esta vacia
		//pinicio = malloc (sizeof(struct nodo));
			(*Pini) =(struct nodo *) malloc (sizeof(struct nodo));
			//El anterior de lista
			(*Pini)->psig = NULL;// apuntamos el siguiente a NULL	
			(*Pini)->pant = NULL;//El anterior de lista APUNTA a NULL
			(*Pini)->Info = dato;
			return 0 ;
	}	else{ //la lista no esta vacia
			//printf("La lista no esta vacia\n");
			//printf("%p\n",aux);
			while((aux!=NULL)&&((aux->Info->dni) > (dato->dni)))
			{	
			aux2=aux;
			aux=(aux->psig);
			//printf("en el while %p\n",aux);	
			}
			
			if(aux==*Pini)
			{
			printf("aux==*Pini\n");
			(*Pini)->pant=(struct nodo *) malloc (sizeof(struct nodo));
			((*Pini)->pant)->psig=(*Pini);//FIXEDerror era que pisabamos al siguiente
			((*Pini)->pant)->pant=NULL;
			(*Pini)=(*Pini)->pant;
			((*Pini)->Info)=dato;
			}else
			{
				aux2->psig=(struct nodo *) malloc (sizeof(struct nodo));
				if(aux!=NULL)//se compara con NULL para ver si es el ultimo elemento de lista
				{					
					aux->pant=aux2->psig;
				}
				(aux2->psig)->psig=aux;//cuando se agrega nodo al final, aux=NULL
				(aux2->psig)->pant=aux2;
				(aux2->psig)->Info=dato;
			}
		
	}
	

	
	return 0;
}
int MostrarLista (struct nodo *ini){
	
	int num;
	struct nodo *aux;
	
	while (ini != NULL)//se recorre la lista en sentido directo
	{
		printf("%d %c %s\n",ini->Info->dni ,ini->Info->sexo ,ini->Info->nombre );
		aux=ini;
		printf("ant: %p\nini: %p \n", ini->pant, ini );
		ini = ini->psig;
		
	}
	printf("recorre lista\n");
	while(aux != NULL)//se recorre la lista en sentido inverso
	{
		printf("%d %c %s\n",aux->Info->dni, aux->Info->sexo, aux->Info->nombre );
		aux=aux->pant;
		printf("aux: %p\n", aux);
	}
	return 0;
 }
	
struct info * GenerarNodo(int gdni,char gsexo,char * gnombre)
{	
	struct info * datoaux;
	datoaux=(struct info *)malloc(sizeof(struct info));
	datoaux->dni=gdni;
	datoaux->sexo=gsexo;
	datoaux->nombre="nombre";
	return (datoaux);
}

