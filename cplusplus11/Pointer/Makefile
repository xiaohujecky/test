opencv_inc_path= /usr/local/include
opencv_lib_path= /usr/local/lib
vpath= $(opencv_inc_path)
c_args= -g -O2 -std=c++11
target=test_out
cxx=g++
cc=gcc
%.o: %.cpp
	$(cxx) $(c_args) -c $^ -o $@
	#$(cxx) $(c_args) -c $^ -o $@ -i$(opencv_inc_path)
objects = experiment.o  
$(target): $(objects)
	$(cxx) $(c_args) $^ -o $@ 
	#$(cxx) $(c_args) $^ -o $@ -i$(opencv_inc_path) -l$(opencv_lib_path) `pkg-config --cflags --libs opencv`

clean:
	rm -f *.o $(TARGET)
