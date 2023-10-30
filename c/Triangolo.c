#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define n 5 //Il triangolo ha 5 livelli di array


struct s_Elenco{
    int array[5];   //La base della piramide ha 5 elementi, quindi il massimo degli elementi degli altri livelli sarà 5
};
typedef struct s_Elenco t_Elenco;


int Genera(t_Elenco Livello_Piramide[]);
int Sottrazione(int a, int b);
int Calcoli(t_Elenco Livello_Piramide[]);
void Visualizza_Calcoli(t_Elenco Livello_Piramide[]);
void Visualizza_Triagolo(t_Elenco Livello_Piramide[]);


int main()
{
    srand(time(NULL)); //Numeri causali sempre diversi ove inizializzazione
    int i;

    t_Elenco Livello_Piramide[5];

    for (i=0; i<5; i++)
    {
    Genera(Livello_Piramide);
    Calcoli(Livello_Piramide);
    Visualizza_Calcoli(Livello_Piramide);
    Visualizza_Triagolo(Livello_Piramide);
    printf("\n\n");
    }
}


//Funzione che genera numeri causali per un array di una struct
int Genera(t_Elenco Livello_Piramide[]){

    int i, j;

    for (i=0; i<n; i++){

    Livello_Piramide[0].array[i]=rand()%15+1; //Genera numeri casuali con un valore massimo prestabilito da 1 a 15
        for (j=0; j<i; j++){
            if (Livello_Piramide[0].array[i] == Livello_Piramide[0].array[j]){
            i--;
            }
        }
    }

}


//Funzione Sottrazione
int Sottrazione(int a, int b){

    int risultato;

    if (a>=b)
        risultato=a-b;
    else
        risultato=b-a;

return risultato;
}


//Funzione per calcolare gli altri elementi della piramide
int Calcoli(t_Elenco Livello_Piramide[]){

    int i;
    // Livello 0 sono i 5 numeri pseduocasuali

        //Calcolo Livello Piramide 1
    for (i=0; i<n-1; i++)
        Livello_Piramide[1].array[i]=Sottrazione(Livello_Piramide[0].array[i], Livello_Piramide[0].array[i+1]);


        //Calcolo Livello Piramide 2
    for (i=0; i<n-2; i++)
        Livello_Piramide[2].array[i]=Sottrazione(Livello_Piramide[1].array[i], Livello_Piramide[1].array[i+1]);

        //Calcolo Livello Piramide 3
    for (i=0; i<n-3; i++)
        Livello_Piramide[3].array[i]=Sottrazione(Livello_Piramide[2].array[i], Livello_Piramide[2].array[i+1]);

        //Calcolo Livello Piramide 4
        Livello_Piramide[4].array[0]=Sottrazione(Livello_Piramide[3].array[0], Livello_Piramide[3].array[1]);

}

//Visualizza i risultati del Calcolo
void Visualizza_Calcoli(t_Elenco Livello_Piramide[]){

    int i;

    printf("LIVELLO 0: ");
    for(i=0; i<n; i++)
        printf("%d ", Livello_Piramide[0].array[i]);

    printf("\nLIVELLO 1: ");
    for(i=0; i<n-1; i++)
        printf("%d ", Livello_Piramide[1].array[i]);

    printf("\nLIVELLO 2: ");
    for(i=0; i<n-2; i++)
        printf("%d ", Livello_Piramide[2].array[i]);

    printf("\nLIVELLO 3: ");
    for(i=0; i<n-3; i++)
        printf("%d ", Livello_Piramide[3].array[i]);

    printf("\nLIVELLO 4: ");
        printf("%d ", Livello_Piramide[4].array[0]);
}


void Visualizza_Triagolo(t_Elenco Livello_Piramide[]){

    printf("\n\n");
    int i;

    printf("                  %d            \n", Livello_Piramide[4].array[0]);
    printf("           %d           %d         \n", Livello_Piramide[3].array[0], Livello_Piramide[3].array[1]);
    printf("        %d         %d        %d      \n", Livello_Piramide[2].array[0], Livello_Piramide[2].array[1], Livello_Piramide[2].array[2]);
    printf("     %d       %d        %d       %d   \n", Livello_Piramide[1].array[0], Livello_Piramide[1].array[1], Livello_Piramide[1].array[2], Livello_Piramide[1].array[3]);
    printf(" %d      %d        %d        %d      %d\n", Livello_Piramide[0].array[0], Livello_Piramide[0].array[1], Livello_Piramide[0].array[2], Livello_Piramide[0].array[3], Livello_Piramide[0].array[4]);
    printf("\n");
}

