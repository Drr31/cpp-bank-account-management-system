#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <list>
#include <fstream>
#include <limits>
#include <iomanip>
#include <sstream>

using namespace std;

class Account{
    private:
    string AccountNo, Password;
    double Balance;
    public:
    Account(){
        AccountNo="";
        Password="";
        Balance=0;
    }
    void setAccountNo(string id ){
        this->AccountNo=id;
    }
    void setPassword(string pw){
        this->Password=pw;
    }
    void setBalance(int b){
        this->Balance=b;
    }
    string getAccountNo(){
        return AccountNo;
    }
    string getPassword(){
        return Password;
    }
    double getBalance(){
        return Balance;
    }
    void openAccount(Account user){
        system("clear");
        string id , pw;

        cout << "\t Enter Account No: ";
        cin>> id;
        user.setAccountNo(id);

        cout << "Enter A strong Password: ";
        cin>>pw;

        user.setPassword(pw);

        user.setBalance(0);

        ofstream outfile("Account.txt",ios::app);
        if(!outfile){
            cout << " \tError : file Cant be open ! "<< endl;
        }
        else{
            outfile<< " \t" << user.getAccountNo() << " \t" << user.getPassword() << " \t" << user.getBalance() << endl;
            cout << " \t Account Created Successfully " << endl;
        }
        outfile.close();
    }
    void addCash() {
        system("clear");
        string id;

        cout << " \t Enter Account No:" << endl;
        cin >> id;

        ifstream infile("Account.txt");
        ofstream outfile("Account_temp.txt");

        if (!infile || !outfile) {
            cout << "File Can't Open " << endl;
            return;
        }
        string line;
        bool found = false;

        while (getline(infile, line)) {
            if (line.find_first_not_of(" \t\r\n") == string::npos) {
                outfile << line << endl;
                continue;
            }
            stringstream ss(line);
            string userID, userPW;
            double userBalance = 0;
            if (!(ss >> userID >> userPW >> userBalance)) {
                outfile << line << endl;
                continue;
            }
            if (id == userID) {
                found = true;
                double cash = 0;
                cout << "Enter the amount " << endl;
                cin >> cash;
                const double newBalance = userBalance + cash;
                outfile << " \t" << userID << " \t" << userPW << " \t" << newBalance << endl;
            } else {
                outfile << line << endl;
            }
        }
        infile.close();
        outfile.close();
        if (found) {
            remove("Account.txt");
            rename("Account_temp.txt", "Account.txt");
            cout << "\t Balance updated." << endl;
        } else {
            remove("Account_temp.txt");
            cout << "\t Enter Valid Account No ! " << endl;
        }
    }

    void withdraw() {
        system("clear");
        string id, pw;
        cout << "Enter Account No: ";
        cin >> id;
        cout << "Enter the Password : ";
        cin >> pw;

        ifstream infile("Account.txt");
        ofstream outfile("Account_temp.txt");
        if (!infile || !outfile) {
            cout << "File Can't Open " << endl;
            return;
        }
        string line;
        bool found = false;
        while (getline(infile, line)) {
            if (line.find_first_not_of(" \t\r\n") == string::npos) {
                outfile << line << endl;
                continue;
            }
            stringstream ss(line);
            string userID, userPW;
            double userBalance = 0;
            if (!(ss >> userID >> userPW >> userBalance)) {
                outfile << line << endl;
                continue;
            }
            if (id == userID && pw == userPW) {
                found = true;
                double cash = 0;
                cout << "\tEnter the amount of cash: ";
                cin >> cash;
                if (cash <= userBalance) {
                    const double newBalance = userBalance - cash;
                    outfile << " \t" << userID << " \t" << userPW << " \t" << userBalance << endl;
                    cout << "\tTransaction success." << endl;
                } else {
                    cout << "Low balance mate " << endl;
                    outfile << " \t" << userID << " \t" << userPW << " \t" << userBalance << endl;
                }
            } else {
                outfile << line << endl;
            }
        }
        infile.close();
        outfile.close();
        if (found) {
            remove("Account.txt");
            rename("Account_temp.txt", "Account.txt");
        } else {
            remove("Account_temp.txt");
            cout << "\tAccount not found or wrong password." << endl;
        }
    }
};


int main(){
    Account user;
    bool exit=false;
    while (!exit)
    {
        system("clear");
        int val;
        cout << "\tWelcome to Bank Account Management System " << endl;
        cout << "\t******************************************" << endl;
        cout << "\t1 Open New Account ."<< endl;
        cout << "\t2 Add Cash." << endl;
        cout << "\t3 Width draw Cash."<< endl;
        cout << "\t4 Enter your choice : " << endl;
        cin >> val;

        if (val == 1) {
            user.openAccount(user);
        } else if (val == 2) {
            user.addCash();
        } else if (val == 3) {
            user.withdraw();
        }else if (val == 4) {
            system("clear");
            exit=true;
            cout << "Good Luck"<< endl;
        }
    }
}
