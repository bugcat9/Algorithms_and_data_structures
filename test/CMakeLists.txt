set(GTEST_DIR "D:\\File\\work_space\\googletest-1.13.0")
find_library(gtestd gtest HINTS "${GTEST_DIR}\\build\\lib\\Debug" required)
find_library(gtest_maind gtest_main HINTS "${GTEST_DIR}\\build\\lib\\Debug" required)
set(gtest ${gtestd} ${gtest_maind})
include_directories("${GTEST_DIR}\\googletest\\include")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

set(TEST_FILE
	main.cpp 
	dijkstra_test.cpp 
	prime_test.cpp
)

# 创建可执行目标
add_executable(unitest ${TEST_FILE})

# 链接静态库到可执行目标
target_link_libraries(unitest ${gtest} algorithm)
