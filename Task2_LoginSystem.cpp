#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ڈپلیکیٹ یوزر نیم چیک کرنے کا فنکشن
bool isUsernameTaken(const string& username) {
    ifstream file("database.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

// یوزر رجسٹر کرنے کا فنکشن
void registerUser() {
    string username, password;
    cout << "Enter a new username: ";
    cin >> username;
    
    if (isUsernameTaken(username)) {
        cout << "Error: Username already exists! Please try another.\n";
        return;
    }
    
    cout << "Enter a password: ";
    cin >> password;
    
    // یوزر ڈیٹا کو فائل میں محفوظ کرنا
    ofstream file("database.txt", ios::app);
    file << username << " " << password << "\n";
    file.close();
    
    cout << "Registration successful!\n";
}

// یوزر لاگ ان کرنے کا فنکشن
void loginUser() {
    string username, password, u, p;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    ifstream file("database.txt");
    bool loggedIn = false;
    
    // فائل سے ڈیٹا پڑھ کر شناخت کی تصدیق کرنا
    while (file >> u >> p) {
        if (u == username && p == password) {
            loggedIn = true;
            break;
        }
    }
    
    if (loggedIn) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Error: Invalid username or password.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Login and Registration System ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            loginUser();
        } else if (choice == 3) {
            cout << "Exiting system. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}