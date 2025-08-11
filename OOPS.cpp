#include<bits/stdc++.h>
using namespace std;

// class Teacher{

// //There are three types of access Modifiers: Private , Public and Protected
// //public allows us to view the methods and attributes outside the class
// public:
    
//     //Defining properties or attributions
//     string name;
//     string dept;
//     string subject;

//     //defining methods or member functions
//     void changeDept(string newDept){
//         dept=newDept;
//     }

//     //setter function
//     void setSalary(double s){
//         salary=s;
//     }

//     //getter function
//     double getSalary(){
//         return salary;
//     }
// private:
//     double salary;
// };

// //The Four Pillars of OOPS
// //Encapsulation : Wrapping up of data & member functions in a single unit called class
// //Polymorphism : 
// //Abstraction : 
// //Inheritance :


// class Account {
// private:
//     double balance;
//     string password;//data hiding

// public:
//     string accountId;
//     string username;

// };

// /*Constructor : 
//     A function that is automatically called(and called only once) when a new object is created
//     Same name as class and doesn't have a return type
//     There are parametrised and non parametrised constructor

//     A thing to be noted is that we can have more than one constructor only if both of them can be differentiated by the arguments inside
//     See below 
//     */


// class Student{
// public:
//     string dept;
//     string name;
//     int age;
//     double salary;

//     //If the student is created along with paranthesis with some arguments that are matching this one ,then this constructor will be called
//     Student(string n,int a,double sal){
//         cout<<"First constructor called";
//         name=n;
//         age=a;
//         salary=sal;
//     };

//     //If the object is created without giving arguments , then this constructor will be created
//     Student(){
//         cout<<"Constructor without arguments";
//     }
// };

// //This phenomenon of having multiple constructors is called constructor overloading and this is a feature of polymorphism

// //Suppose in the earlier example where we gave arguments to the constructor , we wrote n for shorthand name, since if we write name=name , it would be too confusing for the program
// //This is where the this-> comes in use , it means we are referring to the current object

// class Employee{
// public:
    
//     //We need to declare the variable outside the constructor otherwise they will be defined as local variables and won't be accessible
//     string name;
//     int salary;
//     Employee(string name,int salary){
//         this->name=name;
//         this->salary=salary;
//     }
// };

// /*Copy Constructor:
//     A copy constructor is created by default if none is created by user
//     for eg after creating employee e1 with some argument, suppose we want to create another employee e2 with same arguments, should we pass the arguments again in e2
//     For this we use Employee e2(e1) , then when we do cout<<e2.salary , we still get correct salary as we wanted
//     This happens because the copy constructor in invoked by default

// Working of the copy constructor : 
//     The constructor creates a exact replica of the object that has been passed and then names it as required

// We can still create a copy constructor ourselves as shown below

// */

// class Labour{
// public:

//     string name;
//     int wage;
//     int age;

//     Labour(string name,int wage,int age){
//         this->name=name;
//         this->wage=wage;
//         this->age=age;
//     }

//     Labour(Labour &l1){
//         cout<<"I am copy constructor";
//         this->name=l1.name;
//         this->wage=l1.wage;
//         this->age=l1.age;
//     }
// };

// /*
// When copies of an object are created , they can be of two types, shallow copy and deep copy
// Shallow Copy : Most commonly used, copies all of the member values from one object to another
//              : Shallow Copy gets a issue in case of dynamic memory allocation
//              : Normal memory allocation happens in the stack memory 

// Memory is of two types in c++
// Stack or static memory (faster but limited in size, also follows LIFO)
// & 
// Heap memory(slower but much larger, and any element can be accessed)
// Heap memory is used for dynamic allocation.
// Deep Copy : 
// */

// class People{
// public:
//     string name;
//     int* agePtr;
    
//     People(string name,int age){
//         this-> name=name;
//         agePtr=new int;
//         *agePtr=age;
//     }

//     void getInfo(){
//         cout<<"Name : "<<name<<endl;
//         cout<<"Age : "<<*agePtr<<endl;
//     }

