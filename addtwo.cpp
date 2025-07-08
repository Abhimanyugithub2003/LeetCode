#include<iostream>
using namespace std;
struct node{
    node* next;
    int data;
    node(int d){
        data=d;
        next=nullptr;
    }
};

void insertatend(node* &head,int data){
    node* newnode=new node(data);
    if(head==nullptr){
        head=newnode;
        return;
    }
    node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
}
int m(node* &head){
    node* temp=head;
    int d=temp->data;
    while(temp->next){
        d*=10;
        temp=temp->next;
        int l=temp->data;
        d+=l;
    }
    return d;
}
node* num(int x){
    node* dummyhead=new node(-1);
    while(x!=0){
        int l=x%10;
        insertatend(dummyhead,l);
        x/=10;
    }
    return dummyhead->next;
}
void print(node* head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
int main(){
    node* head=nullptr;
    insertatend(head,3);
    insertatend(head,4);
    insertatend(head,2);
    print(head);
    int n=m(head);
    cout<<n<<endl;
    node* newhead=num(n);
    print(newhead);
    node* head2=nullptr;
    insertatend(head2,4);
    insertatend(head2,6);
    insertatend(head2,5);
    print(head2);
    int n2=m(head2);
    cout<<n2<<endl;
    node* newrll=num(n2);
    print(newrll);
    int sum=n+n2;
    node* ans=num(sum);
    print(ans);
}