INC=/usr/local/include 
LIB=/usr/local/lib
LIBS=`pkg-config --libs opencv`
CFLAGS=-Wall -std=c++11 
CC=g++ 
  
TARGET=test_out  
#SRCS=text_detect.cpp   

OBJS=cheatsheet_code.o  
 
%.o:%.c  
	$(CC) $(CFLAGS) -I$(INC) -L$(LIB) -o $@ -c $< 

$(TARGET):$(OBJS)  
	@echo TARGET:$@  
	@echo OBJECTS:$^  
	$(CC) -o $@ $^ $(LIBS) 
  
clean:  
	rm -rf $(TARGET) $(OBJS)  
  
