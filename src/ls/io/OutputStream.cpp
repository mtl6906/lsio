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

        void OutputStream::write()
        {
            int n = 0;
            while(buffer -> size() > 0)
            {
                n = writer -> write(buffer -> begin(), buffer -> size());
                buffer -> moveOffset(n);
            }
        }

        void OutputStream::tryWrite()
        {
            int n = 0;
            while(buffer -> size() > 0)
            {
                n = writer -> tryWrite(buffer -> begin(), buffer -> size());
                buffer -> moveOffset(n);
            }
        }

        void OutputStream::append(const string &text)
        {
            if(text.size() > buffer -> restSize())
                throw Exception(Exception::LS_EFULL);
            buffer -> push(text);
        }

      	void OutputStream::append(const char *data, int len)
      	{
      	    if(len > buffer -> restSize())
      	        throw Exception(Exception::LS_EFULL);
      	    buffer -> push(data, len);
      	}

        Buffer *OutputStream::getBuffer()
        {
            return buffer;
        }
    }
}
