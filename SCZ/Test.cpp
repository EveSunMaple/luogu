#include <iostream>
#include <vector>

using namespace std;

const int N = 100005; // 最大节点数

vector<int> adj[N]; // 树的邻接表表示
int val[N];         // 节点权值
int chainHead[N];   // 链的头节点
int chainPos[N];    // 节点在链中的位置
int chainSize[N];   // 链的大小
int chainIdx[N];    // 节点所属链的编号
int chainNum;       // 链的数量
int nodeIdx;        // 节点编号
int parent[N];      // 节点的父节点，用于DFS和路径跳转

// 以下是你需要补充的部分：
// 线段树的实现和查询函数
int segmentTree[4 * N];

int querySegmentTree(int node, int left, int right, int queryLeft, int queryRight)
{
    if (queryLeft > right || queryRight < left)
        return 0; // 返回合适的初始值
    if (queryLeft <= left && queryRight >= right)
        return segmentTree[node];

    int mid = (left + right) / 2;
    int leftChild = 2 * node + 1;
    int rightChild = 2 * node + 2;

    int leftSum = querySegmentTree(leftChild, left, mid, queryLeft, queryRight);
    int rightSum = querySegmentTree(rightChild, mid + 1, right, queryLeft, queryRight);

    return leftSum + rightSum;
}

// 修改线段树中的节点值
void updateSegmentTree(int node, int left, int right, int idx, int newValue)
{
    if (idx < left || idx > right)
        return;
    if (left == right)
    {
        segmentTree[node] = newValue;
        return;
    }

    int mid = (left + right) / 2;
    int leftChild = 2 * node + 1;
    int rightChild = 2 * node + 2;

    updateSegmentTree(leftChild, left, mid, idx, newValue);
    updateSegmentTree(rightChild, mid + 1, right, idx, newValue);

    segmentTree[node] = segmentTree[leftChild] + segmentTree[rightChild];
}

// 树链剖分的第一步：选择重儿子
int dfs(int u, int p)
{
    int size = 1, maxSubtree = 0;
    parent[u] = p; // 记录父节点
    for (int v : adj[u])
    {
        if (v != p)
        {
            int subtreeSize = dfs(v, u);
            size += subtreeSize;
            if (subtreeSize > maxSubtree)
            {
                maxSubtree = subtreeSize;
                chainHead[u] = v;
            }
        }
    }
    return size;
}

// 树链剖分的第二步：建立链
void hld(int u, int p, int head)
{
    chainPos[u] = nodeIdx++;
    chainIdx[u] = chainNum;
    chainSize[chainNum]++;

    for (int v : adj[u])
    {
        if (v != p)
        {
            if (v == chainHead[u])
            {
                hld(v, u, head);
            }
            else
            {
                chainNum++;
                hld(v, u, v);
            }
        }
    }
}

// 修改节点权值
void update(int u, int newValue)
{
    val[u] = newValue;
    updateSegmentTree(0, 0, nodeIdx - 1, chainPos[u], newValue);
}

// 查询路径上节点权值和
int query(int u, int v)
{
    int res = 0;
    while (chainIdx[u] != chainIdx[v])
    {
        if (chainPos[u] > chainPos[v])
        {
            swap(u, v);
        }
        int curChainHead = chainHead[v];
        res += querySegmentTree(0, 0, nodeIdx - 1, chainPos[curChainHead], chainPos[v]);
        v = parent[curChainHead];
    }
    if (chainPos[u] > chainPos[v])
    {
        swap(u, v);
    }
    res += querySegmentTree(0, 0, nodeIdx - 1, chainPos[u], chainPos[v]);
    return res;
}

int main()
{
    int n;
    cin >> n; // 节点数
    for (int i = 1; i <= n; ++i)
    {
        cin >> val[i]; // 节点权值
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v; // 树的边
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 初始化
    nodeIdx = 0;
    chainNum = 0;
    dfs(1, -1);
    hld(1, -1, 1);

    return 0;
}