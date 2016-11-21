//
// Created by jfanner on 16-11-10.
//

#ifndef REDISCLIENT_REDISCLIENT_H
#define REDISCLIENT_REDISCLIENT_H

#include "network/tcp_client.h"
#include "Reply.h"
#include <initializer_list>
#include <vector>
#include <functional>
#include <queue>
#include <mutex>

namespace redisclient
{
    using std::string;
    using std::vector;
    class RedisClient
    {
    public:
        typedef         std::function<void(Reply&)>      callback_handler_t;
    public:
        bool connect(const std::string& host = "127.0.0.1", const uint16_t& port = 6379);
        bool set(const string& key, const string& value, const callback_handler_t& callback);
        string& get(const string& key);
        string& hmset(const std::initializer_list& ls);
    private:
        string send_buf_;
        string recv_buf_;
        std::queue<callback_handler_t> callbacks_;
        std::mutex callbacks_mutex_;
        void reply_handler(TcpClient& tcp_cli, Reply& reply);

        bool send(const string& text, const callback_handler_t& callback);
        const string serialization(const vector<string>& args);
    };
}


#endif //REDISCLIENT_REDISCLIENT_H
