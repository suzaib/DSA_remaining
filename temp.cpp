#include<bits/stdc++.h>
using namespace std;
int helper(int i,int n,vector<int> &chairs,vector<bool> &vis){
    if(i==n) return 0;
    
    if(vis[i]) return 0;
    int skip=0+helper(i+1,n,chairs,vis);
    vis[chairs[i]-1]=true;
    int sit=1+helper(i+1,n,chairs,vis);
    vis[chairs[i]-1]=false;
    return max(skip,sit);
}
int maxChair(vector<int> &chairs){
    int n=chairs.size();
    vector<bool> vis(n,false);
    return helper(0,n,chairs,vis);
}
int main(){
    return 0;
}


class Node{
    public:
        Node* links[26]={nullptr};
        int endsWith=0;
        int prefixCnt=0;
        void put(char ch, Node* node){
            links[ch-'a']=node;
        }

        Node* get(char ch){
            return links[ch-'a'];
        }

        bool containsChar(char ch){
            return links[ch-'a']!=nullptr;
        }

};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root=new Node();
        }

        void insert(const string& word){
            int n=word.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                if(!node->containsChar(word[i])) node->put(word[i],new Node());
                node=node->get(word[i]);
                node->prefixCnt++;
            }
            node->endsWith++;
        }
        //Time Complexity will be O(n)

        //Count the number of words ending with the given prefix
        int countPrefix(const string& prefix){
            int n=prefix.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                if(!node->containsChar(prefix[i])) return 0;
                node=node->get(prefix[i]);
            }
            return node->prefixCnt;
        }
        //Time Complexity will be O(n)

        //Count the number of Words
        int countWords(const string& word){
            int n=word.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                if(!node->containsChar(word[i])) return 0;
                node=node->get(word[i]);
            }
            return node->endsWith;
        }
        //Time Complexity will be O(n)

        //Erase a particular word from the trie
        //One thing to be noted here, we first need to confirm if the word exists or not
        void erase(const string& word){
            if(search(word)==false) return;
            int n=word.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                node=node->get(word[i]);
                node->prefixCnt--;
            }
            node->endsWith--;
        }
        //Time Complexity will be O(n)

        //Search if a word exists or not
        bool search(const string& word){
            return countWords(word)>0;
        }
        //Time Complexity will be O(n)

        //See if a words start a given prefix
        bool startsWith(const string& prefix){
            return countPrefix(prefix)>0;
        }
        //Time Complexity will be O(n)

};


class Node{
    public:
        Node* links[26]={nullptr};
        int endsWith=0;
        int prefixCnt=0;
        
        void put(char ch, Node* node){
            links[ch-'a']=node;
        }

        Node* get(char ch){
            return links[ch-'a'];
        }

        bool containsChar(char ch){
            return links[ch-'a']!=nullptr;
        }
};

class Trie{
    private:
        Node* root;

    public:
        Trie(){
            root=new Node();
        }

        void insert(const string &word){
            Node* node=root;
            for(int i=0;i<word.size();i++){
                if(!node->containsChar(ch-'a')) node->put(word[i], new Node());
                node=node->get(word[i]);
                node->prefixCnt++;
            }
            node->endsWith++;
        }

        void countPrefix(const string &prefix){
            Node* node=root;
            for(int i=0;i<prefix.size();i++){
                if(!node->containsChar(prefix[i])) return 0;
                node=node->get(prefix[i]);
            }
            return node->prefixCnt;
        }

        int countWords(const string &word){
            int n=word.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                if(!node->containsChar(word[i])) return 0;
                node=node->get(word[i]);
            }
            return node->endsWith;
        }

        void erase(const string &word){
            if(search(word)==false) return;
            int n=word.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                node=node->get(word[i]);
                node->prefixCnt--;
            }
            node->endsWith--;
        }

        bool search(const string &word){
            return countWords(word)>0;
        }

        bool startsWith(const string &word){
            return countPrefix(word)>0;
        }
}



#include<bits/stdc++.h>
using namespace std;

//Xenia and bit operations
class SGTree{
    public:
        vector<int> seg;

        SGTree(int n){
            seg.resize(4*n+1);
        }

        void build(int idx,int low,int high,bool level,vector<int> &arr){
            if(low==high){
                seg[idx]=arr[low];
                return;
            }

            int mid=low+(high-low)/2;
            build(2*idx+1,low,mid,!level,arr);
            build(2*idx+2,mid+1,high,!level,arr);
            if(level) seg[idx]=seg[2*idx+1]|seg[2*idx+2];
            else seg[idx]=seg[2*idx+1]^seg[2*idx+2];
        }

        void update(int idx,int low,int high,bool level,int _idx,int val){
            if(low==high){
                seg[idx]=val;
                return;
            }

            int mid=low+(high-low)/2;
            if(_idx<=mid) update(2*idx+1,low,mid,!level,_idx,val);
            else update(2*idx+2,mid+1,high,!level,_idx,val);
            if(level) seg[idx]=seg[2*idx+1]|seg[2*idx+2];
            else seg[idx]=seg[2*idx+1]^seg[2*idx+2];
        }
};

int main(){
    int n,m;
    cin>>n>>m;
    int el=1<<n;
    vector<int> arr(el);
    for(int i=0;i<el;i++) cin>>arr[i];
    SGTree sgt(el);
    sgt.build(0,0,el-1,n%2!=0,arr);
    for(int i=0;i<m;i++){
        int p,b;
        cin>>p>>b;
        p--;//Since the problem involves 1 based indexing
        sgt.update(0,0,el-1,n%2!=0,p,b);
        cout<<sgt.seg[0]<<"\n";

    }
    return 0;
}

