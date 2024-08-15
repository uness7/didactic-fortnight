# ifndef STREAM_HPP
# define STREAM_HPP

# include "main.hpp"
# include "Server.hpp"

class Stream {
	protected:
		int				_socket_fd;	
		int				_epoll_fd;

		// containers
		std::map<Stream *, Stream *>	_servers;
		Server*				_server;

	public:
		Stream();
		Stream(int fd);
		Stream(int fd, Server *ptr);
		Stream(int fd, Server *ptr, int epoll_fd);
		virtual ~Stream();

		int				getSocketFd() const;
		Server				*getServer(void) const;

		void				setSocketFd(int fd);

		/* A pure virtual function, which means that is intended to be overridden by derived classes */
		virtual	int			handleRequest(int epoll_fd, epoll_event& ev) = 0;
}

# endif
