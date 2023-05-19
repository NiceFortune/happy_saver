#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
#define LIST_SIZE 30
#define TRUE 1

class Svng{
    public:
    string title; // 이름

    int goal_amount; // 목표량
    int curr_amount; // 현재량

    string start_d; // 시작일
    string end_d; // 종료일

    bool is_full; // 달성 여부
    void set_is_full();
};
void Svng :: set_is_full(){
    if(goal_amount <= curr_amount)
        is_full = true;
    else   
        is_full = false;
}
class S_List{
    Svng l[LIST_SIZE];
    int count;
    int index;
    public:
        S_List();
        void addSvng();
        void readSvng();
        void updateSvng();
        void removeSvng();
        void searchData();
        void saveData();
        void loadData();
        void transSvng();
        void organize_list();
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
    cout<<"7. Transfer money\n";
    cout<<"0. Quit  \n\t\t>> ";

    cin>>menu;
    cout<<endl;
    getchar();

    cout<<"********************\n\n";

    return menu;
}

void S_List::addSvng(){
    string month[13] = {"" ,"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string m[2] = {"a", "b"};
    if(index>=LIST_SIZE){
        cout<<"You have reach a maximum number of piggy banks :(";
        return;
    }
    if(count>=LIST_SIZE){
        cout<<"Organizing List...";
        //여기에 리스트 정리해주는 함수가 필요함!
    }
    //input title
    cout<<"Enter new piggy bank name: ";
    cin >> l[count].title;
    //input amount
    cout<<"Enter goal amount: ";
    cin>>l[count].goal_amount;
    getchar();
    l[count].curr_amount = 0;
    //input start_date
    unsigned short start_year, start_month, start_day;
    cout<<"Enter starting date\n";
    cout<<"Year : "; cin>>start_year;
    cout<<"Month : "; cin>>start_month;
    cout<<"day : "; cin>>start_day;
    //getchar();
    l[count].start_d = month[start_month] + " " + to_string(start_day) + " " + to_string(start_year);
    //getline(cin, tmp.start_d);
    //input end_date
    unsigned short end_year, end_month, end_day;
    cout<<"Enter end date\n";
    cout<<"Year : "; cin>>end_year;
    cout<<"Month : "; cin>>end_month;
    cout<<"day : "; cin>>end_day;
    l[count].end_d = month[end_month] + " " + to_string(end_day) + " " + to_string(end_year);
    //getline(cin, tmp.end_d);
    //setting is_full
    if(l[count].curr_amount >= l[count].goal_amount)
    l[count].is_full = true;
    else 
    l[count].is_full = false;
    cout<<"Successfully Saved!\n";
    /*
    l[count].title = s.title;
    l[count].goal_amount = s.goal_amount;
    l[count].curr_amount = s.curr_amount;
    l[count].start_d = s.start_d;
    l[count].end_d = s.end_d;
    l[count].is_full = s.is_full;
    */
    count++;
    index++;
    return;
}
void S_List :: organize_list(){
    
    return; 
}
void show_is_full(bool is_full){
    if(!is_full)
        cout << "N\n";
    else
        cout << "Y\n"; 
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
        cout<<"FINISHED?: "; 
        show_is_full(l[i].is_full); 
        cout<<endl<<endl;
    }
    return;
}

void S_List::updateSvng(){
    int change_num, change_att, tmp;
    readSvng();
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
    l[change_num-1].set_is_full();
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
    cout<<"=> save !\n";
    return;
}

void S_List :: loadData(){
    ifstream myfile;
    string tmp;
    
    myfile.open("datalist.txt");
    // 파일 없을 경우 고려
    if(!myfile){
        printf("=> No file found.\n");
        return;
    }
    // 파일 있을 시
    cout << "=> Loading...";

    while(TRUE){
        getline(myfile, l[count].title);
        // tmp에 한줄씩 넣어서 개행문자 제거 후 데이타에 넣기
        getline(myfile, tmp);
        
        if(!myfile) break;
        
        tmp[-1] = '\0'; // string -> int 바꾸기 전 개행문자 제거
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
    readSvng();
    int fromNum, toNum, amount;

    cout<<"From: ";
    cin>>fromNum;
    if(l[fromNum-1].title == ""){
        cout<<fromNum<<" is Invalid number.\n";
        return;
    }

    cout<<"To: ";
    cin>>toNum;
    if(l[toNum-1].title == ""){
        cout<<toNum<<" is Invalid number.\n";
        return;
    }

    cout<<"Amount: ";
    cin>>amount;
    if(l[fromNum-1].curr_amount < amount){
        cout<<"It is not enough to subtract "<<amount<<"$..\n";
        return;
    }
    l[fromNum-1].curr_amount -= amount;
    l[toNum-1].curr_amount += amount;
    // 돈 옮긴 후 is_full setting
    l[fromNum-1].set_is_full();
    l[toNum-1].set_is_full();
}
int main(){
    S_List savelist;
    Svng tmp;
    int menu_num;
    int flag = 1;
    savelist.loadData();

    while(TRUE){
        if(flag == 0)
         break;
        menu_num = select_menu();
        switch(menu_num){
            case 0:
            //  종료
                flag = 0;
                break;
            case 1:
                savelist.addSvng();
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
                savelist.transSvng();
                cout<<"Successfully Transfer Money!\n";
                break;
            case 8:
                break;
            default:
                cout << "You can enter numbers from 1 to 7 :>\n";
                break;
        }
    }
    return 0;
}


