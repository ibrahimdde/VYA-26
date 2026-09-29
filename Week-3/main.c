#include <stdio.h>
#include <stdlib.h>
// void printlist ve void clear fonksiyonları üç kez tekrarlı yazılmış. Modüler fonksiyon yapısında fonksiyonun işlevi %100 aynı olduğu için yazmadım.

typedef struct Node{
    int sayi;
    struct Node* next;
}Node;
void addinOrder(Node** headptr, int value){
    Node* current;
    Node* newNode =(Node*)malloc(sizeof(Node));
    newNode->sayi=value;
    newNode->next=NULL;
    if(*headptr==NULL){
        *headptr=newNode;
        return;
    }
    current = *headptr;
    Node* prevState=NULL;
    while(current!=NULL && value>current->sayi ){
        prevState=current;
        current=current->next;
    }
    if(prevState==NULL){
        newNode->next=*headptr;
        *headptr=newNode;
        return;
    }
    prevState->next=newNode;
    newNode->next=current;
    current=newNode;
    }
        
void removeNode(Node** headptr, int value){
    Node* current = *headptr;
    Node* prevState=NULL;
    if(*headptr==NULL)
        return;
    if(value==current->sayi){
            
        *headptr=current->next;
        free(current);
        return;
        }
    while(current!=NULL&&current->sayi!=value){
        prevState=current;
        current=current->next;
    }
    if(current == NULL)
            return;
    prevState->next=current->next;
    free(current);
    
}
int count(Node* head){
    int i=1;
    if(head==NULL)
        return 0;
    if(head->next==NULL)
        return 1;
    while(head!=NULL&&head->next!=NULL){
        head=head->next;
        i++;
    }
    return i;
}
void printList(Node* head){
    if(head==NULL)
        return;
    
    while(head!=NULL){
        printf("eleman deger %d\n", head->sayi);
        head=head->next;
    }
}
void bosalt(Node** headptr){
    Node* nextNode;
    Node* current = *headptr;
    if(headptr == NULL || *headptr == NULL)
        return;
    while(current!=NULL){
        nextNode=current->next;
        free(current);
        current=nextNode;
    }
    *headptr=NULL;
}
void insertAt(Node** headptr, int value, int indis){
    Node* current= *headptr;
    Node* prevState=NULL;
    Node* newState=(Node*)malloc(sizeof(Node));
    newState->sayi=value;
    int i;
    if(indis==0){
        newState->next=current;
        *headptr=newState;
        return;
    }
        
    for(i=0;i<indis;i++){
        if(current==NULL){
            free(newState);
            return;
        }
            prevState=current;
            current=current->next;
        }
    
    prevState->next=newState;
    newState->next=current;
}
void deleteAt(Node** headptr, int value, int indis){
    Node* current = *headptr;
    Node* temp=NULL;
    int i;
    Node* prevState=NULL;
    
    if(*headptr==NULL)
        return;
    if(indis==0){
        *headptr=current->next;
        free(current);
        return;
    }
    for(i=0;i<indis;i++){
        if(current==NULL)
            return;
        prevState=current;
        current=current->next;
    }
    
    if(current==NULL)
        return;
    prevState->next=current->next;
    free(current);
}
void findMiddle(Node* head, Node** middlePtr){
        if(head == NULL){
            *middlePtr = NULL;
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        *middlePtr = slow;
    }
    

int main(void){
    int i;
    int a;
    Node bir;
    Node iki;
    Node uc;
    bir.next=&iki;
    iki.next=&uc;
    Node* head=&bir;
    //tüm fonksiyon çağrılarını yapmak için vaktim kalmadı. Fakat hepsi izole şekilde test edildiğinde çalıştı.
    return 0;
}
