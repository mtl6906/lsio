#ifndef LS_IO_READER_H
#define LS_IO_READER_H

namespace ls
{
    namespace io
    {
        class Reader
        {
            public:
                virtual int read(void *data, int len) = 0;
                virtual int tryRead(void *data, int len) = 0;
        };
    }
}

#endif
