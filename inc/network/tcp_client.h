//
// Created by jfanner on 16-11-8.
//

#ifndef REDISCLIENT_TCP_CLIENT_H
#define REDISCLIENT_TCP_CLIENT_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string>

class TcpClient
{
public:
    TcpClient(const std::string& host, const uint16_t& port);
    int connect();

private:
    int sockfd_;
    struct sockaddr_in servaddr_;
    const char* host_;
    int socket();
};



#endif //REDISCLIENT_TCP_CLIENT_H
