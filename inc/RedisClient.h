//
// Created by jfanner on 16-11-10.
//

#ifndef REDISCLIENT_REDISCLIENT_H
#define REDISCLIENT_REDISCLIENT_H

#include "network/tcp_client.h"
#include <functional>

namespace redisclient
{
    class RedisClient
    {
    public:
        bool connect(const std::string& host = "127.0.0.1", const uint16_t& port = 6379);

    private:

    };
}


#endif //REDISCLIENT_REDISCLIENT_H
