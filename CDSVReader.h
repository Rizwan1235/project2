#ifndef CDSVREADER_H
#define CDSVREADER_H

#include <string>
#include <vector>
#include <fstream>

// Forward declaration for CDSVRow (not included here)
class CDSVRow;

class CDSVReader {
public:
    // Constructor to open a DSV file
    CDSVReader(const std::string& filename, char delimiter = ',');

    // Destructor to close the file
    ~CDSVReader();

    // Check if the reader is valid and ready to read
    bool isValid() const;

    // Read the next row from the file
    bool readRow(CDSVRow& row);

private:
    std::ifstream file_;
    char delimiter_;
};

#endif // CDSVREADER_H