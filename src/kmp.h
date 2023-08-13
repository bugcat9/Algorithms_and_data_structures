#ifndef _KMP_H
#define _KMP_H
#include <vector>
#include <string>
using namespace std;

/**
 * @brief kmp 算法
 *
 */
class KMP
{
private:
    vector<vector<int>> dp;
    string pat;

public:
    KMP(string pat) : pat(pat), dp(pat.length(), vector(256, 0))
    {
        int M = pat.length();
        // dp[状态][字符] = 下个状态

        // base case
        dp[0][pat[0]] = 1;
        // 影子状态 X 初始为 0
        int X = 0;
        // 当前状态 j 从 1 开始
        for (int j = 1; j < M; j++)
        {
            for (int c = 0; c < 256; c++)
            {
                if (pat[j] == c)
                    dp[j][c] = j + 1;
                else
                    dp[j][c] = dp[X][c];
            }
            // 更新影子状态
            X = dp[X][pat[j]];
        }
    }

    ~KMP()
    {
    }

    /**
     * @brief 从txt上搜索pat
     *
     * @param txt
     * @return int
     */
    int search(string txt)
    {
        int M = pat.length();
        int N = txt.length();
        // pat 的初始态为 0
        int j = 0;
        for (int i = 0; i < N; i++)
        {
            // 当前是状态 j，遇到字符 txt[i]，
            // pat 应该转移到哪个状态？
            j = dp[j][txt[i]];
            // 如果达到终止态，返回匹配开头的索引
            if (j == M)
                return i - M + 1;
        }
        // 没到达终止态，匹配失败
        return -1;
    }
};

#endif // _KMP_H