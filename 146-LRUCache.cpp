// 146. LRU 缓存
// 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 LRUCache 类：
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
// 如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，
// 则应该 逐出 最久未使用的关键字。
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;

//哈希表和双向链表的组合
struct DlinkedNode{
    int key, val;
    DlinkedNode *next;
    DlinkedNode *prev;
    //默认构造函数
    DlinkedNode():key(0), val(0), next(nullptr), prev(nullptr){};
    //一般构造函数
    DlinkedNode(int _key, int _val):key(_key), val(_val), next(nullptr), prev(nullptr){};
    //拷贝和移动操作使用合成的函数
};

class LRUCache {
private:
    //容器设计大小
    int capacity;
    //容器当前大小
    int size;
    unordered_map<int, DlinkedNode*> container;
    //每一个对象维护一个组合链表，最近使用的元素靠前
    //链表的头结点，使用一次容器中的元素则将元素放置头部
    DlinkedNode* head;
    //链表的尾结点，删除元素是删除末尾的元素
    DlinkedNode* tail;
public:
    //一般构造函数，创建一个对象，对象初始大小为0
    LRUCache(int _capacity):capacity(_capacity) {
        size = 0;
        head = new DlinkedNode();
        tail = new DlinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    //获取容器中的元素
    int get(int key) {
        if (container.find(key) != container.end()){
            //更新key对应的node在链表中的位置
            //先将node从链表中删除
            //再将node添加到链表头部
            movetohead(container[key]);
            return container[key]->val;
        }
        else return -1;
    }
    //添加元素
    void put(int key, int value) {
        //如果key已存在，更新val
        if (container.find(key) != container.end()){
            //更新val
            container[key]->val = value;
            //由于key有变动，需将其移动到head
            movetohead(container[key]);
        }
        //如果不存在
        else {
            //创建一个新的dlinkednode
            DlinkedNode* node = new DlinkedNode(key,value);
            //并将node放入map中
            container[key] = node;
            //将新建的node添加到链表头部
            addtohead(node);
            //容器的容量也要加1
            size++;
            //如果容器的size超过capacity，删除链表末尾的节点
            if (size > capacity){
                //删除组合链表末尾的节点
                DlinkedNode* node = delrettail();
                //删除container中末尾节点对应的key-value
                container.erase(node->key);
                //将size减1
                size--;
                //防止内存泄露
                delete node;
            }
        }
    }
    //添加节点node到组合链表头部
    void addtohead(DlinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    //删除节点node
    void removenode(DlinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    //移动节点node到头部
    void movetohead(DlinkedNode* node){
        removenode(node);
        addtohead(node);
    }
    //删除并返回末尾node
    DlinkedNode* delrettail(){
        DlinkedNode* del_node = tail->prev;
        // removenode(del_node);
        del_node->prev->next = tail;
        tail->prev = del_node->prev;
        return del_node;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */