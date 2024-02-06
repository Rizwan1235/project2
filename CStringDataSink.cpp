#include "CStringDataSink.h"

// getData() implementation for consistency:
std::string CStringDataSink::getData() const { return data_; }


MakeFile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
LDFLAGS = -lexpat

OBJDIR = obj
BINDIR = bin

# Object files for string utils
STRUTILS_OBJS = $(OBJDIR)/StringUtils.o $(OBJDIR)/StringUtilsTest.o
# Object files for StringDataSource
STRDATASOURCE_OBJS = $(OBJDIR)/CStringDataSource.o $(OBJDIR)/CStringDataSourceTest.o
# Object files for StringDataSink
STRDATASINK_OBJS = $(OBJDIR)/CStringDataSink.o $(OBJDIR)/CStringDataSinkTest.o
# Object files for DSV reader/writer
DSV_OBJS = $(OBJDIR)/CDSVReader.o $(OBJDIR)/CDSVWriter.o $(OBJDIR)/DSVTest.o
# Object files for XML reader/writer
XML_OBJS = $(OBJDIR)/CXMLReader.o $(OBJDIR)/CXMLWriter.o $(OBJDIR)/XMLTest.o

# Executable targets
all: teststrutils teststrdatasource teststrdatasink testdsv testxml

# Create directories if needed
$(OBJDIR) $(BINDIR):
	mkdir -p $@

# Compile .cpp files to .o files
$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to create executables
teststrutils: $(STRUTILS_OBJS)
	$(CXX) $(LDFLAGS) $^ -o $(BINDIR)/$@

teststrdatasource: $(STRDATASOURCE_OBJS)
	$(CXX) $(LDFLAGS) $^ -o $(BINDIR)/$@

teststrdatasink: $(STRDATASINK_OBJS)
	$(CXX) $(LDFLAGS) $^ -o $(BINDIR)/$@

testdsv: $(DSV_OBJS)
	$(CXX) $(LDFLAGS) $^ -o $(BINDIR)/$@

testxml: $(XML_OBJS)
	$(CXX) $(LDFLAGS) $^ -o $(BINDIR)/$@

# Run the tests
test: all
	$(BINDIR)/teststrutils
	$(BINDIR)/teststrdatasource
	$(BINDIR)/teststrdatasink
	$(BINDIR)/testdsv
	$(BINDIR)/testxml

# Clean up object and binary files
clean:
	rm -rf $(OBJDIR) $(BINDIR)
