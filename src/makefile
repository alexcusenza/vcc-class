CC = g++
CFLAGS = -Wall

TARGET = modclassexe
SRC = modclass.cpp

DEPS = ../inc/classVEHMGR.h ../inc/classMODFUNC.h ../inc/classMODCONTROL.h  ../inc/classMODREGISTER.h ../inc/classMODBASE.h ../inc/classSIGNALIO.h ../inc/classSIGNALHMI.h
_OBJS = $(DEPS:.h=.o)
OBJS = $(_OBJS) modclass.o

%.o : %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

all:$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)	
