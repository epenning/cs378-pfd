FILES :=                              \
    .travis.yml                       \
    pfd-tests/elp692-RunPFD.in   \
    pfd-tests/elp692-RunPFD.out  \
    pfd-tests/elp692-TestPFD.c++ \
    pfd-tests/elp692-TestPFD.out \
    PFD.c++                       \
    PFD.h                         \
    PFD.log                       \
    html                              \
    RunPFD.c++                    \
    RunPFD.in                     \
    RunPFD.out                    \
    TestPFD.c++                   \
    TestPFD.out

ifeq ($(CXX), clang++)
    COVFLAGS := --coverage
    GCOV     := gcov-4.6
else
    CXX      := g++-4.8
    COVFLAGS := -fprofile-arcs -ftest-coverage
    GCOV     := gcov-4.8
endif

CXXFLAGS := -pedantic -std=c++11 -Wall
LDFLAGS  := -lgtest -lgtest_main -pthread
VALGRIND := valgrind

all: RunPFD TestPFD

check:
	@for i in $(FILES);                                         \
	do                                                          \
        [ -e $$i ] && echo "$$i found" || echo "$$i NOT FOUND"; \
    done

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunPFD
	rm -f RunPFD.out
	rm -f TestPFD
	rm -f TestPFD.out

config:
	git config -l

test: RunPFD.out TestPFD.out

pfd-tests:
	git clone https://github.com/cs378-summer-2015/pfd-tests.git

html: Doxyfile PFD.h PFD.c++ RunPFD.c++ TestPFD.c++
	doxygen Doxyfile

PFD.log:
	git log > PFD.log

Doxyfile:
	doxygen -g

RunPFD: PFD.h PFD.c++ RunPFD.c++
	$(CXX) $(CXXFLAGS) PFD.c++ RunPFD.c++ -o RunPFD
	
winRunPFD: PFD.h PFD.c++ RunPFD.c++
	g++ $(CXXFLAGS) PFD.c++ RunPFD.c++ -o RunPFD.exe

RunPFD.out: RunPFD
	cat RunPFD.in
	./RunPFD < RunPFD.in > RunPFD.out
	cat RunPFD.out
	
winRunPFD.out: winRunPFD
	cat RunPFD.in
	./RunPFD.exe < RunPFD.in > RunPFD.out
	cat RunPFD.out

TestPFD: PFD.h PFD.c++ TestPFD.c++
	$(CXX) $(COVFLAGS) $(CXXFLAGS) PFD.c++ TestPFD.c++ -o TestPFD $(LDFLAGS)

TestPFD.out: TestPFD
	$(VALGRIND) ./TestPFD  >  TestPFD.out 2>&1
	$(GCOV) -b PFD.c++     >> TestPFD.out
	$(GCOV) -b TestPFD.c++ >> TestPFD.out
	cat TestPFD.out
