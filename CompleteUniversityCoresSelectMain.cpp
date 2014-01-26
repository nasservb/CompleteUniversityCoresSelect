// 3432.cpp : Programer :NasserNiazyMobasser  20/9/1387
// copyright:GhayeshSoft all right Reserved
// www.nasservb.blogfa.com
// www.tcvb.tk
#include "string.h"
#include "iostream.h"
#include "conio.h"
class dars{ // this is cores class [dars == cores] 
public:
	int code;
	char name[10];
	int vahed;
	float nomreh;
	char ostad[10];
	dars *next;
};//--------dars
class student{
public:
//---------struct--------
	char name[10];
	char family[10];
	char level[10];
	int id;
	int term;
	float moadel;
	int tvahed;
	dars *firstdrs;
	dars *tempdrs;
	dars *drs;
	student *next;
	//-------function---------------
	void add();
	void addlevel();
	void printall();
	void del();
	void deldrs();
	void getbyid();
	void printsort();
	//-------------------
	student::student()//constractor
	{
		tvahed=  0;
		id=      0;
		term=    0;
		moadel=  0;
		drs=     NULL;
		firstdrs=NULL;
		tempdrs= NULL;
	} //constractor
}*curent=NULL,*first=NULL,*temp=NULL;
//-----------------
class drslist{
public:
	dars *temp;
	dars *curent;
	dars *first;
	//----------function list------
	void printall();
	void add();
	void del();
	void mdify();
}darslist;
//-----------General Function---------------
void fixall(int id){
int a1,a2;
if(first==NULL)return;//if list is empty
curent=first;
darslist.curent=darslist.first;
while(darslist.curent!=NULL){
	if(darslist.curent->code==id)break;
	darslist.curent=darslist.curent->next;
}//while
	while(curent!=NULL){
			if (curent->firstdrs==NULL){
				curent=curent->next ;
				continue;
			}else{
				curent->drs=curent->firstdrs ;
				while(curent->drs !=NULL){
					if (curent->drs->code==id){
						strcpy(curent->drs->name,darslist.curent->name);
						strcpy(curent->drs->ostad,darslist.curent->ostad);
						break;
					}//if
					curent->drs=curent->drs->next ;
				 }//while
			}//if
			curent=curent->next ;
	}//while
	cout<<"Fixed all"<<endl;
}//fixall
//-----------------
void setall(int id){
int a1,a2;
if(first==NULL)return;//if list is empty
curent=first;
	while(curent!=NULL){
			if (curent->firstdrs==NULL){
				curent=curent->next ;
				continue;
			}else{
				curent->drs=curent->tempdrs=curent->firstdrs ;
				if(curent->drs->code==id){
					 curent->firstdrs=curent->drs->next;
					 curent->tvahed-=curent->drs->vahed;
					 a1=curent->moadel*curent->tvahed;
					 a2=curent->drs->nomreh * curent->drs->vahed;
					 a1-=a2;
					 if((curent->tvahed-curent->drs->vahed)!=0 && curent->drs->next!=NULL){
						a1 /=curent->tvahed - curent->drs->vahed;
					 }else{
					 	a1=0;
					 }//if
					 curent->moadel=a1;
					 delete(curent->drs);
					 curent->drs=curent->firstdrs;
					 curent=curent->next ;
					 continue;
				 }//if
				curent->drs=curent->drs->next;
				while(curent->drs !=NULL){
					if (curent->drs->code==id){
						curent->tempdrs->next=curent->drs->next;
						curent->tvahed-=curent->drs->vahed;
						a1=curent->moadel*curent->tvahed;
						a2=curent->drs->nomreh * curent->drs->vahed;
						a1-=a2;
						//if((curent->tvahed-curent->drs->vahed)!=0 && curent->drs->next!=NULL)
							a1 /=curent->tvahed - curent->drs->vahed;
						curent->moadel=a1;
						 delete(curent->drs);
						 curent->drs=curent->tempdrs;
						 break;
					}//if
					curent->tempdrs=curent->drs;
					curent->drs=curent->drs->next ;
				 }//while
			}//if
			curent=curent->next ;
	}//while
	cout<<"Seted all"<<endl;
	}//setall
