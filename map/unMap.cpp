#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main(){

    unordered_map<string , int> m;

    pair<string, int> p = make_pair("abc", 3); // using make_pair to create a pair
    m.insert(p);

    pair<string, int> pair2("def", 2); // using constructor to create a pair
    m.insert(pair2);

    m["ghi"] = 1; // using [] operator to insert a pair

    // search
    cout<<m["abc"] <<endl;
    cout<<m.at("def") <<endl; // at() is used to access the value of a key
    // cout<<m.at("xyz")<<endl; will throw an error if key is not present
    cout<<m["xyz"]<<endl; // if key is not present then it will insert the key with value 0
    cout<<m.size()<<endl;

    cout<<m.count("lmo")<<endl; // count() is used to check if key is present or not
    // if not present will give 0 and if present then 1
    cout<<m.count("abc")<<endl; // will give 1

    // traversing in the unordered map
    for(auto i : m){
        cout<< i.first <<" " << i.second <<endl;
    }

    // iterators in unordered map
    unordered_map<string, int> :: iterator it = m.begin();
    while( it != m.end()){
        cout<<it -> first <<" " << it -> second <<endl;
        it++;
    }
}