#include<iostream>
using namespace std;
class Queue{

    int front;
    int rear;
    int arr[5];

    public:
    Queue(){
        front = -1;
        rear = -1;
        for(int i = 0; i < 5; i++){
            arr[i]=0;
        }
        
    }

    bool is_empty(){
        if(front == -1 & rear == -1)
            return true;
        else
            return false;
    }

    bool is_full(){
        if(front == 0 & rear == 4)
            return true;
        else
            return false;
    }

    void enqueue(int value){
        if(is_full()){
            cout<<" error, the Queue is full, you cannot add to it "<<endl;
            return ;
        }
        if(is_empty()){
            front = rear = 0;
            arr[front] = value;
            //arr[rear] = value;
        }else{
            rear++;
            arr[rear] = value;
        }
    }

    int dequeue(){
        int copy_will_be_removed;
        if(is_empty()){
            cout<<" error, the queue is empty, you cannot remove from it "<<endl;
            return 0;
        } // redundant checking not empty cuz empty is : front = -1, rear = -1, filter that out , the only condition that will make front = rear is one existing element. 
        if( ( (is_empty()) == false ) & (front == rear) ){
            //arr[front] = 0
            
            copy_will_be_removed = arr[rear];
            arr[rear] = 0;
            front = rear = -1;
        }else{
            copy_will_be_removed = arr[front];
            arr[front] = 0;
            front++;
        }
        return copy_will_be_removed;
    }

    int count(){
        if(is_empty()){
            cout<<" ZERO person in line"<<endl;
            return 0;
        }else if(front == rear){
            cout<<"One person in line "<<endl;
            return 1 ;
        }else{
            return(rear-front)+1;
        }
    }

    void display(){
        for(int i = 0; i<5; i++){
            cout<<arr[i]<<endl;
        }
    }

};

int main()
{
    Queue q1;
    int integer;
    int option;
    do
    {
        cout<<"Pick a option below to perform "<<endl;
        cout<<"0. Exit. "<<endl;
        cout<<"1. enqueue "<<endl;
        cout<<"2. dequeue "<<endl;
        cout<<"3. is_empty"<<endl;
        cout<<"4. is_full "<<endl;
        cout<<"5. count "<<endl;
        cout<<"6. display "<<endl;
        cout<<"7. clear screen "<<endl;

        cout<<" Enter a option number : ";
        cin>>option;

        switch(option)
        {
/*             case 0:
                cout<<"0. Exit. "<<endl;
                cout<<" You've Exited the program, GOOD BYE ";
                break; */

            case 1:
                cout<<"1. enqueue "<<endl;
                cout<<" enter an integer to insert in this queue : ";
                cin>>integer;
                q1.enqueue(integer);
                break;
            case 2:
                cout<<"2. dequeue "<<endl;
                q1.dequeue();
                break;
            case 3:
                cout<<"3. is_empty"<<endl;
                cout<<q1.is_empty()<<endl;
                break;
            case 4:
                cout<<"4. is_full"<<endl;
                cout<<q1.is_full()<<endl;
                break;
            case 5:
                cout<<"5. count  "<<endl;
                cout<<"number of persons in line are: " <<q1.count()<<endl;
                break;
            case 6:
                cout<<"6. display "<<endl;
                q1.display();
                break;
            case 7:
                cout<<"7. clear screen "<<endl;
                system("cls");
                break;
            default:
                cout<<" enter a correct option from 0 to 7: "<<endl;  // this makes the while statement false?
        }                                                           // yes, anything character that is not an int type (maybe)
        
    } while (option!=0);
    
    return 0;
}







/* Testing code / DEBUG
####################
    bool jar = s1.is_empty();
    //jar == false;
    if(jar == true)
        cout<<" yes"<<endl;
    else
        cout<<"no"<<endl; */
