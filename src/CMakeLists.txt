SET(ALGORITHM_FILE 
    binary_search.h
    binary_search.cpp
    bst.h
    bst.cpp
    Difference.h
    dijkstra.h
    )

add_library(algorithm STATIC ${ALGORITHM_FILE})

# 创建可执行目标
add_executable(main main.cpp)

# 链接静态库到可执行目标
target_link_libraries(main algorithm)