/* ------------------------------------------------------------------|
ʱ�����ƣ�C/C++ 1�룬��������2��

�ռ����ƣ�C/C++ 32M����������64M

Z���Ļ���ϵͳ������ֵ1Ԫ��4Ԫ��16Ԫ��64Ԫ����4��Ӳ�ң��Լ���ֵ1024Ԫ��ֽ�ҡ�����СYʹ��1024Ԫ��ֽ�ҹ�����һ����ֵΪ����Ʒ���������������յ�����Ӳ�ң�

��������:
һ�У�����һ����N��

�������:
һ�У�����һ��������ʾ�����յ���Ӳ������

��������1:
200

�������1:
17

����˵��1:
��200����Ҫ����824�飬��12��64ԪӲ�ң�3��16ԪӲ�ң�2��4ԪӲ�Ҽ��ɡ�|
-------------------------------------------------------------------*/

//  ����ʱ�䣺 4 ms
//  ռ���ڴ棺396K

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