#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Hazine Ağacı Oyunu (Treasure Tree Game)
Bir ikili arama ağacı (BST) içinde bazı düğümler “hazine” değerini temsil eder.
Kullanıcıdan bir sayı alınır ve ağaçta olup olmadığı rekürsif olarak kontrol
edilir.
Eğer sayı bulunursa:
Hazine bulundu!
aksi halde:
Boşuna kazdın!
Görevler:
Bonus:
 Her adımda hangi düğümün ziyaret edildiğini ekrana yaz.
 Hazineyi bulmak için en kötü durumda kaç adım gerekir? (ağaç
yüksekliği).
*/
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
int TTG(Node* root, int x){
    Node* current = root;
    if(root==NULL){
        return 0;
    }
    
    if(x > current->data){
        int sonuc = TTG(current->next, x);
        if(sonuc == 0) return 0;  // 0 geldiyse zinciri bozma, 0 döndür
        return 1 + sonuc;
    }
    else if(x < current->data){
        int sonuc = TTG(current->prev, x);
        if(sonuc == 0) return 0;  // 0 geldiyse zinciri bozma, 0 döndür
        return 1 + sonuc;
    }
    else if(x == current->data)
        return 1;
    
    return 0;
}
// getsize ağaç yüksekliğini getiriyor, o yüzden worst case scenario bu olabilir ancak
int getSize(Node *root)
{
    if (root == NULL)
        return 0;
    int left = getSize(root->prev);
    int right = getSize(root->next);

    return left + right + 1;
}

Node* insert(Node* root,int x){
    Node* newNode = malloc(sizeof(Node));
    newNode->data=x;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(root==NULL){
        return newNode;
    }
    Node* current = root;
    Node* parent = NULL;
    while (current != NULL) {
        parent = current;

        if (x < current->data) {
            current = current->prev;
        } else {
            current = current->next;
        }
    }
    if(x<parent->data)
        parent->prev=newNode;
    else
        parent->next=newNode;
    return root;
}
int main(void){
    
    return 0;
}

