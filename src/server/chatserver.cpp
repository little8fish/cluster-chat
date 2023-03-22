#include "chatserver.hpp"
#include <functional>
#include "json.hpp"
using namespace std;
using namespace placeholders;
using json = nlohmann::json;

ChatServer::ChatServer(EventLoop *loop,
                       const InetAddress &listenAddr,
                       const string &nameArg)
    : _server(loop, listenAddr, nameArg), _loop(loop)
{
    _server.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1));
    _server.setMessageCallback(std::bind(&ChatServer::onMessage, this, _1, _2, _3));
    _server.setThreadNum(4);
}
void ChatServer::start()
{
    _server.start();
}
void ChatServer::onConnection(const TcpConnectionPtr &conn)
{
    if (!conn->connected()) {
        conn->shutdown();
    }
}
void ChatServer::onMessage(const TcpConnectionPtr &conn,
               Buffer *buffer,
               Timestamp time)
{
    string buf = buffer->retrieveAllAsString();
    json js = json::parse(buf);

}