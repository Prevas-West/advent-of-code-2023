CXX=g++
CXXFLAGS=-std=c++20 -Wall -Wextra -O2

OBJDIR=obj
BINDIR=bin

day1: $(patsubst %.cxx,%.o,$(wildcard src/day1/*.cxx))
	$(CXX) $(addprefix ${OBJDIR}/,$^) -o $(BINDIR)/$@

day2: $(patsubst %.cxx,%.o,$(wildcard src/day2/*.cxx))
	$(CXX) $(addprefix ${OBJDIR}/,$^) -o $(BINDIR)/$@

day3: $(patsubst %.cxx,%.o,$(wildcard src/day3/*.cxx))
	$(CXX) $(addprefix ${OBJDIR}/,$^) -o $(BINDIR)/$@

%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o ${OBJDIR}/$@

all: day1 day2 day3

dirs:
	mkdir -p ${OBJDIR}/src/day1 && \
	mkdir -p ${OBJDIR}/src/day2 && \
	mkdir -p ${OBJDIR}/src/day3 && \
	mkdir -p $(BINDIR)

clean: dirs
	rm -f $(OBJDIR)/src/day*/*.o && \
	rm -f $(BINDIR)/day*
