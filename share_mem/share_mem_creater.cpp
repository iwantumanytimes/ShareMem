#include "share_mem_creater.h"


 

share_mem_creater::share_mem_creater(SM_NAME_CTYPE _sm_name, SM_SIZE_TYPE _size = SHARE_MEM_SIZE) :_sm_name_(_sm_name), _sm_size_(_size)
{ 
	init();
}

share_mem_creater::share_mem_creater(SM_NAME_CPLUSTYPE _sm_name, SM_SIZE_TYPE _size = SHARE_MEM_SIZE) : _sm_name_(_sm_name.c_str()), _sm_size_(_size)
{
	init();
}

share_mem_creater::share_mem_creater(SM_NAME_CPLUSTYPE _sm_name = "default") : _sm_name_(_sm_name.c_str()), _sm_size_(SHARE_MEM_SIZE)
{
	init();
}

 


share_mem_creater::~share_mem_creater()
{
}

bool share_mem_creater::init()
{

	while (1)
	{
		try {
			// creating our first shared memory object.  
			shared_memory_object sharedmem1(create_only, _sm_name_, read_write);

			// setting the size of the shared memory  
			sharedmem1.truncate(_sm_size_);
			// map the shared memory to current process   
			mapped_region mmap(sharedmem1, read_write);

			// access the mapped region using get_address  
			std::strcpy(static_cast<char*>(mmap.get_address()), "Hello World!\n");
			 
			return  1;
		}


		/************************************************************************/
		/*  共享内存存在，触发创建异常，删除，继续申请                                                                    */
		/************************************************************************/

		catch (interprocess_exception& e)
		{
			std::cout << e.what() << std::endl;
			int errcode = e.get_error_code();
			if (e.get_error_code() == 9)
			{
				shared_memory_object::remove(_sm_name_);
			}
			else
				return 0;
		}
	}

	
	
}
