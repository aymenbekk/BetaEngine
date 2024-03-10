# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Beta_Engine")

file(GLOB_RECURSE Beta_EngineSources Beta_Engine/*.cpp Beta_Engine/*.h)
add_executable(TestApp ${Beta_EngineSources} "Beta_Engine/Renderer/VBO.cpp" "Beta_Engine/Renderer/EBO.cpp")

# Include sub-projects.
add_subdirectory(third_party/glfw EXCLUDE_FROM_ALL)
add_subdirectory(third_party/GLAD EXCLUDE_FROM_ALL)
add_subdirectory(third_party/glm EXCLUDE_FROM_ALL)

# stb_image
add_library(stb EXCLUDE_FROM_ALL third_party/stb/stb_image.h third_party/stb/stb_image.cpp "Beta_Engine/Renderer/VBO.cpp" "Beta_Engine/Renderer/EBO.cpp")
include_directories(stb third_party/stb)

#setting up the references for the Beta Engine project this means 
#the Beta Engine project will reference glfw and glad
target_link_libraries(TestApp PRIVATE glfw glad glm stb )

# set a symlink to the assets dir
add_custom_command(
        TARGET TestApp PRE_BUILD COMMAND
        ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_SOURCE_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)

