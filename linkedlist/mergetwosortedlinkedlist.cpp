#include<iostream>
using namespace std;
class node{
	public :
		int data;
		node*next;
	node(int data){
		this->data=data;
		this->next=NULL;
	}
};
node* input(){
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
			tail=tail->next;
		}
		
		cin>>data;
	}
	return head;
}
node*mergesort(node*h1,node*h2){
	node*fH=NULL;
	node*fT=NULL;
	/*if(h1==NULL){
		return h2;
	}
	if(h2==NULL){
		return h1;
	}*/
	if(h1!=NULL&&h2!=NULL){
		if(h1->data<h2->data){
			fH=h1;
			fT=h1;
			h1=h1->next;
		}
		else if(h2->data<h1->data){
			fH=h2;
			fT=h2;
			h2=h2->next;
		}
	}
	while(h1!=NULL&&h2!=NULL)
	{
		if(h2->data<=h1->data){
			fT->next=h2;
			h2=h2->next;
			fT=fT->next;
		}
		else if(h1->data<h2->data){
			fT->next=h1;
			h1=h1->next;
			fT=fT->next;
		}
	}
	while(h1!=NULL){
		fT->next=h1;
		h1=h1->next;
		fT=fT->next;
	}
	while(h2!=NULL){
		fT->next=h2;
		h2=h2->next;
		fT=fT->next;
	}
	return fH;
}
void print(node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
int main(){
	node*h1=input();
	print(h1); 
	cout<<endl;
	node*h2=input();
	print(h2);
	cout<<endl;
	node*head=mergesort(h1,h2);
	cout<<endl;
	print(head);
}