//     People(People &p1){
//         this->name=p1.name;
//         this->agePtr=p1.agePtr;
//     }
// };

// //Come here after reading the people class created 
// //The deep copy not only copies the member values but also makes copies of any dynamically allocated memory that the members point to
// //A constructor that creates a deep copy is not provided by default, we have to make it ourselves

// class Guest{
// public:
//     string name;
//     int*agePtr;
//     Guest(string name,int age){
//         this->name=name;
//         agePtr=new int;
//         *agePtr=age;
//     }
//     Guest(Guest &g1){
//         this->name=g1.name;
//         agePtr=new int;
//         *agePtr=*g1.agePtr;
//     }

//     /*
//     Now we talk about destructor(opposite of constructor) , Constructor allocates memory , it deallocates memory
//     By default a destructor exists that only de allocates the static memory, a memory that has been allocated dynamically should be deallocated dynamically (or by user only)
//     We use the word delete to delete the memory to which the pointer is pointing
//     */
//    //A ~ is used to declare a destructor
//    //This destructor would have been called anyways(a default one) and deleted every stack memory , but this time since we have made a destructor ourselves , the default one won't be called
//    //Even when we make a destructor ourselves , we don't need to delete the stack memory , it will be done automatically, we only make the destructor to delete the heap or randomly allocated memory
//    ~Guest(){
//     cout<<"Destructor deleting everything";
//     delete agePtr;//This does not delete the pointer, but deletes the memory to where the pointer is pointing ,pointer still exitst
//     cout<<agePtr;//This line's output proves that pointer exists
//    }
// };


// //Inheritance
// class Parent {
// public:
//     string name;
//     int age;

//     Parent(){
//         cout<<"Parent Constructor\n";
//     }

//     ~Parent(){
//         cout<<"Parent Destructor\n";
//     }

// };

// class Child : public Parent{
// public:
//     //name age and rollno
//     int rollno;

//     Child(){
//         cout<<"Child Constructor\n";
//     };
//     ~Child(){
//         cout<<"Child Destructor\n";
//     }

//     void getInfo(){
//         cout<<"name : "<<name<<endl;
//         cout<<"age : "<<age<<endl;
//         cout<<"rollno : "<<rollno<<endl;
//     }
// };

//In inheritance the constructor of the Parent is called first, and then the constructor of the child is called
//However the destructor is called first for child and then the parent

//Let's now study this inheritance with a parametrised constructor

// class Father{
// public:
//     string name;
//     int age;
//     Father(string name,int age){
//         this->name=name;
//         this->age=age;
//     }
// };

// class Son : public Father{
// public:
//     int rollno;
//     Son(string name,int age,int rollno) : Father(name,age){
//         this->rollno=rollno;
//     }
//     void getInfo(){
//         cout<<"Name : "<<name<<"\n";
//         cout<<"Age : "<<age<<"\n";
//         cout<<"rollno : "<<rollno<<"\n";
//     }
// };


//Inheritance from multiple classes

// class Student{
// public:
//     string name;
//     int rollno;
// };

// class Teacher{
// public:
//     string subject;
//     double salary;
// };

// class TA:public Student, public Teacher{
// public:
//     string researchArea;

//     void getInfo(){
//         cout<<"Name : "<<name<<"\n";
//         cout<<"Roll No : "<<rollno<<"\n";
//         cout<<"Subject : "<<subject<<"\n";
//         cout<<"Salary : "<<salary<<"\n";
//         cout<<"Research Area : "<<researchArea<<"\n";
//     }
// };


//Polymorphism : The ability of objects to take on different forms or behave in different ways depending on the context in which they are used
// class Student{
// public:
//     string name;
//     Student(){
//         cout<<"non parametrised constructor";
//     };
//     Student(string name){
//         cout<<"Parametrised constructor";
//         this->name=name;
//     }

//     //This thing is called constructor overloading , that is the object knows which constructor to call depending on the context(arguments here)
//     //Constructor overloading is a part of polymorphism(Compile Time Polymorphism)
// };

//Polymorphism is of two types : Compile time polymorphism and Run time polymorphism
//Function Overloading is another example of Compile Time Polymorphism

