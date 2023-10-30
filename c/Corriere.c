#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define max_tir 100


struct s_tir{

    char targa[10];
    char modello[20];
    int capacita_tir; //Capienza del tir
    char cod_oggetto[100][100];
    int peso_oggetto[100]; //Peso oggetto singolarmente
    int tot_peso; //Peso totale degli oggetti
    int quantita_oggetti; //Quantità oggetti nel tir
    char nome_destinatario[15];
    char cognome_destinatario[15];
    char nome_mittente[15];
    char cognome_mittente[15];
    int uso_tir; //Tir utilizzato o no

};
typedef struct s_tir t_tir;


int inizializzazione_struct(t_tir tir[], int n_tir);
int carica_tir(t_tir tir[], int n_tir);
int invia_oggetto(t_tir tir[], int n_tir);
void visualizza_camion(t_tir tir[], int n_tir);
void visualizza_peso_massimo(t_tir[], int n_tir);
void ordina_peso_tir(t_tir tir[], int n_tir);
void menu();


int main()
{
    t_tir tir[100];
    char scelta;
    int n_tir;



    printf("Prima di iniziare...\n\n");

    do{
    printf("inserisci la quantita dei camion che vuoi utilizzare: ");
    scanf("%d", &n_tir);
    }while(n_tir<=0 || n_tir>100);
     carica_tir(tir, n_tir);

    system("cls");

    do{
    menu();
    printf("Inserire una scelta [1 - 5] : ");
    scanf(" %c", &scelta);

    switch(scelta){

        case '1':
         invia_oggetto(tir, n_tir);
            break;

        case '2':
            visualizza_camion(tir, n_tir);
            break;

        case '3':
            visualizza_peso_massimo(tir, n_tir);
            break;

        case '4':
                ordina_peso_tir(tir, n_tir);
            break;

        case '5':
            return 0;
            break;

        default:
            printf("ATTENZIONE, SCELTA SBAGLIATA!\n");
            system("pause");
            break;

        }

    }while(scelta!='5');
return 0;
}


void menu()
{
        system("cls");
        printf("----Benvenuto nel menu' di scelta del corriere espresso!----\n\n");
        printf("1) AGGIUNGI OGGETTO SUL TIR \n");
        printf("2) VISUALIZZA ELEMENTI PRESENTI NEL TIR \n");
        printf("3) RICERCA CAMION CON  OGGETTO PESO MASSIMO \n");
        printf("4) ORDINAMENTO IN ORDINE CRESCENTE DEGLI OGGETTI SUL TIR \n");
        printf("5) ESCI\n\n");

}


int inizializzazione_struct(t_tir tir[], int n_tir)//Inizializzaine di uso tir, del peso totale e la quantita oggetti nei tir
{
        int i;

        for (i=0; i<n_tir; i++){
            tir[i].uso_tir=0;
            tir[i].tot_peso=0;
            tir[i].quantita_oggetti=0;
        }

}

int carica_tir(t_tir tir[], int n_tir) //un for per inserire targa modello e capacita trasportabile del tir
{
    int i;

    printf("\nOra dovrai inserire informazioni dei tuoi tir utilizzati\n");
    printf("Inseriremo Targa, Modello del tir e capacita' del tir\n\n");

        for(i=0; i<n_tir; i++){
            printf("CAMION NUMERO %d\n", i );
        printf("Inserisci targa: ");
        scanf("%s", tir[i].targa);
        printf("Inserisci modello: ");
        scanf("%s", tir[i].modello);
        printf("Inserisci capacita' kg: ");
        scanf("%d", &tir[i].capacita_tir);
        printf("\n");

}
 system("pause");
}


