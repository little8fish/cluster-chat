#include "chatservice.hpp"
#include "public.hpp"

ChatService *ChatService::instance()
{
    static ChatService service;
    return &service;
}
ChatService::ChatService(){
    _msgHandlerMap.insert({LOGIN_MSG, std::bind(&ChatService::login, this, _1, _2, _3)});
    _msgHandlerMap.insert({REG_MSG, std::bind(&ChatService::login, this, _1, _2, _3)});
}
void ChatService::login(const TcpConnectionPtr &conn, json &js, Timestamp time) {


}
void ChatService::reg(const TcpConnectionPtr &conn, json &js, Timestamp time) {

}