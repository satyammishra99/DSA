#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	node(int data){
		this->data=data;
		next=NULL;
	}
};
   void print(node*head){
   	  while(head!=NULL){
   	  	cout<<head->data<<" ";
   	  	head=head->next;
		}
   }/*
   node*takeinput(){
   	int data;
   	cin>>data;
   	node*head=NULL;
   	while(data!=-1){
   		node*newnode=new node(data);
   		if(head==NULL){
   			head=newnode;
		}
		else{
			node*temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newnode;
		}
		cin>>data;
	}
	return head;
   }*/
   node*takeinput(){
   	int data;
   	cin>>data;
   	node*head=NULL;
   	node*tail=NULL;
   	while(data!=-1){
   		node*newnode=new node(data);
   		if(head==NULL){
   			head=newnode;
   			tail=newnode;
		}
		else{
			tail->next=newnode;
			tail=newnode;
		}
		cin>>data;
	}
	return head;
}
int main(){
	node*head=takeinput();
	print(head);
}
/*
int main(){
	node n1(1);
	node*head=&n1;
	node n2(2);
	node n3(3);
	n1.next=&n2;
	n2.next=&n3;
	print(head);
}*/
