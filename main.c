#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage : %s [domainname]\n", argv[0]);
        exit(1);
    }

    struct hostent *mynet;
    mynet = gethostbyname(argv[1]);

    if (mynet == NULL)
        return 1;

    while (*mynet->h_addr_list != NULL)
    {
        printf("%s\n", inet_ntoa(*(struct in_addr *)*mynet->h_addr_list));
        mynet->h_addr_list++;
    }
    return 0;
}