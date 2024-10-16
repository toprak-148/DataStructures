 #include <stdlib.h>
#include <stdio.h>
#include <locale.h>
 
struct NODE
{
    int data;
    struct NODE *next;

}typedef node;

void bastir( node * r )
{
    node * iter = r;

    printf("%d", iter -> data ) ;
    iter = iter -> next;

    while( iter != r ){

        printf("%d",iter -> next);
        iter = iter -> next;

    }

}

void ekle(node * r , int data)
{
    node * iter = r;

    while( r -> next != r){

        iter = iter -> next

    }

    node * temp = ( node * )malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp ;
    temp -> data = data;

}

node * siraliEkle(node * r , int data){

    if( r == NULL ){

        r = ( node * )malloc(sizeof(node));
        r -> next = NULL;
        r -> data = data;

        return r ;
    }

    if( r-> data > data){

        node * temp = ( node * )malloc(sizeof(node));
        temp -> data = data;
        temp -> next = r;
        node * iter = r;

        while( iter -> next != r ){

            iter = iter -> next ;

        }

        iter -> next = temp;

        return temp ;

    }

    node * iter = r;

    while( iter -> next != r  && iter -> next -> data < data){

        iter = iter -> next ;

    }

    node * temp = ( node * )malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> data = data;

    return r;

}

node  * sil(node * r , int data){

    node * temp;
    node * iter = r,

    if( iter -> data = data){

        while( iter -> next != r){

            iter  -> next = r -> next;
            free(r);

            return iter -> next;

        }
    }

    while( iter -> next != r && iter -> next -> data != data){

        iter = iter -> next;

    }

    if( iter -> next == r){

        printf("Aradığınız değer Node içerisinde bulunmuyor");

        return r ;

    }

    temp = iter -> next;
    iter -> next = iter -> next -> next;
    free(temp);

    return r ;

}

int main()
{
    node *root = NULL;

    root = siraliEkle(root , 400);
    root = siraliEkle(root , 40);
    root = siraliEkle(root , 4);
    root = siraliEkle(root , 550);
    root = siraliEkle(root , 500);
    bastir(root);

    root = sil(root , 4);
    bastir(root);

    root = sil(root , 400);
    bastir(root);

    root = sil(root , 550);
    bastir(root);

    root = sil(root , 1);
    bastir(root);

    return 0;
}
