# ifndef __HTTP_SERVER_HPP
# define __HTTPP_SERVER_HPP

# define MAX_EPOLL_EVENT 1024

class HttpServer {
	private:
		std::map <int, std::string>	_request;
		std::vector<Stream *>		_servers;
		int				_epolFd;
		std::vector<epoll_event>	_events;
	public:
		HttpServer();
		~HttpServer();

		std::vector<Stream *>	getStreams() const;

		void	printServers() const;
		void	addServer(Server *server);
		void	initEpollInstance();
		void	startServer();
		void	closeAllFd() const;

		static int				_sig;		

}

std::ostream	&operator<<(std::ostream &os, const p_locate &locate);

# endif
