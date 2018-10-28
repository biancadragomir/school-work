#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
       int c;
       struct sockaddr_in server;
       uint16_t a, b, suma;

       c = socket(AF_INET, SOCK_STREAM, 0);
       if (c < 0) {
              printf("Eroare la crearea socketului client\n");
              return 1;
       }

       memset(&server, 0, sizeof(server));
       server.sin_port = htons(9999);
       server.sin_family = AF_INET;
       server.sin_addr.s_addr = inet_addr("127.0.0.1");

       if (connect(c, (struct sockaddr *) &server, sizeof(server)) < 0
              printf("Eroare la conectarea la server\n");
              return 1;
       }
       char msj[50];
       send(c, "hello from client", sizeof("hello from client"), 0);
       recv(c, &msj, sizeof(msj), 0);
       int bytes_recieved;
       bytes_recieved = recv(c, msj, 1024, 0);
       msj[bytes_recieved] = '\0';
       printf("the client got back: %s\n", msj);
       //suma = ntohs(suma);
       printf("bye\n");
       close(c);
}
