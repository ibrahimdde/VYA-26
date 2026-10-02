#include <stdio.h>
/*
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

*/


int main(void){
    int x;
    int xinit;
    int y = 0;
    int z = 0;
    int i;
    int a=0;
    printf("Bir sayi giriniz : ");
    scanf("%d", &x);
    xinit = x;
    int temp = x;
    while(x>0){
        x=x/10;
        z++;
    }
    for(i=0;i<z; i++){
        a=temp%10;
        temp=temp/10;
        y+=a;
        y=y*10;
    }
    y=y/10;
    if(xinit==y)
        printf("Girdiginiz sayi palindrom \n");
    else
        printf("Girdiginiz sayi palindrom degil \n");
    
    return 0;
}
