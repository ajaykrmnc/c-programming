#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main(){
    // ftok to generate unique key
    key_t key = ftok("memory", 67);

    // shget return an identifier in shmid
    // The shmget() system call creates the shared memory segment in an os.
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);
    // shmflg parameter takes the parameters to create the shared memory segment
    if(shmid == -1){
        printf("Unable to creat the Shared Memory segment");
    }
    // shmat to attach to shared Memory
    char *str = (char *)shmat(shmid, (void *)0, 0);
    // void * shmat(int shmid, const void *shmaddr,int shmflg)
    printf("Enter Data to write into the shared Memory Segment: ");
    scanf("%[^\n]&*c", str);
    printf("Data written in memory: %s\n", str);
    // detach from shared Memory
    shmdt(str);
}