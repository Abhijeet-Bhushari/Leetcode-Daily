class MyHashMap {
private:
    const int size = 1000;
    vector<vector<pair<int, int>>> hashMap;
    int hash(int key){
        return key%size;
    }
public:
    
    MyHashMap() {
        hashMap.resize(size);
    }
    
    void put(int key, int value) {
        int index = hash(key);
        
        for(int i=0; i<hashMap[index].size(); i++){
            if(key == hashMap[index][i].first){ 
                hashMap[index][i].second = value;
                return;                              
            }
        }
        hashMap[hash(key)].push_back({key, value});
        return;
    }
    
    int get(int key) {
        int index = hash(key);
        for(int i=0; i<hashMap[index].size(); i++){
            if(hashMap[index][i].first == key) return hashMap[index][i].second;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        for(int i=0; i<hashMap[index].size(); i++){
            if(hashMap[index][i].first == key){
                hashMap[index].erase(hashMap[index].begin()+i,hashMap[index].begin()+i+1);
                return;
            }
        }
    }
};
