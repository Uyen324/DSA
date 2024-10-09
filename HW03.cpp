#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

struct node {
    string token_id;
    int expiry_time;
    node(string id, int time) {
        token_id = id;
        expiry_time = time;
    }

    bool operator<(const node& other) const {
        return expiry_time < other.expiry_time || 
               (expiry_time == other.expiry_time && token_id < other.token_id);
    }
};

struct authentication_manager {
    int time_to_live;
    unordered_map<string, int> token_map;
    set<node> token_expiry_set;
};

void create_auth_manager(authentication_manager& manager, int ttl) {
    manager.time_to_live = ttl;
}

void remove_expired_tokens(authentication_manager& manager, int current_time) {
    while (!manager.token_expiry_set.empty() && manager.token_expiry_set.begin()->expiry_time <= current_time) {
        string expired_token_id = manager.token_expiry_set.begin()->token_id;
        manager.token_map.erase(expired_token_id);
        manager.token_expiry_set.erase(manager.token_expiry_set.begin());
    }
}

void generate(authentication_manager& manager, string token_id, int current_time) {
    remove_expired_tokens(manager, current_time);
    int expiry_time = current_time + manager.time_to_live;
    manager.token_map[token_id] = expiry_time;
    manager.token_expiry_set.insert(node(token_id, expiry_time));
}

void renew(authentication_manager& manager, string token_id, int current_time) {
    remove_expired_tokens(manager, current_time);
    if (manager.token_map.find(token_id) != manager.token_map.end() && manager.token_map[token_id] > current_time) {
        manager.token_expiry_set.erase(node(token_id, manager.token_map[token_id]));
        int new_expiry_time = current_time + manager.time_to_live;
        manager.token_map[token_id] = new_expiry_time;
        manager.token_expiry_set.insert(node(token_id, new_expiry_time));
    }
}

int count_unexpired_tokens(authentication_manager& manager, int current_time) {
    remove_expired_tokens(manager, current_time);
    return manager.token_map.size();
}

int main() {
    authentication_manager auth_manager;
    create_auth_manager(auth_manager, 5);  

    generate(auth_manager, "aaa", 2);  
    cout << count_unexpired_tokens(auth_manager, 6) << endl;  

    generate(auth_manager, "bbb", 7);  
    renew(auth_manager, "aaa", 8);     
    renew(auth_manager, "bbb", 10);    

    cout << count_unexpired_tokens(auth_manager, 15) << endl;  

    return 0;
}

