#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include "Overload.h"

using namespace std;

class Server {
private:
    int m_port;
    int m_socket;

public:
    Server(int port) : m_port(port), m_socket(-1) {}

    ~Server() {
        if (m_socket != -1) {
            close(m_socket);
        }
    }

    bool start() {
        m_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (m_socket == -1) {
            cerr << "Failed to create socket" << endl;
            return false;
        }

        sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(m_port);
        server_addr.sin_addr.s_addr = INADDR_ANY;
        memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));

        if (bind(m_socket, (sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
            cerr << "Failed to bind socket" << endl;
            return false;
        }

        if (listen(m_socket, 10) == -1) {
            cerr << "Failed to listen on socket" << endl;
            return false;
        }

        cout << "Server started on port " << m_port << endl;

        while (true) {
            int client_socket = accept(m_socket, nullptr, nullptr);
            if (client_socket == -1) {
                cerr << "Failed to accept connection" << endl;
                continue;
            }

            handleClient(client_socket);
            close(client_socket);
        }

        return true;
    }

private:
    void handleClient(int client_socket) {
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        read(client_socket, buffer, sizeof(buffer) - 1);
        cout << "Received request: " << buffer << endl;

        string response = processRequest(buffer);
        write(client_socket, response.c_str(), response.size());
    }
};

int main() {
    Server server(8080);
    if (!server.start()) {
        return 1;
    }
    return 0;
}
