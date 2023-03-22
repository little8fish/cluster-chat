#ifndef CHATSERVICE_H
#define CHATSERVICE_H

#include <functional>
#include <unordered_map>
#include <muduo/net/TcpConnection.h>
#include <json.hpp>

using json = nlohmann::json;

using namespace std;
using namespace muduo;
using namespace muduo::net;

using MsgHandler = function<void(const TcpConnectionPtr &conn, json &js, Timestamp time)>;

class ChatService
{
public:
    static ChatService *instance();
    void login(const TcpConnectionPtr &conn, json &js, Timestamp time);
    void reg(const TcpConnectionPtr &conn, json &js, Timestamp time);

private:
    ChatService();
    unordered_map<int, MsgHandler> _msgHandlerMap;
};

#endif