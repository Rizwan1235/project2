#ifndef CDSVWRITER_H
#define CDSVWRITER_H
#include <string>
#include <vector>
#include <fstream>
// Forward declaration for CDSVRow (not included here)
class CDSVRow;
class CDSVWriter {
public:
    // Constructor to open a DSV file
    CDSVWriter(const std::string& filename, char delimiter = ',');
    // Destructor to close the file
    ~CDSVWriter();
    // Check if the writer is valid and ready to write
    bool isValid() const;
   // Write a row to the file
    bool writeRow(const CDSVRow& row);
private:
    std::ofstream file_;
    char delimiter_;
};

#endif // CDSVWRITER_H
