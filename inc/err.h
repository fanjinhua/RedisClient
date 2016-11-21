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

bool
err_ret_bool(const char* message, const char* arg = nullptr, bool ret = false)
{
    err_log(message, arg);
    return ret;
}
#endif //REDISCLIENT_ERR_H
