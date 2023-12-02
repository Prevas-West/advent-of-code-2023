CXX=g++
CXXFLAGS=-std=c++20 -Wall -Wextra -O2

OBJDIR=obj
BINDIR=bin

day1: $(patsubst %.cxx,%.o,$(wildcard src/day1/*.cxx))
	$(CXX) $(addprefix ${OBJDIR}/,$^) -o $(BINDIR)/$@

%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o ${OBJDIR}/$@

dirs:
	mkdir -p ${OBJDIR}/src/day1 && \
	mkdir -p $(BINDIR)

clean: dirs
	rm -f $(OBJDIR)/src/day*/*.o && \
	rm -f $(BINDIR)/day*
