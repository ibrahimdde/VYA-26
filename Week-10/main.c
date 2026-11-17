#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int graf[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0}
};

char *sehirler[5] = {
    "Istanbul", "Ankara", "Bursa", "Izmir", "Antalya"
};

int ziyaret[5] = {0};
void DFS(int x){
    ziyaret[x]=1;
    printf("%s ", sehirler[x]);
    for(int i=0; i<5; i++){
        if(graf[x][x] == 1 && ziyaret[i]==0)
            DFS(i);
    }
}

int main(void){
    
    for (int i = 0; i < 5; i++) {
        DFS(i);
    }

    return 0;
    }

