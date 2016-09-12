#include "share_mem_creater.h"


 

share_mem_creater::share_mem_creater(SM_NAME_TYPE _sm_name, SM_SIZE_TYPE _size = 1) :_sm_name_(_sm_name), _sm_size_(_size)
{
	init();
}


share_mem_creater::~share_mem_creater()
{
}

void share_mem_creater::init()
{
	try {
		// creating our first shared memory object.  
		shared_memory_object sharedmem1(create_only, _sm_name_, read_write);

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
}
