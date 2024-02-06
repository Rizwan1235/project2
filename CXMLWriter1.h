#ifndef CXMLWRITER_H
#define CXMLWRITER_H

#include <string>
#include <vector>

class CXMLWriter {
public:
    // Constructor to open an XML file
    CXMLWriter(const std::string& filename);

    // Destructor to close the file
    ~CXMLWriter();

    // Start a new element
    void startElement(const std::string& name);

    // Add an attribute to the current element
    void addAttribute(const std::string& name, const std::string& value);
  // Add character data to the current element
    void addData(const std::string& data);
    // End the current element
    void endElement();
private:
    std::ofstream file_;
    // ... other private members for element stack, formatting, etc.
};

#endif // CXMLWRITER_H

CXMLWriter.cpp
#include "CXMLWriter.h"

CXMLWriter::CXMLWriter(const std::string& filename) :
    file_(filename) {
    // ... write XML declaration and initial indentation
}

CXMLWriter::~CXMLWriter() {
    // ... write any remaining closing tags and close file_
}

void CXMLWriter::startElement(const std::string& name) {
    file_ << "<" << name; // ... add attributes if any
    file_ << ">\n";
    // ... update indentation
}

void CXMLWriter::addAttribute(const std::string& name, const std::string& value) {
    // ... write attribute in proper format
}

void CXMLWriter::addData(const std::string& data) {
    // ... escape special characters and write data
}

void CXMLWriter::endElement() {
    // ... decrease indentation
    file_ << "</" << /* ... pop element name from stack */ << ">\n";
}