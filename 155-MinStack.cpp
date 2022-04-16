// 155. 最小栈
// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
// 实现 MinStack 类:
// MinStack() 初始化堆栈对象。
// void push(int val) 将元素val推入堆栈。
// void pop() 删除堆栈顶部的元素。
// int top() 获取堆栈顶部的元素。
// int getMin() 获取堆栈中的最小元素。

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#include <exception>
#include <stdexcept>
#include <algorithm>

struct NodeList
{
    int val;
    NodeList *next;
    NodeList():val(0),next(nullptr){};
    NodeList(int _val):val(_val),next(nullptr){};
    NodeList(int _val, NodeList* _next):val(_val),next(_next){};
};

class MinStack {
private:
    NodeList *head = nullptr;
public:
    MinStack() {
        head = new NodeList(0,nullptr);
    }
    
    void push(int val) {
        NodeList *node = new NodeList(val);
        addtohead(node);
    }
    
    void pop() {
        if (head->next){
            NodeList *node = head->next;
            head->next = node->next;
            delete node;
        }
        else{
            throw std::runtime_error("MinStack is empty!");
        }
        
    }
    
    int top() {
        if (head->next){
            return head->next->val;
        }
        else{
            throw std::runtime_error("MinStack is empty!");
        }
    }
    
    int getMin() {
        if (head->next){
            NodeList *temp = head->next;
            int min_num = INT_MAX;
            while(temp){
                min_num = std::min(min_num,temp->val);
                temp = temp->next;
            }
            return min_num;
        }
        else{
            throw std::runtime_error("MinStack is empty!");
        }
    }

    void addtohead(NodeList *node){
        node->next = head->next;
        head->next = node;
    }
};