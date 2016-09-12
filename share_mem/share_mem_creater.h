#ifndef   _SHARE_MEM_CREATER_
#define   _SHARE_MEM_CREATER_
#include "string"
#include "boost/lexical_cast.hpp"
#include "boost/interprocess/managed_shared_memory.hpp"
#include "boost/interprocess/mapped_region.hpp"
#include "iostream"
#include "cstring"
using namespace boost::interprocess;
const int  SHARE_MEM_SIZE = 1024 ;
 


using namespace std;
class share_mem_creater
{
public:
	typedef  const char*  SM_NAME_CTYPE;
	typedef  std::string  SM_NAME_CPLUSTYPE;
	typedef  int          SM_SIZE_TYPE;
public:
	share_mem_creater(SM_NAME_CTYPE  _sm_name, SM_SIZE_TYPE  _size);
	share_mem_creater(SM_NAME_CPLUSTYPE  _sm_name, SM_SIZE_TYPE  _size);
	share_mem_creater(SM_NAME_CPLUSTYPE  _sm_name);
	~share_mem_creater();
private:
	SM_NAME_CTYPE  _sm_name_;
	SM_SIZE_TYPE   _sm_size_;
private:
	bool  init();//检查并删除旧的共享内存

};
#endif

