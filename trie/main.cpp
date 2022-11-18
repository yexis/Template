#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int count;
    vector<Node*> child;

    Node() {
        count = 0;
        child = vector<Node*>(26);
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void add(string s) {
        int n = s.size();
        auto p = root;
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (p->child[idx] == nullptr) {
                p->child[idx] = new Node();
            }
            p = p->child[idx];
            p->count += 1;
        }
    }

    int ask(string s) {
        int ans = 0;
        int n = s.size();
        auto p = root;
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (p->child[idx] == nullptr) {
                return ans;
            }
            p = p->child[idx];
            ans += p->count;
        }
        return ans;
    }
};

namespace Trie2 {
    class Node {
    public:
        int val;
        vector<Node*> child;
        Node() {
            val = 0;
            child.resize(26);
        }
    };

    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }

        void add(string s) {
            int n = s.size();
            Node* p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    p->child[idx] = new Node();
                }
                p = p->child[idx];
                p->val += 1;
            }
        }


        int ask(string s) {
            int n = s.size();
            int ans = 0;
            Node* p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    return ans;
                }
                p = p->child[idx];
                ans += p->val;
            }
            return ans;
        }
    };
}

namespace TRIE2 {
    class Node {
    public:
        int val;
        vector<Node *> child;

        Node() {
            val = 0;
            child.resize(26);
        }
    };

    class Trie {
        Node* root;

        Trie() {
            root = new Node();
        }

        void add(string s) {
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    p->child[idx] = new Node();
                }
                p = p->child[idx];
                p->val += 1;
            }
        }

        int ask(string s) {
            int n = s.size();
            auto p = root;

            int ans = 0;
            for (auto i = 0; i < n; i++) {
                auto idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    return ans;
                }
                p = p->child[idx];
                ans += p->val;
            }
            return ans;
        }
    };
}

namespace TRIE_3 {
    class Node {
    public:
        int val;
        vector<Node*> child;
        Node() {
            val = 0;
            child.resize(26);
        }
    };

    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }

        void add(string s) {
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    p->child[idx] = new Node();
                }
                p = p->child[idx];
                p->val++;
            }
        }

        int ask(string s) {
            int ans = 0;
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    return ans;
                }
                p = p->child[idx];
                ans += p->val;
            }
            return ans;
        }
    };
}

namespace TRIE_4 {
    class Node {
    public:
        int val;
        vector<Node*> child;
        Node() {
            child.resize(26);
        }
    };

    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        void add(string s) {
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; ++i) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    p->child[idx] = new Node();
                }
                p = p->child[idx];
                p->val++;
            }
        }
        int ask(string s) {
            int ans = 0;
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    return ans;
                }
                p = p->child[idx];
                ans += p->val;
            }
            return ans;
        }
    };
}

namespace TRIE_5 {
    class Node {
    public:
        int val;
        vector<Node*> child;
        Node() {
            val = 0;
            child.resize(26);
        }
    };
    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        void add(string s) {
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    p->child[idx] = new Node();
                }
                p = p->child[idx];
                p->val += 1;
            }
        }
        int ask(string s) {
            int n = s.size();
            auto p = root;
            int ans = 0;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    return ans;
                }
                p = p->child[idx];
                ans += p->val;
            }
            return ans;
        }
    };
}

namespace TRIE_6 {
    class Node {
    public:
        int val;
        vector<Node*> child;
        Node() {
            val = 0;
            child.resize(26);
        }
    };
    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        void add(string s) {
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                auto idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    p->child[idx] = new Node();
                }
                p = p->child[idx];
                p->val++;
            }
        }
        int ask(string s) {
            int n = s.size();
            int ans = 0;
            auto p = root;
            for (int i = 0; i < n; i++) {
                auto idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    return ans;
                }
                p = p->child[idx];
                ans += p->val;
            }
            return ans;
        }
    };
}

namespace TRIE_7 {
    class Node {
    public:
        int val;
        vector<Node*> child;
        Node() {
            val = 0;
            child.resize(26);
        }
    };
    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        void add(string s) {
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    p->child[idx] = new Node();
                }
                p = p->child[idx];
                p->val += 1;
            }
        }
        int ask(string s) {
            int n = s.size();
            int ans = 0;
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    return ans;
                }
                p = p->child[idx];
                ans += p->val;
            }
            return ans;
        }
    };
}

namespace TRIE_8 {
    class Node {
    public:
        int val;
        vector<Node*> child;
        Node() {
            val = 0;
            child.resize(26);
        }
    };
    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        void add(string s) {
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    p->child[idx] = new Node();
                }
                p = p->child[idx];
                p->val++;
            }
        }
        int ask(string s) {
            int n = s.size();
            auto p = root;
            int ans = 0;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    return ans;
                }
                p = p->child[idx];
                ans += p->val;
            }
            return ans;
        }
    };
}

namespace TRIE_9 {
    class Node {
    public:
        int val;
        vector<Node*> child;
        Node() {
            val = 0;
            child.resize(26);
        }
    };
    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        void add(string s) {
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    p->child[idx] = new Node();
                }
                p = p->child[idx];
                p->val++;
            }
        }
        int ask(string s) {
            int ans = 0;
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    return ans;
                }
                p = p->child[idx];
                ans += p->val;
            }
            return ans;
        }
    };
}

int main() {
    // ans : 10
    TRIE_9::Trie trie;
    trie.add("liguoyang");
    trie.add("hezijing");
    trie.add("liguoqing");
    cout << trie.ask("liguo") << endl;
    return 0;
}
