#include <fcntl.h>
#include <iostream>
#include <fstream>
#include <unistd.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;
    // 文件的打开模式下有大量的组合方式,为了简便操作干脆不想了,直接用宏来替代
    if ((fd = creat("file.hole", FILE_MODE)) < 0)
        printf("creat error");

    if (write(fd, buf1, 10) != 10)
        printf("buf1 write error");
    /* offset now = 10 */

// 注意,不要经常性的操作一个文件,没有什么意思
    if (lseek(fd, 16384, SEEK_SET) == -1)
        printf("lseek error");
    /* offset now = 16384 */

    if (write(fd, buf2, 10) != 10)
        printf("buf2 write error");
    /* offset now = 16394 */

    exit(0);
}
