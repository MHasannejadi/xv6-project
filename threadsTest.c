#include "types.h"
#include "stat.h"
#include "user.h"

void childPrint(void* args){
    printf(1, "Argument of child functions when running now : %d\n", *(int*) args);
}

int main(void){
    int argument = 0x0F01; // 3841 in decimal
    int thread_id = thread_create(&childPrint, (void*)&argument);
    if(thread_id < 0)
        printf(1,"Something went wrong with thread create call.\n");

    join();

    printf(1, "thread id:  %d\n", thread_id);

    exit();
} 