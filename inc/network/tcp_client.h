//
// Created by jfanner on 16-11-8.
//

#ifndef REDISCLIENT_TCP_CLIENT_H
#define REDISCLIENT_TCP_CLIENT_H

#include "../Reply.h"
#include <sys/socket.h>
#include <sys/types.h>   // uint16_t
#include <netinet/in.h>
#include <string>
#include <functional>

class TcpClient
{
public:
    TcpClient(const std::string& host, const uint16_t& port);
    int connect(std::function<void(TcpClient&, redisclient::Reply&)> reply_handler);
    int send(const std::string& text);
private:
    int sockfd_;
    struct sockaddr_in servaddr_;
    const char* host_;
    void socket();
    ssize_t writen(int fd, const void *vptr, size_t n);
    ssize_t readn(int fd);
};



#endif //REDISCLIENT_TCP_CLIENT_H
