#include "CDSVReader.h"
#include "CDSVRow.h" // Include necessary implementation

CDSVReader::CDSVReader(const std::string& filename, char delimiter) :
    delimiter_(delimiter) {
    file_.open(filename);
}
CDSVReader::~CDSVReader() {
    file_.close();
}
bool CDSVReader::isValid() const {
    return file_.is_open() && !file_.bad();
}
bool CDSVReader::readRow(CDSVRow& row) {
    if (!isValid()) {
        return false;
    }
    std::string line;
    std::getline(file_, line);
    // Handle empty line or end of file
    if (line.empty()) {
        return false;
    } // Parse the line and populate the row (implementation should use `delimiter_`)
    // ... (implementation details not shown)

    return true;
}