cmake_minimum_required(VERSION 3.5.1)

project(EBOT_API)

# Set clang++ as the default C++ compiler if available
find_program(CMAKE_CXX_COMPILER clang++)
if(CMAKE_CXX_COMPILER)
    message(STATUS "Found Clang++: ${CMAKE_CXX_COMPILER} and using it as default C++ compiler")
    set(CMAKE_CXX_COMPILER clang++)
else()
    message(STATUS "Clang++ not found using default C++ compiler, this might cause E-Bot crashes")
endif()

# Set clang as the default C compiler if available
find_program(CMAKE_C_COMPILER clang)
if(CMAKE_C_COMPILER)
    message(STATUS "Found Clang: ${CMAKE_C_COMPILER} and using it as default C compiler")
    set(CMAKE_C_COMPILER clang)
else()
    message(STATUS "Clang not found using default C compiler, this might cause E-Bot crashes")
endif()

# Set build type and library suffix
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")

# Set compiler flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32 -Ofast")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -m32 -mmmx -msse -msse2 -mfpmath=sse -flto -Ofast -fvisibility=hidden -fno-exceptions -fno-rtti -Wno-parentheses -pipe -mtune=generic -fomit-frame-pointer -fvisibility-inlines-hidden -fno-stack-protector -fno-omit-frame-pointer -no-pie")
set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -m32")
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
cmake_policy(SET CMP0069 NEW)

# Set output directory for the library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/ebot_api)

# Include directories
set(INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR}/sdk/hlsdk
    ${CMAKE_CURRENT_SOURCE_DIR}/sdk/metamod
)
include_directories(${INCLUDE_DIRECTORIES})

# Source files
file(GLOB_RECURSE EBOT_API_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sdk/*.cpp
)

# Create the library
add_library(${PROJECT_NAME} SHARED ${EBOT_API_SRC})

# Link libraries
target_link_libraries(${PROJECT_NAME}
    ${CMAKE_DL_LIBS}
)

# Set library properties
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE ON
    PREFIX ""
    OUTPUT_NAME "ebot_amxx"
    INTERPROCEDURAL_OPTIMIZATION ON
)

# Set installation directories
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
foreach(dir ${INCLUDE_DIRECTORIES})
    install(DIRECTORY ${dir} DESTINATION include)
endforeach()
