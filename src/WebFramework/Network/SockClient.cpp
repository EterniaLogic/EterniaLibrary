#include "SockClient.h"

SockClient::SockClient() {
#ifdef WINDOWSXX
    ClientSocket = INVALID_SOCKET;
#endif
    this->alive = true;
}
