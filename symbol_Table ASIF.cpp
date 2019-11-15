#include<iostream>
#include<stdlib.h>
using namespace std;

class Symbol_Info{
public:
    string Symbol_Type;
    string Symbol_Name;
};

struct node{
    Symbol_Info ob;
    struct node *Next;
};

typedef struct node Node;

class LinkedList{
    int s ;
    Node *Head[];
    public:
    LinkedList(int n){
        s=n;
        for(int i=0;i<n;i++){
            Head[i]=NULL;
        }
    }

    void insert_Node(){

        int index;

        Node *temp=new Node;
        temp->Next=NULL;

        cout<<"Token Name: ";
        cin>>temp->ob.Symbol_Name;
        cout<<"Token Type : ";
        cin>>temp->ob.Symbol_Type;

        index=Type_Match(temp->ob.Symbol_Type);

        if(index==-1){
            cout<<"\nInvalid token\n";
            return;
        }

        if( Head[index] == NULL){
            Head[index]=temp;
        }
        else{
            temp->Next=Head[index];
            Head[index]=temp;
        }
    }

    void Print_List(){
        for(int i=0;i<s;i++){
            Node *temp=Head[i];
            while(temp){
                cout<<"<"<<temp->ob.Symbol_Name<<","<<temp->ob.Symbol_Type<<">\n";
                temp=temp->Next;
            }
            cout<<"\n";
        }
    }

    void Delete_List(){

        int index;

        string N,T;

        int flag=0;

        cout<<"Token Name: ";
        cin>>N;
        cout<<"Token Type: ";
        cin>>T;
        index=Type_Match(T);
        Node **H=&(Head[index]);
        if(index==-1){
            cout<<"Invalid Token";
            return;
        }

        if(Head[index]==NULL){
            cout<<"\nList is Empty\n";
            return;
        }

        if((*H)->ob.Symbol_Name==N && (*H)->ob.Symbol_Type==T){
            *H=(*H)->Next;
        }
        else{
            Node *temp1=*H;
            Node *temp2=(*H)->Next;
            while(temp2){
                if(temp2->ob.Symbol_Name==N&&temp2->ob.Symbol_Type==T){
                    flag=1;
                    break;
                }
                temp1=temp1->Next;
                temp2=temp2->Next;
            }
            if(flag==1){
                temp2=temp2->Next;
                temp1->Next=temp2;
                return;
            }
            cout<<"\nToken is not in list\n";
        }

    }

    int Type_Match(string type){
        if(type=="INT"||type=="STRING"||type=="FLOAT"||type=="CHAR"||type=="STRUCT"||type=="LONG")
            return 0;
        if(type=="NUM")
            return 1;
        if(type=="OP"||type=="RELOP"||type=="ARITH"||type=="SMCLN"||type=="COMMA")
            return 2;
        if(type=="COND"||type=="LOOP")
            return 3;
        if(type=="FUNC")
            return 4;
        return -1;
    }

};

int main(){
    int n;
    cout<<"Size of Symbol Table: ";
    cin>>n;
    LinkedList List(n);
    int ch;

    while(1){
        cout<<endl;
        cout<<"1:Insert"<<endl<<"2:Print the symbol table"<<endl<<"3:Delete"<<endl<<"4:Exit from the symbol table "<<endl;
        cout<<"Enter Your Choice:";
        cin>>ch;
        if(ch==1){
            cout<<endl;
            List.insert_Node();
            cout<<endl;
        }
        if(ch==2){
            cout<<endl;
            List.Print_List();
            cout<<endl;
        }

        if(ch==3){
            cout<<endl;
            List.Delete_List();
            cout<<endl;
        }
        if(ch==4){
            exit(0);
        }
   }

    return 0;
}

