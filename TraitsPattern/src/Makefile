# Simple Makefile for C++ projects
# 
# Each .cpp source is compiled in a separate 
# translation unit. Each .o depends on the 
# relative .cpp and every header file found in this dir.
# Usage:
# make				production code
# make dbg=1	debug code

CXX = g++
CXXFLAGS = -Wall -Wextra -Weffc++

LD = g++
LFLAGS =

ifeq ($(dbg), 1)
	CXXFLAGS += -g -O0 -DDEBUG
	SUFFIX=_dbg
else
	CXXFLAGS += -O3 -ftree-vectorize
	SUFFIX= 
endif

ifeq ($(verb), 1)
	VERB= 
else
	VERB=@
endif

SRCS = $(wildcard *.cpp)
HDRS = $(wildcard *.h)
OBJS = $(SRCS:.cpp=.o$(SUFFIX))

.PHONY: clean

all: test$(SUFFIX)

%.o$(SUFFIX) : %.c $(HDRS)
	$(VERB)$(CXX) -c -o $@ $(CXXFLAGS) $<

test$(SUFFIX): $(OBJS)
	$(VERB)$(LD) -o $@ $^ $(LFLAGS)

clean:
	$(VERB)rm -rf $(OBJS) test$(SUFFIX)

cleanall:
	$(VERB)make -C ./ clean
	$(VERB)make -C ./ dbg=1 clean

