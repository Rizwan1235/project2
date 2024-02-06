#ifndef CDATASOURCE_H
#define CDATASOURCE_H

#include <string>

class CDataSource {
public:
    virtual ~CDataSource() = default;

    // Pure virtual method to read data from the source
    virtual std::string readData() = 0;
};

#endif