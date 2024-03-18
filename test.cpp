#include <iostream>
using namespace std;

#define MAX_CLIENTS 1000

struct client
{
    int fd;     // Client socket.
    char *nick; // Nickname of the client.
};

/* This global structure encapsulates the global state of the chat. */

// 全局的聊天状态

struct chatState
{
    int serversock;                      // Listening server socket.
    int numclients;                      // 用户的数量              // Number of connected clients right now.
    int maxclient;                       // 用户的槽              // The greatest 'clients' slot populated.
    struct client *clients[MAX_CLIENTS]; // 这里有根指针,指向,并且他的大小很大
                                         // Clients are set in the corresponding
                                         // slot of their socket descriptor.
};
//

void test_fcntl()
{
    // 这个的前提是能够进行文件的基本操作,这里就要跳出去了
}

int main(int argc, char const *argv[])
{
    printf("\033[31m--------华丽的分割线--------\033[0m\n");

#ifdef DIAN_COMPILE
    /* snprintf  的用法,
    这里需要注意的点是,可以确定缓冲区的问题,一般情况下没有
    一个通用的方法来解决缓冲区不匹配的的问题,所以使用一些技巧,
    考虑到可能发生的所有情况,然后分别处理才是正确的

     */

    char buffer[20];
    int num = 42;

    int length = snprintf(buffer, sizeof(buffer), "The answer is %d", num);

    if (length >= 0 && length < sizeof(buffer))
    {
        printf("Formatted string: %s\n", buffer);
    }
    else
    {
        printf("Buffer too small!\n");
    }

    chatState c;

    for (size_t i = 0; i < 100; i++)
    {
        std::cout << i << " ";
    }

#endif
    return 0;
}
