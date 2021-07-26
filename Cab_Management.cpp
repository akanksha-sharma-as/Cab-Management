#include <conio.h>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

struct cab{
  int carno;
  struct cab* next;
};

struct cab* cab(){
  int n,*c;
  struct cab* head=NULL,*ptr=head;
  cout<<"Enter the total number of cabs";
  cin>>n;
  c = &n;
  struct cab*newnode = (struct cab*)malloc(sizeof(struct cab));
  head=newnode;
  cout<<"\nEnter the cab route number";
  cin>>newnode->carno;
  for(int i=1;i<n;i++){
    struct  cab* ptr=(struct cab*)malloc(sizeof(struct cab));
    newnode->next=ptr;
    cout<<"\nEnter the cab route number";
    cin>>ptr->carno;
    newnode=ptr;
  }
  newnode->next=NULL;
  return head;
}

int cab_availability(struct cab *cpt,int carno){
  while(cpt!=NULL){
    if(cpt->carno==carno){
      cout<<"\nCar Is Available\n";
      return 1;
    }
    else
      cpt=cpt->next;
    }
    cout<<"\n Car Not Available\n";
    return 0;
}

struct cab* cab_allocation(struct cab *ptr,int carno){
  struct cab *cpt=ptr,*head=ptr;
  int count=0;
  while(ptr!=NULL && ptr->carno!=carno){
    cpt=ptr;
    ptr=ptr->next;
    count++;
  }
  if(count==0){
    cout<<"cab "<<cpt->carno<<" booked";
    ptr=ptr->next;
    head=ptr;
  }
  else{
    cpt->next=ptr->next;
    cout<<"cab "<<ptr->carno<<" booked";
    free (ptr);
  }
  return head;
}

void available_cabs(struct cab *ptr){
  while(ptr!=NULL){
    cout<<"carno="<<ptr->carno<<"\n";
    ptr=ptr->next;
  }
}

void realloc(struct cab* head ){
  struct cab* ptr=head;
  int carno;
  while(ptr->next!=NULL)
    ptr=ptr->next;
  struct cab* cpt=(struct cab*)malloc(sizeof(struct cab));
  ptr->next=cpt;
  cout<<"enter the carno";
  cin>>cpt->carno;
  cpt->next=NULL;
}

void employee_password_check(){
  static int count;
  char password[7];
  cout<<"Enter the six digit password :- ";
  for(int i=0;i<6;i++){
    char ch=getch();
    cout<<"*";
    password[i]=ch;
  }
  password[6]='\0';
  if(strcmp(password,"aks@12")==0){
    cout<<"\n\tAccess Granted :) \n";
  }
  else{
    count++;
    if(count<3){
      cout<<"\nTry Again !!\n";
      employee_password_check();
    }
    else{
      cout<<"Access Not Granted\n";
      exit (0);
    }
  }
}

int fare(int ch,int type){
  if(ch==1 && type==1){
    cout<<"fare =100";
    return 100;
  }
  else if(ch==2 && type==2){
    cout<<"fare=40";
    return 40;
  }
  else if(ch==2 && type==1){
    cout<<"fare=100";
    return 100;
  }
  else if(ch==2 && type==2){
    cout<<"fare=40";
    return 40;
  }
  else if(ch==3 && type==1){
    cout<<"fare=80";
    return 80;
  }
  else if(ch==3 && type==2){
    cout<<"fare=30";
    return 30;
  }
  else if(ch==4 && type==1){
    cout<<"fare=80";
    return 80;
  }
  else if(ch==4 && type==2){
    cout<<"fare=30";
    return 30;
  }
  else if(ch==5 && type==1){
    cout<<"fare=90";
    return 90;
  }
  else if(ch==5 && type==2){
    cout<<"fare=50";
    return 50;
  }
  else if(ch==6 && type==1){
    cout<<"fare=90";
    return 90;
  }
  else if(ch==6 && type==2){
    cout<<"fare=50";
    return 50;
  }
  else
    return 0;
}

int farediscount(int fare){
  if(fare>50){
    fare-=20;
    cout<<fare;
  }
  else{
    fare-=10;
    cout<<fare;
  }
  return fare;
}

