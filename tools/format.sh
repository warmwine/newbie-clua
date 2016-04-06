##############################################
PROJECT_DIR="$( cd "$( dirname "$0"  )" && pwd  )/../src"
cd $PROJECT_DIR

##############################################
astyle --style=linux -f -p -D -U -n --preserve-date --recursive "*.cpp"
astyle --style=linux -f -p -D -U -n --preserve-date --recursive "*.c"
astyle --style=linux -f -p -D -U -n --preserve-date --recursive "*.h"
