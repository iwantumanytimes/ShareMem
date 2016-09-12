#ifndef   _SHARE_MEM_CREATER_
#define   _SHARE_MEM_CREATER_
#include "string"
#include "boost/interprocess/managed_shared_memory.hpp"
#include "boost/interprocess/mapped_region.hpp"
#include "iostream"
#include "cstring"
using namespace boost::interprocess;
using namespace std;
class share_mem_creater
{
public:
	typedef  const char*  SM_NAME_TYPE;
	typedef  int          SM_SIZE_TYPE;
public:
	share_mem_creater(SM_NAME_TYPE  _sm_name, SM_SIZE_TYPE  _size);
	~share_mem_creater();
private:
	SM_NAME_TYPE  _sm_name_;
	SM_SIZE_TYPE  _sm_size_;
private:
	void  init();
};
#endif

