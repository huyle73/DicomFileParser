cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 17)

file(GLOB dcmcore_copy
     "*.h"
     "*.cpp"
)


add_executable(main ${dcmcore_copy})
