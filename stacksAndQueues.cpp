//Stacks

/* 
Stack is a data structure that stores a certain type of data(can be int,bool etc)
It follows the LIFO mechainism(last in first out)
We use push to add elements and pop to remove elements(pop removes the last element)
The top is used to see the top element(in a stack the element at the top is the one inserted most recently) 
We also have a size function to get the size(length) of stack
*/

//Queues

/*
Similar to stack but follows the FIFO mechanism(First in First out) just like in a queue
Also has similar function like:push,top,pop,size
Pop function removes the element entered first(like in a queue)
Top function also gives the first element entered in the array(not removes it, pop does it)
*/

//Syntax is like : stack<int> st and queue<int> q;

//Logic behind push, pop and top functions operations
//We will be using arrays to understand:
    /* We use a top variable initially with value -1 , if the element is pushed , then we increase top by 1 (now 0) and then push the element to the index it points
       If pop is used , we first delete the element at the place of top and then decrease top by 1
       If size is used we return top+1 */
#include<bits/stdc++.h>
using namespace std;

//We can use a class to understand the operations of push ,pop etc:



//Implementing Stack using array
class StackImplementation{
    public:
        int top=-1;
        int st[10];
        void push(int x){
            top=top+1;
            if(top>10) cout<<"Out of bound";
            st[top]=x;
        }

        int topEl(){
            if(top==-1) return -1;
            else return st[top];
        }

        void pop(){
            if(top==-1) return;
            else top--;
        }

        int size(){
            return top+1;
        }

};



//Implementing Queue Using array
class QueueImplementation{
    int size=4;
    int start=-1;
    int end=-1;
    int queue[4];
    int currSize=0;
    void push(int x){
        if(currSize==size) cout<<"Out of bound";
        else if(currSize==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%size;
        }
        queue[end]=x;
        currSize++;
    }

    int top(){
        if(currSize==0) return -1;
        return queue[start];
    }

    void pop(){
        int el;
        if(currSize==0) return;
        else if(currSize==1){
            el=queue[start];
            start=-1;
            end=-1;
        }
        else{
            el=queue[start];
            start=(start+1)%size;
        }
        currSize--;
        return;
    }
    int curSize(){
        return currSize;
    }
};


class Node{
    public:
        int data;
        Node* next;
        Node(int data1){
            this->data=data1;
            this->next=nullptr;
        }
};



//Implementing stack using Linked List
class stackImpUsingLL{
    public:
        Node* top;
        int size=0;
        void push(int x){
            Node* temp=new Node(x);
            temp->next=top;
            top=temp;
            size++;
        }

        void pop(){
            Node* temp=top;
            top=temp->next;
            delete temp;
            size--;
        }

        int topEl(){
            return top->data;
        }

        int currSize(){
            return size;
        }
};




//Implementing Queue Using Linked List
class queueImpUsingLL{
    public:
        Node* start;
        Node* end;
        int size=0;
        void push(int x){
            Node* temp=new Node(x);
            if(start==NULL){
                start=temp;
                end=temp;
            }
            else{
                end->next=temp;
            }
            size++;
        }

        void pop(){
            if(start==NULL) return;
            Node* temp=start;
            start=start->next;
            delete temp;
            size--;
        }

        int top(){
            if(start==NULL) return -1;
            return start->data;
        }

        int currSize(){
            return size;
        }
};




//Implementing Stack Using Queue
class stackImpUsingQueue{
    public:
        queue<int> q;
        void push(int x){
            int s=q.size();
            q.push(x);
            for(int i=1;i<s;i++){
                q.push(q.front());
                q.pop();
            }
        }

        void pop(){
            q.pop();
        }

        int top(){
            return q.front();
        }

        int size(){
            return q.size();
        }
};




//Implementing Queue Using Single Stack
class queueImpUsingStack{
    public:
        stack<int> s1;
        stack<int> s2;
        void push(int x){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(s2.size()){
                s1.push(s2.top());
                s2.pop();
            }
        }

        int top(){
            return s1.top();
        }

        void pop(){
            s1.pop();
        }
};



