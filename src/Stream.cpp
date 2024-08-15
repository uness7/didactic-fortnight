# include "Stream.hpp"

Stream::Stream() : _socket_fd(-1), _epoll_fd(-1), _server(NULL)
{
}

Stream::Stream(int fd) : _socket_fd(fd)
{
}

Stream::Stream(int fd, Server *ptr) : _socket_fd(fd), _server(ptr) 
{
}

Stream::Stream(int fd, Server *ptr, int epfd) : _socket_fd(fd), _epoll_fd(epfd), _server(ptr)
{
}

Server*	Stream::getServer(void) const
{
	return this->_server;
}

void	Stream::setSocketFd(int fd)
{
	this->_socketFd = fd;
}
