### Usage:

#### install caffe
- donwload and checkout
    - `git clone https://github.com/intel/caffe.git `
    - `cd caffe && git checkout 1.0.6`

- modify caffe source
    - move `PATCH/caffe.patch`, `PATCH/clip.patch` to caffe folder
    - run `git apply caffe.patch` to modify caffe

- install caffe and pycaffe
    - `mkdir build && cd build && cmake -DCPU_ONLY=1 -DCMAKE_BUILD_TYPE=Release ..`
    - `make all -j$(nproc)`

- set caffe and pycaffe env
    - change user to `root`
    - `CAFFE_ROOT=$(YOUR CAFFE FOLDER)`
    - `cd $CAFFE_ROOT` and run:

```
for req in $(cat python/requirements.txt) pydot; do pip install  $req; done
export PYCAFFE_ROOT=$CAFFE_ROOT/python
export PYTHONPATH=$PYCAFFE_ROOT:$PYTHONPATH
export PATH=$CAFFE_ROOT/build/tools:$PYCAFFE_ROOT:$PATH
echo "$CAFFE_ROOT/build/lib" >> /etc/ld.so.conf.d/caffe.conf && ldconfig
```

#### install mkl-dnn
- download
    - `git clone https://github.com/intel/mkl-dnn`

- modify mkl-dnn source
    - move `clip.patch` to mkl-dnn folder
    - cd mkl-dnn folder
    - run `git apply clip.patch`

- install mkl-dnn
    - `cd scripts && ./prepare_mkl.sh && cd ..`
    - `mkdir -p build && cd build && cmake .. && make`
    - `make test`
    - `sudo make install`

#### convert model
- now you should have installed caffe, pycaffe, and mkl-dnn.

- make sure you have tensorflow and pycaffe installed, can check by `import tensorflow` and `import caffe` in python.

- prepare pb format tensorflow model.

- create a folder to save caffe model.


- cd to the script folder and run, `eg:`
```
# Transform the model to internal representation
python tf2topo.py --input_model_filename=./mobilenet.pb  --weights_file=save_model/weights.bin\
             --pkl_file=save_model/weights.pkl --topo_file=save_model/topo.txt

# Transform to caffe model
python topo2caffe.py --topo_file=save_model/topo.txt --pkl_file=save_model/weights.pkl\
    --batch_size=1 --save_folder=save_model

# Transform to C++ code which is based on MKLDNN
python make_main.py --topo=save_model/topo.txt
```

- run net of mkl-dnn `as below:`
    - `cd run_mkl_dnn`
	- `vi build.sh` and replace ${path of mkl-dnn} to '/home/enxiang/mkl-dnn' after 'MKLDNN_ROOT='
	- `sh build.sh`
#### done
