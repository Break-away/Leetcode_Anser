// 138. 复制带随机指针的链表
// 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，
// 该指针可以指向链表中的任何节点或空节点。
// 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个
// 新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针
// 也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示
// 相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。
// 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复
// 制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。
// 返回复制链表的头节点。
// 用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
// val：一个表示 Node.val 的整数。
// random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
// 你的代码 只 接受原链表的头节点 head 作为传入参数。

// 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

#include <vector>
#include <unordered_map>
#include <queue>
#include <deque>

using std::vector;
using std::unordered_map;
using std::queue;
using std::deque;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
private:
    //建立当前节点与拷贝节点映射
   unordered_map<Node*,Node*> visited;
public:
    //深度优先的搜索
    //创建输入节点的拷贝
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        //创建拷贝节点
        Node* copy_head = new Node(head->val);
        //将当前节点与拷贝节点建立映射
        visited[head] = copy_head;
        //拷贝节点的next指向下一个节点的拷贝
        //递归调用会创建所有节点的拷贝及完善visited
        copy_head->next = copyRandomList(head->next);
        //如果当前节点的random不为空，则应为拷贝的节点创建random
        if (!head->random){
            copy_head->random = visited[head->random];
        }
        return copy_head;
    }

    //广度优先的遍历
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        //创建拷贝节点
        Node* copy_head = new Node(head->val);
        //将当前节点与拷贝节点建立映射
        visited[head] = copy_head;
        //q用于遍历所有node
        queue<Node*> q;
        q.push(head);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            //如果当前node还没copy，则创建copy
            if(visited.find(node) == visited.end()){
                Node* copy_node = new Node(node->val);
                visited[node] = copy_node;
            }
            //如果当前node的next不为空，则应为node的副本创建next
            if (node->next != nullptr){
                //如果node的next的copy已经存在，则直接将copy的next指向其即可
                if (visited.find(node->next) != visited.end()){
                    visited[node]->next = visited[node->next];
                }
                //如果不存在，创建后再指向
                else{
                    Node* next_node = new Node(node->next->val);
                    visited[node->next] = next_node;
                    visited[node]->next = visited[node->next];
                }
                //将node的next放入q中
                q.push(node->next);
            }
            //如果当前node的random不为空，则应为node的副本创建random
            if (node->random != nullptr){
                //如果node的random的copy已经存在，则直接将copy的random指向其即可
                if (visited.find(node->random) != visited.end()){
                    visited[node]->random = visited[node->random];
                }
                //如果不存在，创建后再指向
                else{
                    Node* random_node = new Node(node->random->val);
                    visited[node->random] = random_node;
                    visited[node]->random = visited[node->random];
                }
            }
        }  
        return copy_head;     
    }
};
 