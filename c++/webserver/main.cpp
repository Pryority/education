#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cerrno>
#include <stdio.h>

const int PORT = 8080;
const std::string WEB_ROOT = "./";

void handleClient(int clientSocket)
{
    /* -- CLIENT HANDLER CONFIG ------------------------ */
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    read(clientSocket, buffer, sizeof(buffer));

    std::istringstream request(buffer);
    std::string requestLine;
    getline(request, requestLine);

    std::istringstream requestLineStream(requestLine);
    std::string method, filePath, httpVersion;
    requestLineStream >> method >> filePath >> httpVersion;

    printf("\t🔌✅ ==> ACCEPTED CONNECTION for file: %s\n", filePath.c_str());

    /* -- ROUTES ------------------------ */
    if (filePath == "/" || filePath.empty())
    {
        filePath = "/index.html";
    }
    else if (filePath == "/about")
    {
        filePath = "/about.html";
    }
    else
    {
        filePath = "/index.html";
    }

    std::string fullPath = WEB_ROOT + filePath;

    /* -- SERVER RESPONSES -------------- */
    std::ifstream file(fullPath);
    if (!file.is_open())
    {
        // If the file doesn't exist, respond with a 404 Not Found
        std::string notFoundResponse = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n";
        notFoundResponse += "<html><body><h1>404 Not Found</h1></body></html>";
        write(clientSocket, notFoundResponse.c_str(), notFoundResponse.length());
    }
    else
    {
        // If the file exists, read its content and respond with a 200 OK
        std::ostringstream fileContent;
        fileContent << file.rdbuf();

        std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
        response += fileContent.str();
        write(clientSocket, response.c_str(), response.length());
    }

    close(clientSocket);
}

int requirePortBindOK(int &serverSocket, sockaddr_in &serverAddress)
{

    if (::bind(serverSocket, reinterpret_cast<struct sockaddr *>(&serverAddress), sizeof(serverAddress)) == -1)
    {
        printf("\t🚢🚫 ==> ERROR BINDING on port %d\n", PORT);
        close(serverSocket);
        return 1;
    }

    return 0;
}

int requireListeningOK(int &serverSocket)
{
    if (listen(serverSocket, 10) == -1)
    {
        printf("\t📡🚫 ==> ERROR LISTENING on port %d\n", PORT);
        close(serverSocket);
        return 1;
    }

    return 0;
}

int requireSocketCreatedOK(int &serverSocket)
{
    if (serverSocket == -1)
    {
        printf("\t📞🚫 ==> ERROR CREATING SOCKET on port %d\n", PORT);
        return 1;
    }

    return 0;
}

int main()
{

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    requireSocketCreatedOK(serverSocket);
    requirePortBindOK(serverSocket, serverAddress);
    requireListeningOK(serverSocket);

    printf("\t📡 ==> OK SERVER LISTENING on port %d...\n", PORT);

    /* -- CLIENT HANDLER LOOP  ---------------- */
    while (true)
    {
        sockaddr_in clientAddress;
        socklen_t clientAddressLen = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, reinterpret_cast<struct sockaddr *>(&clientAddress), &clientAddressLen);

        if (clientSocket == -1)
        {
            printf("\t🔌🚫 ==> ERROR accepting connections: %s\n", strerror(errno));
            continue;
        }

        handleClient(clientSocket);
    }

    close(serverSocket);

    return 0;
}
