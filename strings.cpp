/*
Strings

Strings are mutable
Indexing in strings is 0 based

First let us discuss how memory is allocated for dynamic structures like strings or vectors
Consider you create a vector or string, the system allocates some memory chunk for it which is large enough to store say 20 or 30 characters
Now the push_back or append operations happen in O(1) time. After some time, this space get filled up
Then that memory chunk is deleted and a new memory chunk is allocated which is often 2 times the size (the size grows geometrically, it can be 2x or 3x or 4x)
And then the whole string or vector is copied to that new chunk
Hence in such case when the memory chunk gets full, the push_back operations can take O(n) 

If you just initialise like vector<int> arr, the size of capacity allocated can be anything
In case you do vector<int> arr(200) then the memory chunk will be atleast 200, meaning it can be anything>=200

Concatenation : Consider two strings, a of len n and b of len m. The operation of adding one string to another, whether at the back or at the front, takes time n+m
Adding at the front : The whole string has to be shifted and hence the time taken is O(n)
Adding at the back :  Suppose you are adding s to ticket to make it tickets. Now two things can happen
First is that there is space/memory available and so s can be just put ahead of ticket. In that case time taken will be O(1)
Incase no memory is available, a new memory block will be created in which first the ticket will be copied and then s will be appended
Copying dominates and make the time complexity to n

Character Arithmetic :
First let us discuss the ASCII Code
Remember this : 
'A' - 'Z'  => 65 to 90
'a' - 'z'  => 97 to 122
'0' - '9'  => 48 to 57

Also difference between a and A : 'a'-'A'=32

char and int are interconvertible according to the ASCII code
Now remeber : adding a char to a int => result is int which can be converted to char as well (according the ASCII)
Also char+char is also results in an int. Remember when the addition happens the char is converted to int and then added

Notes:
Char to index : c-'a' => 0 to 25
Index to char : i+'a' 
Convert to lowercase : c+32
Convert to uppercase : c-32

Comparision in strings : Compared lexicographically
That means lower ASCII value means less and if one strings ends earlier the shorted one is smaller
The method s1<s2 is built in and runs in optimal O(min(l1,l2))
Eg. "apple">"Banana" since ASCII value of a is bigger than B


Commonly Used Methods:
substr(pos,len) : to extract a new string from a string. pos means starting position and len means the length of string to be formed
It does not change the original string and returns a new string
If len>str.size() then the whole string starting from pos is return. For eg substr(3,100) used on "0123456" returns "3456"
Pos however must be within range, otherwise error is thrown
If you just want string from pos x till the end the use substr(pos) that's it, no need to give second argument
Time taken for this substr will be O(k) where k is the length of the string returned
Space used is O(k) since a new string is created

*/


//Phase 0 : Basics
//Algorithms : 
//Manual string comparison

//Compare if two strings are equal or not without using the == operator
bool areEqualI(string &a,string &b){
    int n=a.size();
    int m=b.size();
    if(n!=m) return false;
    
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}
//The for loop runs n times
//No extra space is used
//Time Complexity will be O(n)
//Space Complexity will be O(1)


//Tell which string is bigger and which is smaller lexicographically, without comparing the strings directly
//Return 1 if the first string is smaller 2 if second is smaller and 0 if both are equal
int lexicoCompare(string &a,string &b){
    int n=a.size();
    int m=b.size();

    for(int i=0;i<min(n,m);i++){
        if(a[i]==b[i]) continue;
        else if(a[i]<b[i]) return 1;
        else return 2;
    }

    if(n==m) return 0;
    if(n>m) return 2;

    return 1;
}
//The code runs for min(n,m)
//No extra space is used 
//Time Complexity will be O(min(n,m))
//Space Complexity will be O(1)


//Prefix Equality Check
//See if one string is a prefix of the other
bool isPrefix(string &prefix,string &s){
    int m=prefix.size();
    int n=s.size();
    if(m>n) return false;
    for(int i=0;i<m;i++){
        if(s[i]!=prefix[i]) return false;
    }
    return true;
}
//The loop runs for m times
//No extra space is used
//Time Complexity will be O(m)
//Space Complexity will be O(1)


//Frequency Array
//Count How many times a single char appears in a string
//Here we only deal with lowercase char
//However if we require we can extend the array to accomodate even uppercase letters
vector<int> countFreq(const string &s){
    int n=s.size();
    vector<int> freq(26,0);
    for(int i=0;i<n;i++){
        char c=s[i];
        int idx=c-'a';
        freq[idx]++;
    }
    return freq;
}
//The loop runs for n times
//No extra space is used 
//Time Complexity will be O(n)
//Space Complexity will be O(1)


//Anagram Check
//If word a can be formed just by rearranging word b then it means they are anagrams
//We can use the freq array to check for anagrams
bool anagramCheck_brute(string &s1,string &s2){
    int n=s1.size();
    int m=s2.size();
    if(n!=m) return false;
    vector<int> f1=countFreq(s1);
    vector<int> f2=countFreq(s2);
    for(int i=0;i<26;i++){
        if(f1[i]!=f2[i]) return false;
    }
    return true;
}
//The two countFreq functions run for n times
//The for loop run for 26 times
//Space is used by the two freq arrays
//Time Complexity will be O(2n+26)
//Space Complexity will be O(52)

//Optimal Method
//We can reduce the space by half by using a single freq array and just one pass
bool anagramCheck(string &s1,string &s2){
    int n=s1.size();
    int m=s2.size();
    if(n!=m) return false;
    vector<int> freq(26,0);
    for(int i=0;i<n;i++){
        char a=s1[i];
        char b=s2[i];
        freq[a-'a']++;
        freq[b-'a']--;
    }

    for(int i=0;i<26;i++){
        if(freq[i]!=0) return false;
    }
    return true;
}
//Only two loops one runs n times and the other running 26 times
//Space is occupied by the single freq array of 26 size
//Time Complexity will be O(n+26)
//Space Complexity will be O(26)


//Reverse a string
string revStr(string s){
    int n=s.size();
    int i=0;
    int j=n-1;
    while(i<j) swap(s[i++],s[j--]);
    return s;
}
//The while loop runs for half the size
//No extra space is used to solve the question
//Time Complexity will be O(n/2)
//Space Complexity will be O(1)


//Check For Palindrome
bool isPalindrome(string &s){
    int n=s.size();
    int i=0;
    int j=n-1;
    while(i<j){
        if(s[i++]!=s[j--]) return false;
    }
    return true;
}
//The while loop runs for n/2 times
//No extra space is needed to solve the question
//Time Complexity will be O(n/2)
//Space Complexity will be O(1)




/*
Phase 1 : Prefix Techniques (Foundation)
Prefix Function (KMP Preprocessing)
Prefix Function (n array)

Consider the string "apple"
Prefixes : "", "a", "ap", "app", "appl", "apple" ("apple" is not a proper prefix)
Suffixes : "", "e", "le", "ple", "pple", "apple" ("apple" is not a proper suffix)
Border : Elements appearing in both prefix and suffix
The string "" is called a trivial border


*/

vector<int> arr;