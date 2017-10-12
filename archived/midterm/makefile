#
# C++ Compiler
CXX := g++
#
# Flags
#
#   Compiler
CXXFLAGS += -c -Wall -std=c++11
#
# Program name
EXE := 1611617
#
# Directories
#
#   Objects
OBJDIR := obj
#
#   Binary
BINDIR := bin
#
#
################################################################################

SRCS := $(wildcard *.cpp)
OBJS := $(subst [1611617], $(OBJDIR)/[1611617], $(SRCS:.cpp=.o))

CXXFLAGS += $(INCLUDEFLAGS)
LDFLAGS += $(LIBFLAGS)

.PHONY: all clean distclean

all: $(BINDIR)/$(EXE)

$(BINDIR)/$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) $? -o $@

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/$(EXE)

distclean: clean