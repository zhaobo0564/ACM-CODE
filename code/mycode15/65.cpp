class LRUCache {
    int size;
    list<pair<int, int>> li;    //数据用双向链表保存
    unordered_map<int, list<pair<int, int>>::iterator> map; //value值是list的迭代器形式
public:
    LRUCache(int capacity) : size(capacity) {}  //初始化size大小
    
    int get(int key) {
        if(map.find(key) == map.end())  return -1;  //如果key值不存在,直接返回-1
        else
        {
            li.splice(li.begin(), li, map[key]);        //key存在需更新key对应的缓存到list的头部
            return map[key]->second;
        }
    }

    void put(int key, int value) {
        if(get(key) != -1)  map[key]->second = value;//key存在,调用get时已将缓存移到头部，再更新map
        else    
        {   //key不存在
            if(map.size() == size)  //缓存是否满了,删除最久未使用数据，map中也要删除
            {
                int delekey = li.back().first;
                li.pop_back();
                map.erase(delekey);
            }
            li.emplace_front(key, value); //如果key不存在，在头部加入新的缓存   
            map[key] = li.begin();
        }
    }
};
