#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient{
    int id;
    char name[50];
    char status[20];
    struct Patient* next;
}Patient;

typedef struct Queue{
    Patient* front;
    Patient* rear;
}Queue;

typedef struct Stack{
    Patient* top;
}Stack;

void enqueue(Queue* q, int id, char* name){
    Patient* newNode=(Patient*)malloc(sizeof(Patient));

    newNode->id=id;
    strcpy(newNode->name,name);
    strcpy(newNode->status,"bekliyor");
    newNode->next=NULL;

    if(q->front==NULL){
        q->front=newNode;
        q->rear=newNode;
        return;
    }

    q->rear->next=newNode;
    q->rear=newNode;
}

Patient* dequeue(Queue* q){
    Patient* silinecek;

    if(q->front==NULL)
        return NULL;

    silinecek=q->front;
    q->front=q->front->next;

    if(q->front==NULL)
        q->rear=NULL;

    silinecek->next=NULL;

    return silinecek;
}

void push(Stack* s, Patient* hasta){
    if(hasta==NULL)
        return;

    strcpy(hasta->status,"muayenede");

    hasta->next=s->top;
    s->top=hasta;
}

Patient* pop(Stack* s){
    Patient* silinecek;

    if(s->top==NULL)
        return NULL;

    silinecek=s->top;
    s->top=s->top->next;

    silinecek->next=NULL;

    return silinecek;
}

void addHistory(Patient** head, Patient* hasta){
    Patient* current=*head;

    if(hasta==NULL)
        return;

    strcpy(hasta->status,"tamamlandi");
    hasta->next=NULL;

    if(current==NULL){
        *head=hasta;
        return;
    }

    while(current->next!=NULL){
        current=current->next;
    }

    current->next=hasta;
}

void showQueue(Queue q){
    Patient* current=q.front;

    if(current==NULL){
        printf("Hasta yok.\n");
        return;
    }

    while(current!=NULL){
        printf("Hasta ID: %d, Isim: %s, Durum: %s\n",
               current->id,current->name,current->status);

        current=current->next;
    }
}

void showStack(Stack s){
    Patient* current=s.top;

    if(current==NULL){
        printf("Hasta yok.\n");
        return;
    }

    while(current!=NULL){
        printf("Hasta ID: %d, Isim: %s, Durum: %s\n",
               current->id,current->name,current->status);

        current=current->next;
    }
}

void showHistory(Patient* head){
    Patient* current=head;

    if(current==NULL){
        printf("Hasta yok.\n");
        return;
    }

    while(current!=NULL){
        printf("Hasta ID: %d, Isim: %s, Durum: %s\n",
               current->id,current->name,current->status);

        current=current->next;
    }
}

int main(void){
    Queue q;
    Stack s;
    Patient* history=NULL;
    Patient* hasta;

    q.front=NULL;
    q.rear=NULL;
    s.top=NULL;

    enqueue(&q,1,"Ahmet");
    enqueue(&q,2,"Mehmet");
    enqueue(&q,3,"Ayse");

    printf("=== Baslangic Durumu ===\n");

    printf("\n--- Bekleyen Hastalar ---\n");
    showQueue(q);

    printf("\n--- Muayene Odasindaki Hastalar ---\n");
    showStack(s);

    printf("\n--- Tamamlanan Hastalar ---\n");
    showHistory(history);

    printf("\n=== Ahmet Muayeneye Aliniyor ===\n");

    hasta=dequeue(&q);
    push(&s,hasta);

    printf("\n--- Bekleyen Hastalar ---\n");
    showQueue(q);

    printf("\n--- Muayene Odasindaki Hastalar ---\n");
    showStack(s);

    hasta=pop(&s);
    addHistory(&history,hasta);

    printf("\n=== Ahmet Muayenesi Tamamlandi ===\n");

    printf("\n--- Muayene Odasindaki Hastalar ---\n");
    showStack(s);

    printf("\n--- Tamamlanan Hastalar ---\n");
    showHistory(history);

    printf("\n=== Mehmet Muayeneye Aliniyor ===\n");

    hasta=dequeue(&q);
    push(&s,hasta);

    printf("\n--- Bekleyen Hastalar ---\n");
    showQueue(q);

    printf("\n--- Muayene Odasindaki Hastalar ---\n");
    showStack(s);

    hasta=pop(&s);
    addHistory(&history,hasta);

    printf("\n=== Mehmet Muayenesi Tamamlandi ===\n");

    printf("\n=== Tum Islemler Sonrasi ===\n");

    printf("\n--- Bekleyen Hastalar ---\n");
    showQueue(q);

    printf("\n--- Muayene Odasindaki Hastalar ---\n");
    showStack(s);

    printf("\n--- Tamamlanan Hastalar ---\n");
    showHistory(history);

    return 0;
}
