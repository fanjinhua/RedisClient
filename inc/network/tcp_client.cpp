//
// Created by jfanner on 16-11-9.
//
#include "tcp_client.h"
#include <cstring>
#include <arpa/inet.h>
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
    if (inet_pton(AF_INET, host_, &servaddr_.sin_addr) <= 0)
        err_log("inet_pton error for ", host_);
    if (connect(sockfd_, (struct sockaddr *) &servaddr_, sizeof(servaddr_)) < 0)
        err_sys("connect error");  // TODO
}

int
TcpClient::socket()
{
    if ((sockfd_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        err_sys("socket error");
}
