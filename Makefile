CXX=g++-5 -pthread

CPPFLAGS=
CXXFLAGS= -Wall -Wextra -pthread -std=c++14 -O3

LDFLAGS=
LDLIBS= -lrt -ltbb -lopencv_core -lopencv_imgproc -lopencv_video -lopencv_photo -lopencv_highgui

SRC=src/pipeline.cc

all:
	$(CXX) $(SRC) -o bin $(CXXFLAGS) $(LDLIBS)

test:
	$(CXX) test.cc -o bin $(CXXFLAGS) $(LDLIBS)

clean:
	rm -f *.o
