#include <iostream>
#include <string>
#include <vector>

class Person
{
public:
    std::string name;
    std::string pn;
    std::string nn;
    bool bookmark;
    Person(): bookmark(false){}
};

class PhoneBook
{
    public:
        std::vector<Person> pblist;
        void add();
        void search();
        void bookmark();
        void remove();
};

void PhoneBook::add(){
    std::string name, pn, nn;
    std::cout << "Contract Information (Name, Phone number, Nickname): ";
    std::cin >> name >> pn >> nn;

    Person person;
    person.name = name;
    person.pn = pn;
    person.nn = nn;

    PhoneBook::pblist.push_back(person);
}

void PhoneBook::search(){
    if (PhoneBook::pblist.size() == 0){
        std::cout << "Phonebook is Empty\n";
        return;
    }
    std::cout << "INDEX" << '\t'  << "NAME" << '\n';
    for (int i=0;i<PhoneBook::pblist.size();i++){
        std::cout << (i+1) << '\t'  << PhoneBook::pblist[i].name << '\n';
    }

    int idx;
    std::cout<<"Choose index of contract: ";
    std::cin>>idx;
    idx--;
    std::cout << PhoneBook::pblist[idx].name << ' ' << PhoneBook::pblist[idx].pn << ' ' <<PhoneBook::pblist[idx].nn << '\n';

    while (1){
        std::string yes_no;
        std::cout<<"Do you want to bookmark this contract? (Yes/No): ";
        std::cin>>yes_no;
        if (yes_no=="Yes"){
            PhoneBook::pblist[idx].bookmark = true;
            std::cout<<PhoneBook::pblist[idx].name<<"'s contract is Added on Bookmark\n";
            break;
        }
        else if (yes_no=="No"){
            std::cout<<"Not Added\n";
            break;
        }
    }
};

void PhoneBook::bookmark(){
    if (PhoneBook::pblist.size()==0){
        std::cout<<"Phonebook is Empty\n";
        return;
    }

    int cnt=0;

    for (int i=0;i<PhoneBook::pblist.size();i++){
        if (PhoneBook::pblist[i].bookmark==true){
            cnt++;
            if (cnt==1){
                std::cout << "INDEX" << '\t'  << "NAME" << '\n';                
            }
            std::cout << (i+1) << '\t'  << PhoneBook::pblist[i].name << '\n';
        }
    }

    if (cnt==0){
        std::cout<<"Bookmark is Empty\n";
    }
};

void PhoneBook::remove(){

    if (PhoneBook::pblist.size()==0){
        std::cout<<"Phonebook is Empty\n";
        return;
    }

    while (1){
        std::string idx_or_pn;
        std::cout<<"Which contract do you want to remove?(Index or Phone Number): ";
        std::cin>>idx_or_pn;

        // first, check phone number
        for (int i=0;i<PhoneBook::pblist.size();i++){
            if (idx_or_pn==PhoneBook::pblist[i].pn){
                std::cout<<PhoneBook::pblist[i].name<<"'s contract is Deleted\n";
                PhoneBook::pblist.erase(PhoneBook::pblist.begin()+i);
                return;
            }
        }
        // second, check index
        int idx = stoi(idx_or_pn);
        if (idx<=0 || idx > PhoneBook::pblist.size()){
            std::cout<<"You typed the wrong Phone number or Index!\n";
            return;
        }
        idx--;
        std::cout<<PhoneBook::pblist[idx].name<<"'s contract is Deleted\n";
        PhoneBook::pblist.erase(PhoneBook::pblist.begin()+idx);
        return;
    }
};

int main(){
    PhoneBook phonebook;
    
    while (1){
        std::cout << "Choose function (ADD/SEARCH/BOOKMARK/REMOVE/EXIT): ";
        std::string fname;
        std::cin >> fname;
        
        if (fname=="ADD"){
            phonebook.add();
        }
        else if(fname=="SEARCH"){
            phonebook.search();
        }
        else if (fname=="BOOKMARK"){
            phonebook.bookmark();
        }
        else if (fname=="REMOVE"){
            phonebook.remove();
        }
        else if (fname=="EXIT"){
            break;
        }
    }

    return 0;
}