#ifndef CDATASINK_H
#define CDATASINK_H

#include <string>
class CDataSink {
public:
    virtual ~CDataSink() = default;

    // Pure virtual method to write data to the sink
    virtual void writeData(const std::string& data) = 0;
};

#endif // CDATASINK_H