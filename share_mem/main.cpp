#include "boost/interprocess/managed_shared_memory.hpp"
#include "boost/interprocess/mapped_region.hpp"
#include "iostream"
#include "cstring"
using namespace boost::interprocess;
int main()
{
	try {
		// creating our first shared memory object.  
		shared_memory_object sharedmem1(create_only, "Hello", read_write);

		// setting the size of the shared memory  
		sharedmem1.truncate(256);
		// map the shared memory to current process   
		mapped_region mmap(sharedmem1, read_write);

		// access the mapped region using get_address  
		std::strcpy(static_cast<char*>(mmap.get_address()), "Hello World!\n");

		// бн more code follows  
	}
	catch (interprocess_exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 1;
}