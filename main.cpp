
#include<iostream>
#include <string>
#include <vector>
using namespace std;
class Student{
    public:
    string name;
    string student_id;
    Student()
    {
        
    }
    Student(string name, string student_id)
    {
        this->name=name;
        this->student_id=student_id;
    }
    void display(){
        cout<<"Student name is: "<<name<<" and student id is: "<<student_id<<endl;
    }
};
class Participant : public Student{
    public:
    static int ticket_no;
    Participant(string name, string student_id) : Student(name, student_id) {
         ticket_no++;
         cout<<"Student with name : "<<name<<" and student id : "<<student_id<<" has ticket number: "<<ticket_no<<endl;
         
    }
    std::vector<std::string> events_part;
    //events the student would like to participate in
    void add_events(string event_name)
    {
        events_part.push_back(event_name);
        
    }
    void display_events(){
        cout<<"The events "<<this->name<<" is participating in are: "<<endl;
        for(int i=0;i<events_part.size();i++){
            cout<<events_part[i]<<" ";
        }
    }
    
};
int Participant::ticket_no = 0;


class Coordinator : public Student{
    
};


class CoreTeam : public Student{
    public:
    string designation;
    //eg treasurer, public relation, event lead
};


int main() {
    cout<<"Welcome to College Fest Management System"<<endl;
    string student_name, student_id;
    cout<<"Enter student name: ";
    cin>>student_name;
    cout<<"Enter student id: ";
    cin>>student_id;
    Student st(student_name, student_id);
    
    // st.display();
    
    Participant p(student_name, student_id);
    
    p.add_events("Dance");
    p.display_events();
   

    return 0;
}
