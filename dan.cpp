#include <iostream>
#include <fstream>

using namespace std;

void add(void);
void show(void);
void search(void);

int main()
{
    int chos=0;
    while(chos!=4)
    {
        cout << "wellcome to the hamaden libery\n\n";
        cout << "\t1.add new book\n";
        cout << "\t2.show all books\n";
        cout << "\t3.search book\n";
        cout << "\t4.exit\n\n";

        cout << "whats your request?(choose 1 to 4) ";
        cin >> chos;

        switch (chos)
        {
        case 1:
            add();
            break;
        case 2:
            show();
            break;
        case 3:
            search();
            break;
        case 4:
            break;
        default:
            cout << "\nworng number";
            break;
        }
    }
    return 0;
}
void add(void)
{
    ofstream n("F:\\ketab\\n1.txt",ios::app);
    ofstream sh("F:\\ketab\\show.txt",ios::app);
    string nbook,nwriter;
    char isbn[13];
    cout << "whats book name? ";
    cin >> nbook;
    cout << "\nwhats writer name? ";
    cin >> nwriter;
    cout << "\nenter book isbn: ";
    sh << "{" << nbook << "}" << endl;
    n << "name: " << nbook << endl;
    n << "writer: " << nwriter << endl;
    for(int i=0;i<13;i++)
        cin >> isbn[i];
    n << "isbn: ";
    for(int i=0;i<13;i++)
        n << isbn[i];
    n << '.' << endl;
}
void show(void)
{
    ifstream sh("F:\\ketab\\show.txt");
    cout << "the all of books: \n\n";
    char ch;
    sh.get(ch);
    while(!sh.eof())
    {
        cout.put(ch);
        if(ch=='\n')
            cout << endl;
        sh.get(ch);
    }
}
void search(void)
{
    ifstream ser("F:\\ketab\\n1.txt");
    string se,nse,bser,s;
    cout << "enter your book name: ";
    cin >> nse;
    bser = "name: " + nse;
    getline(ser,se,'\n');
    while (!ser.eof())
    {
        if(se==bser)
        {
            getline(ser,s,'.');
            cout << endl << se << endl << s << endl << endl;
            break;
        }
        getline(ser,se,'\n');
    }
}