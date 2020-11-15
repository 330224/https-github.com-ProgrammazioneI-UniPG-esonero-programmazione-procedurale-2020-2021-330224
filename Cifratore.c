#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//VARIABILI.
int i;




char testodatastiera_M [128];
char chiavecifratura_K [128];
char chiavedatastiera_K[128];
char cipher_C[128];
char decrypter_C[128];



int scelta;
int scelta1;



int lunghezza_M;
int lunghezza_K;






int main(void){

                                    //TESTO DA TASTIERA [PLAINTEXT].
    printf("------------------ALGORITMO DI CIFRATURA---------------------\n");
    printf("\n\n###-IMMETTERE UNA FRASE CON NON PIU' DI [128] CARATTERI.-### \n");
       do{
         fgets(testodatastiera_M, 128, stdin);
           lunghezza_M = strlen(testodatastiera_M);
             printf("La lunghezza della frase e': %d\n", lunghezza_M);
  }
       while (lunghezza_M > 128);
         printf("La frase immessa e' : %s\n", testodatastiera_M);
       if(lunghezza_M > 126){
             printf("##ERRORE## :\n.Frase troppo lunga\n");
               return 0;
  }
       else
          printf("Procediamo con la creazione di una Chiave?\n");


                                     //MENU' CREAZIONE DI UNA CHIAVE
printf("1. SI\n");
printf("0. NO\n");
do{
  printf("scelta: ");
   scanf("%d",&scelta1); getchar();
  switch (scelta1) {
                                    //MENU' SCELTA TIPO DI CHIAVE

    case 1: printf("PROCEDIAMO!\n");
    printf("\n------------------MENU' CHIAVE CIFRATURA---------------------\n");
     printf("\nDigita[1],[2],[0] da tastiera per effettuare una scelta :\n");
      printf("\n1. Chiave di cifratura personalizzata\n");
       printf("2. Chiave di cifratura generata casualmente\n");
        printf("0. Esci\n");

      do{
       printf("scelta: ");
        scanf("%d",&scelta); getchar();
       switch (scelta) {

                                   //SCELTA 1: CHIAVE DA TASTIERA


case 1: printf("\n----------MENU'CHIAVE DI CIFRATURA PERSONALIZZATA----------\n");
        printf("\nInserisci la chiave da tastiera di lunghezza >= al testo immesso\n");

        do{
          fgets(chiavedatastiera_K, 128, stdin);
           lunghezza_K = strlen(chiavedatastiera_K);
            printf("La lunghezza della chiave e': %d\n", lunghezza_K);
      }
        while (lunghezza_K > 128 );
          printf("La chiave immessa e' : %s\n", chiavedatastiera_K);
           if(lunghezza_K < strlen(testodatastiera_M)){
            printf("##ERRORE## :\n.chiave troppo corta\n");
             return 0;
           }
           if(lunghezza_K > 126){
            printf("##ERRORE## :\n.chiave troppo lunga\n");
             return 0;
          }
             else
              printf("\n-----GENERAZIONE CIFRATURA:-----\n\nTESTO CIFRATO:\n ");

                                  //CIFRATURA CON CHIAVE DA TASTIERA in XOR
               for (i=0; i<strlen(testodatastiera_M); i++){
                 cipher_C[i]= testodatastiera_M[i] ^ chiavedatastiera_K[i];
                   printf("%x",cipher_C[i]);
               }
               printf("\n\nTESTO DECIFRATO:\n");

                                  //DECIFRATURA CON CHIAVE DA TASTIERA proprieta' XOR
               for (i=0; i<strlen(testodatastiera_M); i++){
                 decrypter_C[i]=cipher_C[i] ^ chiavedatastiera_K[i];
                  printf("%c",decrypter_C[i]);
               }
               printf("\n          -----PROGRAMMA TERMINATO-----\n");
                return 0;
                  break;

                                  //SCELTA 2:CHIAVE GENERATA CASUALMENTE


case 2: printf("\n----------CHIAVE DI CIFRATURA GENERATA CASUALMENTE----------\n");
          printf("\nCHIAVE GENERATA: \n");
          time_t t;
           srand((unsigned) time(NULL));
            int a =0;

          while(a<strlen(testodatastiera_M)){
            chiavecifratura_K[i]= (33 + rand()%96);
             printf("%s",chiavecifratura_K);
              a++;
          }    printf("\n\n----------GENERAZIONE CIFRATURA----------\n\nTESTO CIFRATO: \n");

                                   //CIFRATURA CON CHIAVE DA GENERATORE
          for (i=0; i<strlen(testodatastiera_M); i++){
            cipher_C[i]= testodatastiera_M[i] ^ chiavecifratura_K[i];
              printf("%x",cipher_C[i]);
          }
           printf("\n\nTESTO DECIFRATO: \n");

                                 //DECIFRATURA CON CHIAVE DA GENERATORE
          for (i=0; i<strlen(testodatastiera_M); i++){
            decrypter_C[i]=cipher_C[i] ^ chiavecifratura_K[i];
             printf("%c",decrypter_C[i]);
          }
           printf("\n---------------PROGRAMMA TERMINATO---------------\n");
            return 0;
           break;
            case 0: printf("\nFine sessione.\n");
             break;
              default: printf("\nScelta non consentita.\n");
               break;

                 printf("cifratura con chiave generata");
       }
        while(scelta!=0);
         return 0;
   }
     while(scelta!=1);(scelta!=2);
       return 0;
     break;
     case 0: printf("\nFine sessione.\n");
       break;
        default: printf("\nScelta non consentita.\nRIPROVA\n");
         break;
  }

}
 while(scelta1!=0);
 return 0;











return 0;
  }
