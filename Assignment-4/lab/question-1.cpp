#include <bits/stdc++.h>
using namespace std;

class Simple{
	public:
	int size,front,rear;
	int *a;
	public:
	Simple(int n){
	    size = n;
		a= new int [size];
		front = -1;
		rear = -1;
	}
    bool isEmpty(){
    	return front == -1;
	}
	bool isFull(){
    	return rear == size - 1;
	}
	void enqueue(int x){
		if(isFull()){
			cout<<"Queue is Full\n";
			return;
		}
		if(front == -1)
		{
			front=0;
			a[++rear]=x;
		}
		else
		{
			rear++;
			a[rear]=x;
		 }
		}
	
	void dequeue()
	{
		if(isEmpty())
		{
			cout<<"Queue is empty\n";
			return;
		}
		cout<<"deleted: "<<a[front]<<endl;
		if(front == rear){
			front--;
			rear--;
		}
		else{
			front++;
		}
	}
	void display()
	{
		for(int i=front; i<=rear;i++)
		{
			cout<<a[i]<<" ";
			cout<<endl;
		}
	}
	void peek()
	{
		if(!isEmpty())
		{
			cout<<"Front element: "<<a[front]<<endl;
		}
	}
};
int main()
{
	int n, choice, val;
	cout<<"Enter size of queue: ";
	cin>>n;
	Simple s(n);
	
	do{
		cout<<"\n 1.enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\nChoice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter value:";
				cin>>val;
				s.enqueue(val);
				break;
			case 2:
				s.dequeue();
				break;
			case 3:
				s.display();
				break;
			case 4:
				s.peek();
				break;
		}
	}while(choice!=5);
	return 0;
}
