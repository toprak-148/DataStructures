#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

/*!
    ÇİFT YÖNLÜ BAĞLI LİSTELER

    Amaç geriye dönebilen dairesel bir bağlı liste oluşturup node içerisinde ekleme silme veya güncelleme işlemleri
    yapabilmemizi sağlar.

    ilerleme için yapılan next in yanına prevition(prev) pointeride ekleyerek pointer içerisinde geriye gidebilmemize
    olanak sağlar.

    => random access mümkün değildir. Squention access ile erişim yapılabilir. Sadece ileri ve geri haraket
    edilebilir. Kafamıza göre bir değere gidemeyiz.

*/

struct NODE{
    
    int data;
    struct NODE * next;
    struct NODE * prev;


}typedef node;
node * root = null;
root.a = 5;
root -> next = null;
roott -> prev = null;
void bastir(node * r){
    
    while( r != NULL){
        
        printf("%d ", r -> data);
        r = r -> next;
    }
    
    printf("\n");
}

node * siraliEkle( node * r , int data)
{
    if( r == NULL){//! Eğer linklistte hiç eleman yok ise next ' te null prev'de null değerini göstermelidir.
       
        r = ( node * )malloc(sizeof(node));
        r -> next = NULL;
        r -> prev = NULL;
        r -> data = data;
       
        return r;
	   
    }

    if( r -> data > data)
    {
        //! eğer ilk eleman küçük ise root değişmelidir.
        //! Başa bir tane düğüm ekleme durumu düşünülmelidir.
        //! root un previ temp yeni eklenen değeri göstermelidir.
       
        node * temp = ( node * )malloc(sizeof(node));
        temp -> data = data;
        temp -> next = r;
        r -> prev = temp;
       
        return temp;
    }
    
    node * iter = r;

    while( iter -> next != NULL && iter -> next -> data < data){
    
        iter = iter -> next;
    
    }

    node * temp = ( node * )malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> prev = iter;
    
    if( temp -> next != NULL){
    
        temp -> next -> prev = temp;
    
    }
    
    temp -> data = data;
    
    return r;
}

node * sil( node * r , int data)
{
    node * temp ;
    node * iter = r;

    if( r -> data == data){
    
        temp = r;
        r = r -> next;
        free(temp);
        return r;
    
    }
    
    while( iter -> next != NULL && iter -> next -> data != data){
    
        iter = iter -> next ;
    
    }
    
    if( iter -> next == NULL){
    
        printf("Aranan değer node içerisinde bulunamadı");
    
    }
    
    temp = iter -> next;
    iter -> next = iter -> next -> next;
    free(temp);
    
    if(iter -> next != NULL){
        
        //! son durumu silerken iter -> next null gösteriyor iteri gösteren bir prev değeri olmadığı için özel olarak
        //! düşünülmüş bir durumdur
        
        iter -> next -> prev = iter ;

    }
    
    return r;

}


int main()
{
    setlocale(LC_ALL,"Turkish");

    node * root = NULL;

    root = siraliEkle(root,400);
    root = siraliEkle(root,40);
    root = siraliEkle(root,4);
    root = siraliEkle(root,550);
    root = siraliEkle(root,500);
    bastir(root);

    root = sil(root,400);
    bastir(root);

    root = sil(root,4);
    bastir(root);

    root = sil(root,550);
    bastir(root);

    root = sil(root,990);
    bastir(root);

    return 0;
}
