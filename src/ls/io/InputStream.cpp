#include "ls/io/InputStream.h"
#include "ls/Exception.h"
#include "ls/cstring/API.h"

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
            buffer -> clear();
            this -> reader = reader;
        }

        void InputStream::read()
        {
            int n = reader -> read(buffer -> end(), buffer -> restSize());
            buffer -> moveBuffersize(n);
        }

        void InputStream::tryRead()
        {
            int n = 0;
            while(buffer -> restSize() > 0)
            {
                n = reader -> tryRead(buffer -> end(), buffer -> restSize());
                buffer -> moveBuffersize(n);
            }
        }

        string InputStream::splitOf(const char *endMark, int len)
        {
          if(buffer -> size() == 0)
              throw Exception(Exception::LS_ENOCONTENT);
          int n = buffer -> findFirstOf(endMark, len);
          if(n < 0)
              throw Exception(Exception::LS_EFORMAT);
          string text(n, '\0');
          buffer -> pop(text);
          buffer -> moveOffset(1);
          return text;
        }

        string InputStream::split(const string &endMark, bool with)
        {
            if(buffer -> size() == 0)
                throw Exception(Exception::LS_ENOCONTENT);
            int len = buffer -> find(endMark.c_str(), endMark.size());
            if(len < 0)
                throw Exception(Exception::LS_EFORMAT);
            int endMarkSize = (with ? endMark.size() : 0);
            string text(len + endMarkSize, '\0');
            buffer -> pop(text);
            if(with == false)
              buffer -> moveOffset(endMark.size());
            return text;
        }

        string InputStream::split()
        {
            string text(buffer -> size(), '\0');
            buffer -> pop(text);
            return text;
        }

        string InputStream::split(int n)
        {
	  if(buffer -> size() < n)
		  throw Exception(Exception::LS_ENOCONTENT);
          string text(n, '\0');
	  buffer -> pop(text);
          return text;
        }

        bool InputStream::full()
        {
        	return buffer -> restSize() == 0;
        }
    }
}
