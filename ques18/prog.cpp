// the complexities are :
// Time Complexity: O(n * 32)
// Space Complexity: O(n * 32)

#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode* child[2] = {nullptr, nullptr};
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int maxXOR(int num) {
        TrieNode* node = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;
            if (node->child[opposite]) {
                maxXor |= (1 << i);
                node = node->child[opposite];
            } else {
                node = node->child[bit];
            }
        }

        return maxXor;
    }
};

int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    int maxResult = 0;

    for (int num : nums)
        trie.insert(num);

    for (int num : nums)
        maxResult = max(maxResult, trie.maxXOR(num));

    return maxResult;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Maximum XOR is: " << findMaximumXOR(nums) << endl;
    return 0;
}
