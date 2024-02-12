#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cerrno>

const int PORT = 8080;
const std::string WEB_ROOT = "./";

void handleClient(int clientSocket)
{
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    read(clientSocket, buffer, sizeof(buffer));

    std::istringstream request(buffer);
    std::string requestLine;
    getline(request, requestLine);

    std::istringstream requestLineStream(requestLine);
    std::string method, filePath, httpVersion;
    requestLineStream >> method >> filePath >> httpVersion;

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

int main()
{

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
    {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    if (::bind(serverSocket, reinterpret_cast<struct sockaddr *>(&serverAddress), sizeof(serverAddress)) == -1)
    {
        std::cerr << "Error listening on port " << PORT << "\n";
        close(serverSocket);
        return 1;
    }

    if (listen(serverSocket, 10) == -1)
    {
        std::cerr << "Error listening on port " << PORT << "\n";
        close(serverSocket);
        return 1;
    }

    std::cout << "Server listening on port " << PORT << "...\n";

    while (true)
    {
        sockaddr_in clientAddress;
        socklen_t clientAddressLen = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, reinterpret_cast<struct sockaddr *>(&clientAddress), &clientAddressLen);

        if (clientSocket == -1)
        {
            std::cerr << "Error accepting connections: " << strerror(errno) << "\n";
            continue;
        }

        std::cout << "Accepted connection\n";

        handleClient(clientSocket);
    }

    close(serverSocket);

    return 0;
}