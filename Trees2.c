#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

struct TREE
{
    int data;
    struct TREE * right;
    struct TREE * left;

}typedef tree;

void bastir(tree * r)
{
    tree * iter = r;
    if(iter == NULL){
       return ;
    }

    bastir(iter -> left);
    printf("\n%d %x ", iter -> data,iter);
    bastir(iter -> right);

}
tree  * push(tree * r , int data)
{
    if(r == NULL){
        r = ( tree * )malloc(sizeof(tree));
        r -> data = data;
        r -> right = NULL;
        r -> left = NULL;
        return r;
    }
    if( r -> data < data){
        r -> right = push(r -> right , data);
        return r;
    }
    else{
    r -> left = push(r -> left,data);

    return r;
    }
}
int bul(tree * r , int aranan)
{
    if(r == NULL)
        return -1;

    if( r -> data == aranan)
        return 1;

    if(bul( r -> right , aranan) == 1)
        return 1;

    if(bul(r -> left , aranan) == 1)
        return 1;

    return -1;

}

int max(tree * r)
{
    tree * iter = r;
    while(iter -> right != NULL){
        iter = iter -> right;
    }
    return iter -> data;
}

int min(tree *r )
{
    tree * iter = r;
    while(iter -> left != NULL)
        iter = iter -> left;
    return iter -> data;
}

tree * sil(tree * r , int data){

    if( r == NULL){
        printf("ağaç boş");
    }
    if( r -> data == data){
        if(r -> left == NULL && r -> right == NULL)
            return NULL;
        if(r -> left != NULL){
            r -> data = min( r  -> right);
            r -> right = sil(r -> right , min( r -> right));
            return r;
        }
        r -> data = max(r -> left);
        r -> left =sil(r-> left , max( r -> left));
        return r ;
    }

}


int main()
{
    setlocale(LC_ALL,"Turkish");

    tree * root = NULL;

    root = push(root , 40);
    root = push(root , 20);
    root = push(root , 100);
    root = push(root , 150);
    root = push(root , 90);
    root = push(root , 210);
    root = push(root , 190);
    bastir(root);
    /*
    printf("\n");
    printf("min : %d\nmax : %d\n",min(root),max(root));
    bastir(root);
    printf("\n%d",bul(root , 20));
    printf("\n");
    printf("%d",bul(root , 210));
    printf("\n");
    printf("%d\n",bul(root , 150));
    printf("%d\n",bul(root , 5));
    bastir(root);
*/




    return 0;
}
