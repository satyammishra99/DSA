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
int length(node*head){
	int count=0;
	while(head!=NULL){
		count++;
		head=head->next;
	}
	return count;
}
node*insertnode(node*head,int data,int i){
	node*newnode=new node(data);
	node*temp=head;
	int count=0;
	if(i==0){
		newnode->next=head;
		head=newnode;
		return head;
	}
	while(temp!=NULL&&count<i-1){
		temp=temp->next;
		count++;
	}
	if(temp!=NULL){
		node*a=temp->next;
		temp->next=newnode;
		newnode->next=a;
	}
	return head;
}
node*deletenode(node*head,int i){
	int count=0;
	node*temp=head;
	if(i==0){
		head=temp->next;
		delete temp;
		return head;
	}
	while(temp!=NULL&&count<i-1){
		temp=temp->next;
		count++;
	}
	if(temp!=NULL){
		node*a=temp->next;
		node*b=a->next;
		temp->next=b;
		delete a;
	}
	return head;
}
int recursive_length(node*head){
	if(head==NULL){
		return 0;
	}
	return 1+recursive_length(head->next);
}
node*insertnode_recursively(node*head,int data ,int i){
	if(head==NULL){
		return head;
	}
	if(i==0){
		node*newnode=new node(data);
		newnode->next=head;
		head=newnode;
		return head;
	}
	node *x=insertnode_recursively(head->next,data,i-1);
	head->next=x;
	return head;
}
void makecycle(node*head,int pos){
	node*temp=head;
	node*startnode;
	int count=1;
	while(temp->next!=NULL){
		if(count==pos){
			startnode=temp;
		}
		temp=temp->next;
		count++;
	}
	temp->next=startnode;
}
void deleteloop(node*head){
	if(head==NULL||head->next==NULL){
		return;
	}
	node*fp=head;
	node*sp=head;
	sp=sp->next;
	fp=fp->next->next;
	while(fp!=NULL&&sp->next!=NULL){
		if(sp==fp){
			break;
		}
		sp=sp->next;
	    fp=fp->next->next;
	}
	if(sp==fp){
        fp=head;
        if(sp==fp){
            while(sp->next!=fp){
                sp=sp->next;
            }
        }
        else{
            while(fp->next!=sp->next){
                 fp=fp->next;
                 sp=sp->next;
            }
        }   
        sp->next=NULL;
        
       }
}
node*reverse(node*head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node*smallans=reverse(head->next);
	node*tail=head->next;
	tail->next=head;
	head->next=NULL;
	return smallans;
}
node*foldandmerge(node*head){
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	node*head2=slow->next;
	slow->next=NULL;
	//cout<<head2->data<<endl;
	node*rev=reverse(head2);
	//cout<<rev->data;
//	while(head2!=NULL){
//		cout<<"enter";
//		cout<<head2->data<<" ";
//		head2=head2->next;
//	}
	node*tail=head;
	while(tail){
		//cout<<rev->data<<" ";
		tail->data=(tail->data)*(rev->data);
		tail=tail->next;
		rev=rev->next;
	}
//	cout<<endl;
	return reverse(head);
}
int main(){
	node*head=takeinput();
	print(head);
	/*int l=recursive_length(head);
	cout<<endl;
	cout<<l<<endl;
	int i;
	int data;
	cin>>i>>data;
	head=insertnode_recursively(head,data,i);
//	print (head);
//	cout<<endl;
//	head=deletenode(head,3);
	print(head);   */
//	makecycle(head,2);
	//print(head);
	//deleteloop(head);
	node*head1=foldandmerge(head);
	//node*head1=reverse(head);
	print(head1);
	
	
}
