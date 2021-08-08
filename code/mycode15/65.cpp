class LRUCache {
    int size;
    list<pair<int, int>> li;    //������˫��������
    unordered_map<int, list<pair<int, int>>::iterator> map; //valueֵ��list�ĵ�������ʽ
public:
    LRUCache(int capacity) : size(capacity) {}  //��ʼ��size��С
    
    int get(int key) {
        if(map.find(key) == map.end())  return -1;  //���keyֵ������,ֱ�ӷ���-1
        else
        {
            li.splice(li.begin(), li, map[key]);        //key���������key��Ӧ�Ļ��浽list��ͷ��
            return map[key]->second;
        }
    }

    void put(int key, int value) {
        if(get(key) != -1)  map[key]->second = value;//key����,����getʱ�ѽ������Ƶ�ͷ�����ٸ���map
        else    
        {   //key������
            if(map.size() == size)  //�����Ƿ�����,ɾ�����δʹ�����ݣ�map��ҲҪɾ��
            {
                int delekey = li.back().first;
                li.pop_back();
                map.erase(delekey);
            }
            li.emplace_front(key, value); //���key�����ڣ���ͷ�������µĻ���   
            map[key] = li.begin();
        }
    }
};
