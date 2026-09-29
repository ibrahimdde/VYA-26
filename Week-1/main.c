#include <stdio.h>

int main(void){
    int x[10];
    int i;
    printf("10 adet sayi giriniz = ");
    for(i=0;i<10;i++){
        scanf("%d", &x[i]);
    }
    printf("Girdiginiz sayilar sirasiyla = ");
    for(i=0;i<10;i++){
        printf("%d\n", x[i]);
    }
    
    
    
    return 0;
}
