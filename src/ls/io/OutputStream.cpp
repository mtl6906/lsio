#include "ls/io/OutputStream.h"
#include "ls/Exception.h"
#include "ls/DefaultLogger.h"

using namespace std;

namespace ls
{
    namespace io
    {
        OutputStream::OutputStream(Writer *writer, Buffer *buffer) : writer(writer), buffer(buffer)
        {

        }

        void OutputStream::reset(Writer *writer)
        {
            this -> writer = writer;
        }

	void OutputStream::reset(Buffer *buffer)
	{
	    this -> buffer = buffer;
	}

        int OutputStream::write()
        {
            int n = 0;
            while(buffer -> size() > 0)
            {
                n = writer -> write(buffer -> begin(), buffer -> size());
      		if(n < 0)
			return n;
      		buffer -> moveOffset(n);
            }
	    return Exception::LS_OK;
        }

        int OutputStream::tryWrite()
        {
            int n = 0;
            while(buffer -> size() > 0)
            {
                n = writer -> tryWrite(buffer -> begin(), buffer -> size());
		if(n < 0)
			return n;
                buffer -> moveOffset(n);
            }
	    return Exception::LS_OK;
        }

        int OutputStream::append(const string &text)
        {
            if(text.size() > buffer -> restSize())
		return Exception::LS_EFULL;
            buffer -> push(text);
	    return Exception::LS_OK;
        }

      	int OutputStream::append(const char *data, int len)
      	{
      	    if(len > buffer -> restSize())
      	        return Exception::LS_EFULL;
      	    buffer -> push(data, len);
	    return Exception::LS_OK;
      	}

        Buffer *OutputStream::getBuffer()
        {
            return buffer;
        }
    }
}
