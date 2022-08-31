#include "ls/io/InputStream.h"
#include "ls/Exception.h"
#include "ls/cstring/API.h"
#include "ls/DefaultLogger.h"

using namespace std;

namespace ls
{
    namespace io
    {
        InputStream::InputStream(Reader *reader, Buffer *buffer) : reader(reader), buffer(buffer)
        {

        }

        void InputStream::reset(Reader *reader)
        {
            this -> reader = reader;
        }

	void InputStream::reset(Buffer *buffer)
	{
	    this -> buffer = buffer;
	}

        int InputStream::read()
        {
            int n = reader -> read(buffer -> end(), buffer -> restSize());
	    if(n < 0)
		    return n;
            buffer -> moveBuffersize(n);
	    return Exception::LS_OK;
        }

        int InputStream::tryRead()
        {
            int n = 0;
            while(buffer -> restSize() > 0)
            {
                n = reader -> tryRead(buffer -> end(), buffer -> restSize());
		if(n < 0)
			return n;
		LOGGER(ls::INFO) << "read " << n << "size" << ls::endl;
                buffer -> moveBuffersize(n);
            }
	    return Exception::LS_OK;
	}

        string InputStream::splitOf(int &ec, const char *endMark, int len)
        {
	  ec = Exception::LS_OK;
          if(buffer -> size() == 0)
	  {
		ec = Exception::LS_ENOCONTENT;
		return "";
	  }
          int n = buffer -> findFirstOf(endMark, len);
          if(n < 0)
	  {
              ec = Exception::LS_EFORMAT;
	      return "";
	  }
	  string result(n, '\0');
          buffer -> pop(result);
          buffer -> moveOffset(1);
          return result;
        }

        string InputStream::split(int &ec, const string &endMark, bool with)
        {
	    ec = Exception::LS_OK;
            if(buffer -> size() == 0)
	    {
                ec = Exception::LS_ENOCONTENT;
		return "";
	    }
            int len = buffer -> find(endMark.c_str(), endMark.size());
            if(len < 0)
	    {
                ec = Exception::LS_EFORMAT;
		return "";
	    }
            int endMarkSize = (with ? endMark.size() : 0);
            string result(len + endMarkSize, '\0');
            buffer -> pop(result);
            if(with == false)
              buffer -> moveOffset(endMark.size());
            return result;
        }

        string InputStream::split()
        {
            string text(buffer -> size(), '\0');
            buffer -> pop(text);
            return text;
        }

        string InputStream::split(int &ec, int n)
        {
	    ec = Exception::LS_OK;
	    if(buffer -> size() < n)
	    {
		   ec = Exception::LS_ENOCONTENT;
		   return "";
	    }
            string text(n, '\0');
	    buffer -> pop(text);
            return text;
        }

	Buffer *InputStream::getBuffer()
	{
	    return buffer;
	}

        bool InputStream::full()
        {
        	return buffer -> restSize() == 0;
        }
    }
}
