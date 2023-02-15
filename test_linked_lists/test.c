#include <unistd.h>

int	main(void)
{
	write(2, "error", 5);
	return (0);
}