class Math{
public:
    int a;
    int b;
    int c;
    Math(int a,int b,int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    int add(int a,int b){
        cout<<"The double parameter function is called";
        return a+b;
    };
    int add(int a,int b,int c){
        cout<<"The triple parameter function is called";
        return a+b+c;
    };
    //This shows function overloading
    //There also exists operator overloading
};

//Run Time Polymorphism
//An eg is function overriding
//A similar function when exists in both the parent and child class then the child's one is executed and the parent's one is overridden

// class Parent{
// public:
//     void getInfo(){
//         cout<<"parent class\n";
//     }
//     virtual void hello(){
//         cout<<"hello from parent\n";
//     }
//     //Virtual functions are also a part of Run time polymorphism
//     //Always declared with a base class and overridden in a child class
//     //Only called during run time, and are dynamic in nature
// };

// class Child{
// public:
//     void getInfo(){
//         cout<<"child class";
//     }
//     void hello(){
//         cout<<"hello from child class\n";
//     }
// };


//Abstraction : Hiding all the unnecessary details & showing only the important parts
//Access Modifiers were a part of abstraction : Private , Protected and Public

class Shape{
    virtual void draw()=0;//pure virtual function
    //We can't define the draw function completely since we don't know which shape to draw
};

class Circle : public Shape{
    public:
        void draw(){
            cout<<"drawing circle\n";
        }
};
//A class with a pure virtual function automatically becomes an abstract class
//just try running this code inside int main : Shape s1;


//Static Keywords:
//Static Variables: Variables declared static in a function are created & initialised once for the lifetime of the program.(in function)
//Static Variables in a class are created & initialised once. They are shared by all the objects of the class.(in class)

//Static Objects:
// 

void fun(){
    int x=0;
    cout<<x<<"\n";
    x++;
}
//Write fun three times(inside int main) , you will understand
//Here each time a function is called , it is pushed to the stack and the initialisation x=0 happens each time,
//After the function is completed , the variable x is erased from memory

void func(){
    static int y=0;
    cout<<y<<"\n";
    y++;
}
//This time the initialisation happens only once, and the variable y is created apart from stack memory ,where it is not thrown away after use
//Run func() inside int main three times to see

class ABC{
    public:
    ABC(){
        cout<<"constructor\n";
    };
    ~ABC(){
        cout<<"destructor\n";
    }
};
int main(){

    //We can create an object on the basis of the class Teacher
    // People p1("Rahul",45);
    // People p2(p1);
    // p1.getInfo();
    // *(p2.agePtr)=88;
    // p1.getInfo();
    //This results in the change of p1 info (age) , this is the problem with shallow copy
    //Since it is a shallow copy therefore both the pointer are pointing to same location , this is the problem, hence change in one leads to change in both
    //Even if we use the default copy constructor (by not making our own, the problem persists), this is why we need the deep copy

    // Guest g1("Rahul",55);
    // Guest g2(g1);
    // cout<<*(g1.agePtr);
    // cout<<*(g1.agePtr);
    // cout<<*(g2.agePtr);

    // Child c1;
    // c1.name="rahul Kumar";
    // c1.age=23;
    // c1.rollno=1234;
    // c1.getInfo();

    // Son s1("rahul",34,3434);
    // s1.getInfo();

    // TA t1;
    // t1.name="rahul";
    // t1.rollno=23;
    // t1.salary=34000;
    // t1.subject="engineering";
    // t1.researchArea="Quantum Physics";
    // t1.getInfo();

    // Math m1(12,13,14);
    // m1.add(12,45,55);

    // Child c1;
    // c1.getInfo();
    // c1.hello();

    // Shape s1;

    // Circle c1;
    // c1.draw();

    // func();
    // func();
    // func();

    // if(true){
    //     ABC obj;
    // }
    // cout<<"end of main function\n";

    if(true){
        static ABC obj;
    };

    cout<<"end of main function\n";
    //When we use the word static , the object will remain in the memory until the main function ends, only after it ends , the object will be removed from memory
    return 0;

}
