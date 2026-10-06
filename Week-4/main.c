#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
typedef struct Song {
    char name[50];
    struct Song* next;
    struct Song* prev;
} Song;

void addSongToEnd(Song** head, char* name){
    Song* current=*head;
    Song* newNode=(Song*)malloc(sizeof(Song));
    Song* prevState;
    strcpy(newNode->name,name);
    newNode->next=NULL;
    newNode->prev=NULL;

    if(current==NULL){
        *head=newNode;
        return;
    }

    if(current!=NULL && current->next==NULL){
        current->next=newNode;
        newNode->prev=current;
        current=newNode;
        return;
    }

    while(current->next!=NULL){
        prevState=current;
        current=current->next;
        current->prev=prevState;
    }

    current->next=newNode;
    newNode->prev=current;
}

void removeSong(Song** head, char* name){
    Song* current=*head;
    Song* prevState=NULL;

    if(current==NULL)
        return;

    if(strstr(current->name,name)!=NULL){
        *head=current->next;

        if(current->next!=NULL)
            current->next->prev=NULL;

        free(current);
        return;
    }

    while(current!=NULL){
        if(strstr(current->name,name)!=NULL){
            prevState->next=current->next;

            if(current->next!=NULL)
                current->next->prev=prevState;

            free(current);
            return;
        }

        prevState=current;
        current=current->next;
    }
}

void playNext(Song** current){
    if(*current==NULL)
        return;

    if((*current)->next==NULL)
        return;

    *current=(*current)->next;
}

void playPrevious(Song** current){
    if(*current==NULL)
        return;

    if((*current)->prev==NULL)
        return;

    *current=(*current)->prev;
}

void displayPlaylist(Song* head){
    int i=1;
    Song* current=head;

    if(current==NULL)
        return;

    if(current->next==NULL){
        printf("Tek sarki: %s\n",current->name);
        return;
    }

    while(current!=NULL){
        printf("Sarki %d : %s\n",i,current->name);
        current=current->next;
        i++;
    }
}

int main(void){
    Song* head=NULL;
    Song* currentSong=NULL;
    char c=0;
    char isim[60];

    while(1){
        printf("\nSarki eklemek icin e, cikarmak icin c, listeyi gormek icin l, sonrakini oynatmak icin s, oncekini oynatmak icin o, cikmak icin q : ");
        scanf(" %c",&c);
        switch(c){
            case 'e':
                printf("Sarki ismi yaziniz : ");
                scanf("%s",isim);

                addSongToEnd(&head,isim);

                if(currentSong==NULL)
                    currentSong=head;

                break;

            case 'c':
                printf("Sarki listesi anlik : \n");
                displayPlaylist(head);

                printf("Cikarmak istediginiz sarkiyi giriniz : ");
                scanf("%s",isim);

                if(currentSong!=NULL && strstr(currentSong->name,isim)!=NULL){
                    if(currentSong->next!=NULL)
                        currentSong=currentSong->next;
                    else if(currentSong->prev!=NULL)
                        currentSong=currentSong->prev;
                    else
                        currentSong=NULL;
                }

                removeSong(&head,isim);

                if(head==NULL)
                    currentSong=NULL;

                break;

            case 'l':
                printf("Sarki listesi anlik : \n");
                displayPlaylist(head);
                break;

            case 's':
                playNext(&currentSong);

                if(currentSong!=NULL)
                    printf("Su an calan sarki : %s\n",currentSong->name);

                break;

            case 'o':
                playPrevious(&currentSong);

                if(currentSong!=NULL)
                    printf("Su an calan sarki : %s\n",currentSong->name);

                break;

            case 'q':
                return 0;

            default:
                break;
        }
    }

    return 0;
}

typedef struct Word {
char text[50];
struct Word* next;
} Word;
void pushWord(Word** top, char* text){
    Word* newNode=(Word*)malloc(sizeof(Word));
    strcpy(newNode->text,text);
    newNode->next=*top;
    *top=newNode;
}
void popWord(Word** top){
    if(*top==NULL)
        return;
    Word* silinecek = *top;
    printf("%s silinecek", (*top)->text);
    *top=(*top)->next;
    free(silinecek);
}
void showWords(Word* top){
    if(top==NULL)
        return;
    while(top!=NULL){
        printf("%s\n", top->text);
        top=top->next;
    }
    
}
int main(void){
    Word* head = NULL;
    int sayi;
    char text[50];
    int i;
    char c = 0;
    printf("Hangi operasyonu yapacan, kelime ekleme ise e, cikarma ise c, kelime listesi icin l\n");
    scanf("%c", &c);
    switch(c){
        case 'e':
            printf("Kac kelime ekleyecen : ");
            scanf("%d", &sayi);
            for(i=0; i<sayi; i++)
            {
                printf("%d.kelimeyi girin : \n", i+1);
                scanf("%s", text);
                pushWord(&head,text);
            }
            break;
        case'c':
            popWord(&head);
            break;
        case'l':
            showWords(head);
            break;
        default:
            break;
    }
    return 0;
}

typedef struct PrintJob {
    char fileName[50];
    struct PrintJob* next;
} PrintJob;

typedef struct Queue {
    PrintJob* front;
    PrintJob* rear;
} Queue;

void enqueuePrintJob(Queue* q, char* fileName){
    PrintJob* newNode=(PrintJob*)malloc(sizeof(PrintJob));
    strcpy(newNode->fileName,fileName);
    newNode->next=NULL;

    if(q->front==NULL){
        q->front=newNode;
        q->rear=newNode;
        return;
    }

    q->rear->next=newNode;
    q->rear=newNode;
}

void processNextJob(Queue* q){
    if(q->front==NULL)
        return;

    PrintJob* silinecek=q->front;

    printf("%s yazdiriliyor\n",q->front->fileName);

    q->front=q->front->next;

    if(q->front==NULL)
        q->rear=NULL;

    free(silinecek);
}

void showQueue(Queue q){
    PrintJob* current=q.front;

    if(current==NULL)
        return;

    while(current!=NULL){
        printf("%s\n",current->fileName);
        current=current->next;
    }
}

int main(void){
    Queue q;
    q.front=NULL;
    q.rear=NULL;

    int secim;
    char fileName[50];

    printf("Hangi operasyonu yapacan, dosya ekleme ise 1, yazdirma ise 2, kuyrugu gormek icin 3\n");
    scanf("%d",&secim);

    switch(secim){
        case 1:
            printf("Dosya adini giriniz : ");
            scanf("%s",fileName);
            enqueuePrintJob(&q,fileName);
            break;

        case 2:
            processNextJob(&q);
            break;

        case 3:
            showQueue(q);
            break;

        default:
            break;
    }

    return 0;
}
*/


