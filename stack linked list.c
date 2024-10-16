#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*!
 ABSTRACT DATA TYPE (ADT)
 Yığınlar(Stacks)
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
            [ şuan ki proje linked list yardımı ile yığın kodlamak olacaktır. ]
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct STACK{

    int data;
    struct STACK * next;

}typedef stack;

stack * root = NULL;

stack * push(int data){

    if( root == NULL){
        root = ( stack * )malloc(sizeof(stack));
        root -> data = data;
        root -> next =NULL;
        return root;
    }

    stack * iter = root;
    while(iter -> next != NULL){
        iter = iter -> next;
    }
    stack * temp = (stack *)malloc(sizeof(stack));
    temp -> data = data;
    temp -> next = NULL;
    iter -> next = temp;
    return root;
}
int pop()
{
    if(root == NULL){
        printf("yığın boş");
        return -1;
    }
    stack * iter = root;
    while(iter -> next -> next != NULL){
        iter = iter -> next;
    }
    stack * temp =   iter -> next;
    int rvalue = temp -> data;
    iter -> next = NULL;
    free(temp);
    return rvalue;

}

void dolas()
{
    printf("yığın içeriği : ");
    stack * iter = root;
    while(iter  != NULL){
        printf("%d ",iter -> data);
        iter = iter -> next;
    }
    printf("\n");

}

int bul(int data)
{
    if(root == NULL){
        return -1;
    }
    if( root -> data == data){
        return 1;
    }
    stack *iter = root;
    while(iter -> next != NULL && iter -> next -> data != data){
        iter = iter -> next;}
    int rvalue = iter -> next;
    if(rvalue == NULL){
        return -1;
    }
    if(rvalue    == data){
        return 1;
    }
    return -1;



}

int main()
{
    setlocale(LC_ALL,"Turkish");
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    dolas();
    printf("\n");
    printf("%d popped ",pop());
    dolas();
    printf("\n");
    printf("%d popped ",pop());
    printf("\n");
    dolas();
    printf("\n");

    printf(bul(30));
    printf("\n");
    printf(bul(5));


    return 0;
}


 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct STACK{

    int data;
    struct STACK * next;

}typedef stack;

stack * root = NULL;

stack * push(int data){

    if( root == NULL){
        root = ( stack * )malloc(sizeof(stack));
        root -> data = data;
        root -> next =NULL;
        return root;
    }

    stack * iter = root;
    while(iter -> next != NULL){
        iter = iter -> next;
    }
    stack * temp = (stack *)malloc(sizeof(stack));
    temp -> data = data;
    temp -> next = NULL;
    iter -> next = temp;
    return root;
}
int pop()
{
    if(root == NULL){
        printf("yığın boş");
        return -1;
    }
    stack * iter = root;
    while(iter -> next -> next != NULL){
        iter = iter -> next;
    }
    stack * temp =   iter -> next;
    int rvalue = temp -> data;
    iter -> next = NULL;
    free(temp);
    return rvalue;

}

void dolas()
{
    printf("yığın içeriği : ");
    stack * iter = root;
    while(iter  != NULL){
        printf("%d ",iter -> data);
        iter = iter -> next;
    }
    printf("\n");

}

int bul(int data)
{
    if(root == NULL){
        return -1;
    }
    if( root -> data == data){
        return 1;
    }
    stack *iter = root;
    while(iter -> next != NULL && iter -> next -> data != data){
        iter = iter -> next;}
    int rvalue = iter -> next;
    if(rvalue == NULL){
        return -1;
    }
    if(rvalue    == data){
        return 1;
    }
    return -1;



}

int main()
{
    setlocale(LC_ALL,"Turkish");
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    dolas();
    printf("\n");
    printf("%d popped ",pop());
    dolas();
    printf("\n");
    printf("%d popped ",pop());
    printf("\n");
    dolas();
    printf("\n");

    printf(bul(30));
    printf("\n");
    printf(bul(5));


    return 0;
}


 
