#include<bits/stdc++.h>
using namespace std;
#define speed() ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

// Replace getch() with a macOS-compatible version
char getch() {
    char ch;
    cin >> ch;
    return ch;
}
void gotoxy(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}

// price list of items
// Each array index value is used as an identifier for item codes
float price_list[20] = {865, 2.25, 44, 10, 20, 7710, 33.33, 48, 87, 97, 63, 8, 0.5, 0.01, 88, 999, 25000, 87, 4, 22 };

class po; // Forwaed declaration of po class (needed while using friend fucntions)

/*Class definitions*/

class requisition {
    /*Defining the data members for storing requisition details*/
    static int req_no;
    int item_code;
    int qty;
    string delivery_date;
    public:
    /*class function decllarations*/
    void get_data(){
        system("clear");
        req_no++;
        cout << "Product Item Code : ";
        cin>> item_code;
        cout << "\nQuantity: "; 
        cin>> qty;
        cout << "\nDelivery Date: ";
        cin.clear();
        cin.ignore(1000, '\n');
        getline(cin,delivery_date);
    }
    void display(){
        system("clear");
        cout<< "Requisition NUmber: " << req_no;
        cout << "\nProduct Item Code: " << item_code;
        cout << "\nQuantity: " << qty;
        cout << "\nDelivery Date: " << delivery_date;
        cin.clear();
        getch();
    }
    friend void generate(requisition, po); // friend fuction declaration
};

/*Fucntion for receiving requisiton details*/


//defining static data_member 
int requisition:: req_no;
// Function for displaying requisition details


class po{
    static int po_no;
    public:
    // constructor is used for incrementing the po_no variable;
    po(){
        po_no++;
    }
    friend void generate(requisition,po); // friend function declaration
};

// Defining the static data member
int po:: po_no;

// Defining the friend function generate()
void generate(requisition r, po p){
    ofstream fout;
    //Retreiving system date and time
    time_t current = time(0);
    char* dt = ctime(&current);
    // opening the current po.txt file in which po details are stored 
    fout.open("Current_PO.txt");
    // Generating the PO and storing it in the Current_PO.txt file in a formatted manner
    fout << "\t\t\t Purchase Order#: " << p.po_no << "\n";
    fout << "\t\t\t ___________________\n\n";
    fout << "Requisition#: " << r.req_no  << "\t\t\t\t Issue Date: " << dt << "\n\n";
    if(r.item_code >= 1 and r.item_code <= 10)
    fout << "Supplier: " << "SKS Inc \n\n";
    else if ( r.item_code >= 11 and r.item_code <=20 ){
        fout <<"Supplier: " << "KC Spare Parts Ltd. \n\n";
    }else{
        fout <<"Supplier: " << "Other (_____________)\n\n";
    }
    fout << "Delivery Date: " << r.delivery_date << "\n\n";
    fout << "- - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- -- - - - - - - - - - -- --- - \n";
    fout << "                                             **Line Items**                                         \n";
    fout << "- - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- -- - - - - - - - - - -- --- - \n";
    fout << "Item Code\t\t Quantity\t\tPrice \t\t \tTotal\n";
    fout << "_________\t\t ________\t\t ______\t\t______\n";
    if (r.item_code >= 1 and r.item_code <=20)
    fout << " " << price_list[r.item_code - 1] << "\t\t\t" << price_list[r.item_code - 1] * r.qty << "\n\n\n";
    else
    fout <<"_ _ _ \t\t\t _ _ _\n\n\n\n";
    ifstream fin;

    char line[80];
    // Opening th terms.txt file from where standard terms and conditions are copied into the PO
    fin.open("terms.txt");

    while(fin){
        fin.getline(line,80);
        fout << line << "\n";
    }
    fin.close();
    fout << "\n\n\n\n\nAuthorize Signatory: \t\t\t\t\t\t Total: _ _ _ ";
    fout.close();

}

/*Main function*/

int main(){
    // speed();
    requisition r;
    char flag = 'f';
    char ch;
    // Displaying the a menu to accept user commands
    while(1){
        system("clear");
        gotoxy(35,8);
        cout << "PRPO";
        gotoxy(35,9);
        cout << "_______";
        gotoxy(22,12);
        cout << " 1- Create New Requisition ";
        gotoxy(22,13);
        cout << " 2- Display Requsition ";
        gotoxy(22,14);
        cout << "3 - Generate PO";
        gotoxy(22,15);
        cout << "4 - Exit";
        gotoxy(22,18);
        cout << "Select an option by typing the numeric code: ";
        ch = getch();
        cout << ch << '\n';
        switch(ch){
            case('1'):
            {
                r.get_data();
                flag = 't';
                // setTimeout(1000);
                cout << "executed" << endl;
                break;
            }
            case('2'):{
                cout << "YES" << endl;
                if(flag == 'f'){
                    gotoxy(22,20);
                    cout << "Requisition details not yet entered ! Press any key to continue ...";
                    getch();
                }else{
                    cout << "Calling display function..." << endl;
                    r.display();
                    cout << "Returned from display function..." << endl;
                    break;
                }
            }
            case('3'):{
                po p;
                generate (r,p);
                gotoxy(22,20);
                cout << "PR has been converted into a PO. You can view the Current_O.txt file to view the genrated PO and tke its print out";
                getch();
                break;
            }
            case('4'):{
                exit(1);
                break;
            }
            default:
            {
                gotoxy(22,20);
                cout << "Invalid Choice: Press any key to continue.. ";
                getch();
            }
        }
    }
}