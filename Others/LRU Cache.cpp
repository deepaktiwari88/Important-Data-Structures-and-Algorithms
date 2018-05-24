// Problem Link : https://practice.geeksforgeeks.org/problems/lru-cache/1
/*class LRUCache
{
public:
    LRUCache(int);
    int get(int);
    void set(int,int);
};*/

/*You are required to complete below methods */

//List of variables to be used

map<int,int> count_key;
map<int,int> key_count;
map<int,int> key_value;
int counter, n;

/*Inititalize an LRU cache with size N */

LRUCache::LRUCache(int N)
{
    count_key.clear();
    key_value.clear();
    key_count.clear();
    counter=0;
    n=N;
}

/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
    counter++;
    
    auto itr=key_value.find(x);
    
    if(itr==key_value.end())
    {
        if(key_value.size()==n){
            
            auto itr1=count_key.begin();
            int keyy = itr1->first;
            int value = itr1->second;
            
            count_key.erase(itr1);
            key_count.erase(value);
            key_value.erase(value);   
        }
        
        key_value.insert(make_pair(x,y));
        count_key.insert(make_pair(counter,x));
        key_count.insert(make_pair(x,counter));
    }
    else
    {
        int keyy = itr->first;
        int value = itr->second;
        
        itr->second = y;
        
        auto itr1=key_count.find(x);
        int temp=itr1->second;
        itr1->second=counter;
        
        auto itr2=count_key.find(temp);
        count_key.erase(itr2);
        
        count_key.insert(make_pair(counter,x));
    }
}

/*Returns the value of the key x if 
present else returns -1 */

int LRUCache::get(int x)
{
    counter++;
    
    if(auto itr=(key_value.find(x)==key_value.end()))
        return -1;
    else
    {
        auto itr1 = key_count.find(x);
        
        int keyy=itr1->first;
        int valuee=itr1->second;
        
        itr1->second = counter;
        
        auto itr2 = count_key.find(valuee);
        count_key.erase(itr2);
        
        count_key.insert(make_pair(counter,keyy));
        
        auto itr4=key_value.find(x);
        return (itr4->second);
    }
}
