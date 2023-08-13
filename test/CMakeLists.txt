if(WIN32)
message("debugflag: ${CMAKE_CXX_FLAGS_DEBUG}")
string(REPLACE "/MDd" "/MTd" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
message("debugflag: ${CMAKE_CXX_FLAGS_DEBUG}")
endif()

set(GTEST_DIR "D:\\File\\work_space\\googletest-1.13.0")
find_library(gtestd gtest HINTS "${GTEST_DIR}\\build\\lib\\Debug" required)
find_library(gtest_maind gtest_main HINTS "${GTEST_DIR}\\build\\lib\\Debug" required)
set(gtest ${gtestd} ${gtest_maind})
include_directories("${GTEST_DIR}\\googletest\\include")

# 创建可执行目标
add_executable(main1 main.cpp)

# 链接静态库到可执行目标
target_link_libraries(main1 ${gtest})
