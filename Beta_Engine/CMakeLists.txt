# CMakeList.txt : CMake project for Beta_Engine, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Beta_Engine "Beta_Engine.cpp" "Beta_Engine.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Beta_Engine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
