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
node*midpointlinkedlist(node*head){
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
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
			tail=tail->next;
		}
		cin>>data;
	}
	return head;
}
void print(node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
int main(){
	node*head=takeinput();
	print(head);
	cout<<endl;
	node*mid=midpointlinkedlist(head);
	cout<<mid->data<<endl;
}
