#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
    
/* Soru 1 ve 2 buradan, alt clause'lar daha sonraki blokta
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->prev);
    printf("%d ", root->data);
    inorder(root->next);
}
int search(Node* root, int value){
    Node* current = root;
    if (root==NULL)
        return 0;
    while(current!=NULL){
        if(value==current->data)
        return 1;
        if(value>=current->data)
            current=current->next;
        else if(value<=current->data)
            current=current->prev;
        }
    return 0;
}
int findMin(Node* root){
    Node* current = root;
    if(root==NULL)
        return 0;
    while((current->prev)!=NULL){
        current=current->prev;
    }
    return current->data;
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
 // 40, 20, 60, 10, 30, 50, 70
    Node* root = NULL;
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    inorder(root);
    search(root, 30);
    search(root, 90);
    printf("Agactaki en kucu keleman : %d", findMin(root));
    
    return 0;
}
*/
int findMin(Node* root){
    Node* current = root;
    if(root==NULL)
        return 0;
    while((current->prev)!=NULL){
        current=current->prev;
    }
    return current->data;
}
int search(Node* root, int value){
    Node* current = root;
    if (root==NULL)
        return 0;
    while(current!=NULL){
        if(value==current->data)
        return 1;
        if(value>=current->data)
            current=current->next;
        else if(value<=current->data)
            current=current->prev;
        }
    return 0;
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
int main(void) {
Node* root = NULL;
    int numbers[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++)
        root = insert(root, numbers[i]);
    if (search(root, 30))
        printf("30 agacta bulundu.\n");
    else
        printf("30 agacta bulunamadi.\n");
    if (search(root, 90))
        printf("90 agacta bulundu.\n");
    else
        printf("90 agacta bulunamadi.\n");
    if (root != NULL)
        printf("En kucuk eleman: %d\n", findMin(root));


return 0;
}
//● 25 değeri eklenirse hangi düğümün altına yerleşir? =
// cevap= 30'un sol altına yerleşir. 40solu->20sağı->30solu->25
//● Inorder fonksiyonunda printf() ilk satıra taşınırsa hangi dolaşma elde edilir?
// cevap = DFS, depth first search
//● findMin() içinde left yerine right takip edilirse hangi değer bulunur?
// cevap = max değer.

