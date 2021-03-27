#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void login();
void registration();

void registration(){
    string username, password;
    cout << "To register, enter Username: ";
    cin >> username;
    cout << endl << "Password: ";
    cin >> password;

    ofstream file;
    file.open("D:\\Career\\login_registration\\" + username + ".txt");
    file << username << endl << password ;
    file.close();

    cout << "Registered Successfully. Now you can login" << endl;
    cout << "Press any key" << endl;
    char d;
    if(cin >>d){
        login();
    }
    return;
}

void login(){
    string username, password;
    // check if the user exists 
    cout << "Username: ";
    cin >> username;
    cout << endl << "Password: ";
    cin >> password;
    // if exists find the file and check credentials
    string un, pw;

    ifstream read("D:\\Career\\login_registration\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == username and pw == password){
        cout << "You have successfully logged in..." << endl;
    }
        // dont exist throw error
    else{
        int choose;
        cout << "User doesnot exist. Please Register" << endl;
        registration();
    }
    return;
}

int main(){
    int choice;
    cout << "For login, enter '1'" << endl << "To Register, enter '2'" << endl;
    cout << "Enter your choice!" << endl;
    cin >> choice;
    cout << endl;
    while(choice != 1 and choice != 2){
        cout << "Chosen number should be 1 or 2." << endl;
        cin >> choice;
    }
    if(choice == 1) login();
    else registration();

    return 0;
}