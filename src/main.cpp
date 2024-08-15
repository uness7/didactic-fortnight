# include "Parser.hpp"
# include "HttpServer.hpp"

//int	main(int ac, char *av[])
int	main(void)
{
	/*
	if (ac != 2)
	{
		std::cout << "Usage: ./WebServ [config_file]" << std::endl;
		return (0);
	}
	HttpServer	httpServer;
	const std::string	filename = av[1];
	if (!Parser::parse(filename, httpServer))
	{
		std::cout << Parser::getError() << '\n';
		return (0);
	}
	httpServer.printServers();
	try {
		httpServer.startServer();
	} catch (const std::exception& e) {
		std::cerr << "Catch " << e.what() << '\n';
	}
	*/
	std::cout << "hello world" << std::endl;
	return (0);
}
