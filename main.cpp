/*
Author: Vidur Lutchminarain
Student number: 401914025
Question 1

What is an arraylist?
An arraylist is a resizeable list, unlike an array it can grow when more elements are added, also we template
the arraylist so it has the ability to handle multiple datatypes.

Description: Here we used a class to make the functions necessary for an arraylist, An arraylist is an array
             that can resize itself when it is full. Thishis is accomplished by using a pointer as an array,
             using a pointer allows us to increase the size of the array by allocating more memory to the array.

Function definitions:
add - This function adds a new item to the list, it has been overloaded, with the ability to add the new item at the
      specified position in the list.

find - This function find the position of the given element and returns it.

remove - Removes the element at a given position

getSize - returns the number of elements in the list

makeEmpty - clears the list of all elements.

print - prints the list

contains - returns true or false whether the element exisits in the list.

*/

#include <iostream>
#include <string>// for the print function to convert int to str
using namespace std;

/*============================================Making the data structure using a class=================================================================*/
template <class T>
class Arraylist
{
    public:
        Arraylist(); //constructor to initialize the array based list, with the size and type

        void add(T newElement);   //adds a new element to the end of the array
        void add(T newElement, int position); //adds a new element to a specified position of the array

        int find(T entry) ;   //checks for the value then returns the position of the list at which it is present
        int remove(int position);  //removes value at given position
        int getSize(); //returns the number of elements in the list
        void makeEmpty(); //deletes all elements in the list
        void print(); //prints the array
        bool contains();

    private:
        T *myArray; //pointer is used as we have to dynamically create the array dynamically
        int maxSize;
        int numElements;
};
/*============================================Constrcutor================================================================================================*/
//constructor, initializes array and number of elements
    template <class T>
    Arraylist<T>::Arraylist(){
        maxSize = 10;
        myArray = new T[maxSize];
        numElements = 0;
    }

/*============================================Adding the element at the end of the list====================================================================*/
    template <class T>
    void Arraylist<T>::add(T newElement)
    {
        //checks if the list is already full
        if(numElements >= maxSize)
            {
               T* newArray = new T[maxSize * 2];
                maxSize *= 2;

                 for(int i = 0; i < numElements; i++){
                    newArray[i] = myArray[i];
                    }

                delete []myArray;//relives memory
                myArray = newArray;

                myArray[numElements] = newElement; //adds element to the list
                numElements++; //increments the number of elements present
            }else
            {
                myArray[numElements] = newElement; //adds element to the list
                numElements++; //increments the number of elements present
            }


    }

/*============================================Adding the array at a specific position======================================================================*/
    template <class T>
    void Arraylist<T>::add(T newElement, int position)
    {
        //checking if the array is full
        //since it is full, and the
         if(numElements >= maxSize)
            {
                cout<<"cannot add anymore elements, the list is full"<<endl;
                return;
            }

        //checks if the position in the array is in bound(not below 0 or not higher than the max size)
            if(position < 0 || position > maxSize)
                {
                    cout<<"out of bounds"<<endl;
                    return;
                }


            //moves the elements over to make space for the new element
            for(int i = numElements; i > position; i--)
                {
                    myArray[i] = myArray[i-1];
                }


            //places the new element at the position after we make place for it
            myArray[position] = newElement; //places the new element at the position after we make place for it
            numElements++;

    }

/*===========================================Tells us the position that the given value is at=====================================================================*/
   template <class T>
   int Arraylist<T>::find(T entry)
   {
       int foundIndex = -1; //assuming it is not found
       for(int i = 0;i < numElements;i++)
        {
            if(myArray[i] == entry)
                {
                    foundIndex = i;
                    break;//exits the loop
                }
        }
        return foundIndex;//returning the index at which the first occcurance of where the searched value is
   }
/*=====================================================returns the size of the list=========================================================================================*/
    template <class T>
   int Arraylist<T>::getSize()
   {
       return maxSize;
   }
/*===========================================removes the element at the given position of the list=====================================================================*/
template <class T>
   int Arraylist<T>::remove(int position)
   {
       int value = -1;
       if(position < 0|| position > numElements)
        {
            cout<<"Out of bounds"<<endl;
            return value;
        }

        //closing the gap when we remove the element
        for(int i = position; i < numElements - 1 ; i++)
            {
                myArray[i] = myArray[i + 1];
            }
        numElements--;

       return value;
   }
/*=====================================================Makes the list empty==============================================================================*/
template <class T>
   void Arraylist<T>::makeEmpty()
   {
       numElements = 0;

   }
/*=====================================================prints the array==============================================================================*/
template <class T>
   void Arraylist<T>::print()
   {
      string out;
      string output;

              for(int i = 0;i < numElements;i++)
                {
                   out = to_string(myArray[i]);
                   output  += out + " ; ";
                }
                cout << output<<endl;
   }
/*====================================================main.cpp below:======================================================================================*/

int main()
{

    Arraylist<int> myList; // because of templating we have to specify which type to accept

for(int i =0; i < 10; i++)
    {
        myList.add(i * 10);
    }

    myList.print(); //calls function to display the list
    cout<<"Please enter an integer to add to the list: ";
    int myInt;

    cin>> myInt;

    myList.add(myInt);//adding an 11th element, the list will then now resize itself

    cout<<endl;

    myList.print();

    cout<<"The size of the list is now: "<< myList.getSize() <<endl;

    // now lets remove an element
    cout<<endl;
    cout<<"Please enter an index to remove: ";
    int myIndex;
    cin>>myIndex;

    myList.remove(myIndex);

    cout<<"The list is now: "<<endl;
    myList.print();

    cout<<endl;
    cout<<"Please enter an element to look for: ";
    //lets look for an element
    int lookFor;
    cin>> lookFor;
    cout<<"Element found at index: "<< myList.find(lookFor) << endl;

    cout<<"Pick an integer: ";
    int newInt;
    cin>> newInt;
    cout<<"Pick an index: ";
    int index;
    cin>>index;
    cout<<endl;
    cout<<"The integer has been inserted at position "<<index<<": ";
    //lets addd at a specific place
    myList.add(100,5);
    myList.print();



return 0;
}
