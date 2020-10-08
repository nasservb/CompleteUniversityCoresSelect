// 3432.cpp : Programer :NasserNiazyMobasser  20/9/1387
// copyright:GhayeshSoft all right Reserved
// www.nasservb.blogfa.com
// www.tcvb.tk
#include "string.h"

#include "iostream.h"

#include "conio.h"

class course { // this is cores class [course == cores]
  public:
    int code;
  char name[10];
  int vahed;
  float nomreh;
  char ostad[10];
  course * next;
}; //--------course
class student {
  public:
    //---------struct--------
    char name[10];
  char family[10];
  char level[10];
  int id;
  int term;
  float moadel;
  int tvahed;
  course * firstCourse;
  course * tempCourse;
  course * Course;
  student * next;
  //-------function---------------
  void add();
  void addlevel();
  void printall();
  void del();
  void delCourse();
  void getbyid();
  void printsort();
  //-------------------
  student::student() //constractor
  {
    tvahed = 0;
    id = 0;
    term = 0;
    moadel = 0;
    Course = NULL;
    firstCourse = NULL;
    tempCourse = NULL;
  } //constractor
}* curent = NULL, * first = NULL, * temp = NULL;
//-----------------
class Courselist {
  public:
    course * temp;
  course * curent;
  course * first;
  //----------function list------
  void printall();
  void add();
  void del();
  void mdify();
}
courselist;
//-----------General Function---------------
void fixall(int id) {
  int a1, a2;
  if (first == NULL) return; //if list is empty
  curent = first;
  courselist.curent = courselist.first;
  while (courselist.curent != NULL) {
    if (courselist.curent -> code == id) break;
    courselist.curent = courselist.curent -> next;
  } //while
  while (curent != NULL) {
    if (curent -> firstCourse == NULL) {
      curent = curent -> next;
      continue;
    } else {
      curent -> Course = curent -> firstCourse;
      while (curent -> Course != NULL) {
        if (curent -> Course -> code == id) {
          strcpy(curent -> Course -> name, courselist.curent -> name);
          strcpy(curent -> Course -> ostad, courselist.curent -> ostad);
          break;
        } //if
        curent -> Course = curent -> Course -> next;
      } //while
    } //if
    curent = curent -> next;
  } //while
  cout << "Fixed all" << endl;
} //fixall
//-----------------
void setAll(int id) {
  int a1, a2;
  if (first == NULL) return; //if list is empty
  curent = first;
  while (curent != NULL) {
    if (curent -> firstCourse == NULL) {
      curent = curent -> next;
      continue;
    } else {
      curent -> Course = curent -> tempCourse = curent -> firstCourse;
      if (curent -> Course -> code == id) {
        curent -> firstCourse = curent -> Course -> next;
        curent -> tvahed -= curent -> Course -> vahed;
        a1 = curent -> moadel * curent -> tvahed;
        a2 = curent -> Course -> nomreh * curent -> Course -> vahed;
        a1 -= a2;
        if ((curent -> tvahed - curent -> Course -> vahed) != 0 && curent -> Course -> next != NULL) {
          a1 /= curent -> tvahed - curent -> Course -> vahed;
        } else {
          a1 = 0;
        } //if
        curent -> moadel = a1;
        delete(curent -> Course);
        curent -> Course = curent -> firstCourse;
        curent = curent -> next;
        continue;
      } //if
      curent -> Course = curent -> Course -> next;
      while (curent -> Course != NULL) {
        if (curent -> Course -> code == id) {
          curent -> tempCourse -> next = curent -> Course -> next;
          curent -> tvahed -= curent -> Course -> vahed;
          a1 = curent -> moadel * curent -> tvahed;
          a2 = curent -> Course -> nomreh * curent -> Course -> vahed;
          a1 -= a2;
          //if((curent->tvahed-curent->Course->vahed)!=0 && curent->Course->next!=NULL)
          a1 /= curent -> tvahed - curent -> Course -> vahed;
          curent -> moadel = a1;
          delete(curent -> Course);
          curent -> Course = curent -> tempCourse;
          break;
        } //if
        curent -> tempCourse = curent -> Course;
        curent -> Course = curent -> Course -> next;
      } //while
    } //if
    curent = curent -> next;
  } //while
  cout << "Seted all" << endl;
} //setAll
//---------------------------------
int checkid(int id) {
  if (first == NULL) return 0; //if list is empty
  student * stulist;
  stulist = first;
  while (stulist != NULL) {
    if (stulist -> id == id) return 1;
    stulist = stulist -> next;
  } //while
  return 0;
} //checkid
//---------------------------------
int checkCourse(int id) {
  if (courselist.first == NULL) return 0; //if list is empty
  course * dds;
  dds = courselist.first;
  while (dds != NULL) {
    if (dds -> code == id) return 1;
    dds = dds -> next;
  } //while
  return 0;
} //checkCourse
//---------dras list function------
void Courselist::add() {
  char h;
  int s;
  while (h != 'q') {
    if (courselist.first == NULL) { //avalin
      courselist.temp = new course;
      courselist.curent = courselist.temp;
      courselist.first = courselist.curent;
      cout << "code:" << endl;
      cin >> courselist.curent -> code;
      cout << "name:" << endl;
      cin >> courselist.curent -> name;
      cout << "vahed:" << endl;
      cin >> courselist.curent -> vahed;
      cout << "ostad:" << endl;
      cin >> courselist.curent -> ostad;
      courselist.curent -> next = NULL;
      courselist.temp = NULL;
    } else { //--------------------list por
      courselist.temp = new course;
      courselist.curent = courselist.first;
      while (courselist.curent -> next != NULL) courselist.curent = courselist.curent -> next;
      courselist.curent -> next = courselist.temp;
      courselist.curent = courselist.temp;
      courselist.curent -> next = NULL;
      cout << "code:" << endl;
      cin >> s;
      while (checkCourse(s) == 1) {
        cout << "the course id is exist ,Plase type other id:";
        cin >> s;
      } //while
      courselist.curent -> code = s;
      cout << "name:" << endl;
      cin >> courselist.curent -> name;
      cout << "vahed:" << endl;
      cin >> courselist.curent -> vahed;
      cout << "ostad:" << endl;
      cin >> courselist.curent -> ostad;
      courselist.temp = NULL;
    } //if
    cout << "to quit press 'q' other to add new" << endl;
    cin >> h;
  } //while
} //add
//--------------------------------
void Courselist::del() {
  int id;
  if (courselist.first == NULL) {
    cout << "the list of course is empty!" << endl;
    return;
  } else { // list not empty
    courselist.printall();
    cout << "Plase insert id course to delete:";
    cin >> id;
    courselist.curent = courselist.temp = courselist.first;
    if (courselist.curent -> code == id) { //first item
      //if(courselist.curent->next!=NULL)
      courselist.temp = courselist.curent -> next;
      delete(courselist.curent);
      cout << "item Deleted!" << endl;
      courselist.first = courselist.curent = courselist.temp;
      setAll(id);
      return;
    } //if
    courselist.curent = courselist.temp = courselist.first;
    courselist.curent = courselist.curent -> next;
    while (courselist.curent != NULL) {
      if (courselist.curent -> code == id) {
        courselist.temp -> next = courselist.curent -> next;
        delete(courselist.curent);
        courselist.curent = courselist.temp -> next;
        cout << "item Deleted!" << endl;
        setAll(id);
        return;
      } //if
      courselist.curent = courselist.curent -> next;
      courselist.temp = courselist.temp -> next;
    } //while
    if (courselist.curent == NULL) {
      cout << "not found in list" << endl;
    } //if
  } //if
} //dal course
//---------------------------------
void Courselist::mdify() {
  int id;
  if (courselist.first == NULL) {
    cout << "the list is empty" << endl;
    return;
  } else {
    courselist.printall();
    cout << "plase insert code for modify:";
    cin >> id;
    courselist.curent = courselist.first;
    while (courselist.curent != NULL) {
      if (courselist.curent -> code == id) {
        cout << "-----------------------------" << endl;
        cout << "id:" << courselist.curent -> code << "name:" << courselist.curent -> name << "-ostad:" << courselist.curent -> ostad << "-vahed:" << courselist.curent -> vahed << endl;
        cout << "plase insert new value for modify this vahed" << endl;
        cout << "name[" << courselist.curent -> name << "]:";
        cin >> courselist.curent -> name;
        cout << "ostad[" << courselist.curent -> ostad << "]:";
        cin >> courselist.curent -> ostad;
        fixall(id);
        break;
      } //if
      courselist.curent = courselist.curent -> next;
    } //while
  } //if
} //modify
//--------------------------------
void Courselist::printall() {
  if (courselist.first == NULL) {
    cout << "the list is empty" << endl;
  } else {
    courselist.curent = courselist.first;
    cout << "______________________________________________________" << endl <<
      "|code	|Name	|ostad		|vahed	" << endl;
    while (courselist.curent != NULL) {
      cout << "|" << courselist.curent -> code << char(9) << "|" << courselist.curent -> name << char(9) << "|" <<
        courselist.curent -> ostad << char(9) << char(9) << "|" << courselist.curent -> vahed << endl;
      courselist.curent = courselist.curent -> next;
    } //while
  } //if
} //printall
//---------student function--------
void student::printsort() {
  char arr[20][100];
  int r = 0, s = 0, ts = 0, i, j;
  char tt[100];
  int dd[20];
  if (first == NULL) {
    cout << "student not founded! " << endl;
    return;
  } //if
  cout << "plase select sort model 1 to by name 2 to by id 3 to unsort:";
  cin >> r;
  curent = first;
  while (curent != NULL) {
    strcpy(arr[s], curent -> name);
    //arr[s][20]=char(curent->id);
    dd[s] = curent -> id;
    s++;
    curent = curent -> next;
  } //while
  if (r == 1) { //sort by name
    for (i = s; i >= 0; i--)
      for (j = 0; j < i; j++) {
        if (strcmp(arr[j], arr[j + 1]) > 0) {
          strcpy(tt, arr[j + 1]);
          strcpy(arr[j + 1], arr[j]);
          strcpy(arr[j], tt);
        } //if
      }; //forj
    cout << "_________________________________________________" << endl;
    cout << "Name	|Family		|id	|Term	|reshteh" << endl;
    for (i = 0; i <= s; i++) {
      curent = first;
      while (curent != NULL) {
        if (strcmp(arr[i], curent -> name) == 0) {
          cout << curent -> name << char(9) << "|" << curent -> family << char(9) << char(9) << "|" << curent -> id <<
            char(9) << "|" << curent -> term << char(9) << "|" << curent -> level << endl;
        } //if
        curent = curent -> next;
      } //while
    } //for
  } else if (r == 2) { //sort by id
    for (i = s; i >= 0; i--)
      for (j = 0; j < i; j++) {
        if (dd[j] > dd[j + 1]) {
          ts = dd[j + 1];
          dd[j + 1] = dd[j];
          dd[j] = ts;
        } //if
      } //forj
    cout << "______________________________________________" << endl;
    cout << "id	|Name	|Family		|Term	|reshteh" << endl;
    for (i = 0; i <= s; i++) {
      curent = first;
      while (curent != NULL) {
        if (dd[i] == curent -> id)
          cout << curent -> id << char(9) << "|" << curent -> name << char(9) << "|" << curent -> family <<
          char(9) << char(9) << "|" << curent -> term << char(9) << "|" << curent -> level << endl;
        curent = curent -> next;
      } //while
    } //for
  } else {
    printall();
  } //if
} //printsort
//---------------------------------
void student::add() {
  char g;
  while (g != 'q') {
    if (first == NULL) { //  avalin
      temp = new student;
      cout << "Plase insert the info[name-family-id-level-term]" << endl;
      cin >> temp -> name;
      cout << "famil:";
      cin >> temp -> family;
      cout << "id:";
      cin >> temp -> id;
      while (checkid(temp -> id) == 1) {
        cout << "this id is exist! plase retype id:";
        cin >> temp -> id;
      } //while
      cout << "level[reshteh]:";
      cin >> temp -> level;
      cout << "term:";
      cin >> temp -> term;
      first = temp;
      curent = temp;
      curent -> next = NULL;
      temp = NULL;
    } else { //-------------list por-------
      temp = new student;
      cout << "Plase insert the info[name-family-id-level-term]" << endl;
      cin >> temp -> name;
      cout << "famil:";
      cin >> temp -> family;
      cout << "id:";
      cin >> temp -> id;
      while (checkid(temp -> id) == 1) {
        cout << "this id is exist! plase retype id:";
        cin >> temp -> id;
      } //while
      cout << "level[reshteh]:";
      cin >> temp -> level;
      cout << "term:";
      cin >> temp -> term;
      curent = first;
      while (curent -> next != NULL) curent = curent -> next;
      curent -> next = temp;
      curent = temp;
      curent -> next = NULL;
      temp = NULL;
    } //if
    cout << "to quit press q other to add new and set name" << endl;
    cin >> g;
  } //while
} //add
//-----------------------
void student::printall() {
  if (first == NULL) {
    cout << "the list is empty" << endl;
  } else {
    curent = first;
    cout << "______________________________________________________________________" << endl <<
      "|code	|Name		|family		|level	|term 	|reserved |moadel" << endl;
    while (curent != NULL) {
      cout << "|" << curent -> id << char(9) << "|" << curent -> name << char(9) << char(9) << "|" << curent -> family << char(9) << char(9) <<
        "|" << curent -> level << char(9) << "|" << curent -> term << char(9) << "|" << curent -> tvahed << char(9) << "|" << curent -> moadel << endl;
      curent = curent -> next;
    } //while
  } //if
} //printall
//--------------------
void student::getbyid() {
  int id;
  if (first == NULL) {
    cout << "the list is empty" << endl;
    return;
  } else {
    printall();
    cout << "plase insert id for search:";
    cin >> id;
    curent = first;
    while (curent != NULL) {
      if (curent -> id == id) {
        cout << "-----------------------------" << endl;
        cout << "id:" << curent -> id << "name:" << curent -> name << "-Family:" << curent -> family << "-level:" << curent -> level << "-term:" << curent -> term << "-reserved vahed:" << curent -> tvahed << "moadel:" << curent -> moadel << endl;
        if (curent -> firstCourse == NULL) {
          cout << "no value for course seted" << endl;
          return;
        } else {
          curent -> Course = curent -> firstCourse;
          cout << "______________________________________________________" << endl <<
            "|code	|Name		|ostad		|vahed	|Nomreh" << endl;
          while (curent -> Course != NULL) {
            cout << "|" << curent -> Course -> code << char(9) << "|" << curent -> Course -> name << char(9) << char(9) <<
              "|" << curent -> Course -> ostad << char(9) << char(9) << "|" << curent -> Course -> vahed << char(9) << "|" << curent -> Course -> nomreh << endl;
            curent -> Course = curent -> Course -> next;
          } //while
          break;
        } //if
      } //if
      curent = curent -> next;
    } //while
    if (curent == NULL) {
      cout << "not found this id!" << endl;
      return;
    } //if
  } //if
} //getbyid
//---------------------
void student::addlevel() {
  int id;
  int moad, contm;
  char h;
  if (first == NULL || courselist.first == NULL) {
    cout << "The list of student or course is empty" << endl;
    return;
  } else {
    printall();
    cout << "plase insert the id:";
    cin >> id;
    curent = first;
    while (curent != NULL) {
      if (curent -> id == id) {
        cout << "|" << curent -> id << char(9) << "|" << curent -> name << char(9) << char(9) << "|" << curent -> family << char(9) << char(9) <<
          "|" << curent -> level << char(9) << "|" << curent -> term << char(9) << "|" << curent -> tvahed << char(9) << "|" << curent -> moadel << endl;
        curent -> Course = curent -> firstCourse;
        moad = 0;
        contm = 0;
        if (curent -> firstCourse == NULL) break;
        cout << "course List:" << endl <<
          "	|code	|Name		|ostad		|vahed	|nomreh" << endl;
        while (curent -> Course != NULL) {
          cout << char(9) << "|" << curent -> Course -> code << char(9) << "|" << curent -> Course -> name << char(9) << char(9) <<
            "|" << curent -> Course -> ostad << char(9) << char(9) << "|" << curent -> Course -> vahed << char(9) << "|" << curent -> Course -> nomreh << endl;
          moad += (curent -> Course -> nomreh * curent -> Course -> vahed);
          contm += curent -> Course -> vahed;
          curent -> Course = curent -> Course -> next;
        } //while
        curent -> moadel = (moad / contm);
        curent -> tvahed = contm;
        cout << "moadel:" << (moad / contm) << endl;
        break; //go to end of while if founded id
      } //if
      curent = curent -> next;
    } //while
    if (curent == NULL) {
      cout << "not found this in list of student" << endl;
      return;
    } //if
    while (h != 'q') {
      courselist.printall();
      cout << "plase insert the number of id for set vahed:";
      cin >> id;
      if (curent -> firstCourse == NULL) { //avalin
        courselist.curent = courselist.first;
        while (courselist.curent != NULL) {
          if (courselist.curent -> code == id) {
            curent -> tempCourse = new course;
            curent -> Course = curent -> tempCourse;
            curent -> firstCourse = curent -> Course;
            curent -> Course -> code = courselist.curent -> code;
            strcpy(curent -> Course -> name, courselist.curent -> name);
            curent -> Course -> vahed = courselist.curent -> vahed;
            strcpy(curent -> Course -> ostad, courselist.curent -> ostad);
            curent -> Course -> next = NULL;
            cout << "Plase insert course nomreh:";
            cin >> curent -> Course -> nomreh;
            curent -> tempCourse = NULL;
            curent -> tvahed = courselist.curent -> vahed;
            curent -> moadel = curent -> Course -> nomreh;
            cout << "added  Vahed!" << endl;
            contm = 7;
            break;
          } //if
          courselist.curent = courselist.curent -> next;
        } //while
        if (contm != 7) cout << "vahed not found" << endl;
        curent -> tempCourse = NULL;
      } else { //--------------------list por
        curent -> Course = curent -> firstCourse;
        moad = 0;
        if (curent -> Course -> code == id) moad = 1;
        while (curent -> Course != NULL) {
          curent -> tempCourse = curent -> Course;
          if (curent -> Course -> code == id) {
            cout << "this course is exist,Plase select othe course to add!" << endl;
            moad = 1;
            break;
          } //if
          curent -> Course = curent -> Course -> next;
        } //while
        curent -> Course = curent -> tempCourse;
        if (moad == 1) {
          continue;
        } //if
        courselist.curent = courselist.first;
        while (courselist.curent != NULL) {
          if (courselist.curent -> code == id) {
            curent -> tempCourse = NULL;
            curent -> tempCourse = new course;
            curent -> Course -> next = curent -> tempCourse;
            curent -> Course = curent -> Course -> next;
            curent -> Course -> code = courselist.curent -> code;
            strcpy(curent -> Course -> name, courselist.curent -> name);
            curent -> Course -> vahed = courselist.curent -> vahed;
            strcpy(curent -> Course -> ostad, courselist.curent -> ostad);
            cout << "Plase insert course nomreh1:";
            cin >> curent -> Course -> nomreh;
            moad = curent -> moadel * curent -> tvahed;
            moad += curent -> Course -> nomreh * curent -> Course -> vahed;
            //if ((curent->tvahed+ courselist.curent->vahed) !=0)
            curent -> tvahed += curent -> Course -> vahed;
            curent -> moadel = moad / curent -> tvahed;
            curent -> Course -> next = NULL;
            curent -> tempCourse = NULL;
            cout << "added Vahed!" << endl;
            contm = 7;
            break;
          } //if
          courselist.curent = courselist.curent -> next;
        } //while
        if (contm != 7) cout << "vahed not found" << endl;
        curent -> tempCourse = NULL;
      } //if
      cout << "to quit press 'q' other to add new :";
      cin >> h;
      cout << endl;
    } //while
  } //if
} //addlevel
//---------------------
void student::del() {
  int id, ic, yes;
  char name[16];
  if (first == NULL) {
    cout << "the list is empty" << endl;
  } else {
    printall();
    cout << "insert 1 to search by id other by name to delete:" << endl;
    cin >> ic;
    if (ic == 1) {
      cout << "insert number id for delete:";
      cin >> id;
    } else {
      cout << "insert character to search by name:";
      cin >> name;
    } //if
    curent = temp = first;
    if (curent -> id == id && ic == 1) {
      temp = curent -> next;
      delete(curent);
      cout << "item Deleted!" << endl;
      first = curent = temp;
      return;
    } else if (strcmp(curent -> name, name) == 0 && ic != 1) {
      cout << "do you want to delete " << curent -> name << " " << curent -> family << " id :" << curent -> id << "  to yes pres 1" << endl;
      cin >> yes;
      if (yes == 1) {
        temp = curent -> next;
        delete(curent);
        cout << "item Deleted!" << endl;
        first = curent = temp;
        return;
      } //if
    } //if
    curent = curent -> next;
    while (curent != NULL) {
      if (curent -> id == id && ic == 1) {
        temp -> next = curent -> next;
        delete(curent);
        curent = temp -> next;
        cout << "item Deleted!" << endl;
        return;
      } else if (strcmp(curent -> name, name) == 0 && ic != 1) {
        cout << "do you want to delete " << curent -> name << " " << curent -> family << " id :" << curent -> id << "  to yes pres 1" << endl;
        cin >> yes;
        if (yes == 1) {
          temp -> next = curent -> next;
          delete(curent);
          curent = temp -> next;
          cout << "item Deleted!" << endl;
          return;
        } //if
      } //if
      curent = curent -> next;
      temp = temp -> next;
    } //while
  } //if
} //del
//---------------------
void student::delCourse() {
  int id;
  int cod, cmax;
  if (first == NULL) {
    cout << "the list is empty";
  } else {
    printall();
    cout << "Plase insert id to delete:";
    cin >> id;
    curent = temp = first;
    while (curent != NULL) {
      if (curent -> id == id) {
        if (curent -> firstCourse == NULL) {
          cout << "Vahed Not fund!" << endl;
          return;
        } //if
        curent -> Course = curent -> firstCourse;
        cout << "______________________________________________________" << endl <<
          "|code	|Name		|ostad		|vahed	|nomreh" << endl;
        while (curent -> Course != NULL) {
          cout << "|" << curent -> Course -> code << char(9) << "|" << curent -> Course -> name << char(9) << char(9) <<
            "|" << curent -> Course -> ostad << char(9) << char(9) << "|" << curent -> Course -> vahed << char(9) << "|" << curent -> Course -> nomreh << endl;
          curent -> Course = curent -> Course -> next;
        } //while
        cout << "the item founded!-plase insert code course to delete:";
        cin >> cod;
        curent -> Course = curent -> tempCourse = curent -> firstCourse;
        if (curent -> Course -> code == cod) {
          curent -> firstCourse = curent -> Course -> next;
          curent -> moadel *= curent -> tvahed;
          cmax = curent -> Course -> nomreh * curent -> Course -> vahed;
          curent -> moadel -= cmax;
          if ((curent -> tvahed - curent -> Course -> vahed) != 0)
            curent -> moadel /= curent -> tvahed - curent -> Course -> vahed;
          curent -> tvahed -= curent -> Course -> vahed;
          delete(curent -> Course);
          curent -> Course = curent -> firstCourse;
          cout << "item deleted!" << endl;
          return;
        } //if
        curent -> Course = curent -> Course -> next;
        while (curent -> Course != NULL) {
          if (curent -> Course -> code == cod) {
            curent -> tempCourse -> next = curent -> Course -> next;
            curent -> moadel *= curent -> tvahed;
            cmax = curent -> Course -> nomreh * curent -> Course -> vahed;
            curent -> moadel -= cmax;
            curent -> moadel /= curent -> tvahed - curent -> Course -> vahed;
            curent -> tvahed -= curent -> Course -> vahed;
            delete(curent -> Course);
            curent -> Course = NULL;
            curent -> Course = curent -> tempCourse;
            cout << "item deleted!" << endl;
            return;
          } //if
          curent -> tempCourse = curent -> Course;
          curent -> Course = curent -> Course -> next;
        } //while
      } //if
      curent = curent -> next;
    } //while
  } //if
} //delCourse
//---------------------
void main() {
  student stu;
  int d = 0;
  while (d != 1) {
    cout << "________________________________________" << endl <<
      "|'1' to quit Program                    |" << endl <<
      "|---------------------------------------|" << endl;
    cout << "|Plase Select Function:                 |" << endl <<
      "|'2' to add Student                     |" << endl <<
      "|'3' to print all Student               |" << endl;
    cout <<
      "|'4' to search by id                    |" << endl <<
      "|'5' to add vahed For Student           |" << endl <<
      "|'6' to delet vahed of Student          |" << endl <<
      "|'7' to delet a student                 |" << endl <<
      "|---------------course function-----------|" << endl <<
      "|'8' to add course                        |" << endl;
    cout <<
      "|'9' to delete course                     |" << endl <<
      "|'0' to modify course                     |" << endl <<
      "|'10 to print all course                  |" << endl <<
      "|_______________________________________|" << endl;
    cin >> d;
    clrscr();
    //	cout.clear ();
    switch (d) {
    case 2:
      stu.add();
      break;
    case 3:
      stu.printsort();
      break;
    case 4:
      stu.getbyid();
      break;
    case 5:
      stu.addlevel();
      break;
    case 6:
      stu.delCourse();
      break;
    case 7:
      stu.del();
      break;
    case 8:
      courselist.add();
      break;
    case 9:
      courselist.del();
      break;
    case 0:
      courselist.mdify();
      break;
    case 10:
      courselist.printall();
      break;
    } //case
  } //while
  cout << "GOOD BY!" << endl;
} //main
