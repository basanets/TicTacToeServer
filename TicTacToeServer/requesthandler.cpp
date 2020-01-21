#include "requesthandler.h"
#include "requests/request.h"
#include "reply.h"
#include "connection.h"

#include "QJsonObject"

RequestHandler::RequestHandler(QObject *parent) : QObject(parent)
{

}

Reply RequestHandler::handle(const TestRequest & /*request*/)
{
    return Reply();
}

Reply RequestHandler::handle(const UnknownRequest & /*request*/)
{
    return Reply();
}

Reply RequestHandler::handle(const InvalidRequest &/*request*/)
{
    return Reply();
}

Reply RequestHandler::handle(const SignInRequest &/*request*/)
{
    return Reply();
}

Reply RequestHandler::handle(const SignUpUserRequest &/*request*/)
{
    return Reply();
}

Reply RequestHandler::handle(const FindGameRequest &/*request*/)
{
    return Reply();
}

Reply RequestHandler::handle(const GetStatisticsRequest &/*request*/)
{
    return Reply();
}

void RequestHandler::onRequestReady(std::shared_ptr<Request> request)
{
    Connection * connection = static_cast<Connection*>(sender());

    Reply reply = request->handle(this);

    connection->onReplyReady(reply);
}
