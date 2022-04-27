// Assessment 2...
/*Design an array based data structure for two stacks called a DualStack... The two stacks should share
the same array in an efficient manner... If there are MaxSize entries in the array then the IsFull 
function should only return true if all the entries in the array are occupied... Your operations should
all be constant time... 
a. Implement Push(S: DualStack pointer, i: integer, p: blob pointer) that pushes the blob pointed to
by p in the ith stack in S (i = 0 or 1). Similarly, implement Pop, IsEmpty, IsFul...
b. Explain why such a nice data structure would not be possible for 3 stacks...*/
#include <iostream>
using namespace std;
class Node              // Node class for defining Node attributes
{
    public:     // Data members
        int data;
        Node* next;
        Node(int value)    // Parametrized Constructor
        {
            data = value;
            next = NULL;
        }
};
class DualStack   // Class for Implementing Dual Stack
{
    public:
        Node* top;     // Top pointer member for every Stack
        int height;
        DualStack()
        {
            top = NULL;
            height = 0;
        }
        void Push(int &t, int val)  // Push Operation O(1) time...
        {
            Node* n = new Node(val);
            if(top == NULL)           // If Stack is Empty
            {
                top = n;
                height++;
                t = top -> data;   // Attaching the reference of the Array item to the value
                return;                  // Coming out of the function
            }
            n -> next = top;
            top = n;
            height++;     // Increasing height of the Stack
            t = top -> data;   // Attaching the reference of the Array item to the value
        }
        void Pop()   // Pop Operation O(1) time...
        {
            if(top == NULL)
            {
                cout << "Since Stack is empty nothing can be popped out from the Stack !!" << endl;
                return;
            }
            Node* temp = top;
            height--;           // Decreasing height of the Stack
            top = temp -> next; 
            delete temp;          // Deleting the top Node
        }
        void PrintStack()    // Printing Stack
        {
            Node* temp = top;
            if(temp == NULL)
            {
                cout << "Top <--- \t EMPTY" << endl;
                return;
            }
            if(temp != NULL)
            {
                cout << "Top <--- \t" << temp -> data << "\t";
                temp = temp -> next;
            }
            for(; temp != NULL; temp = temp -> next)
            {
                cout << temp -> data << "\t";
            }
            cout << endl;
        }
};
int main()
{
    int s, x, v, place, s1;
    string str;
    cout << "Enter size of the Array : ";
    cin >> s;
    int array[s];    // Defining an Array of given size
    for(int loop = 0; loop < s; loop++) 
    {
        array[loop] = 0;    // Initializing array
    }
    DualStack stack1, stack2;     // Creating two Stacks
    cout << "Enter the number of Operations to perform : ";
    cin >> s1;
    for(int loop = 0; loop < s1; loop++)    // Loop for performing Operations
    {
        cout << "Enter A to add, D to delete, F to check if Full, P to print Array or E to check if Empty : ";
        cin >> str;
        place = 1;    // Deafult choice just for Output sake
        if(str == "A" || str == "a" || str == "D" || str == "d")
        {
            cout << "Enter 1 for 1st Stack and 2 for 2nd Stack : ";
            cin >> place;    // Entering which Stack to take into account
        }
        switch(place)
        {
            case 1:
            if(str == "A" || str == "a")
            {
                cout << "Enter the place in the array where to perform Insertion : ";
                cin >> x;
                cout << "Enter the value to be stored : ";
                cin >> v;
                if(array[x-1] != 0)   // If the place is already Occupied
                {
                    cout << "This Place is Already Occupied !!" << endl;
                    break;
                }
                stack1.Push(array[x-1], v);    // Pushing Stack
                stack1.PrintStack();
                stack2.PrintStack();
            }
            if(str == "D" || str == "d")
            {
                stack1.Pop();     // Removing the data from the chosen Stack
                array[x-1] = 0;
                stack1.PrintStack();
                stack2.PrintStack();
            }
            if(str == "E" || str == "e")
            {
                int h = stack1.height + stack2.height;   // Checking if empty O(1) time...
                if(h == 0)
                    cout << "The Array is Empty !!" << endl;
                else
                    cout << "The Array is Not Empty !!" << endl;
            }
            if(str == "F" || str == "f")
            {
                int h = stack1.height + stack2.height;   // Checking if Full O(1) time...
                if(h == s)
                    cout << "The Array is Full !!" << endl;
                else
                    cout << "The Array is Not Full !!" << endl;
            }
            if(str == "P" || str == "p")   // Printing the Array when needed
            {
                cout << "Array : " << endl;
                for(int z = 0; z < s; z++)
                    cout <<  array[z] << "\t";
                cout << endl;
            }
            break;    // break statement
            case 2:
            if(str == "A" || str == "a")
            {
                cout << "Enter the place in the array where to perform Operation : ";
                cin >> x;
                cout << "Enter the value to be stored : ";
                cin >> v;
                if(array[x-1] != 0)   // When already occupied
                {
                    cout << "This Place is Already Occupied !!" << endl;
                    break;
                }
                stack2.Push(array[x-1], v);    // Push Operation O(1) time...
                stack1.PrintStack();
                stack2.PrintStack();
            }
            if(str == "D" || str == "d")
            {
                stack2.Pop();        // Pop Operation O(1) time...
                array[x-1] = 0;
                stack1.PrintStack();
                stack2.PrintStack();
            }
            if(str == "E" || str == "e")
            {
                int h = stack1.height + stack2.height;    // Checking if Empty O(1) time...
                if(h == 0)
                    cout << "The Array is Empty !!" << endl;
                else
                    cout << "The Array is Not Empty !!" << endl;
            }
            if(str == "F" || str == "f")
            {
                int h = stack1.height + stack2.height;    // Checking if Full O(1) time...
                if(h == s)
                    cout << "The Array is Full !!" << endl;
                else
                    cout << "The Array is Not Full !!" << endl;
            }
            if(str == "P" || str == "p")    // Printing Array
            {
                cout << "Array : " << endl;
                for(int z = 0; z < s; z++)
                    cout <<  array[z] << "\t";
                cout << endl;
            }
            break;     // break statement
            default:       // Deafult case
            cout << "Wrong Choice Entered !!" << endl;
        }
    }
    return 0;     // End of the program
}