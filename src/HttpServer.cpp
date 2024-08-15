# include "HttpServer.hpp"

HttpServer::HttpServer() : _events(MAX_POLL_EVENT)
{
}

HttpServer::HttpServer()
{
	for (size_t i = 0; i < _servers.size(); i++)
		delete _servers[i];
}

// Printing server logs and details
void	HttpServer::printServers() const
{
}

/* This function will init the instance that the HttpServer will use to manage multiple socket connections */
/* It created an epoll file descriptor and registers each server's socket file with epoll, setting it up to listen for incoming data or connections EPOLLIN events */
void	HttpServer::initEpollInstance()
{
}

void	HttpServer::closeAllFd() const
{
}

/* It adds a Serve obj to _servers vector allowing the http server to manage multiple servers */
void	HttpServer::addServer(Server *serv)
{
}

/*
 * This is the function that starts the server's main event loop. 
 * This loop awaits for epoll instance (new connections) and processes them. 
 * It handles requests for each server.
 * epoll_wait() takes in : 
 * 	1. epoll fd.
 * 	2. a ptr to the 1st element of the vector this->_events where the events data will be stored.
 * 	3. the max number of events to process at once which corresponds to the number of servers.  
 * 	4. -1 (the timeout value) where -1 means that the functions wil wait indefinitely untill an event occurs.
 * */

void	HttpServer::startServer(void)
{
	int		local_num_events; 

	initEpollInstance();	
	while (this->_sig != 1)
	{
		if (this->_sig == 1)
			break ;
		if ((local_num_events = epoll_wait(this->_epollFd, this->_servers.size(), -1)) < 0 && this->_sig != 0)
				std::cout << "Epoll_wait sys call has failed\n";
		// Here we are processing each event returned by epoll_wait()
		for (int i = 0; i < local_num_events; i++)
		{
			Stream	*stream	= static_cast<Stream *>(_events[i].data.ptr); // generic type conversion
			if (stream->handleRequest(this->_epollFd, this->_events[i]) == -1)
				stream->getServer()->deleteFromMap(stream);
		}
	}
}

std::vector<Stream *>	HttpServer::getStreams() const
{
	return this->_servers;
}

int	HttpServer::_sig = 0;
