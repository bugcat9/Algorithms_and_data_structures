# 设置gtest目录
set(GTEST_DIR "D:/File/work_space/googletest-1.13.0")

if (WIN32)
find_library(GTESTD gtest HINTS "${GTEST_DIR}/build/lib/Debug" required)
find_library(GTEST_MAIND gtest_main HINTS "${GTEST_DIR}/build/lib/Debug" required)
else()
find_library(GTESTD gtest HINTS "${GTEST_DIR}/build/lib" required)
find_library(GTEST_MAIND gtest_main HINTS "${GTEST_DIR}/build/lib" required)
endif()

set(GTEST ${GTESTD} ${GTEST_MAIND})
include_directories("${GTEST_DIR}/googletest/include")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)


set(TEST_FILE
	main.cpp 
	dijkstra_test.cpp 
	prime_test.cpp
)

# 创建可执行目标
add_executable(unittest ${TEST_FILE})

# 链接静态库到可执行目标
target_link_libraries(unittest ${GTEST} algorithm)
