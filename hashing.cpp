#include <iostream>
#include <string>

using namespace std;


bool insert_hash(string hash[], string key) {
    int key2 = 0, key3;
    for (int i = 0; i < key.length(); i ++) {
        key2 += key[i] * (i+1);
    }
    key2 *= 19;
    key3 = key2;
    bool trys = true;
    for (int i = 0; i <= 19 && trys; i ++) {
        key3 = key2 + (i*i + 23*i);
        if (hash[key3%101] == key) {
            trys = false;
        }
    }
    key3 = key2;
    for (int i = 0; i <= 19 && trys; i ++) {
        key3 = key2 + (i*i + 23*i);
         if (hash[key3%101] == "" || hash[key3%101] == "ja teve") { 
            hash[key3%101] = key;
            return true;
            trys = false;
        }
    }
    return false;
}


bool remove_hash(string hash[], string key) {
    int key2 = 0, key3;
    for (int i = 0; i < key.length(); i ++) {
        key2 += key[i] * (i + 1);
    }
    key2 *= 19;
    key3 = key2;
    for (int i = 1; i <= 19 && trys; i ++) {
        if (hash[key3%101] == key) {
            hash[key3%101] = "ja teve";
            return true;
        } else {
            key3 = key2 + (i*i + 23*i);
        }
    }
    return false;
}

int main () {
    string hash [101];
    int x, y, test = 0;
    bool b;
    string z;
    cin >> x;
    while (x --) {
        test = 0;
        cin >> y;
        while (y --) {
            b = false;
            cin >> z;
            if (z[0] == 'A') {
                z = z.substr(4, z.length());
                b = insert_hash(hash, z);
                if (b) {
                    test ++;
                }
            } else if (z[0] == 'D') {
                z = z.substr(4, z.length());
                b = remove_hash(hash, z);
                if (b) {
                    test --;
                }
            }     
        }
        cout << test << endl;
        for (int i = 0; i < 101; i ++) {
            if (hash[i] != "" && hash[i] != "ja teve") {
                cout << i << ":" << hash[i] << endl;
                hash[i] = "";
            }
            if (hash[i] == "ja teve") {
                hash[i] = "";
            }
        }
    }
    return 0;
}
