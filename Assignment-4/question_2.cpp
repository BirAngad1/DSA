#include <bits/stdc++.h>
using namespace std;

class Circle{
	public:
	int size,front,rear,count;
	int *a;
	public:
	Circle(int n){
	    size = n;
		a= new int [size];
		front = 0;
		rear = -1;
		count=0;
	}
    bool isEmpty(){
    	return count == 0;
	}
	bool isFull(){
    	return count == size;
	}
	void enqueue(int x){
		if(isFull()){
			cout<<"Queue is Full\n";
			return;
		}
		
        rear= (rear+1)%size;
        a[rear]=x;
        count++;
		}
	
	void dequeue()
	{
		if(isEmpty())
		{
			cout<<"Queue is empty\n";
			return;
		}
		cout<<"deleted: "<<a[front]<<endl;
		front= (front+1)%size;
		count--;
	}
	void display()
	{
		for(int i=0; i<count;i++)
		{
			cout<<a[(front+i) % size]<<" ";
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
	Circle c(n);
	
	do{
		cout<<"\n 1.enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\nChoice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter value:";
				cin>>val;
				c.enqueue(val);
				break;
			case 2:
				c.dequeue();
				break;
			case 3:
				c.display();
				break;
			case 4:
				c.peek();
				break;
		}
	}while(choice!=5);
	return 0;
}
