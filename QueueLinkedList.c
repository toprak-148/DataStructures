#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct QUEUE{

    int data;
    struct QUEUE * next;
}typedef queu;

queu * root = NULL;
queu * end = NULL;



int deque()
{
    if(root == NULL)
    {
        printf("\nque boş");
        return -1;
    }
    int rvalue = root -> data;
    queu * temp = root ;
    root = root -> next;
    free(temp);
    return rvalue;

}

void enque(int data)
{

    if(root == NULL)
    {
        root = ( queu * )malloc(sizeof(queu));
        root -> data = data;
        root -> next = NULL;
        end = root;
    }
    else
    {
        end -> next = ( queu *)malloc(sizeof(queu));
        end -> next -> data = data;
        end = end -> next;
        end -> next = NULL;
    }

}

int main()
{
    setlocale(LC_ALL,"Turkish");
    for( int i = 0 ; i < 20 ; i++)
        enque(i*10);
    printf("\n");
    for(int i = 0 ; i < 11 ;i++)
    {
        printf("%d ",deque());
    }
    printf("\n");
    for(int i = 0 ; i < 20 ; i++ )
        enque(i*10);
    printf("\n");
    for( int i =  0 ; i < 30 ; i++)
    {
        printf("%d ",deque());
    }
    printf("\n");
    return 0;
}


 
