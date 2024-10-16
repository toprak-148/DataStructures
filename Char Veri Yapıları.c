 #include <stdlib.h>
#include <stdio.h>
#include <locale.h>
 
struct NODE{
    char data;
    struct NODE * next;
}typedef node;

node * ekle(node * r , char data)
{
    if(r == NULL)
    {
        r = ( node * )malloc(sizeof(node));
        r -> data = data;
        r -> next = NULL;
        return r;
    }

    node * iter = r;
    while( iter -> next != NULL)
        iter = iter -> next;

    node * temp = ( node * )malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> data = data;
    return r;
}

int  t_lenght(node * r )
{
    node * iter = r;
    int sayac = 0;
    while(iter  != NULL)
    {
        sayac++;
        iter = iter -> next;
    }

    return sayac;
}

int indexOf(node * r , char aranan_deger)
{
    if(r == NULL)
        return;
    int sayac = 0;
    node * iter = r;
    while(iter != NULL && iter -> data != aranan_deger )
    {
        sayac++;
        iter = iter -> next;
        if(iter == NULL)
            return -1;
    }
    return sayac;

}
node * tolower(node * r)
{
    if( r == NULL)
        return;
    node * iter = r;
    while(iter  != NULL)
    {
        if( iter -> data == 'A')
            iter -> data = 'a';
        if(iter -> data == 'B')
            iter -> data = 'b';
        if(iter -> data == 'C')
            iter -> data = 'c';
        if(iter -> data == 'D')
            iter -> data = 'd';
        if(iter -> data == 'E')
            iter -> data = 'e';
        if(iter -> data == 'F')
            iter -> data = 'f';
        if(iter -> data == 'G')
            iter -> data = 'g';
        if(iter -> data == 'H')
            iter -> data == 'h';
        if(iter -> data == 'I')
            iter -> data = 'i';
        if(iter -> data == 'J')
            iter -> data = 'j';
        if(iter -> data == 'K')
            iter -> data = 'k';
        if(iter -> data == 'L')
            iter -> data = 'l';
        if(iter -> data == 'M')
            iter -> data = 'm';
        if(iter -> data == 'N')
            iter -> data = 'n';
        if(iter -> data == 'O')
            iter -> data = 'o';
        if(iter -> data == 'P')
            iter -> data = 'p';
        if(iter -> data == 'R')
            iter -> data = 'r';
        if(iter -> data == 'S')
            iter -> data = 's';
        if(iter -> data == 'T')
            iter -> data = 't';
        if(iter -> data == 'U')
            iter -> data = 'u';
        if(iter -> data == 'V')
            iter -> data = 'v';
        if(iter -> data == 'Y')
            iter -> data = 'y';
        if(iter -> data == 'Z')
            iter -> data = 'z';
        iter = iter -> next;
    }
    return r;
}

node * toupper(node * r)
{
    if( r == NULL)
        return;
    node * iter = r;
    while(iter  != NULL)
    {
        if( iter -> data == 'a')
            iter -> data = 'A';
        if(iter -> data == 'b')
            iter -> data = 'B';
        if(iter -> data == 'c')
            iter -> data = 'C';
        if(iter -> data == 'd')
            iter -> data = 'D';
        if(iter -> data == 'e')
            iter -> data = 'E';
        if(iter -> data == 'f')
            iter -> data = 'F';
        if(iter -> data == 'g')
            iter -> data = 'G';
        if(iter -> data == 'h')
            iter -> data == 'H';
        if(iter -> data == 'i')
            iter -> data = 'I';
        if(iter -> data == 'j')
            iter -> data = 'J';
        if(iter -> data == 'k')
            iter -> data = 'K';
        if(iter -> data == 'l')
            iter -> data = 'L';
        if(iter -> data == 'm')
            iter -> data = 'M';
        if(iter -> data == 'n')
            iter -> data = 'N';
        if(iter -> data == 'o')
            iter -> data = 'O';
        if(iter -> data == 'p')
            iter -> data = 'P';
        if(iter -> data == 'r')
            iter -> data = 'R';
        if(iter -> data == 's')
            iter -> data = 'S';
        if(iter -> data == 't')
            iter -> data = 'T';
        if(iter -> data == 'u')
            iter -> data = 'U';
        if(iter -> data == 'v')
            iter -> data = 'V';
        if(iter -> data == 'y')
            iter -> data = 'Y';
        if(iter -> data == 'z')
            iter -> data = 'Z';
        iter = iter -> next;
    }
    return r;
}

void bastir(node * r)
{
    node * iter = r;
    while(iter != NULL)
    {
        printf("%c",iter -> data);
        iter = iter -> next;
    }
    printf("\n");
}
node *  kelime_turet(node * r)
{
    int kelime_sayisi;
    printf("Yazmak istediğiniz harf sayısı : ");
    scanf("%d",&kelime_sayisi);
    for(int i = 0 ; i < kelime_sayisi ; i++)
    {
        printf("Harf:");
        char harf;
        scanf(" %c",&harf);
        r = ekle(r,harf);
    }
    return r;

}
int main()
{
    setlocale(LC_ALL,"Turkish");

    node * root = NULL;
    node * soyisim = NULL;
    root = ekle(root,'t');
    root = ekle(root,'O');
    root = ekle(root,'p');
    root = ekle(root,'R');
    root = ekle(root,'a');
    root = ekle(root,'K');
    soyisim = ekle(soyisim,'D');
    soyisim = ekle(soyisim,'O');
    soyisim = ekle(soyisim,'G');
    soyisim = ekle(soyisim,'A');
    soyisim = ekle(soyisim,'N');
    bastir(root);
    printf(" ");
    bastir(soyisim);
    root = tolower(root);
    soyisim = tolower(soyisim);
    printf("\n");
    bastir(root);
    printf(" ");
    bastir(soyisim);
    printf("\n");
    root = toupper(root);
    soyisim = toupper(soyisim);
    bastir(root);
    printf(" ");
    bastir(soyisim);
    printf("\n");

    printf("İsim boyutu : %d ,  soyisim Boyutu : %d\n",t_lenght(root),t_lenght(soyisim));
    printf("%d\n\n",indexOf(root,'Y'));
    node * deneme = NULL;
    deneme = kelime_turet(deneme);
    bastir(deneme);
    deneme = toupper(deneme);
    bastir(deneme);
    deneme =tolower(deneme);
    bastir(deneme);
    printf("%d\n",indexOf(deneme,'k'));
    printf("%d\n",t_lenght(deneme));

    return 0;
}
