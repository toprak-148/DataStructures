#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

 


int *dizi = NULL ;
int sira = 0 , sirabasi = 0 , boyut = 2;

void clear()
{
    if(sirabasi == 0 ){
        return;
    }
    for( int i = 0 ; i < boyut; i++){
        dizi[i] = dizi[i+sirabasi];
    }
    sira -= sirabasi;
    sirabasi = 0;

}

int enque(int a){
    if(dizi == NULL){
        dizi = ( int * )malloc(sizeof(int)*boyut);
    }
    if(sira >= boyut){
        int * dizi2 = (int *)malloc(sizeof(int)* boyut * 2);
        for(int i = 0 ; i < boyut; i++){
            dizi2[i]=dizi[i];
        }
        free(dizi); 
        dizi = dizi2;
        boyut = boyut *2;
    }
    dizi[sira++] = a;
}

int deque(){

    if(sirabasi == sira){
        printf("kuyruk boş ");
        return -1;
    }
    //printf("boyut : %d , sıra : %d , fark : %d\n",boyut , sira , sira - sirabasi);
    if(sira - sirabasi <= boyut / 4){
            int * dizi2 = (int *)malloc(sizeof(int)* boyut / 2);
            for(int i  = 0 ; i < sira - sirabasi ; i++){
                dizi2[i] = dizi[sira + i];

            }
            sira -= sirabasi;
            sirabasi = 0;
            free(dizi);
            boyut = boyut /2 ;
            dizi = dizi2;


    }
    return dizi[sirabasi++];
}



int main()
{
    setlocale(LC_ALL,"turkish");

    for(int i = 0 ; i < 20 ; i++){
        enque(i*10);
    }
    printf("durum :  boyut : %d  sıra : %d   sırabaşı : %d",boyut , sira , sirabasi);
    for(int i = 0 ; i < 13 ; i++){
        printf("%d\n",deque());

    }
    clear();
    printf("durum :  boyut : %d  sıra : %d   sırabaşı : %d",boyut , sira , sirabasi);
    for(int i = 0 ; i< 20 ; i++){
        enque(i*10);

    }
    printf("durum :  boyut : %d  sıra : %d   sırabaşı : %d",boyut , sira , sirabasi);
    for(int i = 0 ; i < 30 ; i++){
        printf("%d\n",deque());

    }
    clear();
    printf("durum :  boyut : %d  sıra : %d   sırabaşı : %d",boyut , sira , sirabasi);
    return 0;
}
