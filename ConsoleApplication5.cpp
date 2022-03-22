#include <iostream>
#include <vector>
#include <string>

using namespace std;

// create a class named Person
class Person
{
public:
    string name;
    vector<Person*> friends;

    // constructor for the person object
    Person(string name) { this->name = name; }

    // function to add a friend to a persons list 
    void befriend(Person* p) 
    { 
        friends.push_back(p); 
    }

    // function to remove a given friend from a persons list
    void unfriend(Person* p)
    {
        int index = -1;

        int num = 0;

        for (Person* person : friends)
        {
            if (person->name.compare(p->name) == 0)
            {
                index = num;
                break;
            }
            num++;
        }

        if (index == -1)
            cout << "The given friend does not exist in the friends list!" << endl;
        else
            friends.erase(friends.begin() + index);
    }

    // function to return all names of friends for a given person
    string getfriendnames()
    {
        string friendList = "";

        for (Person* p : friends)
            friendList += (p->name + "\n");

        return friendList;
    }
};

// main method for testing person class
int main()
{
    // Create person object
    Person p("Dillon");

    // Create people
    Person* friend1 = new Person("Jane");
    Person* friend2 = new Person("Jack");
    Person* friend3 = new Person("Jill");
    Person* friend4 = new Person("John");
    Person* friend5 = new Person("Jake");

    // Befriend all created people
    p.befriend(friend1);
    p.befriend(friend2);
    p.befriend(friend3);
    p.befriend(friend4);
    p.befriend(friend5);

    // Display all friends before removal
    cout << "Friends of " << p.name << " are: \n" << p.getfriendnames();
    
    // Remove one friend 
    p.unfriend(friend3);

    // Display friends after removal
    cout << "\n\nFriends of " << p.name << " are: \n" << p.getfriendnames();

    return 0;
}
