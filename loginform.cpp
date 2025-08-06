#include <iostream>
#include <fstream>
using namespace std;

//class template
class temp{
    string userName,Email,Password;
    string searchName, searchPass, searchEmail;
    
    public:
    fstream file;
    //signup function inside the class.
    void signup(){

        cin.ignore();
        cout << "Enter the username :: " <<endl;
        getline(cin, userName);
        cout << "Enter the Email Address :: "<<endl;
        getline(cin ,Email);
        cout << "Enter the Password :: "<<endl;
        getline(cin,Password);

        //file handling concept used here.
        file.open("logindata.txt", ios :: out | ios :: app);
        file<<userName << Email << Password << endl;
        file.close();
    }

    //login function inside the class
    void login(){

        cin.ignore();
        cout << "Enter the Username :: ";
        getline(cin, searchName);

        cout << "Enter the Password :: ";
        getline(cin, searchPass);

        //file handling used here.

        bool found = false;
        file.open("logindata.txt",ios :: in);
        
        while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, Password)){
            if (userName == searchName && Password == searchPass) {
                cout << "\nAccount Login Successfully!\n";
                cout << "Username  :: " << userName << endl;
                cout << "Email     :: " << Email << endl;
                found = true;
                break;
            }
        }
        file.close();

        if (!found){
            cout << "Login is failed... Uername or password is incorrect .... " <<endl;
        }
    }

    //forget password function inside the class
    void forgetPassword() {
        cin.ignore();
        cout << "Enter the Username :: ";
        getline(cin, searchName);

        cout << "Enter the Email Address :: ";
        getline(cin, searchEmail); // correct variable used here

        bool found = false;
        file.open("logindata.txt", ios::in);

        while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, Password)) {
            if (userName == searchName && Email == searchEmail) {
                cout << "Account found....\n";
                cout << "Your password :: " << Password << endl;
                found = true;
                break;
            }
        }

        file.close();

        if (!found) {
            cout << "Account not found or Email is incorrect.\n";
        }
    }

}obj; //here i have created an object of temp class direclty.


int main(){
    //Login form using file handling concept of c++.

    int choice; //This char is character type of variable I have declared.
    
    cout << "1- Login \n";
    cout << "2- Sign-up \n";
    cout << "3- Forget Password \n";
    cout << "4- Exit \n" <<endl;

    cout << "Enter your choice...... ";
    cin >>choice;

    switch (choice)
    {
    case 1:
        obj.login();
    break;
    case 2:
        obj.signup();
    break;
    case 3:
        obj.forgetPassword();
    break;
    case 4:
        cout << "Exiting from the program ..... " <<endl;
    break;
    
    default:
    cout << "You have entered Invalid Input, Please! Try Once Again....... " <<endl;
        break;
    }
    return 0;
}


