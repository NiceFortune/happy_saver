#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;
#define LIST_SIZE 30
#define TRUE 1

class Svng{
    public:
    string title;

    int goal_amount;
    int curr_amount;

    string start_d;
    string end_d;

    char is_full;
};

class S_List{
    Svng l[LIST_SIZE];
    int count;
    int index;
    public:
        S_List();
        void addSvng(Svng s);
        void readSvng();
        void updateSvng();
        void removeSvng();
        void searchData();
        void saveData();
        void loadData();
        void transSvng();
};

S_List::S_List(){
    count = 0;
    index = 0;
}

int select_menu(){
    int menu;
    cout<<"\n*** NICE FORTUNE ***\n";
    cout<<"1. Create a new piggy bank\n";
    cout<<"2. View status\n";
    cout<<"3. Change current status\n";
    cout<<"4. Remove piggy bank\n";
    cout<<"5. Save status\n";
    cout<<"6. Search piggy bank\n";
    cout<<"0. Quit  \n\t\t>> ";
    cin>>menu;
    cout<<endl;
    getchar();
    return menu;
}

void S_List::addSvng(Svng s){
    l[count].title = s.title;
    l[count].goal_amount = s.goal_amount;
    l[count].curr_amount = s.curr_amount;
    l[count].start_d = s.start_d;
    l[count].end_d = s.end_d;
    l[count].is_full = s.is_full;

    count++;
    index++;
    return;
}

void S_List::readSvng(){
    if(index==0){
        cout << "There are no piggy banks :(\n";
        return;
    } 
    for(int i=0;i<count;i++){
        if(l[i].title=="") continue;

        cout<<"Piggy Bank #"<<i+1<<endl;
        cout<<"TITLE: "<<l[i].title<<endl;
        cout<<"GOAL: $"<<l[i].goal_amount<<endl;
        cout<<"STATUS: $"<<l[i].curr_amount<<endl;
        cout<<"START: "<<l[i].start_d<<endl;
        cout<<"END: "<<l[i].end_d<<endl;
        cout<<"FINISHED?: "<<l[i].is_full<<endl<<endl;
    }
    return;
}

void S_List::updateSvng(){
    int change_num, change_att, tmp;

    cout<<"Enter number of piggy bank to change: ";
    cin>>change_num;
    if(l[change_num-1].title=="") {
        cout << "Improper input.\n";
        return;
    }
    cout<<"Enter which attricute to change: \n";
    cout<<"1) Piggy bank name\n";
    cout<<"2) Goal Amount\n";
    cout<<"3) Current Savings\n";
    cout<<"4) Start Date\n";
    cout<<"5) End Date\n";
    cin>>change_att;
    getchar();
    switch (change_att){
        case 1:
            cout<<"Enter new piggy bank name: ";
            getline(cin, l[change_num-1].title);
            break;
        case 2:
            cout<<"Enter goal amount: ";
            cin>>l[change_num-1].goal_amount;
            getchar();
            break;
        case 3:
            cout<<"Enter amount to add to bank: ";
            cin>>tmp;
            l[change_num-1].curr_amount += tmp;
            break;
        case 4:
            cout<<"Enter starting date: ";
            getline(cin, l[change_num-1].start_d);
            break;
        case 5:
            cout<<"Enter end date: ";
            getline(cin, l[change_num-1].end_d);
            break;
    }
    cout<<"Change successfully implemented.\n";
}

void S_List::removeSvng(){
    int num;

    readSvng();

    cout << "Enter the number of piggy bank to delete: ";
    cin >> num;
    if(l[num-1].title==""){ 
        cout << "Improper input.\n";
        return;
    }
    cout <<"Are you sure you're going to delete? (Delete:1) ";
    cin>>num;

    if(num==1){
        l[num-1].title="";
        index--;
    }
    else{
        printf("Deletion canceled.\n");
        return;
    }
}

void S_List :: saveData(){
    int i;
    ofstream myfile;

    myfile.open("datalist.txt");
    for(i=0;i<count;i++){
        if(l[i].title==""){
            continue;
        }
        myfile << l[i].title << endl;
        myfile << l[i].goal_amount << endl; 
        myfile << l[i].curr_amount << endl; 
        myfile << l[i].start_d << endl;
        myfile << l[i].end_d << endl;
        myfile << l[i].is_full<< endl;
    }
    cout<<"=> 저장됨!\n";
    return;
}

void S_List :: loadData(){
    ifstream myfile;
    string tmp;
    
    myfile.open("datalist.txt");
    
    if(!myfile){
        printf("=> No file found\n");
        return;
    }

    cout << "=> Loading...";

    while(TRUE){
        getline(myfile, l[count].title);
        
        getline(myfile, tmp);

        if(!myfile) break;
        
        tmp[-1] = '\0';
        l[count].goal_amount = stoi(tmp, nullptr, 10);
       
        getline(myfile, tmp);
        tmp[-1] = '\0';
        
        l[count].curr_amount = stoi(tmp, nullptr, 10);
        getline(myfile, l[count].start_d);
        getline(myfile,l[count].end_d);
        getline(myfile,tmp);

        l[count].is_full = tmp[0];
        if(!myfile) break;
        count++;
        index++;
    }
    cout << " successful!\n";

    return;
}

void S_List::searchData(){
    string keyword;
    int scount=0;
    cout << "Search >> ";
    getline(cin, keyword);

    for(int i=0;i<count;i++){
        if(l[i].title==""){
            continue;
        }
        else if(l[i].title.find(keyword)!=string::npos){
            cout << "========================\n";
            cout<<"Piggy Bank : "<<l[i].title<<endl;
            cout<<"GOAL: $"<<l[i].goal_amount<<endl;
            cout<<"Current Status: $"<<l[i].curr_amount<<endl;
            cout<<"Start Date: "<<l[i].start_d<<endl;
            cout<<"End Date: "<<l[i].end_d<<endl;
            cout<<"Finished?: "<<l[i].is_full<<endl;

            scount++;
        }  
        cout << "========================\n\n";

    }
    if(scount==0){
        printf("=> 검색된 데이터 없음!\n");
    }
    return;
}

void S_List :: transSvng(){
    int fromNum, toNum, amount;
    cout<<"From: ";
    cin>>fromNum;
    cout<<"To: ";
    cin>>toNum;
    cout<<"Amount: ";
    cin>>amount;

    return;
}
int main(){
    S_List savelist;
    Svng tmp;
    int menu_num;

    savelist.loadData();

    while(TRUE){
        menu_num = select_menu();
        switch(menu_num){
            case 1:
                //input title
                cout<<"Enter new piggy bank name: ";
                getline(cin, tmp.title);
                //input amount
                cout<<"Enter goal amount: ";
                cin>>tmp.goal_amount;
                getchar();
                tmp.curr_amount = 0;
                //input start_date
                cout<<"Enter starting date: ";
                getline(cin, tmp.start_d);
                //input end_date
                cout<<"Enter end date: ";
                getline(cin, tmp.end_d);
        
                tmp.is_full = 'n';
                savelist.addSvng(tmp);
                cout<<"Successfully Saved!\n";
                break;
            case 2:
                savelist.readSvng();
                break;
            case 3:
                savelist.updateSvng();
                break;
            case 4:
                savelist.removeSvng();
                break;
            case 5:
                savelist.saveData();
                break;
            case 6:
                savelist.searchData();
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                break;
        }
        if(menu_num==0) break;
    }
    return 0;
}


