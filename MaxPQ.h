#ifndef _MAXPQ_H
#define _MAXPQ_H
#include <vector>
using namespace std;

/**
 * @brief 优先队列
 *
 * @tparam T
 */
template <class T>
class MaxPQ
{
private:
    // 存储元素的数组
    vector<T> pq;
    // 当前 Priority Queue 中的元素个数
    int size_;

public:
    // 索引 0 不用，所以多分配一个空间
    MaxPQ(int cap) : pq(cap + 1), size_(0)
    {
    }

    ~MaxPQ()
    {
    }
    /**
     * @brief 返回当前队列中最大元素
     *
     * @return T
     */
    T max()
    {
        return pq[1];
    }

    /**
     * @brief 插入元素 e
     *
     * @param e
     */
    void insert(T e)
    {
        size_++;
        // 先把新元素加到最后
        pq[size_] = e;
        // 然后让它上浮到正确的位置
        swim(size_);
    }

    /**
     * @brief 删除并返回当前队列中最大元素
     *
     * @return T
     */
    T delMax()
    {
        // 最大堆的堆顶就是最大元素
        T max = pq[1];
        // 把这个最大元素换到最后，删除之
        swap(1, size_);
        size_--;
        // 让 pq[1] 下沉到正确位置
        sink(1);
        return max;
    }

private:
    /**
     * @brief 浮第 x 个元素，以维护最大堆性质
     *
     * @param x
     */
    void swim(int x)
    {
        // 如果浮到堆顶，就不能再上浮了
        while (x > 1 && less(parent(x), x))
        {
            // 如果第 x 个元素比上层大
            // 将 x 换上去
            swap(parent(x), x);
            x = parent(x);
        }
    }

    /**
     * @brief 下沉第 x 个元素，以维护最大堆性质
     *
     * @param x
     */
    void sink(int x)
    {
        // 如果沉到堆底，就沉不下去了
        while (left(x) <= size_)
        {
            // 先假设左边节点较大
            int max = left(x);
            // 如果右边节点存在，比一下大小
            if (right(x) <= size && less(max, right(x)))
                max = right(x);
            // 结点 x 比俩孩子都大，就不必下沉了
            if (less(max, x))
                break;
            // 否则，不符合最大堆的结构，下沉 x 结点
            swap(x, max);
            x = max;
        }
    }

    /**
     * @brief 交换数组的两个元素
     *
     * @param i
     * @param j
     */
    void swap(int i, int j)
    {
        Key temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }

    /**
     * @brief pq[i] 是否比 pq[j] 小？
     *
     * @param i
     * @param j
     * @return true
     * @return false
     */
    bool less(int i, int j)
    {
        return pq[i] < pq[j];
    }

    // 父节点的索引
    int parent(int root)
    {
        return root / 2;
    }
    // 左孩子的索引
    int left(int root)
    {
        return root * 2;
    }
    // 右孩子的索引
    int right(int root)
    {
        return root * 2 + 1;
    }
};

#endif // _MAXPQ_H