void recipt(int fare,int carno,int type){
  if(carno==1 && type==1){
    cout<<"Driver Name:- Ramesh Prasad\n";
    cout<<"Phone number:- 9516234510\n";
    cout<<"fare="<<fare<<endl;
    cout<<"carno="<<carno<<endl;
    cout<<"type="<<type<<endl;
  }
  else if(carno==1 && type==2){
    cout<<"Driver Name:- Ramesh Kumar\n";
    cout<<"Phone number:- 9513524710\n";
    cout<<"fare="<<fare<<endl;
    cout<<"carno="<<carno<<endl;
    cout<<"type="<<type<<endl;
  }
  else if(carno==2 && type==1){
    cout<<"Driver Name:- Umesh Kumar\n";
    cout<<"Phone number:- 9532454510\n";
    cout<<"fare="<<fare<<endl;
    cout<<"carno="<<carno<<endl;
    cout<<"type="<<type<<endl;
  }
  else if(carno==2 && type==2){
    cout<<"Driver Name:- Arnab\n";
    cout<<"Phone number:- 9516233456\n";
    cout<<"fare="<<fare<<endl;
    cout<<"carno="<<carno<<endl;
    cout<<"type="<<type<<endl;
  }
  else if(carno==3 && type==1){
    cout<<"Driver Name:- Toofan Singh\n";
    cout<<"Phone number:- 9516245345\n";
    cout<<"fare="<<fare<<endl;
    cout<<"carno="<<carno<<endl;
    cout<<"type="<<type<<endl;
  }
  else if(carno==3 && type==2){
    cout<<"Driver Name:- Zakir\n";
    cout<<"Phone number:- 9516324526\n";
    cout<<"fare="<<fare<<endl;
    cout<<"carno="<<carno<<endl;
    cout<<"type="<<type<<endl;
  }
  else if(carno==4 && type==1){
    cout<<"Driver Name:- Rahul \n";
    cout<<"Phone number:- 9516534510\n";
    cout<<"fare="<<fare<<endl;
    cout<<"carno="<<carno<<endl;
    cout<<"type="<<type<<endl;
  }
  else if(carno==4 && type==2){
    cout<<"Driver Name:- Ritik \n";
    cout<<"Phone number:- 9213434510\n";
    cout<<"fare="<<fare<<endl;
    cout<<"carno="<<carno<<endl;
    cout<<"type="<<type<<endl;
  }
  else if(carno==5 && type==1){
    cout<<"Driver Name:- Harry\n";
    cout<<"Phone number:- 9234233456\n";
    cout<<"fare="<<fare<<endl;
    cout<<"carno="<<carno<<endl;
    cout<<"type="<<type<<endl;
  }
  else if(carno==5 && type==2){
    cout<<"Driver Name:- Himanshu\n";
    cout<<"Phone number:- 9516574610\n";
    cout<<"fare="<<fare<<endl;
    cout<<"carno="<<carno<<endl;
    cout<<"type="<<type<<endl;
  }
 else  if(carno==6 && type==1){
    cout<<"Driver Name:- Priyansh\n";
    cout<<"Phone number:- 9516234560\n";
    cout<<"fare="<<fare<<endl;
    cout<<"carno="<<carno<<endl;
    cout<<"type="<<type<<endl;
  }
  else if(carno==6 && type==2){
    cout<<"Driver Name:- Anant\n";
    cout<<"Phone number:- 9516564506\n";
    cout<<"fare="<<fare<<endl;
    cout<<"carno="<<carno<<endl;
    cout<<"type="<<type<<endl;
  }
}


int main(){
  int price, choice, id_no, ch, a, type;
  char fname[20], lname[20], c;
  struct cab* cpt=NULL, *head=NULL, *ptr=NULL;
  cout<<"\t***************************************************\n";
  cout<<"\t**           Welcome To The Cab Services         **\n";
  cout<<"\t***************************************************\n";
  cout<<"Enter your id number\t: ";
  cin>>id_no;
  employee_password_check();
  cout<<"To login to initalization phase please press 1 and to avoid press 0\t: ";
  cin>>choice;
  while(choice==1){
    // clrscr();
    cout<<"\t\t:- Welcome to the cab services -:\n";
    cout<<"Enter your first name\t: ";
    cin>>fname;
    cout<<"Enter your last name\t: ";
    cin>>lname;
    cout<<"We are here to provide you cab servies for Bhopal......\n";
    cout<<"Cabs for areas that we provide-\n";
    cout<<"1. M.P.Nagar to Indrapuri\n";
    cout<<"2. Indrapuri to M.P.Nagar\n";
    cout<<"3. M.P.Nagar to Main Station\n";
    cout<<"4. Main Station to M.P.Nagar\n";
    cout<<"5. Indrapuri to Main Station\n";
    cout<<"6. Main Station to Indrapuri\n";
    cpt=cab();
    cout<<"Enter the type A.C.(1)/Non-A.C.(2)\n";
    cin>>type;
    cout<<"Please Wait... While we search for the availbility of cab on this route.. :)\n";
    int avail=cab_availability(cpt, c);
    if(avail==1){
      int cost=fare(ch,type);
      cout<<"\nPlease confirm the booking by pressing 1\t: ";
	    cin>>a;
	    if(a==1){
	      head= cab_allocation(cpt,ch);
        cout<<"\nDo you have any discount coupon?(Press 1 if Yes else 0)\t: ";
        cin>>choice;
        if(choice==1)
          price= farediscount(cost);
        cout<<"Recipt:-\n";
        recipt(price,ch,type);
        ofstream obj;
        obj.open("data.txt");
        obj<<"Name = "<< fname<<" "<<lname<<" " <<", Car number = "<< ch<<", Type = ";
        if(type == 1)
          obj<<" A.C.";
        else
          obj<<" NON-A.C.";
        obj.close();
        }
      }
    // clrscr();
    cout<<"The cabs available are\n";
    available_cabs(head);
    // clrscr();
    cout<<"Welcome to the login phase";
    cout<<"\nTo continue as customer please press 1 and to avoid press 0\n";
    cin>>choice;
    if(choice==0){
      // clrscr();
      cout<<"\nTo continue as employee press 1";
      cin>>ch;
      if(ch==1){
        cout<<"\n Enter Password:-";
        employee_password_check();
        do{
          cout<<"Want to check the data file :- press1 to check....";
          cin>>ch;
          if(ch==1) {
            ifstream obj;
            obj.open("F:\\Projects\\cm");
            while(obj.eof()==0){
              obj.get(c);
              cout<<c;
              }
            obj.close();
            }
          cout<<"\nTo start the reallocation phase press 1 or press 0";
          cin>>ch;
          if(ch==1){
            realloc(head);
            available_cabs(head);
            }
         }while(ch==1);
        }
      }
    }
   return 0;
  }
