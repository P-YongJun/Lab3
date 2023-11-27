#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    umask(0);

    if (creat("test1.txt", mode) < 0) {
        perror("creat: test1.txt");
        exit(1);
    }

    // 두 번째 umask 호출 제거
    if (creat("test2.txt", mode) < 0) {
        perror("creat: test2.txt");
        exit(1);
    }

    return 0;
}