//---------------------------------
int checkid(int id){
if (first==NULL)return 0;//if list is empty
student *stulist;
stulist=first;
	while(stulist!=NULL){
		if(stulist->id==id)return 1;
		stulist=stulist->next;
	}//while
	return 0;
}//checkid
//---------------------------------
int checkdrs(int id){
if(darslist.first==NULL) return 0;//if list is empty
dars *dds;
dds=darslist.first;
	while(dds!=NULL){
		if (dds->code==id) return 1;
		dds=dds->next;
	}//while
	return 0;
}//checkdrs
//---------dras list function------
void drslist::add (){
char h;int s;
while(h!='q'){
	if (darslist.first==NULL ){//avalin
		darslist.temp  =new dars;
		darslist.curent =darslist.temp  ;
		darslist.first =darslist.curent  ;
		cout<<"code:"<<endl;
		cin>>darslist.curent->code ;
		cout<<"name:"<<endl;
		cin>>darslist.curent->name;
		cout<<"vahed:"<<endl;
		cin>>darslist.curent->vahed;
		cout<<"ostad:"<<endl;
		cin>>darslist.curent->ostad;
		darslist.curent->next =NULL;
		darslist.temp =NULL ;
	}else{//--------------------list por
		darslist.temp =new dars;
		darslist.curent =darslist.first  ;
		  while(darslist.curent->next !=NULL)darslist.curent =darslist.curent->next ;
		darslist.curent->next  =darslist.temp  ;
		darslist.curent =darslist.temp  ;
		darslist.curent->next =NULL ;
		cout<<"code:"<<endl;
		cin>>s;
		while(checkdrs(s)==1){
				cout<<"the dars id is exist ,Plase type other id:";
				cin>>s;
		}//while
		darslist.curent->code=s;
		cout<<"name:"<<endl;
		cin>>darslist.curent->name;
		cout<<"vahed:"<<endl;
		cin>>darslist.curent->vahed;
		cout<<"ostad:"<<endl;
		cin>>darslist.curent->ostad;
		darslist.temp=NULL ;
	}//if
	cout<<"to quit press 'q' other to add new"<<endl;
	cin>>h;
	}//while
}//add
//--------------------------------
void drslist::del (){
int id ;
if (darslist.first ==NULL){
	cout<<"the list of dars is empty!"<<endl;
	return;
}else{// list not empty
	darslist.printall();
	cout<<"Plase insert id dars to delete:";
	cin>>id;
	darslist.curent=darslist.temp=darslist.first;
	if (darslist.curent->code ==id ){//first item
		//if(darslist.curent->next!=NULL)
		darslist.temp=darslist.curent->next ;
		delete(darslist.curent);
		cout<<"item Deleted!"<<endl;
		darslist.first=darslist.curent=darslist.temp;
		setall(id);
		return;
	}//if
	darslist.curent=darslist.temp=darslist.first;
	darslist.curent=darslist.curent->next ;
	while(darslist.curent!=NULL){
		if (darslist.curent->code  ==id ){
			darslist.temp->next=darslist.curent->next ;
			delete(darslist.curent);
			darslist.curent=darslist.temp->next ;
			cout<<"item Deleted!"<<endl;
			setall(id);
			return;
		}//if
	  darslist.curent=darslist.curent->next ;
	  darslist.temp=darslist.temp->next;
	}//while
	if (darslist.curent==NULL){
		cout<<"not found in list"<<endl ;
	}//if
}//if
}//dal dars
//---------------------------------
void drslist::mdify(){
	int id;
if (darslist.first==NULL){
	cout<<"the list is empty"<<endl;
	return ;
}else{
darslist.printall();
	cout<<"plase insert code for modify:";
	 cin>>id;
	darslist.curent=darslist.first;
	while(darslist.curent!=NULL){
		if (darslist.curent->code ==id){
			cout<<"-----------------------------"<<endl;
			cout<<"id:"<<darslist.curent->code  <<"name:"<<darslist.curent->name <<"-ostad:"<<darslist.curent->ostad <<"-vahed:"<<darslist.curent->vahed  <<endl;
			cout<<"plase insert new value for modify this vahed"<<endl;
		cout<<"name["<<darslist.curent->name <<"]:";
		cin>>darslist.curent->name;
		cout<<"ostad["<<darslist.curent->ostad<<"]:";
		cin>>darslist.curent->ostad;
		fixall(id);
		break;
		}//if
		darslist.curent=darslist.curent->next ;
	}//while
}//if
}//modify
//--------------------------------
void drslist::printall (){
	if (darslist.first==NULL){
		cout<<"the list is empty"<<endl;
	}else
	{	darslist.curent=darslist.first;
		cout<<"______________________________________________________"<<endl
		<<"|code	|Name	|ostad		|vahed	"<<endl;
		while(darslist.curent!=NULL){
		cout<<"|"<<darslist.curent->code<<char(9)<<"|"<<darslist.curent->name <<char(9)<<"|"
					<<darslist.curent->ostad<<char(9)<<char(9)<<"|"<<darslist.curent->vahed<<endl;
		darslist.curent=darslist.curent->next ;
		}//while
	}//if
}//printall
//---------student function--------
void student::printsort() {
char arr[20][100];
int r=0,s=0,ts=0,i,j;
char tt[100];
int dd[20];
if(first==NULL){
	cout<<"student not founded! "<<endl;
	return;
}//if
cout<<"plase select sort model 1 to by name 2 to by id 3 to unsort:" ;
cin>>r;
curent=first;
	while(curent!=NULL){
			strcpy(arr[s],curent->name);
			//arr[s][20]=char(curent->id);
			dd[s]=curent->id;
			s++;
			curent=curent->next;
	}//while
if (r==1){//sort by name
	for(i=s;i>=0;i--)
		for(j=0;j<i;j++){
			if(strcmp(arr[j],arr[j+1])>0){
				strcpy(tt,arr[j+1]);
				strcpy(arr[j+1],arr[j]);
				strcpy(arr[j],tt);
			}//if
		};//forj
	 cout<<"_________________________________________________"<<endl ;
	 cout<<"Name	|Family		|id	|Term	|reshteh"<<endl;
		for(i=0;i<=s;i++){
			curent=first;
			while(curent!=NULL){
				if(strcmp(arr[i],curent->name )==0){
					cout<<curent->name<<char(9)<<"|"<<curent->family<<char(9)<<char(9)<<"|"<<curent->id<<
					char(9)<<"|"<<curent->term<<char(9)<<"|"<<curent->level<<endl;
				}//if
				curent=curent->next ;
			}//while
		}//for
}else if(r==2){//sort by id
	for(i=s;i>=0;i--)
		for(j=0;j<i;j++){
			if(dd[j]>dd[j+1]){
				ts=dd[j+1];
				dd[j+1]=dd[j];
				dd[j]=ts;
			}//if
		}//forj
		cout<<"______________________________________________"<<endl;
		cout<<"id	|Name	|Family		|Term	|reshteh"<<endl;
		for(i=0;i<=s;i++){
			curent=first;
			while(curent!=NULL){
				if(dd[i]==curent->id)
					cout<<curent->id<<char(9)<<"|"<<curent->name<<char(9)<<"|"<<curent->family
					<<char(9)<<char(9)<<"|"<<curent->term<<char(9)<<"|"<<curent->level<<endl;
				curent=curent->next ;
			}//while
		}//for
}else{
	printall();
}//if
}//printsort
//---------------------------------
void student::add (){
char g;
while (g!='q'){
	if (first==NULL){//  avalin
		temp=new student;
		cout<<"Plase insert the info[name-family-id-level-term]"<<endl;
		cin>>temp->name;
		cout<<"famil:";
		cin>>temp->family;
		cout<<"id:";
		cin>>temp->id;
		while (checkid(temp->id)==1){
				cout<<"this id is exist! plase retype id:";
				cin>>temp->id;
		}//while
		cout<<"level[reshteh]:";
		cin>>temp->level;
		cout<<"term:";
		cin>> temp->term ;
		first=temp;
		curent=temp;
		curent->next =NULL;
		temp=NULL;
	}else {//-------------list por-------
		temp=new student;
		cout<<"Plase insert the info[name-family-id-level-term]"<<endl;
		cin>>temp->name;
		cout<<"famil:";
		cin>>temp->family;
		cout<<"id:";
		cin>>temp->id;
		while (checkid(temp->id)==1){
				cout<<"this id is exist! plase retype id:";
				cin>>temp->id;
		}//while
		cout<<"level[reshteh]:";
		cin>>temp->level;
		cout<<"term:";
		cin>> temp->term ;
	  curent=first;
		while(curent->next !=NULL)curent=curent->next ;
		curent->next =temp;
		curent=temp;
		curent->next =NULL;
		temp=NULL;
	}//if
cout<<"to quit press q other to add new and set name"<<endl;
cin>>g;
}//while
}//add
//-----------------------
void student::printall (){
	if (first==NULL){
		cout<<"the list is empty"<<endl;
	}else{
	curent=first;
		cout<<"______________________________________________________________________"<<endl
		<<"|code	|Name		|family		|level	|term 	|reserved |moadel"<<endl;
		while(curent!=NULL){
			cout<<"|"<<curent->id<<char(9)<<"|"<<curent->name<<char(9)<<char(9)<<"|"<<curent->family<<char(9)<<char(9)
			<<"|"<<curent->level<<char(9)<<"|"<<curent->term<<char(9)<<"|"<<curent->tvahed	<<char(9)<<"|"<<curent->moadel <<endl;
			curent=curent->next ;
		}//while
	}//if
}//printall
//--------------------
void student::getbyid (){
int id;
if (first==NULL){
	cout<<"the list is empty"<<endl;
	return ;
}else{
	printall();
	cout<<"plase insert id for search:";
	 cin>>id;
	curent=first;
	while(curent!=NULL){
		if (curent->id==id){
		cout<<"-----------------------------"<<endl;
			cout<<"id:"<<curent->id <<"name:"<<curent->name <<"-Family:"<<curent->family <<"-level:"<<curent->level <<"-term:"<<curent->term <<"-reserved vahed:"<<curent->tvahed<<"moadel:"<<curent->moadel <<endl;
			if (curent->firstdrs==NULL){
				cout<<"no value for dars seted"<<endl; return;
			}else{
				curent->drs=curent->firstdrs ;
				cout<<"______________________________________________________"<<endl
				<<"|code	|Name		|ostad		|vahed	|Nomreh"<<endl;
				while(curent->drs !=NULL){
					cout<<"|"<<curent->drs->code<<char(9)<<"|"<<curent->drs->name <<char(9)<<char(9)<<
					"|"<<curent->drs->ostad<<char(9)<<char(9)<<"|"<<curent->drs->vahed<<char(9)<<"|"<<curent->drs->nomreh<<endl;
					curent->drs=curent->drs->next ;
				}//while
				break;
			}//if
		}//if
		curent=curent->next ;
	}//while
   if(curent==NULL){
		cout<<"not found this id!"<<endl;
		return;
	}//if
}//if
}//getbyid
//---------------------
void student::addlevel (){
int id;int moad,contm;
char h;
if (first==NULL || darslist.first==NULL){
	cout<<"The list of student or dars is empty"<<endl;
	return;
}else{
printall();
cout<<"plase insert the id:";
cin>>id;
	curent=first;
	while(curent!=NULL){
		if(curent->id ==id){
			cout<<"|"<<curent->id<<char(9)<<"|"<<curent->name<<char(9)<<char(9)<<"|"<<curent->family<<char(9)<<char(9)
			<<"|"<<curent->level<<char(9)<<"|"<<curent->term<<char(9)<<"|"<<curent->tvahed<<char(9)<<"|"<<curent->moadel<<endl;
				curent->drs =curent->firstdrs;
				moad=0;contm=0;
				 if (curent->firstdrs==NULL)break;
				 cout<<"Dars List:"<<endl
				<<"	|code	|Name		|ostad		|vahed	|nomreh"<<endl;
				while(curent->drs !=NULL){
					cout<<char(9)<<"|"<<curent->drs->code<<char(9)<<"|"<<curent->drs->name <<char(9)<<char(9)<<
					"|"<<curent->drs->ostad<<char(9)<<char(9)<<"|"<<curent->drs->vahed<<char(9)<<"|"<<curent->drs->nomreh<<endl;
					moad+=(curent->drs->nomreh * curent->drs->vahed);
					contm+=curent->drs->vahed;
					curent->drs=curent->drs->next ;
				}//while
				curent->moadel=(moad/contm);
				curent->tvahed =contm;
				cout<<"moadel:"<< (moad/contm)<<endl;
			break;//go to end of while if founded id
		}//if
	curent=curent->next ;
	}//while
	if (curent==NULL){
		cout<<"not found this in list of student"<<endl;
		return;
	}//if
while(h!='q'){
		darslist.printall();
		cout<<"plase insert the number of id for set vahed:";
		cin>>id;
	if (curent->firstdrs==NULL ){//avalin
			darslist.curent=darslist.first;
			while(darslist.curent!=NULL){
					if(darslist.curent->code ==id ){
						curent->tempdrs =new dars;
						curent->drs=curent->tempdrs ;
						curent->firstdrs =curent->drs ;
						curent->drs->code=darslist.curent->code ;
						strcpy(curent->drs->name,darslist.curent->name);
						curent->drs->vahed=darslist.curent->vahed;
						strcpy(curent->drs->ostad,darslist.curent->ostad);
						curent->drs->next =NULL;
							cout<<"Plase insert dars nomreh:";
							cin>>curent->drs->nomreh;
						curent->tempdrs=NULL ;
						curent->tvahed=darslist.curent->vahed;
						curent->moadel=curent->drs->nomreh;
						cout<<"added  Vahed!"<<endl;
						contm=7;break;
					}//if
				darslist.curent=darslist.curent->next;
			}//while
			if(contm!=7)cout<<"vahed not found"<<endl;
				curent->tempdrs=NULL ;
	}else{//--------------------list por
			curent->drs=curent->firstdrs ;
			moad=0;
			if (curent->drs->code==id)moad=1;
		while(curent->drs!=NULL){
			curent->tempdrs=curent->drs;
			if (curent->drs->code==id){
				cout<<"this dars is exist,Plase select othe dars to add!"<<endl;
				moad=1;break;
			}//if
			curent->drs=curent->drs->next;
		}//while
		curent->drs=curent->tempdrs;
		if (moad==1){
		continue;
		}//if
		darslist.curent=darslist.first;
	while(darslist.curent!=NULL){
			if(darslist.curent->code ==id ){
					curent->tempdrs=NULL;
					curent->tempdrs =new dars;
					curent->drs->next=curent->tempdrs ;
					curent->drs=curent->drs->next;
					curent->drs->code=darslist.curent->code ;
					strcpy(curent->drs->name,darslist.curent->name );
					curent->drs->vahed=darslist.curent->vahed;
					strcpy(curent->drs->ostad,darslist.curent->ostad);
						cout<<"Plase insert dars nomreh1:";
						cin>>curent->drs->nomreh;
					moad=curent->moadel * curent->tvahed ;
					moad+=curent->drs->nomreh * curent->drs->vahed ;
					//if ((curent->tvahed+ darslist.curent->vahed) !=0)
					curent->tvahed +=curent->drs->vahed ;
					curent->moadel =moad/curent->tvahed ;
					curent->drs->next=NULL;
					curent->tempdrs=NULL;
					cout<<"added Vahed!"<<endl;
					contm=7;break;
			}//if
		darslist.curent=darslist.curent->next;
	}//while
		if(contm!=7)cout<<"vahed not found"<<endl;
		curent->tempdrs=NULL ;
	}//if
	cout<<"to quit press 'q' other to add new :";
	cin>>h;
	cout<<endl;
}//while
}//if
}//addlevel
//---------------------
void student::del(){
int id , ic,yes ;char name[16];
if (first==NULL){
	cout<<"the list is empty"<<endl;
}else{
printall();
	cout<<"insert 1 to search by id other by name to delete:"<<endl;
	cin>>ic;
	if (ic ==1){
		cout <<"insert number id for delete:";
		cin>>id;
	}else{
		cout <<"insert character to search by name:";
		cin>> name;
	}//if
	curent=temp=first;
	if (curent->id ==id && ic ==1){
		temp=curent->next ;
		  delete(curent);
		  cout<<"item Deleted!"<<endl;
		first=curent=temp;
		return;
	}else if (strcmp(curent->name , name)==0 && ic != 1){
		cout<< "do you want to delete "<<curent->name <<" "<<curent->family <<" id :"<<curent->id <<"  to yes pres 1"<<endl;
		cin >>yes;
		if (yes==1){
			temp=curent->next ;
			delete(curent);
			cout<<"item Deleted!"<<endl;
			first=curent=temp;
			return;
		}//if
	}//if
	curent=curent->next ;
	while(curent!=NULL){
		if (curent->id ==id && ic==1){
			temp->next=curent->next ;
			delete(curent);
			curent=temp->next ;
			cout<<"item Deleted!"<<endl;
			return;
		}else if(strcmp(curent->name , name)==0 && ic != 1){
			cout<< "do you want to delete "<<curent->name <<" "<<curent->family <<" id :"<<curent->id <<"  to yes pres 1"<<endl;
			cin >>yes;
			if (yes==1){
				temp->next=curent->next ;
				delete(curent);
				curent=temp->next ;
				cout<<"item Deleted!"<<endl;
				return;
			}//if
		}//if
		curent=curent->next ;
		temp=temp->next;
	}//while
}//if
}//del
//---------------------
void student::deldrs(){
int id ;int cod,cmax;
if (first==NULL){
	cout<<"the list is empty";
}else{
   printall();
	cout<<"Plase insert id to delete:";
    cin>>id;
	curent=temp=first;
	while(curent!=NULL){
        if (curent->id ==id){
          if(curent->firstdrs==NULL){
             cout<<"Vahed Not fund!"<<endl;
             return;
          }//if
			curent->drs=curent->firstdrs;
         cout<<"______________________________________________________"<<endl
				<<"|code	|Name		|ostad		|vahed	|nomreh"<<endl;
				while(curent->drs !=NULL){
					cout<<"|"<<curent->drs->code<<char(9)<<"|"<<curent->drs->name <<char(9)<<char(9)<<
					"|"<<curent->drs->ostad<<char(9)<<char(9)<<"|"<<curent->drs->vahed<<char(9)<<"|"<<curent->drs->nomreh <<endl;
					curent->drs=curent->drs->next ;
			}//while
			cout<<"the item founded!-plase insert code dars to delete:";
				cin>>cod;
			curent->drs=curent->tempdrs=curent->firstdrs ;
			if (curent->drs->code ==cod){
				curent->firstdrs=curent->drs->next;
				curent->moadel *=  curent->tvahed ;
				cmax=curent->drs->nomreh * curent->drs->vahed  ;
				curent->moadel -= cmax;
				if ((curent->tvahed-curent->drs->vahed )!=0)
					curent->moadel /= curent->tvahed-curent->drs->vahed ;
				curent->tvahed -=curent->drs->vahed;
				delete(curent->drs);
				curent->drs=curent->firstdrs;
				cout<<"item deleted!"<<endl;
				return;
			}//if
         curent->drs=curent->drs->next;
			while(curent->drs !=NULL){
				if (curent->drs->code  ==cod){
					curent->tempdrs->next=curent->drs->next ;
					curent->moadel *=  curent->tvahed ;
					cmax=curent->drs->nomreh * curent->drs->vahed  ;
					curent->moadel -= cmax;
					curent->moadel /= curent->tvahed-curent->drs->vahed ;
					curent->tvahed-=curent->drs->vahed;
					delete(curent->drs);
					curent->drs=NULL;
					curent->drs =curent->tempdrs;
					cout<<"item deleted!"<<endl;
               return ;
				}//if
				curent->tempdrs =curent->drs ;
				curent->drs =curent->drs->next ;
			}//while
		}//if
    curent=curent->next ;
	}//while
}//if
}//deldrs
//---------------------
void main(){
	student stu ;
	int d=0;
	while(d!=1){
 cout<<"________________________________________"<<endl<<
		"|'1' to quit Program                    |"<<endl<<
		"|---------------------------------------|"<<endl;
  cout<<"|Plase Select Function:                 |"<<endl<<
		 "|'2' to add Student                     |"<<endl<<
		 "|'3' to print all Student               |"<<endl;cout<<
		 "|'4' to search by id                    |"<<endl<<
		 "|'5' to add vahed For Student           |"<<endl<<
		 "|'6' to delet vahed of Student          |"<<endl<<
		 "|'7' to delet a student                 |"<<endl<<
		 "|---------------Dars function-----------|"<<endl<<
		 "|'8' to add dars                        |"<<endl;cout<<
		 "|'9' to delete dars                     |"<<endl<<
		 "|'0' to modify dars                     |"<<endl<<
		 "|'10 to print all dars                  |"<<endl<<
		 "|_______________________________________|"<<endl;
		cin>>d;
		clrscr();
	//	cout.clear ();
		switch (d){
			case 2:stu.add();				break;
			case 3:stu.printsort() ;	break;
			case 4:stu.getbyid() ;		break;
			case 5:stu.addlevel();		break;
			case 6:stu.deldrs ();		break;
			case 7:stu.del();				break;
			case 8:darslist.add ();		break;
			case 9:darslist.del ();		break;
			case 0:darslist.mdify ();	break;
			case 10:darslist.printall ();break;
		}//case
	}//while
	cout<<"GOOD BY!"<<endl;
}//main

