// extent wire protocol

#ifndef extent_protocol_h
#define extent_protocol_h

#include "rpc.h"

class extent_protocol {
 public:
  typedef int status;
  typedef unsigned long long extentid_t;     // 文件名

  //rpc的请求号和状态号
  //返回状态
  // RETRY: try again
  // RPCERR: rpc error
  // NOENT: no such file or directory
  // IOERR: io error
  enum xxstatus { OK, RPCERR, NOENT, IOERR };
  enum rpc_numbers {
    put = 0x6001,
    get,
    getattr,
    remove
  };

  struct attr {                              // 文件属性
    unsigned int atime;    //读取或执行时修改
    unsigned int mtime;    //修改属性时修改
    unsigned int ctime;    //写入时修改
    unsigned int size;
  };
};

inline unmarshall &
operator>>(unmarshall &u, extent_protocol::attr &a)
{
  u >> a.atime;
  u >> a.mtime;
  u >> a.ctime;
  u >> a.size;
  return u;
}

inline marshall &
operator<<(marshall &m, extent_protocol::attr a)
{
  m << a.atime;
  m << a.mtime;
  m << a.ctime;
  m << a.size;
  return m;
}

#endif 
