//
// Created by jfanner on 16-11-9.
//

#ifndef REDISCLIENT_ERR_H
#define REDISCLIENT_ERR_H

#include <iostream>
using std::endl;

void
err_sys(const char* message)
{
    std::cerr << message;
    exit(1);
}

void
err_log(const char* message, const char* arg= nullptr)
{
    std::clog << message << arg << endl;
}
#endif //REDISCLIENT_ERR_H
