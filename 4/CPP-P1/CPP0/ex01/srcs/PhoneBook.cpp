#include "PhoneBook.hpp"

// init main (test)
int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << " <name>" << std::endl;
		return (1);
	}

	std::cout << "Hello, " << argv[1] << "!" << std::endl;

	return (0);
}
