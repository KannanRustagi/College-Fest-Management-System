#include<iostream>
#include <string>
#include <vector>
#include <map>
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

class CoreTeam : public Student{
    public:

    //the division of the fest of which the core team member is a part
    string division;
    //the designation the core team member holds in their event eg treasurer, public relation, event lead
    string designation;
    CoreTeam(Student &s,  string division, string designation){
        this->division=division;
        this->designation=designation;
    }
    CoreTeam(){}

    void display(){
        cout<<"Role is Core Team member, part of "<<this->division<<" as a  "<<this->designation<<endl;
        
    }
    //the list of coordinators which work under a particular core team member
    // vector <Coordinator> coordinator_list;

    // void add_coordinator_names(Coordinator &co)
    // {
    //     coordinator_list.push_back(co);
    // }

    // map <Coordinator, string> task_assigning;
    
    
};

class Coordinator : public CoreTeam{
    public:
    string division;
    string CoreTeamHead;

    Coordinator(string CoreTeamHead, string division)
    {
        this->CoreTeamHead=CoreTeamHead;
        this->division= division;
    }

    void display()
    {
        cout<<"Coordinator "<<this->name<<" is working under "<<this->CoreTeamHead<<" in the division "<<this->division<<endl;
    }

};


int main() {

    cout<<"Welcome to College Fest Management System"<<endl;
    int exit=1;
    while(exit)
    {
    string student_name, student_id;
    cout<<"Enter student name: ";
    cin>>student_name;
    cout<<"Enter student id: ";
    cin>>student_id;
    Student st(student_name, student_id);
    
    // st.display();

    cout<<"Select one of the following options:"<<endl;
    int choice;
    cout<<"Choose 1 if you are a participant"<<endl;
    cout<<"Choose 2 if you are a core team member"<<endl;
    cout<<"Choose 3 if you are a coordinator"<<endl;
    cout<<"Choose 5 if you are part of the team working under coordinators"<<endl;
    cout<<"Choose 6 if you want to exit the portal"<<endl;
    cin>>choice;

    if(choice==1)
    {
        Participant p(student_name, student_id);
        p.add_events("Dance");
        p.display_events();
    }
    else if(choice==2)
    {   
        string division;
        cout<<"Enter the division you are a part of:"<<endl;
        cin>>division;

        string designation;
        cout<<"Enter your designation:"<<endl;
        cin>>designation;


        CoreTeam student_name(st, division, designation);
        st.display();
        student_name.display();

    }
    else if(choice==3)
    {   
        string CoreTeamhead;
        string division;

        cout<<"Enter you division: "<<endl;
        cin>>division;

        cout<<"Enter the name of the core team head under which you are working: "<<endl;
        cin>>CoreTeamhead;

        Coordinator student_name(CoreTeamhead, division);
        student_name.display();

    }

    else if(choice == 6)
    {
        exit=0;
    }

    cout<<"This log is complete. Next entry"<<endl;
    }
    return 0;
}