//Implementing Queue Using two Stacks
class queueImpUsingStack_method2{
    public:
        stack<int> s1;
        stack<int> s2;
        void push(int x){
            s1.push(x);
        }
        int top(){
            if(s2.size()==0){
                while(s1.size()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            return s2.top();
        }

        void pop(){
            if(s2.size()==0){
                while(s1.size()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            s2.pop();
        }
        int size(){
            int s=s1.size()+s2.size();
            return s;
        }
};




//Valid Parenthesis
bool validParenthesis(string str){
    stack<char> st;
    int n=str.size();
    if(n%2!=0) return false;
    for(int i=0;i<n;i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            st.push(str[i]);
        }
        else{
            if(st.empty()==true) return false;
            char ch=st.top();
            if((str[i]==')' && ch!='(') || (str[i]=='}' && ch!='{') || (str[i]==']' && ch!='[')) return false;
        }
    }
    return true;
}
//Time Complexity will be O(n)
//Space Complexity will be O(n)

/*Priority Order of Operators
^,(*,/),(+,-);

Infix expression : (everything in between), for eg like : (x+y)-(p/q), see all the operators, +,-,/ etc are in between
Prefix expression : *+pq-mn (*+ before the variables)
Postfix expression : pq+mn-*

Postfix expressions are used heavily in stack based calculators
Prefix expressions are used in the language LISP and in tree data structure
*/


//Converting infix to postfix
//Consider : a+b*(c^d-e)
//First we make up a priority function 
int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return -1;
};

string infixToPostfix(string str){
    int n=str.size();
    string ans="";
    stack<char> st;
    for(int i=0;i<n;i++){
        char ch=str[i];
        if((ch>=65 && ch<=90) || (ch>=97 && ch<=122) || (ch>=48 && ch<=57)) ans+=ch;
        else{
            if(ch=='(') st.push(ch);
            else if(ch==')'){
                while(st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(st.empty()) st.push(ch);
            else if(priority(ch)>priority(st.top())) st.push(ch);
            else{
                while(priority(st.top())>priority(ch)){
                    ans+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
//Time Complexity will be O(2N) 
//Space Complexity will be O(2N) (stack and ans both store 2n elements at max)


//Infix to Prefix
//Consider : (A+B)*C-D+F
//Step 1 : Reverse the Infix string(make sure to inverse the ( and ) brackers as they will be like )( after reversing the string)
void revStrWithBrackets(string &str){
    int n=str.size();
    int i=0;
    int j=n-1;
    while(i<j){
        if(str[i]=='(') str[i]=')';
        else if(str[i]==')') str[i]='(';
        if(str[j]==')') str[j]='(';
        else if(str[j]=='(') str[j]=')';
        swap(str[i],str[j]);
        i++;
        j--;
    }
}
//Time Complexity will be O(n/2)

void revStr(string &str){
    int n=str.size();
    int i=0;
    int j=n-1;
    while(i<j){
        swap(str[i],str[j]);
        i++;
        j--;
    }
}
//Time Complexity will be O(n/2)

//Step 2 : Use controlled conversion from infix to postfix
int priority2(char ch){
    if(ch=='^') return 2;
    else if(ch=='+' || ch=='-' || ch=='*' || ch=='/') return 1;
    else return -1;
}

string controlledInfixToPostfix(string str){
    int n=str.size();
    stack<char> st;
    string ans="";
    for(int i=0;i<n;i++){
        char ch=str[i];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')) ans+=ch;
        else{
            if(st.empty()) st.push(ch);
            else{
                if(ch=='^'){
                    if(st.top()!='^') st.push(ch);
                    else{
                        ans+=st.top();
                        st.pop();
                        st.push(ch);
                    }
                }
                else if(ch=='(') st.push(ch);
                else if(ch==')'){
                    while(st.top()!='('){
                        ans+=st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else{
                    if(st.top()=='^'){
                        ans+=st.top();
                        st.pop();
                        st.push(ch);
                    }
                    else st.push(ch);

                }
            }
        }
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
//Time complexity will be O(n)

//Step 3 : Reverse the string obtained, This is your answer
string infixToPrefix(string str){
    int n=str.size();
    revStrWithBrackets(str);
    string ans=controlledInfixToPostfix(str);
    revStr(ans);
    return ans;
}
//Time Complexity will be O(3n)
//Space Complexity will be O(n)


//Postfix to Infix
string postfixToInfix(string str){
    int n=str.size();
    stack<string> st;
    string t1="";
    string t2="";
    for(int i=0;i<n;i++){
        string ch=string(1,str[i]);
        if(ch=="+" || ch=="-" || ch=="*" || ch=="/" || ch=="^"){
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            string temp="("+t2+ch+t1+")";
            st.push(temp);
        }
        else{
            st.push(ch);
        }
    }
    return st.top();
}
//Time Complexity will be O(n) (for loop) + O(n) (since string addition takes time as well) for eg adding two string of n1 and n2 length takes O(n1+n2)
//Space Complexity will be O(n)


string prefixToInfix(string str){
    int n=str.size();
    stack<string> st;
    for(int i=n-1;i>=0;i--){
        string ch=string(1,str[i]);
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^'){
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string temp="("+t1+str[i]+t2+")";
            st.push(temp);
        }
        else st.push(ch);
    }
    return st.top();
}
//Time Complexity will be O(n)+O(n) (for loop and addition)
//Space Comlexity will be O(n) 


//Postfix to Prefix
string postfixToPrefix(string str){
    int n=str.size();
    stack<string> st;
    for(int i=0;i<n;i++){
        string ch=string(1,str[i]);
        if(ch=="+" || ch=="-" || ch=="*" || ch=="/" || ch=="^"){
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string temp=ch+t2+t1;
            st.push(temp);
        }
        else st.push(ch);
    }
    return st.top();
}
//Time Complexity will be O(2n)
//Space Complexity will be O(n)


//Prefix To Postfix
string prefixToPostfix(string str){
    int n=str.size();
    stack<string> st;
    for(int i=n-1;i>=0;i--){
        string ch=string(1,str[i]);
        if(ch=="+" || ch=="-" || ch=="*" || ch=="/" || ch=="^"){
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string temp=t1+t2+ch;
            st.push(temp);
        }
        else st.push(ch);
    }
    return st.top();
}
//Time Complexity will be O(2n)
//Space Complexity will be O(n)


//Min Stack : A stack that keeps track of the minimum element, uptill the particular element
class minStack_brute{
    public:
        stack<pair<int,int>> st;
        void push(int val){
            if(st.empty()) st.push({val,val});
            else st.push({val,min(val,st.top().second)});
            
        }
        int getMin(){
            return st.top().second;
        }
        int top(){
            return st.top().first;
        }
};
//Time Complexity will be O(1), that is constant time
//Space Complexity will be O(2n) since pair stores two elements

//We can optimise the space
class minStack{
    public:
        stack<int> st;
        int minEl=INT_MAX;
        void push(int &val){
            if(st.empty()) minEl=val;
            else{
                if(val<=minEl){
                    int temp=minEl;
                    minEl=val;
                    val=2*val-temp;
                }
            }
            st.push(val);
        }

        int findMin(){
            return minEl;
        }

        int top(){
            if(st.empty()) return -1;
            int ans=st.top();
            if(ans<findMin()) return findMin();
            return ans;
        }

        void pop(){
            if(st.empty()) return;
            else{
                if(st.top()<minEl) minEl=2*findMin()-st.top();
            }
            st.pop();
        }
};
//Time Complexity will be O(1) 
//Space Complexity will be O(n)


//Monotonic Stack : Stack that stores element in some particular order, say increasing or decreasing etc
//Next greater element
void nextGreater_brute(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int nextGreater=-1;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                nextGreater=arr[j];
                break;
            }
        }
        arr[i]=nextGreater;
    }
}
//Time Complexity will be O(pow(n,2))

//Optimal approach will be to keep track of the greatest element from the back
void nextGreater(vector<int> &arr){
    int n=arr.size();
    vector<int> nge(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]) st.pop();
        if(st.empty()) nge[i]=-1;
        else nge[i]=st.top();
        st.push(arr[i]);
    }
    arr=nge;
}
//Time Complexity will be O(2n) since the inner loop run at most n times(it removes at max n elements)
//Space Complexity will be O(n) (stack may store all elements at worst)


//Next Greater Element : Variation 2
//Keep the search going around in circular manner when you reach the end of array(begin at first element)
vector<int> nextGreaterII_brute(vector<int> arr){
    int n=arr.size();
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int nextGreater=-1;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                nextGreater=arr[j];
                break;
            }
        }
        if(nextGreater==-1){
            for(int k=0;k<i;k++){
                if(arr[k]>arr[i]){
                    nextGreater=arr[k];
                    break;
                }
            }
        }
        ans[i]=nextGreater;
    }
    return ans;
}
//Time Complexity will be O(n2)

//Better Method : Using Circular array concept
vector<int> nextGreaterII_better(vector<int> arr){
    int n=arr.size();
    vector<int> ans(n);
    int i=0;
    int j=i+1;
    for(int i=0;i<n;i++){
        int nextGreater=-1;
        for(int j=i+1;j<(n+i);j++){
            int idx=j%n;
            if(arr[idx]>arr[i]){
                nextGreater=arr[idx];
                break;
            }
        }
        ans[i]=nextGreater;
    }
    return ans;
}
//Time Complexity will be O(n2)

//Optimal Approach : Using monotonic stack option
vector<int> nextGreaterII(vector<int> arr){
    int n=arr.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i=2*n-1;i>=0;i--){
        int idx=i%n;
        while(!st.empty() && st.top()<=arr[idx]) st.pop();
        if(i<n) ans[i]=st.empty()? -1:st.top();
        st.push(arr[idx]);
    }
    return ans;
}
//Time Complexity will be O(2n)
//Space Complexity will be O(n)


//Nearest Smaller Element
//Brute Force : Two loops
vector<int> nearestSmaller_brute(vector<int> arr){
    int n=arr.size();
    vector<int> ans;
    int smallest=-1;
    for(int i=0;i<n;i++){
        smallest=-1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                smallest=arr[j];
                break;
            }
        }
        ans.push_back(smallest);
    }
    return ans;
}
//Time Complexity will be O(n2)

//Optimal Approach : Using monotonic stack
vector<int> nearestSmaller(vector<int> arr){
    int n=arr.size();
    stack<int> st;
    vector<int> ans;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=arr[i]) st.pop();
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(arr[i]);
    }
    return ans;
}


