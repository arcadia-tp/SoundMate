#include <server.hpp>

    
Server::Server(HandleThreads *handle_threads, int port) : handle_threads_(handle_threads),
                                                          port_(port) {}
void Server::RunThreads() {}

void HandleThreads::ClientsThreadHandle() {}
void HandleThreads::SearchThreadHandle() {}
void HandleThreads::DataBaseWriteThreadHandle() {}
void HandleThreads::DataBaseReadThreadHandle() {}
void HandleThreads::AcceptConnectionsThreadHandle() {}

void ClientAcceptor::FaitForClient() {}
