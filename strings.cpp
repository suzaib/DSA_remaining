/*
Strings

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

ASCII Code
Remember this : 
'A' - 'Z'  => 65 to 90
'a' - 'z'  => 97 to 122
'0' - '9'  => 48 to 57

Also difference between a and A : 'a'-'A'=32
Indexing in strings is 0 based

Commonly Used Methods:
substr(pos,len) : to extract a new string from a string. pos means starting position and len means the length of string to be formed


*/

vector<int> arr;