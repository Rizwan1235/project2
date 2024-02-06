#include "CDSVWriter.h"
//#include "CDSVRow.h" // Include necessary implementation

CDSVWriter::CDSVWriter(const std::string& filename, char delimiter) :
    delimiter_(delimiter) {
    file_.open(filename);
}

CDSVWriter::~CDSVWriter() {
    file_.close();
}
bool CDSVWriter::isValid() const {
    return file_.is_open() && !file_.bad();
}
bool CDSVWriter::writeRow(const CDSVRow& row) {
    if (!isValid()) {
        return false;
    }
 // Format and write the row to the file (implementation should use `delimiter_`)
    // ... (implementation details not shown)

    return true;
}
