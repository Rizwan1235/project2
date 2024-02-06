#ifndef CSTRINGDATASOURCE_H
#define CSTRINGDATASOURCE_H
#include "CDataSource.h"
class CStringDataSource : public CDataSource {
public:
    CStringDataSource(const std::string& data) : data_(data) {}
    std::string readData() override { return data_; }
private:
    std::string data_;
};
#endif // CSTRINGDATASOURCE_H