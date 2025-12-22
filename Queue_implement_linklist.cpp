#include<iostream>
#define Max 5
using namespace std;

struct LQueue
    {
    int data;
    LQueue *next;
   
    };

    LQueue *front, *rear, *temp;

   void init()
   {
    front = rear = temp = NULL;
   }

   void Enq(int x)
   {
    temp = new LQueue; // create dynamic memory
    if(temp == NULL)    // memory alocation fail
    return ;

    temp-> data =x;

    temp -> next =NULL;
    if(front == NULL && rear ==NULL)

    front=rear=temp;

    else{
        rear-> next = temp;
        rear = temp;
        }
   }

   int DeQ()
   {
    int x;
    if(front == NULL)
         return ;

         x= front-> data;
         temp = front;

         if(front==rear)
         front = rear;
         
         else 
           {        
            front = front->next;
             temp ->next =NULL;
             delete temp;
             return x;    
           }
   }

int main ()
{
    init();
    Enq(10);
    Enq(50);
    Enq(30);

     cout << DeQ();
     cout << DeQ();
      cout << DeQ(); 
}
 