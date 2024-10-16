#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//! ABSTRACT DATA TYPE (ADT)
/*! Yığınlar(Stacks)
    => Tek taraflı giriş ve çıkışlara açık olan. İlk giren son çıkar ( last in first out) mantığı ile çalışan bir yapıdır.
       Temelde 3 adet fonksiyonları bulunur.
       -> Push = Stack içerisine veri[bilgi] koymayı sağlayan fonksiyondur
       -> Pop = Stack içerisinden veri[bilgi] silmeye yarayan fonskiyondur.
       -> Top = Stack'in en tepesindeki bilgiyi alır ancak stackten çıkarmaz sadece okur

    => Bir kutu gibi düşünebiliriz.Kutuya baştan itibaren üst üste kitapları koyuyoruz.Eğer kutuyu boşalmak ister isek
       ilk başta kutuya son koyduğumuz kitabı alırız en son alacağımız kitap en alttaki ilk koyduğumuz kitap olacaktır.

    => iki tür kodlama çeşidi vardır. Bunlar :
        -> Array tarzı yığın kodlamak
        -> LinkedList tarzı yığın kodlamak.
            [ şuan ki proje arraylar yardımı ile yığın kodlamak olacaktır.
*/
  
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int *dizi ;
int boyut = 2;
int tepe = 0;

void push(int data)
{
    if(tepe <= boyut )
    {
        int * dizi2 = ( int * )malloc(sizeof(int)*2*boyut);
        for(int i = 0 ; i < boyut ; i++){
            dizi2[i] = dizi[i];
        }
        free(dizi);
        dizi = dizi2;
        boyut = boyut * 2;
    }
    dizi[tepe++] = data;
}

int pop()
{
    if(tepe >= boyut)
    {
        int * dizi2 = (int * )malloc(sizeof(int)*boyut / 2);
        for(int i = 0 ; i <boyut ; i++)
            dizi2[i] = dizi[i];
        free(dizi);
        dizi = dizi2 ;
        boyut = boyut / 2;
    }

    return dizi[--tepe];
}

void bastir()
{
    int *adres;
    for(int i = 0 ; i < tepe ; i++){
        adres = &dizi[i];
    }
    if(dizi == NULL)
        printf("yığın boş");
    printf("yığın içeriği:");
    for( int i = 0 ; i < tepe ; i++){
        printf("%d ",dizi[i]);
    }
    printf("\n");
    printf("adresler:\n");

    for( int i = 0 ; i < tepe ; i++){
        printf("%d.değer adresi : %d\n",i,adres[i]);
    }
    printf("\n");
}

int aranan(int data)
{
    if(dizi == NULL){
        return -1;
    }
    for(int i = 0 ; i < tepe ; i++)
    {
        if(dizi[i] == data)
            return 1;
    }
    return -1;
}

int main()
{   setlocale(LC_ALL,"Turkish");

    dizi = (int * )malloc(sizeof(int)*2);

    for(int i = 0 ; i <= 10 ; i++)
        push(i*10);

    bastir();
    printf("%d popped\n",pop());
    printf("%d popped\n",pop());
    bastir();
    printf("%d",aranan(40));

    return 0;
}