int invia_oggetto(t_tir tir[], int n_tir)//Utilizzeremo un tir selezionato, inserendo informazioni degli oggetti da inviare
{
    int i, j, temp_oggetto;
    char risposta;

    printf("\nInseriremo quale tir utilizzare, nome e cognome del mittente e del destinartario\n");
    printf("Successivamente penseremo a inviare gli oggetti\n\n");
    do{
        printf("Inserisci tir da utilizzare [ 0 - %d ]: ", n_tir-1);
    scanf("%d", &i);
    }while(i<0 || i>n_tir);

    if(tir[i].uso_tir!=1)
    {
    printf("\nInserisci nome mittente: ");
    scanf("%s", tir[i].nome_mittente);
    printf("Inserisci cognome mittente: ");
    scanf("%s", tir[i].cognome_mittente);
    printf("\nInserisci nome destinatario: ");
    scanf("%s", tir[i].nome_destinatario);
    printf("Inserisci cognome destinatario: ");
    scanf("%s", tir[i].cognome_destinatario);
    }

    do{
            printf("\nPeso kg oggetto da inviare: ");
            scanf("%d", &temp_oggetto);

            if(tir[i].tot_peso+temp_oggetto<=tir[i].capacita_tir){
                j=tir[i].quantita_oggetti;
                printf("Inserisci codice oggetto (ES: 1101): ");
                scanf("%s", tir[i].cod_oggetto[j]);
                tir[i].peso_oggetto[j]=temp_oggetto;                         //semplici istruzione da passare a informazione temporane a salvate
                tir[i].tot_peso=tir[i].tot_peso+tir[i].peso_oggetto[j];
                tir[i].quantita_oggetti++;
                tir[i].uso_tir=1;
                }
                else
                {
                    printf("\nSpazio insufficiene");
                    printf("\nHai disponibile solo: %d kg di spazio", tir[i].capacita_tir-tir[i].tot_peso);
                }
                printf("\nVuoi continuare a inviare oggetti? ( y - n ) : ");
                scanf(" %c", &risposta); //Qui ho trovato un bug di compilatore che non capisco il perchè, se non metto lo spazio prima del %c mi da problemi di input

     }while(risposta!='n' );
      system("pause");
    }




void visualizza_camion(t_tir tir[], int n_tir){//Visualizzamento degli oggetti presenti nel camion

    int i, j;
    do{
    printf("\nInserisci tir da visualizzare [ 0 - %d ]: ", n_tir-1);
    scanf("%d", &i);
    }while(i<0 || i>n_tir);

            printf("\nOGGETTI DEL TIR %d", i);
            for(j=0; j<tir[i].quantita_oggetti; j++){
            printf("\nCodice oggetto: %s", tir[i].cod_oggetto[j]);
            printf("\nPeso oggetto: %d", tir[i].peso_oggetto[j]);
            printf("\n");

}

        system("pause");
}


void visualizza_peso_massimo(t_tir tir[], int n_tir)//Trova il tir che contiene l'oggetto piu' pesante
{
        int i, j, oggetto_max, numero_tir, numero_oggetto;
        char cod_max[100];
        oggetto_max=0;
        for (i=0; i<n_tir; i++){
            for(j=0; j<tir[i].quantita_oggetti; j++){
                if (tir[i].peso_oggetto[j]>oggetto_max){
                    oggetto_max=tir[i].peso_oggetto[j];
                    strcpy(cod_max, tir[i].cod_oggetto[j]);
                    numero_tir=i;
                    numero_oggetto=j;

                }
                    }}

                    printf("\n\nMassimo peso oggetto si trova nel tir numero %d", numero_tir);
                    printf("\nPESO: %d \nCODICE: %s\nNUMERO OGGETTO: %d", oggetto_max, cod_max, numero_oggetto);
                     system("pause");
}



void ordina_peso_tir(t_tir tir[], int n_tir) //Ordina gli oggetti nel tir selezionato in modo crescente di peso
{
    int i, j, k, temp_peso;
    char temp_cod[100];

    do{
        printf("\n\nInserisci tir da utilizzare [ 0 - %d ]: ", n_tir-1);
    scanf("%d", &i);
    }while(i<0 || i>n_tir);

    for(j=0; j<tir[i].quantita_oggetti-1; j++)
    {
        for(k=j+1; k<tir[i].quantita_oggetti; k++)
        {
            if(tir[i].peso_oggetto[j]>tir[i].peso_oggetto[k])
            {
                temp_peso=tir[i].peso_oggetto[j];
                tir[i].peso_oggetto[j]=tir[i].peso_oggetto[k];
                tir[i].peso_oggetto[k]=temp_peso;

                strcpy(temp_cod, tir[i].cod_oggetto[j]);
                strcpy(tir[i].cod_oggetto[j], tir[i].cod_oggetto[k]);
                strcpy(tir[i].cod_oggetto[k], temp_cod);
            }

        }

    }

    printf("\nLista oggetti del tir numero %d in ordine crescente", i);
    for(j=0; j<tir[i].quantita_oggetti; j++){
        printf("\n\nCODICE: %s \nPESO: %d", tir[i].cod_oggetto[j], tir[i].peso_oggetto[j] );
    }
system("pause");
}