//Trapping Rainwater : Formula --> min(leftMaxElement,rightMaxElement)-height of building, this give the water logged on that building
//Add water logged on all the buildings to get the total trapped water
int trappingRainwater_brute(vector<int> arr){
    int n=arr.size();
    int leftMax=-1;
    int rightMax=-1;
    int totalWaterTrapped=0;
    for(int i=1;i<n-1;i++){
        leftMax=-1;
        rightMax=-1;
        for(int j=i-1;j>=0;j--) leftMax=max(leftMax,arr[j]);
        for(int j=i+1;j<n;j++) rightMax=max(rightMax,arr[j]);
        int waterTrapped=min(leftMax,rightMax)-arr[i];
        totalWaterTrapped+=(waterTrapped>0? waterTrapped:0);
    }
    return totalWaterTrapped;
}
//Time Complexity will be O(n2)

//We can create two arrays and keep track of left max and right max in them
//Better Approach
int trappingRainwater_better(vector<int> arr){
    int n=arr.size();
    int totalWaterLogged;
    vector<int> prefixMax=arr;
    vector<int> suffixMax=arr;
    for(int i=1;i<n;i++) prefixMax[i]=max(prefixMax[i],prefixMax[i-1]);
    for(int i=n-2;i>=0;i--) suffixMax[i]=max(suffixMax[i],suffixMax[i+1]);
    for(int i=1;i<n-1;i++){
        int waterLogged=(min(prefixMax[i],suffixMax[i])-arr[i]);
        totalWaterLogged+=(waterLogged>0? waterLogged:0);
    }
    return totalWaterLogged;
}
//Time Complexity will be O(3n)
//Space Complexity will be O(2n)

