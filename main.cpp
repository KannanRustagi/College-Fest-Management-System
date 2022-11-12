#include<iostream>
#include <string>
#include <vector>

using namespace std;

class Events{
    public:

    string title;
    string date;
    string venue;

    Events(string title, string date, string venue)
    {
        this->title=title;
        this->date=date;
        this->venue=venue;
    }

    void display_details(){
        cout<<"Event "<<this->title<<" is scheduled to be held on date "<<this->date<<" at "<<this->venue<<endl;
    }



};

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
            cout<<events_part[i]<<", ";
        }
        cout<<endl;
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
    
};

class Coordinator : public CoreTeam{
    public:
    string division;
    string CoreTeamHead;

    Coordinator(){};

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

class Workforce_Member : public Coordinator{
    public:
    string division;
    string Supervisor;

    Workforce_Member(string Supervisor, string division)
    {
        this->Supervisor=Supervisor;
        this->division= division;
    }

    void display()
    {
        cout<<"Workforce Member "<<this->name<<" is working under "<<this->Supervisor<<" in the division "<<this->division<<endl;
    }

};


int main() {

    vector <string> all_events;

    Events Dance( "Dance", "15/11/22","Auditorium");
    all_events.push_back("Dance");
    Events Debate( "Debate", "16/11/22","Conference Room");
    all_events.push_back("Debate");
    Events Music("Music", "17/11/22","Auditorium");
    all_events.push_back("Music");
    Events Orchestra("Orchestra",  "18/11/22","Auditorium");
    all_events.push_back("Orchestra");

    cout<<"Welcome to College Fest Management System"<<endl;
    cout<<endl;
    cout<<"The different events in the fest are:"<<endl;

    for(int i=0; i<all_events.size(); i++){
        cout<<all_events[i]<<endl;
    }

    cout<<endl;

    int exit=1;
    while(exit)
    {
    string student_name, student_id;
    cout<<"Enter student name: ";
    cin>>student_name;
    cout<<"Enter student id: ";
    cin>>student_id;
    Student st(student_name, student_id);
    cout<<endl;

    cout<<"Select one of the following options:"<<endl;
    int choice;
    cout<<"Choose 1 if you are a participant"<<endl;
    cout<<"Choose 2 if you are a core team member"<<endl;
    cout<<"Choose 3 if you are a coordinator"<<endl;
    cout<<"Choose 4 if you are part of the team working under coordinators"<<endl;
    cout<<"Choose 5 if you want to exit the portal"<<endl;
    cin>>choice;

    cout<<endl;

    if(choice==1)
    {
        Participant p(student_name, student_id);
        int number;
        cout<<"How many events do you want to participate in: "<<endl;
        cin>>number;
        
        for(int i=0; i<number; i++)
        {
        string event;
        cout<<"The event you want to participate in out of the given list: "<<endl;
        cin>>event;
        p.add_events(event);
        }
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

    else if(choice==4)
    {   
        string supervisor;
        string division;

        cout<<"Enter you division: "<<endl;
        cin>>division;

        cout<<"Enter the name of the core team head under which you are working: "<<endl;
        cin>>supervisor;

        Workforce_Member student_name(supervisor, division);
        student_name.display();

    }

    else if(choice == 5)
    {
        exit=0;
    }

    cout<<"This log is complete. Next entry"<<endl;
    cout<<endl;
    }
    return 0;
}
