#define f first
#define s second

using namespace std;

typedef pair<int,int> pint;

class Trie{
    private:
        int trie_size=1;
        struct node{
            vector<pint> adj;
            int chr;
            bool is_word = false;
        };
        vector<node> tree;
    public:
        Trie(){
            node root;
            root.chr = '#';
            node dummy;
            dummy.chr = '?';
            tree.push_back(dummy);
            tree.push_back(root);
        }
        int size(){
            return trie_size;
        }
        void addWord(string word){
            int curr_node = 1;
            for(int i = 0;i<word.size();i++){
                int curr_char = word[i];
                bool found = false;
                int next_node = 0;
                for(pint edge : tree[curr_node].adj){
                    if(edge.f == curr_char){
                        found = true;
                        next_node = edge.s;
                    }
                }
                if(found){
                    curr_node = next_node;
                }else{
                    trie_size++;
                    node new_node;
                    new_node.chr = curr_char;
                    tree.push_back(new_node);
                    tree[curr_node].adj.push_back({curr_char,trie_size});
                    curr_node = trie_size;
                }
            }
            tree[curr_node].is_word = true;
        }
        bool find(string word){
            int curr_node = 1;
            for(int i = 0;i<word.size();i++){
                int curr_char = word[i];
                bool found = false;
                int next_node = 0;
                for(pint edge : tree[curr_node].adj){
                    if(edge.f == curr_char){
                        found = true;
                        next_node = edge.s;
                    }
                }
                if(found){
                    curr_node = next_node;
                }else{
                    return false;
                }
            }
            return tree[curr_node].is_word;
        }
};