//Optimal Approach
int trappingRainwater(vector<int> arr){
    int n=arr.size();
    int leftMax=0;
    int rightMax=0;
    int total=0;
    int left=0;
    int right=n-1;
    while(left<right){
        if(arr[left]<=arr[right]){
            if(leftMax>arr[left]) total+=(leftMax-arr[left]);
            else leftMax=arr[left];
            left++;
        }
        else{
            if(rightMax>arr[right]) total+=(rightMax-arr[right]);
            else rightMax=arr[right];
            right--;
        }
    }
    return total;
}
//Time Complexity will be O(n)


//Sum of Subarray minimum
//Form all possible subarrays, then find out the minimum element in each one of them, then sum all these minimum element
//Naive Approach : Do as instructed above
int sumOfSubarrMin_naive(vector<int> arr){
    int n=arr.size();
    vector<vector<int>> a;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=i;j<n;j++){
            temp.push_back(arr[j]);
            a.push_back(temp);
        }
    }
    int minEl=INT_MAX;
    int minSum=0;
    for(auto it:a){
        minEl=INT_MAX;
        for(auto el:it) minEl=min(minEl,el);
        minSum+=minEl;
    }
    return minSum;
}
//Time Complexity will be O(2n2)
//Space Complexity O(n2)

//Same Approach can be written in better way
//Brute Force
int sumOfSubarrMin_brute(vector<int> arr){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        int mini=arr[i];
        for(int j=i;j<n;j++){
            mini=min(arr[j],mini);
            sum+=mini;
        }
    }
    return sum;
}

//Optimal Approach
// int sumOfSubarrMin(vector<int> arr){
//     int n=arr.size();
//     int sum=0;
//     vector<int> nse=findNSE(arr);
//     vector<int> pse=findPSE(arr);
//     for(int i=0;i<n;i++){
//         int left=i-pse[i];
//         int right=nse[i]-i;
//         sum=(sum+(right*left*(1LL)*arr[i])%mod)%mod;
//     }
//     return sum;
// }
int main(){
    vector<int> arr={3,1,2,4};
    cout<<sumOfSubarrMin_brute(arr);
}
