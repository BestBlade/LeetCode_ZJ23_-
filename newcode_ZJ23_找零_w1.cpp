/* ------------------------------------------------------------------|
时间限制：C/C++ 1秒，其他语言2秒

空间限制：C/C++ 32M，其他语言64M

Z国的货币系统包含面值1元、4元、16元、64元共计4种硬币，以及面值1024元的纸币。现在小Y使用1024元的纸币购买了一件价值为的商品，请问最少他会收到多少硬币？

输入描述:
一行，包含一个数N。

输出描述:
一行，包含一个数，表示最少收到的硬币数。

输入例子1:
200

输出例子1:
17

例子说明1:
花200，需要找零824块，找12个64元硬币，3个16元硬币，2个4元硬币即可。|
-------------------------------------------------------------------*/

//  运行时间： 4 ms
//  占用内存：396K

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int N;
int coins[] = { 64,16,4,1 };

int minCoins(int n) {
    int res = 0;
    int i = 0;
    while (n) {
        if (n >= coins[i]) {
            res += n / coins[i];
            n %= coins[i++];
        }
        else {
            i++;
        }
    }
    return res;
}

int main(){
    cin >> N;
    N = 1024 - N;
    cout << minCoins(N) << endl;
    return 0;
}