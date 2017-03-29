#include "SockClient.h"

SockClient::SockClient() {
    ClientSocket = INVALID_SOCKET;
    this->alive = true;
}
