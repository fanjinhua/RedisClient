//
// Created by jfanner on 16-11-12.
//
#include "../inc/RedisClient.h"
#include <stdexcept>

namespace redisclient
{
    TcpClient* tcp_cli;
    static const string& CRLF = "\r\n";

    void reply_handler(TcpClient& tcp_cli, Reply& reply)
    {

    }

    bool RedisClient::connect(const std::string &host, const uint16_t &port)
    {
        tcp_cli = new TcpClient(host, port);


        if(!(tcp_cli->connect(reply_handler) ))
            throw std::runtime_error("Can't connected!");
        return true;
    }

    bool RedisClient::set(const string& key, const string& value, const callback_handler_t& callback)
    {
        send(serialization(vector<string>{"SET", key, value}), callback);
        return false;
    }

    string& RedisClient::get(const string &key)
    {
    }

    string &RedisClient::hmset(const std::initializer_list &ls)
    {

        return <#initializer#>;
    }

    bool RedisClient::send(const string& text, const RedisClient::callback_handler_t &callback)
    {
        std::lock_guard<std::mutex> lock(callbacks_mutex_);
        tcp_cli->send(text);
        callbacks_.push(callback);
        return true;
    }

    const string RedisClient::serialization(const vector<string>& args)
    {
        string ret("*");
        ret += std::to_string(args.size()) + CRLF;
        for (auto arg : args)
            ret += '$' + std::to_string(arg.size()) + CRLF + arg + CRLF;

        return ret;
    }

}
