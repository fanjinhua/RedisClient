//
// Created by jfanner on 16-11-9.
//
#include "tcp_client.h"
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include "../err.h"

TcpClient::TcpClient(const std::string& host, const uint16_t& port)
{
    host_ = host.c_str();
    bzero(&servaddr_, sizeof(servaddr_));
    servaddr_.sin_family = AF_INET;
    servaddr_.sin_port = port;
}

int
TcpClient::connect()
{
    socket();
    if (inet_pton(AF_INET, host_, &servaddr_.sin_addr) <= 0)
        return err_ret_bool("inet_pton error for ", host_, false);
    if (connect(sockfd_, (struct sockaddr *) &servaddr_, sizeof(servaddr_)) < 0)
        err_sys("connect error");  // TODO
    return true;
}

void
TcpClient::socket()
{
    if ((sockfd_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        err_sys("socket error");
}

ssize_t
TcpClient::writen(int fd, const void *vptr, size_t n)
{
    size_t nleft;
    ssize_t nwritten;
    const char* ptr;

    nleft = n;
    ptr = (const char*)vptr;

    while(nleft > 0)
    {
        if ((nwritten = write(fd, ptr, nleft) <= 0))
        {
            if (nwritten < 0 && errno == EINTR)
                nwritten = 0;
            else
                return -1;
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return n;
}

int TcpClient::send(const std::string &text)
{
    writen(sockfd_, text.c_str(), text.length());
    return 0;
}
