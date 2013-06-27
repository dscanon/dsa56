#include <iostream>
using namespace std;
  
struct node
{
    node *link;
    int data;
    /* data */
};
  
node *head=NULL;
node *tail=NULL;
int count=0;
void insert(int n){
    node *cp=new node;
    cp->data=n;
    cp->link=NULL;
    if(head==NULL&&tail==NULL){
        head=cp;
    }
    else tail->link=cp;
    tail=cp;
    count++;    
}
  
void printNode(){
    cout<<"----------------"<<endl;
    node *cursor=head;
    while(cursor!=NULL){
        cout<<cursor->data<<endl;
        cursor=cursor->link;
    }
} 
int roPer;
void rotate(int per){
    node *tail2=head;
    roPer=100-per;
    int posi=count*(per/100.0);
    cout<<"Position : "<<posi<<endl;
    for(int j=1;j<posi;j++){
        tail2=tail2->link;
    }
    node *head2=tail2->link;
    cout<<tail2->data<<endl;
    cout<<head2->data<<endl;
    tail->link=head;
    tail2->link=NULL;
    head=head2;
    tail=tail2;
} 
  
void rotateBack(){
    rotate(roPer);
}
  
void cut(int per){
    node *tail2=tail;
    node *tail=head;
    node *htmp=head->link;
  
    int posi=count*(per/100.0);
    cout<<"Position :"<<posi<<endl;
    for(int i=1;i<posi;i++){
        tail=tail->link;
    }
    node *head2=tail->link;
      
    node *htmp2=head2->link;
    tail->link=NULL;
  
    /*node *cp=head;
    while(cp!=NULL){
        //cout<<cp->data<<endl;
        cp=cp->link;
    }
    cp=head2;
    while(cp!=NULL){
        cout<<cp->data<<endl;
        cp=cp->link;
    }*/
  
    for(int i=1;(i<posi)&&i<(count-posi);i++){
        if(per>50){
            while(htmp2!=NULL){
                htmp=head->link;
                htmp2=head2->link;
                head->link=head2;
                head2->link=htmp;
                head=htmp;
                head2=htmp2;
            }
        }
    }
}
  
  
int main(){
    for(int i=1;i<=10;i++){
        insert(i);
    }
    printNode();
    //rotate(30);
    //printNode();
    //rotateBack();
    //printNode();
    cin.get();
    cut(60);
    printNode();
    int oo;
    cin>>oo;
  
}*/