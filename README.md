# Algorithms_and_data_structures
学习数据结构和算法编写的代码

## 编译
1. 编译gtest（**windows下gtest记得使用DLL/MDd进行编译**）
2. 更改test/CMakeLists.txt 中 GTEST_DIR
   ```camke
   # 设置gtest目录
    set(GTEST_DIR "D:/File/work_space/googletest-1.13.0")
   ```
3. 正常编译
   ```
   mkdir build
   cmake ..
   ```
