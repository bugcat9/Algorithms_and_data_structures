SET(ALGORITHM_FILE 
    quick_sort.h
    quick_sort.cpp
    merge_sort.h
    merge_sort.cpp
    binary_search.h
    binary_search.cpp
    precision_compute.h
    precision_compute.cpp
    pre_sum.h
    pre_sum.cpp
    trie.h
    trie.cpp
    uf.h
    uf.cpp
    dijkstra.h
    dijkstra.cpp
    bellman_ford.h
    bellman_ford.cpp
    floyd.h
    floyd.cpp
    prim.h
    prim.cpp
    kruskal.h
    kruskal.cpp
    bipartite.h
    bipartite.cpp
    hungarian.h
    hungarian.cpp
    prime.h
    prime.cpp
    factor.h
    factor.cpp
    binpow.h
    binpow.cpp
)

add_library(algorithm STATIC ${ALGORITHM_FILE})

# 创建可执行目标
# add_executable(main main.cpp)

# 链接静态库到可执行目标
# target_link_libraries(main algorithm)