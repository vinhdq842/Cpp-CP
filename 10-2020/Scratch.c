#include <pthread.h>
#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#define DELAY	sleep(rand() % 4)
#define TRUE 1
#define FALSE 0
int account; // tai khoan ngan hang
int turn;
int interest[2];

void enter_region(int pid) {
    int other;
    //...
}

void leave_region(int pid) {
    //...
}
void *chaGuiTien() {  // luot =0
    int x;
    while (1) {
        // ...
        x=account; DELAY;
        x=x+2; DELAY;
        account=x; DELAY;
        printf("Tao da gui. Account=%d\n", account);
        // ...
    }
}

void *conRutTien() { // luot =1
    int y;
    while (1) {
        // ...
        y=account; DELAY;
        y=y-3; DELAY;
        if (y>=0) { account=y; printf("Con da rut. Account=%d\n", account);}
        else printf("Khong du tien\n");
        // ...
        DELAY;
    }
}
void main() {
    pthread_t tid1, tid2;

    printf("Account=%d\n",account);
    pthread_create(&tid1, NULL, chaGuiTien, NULL);
    pthread_create(&tid2, NULL, conRutTien, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}
