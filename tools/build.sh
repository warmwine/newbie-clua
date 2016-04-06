BUILD_PATH="bin"
##############################################
PROJECT_DIR="$( cd "$( dirname "$0"  )" && pwd  )/../"
cd $PROJECT_DIR

##############################################
if [ "$1" == "clean"  ]; then
    echo 'Cleaning...'
    rm -rf $BUILD_PATH/*
    echo 'Done.'
    exit 0
fi

##############################################
if [ ! -d $BUILD_PATH ]; then
  mkdir $BUILD_PATH
fi
cd $BUILD_PATH

##############################################
cmake ../project/cmake
make
