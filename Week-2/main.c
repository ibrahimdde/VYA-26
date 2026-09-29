#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int sayi;
    struct Node* next;
}Node;

/* SORU 1:
int main(void){
    Node head;
    head.sayi=10;
    head.next=NULL;
    printf("%d", head.sayi);
}
*/
/* SORU 2
 
int main(void){
    Node bir;
    Node iki;
    bir.sayi=10;
    bir.next=&iki;
    bir.next->sayi=20;
    bir.next->next=NULL;
    printf("%d\n", bir.sayi);
    printf("%d\n", iki.sayi);
    
    return 0;
}
 */
/* SORU 3
 
void nodeEkle(Node** headptr, int value){
    Node* current = (Node*)malloc(sizeof(Node));
    current->sayi=value;
    current->next=NULL;
    if(*headptr == NULL){
            *headptr = current;
            return;
        }
    Node* temp = *headptr;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = current;
    
    
}
int main(void){
    Node* head = NULL;
    int i;
    for(i=1;i<4;i++){
        nodeEkle(&head,i*10);
    }
    Node* temp = head;
    while(temp!=NULL){
        printf("%d",temp->sayi);
        temp=temp->next;
        
    }
    
    //can sıkıntısı pushback'i şu an yaptım
    
    return 0;
}

 */
/* SORU 4
 
int main(void){
    Node* bir = (Node*)malloc(sizeof(Node));
    Node* iki = (Node*)malloc(sizeof(Node));
    Node* uc = (Node*)malloc(sizeof(Node));
    bir->sayi=10;
    bir->next=iki;
    iki->next=uc;
    uc->next=NULL;
    iki->sayi=20;
    uc->sayi=30;
    Node* head = bir;
    while(head!=NULL){
        printf("%d", head->sayi);
        head=head->next;
    }
    free(bir);
    free(iki);
    free(uc);
    return 0;
}

 
 */
/* SORU 5
 
int main(void){
   Node* bir = (Node*)malloc(sizeof(Node));
   Node* iki = (Node*)malloc(sizeof(Node));
   Node* uc = (Node*)malloc(sizeof(Node));
    
    Node* dort = (Node*)malloc(sizeof(Node));
   bir->sayi=10;
   bir->next=iki;
   iki->next=uc;
   uc->next=dort;
   iki->sayi=20;
   uc->sayi=30;
    dort->sayi=40;
   Node* head = bir;
    int iteration=0;
   while(head!=NULL){
       printf("%d\n", head->sayi);
       head=head->next;
       iteration++;
   }
    printf("total iterasyon sayisi : %d", iteration);
   free(bir);
   free(iki);
   free(uc);
    free(dort);
   return 0;
}


 */
/* SORU 6
 
 
 int main(void){
     Node bir;
     Node iki;
     Node uc;
     Node dort;
     bir.sayi=10;
     bir.next=&iki;
     iki.sayi=20;
     iki.next=&uc;
     uc.sayi=30;
     uc.next=&dort;
     dort.sayi=40;
     dort.next=NULL;
     Node* head = &bir;
     int toplam=0;
     while(head!=NULL){
         toplam+=head->sayi;
         head=head->next;
     }
     printf("TOPLAM = %d", toplam);
     return 0;
 }*/
/* SORU 7
 
int main(void){
    Node* bir = (Node*)malloc(sizeof(Node));
    Node* iki = (Node*)malloc(sizeof(Node));
    Node* uc = (Node*)malloc(sizeof(Node));
    bir->sayi=10;
    bir->next=iki;
    iki->next=uc;
    uc->next=NULL;
    iki->sayi=20;
    uc->sayi=30;
    // 20'yi arayalım diyelim
    Node* head = bir;
    int flag=0;
    int i=1;
    while(flag!=1){
        if((head->sayi)!=20){
            head=head->next;
            i++;
        }
        flag=1;
    }
    printf("20 sayısı %d'deydi.",i);
    free(bir);
    free(iki);
    free(uc);
    return 0;
 }
 */
/* SORU 8
 
void nodeEkle(Node** headptr, int value){
    Node* current = (Node*)malloc(sizeof(Node));
    current->sayi = value;
    current->next = *headptr;
    *headptr = current;
}

int main(void){
    Node* head = NULL;
    int i;
    for(i = 1; i <= 3; i++){
        nodeEkle(&head, i * 10);
    }
    return 0;
}

 */
/* SORU 9
 
void nodeEkle(Node** headptr, int value){
   Node* current = (Node*)malloc(sizeof(Node));
   current->sayi=value;
   current->next=NULL;
   if(*headptr == NULL){
           *headptr = current;
           return;
       }
   Node* temp = *headptr;
   while(temp->next!=NULL){
       temp=temp->next;
   }
   temp->next = current;
   
   
}
int main(void){
    Node* head = NULL;
    int i;
    for(i=1;i<4;i++){
        nodeEkle(&head,i*10);
    }
    return 0;
}

 */
/*
 
//20'yi sildiğimizi var sayalım
void nodeSil(Node** headptr, int value){
    Node* current =*headptr;
    Node* prevState;
    if(current->sayi==value){
        *headptr=current->next;
        free(current);
        return;
    }
    while(current->sayi!=value){
        prevState=current;
        current=current->next;
        
    }
    //duble check ettim can sıkıntısı
    if(current->sayi==20){
        prevState->next=current->next;
    }
    if (current == NULL)
        return;
    free(current);
}
int main(void){
    Node* bir = (Node*)malloc(sizeof(Node));
    Node* iki = (Node*)malloc(sizeof(Node));
    Node* uc = (Node*)malloc(sizeof(Node));
    bir->sayi=10;
    bir->next=iki;
    iki->next=uc;
    uc->next=NULL;
    iki->sayi=20;
    uc->sayi=30;
    Node* head = bir;
    return 0;
}

 
 */
