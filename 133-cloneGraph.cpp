// 给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
// 图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
// 测试用例格式：
// 简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），
// 第二个节点值为 2（val = 2），以此类推。该图在测试用例中使用邻接列表表示。
// 邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。
// 给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。

#include <vector>
#include <unordered_map>
#include <queue>

using std::vector;
using std::unordered_map;
using std::queue;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
private:
    //用于记录node中的节点是否已被访问过
    unordered_map<Node*, Node*> visited;
public:
    //深度优先遍历
    Node* cloneGraph(Node* node) {
        //如果当前节点为nullptr则直接返回
        if (node == nullptr) return node;
        //如果当前节点已经被访问过，则表示已被克隆，为避免循环重复，直接返回克隆节点
        if  (visited.find(node) != visited.end()) return visited[node];
        //克隆当前节点
        Node* clone_node = new Node(node->val);
        //当前节点被克隆则表示该节点已被访问
        visited[node] = clone_node;
        //复制node的neighbors
        for (auto neighbor : node->neighbors){
            clone_node->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return clone_node;
    }

    //深度优先遍历
    Node* cloneGraph(Node* node){
        //如果当前节点为nullptr则直接返回
        if (node == nullptr) return node;
        //用于记录node中的节点是否已被访问过
        //存储访问过的node和其克隆
        unordered_map<Node*, Node*> visited;
        //用于存储克隆已创建，但neighbor还没完善的node
        queue<Node*> q;
        //创建克隆
        visited[node] = new Node(node->val);
        q.push(node);
        //完善各个克隆的neighbor
        while(!q.empty()){
            //当前完善的克隆的origin
            Node* cur_node = q.front();
            q.pop();
            //添加克隆的neighbor
            for (auto &neighbor : cur_node->neighbors){
                //如果neighbor的克隆还未创建，则创建克隆
                if (visited.find(neighbor) == visited.end()){
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                //添加neighbor
                visited[cur_node]->neighbors.emplace_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};