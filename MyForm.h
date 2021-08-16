#pragma once
#include"message.h"
#include<msclr/marshal_cppstd.h>
#include<msclr/marshal.h>
#include<msclr/marshal_cppstd.h>
#include<msclr/marshal_cppstd.h>
#include<msclr/marshal_atl.h>
#include <iostream>
#include"articles.h"
#include"books.h"
#include"digitalmedia.h"
#include"contents.h"
#include"subscribers.h"
#include"borrowingrecord.h"
#include"library.h"
#include<map>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void loadborrowfile();
void loadsubscriberfile();
void loadlibrraryfile();
void loaditemsfile();
void updatebookinborrow(books);
void updatedigitalinborrow(digitalmedia);
void updatearticleinborrow(articles);
void increase(int);
void saveinfile();
void deletebookinborrow(int);
void deletearticleinborrow(int);
void deletedigitalmediainborrow(int);
void uniquekey(int itemid);
void edilibraryinborrow(string, string, string, string);
void deletelibraryinborrow(string, string);

string isValidLibraryId(string id);
string isValidSubscriberid(string id);
string isValidSubscriberType(string stype);
string isValidSubscriberName(string sname);
string isValidSubscriberPhone(string pNo);
string isValidSubscriberEmail(string semail);
string isValidAuthor(string auth);
string isValidPublisher(string pub); 
string isValidProductionYear(string year);
string isValidCopies(string copies);

int global_iteamid = 1;
vector<library> lib;
vector<subscribers> sub;
vector<borrowingrecord> borr;


void increase(int itemid);
void saveinfile();
void  updatebookinborrow(books that);
void  updatearticleinborrow(articles that);
void  updatedigitalinborrow(digitalmedia that);
void deletebookinborrow(int itemid);
void deletearticleinborrow(int itemid);
void deletedigitalmediainborrow(int itemid);
void uniquekey(int itemid);
void edilibraryinborrow(string findid, string findname, string replaceid, string replacename);
void deletelibraryinborrow(string itemid, string name);
void loadlibrraryfile();
void loaditemsfile();
void loadsubscriberfile();
void loadborrowfile();

namespace LIbraryMnagementSystem 
{

    
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
		MyForm(void)//constructor
		{
			InitializeComponent();
            loadlibrraryfile();
            loaditemsfile();
            loadsubscriberfile();
            loadborrowfile();
			this->addeditdelete->Hide();
			this->borrow->Hide();
			this->returnpnl->Hide();
			this->viewupduepnl->Hide();

		}
        bool isValidLibraryName(string lname)
        {
            bool x = true;

            if (lname.empty())
            {
                string msg = "Library name is empty";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                obj->ShowDialog();
                x = false;
            }
            else
            {
                for (int i = 0; i < lname.length(); i++)
                {
                    if (!(isalpha(lname[i]) || lname[i] == 32))
                    {
                        //cout << "Error! Library name should consisit alphabet or space. Please try again....\n";
                        //cout << "Enter Library name: ";
                        string msg = "Library name should consist \nalphabet or space";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        x = false;
                    }
                }
            }

            return x;
        }
        bool isValidLibraryId(string id)
        {
            bool x = true;
            if (id.empty())
            {
                string msg = "Library id is empty";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                obj->ShowDialog();
                x = false;
            }
            else
            {
                for (int i = 0; i < id.length(); i++)
                {
                    if (!(isdigit(id[i])))
                    {
                        string msg = "Library id must contain only digits";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        x = false;
                        break;
                    }
                }
            }


            return x;
        }
        //
        bool isValidSubId(string id)
        {
            bool x = true;
            if (id.empty())
            {
                string msg = "Subscriber id  is empty";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                obj->ShowDialog();
                x = false;
            }
            else
            {
                for (int i = 0; i < id.length(); i++)
                {
                    if (!(isdigit(id[i])))
                    {
                        string msg = "Subscriber id must contain only digits";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        x = false;
                        return x;
                    }
                }
            }


            return x;
        }
        bool isValidSubscriberType(string stype)
        {
            for (int i = 0; i < stype.length(); i++)
                stype[i] = toupper(stype[i]);

            bool x = true;
            if (stype == "REGULAR" || stype == "GOLDEN")
            {

            }
            else {
                string msg = "Subscriber type should \nbe 'Golden' or 'Regular'";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                obj->ShowDialog();
                x = false;
            }
            return x;
        }
        bool isValidSubscriberName(string sname) {
            bool x = true;
            if (sname.empty())
            {
                string msg = "Subscriber name  is empty";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                obj->ShowDialog();
                x = false;
            }
            else
            {
                if (sname.length() > 30)
                {
                    string msg = "Subscriber name length \nshould be of 30 or less";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    obj->ShowDialog();
                    x = false;
                }
                else
                {
                    for (int i = 0; i < sname.length(); i++)
                    {
                        if (!(isalpha(sname[i]) || sname[i] == 32))
                        {
                            string msg = "Subscriber name should consist \nalphabet or space";
                            string head = "Error!";
                            message^ obj = gcnew message(this, msg, head);
                            obj->ShowDialog();
                            return x = false;
                        }
                    }
                }
            }


            return x;

        }

        bool isValidSubscriberPhone(string pNo) {
            bool x = true;
            if (pNo.length() == 11)
            {
                for (int i = 0; i < pNo.length(); i++)
                {
                    if (!(isdigit(pNo[i])))
                    {
                        string msg = " Phone no must contain only digits";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        x = false;
                        break;
                    }
                }

            }
            else
            {
                string msg = " Subscriber Phone no length should be of 11";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                obj->ShowDialog();
                x = false;
            }

            return x;
        }
        bool isValidSubscriberEmail(string semail)
        {
            bool xl = true;
            size_t x = semail.find('@');
            if (x != string::npos)
            {
                string key;
                key = semail.substr(x + 1);
                if (!(key == "gmail.com" || key == "hotmail.com" || key == "yahoo.com"))
                {
                    //cout << "Error! email must contain 'gmail.com' or 'hotmail.com' or 'yahoo.com' as domain Please try again...\n";
                    //cout << "Enter email: ";
                    string msg = "Email must contain 'gmail.com' or \n'hotmail.com' or 'yahoo.com' as domain";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    obj->ShowDialog();
                    xl = false;
                }
            }
            else {
                string msg = "Email must contain domain";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                obj->ShowDialog();
                xl = false;
            }
            return xl;
        }
        //
        bool isValidAuthor(string auth) {
            bool x = true;
            if (auth.empty())

            {
                string msg = "Author name is empty";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                obj->ShowDialog();
                x = false;
            }
            else
            {
                for (int i = 0; i < auth.length(); i++)
                {
                    if (!(isalpha(auth[i]) || auth[i] == 32))
                    {
                        string msg = "Author name should consist alphabet or space";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        x = false;
                        break;
                    }
                }
            }





            return x;
        }
        bool isValidPublisher(string pub) {

            bool x = true;
            if (pub.empty())
            {
                string msg = "Publisher name  is empty";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                obj->ShowDialog();
                x = false;
            }
            else
            {
                for (int i = 0; i < pub.length(); i++)
                {
                    if (!(isalpha(pub[i]) || pub[i] == 32))
                    {
                        string msg = "Publisher name should consist \nalphabet or space";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        x = false;
                        break;
                    }
                }
            }

            return x;
        }
        bool isValidProductionYear(string p_year) {
            
            bool x = true;
            if (p_year.empty())
            {
                string msg = "Production year  is empty";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                obj->ShowDialog();
                x = false;
            }
            else
            {
                for (int i = 0; i < p_year.length(); i++)
                {
                    if (isdigit(p_year[i]))
                    {
                        
                    }
                    else
                    {
                        string msg = "Production year should consist \nonly digits";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        x = false;
                        break;
                    }
                }
                if (x)
                {
                    int pyear = stoi(p_year, nullptr, 10);
                    if (pyear > 2020 || pyear < 1800)
                    {
                        string msg = "Production year must be greater \nthan 1800 and less or equal to 2020";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        x = false;
                    }
                }
            }

            return x;
        }
        bool isValidCopies(string copi) {

            bool x = true;
            if (copi == "")
            {
                string msg = "Copies section is empty";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                obj->ShowDialog();
                x = false;
            }
            else
            {
                for (int i = 0; i < copi.length(); i++)
                {
                    if (!(isdigit(copi[i])))
                    {
                        string msg = "Copies should consist \nonly digits";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        x = false;
                        break;
                    }
                }
                if (x)
                {
                    int copy = stoi(copi, nullptr, 10);
                    if (copy < 0)
                    {
                        string msg = "No of copies must not be less than 0";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        x = false;
                    }
                }
            }



            return x;
        }
	protected:
		
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
        System::Windows::Forms::ListViewItem^ listview;
	private: System::Windows::Forms::Label^ Librarymanagement;


	private: System::Windows::Forms::Button^ button3;

private: System::Windows::Forms::Panel^ returnpnl;
private: System::Windows::Forms::Button^ button21;
private: System::Windows::Forms::Label^ returnst;
private: System::Windows::Forms::Panel^ viewupduepnl;
private: System::Windows::Forms::Button^ button22;
private: System::Windows::Forms::Button^ button23;
private: System::Windows::Forms::Label^ label57;
private: System::Windows::Forms::Panel^ returnbookpnl;
private: System::Windows::Forms::Button^ button33;
private: System::Windows::Forms::Panel^ panel22;
private: System::Windows::Forms::TextBox^ returnbooktxt;

private: System::Windows::Forms::Label^ label75;
private: System::Windows::Forms::Label^ label74;
private: System::Windows::Forms::Label^ label73;
private: System::Windows::Forms::Button^ button32;
private: System::Windows::Forms::Button^ button31;
private: System::Windows::Forms::Button^ button30;
private: System::Windows::Forms::Button^ button29;
private: System::Windows::Forms::Label^ label72;
private: System::Windows::Forms::Panel^ panel21;
private: System::Windows::Forms::TextBox^ returnsubinfotxt;

private: System::Windows::Forms::Label^ label71;
private: System::Windows::Forms::Label^ label70;
private: System::Windows::Forms::Panel^ returnarticlepnl;
private: System::Windows::Forms::Button^ button34;
private: System::Windows::Forms::Panel^ panel24;
private: System::Windows::Forms::TextBox^ returnarticletxt;

private: System::Windows::Forms::Label^ label76;
private: System::Windows::Forms::Label^ label77;
private: System::Windows::Forms::Label^ label78;
private: System::Windows::Forms::Panel^ returndigitalpnl;
private: System::Windows::Forms::Button^ button35;
private: System::Windows::Forms::Panel^ panel25;
private: System::Windows::Forms::TextBox^ returndigitaltxt;
private: System::Windows::Forms::Label^ label79;
private: System::Windows::Forms::Label^ label80;
private: System::Windows::Forms::Label^ label81;

























private: System::Windows::Forms::Button^ button4;

private: System::Windows::Forms::Label^ label95;
private: System::Windows::Forms::Panel^ panel34;
private: System::Windows::Forms::Panel^ panel35;
private: System::Windows::Forms::Panel^ panel36;
private: System::Windows::Forms::Panel^ borrow;
private: System::Windows::Forms::ListView^ listView1;
private: System::Windows::Forms::ColumnHeader^ columnHeader11;
private: System::Windows::Forms::ColumnHeader^ columnHeader12;
private: System::Windows::Forms::ColumnHeader^ columnHeader13;
private: System::Windows::Forms::ColumnHeader^ columnHeader14;
private: System::Windows::Forms::ColumnHeader^ columnHeader15;
private: System::Windows::Forms::ColumnHeader^ columnHeader16;
private: System::Windows::Forms::ColumnHeader^ columnHeader17;
private: System::Windows::Forms::ColumnHeader^ columnHeader18;
private: System::Windows::Forms::ColumnHeader^ columnHeader19;
private: System::Windows::Forms::ColumnHeader^ columnHeader20;
private: System::Windows::Forms::ListView^ listView2;
private: System::Windows::Forms::ColumnHeader^ columnHeader1;
private: System::Windows::Forms::ColumnHeader^ columnHeader2;
private: System::Windows::Forms::ColumnHeader^ columnHeader3;
private: System::Windows::Forms::ColumnHeader^ columnHeader4;
private: System::Windows::Forms::ColumnHeader^ columnHeader5;
private: System::Windows::Forms::ColumnHeader^ columnHeader6;
private: System::Windows::Forms::ColumnHeader^ columnHeader7;
private: System::Windows::Forms::ColumnHeader^ columnHeader8;
private: System::Windows::Forms::ColumnHeader^ columnHeader9;
private: System::Windows::Forms::ColumnHeader^ columnHeader10;
private: System::Windows::Forms::Label^ label96;
private: System::Windows::Forms::Button^ button9;
private: System::Windows::Forms::Button^ borrowlistokbtn;
private: System::Windows::Forms::Button^ viewlistbtn;
private: System::Windows::Forms::Panel^ panel32;
private: System::Windows::Forms::TextBox^ borrowsubinfoinput;
private: System::Windows::Forms::Label^ label91;
private: System::Windows::Forms::Label^ label90;
private: System::Windows::Forms::Label^ label89;
private: System::Windows::Forms::Label^ label88;
private: System::Windows::Forms::Button^ reselect;
private: System::Windows::Forms::Button^ doneselection;
private: System::Windows::Forms::Button^ borrowselectedok;
private: System::Windows::Forms::Label^ label83;
private: System::Windows::Forms::Label^ selecteditempnl;
private: System::Windows::Forms::Button^ button20;
private: System::Windows::Forms::Button^ printlist;
private: System::Windows::Forms::Button^ oksub;
private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::TextBox^ borrowsubtxt;
private: System::Windows::Forms::Label^ label51;
private: System::Windows::Forms::Label^ label52;
private: System::Windows::Forms::Label^ label53;
private: System::Windows::Forms::Label^ labelborrow;

private: System::Windows::Forms::Panel^ addeditdelete;
private: System::Windows::Forms::Panel^ deletesubpnl;
private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::TextBox^ deletesubtxt;
private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::Button^ button10;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::Panel^ deletebookpnl;
private: System::Windows::Forms::Button^ button14;
private: System::Windows::Forms::Panel^ panel20;
private: System::Windows::Forms::TextBox^ deletebooktxt;
private: System::Windows::Forms::Label^ label33;
private: System::Windows::Forms::Label^ label34;
private: System::Windows::Forms::Label^ label35;
private: System::Windows::Forms::Panel^ dletearticlepnl;
private: System::Windows::Forms::Panel^ panel6;
private: System::Windows::Forms::TextBox^ deletearticletxt;
private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::Label^ label31;
private: System::Windows::Forms::Button^ button13;
private: System::Windows::Forms::Label^ label32;
private: System::Windows::Forms::Panel^ deletedigitalpnl;
private: System::Windows::Forms::Panel^ panel8;
private: System::Windows::Forms::TextBox^ deletedigitaltxt;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::Button^ button12;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::Panel^ deletelibrarypnl;
private: System::Windows::Forms::Panel^ panel9;
private: System::Windows::Forms::TextBox^ deletelibtxt;
private: System::Windows::Forms::Label^ label24;
private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::Button^ button11;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::Panel^ bookadd;
private: System::Windows::Forms::Button^ btnbookadd;
private: System::Windows::Forms::Panel^ panel13;
private: System::Windows::Forms::TextBox^ addbooktext;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Panel^ addlib;
private: System::Windows::Forms::Button^ addlibbtn;
private: System::Windows::Forms::Panel^ panel4;
private: System::Windows::Forms::TextBox^ addlibtxt;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Panel^ subadd;
private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::TextBox^ addsubtxt;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Button^ button6;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::Panel^ digitaladd;





private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Panel^ editarticlepnl;
private: System::Windows::Forms::Label^ label64;
private: System::Windows::Forms::Label^ label58;
private: System::Windows::Forms::Panel^ panel11;
private: System::Windows::Forms::TextBox^ newarticletxt;
private: System::Windows::Forms::Label^ label59;
private: System::Windows::Forms::Label^ label60;
private: System::Windows::Forms::Button^ button25;
private: System::Windows::Forms::Panel^ panel12;
private: System::Windows::Forms::TextBox^ editartricletxt;
private: System::Windows::Forms::Label^ label61;
private: System::Windows::Forms::Button^ button18;
private: System::Windows::Forms::Label^ label47;
private: System::Windows::Forms::Panel^ articleadd;
private: System::Windows::Forms::Panel^ panel10;
private: System::Windows::Forms::TextBox^ addarticleinputtxt;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Button^ button8;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Panel^ editsubscriberpnl;
private: System::Windows::Forms::Label^ label36;
private: System::Windows::Forms::Label^ label37;
private: System::Windows::Forms::Panel^ panel18;
private: System::Windows::Forms::TextBox^ newsubtxt;
private: System::Windows::Forms::Label^ label67;
private: System::Windows::Forms::Label^ label68;
private: System::Windows::Forms::Button^ button28;
private: System::Windows::Forms::Panel^ panel19;
private: System::Windows::Forms::TextBox^ editsubtxt;
private: System::Windows::Forms::Label^ label69;
private: System::Windows::Forms::Button^ button15;
private: System::Windows::Forms::Label^ label38;
private: System::Windows::Forms::Panel^ editdigitalpnl;
private: System::Windows::Forms::Label^ label66;
private: System::Windows::Forms::Label^ label42;
private: System::Windows::Forms::Panel^ panel16;
private: System::Windows::Forms::TextBox^ newdigitaltxt;
private: System::Windows::Forms::Label^ label43;
private: System::Windows::Forms::Label^ label62;
private: System::Windows::Forms::Button^ button27;
private: System::Windows::Forms::Panel^ panel17;
private: System::Windows::Forms::TextBox^ editdigitaltxt;
private: System::Windows::Forms::Label^ label63;
private: System::Windows::Forms::Button^ button17;
private: System::Windows::Forms::Label^ label44;
private: System::Windows::Forms::Panel^ editlibpnl;
private: System::Windows::Forms::Label^ label65;
private: System::Windows::Forms::Label^ label39;
private: System::Windows::Forms::Panel^ panel14;
private: System::Windows::Forms::TextBox^ newlibtxt;
private: System::Windows::Forms::Label^ label40;
private: System::Windows::Forms::Label^ label45;
private: System::Windows::Forms::Button^ button26;
private: System::Windows::Forms::Panel^ panel15;
private: System::Windows::Forms::TextBox^ editlibtxt;
private: System::Windows::Forms::Label^ label46;
private: System::Windows::Forms::Button^ button16;
private: System::Windows::Forms::Label^ label41;
private: System::Windows::Forms::Panel^ editbookpnl;
private: System::Windows::Forms::Label^ label56;
private: System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::TextBox^ newbooktxt;
private: System::Windows::Forms::Label^ label54;
private: System::Windows::Forms::Label^ label55;
private: System::Windows::Forms::Button^ button24;
private: System::Windows::Forms::Button^ button19;
private: System::Windows::Forms::Panel^ panel30;
private: System::Windows::Forms::TextBox^ editbooktxt;
private: System::Windows::Forms::Label^ label48;
private: System::Windows::Forms::Label^ label49;
private: System::Windows::Forms::Label^ label50;
private: System::Windows::Forms::Button^ back;
private: System::Windows::Forms::Button^ deletesubscriber;
private: System::Windows::Forms::Button^ deletelib;
private: System::Windows::Forms::Button^ deletedigital;
private: System::Windows::Forms::Button^ deletarticle;
private: System::Windows::Forms::Button^ deletebook;
private: System::Windows::Forms::Button^ Editlib;
private: System::Windows::Forms::Button^ Editsub;
private: System::Windows::Forms::Button^ editarticle;
private: System::Windows::Forms::Button^ editdigital;
private: System::Windows::Forms::Button^ editBook;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ Book;
private: System::Windows::Forms::Button^ addliberary;
private: System::Windows::Forms::Button^ addsubscriber;
private: System::Windows::Forms::Button^ AddArticle;
private: System::Windows::Forms::Button^ AddDigitalMedia;
private: System::Windows::Forms::Button^ Addbook;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Panel^ dockingpnl;
private: System::Windows::Forms::Button^ button37;
private: System::Windows::Forms::ListView^ listView3;
private: System::Windows::Forms::ColumnHeader^ columnHeader21;
private: System::Windows::Forms::ColumnHeader^ columnHeader22;
private: System::Windows::Forms::ColumnHeader^ columnHeader23;


private: System::Windows::Forms::Label^ label98;
private: System::Windows::Forms::Label^ label97;
private: System::Windows::Forms::Panel^ panel7;
private: System::Windows::Forms::TextBox^ adddigitaltxt;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Button^ button7;
private: System::Windows::Forms::Button^ button38;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Button^ button1;


	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->Librarymanagement = (gcnew System::Windows::Forms::Label());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->returnpnl = (gcnew System::Windows::Forms::Panel());
            this->returndigitalpnl = (gcnew System::Windows::Forms::Panel());
            this->button35 = (gcnew System::Windows::Forms::Button());
            this->panel25 = (gcnew System::Windows::Forms::Panel());
            this->returndigitaltxt = (gcnew System::Windows::Forms::TextBox());
            this->label79 = (gcnew System::Windows::Forms::Label());
            this->label80 = (gcnew System::Windows::Forms::Label());
            this->label81 = (gcnew System::Windows::Forms::Label());
            this->returnarticlepnl = (gcnew System::Windows::Forms::Panel());
            this->button34 = (gcnew System::Windows::Forms::Button());
            this->panel24 = (gcnew System::Windows::Forms::Panel());
            this->returnarticletxt = (gcnew System::Windows::Forms::TextBox());
            this->label76 = (gcnew System::Windows::Forms::Label());
            this->label77 = (gcnew System::Windows::Forms::Label());
            this->label78 = (gcnew System::Windows::Forms::Label());
            this->returnbookpnl = (gcnew System::Windows::Forms::Panel());
            this->button33 = (gcnew System::Windows::Forms::Button());
            this->panel22 = (gcnew System::Windows::Forms::Panel());
            this->returnbooktxt = (gcnew System::Windows::Forms::TextBox());
            this->label75 = (gcnew System::Windows::Forms::Label());
            this->label74 = (gcnew System::Windows::Forms::Label());
            this->label73 = (gcnew System::Windows::Forms::Label());
            this->label95 = (gcnew System::Windows::Forms::Label());
            this->button32 = (gcnew System::Windows::Forms::Button());
            this->button31 = (gcnew System::Windows::Forms::Button());
            this->button30 = (gcnew System::Windows::Forms::Button());
            this->button29 = (gcnew System::Windows::Forms::Button());
            this->label72 = (gcnew System::Windows::Forms::Label());
            this->panel21 = (gcnew System::Windows::Forms::Panel());
            this->returnsubinfotxt = (gcnew System::Windows::Forms::TextBox());
            this->label70 = (gcnew System::Windows::Forms::Label());
            this->button21 = (gcnew System::Windows::Forms::Button());
            this->returnst = (gcnew System::Windows::Forms::Label());
            this->label71 = (gcnew System::Windows::Forms::Label());
            this->viewupduepnl = (gcnew System::Windows::Forms::Panel());
            this->listView3 = (gcnew System::Windows::Forms::ListView());
            this->columnHeader21 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader22 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader23 = (gcnew System::Windows::Forms::ColumnHeader());
            this->button22 = (gcnew System::Windows::Forms::Button());
            this->button23 = (gcnew System::Windows::Forms::Button());
            this->label57 = (gcnew System::Windows::Forms::Label());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->panel34 = (gcnew System::Windows::Forms::Panel());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button38 = (gcnew System::Windows::Forms::Button());
            this->panel35 = (gcnew System::Windows::Forms::Panel());
            this->panel36 = (gcnew System::Windows::Forms::Panel());
            this->borrow = (gcnew System::Windows::Forms::Panel());
            this->listView1 = (gcnew System::Windows::Forms::ListView());
            this->columnHeader11 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader12 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader13 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader14 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader15 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader16 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader17 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader18 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader19 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader20 = (gcnew System::Windows::Forms::ColumnHeader());
            this->listView2 = (gcnew System::Windows::Forms::ListView());
            this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
            this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
            this->button9 = (gcnew System::Windows::Forms::Button());
            this->borrowlistokbtn = (gcnew System::Windows::Forms::Button());
            this->viewlistbtn = (gcnew System::Windows::Forms::Button());
            this->panel32 = (gcnew System::Windows::Forms::Panel());
            this->borrowsubinfoinput = (gcnew System::Windows::Forms::TextBox());
            this->label91 = (gcnew System::Windows::Forms::Label());
            this->label90 = (gcnew System::Windows::Forms::Label());
            this->label89 = (gcnew System::Windows::Forms::Label());
            this->label88 = (gcnew System::Windows::Forms::Label());
            this->reselect = (gcnew System::Windows::Forms::Button());
            this->doneselection = (gcnew System::Windows::Forms::Button());
            this->borrowselectedok = (gcnew System::Windows::Forms::Button());
            this->label83 = (gcnew System::Windows::Forms::Label());
            this->selecteditempnl = (gcnew System::Windows::Forms::Label());
            this->button20 = (gcnew System::Windows::Forms::Button());
            this->printlist = (gcnew System::Windows::Forms::Button());
            this->oksub = (gcnew System::Windows::Forms::Button());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->borrowsubtxt = (gcnew System::Windows::Forms::TextBox());
            this->label51 = (gcnew System::Windows::Forms::Label());
            this->label52 = (gcnew System::Windows::Forms::Label());
            this->label53 = (gcnew System::Windows::Forms::Label());
            this->labelborrow = (gcnew System::Windows::Forms::Label());
            this->label96 = (gcnew System::Windows::Forms::Label());
            this->addeditdelete = (gcnew System::Windows::Forms::Panel());
            this->deletesubpnl = (gcnew System::Windows::Forms::Panel());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->deletesubtxt = (gcnew System::Windows::Forms::TextBox());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->button10 = (gcnew System::Windows::Forms::Button());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->deletebookpnl = (gcnew System::Windows::Forms::Panel());
            this->button14 = (gcnew System::Windows::Forms::Button());
            this->panel20 = (gcnew System::Windows::Forms::Panel());
            this->deletebooktxt = (gcnew System::Windows::Forms::TextBox());
            this->label33 = (gcnew System::Windows::Forms::Label());
            this->label34 = (gcnew System::Windows::Forms::Label());
            this->label35 = (gcnew System::Windows::Forms::Label());
            this->dletearticlepnl = (gcnew System::Windows::Forms::Panel());
            this->panel6 = (gcnew System::Windows::Forms::Panel());
            this->deletearticletxt = (gcnew System::Windows::Forms::TextBox());
            this->label30 = (gcnew System::Windows::Forms::Label());
            this->label31 = (gcnew System::Windows::Forms::Label());
            this->button13 = (gcnew System::Windows::Forms::Button());
            this->label32 = (gcnew System::Windows::Forms::Label());
            this->deletedigitalpnl = (gcnew System::Windows::Forms::Panel());
            this->panel8 = (gcnew System::Windows::Forms::Panel());
            this->deletedigitaltxt = (gcnew System::Windows::Forms::TextBox());
            this->label27 = (gcnew System::Windows::Forms::Label());
            this->label28 = (gcnew System::Windows::Forms::Label());
            this->button12 = (gcnew System::Windows::Forms::Button());
            this->label29 = (gcnew System::Windows::Forms::Label());
            this->deletelibrarypnl = (gcnew System::Windows::Forms::Panel());
            this->panel9 = (gcnew System::Windows::Forms::Panel());
            this->deletelibtxt = (gcnew System::Windows::Forms::TextBox());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->label25 = (gcnew System::Windows::Forms::Label());
            this->button11 = (gcnew System::Windows::Forms::Button());
            this->label26 = (gcnew System::Windows::Forms::Label());
            this->addlib = (gcnew System::Windows::Forms::Panel());
            this->addlibbtn = (gcnew System::Windows::Forms::Button());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->addlibtxt = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->bookadd = (gcnew System::Windows::Forms::Panel());
            this->btnbookadd = (gcnew System::Windows::Forms::Button());
            this->panel13 = (gcnew System::Windows::Forms::Panel());
            this->addbooktext = (gcnew System::Windows::Forms::TextBox());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->subadd = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->addsubtxt = (gcnew System::Windows::Forms::TextBox());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->digitaladd = (gcnew System::Windows::Forms::Panel());
            this->panel7 = (gcnew System::Windows::Forms::Panel());
            this->adddigitaltxt = (gcnew System::Windows::Forms::TextBox());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->articleadd = (gcnew System::Windows::Forms::Panel());
            this->panel10 = (gcnew System::Windows::Forms::Panel());
            this->addarticleinputtxt = (gcnew System::Windows::Forms::TextBox());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->button8 = (gcnew System::Windows::Forms::Button());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->editarticlepnl = (gcnew System::Windows::Forms::Panel());
            this->label64 = (gcnew System::Windows::Forms::Label());
            this->label58 = (gcnew System::Windows::Forms::Label());
            this->panel11 = (gcnew System::Windows::Forms::Panel());
            this->newarticletxt = (gcnew System::Windows::Forms::TextBox());
            this->label59 = (gcnew System::Windows::Forms::Label());
            this->label60 = (gcnew System::Windows::Forms::Label());
            this->button25 = (gcnew System::Windows::Forms::Button());
            this->panel12 = (gcnew System::Windows::Forms::Panel());
            this->editartricletxt = (gcnew System::Windows::Forms::TextBox());
            this->label61 = (gcnew System::Windows::Forms::Label());
            this->button18 = (gcnew System::Windows::Forms::Button());
            this->label47 = (gcnew System::Windows::Forms::Label());
            this->editsubscriberpnl = (gcnew System::Windows::Forms::Panel());
            this->label36 = (gcnew System::Windows::Forms::Label());
            this->label37 = (gcnew System::Windows::Forms::Label());
            this->panel18 = (gcnew System::Windows::Forms::Panel());
            this->newsubtxt = (gcnew System::Windows::Forms::TextBox());
            this->label67 = (gcnew System::Windows::Forms::Label());
            this->label68 = (gcnew System::Windows::Forms::Label());
            this->button28 = (gcnew System::Windows::Forms::Button());
            this->panel19 = (gcnew System::Windows::Forms::Panel());
            this->editsubtxt = (gcnew System::Windows::Forms::TextBox());
            this->label69 = (gcnew System::Windows::Forms::Label());
            this->button15 = (gcnew System::Windows::Forms::Button());
            this->label38 = (gcnew System::Windows::Forms::Label());
            this->editdigitalpnl = (gcnew System::Windows::Forms::Panel());
            this->label66 = (gcnew System::Windows::Forms::Label());
            this->label42 = (gcnew System::Windows::Forms::Label());
            this->panel16 = (gcnew System::Windows::Forms::Panel());
            this->newdigitaltxt = (gcnew System::Windows::Forms::TextBox());
            this->label43 = (gcnew System::Windows::Forms::Label());
            this->label62 = (gcnew System::Windows::Forms::Label());
            this->button27 = (gcnew System::Windows::Forms::Button());
            this->panel17 = (gcnew System::Windows::Forms::Panel());
            this->editdigitaltxt = (gcnew System::Windows::Forms::TextBox());
            this->label63 = (gcnew System::Windows::Forms::Label());
            this->button17 = (gcnew System::Windows::Forms::Button());
            this->label44 = (gcnew System::Windows::Forms::Label());
            this->editlibpnl = (gcnew System::Windows::Forms::Panel());
            this->label65 = (gcnew System::Windows::Forms::Label());
            this->label39 = (gcnew System::Windows::Forms::Label());
            this->panel14 = (gcnew System::Windows::Forms::Panel());
            this->newlibtxt = (gcnew System::Windows::Forms::TextBox());
            this->label40 = (gcnew System::Windows::Forms::Label());
            this->label45 = (gcnew System::Windows::Forms::Label());
            this->button26 = (gcnew System::Windows::Forms::Button());
            this->panel15 = (gcnew System::Windows::Forms::Panel());
            this->editlibtxt = (gcnew System::Windows::Forms::TextBox());
            this->label46 = (gcnew System::Windows::Forms::Label());
            this->button16 = (gcnew System::Windows::Forms::Button());
            this->label41 = (gcnew System::Windows::Forms::Label());
            this->editbookpnl = (gcnew System::Windows::Forms::Panel());
            this->label56 = (gcnew System::Windows::Forms::Label());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->newbooktxt = (gcnew System::Windows::Forms::TextBox());
            this->label54 = (gcnew System::Windows::Forms::Label());
            this->label55 = (gcnew System::Windows::Forms::Label());
            this->button24 = (gcnew System::Windows::Forms::Button());
            this->button19 = (gcnew System::Windows::Forms::Button());
            this->panel30 = (gcnew System::Windows::Forms::Panel());
            this->editbooktxt = (gcnew System::Windows::Forms::TextBox());
            this->label48 = (gcnew System::Windows::Forms::Label());
            this->label49 = (gcnew System::Windows::Forms::Label());
            this->label50 = (gcnew System::Windows::Forms::Label());
            this->back = (gcnew System::Windows::Forms::Button());
            this->deletesubscriber = (gcnew System::Windows::Forms::Button());
            this->deletelib = (gcnew System::Windows::Forms::Button());
            this->deletedigital = (gcnew System::Windows::Forms::Button());
            this->deletarticle = (gcnew System::Windows::Forms::Button());
            this->deletebook = (gcnew System::Windows::Forms::Button());
            this->Editlib = (gcnew System::Windows::Forms::Button());
            this->Editsub = (gcnew System::Windows::Forms::Button());
            this->editarticle = (gcnew System::Windows::Forms::Button());
            this->editdigital = (gcnew System::Windows::Forms::Button());
            this->editBook = (gcnew System::Windows::Forms::Button());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->Book = (gcnew System::Windows::Forms::Label());
            this->addliberary = (gcnew System::Windows::Forms::Button());
            this->addsubscriber = (gcnew System::Windows::Forms::Button());
            this->AddArticle = (gcnew System::Windows::Forms::Button());
            this->AddDigitalMedia = (gcnew System::Windows::Forms::Button());
            this->Addbook = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->dockingpnl = (gcnew System::Windows::Forms::Panel());
            this->label98 = (gcnew System::Windows::Forms::Label());
            this->label97 = (gcnew System::Windows::Forms::Label());
            this->button37 = (gcnew System::Windows::Forms::Button());
            this->returnpnl->SuspendLayout();
            this->returndigitalpnl->SuspendLayout();
            this->returnarticlepnl->SuspendLayout();
            this->returnbookpnl->SuspendLayout();
            this->viewupduepnl->SuspendLayout();
            this->panel34->SuspendLayout();
            this->panel35->SuspendLayout();
            this->borrow->SuspendLayout();
            this->addeditdelete->SuspendLayout();
            this->deletesubpnl->SuspendLayout();
            this->deletebookpnl->SuspendLayout();
            this->dletearticlepnl->SuspendLayout();
            this->deletedigitalpnl->SuspendLayout();
            this->deletelibrarypnl->SuspendLayout();
            this->addlib->SuspendLayout();
            this->bookadd->SuspendLayout();
            this->subadd->SuspendLayout();
            this->digitaladd->SuspendLayout();
            this->articleadd->SuspendLayout();
            this->editarticlepnl->SuspendLayout();
            this->editsubscriberpnl->SuspendLayout();
            this->editdigitalpnl->SuspendLayout();
            this->editlibpnl->SuspendLayout();
            this->editbookpnl->SuspendLayout();
            this->dockingpnl->SuspendLayout();
            this->SuspendLayout();
            // 
            // Librarymanagement
            // 
            this->Librarymanagement->AutoSize = true;
            this->Librarymanagement->BackColor = System::Drawing::Color::Transparent;
            this->Librarymanagement->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Librarymanagement->ForeColor = System::Drawing::Color::Red;
            this->Librarymanagement->Location = System::Drawing::Point(219, 30);
            this->Librarymanagement->Name = L"Librarymanagement";
            this->Librarymanagement->Size = System::Drawing::Size(593, 45);
            this->Librarymanagement->TabIndex = 0;
            this->Librarymanagement->Text = L"Library Management System";
            this->Librarymanagement->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // button3
            // 
            this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(144)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Red;
            this->button3->FlatAppearance->BorderSize = 7;
            this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button3->ForeColor = System::Drawing::Color::White;
            this->button3->Location = System::Drawing::Point(3, 425);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(271, 62);
            this->button3->TabIndex = 3;
            this->button3->Text = L"Return";
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            // 
            // returnpnl
            // 
            this->returnpnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"returnpnl.BackgroundImage")));
            this->returnpnl->Controls->Add(this->returndigitalpnl);
            this->returnpnl->Controls->Add(this->returnarticlepnl);
            this->returnpnl->Controls->Add(this->returnbookpnl);
            this->returnpnl->Controls->Add(this->label95);
            this->returnpnl->Controls->Add(this->button32);
            this->returnpnl->Controls->Add(this->button31);
            this->returnpnl->Controls->Add(this->button30);
            this->returnpnl->Controls->Add(this->button29);
            this->returnpnl->Controls->Add(this->label72);
            this->returnpnl->Controls->Add(this->panel21);
            this->returnpnl->Controls->Add(this->returnsubinfotxt);
            this->returnpnl->Controls->Add(this->label70);
            this->returnpnl->Controls->Add(this->button21);
            this->returnpnl->Controls->Add(this->returnst);
            this->returnpnl->Controls->Add(this->label71);
            this->returnpnl->Location = System::Drawing::Point(16, 5);
            this->returnpnl->Name = L"returnpnl";
            this->returnpnl->Size = System::Drawing::Size(1067, 586);
            this->returnpnl->TabIndex = 12;
            this->returnpnl->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::returnpnl_Paint);
            // 
            // returndigitalpnl
            // 
            this->returndigitalpnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"returndigitalpnl.BackgroundImage")));
            this->returndigitalpnl->Controls->Add(this->button35);
            this->returndigitalpnl->Controls->Add(this->panel25);
            this->returndigitalpnl->Controls->Add(this->returndigitaltxt);
            this->returndigitalpnl->Controls->Add(this->label79);
            this->returndigitalpnl->Controls->Add(this->label80);
            this->returndigitalpnl->Controls->Add(this->label81);
            this->returndigitalpnl->Location = System::Drawing::Point(214, 81);
            this->returndigitalpnl->Name = L"returndigitalpnl";
            this->returndigitalpnl->Size = System::Drawing::Size(645, 372);
            this->returndigitalpnl->TabIndex = 36;
            // 
            // button35
            // 
            this->button35->BackColor = System::Drawing::Color::Blue;
            this->button35->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button35->Font = (gcnew System::Drawing::Font(L"Lucida Console", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button35->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->button35->Location = System::Drawing::Point(492, 312);
            this->button35->Name = L"button35";
            this->button35->Size = System::Drawing::Size(121, 41);
            this->button35->TabIndex = 34;
            this->button35->Text = L"OK";
            this->button35->UseVisualStyleBackColor = false;
            this->button35->Click += gcnew System::EventHandler(this, &MyForm::button35_Click);
            // 
            // panel25
            // 
            this->panel25->Location = System::Drawing::Point(176, 169);
            this->panel25->Name = L"panel25";
            this->panel25->Size = System::Drawing::Size(437, 5);
            this->panel25->TabIndex = 30;
            // 
            // returndigitaltxt
            // 
            this->returndigitaltxt->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
            this->returndigitaltxt->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->returndigitaltxt->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->returndigitaltxt->Location = System::Drawing::Point(176, 136);
            this->returndigitaltxt->Name = L"returndigitaltxt";
            this->returndigitaltxt->Size = System::Drawing::Size(437, 35);
            this->returndigitaltxt->TabIndex = 29;
            // 
            // label79
            // 
            this->label79->AutoSize = true;
            this->label79->BackColor = System::Drawing::Color::Transparent;
            this->label79->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label79->ForeColor = System::Drawing::Color::White;
            this->label79->Location = System::Drawing::Point(48, 131);
            this->label79->Name = L"label79";
            this->label79->Size = System::Drawing::Size(128, 47);
            this->label79->TabIndex = 26;
            this->label79->Text = L"Input:";
            // 
            // label80
            // 
            this->label80->AutoSize = true;
            this->label80->BackColor = System::Drawing::Color::Transparent;
            this->label80->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label80->ForeColor = System::Drawing::Color::White;
            this->label80->Location = System::Drawing::Point(171, 50);
            this->label80->Name = L"label80";
            this->label80->Size = System::Drawing::Size(307, 25);
            this->label80->TabIndex = 25;
            this->label80->Text = L"Digital Title,Digital AUTHOR";
            // 
            // label81
            // 
            this->label81->AutoSize = true;
            this->label81->BackColor = System::Drawing::Color::Transparent;
            this->label81->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label81->ForeColor = System::Drawing::Color::White;
            this->label81->Location = System::Drawing::Point(105, 0);
            this->label81->Name = L"label81";
            this->label81->Size = System::Drawing::Size(463, 47);
            this->label81->TabIndex = 24;
            this->label81->Text = L"Enter the required info ";
            // 
            // returnarticlepnl
            // 
            this->returnarticlepnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"returnarticlepnl.BackgroundImage")));
            this->returnarticlepnl->Controls->Add(this->button34);
            this->returnarticlepnl->Controls->Add(this->panel24);
            this->returnarticlepnl->Controls->Add(this->returnarticletxt);
            this->returnarticlepnl->Controls->Add(this->label76);
            this->returnarticlepnl->Controls->Add(this->label77);
            this->returnarticlepnl->Controls->Add(this->label78);
            this->returnarticlepnl->Location = System::Drawing::Point(217, 72);
            this->returnarticlepnl->Name = L"returnarticlepnl";
            this->returnarticlepnl->Size = System::Drawing::Size(645, 372);
            this->returnarticlepnl->TabIndex = 35;
            // 
            // button34
            // 
            this->button34->BackColor = System::Drawing::Color::Blue;
            this->button34->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button34->Font = (gcnew System::Drawing::Font(L"Lucida Console", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button34->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->button34->Location = System::Drawing::Point(492, 312);
            this->button34->Name = L"button34";
            this->button34->Size = System::Drawing::Size(121, 41);
            this->button34->TabIndex = 34;
            this->button34->Text = L"OK";
            this->button34->UseVisualStyleBackColor = false;
            this->button34->Click += gcnew System::EventHandler(this, &MyForm::button34_Click);
            // 
            // panel24
            // 
            this->panel24->Location = System::Drawing::Point(176, 169);
            this->panel24->Name = L"panel24";
            this->panel24->Size = System::Drawing::Size(437, 5);
            this->panel24->TabIndex = 30;
            // 
            // returnarticletxt
            // 
            this->returnarticletxt->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
            this->returnarticletxt->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->returnarticletxt->ForeColor = System::Drawing::Color::White;
            this->returnarticletxt->Location = System::Drawing::Point(176, 136);
            this->returnarticletxt->Name = L"returnarticletxt";
            this->returnarticletxt->Size = System::Drawing::Size(437, 35);
            this->returnarticletxt->TabIndex = 29;
            // 
            // label76
            // 
            this->label76->AutoSize = true;
            this->label76->BackColor = System::Drawing::Color::Transparent;
            this->label76->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label76->ForeColor = System::Drawing::Color::White;
            this->label76->Location = System::Drawing::Point(48, 131);
            this->label76->Name = L"label76";
            this->label76->Size = System::Drawing::Size(128, 47);
            this->label76->TabIndex = 26;
            this->label76->Text = L"Input:";
            // 
            // label77
            // 
            this->label77->AutoSize = true;
            this->label77->BackColor = System::Drawing::Color::Transparent;
            this->label77->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label77->ForeColor = System::Drawing::Color::White;
            this->label77->Location = System::Drawing::Point(171, 50);
            this->label77->Name = L"label77";
            this->label77->Size = System::Drawing::Size(307, 25);
            this->label77->TabIndex = 25;
            this->label77->Text = L"Article Title,Article AUTHOR";
            // 
            // label78
            // 
            this->label78->AutoSize = true;
            this->label78->BackColor = System::Drawing::Color::Transparent;
            this->label78->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label78->ForeColor = System::Drawing::Color::White;
            this->label78->Location = System::Drawing::Point(105, 0);
            this->label78->Name = L"label78";
            this->label78->Size = System::Drawing::Size(463, 47);
            this->label78->TabIndex = 24;
            this->label78->Text = L"Enter the required info ";
            // 
            // returnbookpnl
            // 
            this->returnbookpnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"returnbookpnl.BackgroundImage")));
            this->returnbookpnl->Controls->Add(this->button33);
            this->returnbookpnl->Controls->Add(this->panel22);
            this->returnbookpnl->Controls->Add(this->returnbooktxt);
            this->returnbookpnl->Controls->Add(this->label75);
            this->returnbookpnl->Controls->Add(this->label74);
            this->returnbookpnl->Controls->Add(this->label73);
            this->returnbookpnl->Location = System::Drawing::Point(227, 59);
            this->returnbookpnl->Name = L"returnbookpnl";
            this->returnbookpnl->Size = System::Drawing::Size(645, 372);
            this->returnbookpnl->TabIndex = 34;
            // 
            // button33
            // 
            this->button33->BackColor = System::Drawing::Color::Blue;
            this->button33->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button33->Font = (gcnew System::Drawing::Font(L"Lucida Console", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button33->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->button33->Location = System::Drawing::Point(492, 312);
            this->button33->Name = L"button33";
            this->button33->Size = System::Drawing::Size(121, 41);
            this->button33->TabIndex = 34;
            this->button33->Text = L"OK";
            this->button33->UseVisualStyleBackColor = false;
            this->button33->Click += gcnew System::EventHandler(this, &MyForm::button33_Click);
            // 
            // panel22
            // 
            this->panel22->Location = System::Drawing::Point(176, 169);
            this->panel22->Name = L"panel22";
            this->panel22->Size = System::Drawing::Size(437, 5);
            this->panel22->TabIndex = 30;
            // 
            // returnbooktxt
            // 
            this->returnbooktxt->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
            this->returnbooktxt->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->returnbooktxt->ForeColor = System::Drawing::Color::White;
            this->returnbooktxt->Location = System::Drawing::Point(176, 136);
            this->returnbooktxt->Name = L"returnbooktxt";
            this->returnbooktxt->Size = System::Drawing::Size(437, 35);
            this->returnbooktxt->TabIndex = 29;
            // 
            // label75
            // 
            this->label75->AutoSize = true;
            this->label75->BackColor = System::Drawing::Color::Transparent;
            this->label75->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label75->ForeColor = System::Drawing::Color::White;
            this->label75->Location = System::Drawing::Point(48, 131);
            this->label75->Name = L"label75";
            this->label75->Size = System::Drawing::Size(128, 47);
            this->label75->TabIndex = 26;
            this->label75->Text = L"Input:";
            // 
            // label74
            // 
            this->label74->AutoSize = true;
            this->label74->BackColor = System::Drawing::Color::Transparent;
            this->label74->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label74->ForeColor = System::Drawing::Color::White;
            this->label74->Location = System::Drawing::Point(171, 50);
            this->label74->Name = L"label74";
            this->label74->Size = System::Drawing::Size(279, 25);
            this->label74->TabIndex = 25;
            this->label74->Text = L"Book Title,Book AUTHOR";
            // 
            // label73
            // 
            this->label73->AutoSize = true;
            this->label73->BackColor = System::Drawing::Color::Transparent;
            this->label73->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label73->ForeColor = System::Drawing::Color::White;
            this->label73->Location = System::Drawing::Point(105, 0);
            this->label73->Name = L"label73";
            this->label73->Size = System::Drawing::Size(463, 47);
            this->label73->TabIndex = 24;
            this->label73->Text = L"Enter the required info ";
            // 
            // label95
            // 
            this->label95->AutoSize = true;
            this->label95->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->label95->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label95->ForeColor = System::Drawing::Color::White;
            this->label95->Location = System::Drawing::Point(346, 62);
            this->label95->Name = L"label95";
            this->label95->Size = System::Drawing::Size(368, 58);
            this->label95->TabIndex = 37;
            this->label95->Text = L"FIRST ENTER SUBSCRIBER\r\n                    INFO  \r\n";
            // 
            // button32
            // 
            this->button32->BackColor = System::Drawing::Color::Blue;
            this->button32->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button32->Font = (gcnew System::Drawing::Font(L"Lucida Console", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button32->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->button32->Location = System::Drawing::Point(618, 211);
            this->button32->Name = L"button32";
            this->button32->Size = System::Drawing::Size(121, 41);
            this->button32->TabIndex = 33;
            this->button32->Text = L"OK";
            this->button32->UseVisualStyleBackColor = false;
            this->button32->Click += gcnew System::EventHandler(this, &MyForm::button32_Click);
            // 
            // button31
            // 
            this->button31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->button31->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button31->Font = (gcnew System::Drawing::Font(L"Lucida Console", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button31->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->button31->Location = System::Drawing::Point(423, 475);
            this->button31->Name = L"button31";
            this->button31->Size = System::Drawing::Size(249, 48);
            this->button31->TabIndex = 32;
            this->button31->Text = L"Digital Media";
            this->button31->UseVisualStyleBackColor = false;
            this->button31->Click += gcnew System::EventHandler(this, &MyForm::button31_Click);
            // 
            // button30
            // 
            this->button30->BackColor = System::Drawing::Color::Red;
            this->button30->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button30->Font = (gcnew System::Drawing::Font(L"Lucida Console", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button30->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->button30->Location = System::Drawing::Point(423, 408);
            this->button30->Name = L"button30";
            this->button30->Size = System::Drawing::Size(249, 48);
            this->button30->TabIndex = 31;
            this->button30->Text = L"Article";
            this->button30->UseVisualStyleBackColor = false;
            this->button30->Click += gcnew System::EventHandler(this, &MyForm::button30_Click);
            // 
            // button29
            // 
            this->button29->BackColor = System::Drawing::Color::Blue;
            this->button29->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button29->Font = (gcnew System::Drawing::Font(L"Lucida Console", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button29->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->button29->Location = System::Drawing::Point(423, 344);
            this->button29->Name = L"button29";
            this->button29->Size = System::Drawing::Size(249, 48);
            this->button29->TabIndex = 30;
            this->button29->Text = L"Book";
            this->button29->UseVisualStyleBackColor = false;
            this->button29->Click += gcnew System::EventHandler(this, &MyForm::button29_Click);
            // 
            // label72
            // 
            this->label72->AutoSize = true;
            this->label72->BackColor = System::Drawing::Color::Transparent;
            this->label72->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label72->ForeColor = System::Drawing::Color::White;
            this->label72->Location = System::Drawing::Point(374, 272);
            this->label72->Name = L"label72";
            this->label72->Size = System::Drawing::Size(343, 47);
            this->label72->TabIndex = 29;
            this->label72->Text = L"Choose to return";
            // 
            // panel21
            // 
            this->panel21->Location = System::Drawing::Point(354, 200);
            this->panel21->Name = L"panel21";
            this->panel21->Size = System::Drawing::Size(385, 5);
            this->panel21->TabIndex = 28;
            // 
            // returnsubinfotxt
            // 
            this->returnsubinfotxt->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
            this->returnsubinfotxt->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->returnsubinfotxt->ForeColor = System::Drawing::Color::White;
            this->returnsubinfotxt->Location = System::Drawing::Point(354, 167);
            this->returnsubinfotxt->Name = L"returnsubinfotxt";
            this->returnsubinfotxt->Size = System::Drawing::Size(385, 35);
            this->returnsubinfotxt->TabIndex = 27;
            // 
            // label70
            // 
            this->label70->AutoSize = true;
            this->label70->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->label70->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label70->ForeColor = System::Drawing::Color::White;
            this->label70->Location = System::Drawing::Point(329, 141);
            this->label70->Name = L"label70";
            this->label70->Size = System::Drawing::Size(422, 25);
            this->label70->TabIndex = 25;
            this->label70->Text = L"SUBSCRIBER_ID,SUBSCRIBER_NAME";
            // 
            // button21
            // 
            this->button21->BackColor = System::Drawing::Color::Gray;
            this->button21->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button21->FlatAppearance->BorderSize = 0;
            this->button21->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button21->ForeColor = System::Drawing::Color::White;
            this->button21->Location = System::Drawing::Point(914, 517);
            this->button21->Name = L"button21";
            this->button21->Size = System::Drawing::Size(107, 60);
            this->button21->TabIndex = 24;
            this->button21->Text = L"Back";
            this->button21->UseVisualStyleBackColor = false;
            this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
            // 
            // returnst
            // 
            this->returnst->AutoSize = true;
            this->returnst->BackColor = System::Drawing::Color::Transparent;
            this->returnst->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->returnst->ForeColor = System::Drawing::Color::White;
            this->returnst->Location = System::Drawing::Point(293, 0);
            this->returnst->Name = L"returnst";
            this->returnst->Size = System::Drawing::Size(463, 47);
            this->returnst->TabIndex = 23;
            this->returnst->Text = L"Enter the required info ";
            // 
            // label71
            // 
            this->label71->AutoSize = true;
            this->label71->BackColor = System::Drawing::Color::Transparent;
            this->label71->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label71->ForeColor = System::Drawing::Color::White;
            this->label71->Location = System::Drawing::Point(226, 155);
            this->label71->Name = L"label71";
            this->label71->Size = System::Drawing::Size(128, 47);
            this->label71->TabIndex = 26;
            this->label71->Text = L"Input:";
            // 
            // viewupduepnl
            // 
            this->viewupduepnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"viewupduepnl.BackgroundImage")));
            this->viewupduepnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->viewupduepnl->Controls->Add(this->listView3);
            this->viewupduepnl->Controls->Add(this->button22);
            this->viewupduepnl->Controls->Add(this->button23);
            this->viewupduepnl->Controls->Add(this->label57);
            this->viewupduepnl->Location = System::Drawing::Point(10, 9);
            this->viewupduepnl->Name = L"viewupduepnl";
            this->viewupduepnl->Size = System::Drawing::Size(1067, 586);
            this->viewupduepnl->TabIndex = 13;
            this->viewupduepnl->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::viewupduepnl_Paint);
            // 
            // listView3
            // 
            this->listView3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->listView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
                this->columnHeader21, this->columnHeader22,
                    this->columnHeader23
            });
            this->listView3->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->listView3->HideSelection = false;
            this->listView3->Location = System::Drawing::Point(312, 214);
            this->listView3->Name = L"listView3";
            this->listView3->Size = System::Drawing::Size(506, 192);
            this->listView3->TabIndex = 34;
            this->listView3->UseCompatibleStateImageBehavior = false;
            this->listView3->View = System::Windows::Forms::View::Details;
            // 
            // columnHeader21
            // 
            this->columnHeader21->Text = L"Sub_Id";
            this->columnHeader21->Width = 84;
            // 
            // columnHeader22
            // 
            this->columnHeader22->Text = L"Sub_Name";
            this->columnHeader22->Width = 309;
            // 
            // columnHeader23
            // 
            this->columnHeader23->Text = L"Item_Id";
            this->columnHeader23->Width = 107;
            // 
            // button22
            // 
            this->button22->BackColor = System::Drawing::Color::Gray;
            this->button22->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button22->FlatAppearance->BorderSize = 0;
            this->button22->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button22->ForeColor = System::Drawing::Color::White;
            this->button22->Location = System::Drawing::Point(925, 509);
            this->button22->Name = L"button22";
            this->button22->Size = System::Drawing::Size(107, 60);
            this->button22->TabIndex = 33;
            this->button22->Text = L"Back";
            this->button22->UseVisualStyleBackColor = false;
            this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click_1);
            // 
            // button23
            // 
            this->button23->BackColor = System::Drawing::Color::Blue;
            this->button23->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button23->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->button23->Location = System::Drawing::Point(147, 97);
            this->button23->Name = L"button23";
            this->button23->Size = System::Drawing::Size(128, 48);
            this->button23->TabIndex = 32;
            this->button23->Text = L"View List";
            this->button23->UseVisualStyleBackColor = false;
            this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
            // 
            // label57
            // 
            this->label57->AutoSize = true;
            this->label57->BackColor = System::Drawing::Color::Transparent;
            this->label57->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label57->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label57->Location = System::Drawing::Point(280, 1);
            this->label57->Name = L"label57";
            this->label57->Size = System::Drawing::Size(587, 47);
            this->label57->TabIndex = 23;
            this->label57->Text = L"View the list of overdue items";
            // 
            // button4
            // 
            this->button4->BackColor = System::Drawing::Color::Magenta;
            this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button4->ForeColor = System::Drawing::Color::White;
            this->button4->Location = System::Drawing::Point(0, 537);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(271, 62);
            this->button4->TabIndex = 4;
            this->button4->Text = L"View Overdue Items";
            this->button4->UseVisualStyleBackColor = false;
            this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
            // 
            // panel34
            // 
            this->panel34->BackColor = System::Drawing::Color::Black;
            this->panel34->Controls->Add(this->button2);
            this->panel34->Controls->Add(this->button1);
            this->panel34->Controls->Add(this->button38);
            this->panel34->Controls->Add(this->button3);
            this->panel34->Controls->Add(this->button4);
            this->panel34->Dock = System::Windows::Forms::DockStyle::Left;
            this->panel34->Location = System::Drawing::Point(0, 0);
            this->panel34->MaximumSize = System::Drawing::Size(287, 880);
            this->panel34->Name = L"panel34";
            this->panel34->Size = System::Drawing::Size(287, 870);
            this->panel34->TabIndex = 17;
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Red;
            this->button2->FlatAppearance->BorderSize = 7;
            this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button2->ForeColor = System::Drawing::Color::White;
            this->button2->Location = System::Drawing::Point(0, 304);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(271, 62);
            this->button2->TabIndex = 7;
            this->button2->Text = L"Borrow";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(54)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Red;
            this->button1->FlatAppearance->BorderSize = 7;
            this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->ForeColor = System::Drawing::Color::White;
            this->button1->Location = System::Drawing::Point(0, 204);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(271, 62);
            this->button1->TabIndex = 6;
            this->button1->Text = L"Add/ Edit / Delete";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // button38
            // 
            this->button38->BackColor = System::Drawing::Color::Navy;
            this->button38->FlatAppearance->BorderColor = System::Drawing::Color::Red;
            this->button38->FlatAppearance->BorderSize = 7;
            this->button38->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button38->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button38->ForeColor = System::Drawing::Color::White;
            this->button38->Location = System::Drawing::Point(21, 17);
            this->button38->Name = L"button38";
            this->button38->Size = System::Drawing::Size(238, 98);
            this->button38->TabIndex = 5;
            this->button38->Text = L"Home";
            this->button38->UseVisualStyleBackColor = false;
            this->button38->Click += gcnew System::EventHandler(this, &MyForm::button38_Click);
            // 
            // panel35
            // 
            this->panel35->BackColor = System::Drawing::Color::Black;
            this->panel35->Controls->Add(this->Librarymanagement);
            this->panel35->Dock = System::Windows::Forms::DockStyle::Top;
            this->panel35->Location = System::Drawing::Point(287, 0);
            this->panel35->MaximumSize = System::Drawing::Size(1270, 100);
            this->panel35->MinimumSize = System::Drawing::Size(1270, 100);
            this->panel35->Name = L"panel35";
            this->panel35->Size = System::Drawing::Size(1270, 100);
            this->panel35->TabIndex = 18;
            // 
            // panel36
            // 
            this->panel36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->panel36->Dock = System::Windows::Forms::DockStyle::Top;
            this->panel36->Location = System::Drawing::Point(287, 100);
            this->panel36->MaximumSize = System::Drawing::Size(1270, 10);
            this->panel36->Name = L"panel36";
            this->panel36->Size = System::Drawing::Size(1270, 10);
            this->panel36->TabIndex = 19;
            // 
            // borrow
            // 
            this->borrow->AutoScroll = true;
            this->borrow->BackColor = System::Drawing::Color::Black;
            this->borrow->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"borrow.BackgroundImage")));
            this->borrow->Controls->Add(this->listView1);
            this->borrow->Controls->Add(this->listView2);
            this->borrow->Controls->Add(this->button9);
            this->borrow->Controls->Add(this->borrowlistokbtn);
            this->borrow->Controls->Add(this->viewlistbtn);
            this->borrow->Controls->Add(this->panel32);
            this->borrow->Controls->Add(this->borrowsubinfoinput);
            this->borrow->Controls->Add(this->label91);
            this->borrow->Controls->Add(this->label90);
            this->borrow->Controls->Add(this->label89);
            this->borrow->Controls->Add(this->label88);
            this->borrow->Controls->Add(this->reselect);
            this->borrow->Controls->Add(this->doneselection);
            this->borrow->Controls->Add(this->borrowselectedok);
            this->borrow->Controls->Add(this->label83);
            this->borrow->Controls->Add(this->selecteditempnl);
            this->borrow->Controls->Add(this->button20);
            this->borrow->Controls->Add(this->printlist);
            this->borrow->Controls->Add(this->oksub);
            this->borrow->Controls->Add(this->panel1);
            this->borrow->Controls->Add(this->borrowsubtxt);
            this->borrow->Controls->Add(this->label51);
            this->borrow->Controls->Add(this->label52);
            this->borrow->Controls->Add(this->label53);
            this->borrow->Controls->Add(this->labelborrow);
            this->borrow->Controls->Add(this->label96);
            this->borrow->Location = System::Drawing::Point(6, 21);
            this->borrow->MaximumSize = System::Drawing::Size(1550, 824);
            this->borrow->Name = L"borrow";
            this->borrow->Size = System::Drawing::Size(1250, 824);
            this->borrow->TabIndex = 15;
            this->borrow->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::borrow_Paint);
            // 
            // listView1
            // 
            this->listView1->Activation = System::Windows::Forms::ItemActivation::TwoClick;
            this->listView1->BackColor = System::Drawing::Color::Black;
            this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(10) {
                this->columnHeader11, this->columnHeader12,
                    this->columnHeader13, this->columnHeader14, this->columnHeader15, this->columnHeader16, this->columnHeader17, this->columnHeader18,
                    this->columnHeader19, this->columnHeader20
            });
            this->listView1->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->listView1->ForeColor = System::Drawing::Color::White;
            this->listView1->FullRowSelect = true;
            this->listView1->GridLines = true;
            this->listView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
            this->listView1->HideSelection = false;
            this->listView1->Location = System::Drawing::Point(4, 262);
            this->listView1->Name = L"listView1";
            this->listView1->Size = System::Drawing::Size(1232, 279);
            this->listView1->TabIndex = 56;
            this->listView1->UseCompatibleStateImageBehavior = false;
            this->listView1->View = System::Windows::Forms::View::Details;
            // 
            // columnHeader11
            // 
            this->columnHeader11->Text = L"Sr";
            // 
            // columnHeader12
            // 
            this->columnHeader12->Text = L"Lib_Id";
            this->columnHeader12->Width = 79;
            // 
            // columnHeader13
            // 
            this->columnHeader13->Text = L"ItemId";
            this->columnHeader13->Width = 79;
            // 
            // columnHeader14
            // 
            this->columnHeader14->Text = L"Category";
            this->columnHeader14->Width = 131;
            // 
            // columnHeader15
            // 
            this->columnHeader15->Text = L"Title";
            this->columnHeader15->Width = 432;
            // 
            // columnHeader16
            // 
            this->columnHeader16->Text = L"Author";
            this->columnHeader16->Width = 314;
            // 
            // columnHeader17
            // 
            this->columnHeader17->Text = L"Publisher";
            this->columnHeader17->Width = 253;
            // 
            // columnHeader18
            // 
            this->columnHeader18->Text = L"Pro_Year";
            this->columnHeader18->Width = 208;
            // 
            // columnHeader19
            // 
            this->columnHeader19->Text = L"Status";
            this->columnHeader19->Width = 115;
            // 
            // columnHeader20
            // 
            this->columnHeader20->Text = L"Copies";
            this->columnHeader20->Width = 95;
            // 
            // listView2
            // 
            this->listView2->BackColor = System::Drawing::Color::Teal;
            this->listView2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->listView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(10) {
                this->columnHeader1, this->columnHeader2,
                    this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6, this->columnHeader7, this->columnHeader8,
                    this->columnHeader9, this->columnHeader10
            });
            this->listView2->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->listView2->ForeColor = System::Drawing::Color::White;
            this->listView2->HideSelection = false;
            this->listView2->Location = System::Drawing::Point(4, 262);
            this->listView2->Name = L"listView2";
            this->listView2->Size = System::Drawing::Size(1232, 269);
            this->listView2->TabIndex = 55;
            this->listView2->UseCompatibleStateImageBehavior = false;
            this->listView2->View = System::Windows::Forms::View::Details;
            // 
            // columnHeader1
            // 
            this->columnHeader1->Text = L"Sr";
            // 
            // columnHeader2
            // 
            this->columnHeader2->Text = L"Lib_Id";
            this->columnHeader2->Width = 79;
            // 
            // columnHeader3
            // 
            this->columnHeader3->Text = L"ItemId";
            this->columnHeader3->Width = 79;
            // 
            // columnHeader4
            // 
            this->columnHeader4->Text = L"Category";
            this->columnHeader4->Width = 131;
            // 
            // columnHeader5
            // 
            this->columnHeader5->Text = L"Title";
            this->columnHeader5->Width = 432;
            // 
            // columnHeader6
            // 
            this->columnHeader6->Text = L"Author";
            this->columnHeader6->Width = 314;
            // 
            // columnHeader7
            // 
            this->columnHeader7->Text = L"Publisher";
            this->columnHeader7->Width = 253;
            // 
            // columnHeader8
            // 
            this->columnHeader8->Text = L"Pro_Year";
            this->columnHeader8->Width = 208;
            // 
            // columnHeader9
            // 
            this->columnHeader9->Text = L"Status";
            this->columnHeader9->Width = 115;
            // 
            // columnHeader10
            // 
            this->columnHeader10->Text = L"Copies";
            this->columnHeader10->Width = 95;
            // 
            // button9
            // 
            this->button9->BackColor = System::Drawing::Color::DimGray;
            this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button9->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button9->ForeColor = System::Drawing::Color::White;
            this->button9->Location = System::Drawing::Point(896, 613);
            this->button9->Name = L"button9";
            this->button9->Size = System::Drawing::Size(135, 64);
            this->button9->TabIndex = 53;
            this->button9->Text = L"Back";
            this->button9->UseVisualStyleBackColor = false;
            this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click_2);
            // 
            // borrowlistokbtn
            // 
            this->borrowlistokbtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->borrowlistokbtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->borrowlistokbtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->borrowlistokbtn->ForeColor = System::Drawing::Color::White;
            this->borrowlistokbtn->Location = System::Drawing::Point(43, 559);
            this->borrowlistokbtn->Name = L"borrowlistokbtn";
            this->borrowlistokbtn->Size = System::Drawing::Size(96, 42);
            this->borrowlistokbtn->TabIndex = 52;
            this->borrowlistokbtn->Text = L"OK\r\n";
            this->borrowlistokbtn->UseVisualStyleBackColor = false;
            this->borrowlistokbtn->Click += gcnew System::EventHandler(this, &MyForm::borrowlistokbtn_Click);
            // 
            // viewlistbtn
            // 
            this->viewlistbtn->BackColor = System::Drawing::Color::Red;
            this->viewlistbtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->viewlistbtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->viewlistbtn->ForeColor = System::Drawing::Color::White;
            this->viewlistbtn->Location = System::Drawing::Point(646, 178);
            this->viewlistbtn->Name = L"viewlistbtn";
            this->viewlistbtn->Size = System::Drawing::Size(120, 42);
            this->viewlistbtn->TabIndex = 51;
            this->viewlistbtn->Text = L"View list";
            this->viewlistbtn->UseVisualStyleBackColor = false;
            this->viewlistbtn->Click += gcnew System::EventHandler(this, &MyForm::viewlistbtn_Click);
            // 
            // panel32
            // 
            this->panel32->BackColor = System::Drawing::Color::White;
            this->panel32->Location = System::Drawing::Point(328, 168);
            this->panel32->Name = L"panel32";
            this->panel32->Size = System::Drawing::Size(437, 5);
            this->panel32->TabIndex = 50;
            // 
            // borrowsubinfoinput
            // 
            this->borrowsubinfoinput->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
            this->borrowsubinfoinput->Font = (gcnew System::Drawing::Font(L"Arial", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->borrowsubinfoinput->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->borrowsubinfoinput->Location = System::Drawing::Point(328, 135);
            this->borrowsubinfoinput->Name = L"borrowsubinfoinput";
            this->borrowsubinfoinput->Size = System::Drawing::Size(437, 31);
            this->borrowsubinfoinput->TabIndex = 49;
            // 
            // label91
            // 
            this->label91->AutoSize = true;
            this->label91->BackColor = System::Drawing::Color::Transparent;
            this->label91->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label91->ForeColor = System::Drawing::Color::White;
            this->label91->Location = System::Drawing::Point(229, 140);
            this->label91->Name = L"label91";
            this->label91->Size = System::Drawing::Size(89, 31);
            this->label91->TabIndex = 48;
            this->label91->Text = L"Input:";
            // 
            // label90
            // 
            this->label90->AutoSize = true;
            this->label90->BackColor = System::Drawing::Color::Transparent;
            this->label90->Font = (gcnew System::Drawing::Font(L"Arial", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label90->ForeColor = System::Drawing::Color::White;
            this->label90->Location = System::Drawing::Point(335, 101);
            this->label90->Name = L"label90";
            this->label90->Size = System::Drawing::Size(387, 64);
            this->label90->TabIndex = 47;
            this->label90->Text = L"Subscriber id,Subscriber name\r\n\r\n";
            // 
            // label89
            // 
            this->label89->AutoSize = true;
            this->label89->BackColor = System::Drawing::Color::Transparent;
            this->label89->Font = (gcnew System::Drawing::Font(L"Arial", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label89->ForeColor = System::Drawing::Color::White;
            this->label89->Location = System::Drawing::Point(379, 70);
            this->label89->Name = L"label89";
            this->label89->Size = System::Drawing::Size(293, 32);
            this->label89->TabIndex = 46;
            this->label89->Text = L"Enter subscriber info\r\n";
            // 
            // label88
            // 
            this->label88->AutoSize = true;
            this->label88->BackColor = System::Drawing::Color::Transparent;
            this->label88->Font = (gcnew System::Drawing::Font(L"Arial", 30.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label88->ForeColor = System::Drawing::Color::White;
            this->label88->Location = System::Drawing::Point(389, 15);
            this->label88->Name = L"label88";
            this->label88->Size = System::Drawing::Size(271, 47);
            this->label88->TabIndex = 45;
            this->label88->Text = L"Borrow  item";
            // 
            // reselect
            // 
            this->reselect->BackColor = System::Drawing::Color::Red;
            this->reselect->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->reselect->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->reselect->ForeColor = System::Drawing::Color::White;
            this->reselect->Location = System::Drawing::Point(135, 616);
            this->reselect->Name = L"reselect";
            this->reselect->Size = System::Drawing::Size(120, 42);
            this->reselect->TabIndex = 42;
            this->reselect->Text = L"Reselect";
            this->reselect->UseVisualStyleBackColor = false;
            this->reselect->Click += gcnew System::EventHandler(this, &MyForm::reselect_Click_1);
            // 
            // doneselection
            // 
            this->doneselection->BackColor = System::Drawing::Color::Blue;
            this->doneselection->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->doneselection->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->doneselection->ForeColor = System::Drawing::Color::White;
            this->doneselection->Location = System::Drawing::Point(10, 616);
            this->doneselection->Name = L"doneselection";
            this->doneselection->Size = System::Drawing::Size(96, 42);
            this->doneselection->TabIndex = 41;
            this->doneselection->Text = L"Done";
            this->doneselection->UseVisualStyleBackColor = false;
            this->doneselection->Click += gcnew System::EventHandler(this, &MyForm::doneselection_Click_1);
            // 
            // borrowselectedok
            // 
            this->borrowselectedok->BackColor = System::Drawing::Color::DeepSkyBlue;
            this->borrowselectedok->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->borrowselectedok->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->borrowselectedok->Location = System::Drawing::Point(-1013, 578);
            this->borrowselectedok->Name = L"borrowselectedok";
            this->borrowselectedok->Size = System::Drawing::Size(75, 32);
            this->borrowselectedok->TabIndex = 37;
            this->borrowselectedok->Text = L"OK";
            this->borrowselectedok->UseVisualStyleBackColor = false;
            // 
            // label83
            // 
            this->label83->AutoSize = true;
            this->label83->BackColor = System::Drawing::Color::Transparent;
            this->label83->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label83->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label83->Location = System::Drawing::Point(-860, 230);
            this->label83->Name = L"label83";
            this->label83->Size = System::Drawing::Size(653, 31);
            this->label83->TabIndex = 35;
            this->label83->Text = L"Click view list to see the list of items and choose:";
            // 
            // selecteditempnl
            // 
            this->selecteditempnl->AutoSize = true;
            this->selecteditempnl->BackColor = System::Drawing::Color::Transparent;
            this->selecteditempnl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->selecteditempnl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->selecteditempnl->Location = System::Drawing::Point(-988, 284);
            this->selecteditempnl->Name = L"selecteditempnl";
            this->selecteditempnl->Size = System::Drawing::Size(280, 31);
            this->selecteditempnl->TabIndex = 34;
            this->selecteditempnl->Text = L"Your selected items:";
            // 
            // button20
            // 
            this->button20->BackColor = System::Drawing::Color::Gray;
            this->button20->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button20->FlatAppearance->BorderSize = 0;
            this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button20->ForeColor = System::Drawing::Color::White;
            this->button20->Location = System::Drawing::Point(-115, 631);
            this->button20->Name = L"button20";
            this->button20->Size = System::Drawing::Size(107, 60);
            this->button20->TabIndex = 33;
            this->button20->Text = L"Back";
            this->button20->UseVisualStyleBackColor = false;
            // 
            // printlist
            // 
            this->printlist->BackColor = System::Drawing::Color::Red;
            this->printlist->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->printlist->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->printlist->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->printlist->Location = System::Drawing::Point(-308, 264);
            this->printlist->Name = L"printlist";
            this->printlist->Size = System::Drawing::Size(101, 32);
            this->printlist->TabIndex = 32;
            this->printlist->Text = L"View List";
            this->printlist->UseVisualStyleBackColor = false;
            // 
            // oksub
            // 
            this->oksub->BackColor = System::Drawing::Color::DeepSkyBlue;
            this->oksub->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->oksub->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->oksub->Location = System::Drawing::Point(-282, 183);
            this->oksub->Name = L"oksub";
            this->oksub->Size = System::Drawing::Size(75, 32);
            this->oksub->TabIndex = 31;
            this->oksub->Text = L"OK";
            this->oksub->UseVisualStyleBackColor = false;
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel1->Location = System::Drawing::Point(-719, 172);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(512, 5);
            this->panel1->TabIndex = 30;
            // 
            // borrowsubtxt
            // 
            this->borrowsubtxt->BackColor = System::Drawing::Color::Black;
            this->borrowsubtxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->borrowsubtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->borrowsubtxt->ForeColor = System::Drawing::Color::White;
            this->borrowsubtxt->Location = System::Drawing::Point(-719, 142);
            this->borrowsubtxt->Name = L"borrowsubtxt";
            this->borrowsubtxt->Size = System::Drawing::Size(512, 28);
            this->borrowsubtxt->TabIndex = 29;
            // 
            // label51
            // 
            this->label51->AutoSize = true;
            this->label51->BackColor = System::Drawing::Color::Transparent;
            this->label51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label51->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label51->Location = System::Drawing::Point(-814, 142);
            this->label51->Name = L"label51";
            this->label51->Size = System::Drawing::Size(89, 31);
            this->label51->TabIndex = 26;
            this->label51->Text = L"Input:";
            // 
            // label52
            // 
            this->label52->AutoSize = true;
            this->label52->BackColor = System::Drawing::Color::Transparent;
            this->label52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label52->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label52->Location = System::Drawing::Point(-723, 110);
            this->label52->Name = L"label52";
            this->label52->Size = System::Drawing::Size(422, 25);
            this->label52->TabIndex = 25;
            this->label52->Text = L"SUBSCRIBER_ID,SUBSCRIBER_NAME";
            // 
            // label53
            // 
            this->label53->AutoSize = true;
            this->label53->BackColor = System::Drawing::Color::Transparent;
            this->label53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label53->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label53->Location = System::Drawing::Point(-711, 45);
            this->label53->Name = L"label53";
            this->label53->Size = System::Drawing::Size(357, 31);
            this->label53->TabIndex = 24;
            this->label53->Text = L"First enter subscriber info.\r\n";
            // 
            // labelborrow
            // 
            this->labelborrow->AutoSize = true;
            this->labelborrow->BackColor = System::Drawing::Color::Transparent;
            this->labelborrow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->labelborrow->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->labelborrow->Location = System::Drawing::Point(-685, 0);
            this->labelborrow->Name = L"labelborrow";
            this->labelborrow->Size = System::Drawing::Size(311, 47);
            this->labelborrow->TabIndex = 23;
            this->labelborrow->Text = L"Borrow an item";
            // 
            // label96
            // 
            this->label96->AutoSize = true;
            this->label96->BackColor = System::Drawing::Color::Transparent;
            this->label96->Font = (gcnew System::Drawing::Font(L"Arial", 15.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label96->ForeColor = System::Drawing::Color::White;
            this->label96->Location = System::Drawing::Point(381, 190);
            this->label96->Name = L"label96";
            this->label96->Size = System::Drawing::Size(297, 72);
            this->label96->TabIndex = 57;
            this->label96->Text = L"               For multiselect\r\nHold Cntrl+Double Click on row\r\n\r\n";
            // 
            // addeditdelete
            // 
            this->addeditdelete->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addeditdelete.BackgroundImage")));
            this->addeditdelete->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->addeditdelete->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
            this->addeditdelete->Controls->Add(this->deletesubpnl);
            this->addeditdelete->Controls->Add(this->deletebookpnl);
            this->addeditdelete->Controls->Add(this->dletearticlepnl);
            this->addeditdelete->Controls->Add(this->deletedigitalpnl);
            this->addeditdelete->Controls->Add(this->deletelibrarypnl);
            this->addeditdelete->Controls->Add(this->addlib);
            this->addeditdelete->Controls->Add(this->bookadd);
            this->addeditdelete->Controls->Add(this->subadd);
            this->addeditdelete->Controls->Add(this->digitaladd);
            this->addeditdelete->Controls->Add(this->articleadd);
            this->addeditdelete->Controls->Add(this->editarticlepnl);
            this->addeditdelete->Controls->Add(this->editsubscriberpnl);
            this->addeditdelete->Controls->Add(this->editdigitalpnl);
            this->addeditdelete->Controls->Add(this->editlibpnl);
            this->addeditdelete->Controls->Add(this->editbookpnl);
            this->addeditdelete->Controls->Add(this->back);
            this->addeditdelete->Controls->Add(this->deletesubscriber);
            this->addeditdelete->Controls->Add(this->deletelib);
            this->addeditdelete->Controls->Add(this->deletedigital);
            this->addeditdelete->Controls->Add(this->deletarticle);
            this->addeditdelete->Controls->Add(this->deletebook);
            this->addeditdelete->Controls->Add(this->Editlib);
            this->addeditdelete->Controls->Add(this->Editsub);
            this->addeditdelete->Controls->Add(this->editarticle);
            this->addeditdelete->Controls->Add(this->editdigital);
            this->addeditdelete->Controls->Add(this->editBook);
            this->addeditdelete->Controls->Add(this->label5);
            this->addeditdelete->Controls->Add(this->label4);
            this->addeditdelete->Controls->Add(this->label3);
            this->addeditdelete->Controls->Add(this->label2);
            this->addeditdelete->Controls->Add(this->Book);
            this->addeditdelete->Controls->Add(this->addliberary);
            this->addeditdelete->Controls->Add(this->addsubscriber);
            this->addeditdelete->Controls->Add(this->AddArticle);
            this->addeditdelete->Controls->Add(this->AddDigitalMedia);
            this->addeditdelete->Controls->Add(this->Addbook);
            this->addeditdelete->Controls->Add(this->label1);
            this->addeditdelete->Location = System::Drawing::Point(20, 0);
            this->addeditdelete->Margin = System::Windows::Forms::Padding(100);
            this->addeditdelete->Name = L"addeditdelete";
            this->addeditdelete->Size = System::Drawing::Size(1160, 715);
            this->addeditdelete->TabIndex = 6;
            this->addeditdelete->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::addeditdelete_Paint);
            // 
            // deletesubpnl
            // 
            this->deletesubpnl->AutoSize = true;
            this->deletesubpnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deletesubpnl.BackgroundImage")));
            this->deletesubpnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->deletesubpnl->Controls->Add(this->panel5);
            this->deletesubpnl->Controls->Add(this->deletesubtxt);
            this->deletesubpnl->Controls->Add(this->label21);
            this->deletesubpnl->Controls->Add(this->label22);
            this->deletesubpnl->Controls->Add(this->button10);
            this->deletesubpnl->Controls->Add(this->label23);
            this->deletesubpnl->Location = System::Drawing::Point(248, 100);
            this->deletesubpnl->Name = L"deletesubpnl";
            this->deletesubpnl->Size = System::Drawing::Size(624, 429);
            this->deletesubpnl->TabIndex = 54;
            // 
            // panel5
            // 
            this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel5->Location = System::Drawing::Point(112, 235);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(402, 4);
            this->panel5->TabIndex = 43;
            // 
            // deletesubtxt
            // 
            this->deletesubtxt->BackColor = System::Drawing::Color::Black;
            this->deletesubtxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->deletesubtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->deletesubtxt->ForeColor = System::Drawing::Color::White;
            this->deletesubtxt->Location = System::Drawing::Point(109, 208);
            this->deletesubtxt->Name = L"deletesubtxt";
            this->deletesubtxt->Size = System::Drawing::Size(402, 28);
            this->deletesubtxt->TabIndex = 42;
            // 
            // label21
            // 
            this->label21->AutoSize = true;
            this->label21->BackColor = System::Drawing::Color::Transparent;
            this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label21->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label21->Location = System::Drawing::Point(30, 205);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(89, 31);
            this->label21->TabIndex = 41;
            this->label21->Text = L"Input:";
            // 
            // label22
            // 
            this->label22->AutoSize = true;
            this->label22->BackColor = System::Drawing::Color::Transparent;
            this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label22->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label22->Location = System::Drawing::Point(128, 139);
            this->label22->Name = L"label22";
            this->label22->Size = System::Drawing::Size(364, 22);
            this->label22->TabIndex = 40;
            this->label22->Text = L"SUBSCRIBER_ID,SUBSCRIBER_NAME";
            // 
            // button10
            // 
            this->button10->BackColor = System::Drawing::Color::Red;
            this->button10->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button10->FlatAppearance->BorderSize = 0;
            this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button10->ForeColor = System::Drawing::Color::White;
            this->button10->Location = System::Drawing::Point(470, 306);
            this->button10->Name = L"button10";
            this->button10->Size = System::Drawing::Size(113, 38);
            this->button10->TabIndex = 39;
            this->button10->Text = L"Delete";
            this->button10->UseVisualStyleBackColor = false;
            this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click_1);
            // 
            // label23
            // 
            this->label23->AutoSize = true;
            this->label23->BackColor = System::Drawing::Color::Transparent;
            this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label23->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label23->Location = System::Drawing::Point(164, 19);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(296, 31);
            this->label23->TabIndex = 9;
            this->label23->Text = L" Enter Subscriber info\r\n";
            // 
            // deletebookpnl
            // 
            this->deletebookpnl->AutoSize = true;
            this->deletebookpnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deletebookpnl.BackgroundImage")));
            this->deletebookpnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->deletebookpnl->Controls->Add(this->button14);
            this->deletebookpnl->Controls->Add(this->panel20);
            this->deletebookpnl->Controls->Add(this->deletebooktxt);
            this->deletebookpnl->Controls->Add(this->label33);
            this->deletebookpnl->Controls->Add(this->label34);
            this->deletebookpnl->Controls->Add(this->label35);
            this->deletebookpnl->Location = System::Drawing::Point(245, 101);
            this->deletebookpnl->Name = L"deletebookpnl";
            this->deletebookpnl->Size = System::Drawing::Size(624, 429);
            this->deletebookpnl->TabIndex = 53;
            // 
            // button14
            // 
            this->button14->BackColor = System::Drawing::Color::Red;
            this->button14->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button14->FlatAppearance->BorderSize = 0;
            this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button14->ForeColor = System::Drawing::Color::White;
            this->button14->Location = System::Drawing::Point(479, 309);
            this->button14->Name = L"button14";
            this->button14->Size = System::Drawing::Size(113, 38);
            this->button14->TabIndex = 39;
            this->button14->Text = L"Delete";
            this->button14->UseVisualStyleBackColor = false;
            this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
            // 
            // panel20
            // 
            this->panel20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel20->Location = System::Drawing::Point(150, 267);
            this->panel20->Name = L"panel20";
            this->panel20->Size = System::Drawing::Size(402, 4);
            this->panel20->TabIndex = 18;
            // 
            // deletebooktxt
            // 
            this->deletebooktxt->BackColor = System::Drawing::Color::Black;
            this->deletebooktxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->deletebooktxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->deletebooktxt->ForeColor = System::Drawing::Color::White;
            this->deletebooktxt->Location = System::Drawing::Point(147, 240);
            this->deletebooktxt->Name = L"deletebooktxt";
            this->deletebooktxt->Size = System::Drawing::Size(402, 28);
            this->deletebooktxt->TabIndex = 17;
            // 
            // label33
            // 
            this->label33->AutoSize = true;
            this->label33->BackColor = System::Drawing::Color::Transparent;
            this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label33->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label33->Location = System::Drawing::Point(68, 237);
            this->label33->Name = L"label33";
            this->label33->Size = System::Drawing::Size(89, 31);
            this->label33->TabIndex = 11;
            this->label33->Text = L"Input:";
            // 
            // label34
            // 
            this->label34->AutoSize = true;
            this->label34->BackColor = System::Drawing::Color::Transparent;
            this->label34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label34->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label34->Location = System::Drawing::Point(179, 175);
            this->label34->Name = L"label34";
            this->label34->Size = System::Drawing::Size(263, 22);
            this->label34->TabIndex = 10;
            this->label34->Text = L"BOOK Title,BOOK AUTHOR";
            // 
            // label35
            // 
            this->label35->AutoSize = true;
            this->label35->BackColor = System::Drawing::Color::Transparent;
            this->label35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label35->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label35->Location = System::Drawing::Point(207, 15);
            this->label35->Name = L"label35";
            this->label35->Size = System::Drawing::Size(222, 31);
            this->label35->TabIndex = 9;
            this->label35->Text = L" Enter Book info\r\n";
            // 
            // dletearticlepnl
            // 
            this->dletearticlepnl->AutoSize = true;
            this->dletearticlepnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dletearticlepnl.BackgroundImage")));
            this->dletearticlepnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->dletearticlepnl->Controls->Add(this->panel6);
            this->dletearticlepnl->Controls->Add(this->deletearticletxt);
            this->dletearticlepnl->Controls->Add(this->label30);
            this->dletearticlepnl->Controls->Add(this->label31);
            this->dletearticlepnl->Controls->Add(this->button13);
            this->dletearticlepnl->Controls->Add(this->label32);
            this->dletearticlepnl->Location = System::Drawing::Point(243, 103);
            this->dletearticlepnl->Name = L"dletearticlepnl";
            this->dletearticlepnl->Size = System::Drawing::Size(624, 429);
            this->dletearticlepnl->TabIndex = 52;
            // 
            // panel6
            // 
            this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel6->Location = System::Drawing::Point(147, 259);
            this->panel6->Name = L"panel6";
            this->panel6->Size = System::Drawing::Size(402, 4);
            this->panel6->TabIndex = 47;
            // 
            // deletearticletxt
            // 
            this->deletearticletxt->BackColor = System::Drawing::Color::Black;
            this->deletearticletxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->deletearticletxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->deletearticletxt->ForeColor = System::Drawing::Color::White;
            this->deletearticletxt->Location = System::Drawing::Point(144, 232);
            this->deletearticletxt->Name = L"deletearticletxt";
            this->deletearticletxt->Size = System::Drawing::Size(402, 28);
            this->deletearticletxt->TabIndex = 46;
            // 
            // label30
            // 
            this->label30->AutoSize = true;
            this->label30->BackColor = System::Drawing::Color::Transparent;
            this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label30->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label30->Location = System::Drawing::Point(65, 229);
            this->label30->Name = L"label30";
            this->label30->Size = System::Drawing::Size(89, 31);
            this->label30->TabIndex = 45;
            this->label30->Text = L"Input:";
            // 
            // label31
            // 
            this->label31->AutoSize = true;
            this->label31->BackColor = System::Drawing::Color::Transparent;
            this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label31->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label31->Location = System::Drawing::Point(186, 193);
            this->label31->Name = L"label31";
            this->label31->Size = System::Drawing::Size(265, 22);
            this->label31->TabIndex = 44;
            this->label31->Text = L"Article Title,Article AUTHOR";
            // 
            // button13
            // 
            this->button13->BackColor = System::Drawing::Color::Red;
            this->button13->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button13->FlatAppearance->BorderSize = 0;
            this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button13->ForeColor = System::Drawing::Color::White;
            this->button13->Location = System::Drawing::Point(471, 319);
            this->button13->Name = L"button13";
            this->button13->Size = System::Drawing::Size(113, 38);
            this->button13->TabIndex = 39;
            this->button13->Text = L"Delete";
            this->button13->UseVisualStyleBackColor = false;
            this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
            // 
            // label32
            // 
            this->label32->AutoSize = true;
            this->label32->BackColor = System::Drawing::Color::Transparent;
            this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label32->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label32->Location = System::Drawing::Point(214, 18);
            this->label32->Name = L"label32";
            this->label32->Size = System::Drawing::Size(239, 31);
            this->label32->TabIndex = 9;
            this->label32->Text = L" Enter Article info\r\n";
            // 
            // deletedigitalpnl
            // 
            this->deletedigitalpnl->AutoSize = true;
            this->deletedigitalpnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deletedigitalpnl.BackgroundImage")));
            this->deletedigitalpnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->deletedigitalpnl->Controls->Add(this->panel8);
            this->deletedigitalpnl->Controls->Add(this->deletedigitaltxt);
            this->deletedigitalpnl->Controls->Add(this->label27);
            this->deletedigitalpnl->Controls->Add(this->label28);
            this->deletedigitalpnl->Controls->Add(this->button12);
            this->deletedigitalpnl->Controls->Add(this->label29);
            this->deletedigitalpnl->Location = System::Drawing::Point(240, 106);
            this->deletedigitalpnl->Name = L"deletedigitalpnl";
            this->deletedigitalpnl->Size = System::Drawing::Size(624, 429);
            this->deletedigitalpnl->TabIndex = 51;
            // 
            // panel8
            // 
            this->panel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel8->Location = System::Drawing::Point(117, 238);
            this->panel8->Name = L"panel8";
            this->panel8->Size = System::Drawing::Size(466, 4);
            this->panel8->TabIndex = 47;
            // 
            // deletedigitaltxt
            // 
            this->deletedigitaltxt->BackColor = System::Drawing::Color::Black;
            this->deletedigitaltxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->deletedigitaltxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->deletedigitaltxt->ForeColor = System::Drawing::Color::White;
            this->deletedigitaltxt->Location = System::Drawing::Point(114, 211);
            this->deletedigitaltxt->Name = L"deletedigitaltxt";
            this->deletedigitaltxt->Size = System::Drawing::Size(466, 28);
            this->deletedigitaltxt->TabIndex = 46;
            // 
            // label27
            // 
            this->label27->AutoSize = true;
            this->label27->BackColor = System::Drawing::Color::Transparent;
            this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label27->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label27->Location = System::Drawing::Point(35, 208);
            this->label27->Name = L"label27";
            this->label27->Size = System::Drawing::Size(89, 31);
            this->label27->TabIndex = 45;
            this->label27->Text = L"Input:";
            // 
            // label28
            // 
            this->label28->AutoSize = true;
            this->label28->BackColor = System::Drawing::Color::Transparent;
            this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label28->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label28->Location = System::Drawing::Point(116, 165);
            this->label28->Name = L"label28";
            this->label28->Size = System::Drawing::Size(404, 22);
            this->label28->TabIndex = 44;
            this->label28->Text = L"DigitalMEDIA Title,DIGITALMEDIA AUTHOR";
            // 
            // button12
            // 
            this->button12->BackColor = System::Drawing::Color::Red;
            this->button12->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button12->FlatAppearance->BorderSize = 0;
            this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button12->ForeColor = System::Drawing::Color::White;
            this->button12->Location = System::Drawing::Point(476, 298);
            this->button12->Name = L"button12";
            this->button12->Size = System::Drawing::Size(113, 38);
            this->button12->TabIndex = 39;
            this->button12->Text = L"Delete";
            this->button12->UseVisualStyleBackColor = false;
            this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
            // 
            // label29
            // 
            this->label29->AutoSize = true;
            this->label29->BackColor = System::Drawing::Color::Transparent;
            this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label29->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label29->Location = System::Drawing::Point(168, 8);
            this->label29->Name = L"label29";
            this->label29->Size = System::Drawing::Size(325, 31);
            this->label29->TabIndex = 9;
            this->label29->Text = L" Enter Digital media info\r\n";
            // 
            // deletelibrarypnl
            // 
            this->deletelibrarypnl->AutoSize = true;
            this->deletelibrarypnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deletelibrarypnl.BackgroundImage")));
            this->deletelibrarypnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->deletelibrarypnl->Controls->Add(this->panel9);
            this->deletelibrarypnl->Controls->Add(this->deletelibtxt);
            this->deletelibrarypnl->Controls->Add(this->label24);
            this->deletelibrarypnl->Controls->Add(this->label25);
            this->deletelibrarypnl->Controls->Add(this->button11);
            this->deletelibrarypnl->Controls->Add(this->label26);
            this->deletelibrarypnl->Location = System::Drawing::Point(237, 108);
            this->deletelibrarypnl->Name = L"deletelibrarypnl";
            this->deletelibrarypnl->Size = System::Drawing::Size(624, 429);
            this->deletelibrarypnl->TabIndex = 50;
            // 
            // panel9
            // 
            this->panel9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel9->Location = System::Drawing::Point(86, 270);
            this->panel9->Name = L"panel9";
            this->panel9->Size = System::Drawing::Size(487, 4);
            this->panel9->TabIndex = 47;
            // 
            // deletelibtxt
            // 
            this->deletelibtxt->BackColor = System::Drawing::Color::Black;
            this->deletelibtxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->deletelibtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->deletelibtxt->ForeColor = System::Drawing::Color::White;
            this->deletelibtxt->Location = System::Drawing::Point(83, 243);
            this->deletelibtxt->Name = L"deletelibtxt";
            this->deletelibtxt->Size = System::Drawing::Size(487, 28);
            this->deletelibtxt->TabIndex = 46;
            // 
            // label24
            // 
            this->label24->AutoSize = true;
            this->label24->BackColor = System::Drawing::Color::Transparent;
            this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label24->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label24->Location = System::Drawing::Point(4, 240);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(89, 31);
            this->label24->TabIndex = 45;
            this->label24->Text = L"Input:";
            // 
            // label25
            // 
            this->label25->AutoSize = true;
            this->label25->BackColor = System::Drawing::Color::Transparent;
            this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label25->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label25->Location = System::Drawing::Point(150, 183);
            this->label25->Name = L"label25";
            this->label25->Size = System::Drawing::Size(278, 22);
            this->label25->TabIndex = 44;
            this->label25->Text = L"LIBRARY_ID,LIBRARY_NAME";
            // 
            // button11
            // 
            this->button11->BackColor = System::Drawing::Color::Red;
            this->button11->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button11->FlatAppearance->BorderSize = 0;
            this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button11->ForeColor = System::Drawing::Color::White;
            this->button11->Location = System::Drawing::Point(463, 325);
            this->button11->Name = L"button11";
            this->button11->Size = System::Drawing::Size(113, 38);
            this->button11->TabIndex = 39;
            this->button11->Text = L"Delete";
            this->button11->UseVisualStyleBackColor = false;
            this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
            // 
            // label26
            // 
            this->label26->AutoSize = true;
            this->label26->BackColor = System::Drawing::Color::Transparent;
            this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label26->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label26->Location = System::Drawing::Point(178, 36);
            this->label26->Name = L"label26";
            this->label26->Size = System::Drawing::Size(248, 31);
            this->label26->TabIndex = 9;
            this->label26->Text = L" Enter LIbrary info\r\n";
            // 
            // addlib
            // 
            this->addlib->AutoSize = true;
            this->addlib->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addlib.BackgroundImage")));
            this->addlib->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->addlib->Controls->Add(this->addlibbtn);
            this->addlib->Controls->Add(this->panel4);
            this->addlib->Controls->Add(this->addlibtxt);
            this->addlib->Controls->Add(this->label6);
            this->addlib->Controls->Add(this->label7);
            this->addlib->Controls->Add(this->label8);
            this->addlib->Location = System::Drawing::Point(279, 72);
            this->addlib->Name = L"addlib";
            this->addlib->Size = System::Drawing::Size(624, 429);
            this->addlib->TabIndex = 7;
            // 
            // addlibbtn
            // 
            this->addlibbtn->BackColor = System::Drawing::Color::Blue;
            this->addlibbtn->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->addlibbtn->FlatAppearance->BorderSize = 0;
            this->addlibbtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->addlibbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addlibbtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->addlibbtn->Location = System::Drawing::Point(421, 256);
            this->addlibbtn->Name = L"addlibbtn";
            this->addlibbtn->Size = System::Drawing::Size(103, 43);
            this->addlibbtn->TabIndex = 27;
            this->addlibbtn->Text = L"Add";
            this->addlibbtn->UseVisualStyleBackColor = false;
            this->addlibbtn->Click += gcnew System::EventHandler(this, &MyForm::addlibbtn_Click);
            // 
            // panel4
            // 
            this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel4->Location = System::Drawing::Point(143, 239);
            this->panel4->Name = L"panel4";
            this->panel4->Size = System::Drawing::Size(358, 4);
            this->panel4->TabIndex = 18;
            // 
            // addlibtxt
            // 
            this->addlibtxt->BackColor = System::Drawing::Color::Black;
            this->addlibtxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->addlibtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addlibtxt->ForeColor = System::Drawing::Color::White;
            this->addlibtxt->Location = System::Drawing::Point(140, 212);
            this->addlibtxt->Name = L"addlibtxt";
            this->addlibtxt->Size = System::Drawing::Size(358, 28);
            this->addlibtxt->TabIndex = 17;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::Color::Transparent;
            this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label6->Location = System::Drawing::Point(61, 209);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(97, 31);
            this->label6->TabIndex = 11;
            this->label6->Text = L"Input: ";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->BackColor = System::Drawing::Color::Transparent;
            this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label7->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label7->Location = System::Drawing::Point(198, 158);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(278, 22);
            this->label7->TabIndex = 10;
            this->label7->Text = L"LIBRARY_ID,LIBRARY_NAME";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->BackColor = System::Drawing::Color::Transparent;
            this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label8->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label8->Location = System::Drawing::Point(196, 20);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(246, 31);
            this->label8->TabIndex = 9;
            this->label8->Text = L" Enter Library info\r\n";
            // 
            // bookadd
            // 
            this->bookadd->AutoSize = true;
            this->bookadd->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bookadd.BackgroundImage")));
            this->bookadd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->bookadd->Controls->Add(this->btnbookadd);
            this->bookadd->Controls->Add(this->panel13);
            this->bookadd->Controls->Add(this->addbooktext);
            this->bookadd->Controls->Add(this->label18);
            this->bookadd->Controls->Add(this->label19);
            this->bookadd->Controls->Add(this->label20);
            this->bookadd->Location = System::Drawing::Point(273, 77);
            this->bookadd->Name = L"bookadd";
            this->bookadd->Size = System::Drawing::Size(624, 429);
            this->bookadd->TabIndex = 47;
            // 
            // btnbookadd
            // 
            this->btnbookadd->BackColor = System::Drawing::Color::Blue;
            this->btnbookadd->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->btnbookadd->FlatAppearance->BorderSize = 0;
            this->btnbookadd->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnbookadd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnbookadd->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->btnbookadd->Location = System::Drawing::Point(489, 308);
            this->btnbookadd->Name = L"btnbookadd";
            this->btnbookadd->Size = System::Drawing::Size(103, 43);
            this->btnbookadd->TabIndex = 28;
            this->btnbookadd->Text = L"Add";
            this->btnbookadd->UseVisualStyleBackColor = false;
            this->btnbookadd->Click += gcnew System::EventHandler(this, &MyForm::btnbookadd_Click);
            // 
            // panel13
            // 
            this->panel13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel13->Location = System::Drawing::Point(116, 257);
            this->panel13->Name = L"panel13";
            this->panel13->Size = System::Drawing::Size(488, 4);
            this->panel13->TabIndex = 18;
            // 
            // addbooktext
            // 
            this->addbooktext->BackColor = System::Drawing::Color::Black;
            this->addbooktext->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->addbooktext->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addbooktext->ForeColor = System::Drawing::Color::White;
            this->addbooktext->Location = System::Drawing::Point(113, 230);
            this->addbooktext->Name = L"addbooktext";
            this->addbooktext->Size = System::Drawing::Size(488, 28);
            this->addbooktext->TabIndex = 17;
            // 
            // label18
            // 
            this->label18->AutoSize = true;
            this->label18->BackColor = System::Drawing::Color::Transparent;
            this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label18->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label18->Location = System::Drawing::Point(32, 227);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(97, 31);
            this->label18->TabIndex = 11;
            this->label18->Text = L"Input: ";
            // 
            // label19
            // 
            this->label19->AutoSize = true;
            this->label19->BackColor = System::Drawing::Color::Transparent;
            this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label19->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label19->Location = System::Drawing::Point(108, 137);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(446, 51);
            this->label19->TabIndex = 10;
            this->label19->Text = L"LIBRARY_ID,LIBRARY_NAME,BOOK_TITLE,\r\nBOOK_AUTHOR,BOOK_PUBLISHER,\r\nBOOK_STATUS,BOO"
                L"K_PRODUCTION_YEAR,BOOK_COPIES";
            // 
            // label20
            // 
            this->label20->AutoSize = true;
            this->label20->BackColor = System::Drawing::Color::Transparent;
            this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label20->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label20->Location = System::Drawing::Point(206, 38);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(222, 31);
            this->label20->TabIndex = 9;
            this->label20->Text = L" Enter Book info\r\n";
            // 
            // subadd
            // 
            this->subadd->AutoSize = true;
            this->subadd->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"subadd.BackgroundImage")));
            this->subadd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->subadd->Controls->Add(this->panel2);
            this->subadd->Controls->Add(this->addsubtxt);
            this->subadd->Controls->Add(this->label9);
            this->subadd->Controls->Add(this->label10);
            this->subadd->Controls->Add(this->button6);
            this->subadd->Controls->Add(this->label11);
            this->subadd->Location = System::Drawing::Point(276, 74);
            this->subadd->Name = L"subadd";
            this->subadd->Size = System::Drawing::Size(624, 429);
            this->subadd->TabIndex = 48;
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel2->Location = System::Drawing::Point(113, 226);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(497, 4);
            this->panel2->TabIndex = 31;
            // 
            // addsubtxt
            // 
            this->addsubtxt->BackColor = System::Drawing::Color::Black;
            this->addsubtxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->addsubtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubtxt->ForeColor = System::Drawing::Color::White;
            this->addsubtxt->Location = System::Drawing::Point(110, 199);
            this->addsubtxt->Name = L"addsubtxt";
            this->addsubtxt->Size = System::Drawing::Size(497, 28);
            this->addsubtxt->TabIndex = 30;
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->BackColor = System::Drawing::Color::Transparent;
            this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label9->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label9->Location = System::Drawing::Point(29, 196);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(97, 31);
            this->label9->TabIndex = 29;
            this->label9->Text = L"Input: ";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->BackColor = System::Drawing::Color::Transparent;
            this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label10->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label10->Location = System::Drawing::Point(110, 114);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(439, 51);
            this->label10->TabIndex = 28;
            this->label10->Text = L"SUBSCRIBER_ID,SUBSCRIBER_TYPE,SUBSCRIBER_NAME,\r\nSUBSCRIBER_ADDRESS,SUBSCRIBER_PHO"
                L"NE_NO,\r\nSUBSCRIBER_EMAIL";
            // 
            // button6
            // 
            this->button6->BackColor = System::Drawing::Color::Blue;
            this->button6->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button6->FlatAppearance->BorderSize = 0;
            this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->button6->Location = System::Drawing::Point(495, 296);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(103, 43);
            this->button6->TabIndex = 27;
            this->button6->Text = L"Add";
            this->button6->UseVisualStyleBackColor = false;
            this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->BackColor = System::Drawing::Color::Transparent;
            this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label11->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label11->Location = System::Drawing::Point(162, 6);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(296, 31);
            this->label11->TabIndex = 9;
            this->label11->Text = L" Enter Subscriber info\r\n";
            // 
            // digitaladd
            // 
            this->digitaladd->AutoSize = true;
            this->digitaladd->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"digitaladd.BackgroundImage")));
            this->digitaladd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->digitaladd->Controls->Add(this->panel7);
            this->digitaladd->Controls->Add(this->adddigitaltxt);
            this->digitaladd->Controls->Add(this->label12);
            this->digitaladd->Controls->Add(this->label13);
            this->digitaladd->Controls->Add(this->button7);
            this->digitaladd->Controls->Add(this->label14);
            this->digitaladd->Location = System::Drawing::Point(270, 80);
            this->digitaladd->Name = L"digitaladd";
            this->digitaladd->Size = System::Drawing::Size(624, 429);
            this->digitaladd->TabIndex = 45;
            // 
            // panel7
            // 
            this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel7->Location = System::Drawing::Point(96, 242);
            this->panel7->Name = L"panel7";
            this->panel7->Size = System::Drawing::Size(505, 4);
            this->panel7->TabIndex = 31;
            // 
            // adddigitaltxt
            // 
            this->adddigitaltxt->BackColor = System::Drawing::Color::Black;
            this->adddigitaltxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->adddigitaltxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->adddigitaltxt->ForeColor = System::Drawing::Color::White;
            this->adddigitaltxt->Location = System::Drawing::Point(93, 215);
            this->adddigitaltxt->Name = L"adddigitaltxt";
            this->adddigitaltxt->Size = System::Drawing::Size(505, 28);
            this->adddigitaltxt->TabIndex = 30;
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->BackColor = System::Drawing::Color::Transparent;
            this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label12->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label12->Location = System::Drawing::Point(12, 212);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(97, 31);
            this->label12->TabIndex = 29;
            this->label12->Text = L"Input: ";
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->BackColor = System::Drawing::Color::Transparent;
            this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label13->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label13->Location = System::Drawing::Point(93, 130);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(458, 51);
            this->label13->TabIndex = 28;
            this->label13->Text = L"LIBRARY_ID,LIBRARY_NAME,DIGITALMEDIA_TITLE,AUTHOR,\r\nDIGITALMEDIA_PUBLISHER,DIGITA"
                L"LMEDIA_STATUS,\r\nDIGITALMEDIA_PRODUCTION_YEAR,DIGITALMEDIA_COPIES";
            // 
            // button7
            // 
            this->button7->BackColor = System::Drawing::Color::Blue;
            this->button7->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button7->FlatAppearance->BorderSize = 0;
            this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button7->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->button7->Location = System::Drawing::Point(474, 318);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(103, 43);
            this->button7->TabIndex = 27;
            this->button7->Text = L"Add";
            this->button7->UseVisualStyleBackColor = false;
            this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->BackColor = System::Drawing::Color::Transparent;
            this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label14->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label14->Location = System::Drawing::Point(148, 17);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(325, 31);
            this->label14->TabIndex = 9;
            this->label14->Text = L" Enter Digital Media info\r\n";
            // 
            // articleadd
            // 
            this->articleadd->AutoSize = true;
            this->articleadd->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"articleadd.BackgroundImage")));
            this->articleadd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->articleadd->Controls->Add(this->panel10);
            this->articleadd->Controls->Add(this->addarticleinputtxt);
            this->articleadd->Controls->Add(this->label15);
            this->articleadd->Controls->Add(this->label16);
            this->articleadd->Controls->Add(this->button8);
            this->articleadd->Controls->Add(this->label17);
            this->articleadd->Location = System::Drawing::Point(267, 82);
            this->articleadd->Name = L"articleadd";
            this->articleadd->Size = System::Drawing::Size(624, 429);
            this->articleadd->TabIndex = 46;
            // 
            // panel10
            // 
            this->panel10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel10->Location = System::Drawing::Point(102, 244);
            this->panel10->Name = L"panel10";
            this->panel10->Size = System::Drawing::Size(490, 4);
            this->panel10->TabIndex = 31;
            // 
            // addarticleinputtxt
            // 
            this->addarticleinputtxt->BackColor = System::Drawing::Color::Black;
            this->addarticleinputtxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->addarticleinputtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addarticleinputtxt->ForeColor = System::Drawing::Color::White;
            this->addarticleinputtxt->Location = System::Drawing::Point(99, 217);
            this->addarticleinputtxt->Name = L"addarticleinputtxt";
            this->addarticleinputtxt->Size = System::Drawing::Size(490, 28);
            this->addarticleinputtxt->TabIndex = 30;
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->BackColor = System::Drawing::Color::Transparent;
            this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label15->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label15->Location = System::Drawing::Point(18, 214);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(97, 31);
            this->label15->TabIndex = 29;
            this->label15->Text = L"Input: ";
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->BackColor = System::Drawing::Color::Transparent;
            this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label16->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label16->Location = System::Drawing::Point(92, 121);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(488, 51);
            this->label16->TabIndex = 28;
            this->label16->Text = L"LIBRARY_ID,LIBRARY_NAME,ARTICLE_TITLE,ARTICLE_AUTHOR,\r\nARTICLE_PUBLISHER,ARTICLE_"
                L"STATUS,\r\nARTICLE_PRODUCTION_YEAR,ARTICLE_COPIES";
            // 
            // button8
            // 
            this->button8->BackColor = System::Drawing::Color::Blue;
            this->button8->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button8->FlatAppearance->BorderSize = 0;
            this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button8->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->button8->Location = System::Drawing::Point(486, 310);
            this->button8->Name = L"button8";
            this->button8->Size = System::Drawing::Size(103, 43);
            this->button8->TabIndex = 27;
            this->button8->Text = L"Add";
            this->button8->UseVisualStyleBackColor = false;
            this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->BackColor = System::Drawing::Color::Transparent;
            this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label17->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label17->Location = System::Drawing::Point(201, 11);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(239, 31);
            this->label17->TabIndex = 9;
            this->label17->Text = L" Enter Article info\r\n";
            // 
            // editarticlepnl
            // 
            this->editarticlepnl->AutoSize = true;
            this->editarticlepnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editarticlepnl.BackgroundImage")));
            this->editarticlepnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->editarticlepnl->Controls->Add(this->label64);
            this->editarticlepnl->Controls->Add(this->label58);
            this->editarticlepnl->Controls->Add(this->panel11);
            this->editarticlepnl->Controls->Add(this->newarticletxt);
            this->editarticlepnl->Controls->Add(this->label59);
            this->editarticlepnl->Controls->Add(this->label60);
            this->editarticlepnl->Controls->Add(this->button25);
            this->editarticlepnl->Controls->Add(this->panel12);
            this->editarticlepnl->Controls->Add(this->editartricletxt);
            this->editarticlepnl->Controls->Add(this->label61);
            this->editarticlepnl->Controls->Add(this->button18);
            this->editarticlepnl->Controls->Add(this->label47);
            this->editarticlepnl->Location = System::Drawing::Point(260, 88);
            this->editarticlepnl->Name = L"editarticlepnl";
            this->editarticlepnl->Size = System::Drawing::Size(624, 429);
            this->editarticlepnl->TabIndex = 58;
            // 
            // label64
            // 
            this->label64->AutoSize = true;
            this->label64->BackColor = System::Drawing::Color::Transparent;
            this->label64->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label64->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label64->Location = System::Drawing::Point(163, 55);
            this->label64->Name = L"label64";
            this->label64->Size = System::Drawing::Size(267, 17);
            this->label64->TabIndex = 50;
            this->label64->Text = L"ARTICLE_TITLE,ARTICLE_AUTHOR";
            // 
            // label58
            // 
            this->label58->AutoSize = true;
            this->label58->BackColor = System::Drawing::Color::Transparent;
            this->label58->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label58->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label58->Location = System::Drawing::Point(160, 192);
            this->label58->Name = L"label58";
            this->label58->Size = System::Drawing::Size(247, 31);
            this->label58->TabIndex = 49;
            this->label58->Text = L" Enter Article info ";
            // 
            // panel11
            // 
            this->panel11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel11->Location = System::Drawing::Point(140, 345);
            this->panel11->Name = L"panel11";
            this->panel11->Size = System::Drawing::Size(403, 4);
            this->panel11->TabIndex = 48;
            // 
            // newarticletxt
            // 
            this->newarticletxt->BackColor = System::Drawing::Color::Black;
            this->newarticletxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->newarticletxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->newarticletxt->ForeColor = System::Drawing::Color::White;
            this->newarticletxt->Location = System::Drawing::Point(137, 318);
            this->newarticletxt->Name = L"newarticletxt";
            this->newarticletxt->Size = System::Drawing::Size(403, 28);
            this->newarticletxt->TabIndex = 47;
            this->newarticletxt->TextChanged += gcnew System::EventHandler(this, &MyForm::newarticletxt_TextChanged);
            // 
            // label59
            // 
            this->label59->AutoSize = true;
            this->label59->BackColor = System::Drawing::Color::Transparent;
            this->label59->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label59->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label59->Location = System::Drawing::Point(56, 315);
            this->label59->Name = L"label59";
            this->label59->Size = System::Drawing::Size(97, 31);
            this->label59->TabIndex = 46;
            this->label59->Text = L"Input: ";
            // 
            // label60
            // 
            this->label60->AutoSize = true;
            this->label60->BackColor = System::Drawing::Color::Transparent;
            this->label60->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label60->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label60->Location = System::Drawing::Point(132, 251);
            this->label60->Name = L"label60";
            this->label60->Size = System::Drawing::Size(436, 51);
            this->label60->TabIndex = 45;
            this->label60->Text = L"ARTICLE_TITLE,ARTICLE_AUTHOR,ARTICLE_PUBLISHER,\r\nARTICLE_STATUS,ARTICLE_PRODUCTIO"
                L"N_YEAR,\r\nARTICLE_COPIES";
            // 
            // button25
            // 
            this->button25->BackColor = System::Drawing::Color::Blue;
            this->button25->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button25->FlatAppearance->BorderSize = 0;
            this->button25->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button25->ForeColor = System::Drawing::Color::White;
            this->button25->Location = System::Drawing::Point(426, 133);
            this->button25->Name = L"button25";
            this->button25->Size = System::Drawing::Size(104, 38);
            this->button25->TabIndex = 44;
            this->button25->Text = L"OK";
            this->button25->UseVisualStyleBackColor = false;
            this->button25->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
            // 
            // panel12
            // 
            this->panel12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel12->Location = System::Drawing::Point(128, 123);
            this->panel12->Name = L"panel12";
            this->panel12->Size = System::Drawing::Size(414, 4);
            this->panel12->TabIndex = 43;
            // 
            // editartricletxt
            // 
            this->editartricletxt->BackColor = System::Drawing::Color::Black;
            this->editartricletxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editartricletxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editartricletxt->ForeColor = System::Drawing::Color::White;
            this->editartricletxt->Location = System::Drawing::Point(125, 96);
            this->editartricletxt->Name = L"editartricletxt";
            this->editartricletxt->Size = System::Drawing::Size(414, 28);
            this->editartricletxt->TabIndex = 42;
            // 
            // label61
            // 
            this->label61->AutoSize = true;
            this->label61->BackColor = System::Drawing::Color::Transparent;
            this->label61->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label61->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label61->Location = System::Drawing::Point(47, 93);
            this->label61->Name = L"label61";
            this->label61->Size = System::Drawing::Size(97, 31);
            this->label61->TabIndex = 41;
            this->label61->Text = L"Input: ";
            // 
            // button18
            // 
            this->button18->BackColor = System::Drawing::Color::Fuchsia;
            this->button18->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button18->FlatAppearance->BorderSize = 0;
            this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button18->ForeColor = System::Drawing::Color::White;
            this->button18->Location = System::Drawing::Point(455, 365);
            this->button18->Name = L"button18";
            this->button18->Size = System::Drawing::Size(104, 38);
            this->button18->TabIndex = 34;
            this->button18->Text = L"Edit";
            this->button18->UseVisualStyleBackColor = false;
            this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
            // 
            // label47
            // 
            this->label47->AutoSize = true;
            this->label47->BackColor = System::Drawing::Color::Transparent;
            this->label47->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label47->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label47->Location = System::Drawing::Point(131, 4);
            this->label47->Name = L"label47";
            this->label47->Size = System::Drawing::Size(328, 31);
            this->label47->TabIndex = 9;
            this->label47->Text = L" Enter Article info to edit\r\n";
            // 
            // editsubscriberpnl
            // 
            this->editsubscriberpnl->AutoSize = true;
            this->editsubscriberpnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editsubscriberpnl.BackgroundImage")));
            this->editsubscriberpnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->editsubscriberpnl->Controls->Add(this->label36);
            this->editsubscriberpnl->Controls->Add(this->label37);
            this->editsubscriberpnl->Controls->Add(this->panel18);
            this->editsubscriberpnl->Controls->Add(this->newsubtxt);
            this->editsubscriberpnl->Controls->Add(this->label67);
            this->editsubscriberpnl->Controls->Add(this->label68);
            this->editsubscriberpnl->Controls->Add(this->button28);
            this->editsubscriberpnl->Controls->Add(this->panel19);
            this->editsubscriberpnl->Controls->Add(this->editsubtxt);
            this->editsubscriberpnl->Controls->Add(this->label69);
            this->editsubscriberpnl->Controls->Add(this->button15);
            this->editsubscriberpnl->Controls->Add(this->label38);
            this->editsubscriberpnl->Location = System::Drawing::Point(252, 97);
            this->editsubscriberpnl->Name = L"editsubscriberpnl";
            this->editsubscriberpnl->Size = System::Drawing::Size(572, 429);
            this->editsubscriberpnl->TabIndex = 56;
            // 
            // label36
            // 
            this->label36->AutoSize = true;
            this->label36->BackColor = System::Drawing::Color::Transparent;
            this->label36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label36->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label36->Location = System::Drawing::Point(153, 60);
            this->label36->Name = L"label36";
            this->label36->Size = System::Drawing::Size(283, 17);
            this->label36->TabIndex = 69;
            this->label36->Text = L"SUBSCRIBER_ID,SUBSCRIBER_NAME";
            // 
            // label37
            // 
            this->label37->AutoSize = true;
            this->label37->BackColor = System::Drawing::Color::Transparent;
            this->label37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label37->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label37->Location = System::Drawing::Point(119, 212);
            this->label37->Name = L"label37";
            this->label37->Size = System::Drawing::Size(296, 31);
            this->label37->TabIndex = 68;
            this->label37->Text = L" Enter Subscriber info\r\n";
            // 
            // panel18
            // 
            this->panel18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel18->Location = System::Drawing::Point(125, 364);
            this->panel18->Name = L"panel18";
            this->panel18->Size = System::Drawing::Size(403, 4);
            this->panel18->TabIndex = 67;
            // 
            // newsubtxt
            // 
            this->newsubtxt->BackColor = System::Drawing::Color::Black;
            this->newsubtxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->newsubtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->newsubtxt->ForeColor = System::Drawing::Color::White;
            this->newsubtxt->Location = System::Drawing::Point(122, 337);
            this->newsubtxt->Name = L"newsubtxt";
            this->newsubtxt->Size = System::Drawing::Size(403, 28);
            this->newsubtxt->TabIndex = 66;
            this->newsubtxt->TextChanged += gcnew System::EventHandler(this, &MyForm::newsubtxt_TextChanged);
            // 
            // label67
            // 
            this->label67->AutoSize = true;
            this->label67->BackColor = System::Drawing::Color::Transparent;
            this->label67->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label67->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label67->Location = System::Drawing::Point(41, 334);
            this->label67->Name = L"label67";
            this->label67->Size = System::Drawing::Size(97, 31);
            this->label67->TabIndex = 65;
            this->label67->Text = L"Input: ";
            // 
            // label68
            // 
            this->label68->AutoSize = true;
            this->label68->BackColor = System::Drawing::Color::Transparent;
            this->label68->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label68->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label68->Location = System::Drawing::Point(76, 256);
            this->label68->Name = L"label68";
            this->label68->Size = System::Drawing::Size(439, 51);
            this->label68->TabIndex = 64;
            this->label68->Text = L"SUBSCRIBER_ID,SUBSCRIBER_TYPE,SUBSCRIBER_NAME,\r\nSUBSCRIBER_ADDRESS,SUBSCRIBER_PHO"
                L"NE_NO,\r\nSUBSCRIBER_EMAIL";
            // 
            // button28
            // 
            this->button28->BackColor = System::Drawing::Color::Blue;
            this->button28->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button28->FlatAppearance->BorderSize = 0;
            this->button28->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button28->ForeColor = System::Drawing::Color::White;
            this->button28->Location = System::Drawing::Point(411, 152);
            this->button28->Name = L"button28";
            this->button28->Size = System::Drawing::Size(104, 38);
            this->button28->TabIndex = 63;
            this->button28->Text = L"OK";
            this->button28->UseVisualStyleBackColor = false;
            this->button28->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
            // 
            // panel19
            // 
            this->panel19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel19->Location = System::Drawing::Point(113, 142);
            this->panel19->Name = L"panel19";
            this->panel19->Size = System::Drawing::Size(414, 4);
            this->panel19->TabIndex = 62;
            // 
            // editsubtxt
            // 
            this->editsubtxt->BackColor = System::Drawing::Color::Black;
            this->editsubtxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editsubtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubtxt->ForeColor = System::Drawing::Color::White;
            this->editsubtxt->Location = System::Drawing::Point(110, 115);
            this->editsubtxt->Name = L"editsubtxt";
            this->editsubtxt->Size = System::Drawing::Size(414, 28);
            this->editsubtxt->TabIndex = 61;
            // 
            // label69
            // 
            this->label69->AutoSize = true;
            this->label69->BackColor = System::Drawing::Color::Transparent;
            this->label69->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label69->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label69->Location = System::Drawing::Point(32, 112);
            this->label69->Name = L"label69";
            this->label69->Size = System::Drawing::Size(97, 31);
            this->label69->TabIndex = 60;
            this->label69->Text = L"Input: ";
            // 
            // button15
            // 
            this->button15->BackColor = System::Drawing::Color::Fuchsia;
            this->button15->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button15->FlatAppearance->BorderSize = 0;
            this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button15->ForeColor = System::Drawing::Color::White;
            this->button15->Location = System::Drawing::Point(426, 379);
            this->button15->Name = L"button15";
            this->button15->Size = System::Drawing::Size(104, 38);
            this->button15->TabIndex = 34;
            this->button15->Text = L"Edit";
            this->button15->UseVisualStyleBackColor = false;
            this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click_1);
            // 
            // label38
            // 
            this->label38->AutoSize = true;
            this->label38->BackColor = System::Drawing::Color::Transparent;
            this->label38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label38->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label38->Location = System::Drawing::Point(131, 4);
            this->label38->Name = L"label38";
            this->label38->Size = System::Drawing::Size(296, 31);
            this->label38->TabIndex = 9;
            this->label38->Text = L" Enter Subscriber info\r\n";
            // 
            // editdigitalpnl
            // 
            this->editdigitalpnl->AutoSize = true;
            this->editdigitalpnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editdigitalpnl.BackgroundImage")));
            this->editdigitalpnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->editdigitalpnl->Controls->Add(this->label66);
            this->editdigitalpnl->Controls->Add(this->label42);
            this->editdigitalpnl->Controls->Add(this->panel16);
            this->editdigitalpnl->Controls->Add(this->newdigitaltxt);
            this->editdigitalpnl->Controls->Add(this->label43);
            this->editdigitalpnl->Controls->Add(this->label62);
            this->editdigitalpnl->Controls->Add(this->button27);
            this->editdigitalpnl->Controls->Add(this->panel17);
            this->editdigitalpnl->Controls->Add(this->editdigitaltxt);
            this->editdigitalpnl->Controls->Add(this->label63);
            this->editdigitalpnl->Controls->Add(this->button17);
            this->editdigitalpnl->Controls->Add(this->label44);
            this->editdigitalpnl->Location = System::Drawing::Point(255, 94);
            this->editdigitalpnl->Name = L"editdigitalpnl";
            this->editdigitalpnl->Size = System::Drawing::Size(572, 429);
            this->editdigitalpnl->TabIndex = 57;
            // 
            // label66
            // 
            this->label66->AutoSize = true;
            this->label66->BackColor = System::Drawing::Color::Transparent;
            this->label66->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label66->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label66->Location = System::Drawing::Point(163, 67);
            this->label66->Name = L"label66";
            this->label66->Size = System::Drawing::Size(259, 17);
            this->label66->TabIndex = 59;
            this->label66->Text = L"DIGITAL_TITLE,DIGITAL_AUTHOR";
            // 
            // label42
            // 
            this->label42->AutoSize = true;
            this->label42->BackColor = System::Drawing::Color::Transparent;
            this->label42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label42->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label42->Location = System::Drawing::Point(129, 219);
            this->label42->Name = L"label42";
            this->label42->Size = System::Drawing::Size(325, 31);
            this->label42->TabIndex = 58;
            this->label42->Text = L" Enter Digital media info\r\n";
            // 
            // panel16
            // 
            this->panel16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel16->Location = System::Drawing::Point(135, 371);
            this->panel16->Name = L"panel16";
            this->panel16->Size = System::Drawing::Size(403, 4);
            this->panel16->TabIndex = 57;
            // 
            // newdigitaltxt
            // 
            this->newdigitaltxt->BackColor = System::Drawing::Color::Black;
            this->newdigitaltxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->newdigitaltxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->newdigitaltxt->ForeColor = System::Drawing::Color::White;
            this->newdigitaltxt->Location = System::Drawing::Point(132, 344);
            this->newdigitaltxt->Name = L"newdigitaltxt";
            this->newdigitaltxt->Size = System::Drawing::Size(403, 28);
            this->newdigitaltxt->TabIndex = 56;
            this->newdigitaltxt->TextChanged += gcnew System::EventHandler(this, &MyForm::newdigitaltxt_TextChanged);
            // 
            // label43
            // 
            this->label43->AutoSize = true;
            this->label43->BackColor = System::Drawing::Color::Transparent;
            this->label43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label43->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label43->Location = System::Drawing::Point(51, 341);
            this->label43->Name = L"label43";
            this->label43->Size = System::Drawing::Size(97, 31);
            this->label43->TabIndex = 55;
            this->label43->Text = L"Input: ";
            // 
            // label62
            // 
            this->label62->AutoSize = true;
            this->label62->BackColor = System::Drawing::Color::Transparent;
            this->label62->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label62->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label62->Location = System::Drawing::Point(127, 277);
            this->label62->Name = L"label62";
            this->label62->Size = System::Drawing::Size(424, 51);
            this->label62->TabIndex = 54;
            this->label62->Text = L"DIGITAL_TITLE,DIGITAL_AUTHOR,DIGITAL_PUBLISHER,\r\nDIGITAL_STATUS,DIGITAL_PRODUCTIO"
                L"N_YEAR,\r\nDIGITAL_COPIES";
            // 
            // button27
            // 
            this->button27->BackColor = System::Drawing::Color::Blue;
            this->button27->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button27->FlatAppearance->BorderSize = 0;
            this->button27->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button27->ForeColor = System::Drawing::Color::White;
            this->button27->Location = System::Drawing::Point(421, 159);
            this->button27->Name = L"button27";
            this->button27->Size = System::Drawing::Size(104, 38);
            this->button27->TabIndex = 53;
            this->button27->Text = L"OK";
            this->button27->UseVisualStyleBackColor = false;
            this->button27->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
            // 
            // panel17
            // 
            this->panel17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel17->Location = System::Drawing::Point(123, 149);
            this->panel17->Name = L"panel17";
            this->panel17->Size = System::Drawing::Size(414, 4);
            this->panel17->TabIndex = 52;
            // 
            // editdigitaltxt
            // 
            this->editdigitaltxt->BackColor = System::Drawing::Color::Black;
            this->editdigitaltxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editdigitaltxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editdigitaltxt->ForeColor = System::Drawing::Color::White;
            this->editdigitaltxt->Location = System::Drawing::Point(120, 122);
            this->editdigitaltxt->Name = L"editdigitaltxt";
            this->editdigitaltxt->Size = System::Drawing::Size(414, 28);
            this->editdigitaltxt->TabIndex = 51;
            // 
            // label63
            // 
            this->label63->AutoSize = true;
            this->label63->BackColor = System::Drawing::Color::Transparent;
            this->label63->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label63->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label63->Location = System::Drawing::Point(42, 119);
            this->label63->Name = L"label63";
            this->label63->Size = System::Drawing::Size(97, 31);
            this->label63->TabIndex = 50;
            this->label63->Text = L"Input: ";
            // 
            // button17
            // 
            this->button17->BackColor = System::Drawing::Color::Fuchsia;
            this->button17->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button17->FlatAppearance->BorderSize = 0;
            this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button17->ForeColor = System::Drawing::Color::White;
            this->button17->Location = System::Drawing::Point(446, 382);
            this->button17->Name = L"button17";
            this->button17->Size = System::Drawing::Size(104, 38);
            this->button17->TabIndex = 34;
            this->button17->Text = L"Edit";
            this->button17->UseVisualStyleBackColor = false;
            this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
            // 
            // label44
            // 
            this->label44->AutoSize = true;
            this->label44->BackColor = System::Drawing::Color::Transparent;
            this->label44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label44->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label44->Location = System::Drawing::Point(101, 9);
            this->label44->Name = L"label44";
            this->label44->Size = System::Drawing::Size(414, 31);
            this->label44->TabIndex = 9;
            this->label44->Text = L" Enter Digital media info to edit\r\n";
            // 
            // editlibpnl
            // 
            this->editlibpnl->AutoSize = true;
            this->editlibpnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editlibpnl.BackgroundImage")));
            this->editlibpnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->editlibpnl->Controls->Add(this->label65);
            this->editlibpnl->Controls->Add(this->label39);
            this->editlibpnl->Controls->Add(this->panel14);
            this->editlibpnl->Controls->Add(this->newlibtxt);
            this->editlibpnl->Controls->Add(this->label40);
            this->editlibpnl->Controls->Add(this->label45);
            this->editlibpnl->Controls->Add(this->button26);
            this->editlibpnl->Controls->Add(this->panel15);
            this->editlibpnl->Controls->Add(this->editlibtxt);
            this->editlibpnl->Controls->Add(this->label46);
            this->editlibpnl->Controls->Add(this->button16);
            this->editlibpnl->Controls->Add(this->label41);
            this->editlibpnl->Location = System::Drawing::Point(262, 86);
            this->editlibpnl->Name = L"editlibpnl";
            this->editlibpnl->Size = System::Drawing::Size(572, 429);
            this->editlibpnl->TabIndex = 56;
            // 
            // label65
            // 
            this->label65->AutoSize = true;
            this->label65->BackColor = System::Drawing::Color::Transparent;
            this->label65->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label65->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label65->Location = System::Drawing::Point(154, 57);
            this->label65->Name = L"label65";
            this->label65->Size = System::Drawing::Size(219, 17);
            this->label65->TabIndex = 59;
            this->label65->Text = L"LIBRARY_ID,LIBRARY_NAME";
            // 
            // label39
            // 
            this->label39->AutoSize = true;
            this->label39->BackColor = System::Drawing::Color::Transparent;
            this->label39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label39->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label39->Location = System::Drawing::Point(160, 211);
            this->label39->Name = L"label39";
            this->label39->Size = System::Drawing::Size(246, 31);
            this->label39->TabIndex = 58;
            this->label39->Text = L" Enter Library info\r\n";
            // 
            // panel14
            // 
            this->panel14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel14->Location = System::Drawing::Point(143, 356);
            this->panel14->Name = L"panel14";
            this->panel14->Size = System::Drawing::Size(403, 4);
            this->panel14->TabIndex = 57;
            // 
            // newlibtxt
            // 
            this->newlibtxt->BackColor = System::Drawing::Color::Black;
            this->newlibtxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->newlibtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->newlibtxt->ForeColor = System::Drawing::Color::White;
            this->newlibtxt->Location = System::Drawing::Point(140, 329);
            this->newlibtxt->Name = L"newlibtxt";
            this->newlibtxt->Size = System::Drawing::Size(403, 28);
            this->newlibtxt->TabIndex = 56;
            this->newlibtxt->TextChanged += gcnew System::EventHandler(this, &MyForm::newlibtxt_TextChanged);
            // 
            // label40
            // 
            this->label40->AutoSize = true;
            this->label40->BackColor = System::Drawing::Color::Transparent;
            this->label40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label40->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label40->Location = System::Drawing::Point(59, 326);
            this->label40->Name = L"label40";
            this->label40->Size = System::Drawing::Size(97, 31);
            this->label40->TabIndex = 55;
            this->label40->Text = L"Input: ";
            // 
            // label45
            // 
            this->label45->AutoSize = true;
            this->label45->BackColor = System::Drawing::Color::Transparent;
            this->label45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label45->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label45->Location = System::Drawing::Point(187, 260);
            this->label45->Name = L"label45";
            this->label45->Size = System::Drawing::Size(219, 17);
            this->label45->TabIndex = 54;
            this->label45->Text = L"LIBRARY_ID,LIBRARY_NAME";
            // 
            // button26
            // 
            this->button26->BackColor = System::Drawing::Color::Blue;
            this->button26->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button26->FlatAppearance->BorderSize = 0;
            this->button26->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button26->ForeColor = System::Drawing::Color::White;
            this->button26->Location = System::Drawing::Point(429, 144);
            this->button26->Name = L"button26";
            this->button26->Size = System::Drawing::Size(104, 38);
            this->button26->TabIndex = 53;
            this->button26->Text = L"OK";
            this->button26->UseVisualStyleBackColor = false;
            this->button26->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
            // 
            // panel15
            // 
            this->panel15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel15->Location = System::Drawing::Point(131, 134);
            this->panel15->Name = L"panel15";
            this->panel15->Size = System::Drawing::Size(414, 4);
            this->panel15->TabIndex = 52;
            // 
            // editlibtxt
            // 
            this->editlibtxt->BackColor = System::Drawing::Color::Black;
            this->editlibtxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editlibtxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editlibtxt->ForeColor = System::Drawing::Color::White;
            this->editlibtxt->Location = System::Drawing::Point(128, 107);
            this->editlibtxt->Name = L"editlibtxt";
            this->editlibtxt->Size = System::Drawing::Size(414, 28);
            this->editlibtxt->TabIndex = 51;
            // 
            // label46
            // 
            this->label46->AutoSize = true;
            this->label46->BackColor = System::Drawing::Color::Transparent;
            this->label46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label46->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label46->Location = System::Drawing::Point(50, 104);
            this->label46->Name = L"label46";
            this->label46->Size = System::Drawing::Size(97, 31);
            this->label46->TabIndex = 50;
            this->label46->Text = L"Input: ";
            // 
            // button16
            // 
            this->button16->BackColor = System::Drawing::Color::Fuchsia;
            this->button16->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button16->FlatAppearance->BorderSize = 0;
            this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button16->ForeColor = System::Drawing::Color::White;
            this->button16->Location = System::Drawing::Point(454, 378);
            this->button16->Name = L"button16";
            this->button16->Size = System::Drawing::Size(104, 38);
            this->button16->TabIndex = 34;
            this->button16->Text = L"Edit";
            this->button16->UseVisualStyleBackColor = false;
            this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
            // 
            // label41
            // 
            this->label41->AutoSize = true;
            this->label41->BackColor = System::Drawing::Color::Transparent;
            this->label41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label41->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label41->Location = System::Drawing::Point(131, 4);
            this->label41->Name = L"label41";
            this->label41->Size = System::Drawing::Size(335, 31);
            this->label41->TabIndex = 9;
            this->label41->Text = L" Enter Library info to edit\r\n";
            // 
            // editbookpnl
            // 
            this->editbookpnl->AutoSize = true;
            this->editbookpnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editbookpnl.BackgroundImage")));
            this->editbookpnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->editbookpnl->Controls->Add(this->label56);
            this->editbookpnl->Controls->Add(this->panel3);
            this->editbookpnl->Controls->Add(this->newbooktxt);
            this->editbookpnl->Controls->Add(this->label54);
            this->editbookpnl->Controls->Add(this->label55);
            this->editbookpnl->Controls->Add(this->button24);
            this->editbookpnl->Controls->Add(this->button19);
            this->editbookpnl->Controls->Add(this->panel30);
            this->editbookpnl->Controls->Add(this->editbooktxt);
            this->editbookpnl->Controls->Add(this->label48);
            this->editbookpnl->Controls->Add(this->label49);
            this->editbookpnl->Controls->Add(this->label50);
            this->editbookpnl->Location = System::Drawing::Point(258, 91);
            this->editbookpnl->Name = L"editbookpnl";
            this->editbookpnl->Size = System::Drawing::Size(572, 429);
            this->editbookpnl->TabIndex = 59;
            // 
            // label56
            // 
            this->label56->AutoSize = true;
            this->label56->BackColor = System::Drawing::Color::Transparent;
            this->label56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label56->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label56->Location = System::Drawing::Point(116, 205);
            this->label56->Name = L"label56";
            this->label56->Size = System::Drawing::Size(230, 31);
            this->label56->TabIndex = 40;
            this->label56->Text = L" Enter Book info \r\n";
            // 
            // panel3
            // 
            this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel3->Location = System::Drawing::Point(96, 358);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(403, 4);
            this->panel3->TabIndex = 39;
            // 
            // newbooktxt
            // 
            this->newbooktxt->BackColor = System::Drawing::Color::Black;
            this->newbooktxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->newbooktxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->newbooktxt->ForeColor = System::Drawing::Color::White;
            this->newbooktxt->Location = System::Drawing::Point(93, 331);
            this->newbooktxt->Name = L"newbooktxt";
            this->newbooktxt->Size = System::Drawing::Size(403, 28);
            this->newbooktxt->TabIndex = 38;
            this->newbooktxt->TextChanged += gcnew System::EventHandler(this, &MyForm::newbooktxt_TextChanged);
            // 
            // label54
            // 
            this->label54->AutoSize = true;
            this->label54->BackColor = System::Drawing::Color::Transparent;
            this->label54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label54->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label54->Location = System::Drawing::Point(12, 328);
            this->label54->Name = L"label54";
            this->label54->Size = System::Drawing::Size(97, 31);
            this->label54->TabIndex = 37;
            this->label54->Text = L"Input: ";
            // 
            // label55
            // 
            this->label55->AutoSize = true;
            this->label55->BackColor = System::Drawing::Color::Transparent;
            this->label55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label55->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label55->Location = System::Drawing::Point(88, 264);
            this->label55->Name = L"label55";
            this->label55->Size = System::Drawing::Size(376, 51);
            this->label55->TabIndex = 36;
            this->label55->Text = L"BOOK_TITLE,BOOK_AUTHOR,BOOK_PUBLISHER,\r\nBOOK_STATUS,BOOK_PRODUCTION_YEAR,\r\nBOOK_C"
                L"OPIES";
            // 
            // button24
            // 
            this->button24->BackColor = System::Drawing::Color::Blue;
            this->button24->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button24->FlatAppearance->BorderSize = 0;
            this->button24->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button24->ForeColor = System::Drawing::Color::White;
            this->button24->Location = System::Drawing::Point(382, 146);
            this->button24->Name = L"button24";
            this->button24->Size = System::Drawing::Size(104, 38);
            this->button24->TabIndex = 35;
            this->button24->Text = L"OK";
            this->button24->UseVisualStyleBackColor = false;
            this->button24->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
            // 
            // button19
            // 
            this->button19->BackColor = System::Drawing::Color::Fuchsia;
            this->button19->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->button19->FlatAppearance->BorderSize = 0;
            this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button19->ForeColor = System::Drawing::Color::White;
            this->button19->Location = System::Drawing::Point(430, 371);
            this->button19->Name = L"button19";
            this->button19->Size = System::Drawing::Size(104, 38);
            this->button19->TabIndex = 34;
            this->button19->Text = L"Edit";
            this->button19->UseVisualStyleBackColor = false;
            this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
            // 
            // panel30
            // 
            this->panel30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->panel30->Location = System::Drawing::Point(84, 136);
            this->panel30->Name = L"panel30";
            this->panel30->Size = System::Drawing::Size(414, 4);
            this->panel30->TabIndex = 18;
            // 
            // editbooktxt
            // 
            this->editbooktxt->BackColor = System::Drawing::Color::Black;
            this->editbooktxt->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editbooktxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editbooktxt->ForeColor = System::Drawing::Color::White;
            this->editbooktxt->Location = System::Drawing::Point(81, 109);
            this->editbooktxt->Name = L"editbooktxt";
            this->editbooktxt->Size = System::Drawing::Size(414, 28);
            this->editbooktxt->TabIndex = 17;
            // 
            // label48
            // 
            this->label48->AutoSize = true;
            this->label48->BackColor = System::Drawing::Color::Transparent;
            this->label48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label48->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label48->Location = System::Drawing::Point(3, 106);
            this->label48->Name = L"label48";
            this->label48->Size = System::Drawing::Size(97, 31);
            this->label48->TabIndex = 11;
            this->label48->Text = L"Input: ";
            // 
            // label49
            // 
            this->label49->AutoSize = true;
            this->label49->BackColor = System::Drawing::Color::Transparent;
            this->label49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label49->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label49->Location = System::Drawing::Point(131, 56);
            this->label49->Name = L"label49";
            this->label49->Size = System::Drawing::Size(263, 22);
            this->label49->TabIndex = 10;
            this->label49->Text = L"BOOK Title,BOOK AUTHOR";
            // 
            // label50
            // 
            this->label50->AutoSize = true;
            this->label50->BackColor = System::Drawing::Color::Transparent;
            this->label50->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label50->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label50->Location = System::Drawing::Point(116, 7);
            this->label50->Name = L"label50";
            this->label50->Size = System::Drawing::Size(311, 31);
            this->label50->TabIndex = 9;
            this->label50->Text = L" Enter Book info to edit\r\n";
            // 
            // back
            // 
            this->back->BackColor = System::Drawing::Color::Gray;
            this->back->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->back->FlatAppearance->BorderSize = 0;
            this->back->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->back->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->back->ForeColor = System::Drawing::Color::White;
            this->back->Location = System::Drawing::Point(878, 462);
            this->back->Name = L"back";
            this->back->Size = System::Drawing::Size(107, 60);
            this->back->TabIndex = 43;
            this->back->Text = L"Back";
            this->back->UseVisualStyleBackColor = false;
            this->back->Click += gcnew System::EventHandler(this, &MyForm::back_Click);
            // 
            // deletesubscriber
            // 
            this->deletesubscriber->BackColor = System::Drawing::Color::Red;
            this->deletesubscriber->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->deletesubscriber->FlatAppearance->BorderSize = 0;
            this->deletesubscriber->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->deletesubscriber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->deletesubscriber->ForeColor = System::Drawing::Color::White;
            this->deletesubscriber->Location = System::Drawing::Point(577, 447);
            this->deletesubscriber->Name = L"deletesubscriber";
            this->deletesubscriber->Size = System::Drawing::Size(107, 60);
            this->deletesubscriber->TabIndex = 42;
            this->deletesubscriber->Text = L"Delete";
            this->deletesubscriber->UseVisualStyleBackColor = false;
            this->deletesubscriber->Click += gcnew System::EventHandler(this, &MyForm::deletesubscriber_Click);
            // 
            // deletelib
            // 
            this->deletelib->BackColor = System::Drawing::Color::Red;
            this->deletelib->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->deletelib->FlatAppearance->BorderSize = 0;
            this->deletelib->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->deletelib->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->deletelib->ForeColor = System::Drawing::Color::White;
            this->deletelib->Location = System::Drawing::Point(577, 362);
            this->deletelib->Name = L"deletelib";
            this->deletelib->Size = System::Drawing::Size(107, 60);
            this->deletelib->TabIndex = 41;
            this->deletelib->Text = L"Delete";
            this->deletelib->UseVisualStyleBackColor = false;
            this->deletelib->Click += gcnew System::EventHandler(this, &MyForm::deletelib_Click);
            // 
            // deletedigital
            // 
            this->deletedigital->BackColor = System::Drawing::Color::Red;
            this->deletedigital->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->deletedigital->FlatAppearance->BorderSize = 0;
            this->deletedigital->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->deletedigital->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->deletedigital->ForeColor = System::Drawing::Color::White;
            this->deletedigital->Location = System::Drawing::Point(577, 264);
            this->deletedigital->Name = L"deletedigital";
            this->deletedigital->Size = System::Drawing::Size(107, 60);
            this->deletedigital->TabIndex = 40;
            this->deletedigital->Text = L"Delete";
            this->deletedigital->UseVisualStyleBackColor = false;
            this->deletedigital->Click += gcnew System::EventHandler(this, &MyForm::deletedigital_Click);
            // 
            // deletarticle
            // 
            this->deletarticle->BackColor = System::Drawing::Color::Red;
            this->deletarticle->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->deletarticle->FlatAppearance->BorderSize = 0;
            this->deletarticle->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->deletarticle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->deletarticle->ForeColor = System::Drawing::Color::White;
            this->deletarticle->Location = System::Drawing::Point(577, 181);
            this->deletarticle->Name = L"deletarticle";
            this->deletarticle->Size = System::Drawing::Size(107, 60);
            this->deletarticle->TabIndex = 39;
            this->deletarticle->Text = L"Delete";
            this->deletarticle->UseVisualStyleBackColor = false;
            this->deletarticle->Click += gcnew System::EventHandler(this, &MyForm::deletarticle_Click);
            // 
            // deletebook
            // 
            this->deletebook->BackColor = System::Drawing::Color::Red;
            this->deletebook->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->deletebook->FlatAppearance->BorderSize = 0;
            this->deletebook->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->deletebook->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->deletebook->ForeColor = System::Drawing::Color::White;
            this->deletebook->Location = System::Drawing::Point(577, 98);
            this->deletebook->Name = L"deletebook";
            this->deletebook->Size = System::Drawing::Size(107, 60);
            this->deletebook->TabIndex = 38;
            this->deletebook->Text = L"Delete";
            this->deletebook->UseVisualStyleBackColor = false;
            this->deletebook->Click += gcnew System::EventHandler(this, &MyForm::deletebook_Click);
            // 
            // Editlib
            // 
            this->Editlib->BackColor = System::Drawing::Color::Fuchsia;
            this->Editlib->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->Editlib->FlatAppearance->BorderSize = 0;
            this->Editlib->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->Editlib->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Editlib->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->Editlib->Location = System::Drawing::Point(445, 352);
            this->Editlib->Name = L"Editlib";
            this->Editlib->Size = System::Drawing::Size(107, 62);
            this->Editlib->TabIndex = 37;
            this->Editlib->Text = L"Edit";
            this->Editlib->UseVisualStyleBackColor = false;
            this->Editlib->Click += gcnew System::EventHandler(this, &MyForm::Editlib_Click);
            // 
            // Editsub
            // 
            this->Editsub->BackColor = System::Drawing::Color::Fuchsia;
            this->Editsub->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->Editsub->FlatAppearance->BorderSize = 0;
            this->Editsub->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->Editsub->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Editsub->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->Editsub->Location = System::Drawing::Point(445, 445);
            this->Editsub->Name = L"Editsub";
            this->Editsub->Size = System::Drawing::Size(107, 62);
            this->Editsub->TabIndex = 36;
            this->Editsub->Text = L"Edit";
            this->Editsub->UseVisualStyleBackColor = false;
            this->Editsub->Click += gcnew System::EventHandler(this, &MyForm::Editsub_Click);
            // 
            // editarticle
            // 
            this->editarticle->BackColor = System::Drawing::Color::Fuchsia;
            this->editarticle->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->editarticle->FlatAppearance->BorderSize = 0;
            this->editarticle->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->editarticle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editarticle->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->editarticle->Location = System::Drawing::Point(445, 183);
            this->editarticle->Name = L"editarticle";
            this->editarticle->Size = System::Drawing::Size(107, 58);
            this->editarticle->TabIndex = 35;
            this->editarticle->Text = L"Edit";
            this->editarticle->UseVisualStyleBackColor = false;
            this->editarticle->Click += gcnew System::EventHandler(this, &MyForm::editarticle_Click);
            // 
            // editdigital
            // 
            this->editdigital->BackColor = System::Drawing::Color::Fuchsia;
            this->editdigital->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->editdigital->FlatAppearance->BorderSize = 0;
            this->editdigital->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->editdigital->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editdigital->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->editdigital->Location = System::Drawing::Point(445, 264);
            this->editdigital->Name = L"editdigital";
            this->editdigital->Size = System::Drawing::Size(107, 58);
            this->editdigital->TabIndex = 34;
            this->editdigital->Text = L"Edit";
            this->editdigital->UseVisualStyleBackColor = false;
            this->editdigital->Click += gcnew System::EventHandler(this, &MyForm::editdigital_Click);
            // 
            // editBook
            // 
            this->editBook->BackColor = System::Drawing::Color::Fuchsia;
            this->editBook->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->editBook->FlatAppearance->BorderSize = 0;
            this->editBook->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->editBook->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editBook->ForeColor = System::Drawing::Color::White;
            this->editBook->Location = System::Drawing::Point(445, 98);
            this->editBook->Name = L"editBook";
            this->editBook->Size = System::Drawing::Size(107, 60);
            this->editBook->TabIndex = 33;
            this->editBook->Text = L"Edit";
            this->editBook->UseVisualStyleBackColor = false;
            this->editBook->Click += gcnew System::EventHandler(this, &MyForm::editBook_Click);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->BackColor = System::Drawing::Color::Transparent;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label5->Location = System::Drawing::Point(56, 456);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(184, 39);
            this->label5->TabIndex = 32;
            this->label5->Text = L"Subscriber";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::Color::Transparent;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label4->Location = System::Drawing::Point(50, 362);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(124, 39);
            this->label4->TabIndex = 31;
            this->label4->Text = L"Library";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::Color::Transparent;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label3->Location = System::Drawing::Point(50, 283);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(217, 39);
            this->label3->TabIndex = 30;
            this->label3->Text = L"Digital Media";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::Transparent;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label2->Location = System::Drawing::Point(50, 191);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(115, 39);
            this->label2->TabIndex = 29;
            this->label2->Text = L"Article";
            // 
            // Book
            // 
            this->Book->AutoSize = true;
            this->Book->BackColor = System::Drawing::Color::Transparent;
            this->Book->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Book->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Book->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->Book->Location = System::Drawing::Point(55, 106);
            this->Book->Name = L"Book";
            this->Book->Size = System::Drawing::Size(96, 39);
            this->Book->TabIndex = 28;
            this->Book->Text = L"Book";
            // 
            // addliberary
            // 
            this->addliberary->BackColor = System::Drawing::Color::Blue;
            this->addliberary->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->addliberary->FlatAppearance->BorderSize = 0;
            this->addliberary->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->addliberary->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addliberary->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->addliberary->Location = System::Drawing::Point(313, 352);
            this->addliberary->Name = L"addliberary";
            this->addliberary->Size = System::Drawing::Size(107, 62);
            this->addliberary->TabIndex = 27;
            this->addliberary->Text = L"Add";
            this->addliberary->UseVisualStyleBackColor = false;
            this->addliberary->Click += gcnew System::EventHandler(this, &MyForm::addliberary_Click);
            // 
            // addsubscriber
            // 
            this->addsubscriber->BackColor = System::Drawing::Color::Blue;
            this->addsubscriber->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->addsubscriber->FlatAppearance->BorderSize = 0;
            this->addsubscriber->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->addsubscriber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubscriber->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->addsubscriber->Location = System::Drawing::Point(313, 445);
            this->addsubscriber->Name = L"addsubscriber";
            this->addsubscriber->Size = System::Drawing::Size(107, 62);
            this->addsubscriber->TabIndex = 26;
            this->addsubscriber->Text = L"Add";
            this->addsubscriber->UseVisualStyleBackColor = false;
            this->addsubscriber->Click += gcnew System::EventHandler(this, &MyForm::addsubscriber_Click);
            // 
            // AddArticle
            // 
            this->AddArticle->BackColor = System::Drawing::Color::Blue;
            this->AddArticle->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->AddArticle->FlatAppearance->BorderSize = 0;
            this->AddArticle->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->AddArticle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->AddArticle->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->AddArticle->Location = System::Drawing::Point(313, 183);
            this->AddArticle->Name = L"AddArticle";
            this->AddArticle->Size = System::Drawing::Size(107, 58);
            this->AddArticle->TabIndex = 25;
            this->AddArticle->Text = L"Add";
            this->AddArticle->UseVisualStyleBackColor = false;
            this->AddArticle->Click += gcnew System::EventHandler(this, &MyForm::AddArticle_Click);
            // 
            // AddDigitalMedia
            // 
            this->AddDigitalMedia->BackColor = System::Drawing::Color::Blue;
            this->AddDigitalMedia->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->AddDigitalMedia->FlatAppearance->BorderSize = 0;
            this->AddDigitalMedia->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->AddDigitalMedia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->AddDigitalMedia->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->AddDigitalMedia->Location = System::Drawing::Point(313, 264);
            this->AddDigitalMedia->Name = L"AddDigitalMedia";
            this->AddDigitalMedia->Size = System::Drawing::Size(107, 58);
            this->AddDigitalMedia->TabIndex = 24;
            this->AddDigitalMedia->Text = L"Add ";
            this->AddDigitalMedia->UseVisualStyleBackColor = false;
            this->AddDigitalMedia->Click += gcnew System::EventHandler(this, &MyForm::AddDigitalMedia_Click);
            // 
            // Addbook
            // 
            this->Addbook->BackColor = System::Drawing::Color::Blue;
            this->Addbook->FlatAppearance->BorderColor = System::Drawing::Color::Black;
            this->Addbook->FlatAppearance->BorderSize = 0;
            this->Addbook->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->Addbook->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Addbook->ForeColor = System::Drawing::Color::White;
            this->Addbook->Location = System::Drawing::Point(313, 98);
            this->Addbook->Name = L"Addbook";
            this->Addbook->Size = System::Drawing::Size(107, 60);
            this->Addbook->TabIndex = 23;
            this->Addbook->Text = L"Add";
            this->Addbook->UseVisualStyleBackColor = false;
            this->Addbook->Click += gcnew System::EventHandler(this, &MyForm::Addbook_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(320, 2);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(580, 31);
            this->label1->TabIndex = 22;
            this->label1->Text = L"Choose below to Add,Edit or Delete an item";
            // 
            // dockingpnl
            // 
            this->dockingpnl->BackColor = System::Drawing::Color::Gray;
            this->dockingpnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dockingpnl.BackgroundImage")));
            this->dockingpnl->Controls->Add(this->borrow);
            this->dockingpnl->Controls->Add(this->addeditdelete);
            this->dockingpnl->Controls->Add(this->viewupduepnl);
            this->dockingpnl->Controls->Add(this->returnpnl);
            this->dockingpnl->Controls->Add(this->label98);
            this->dockingpnl->Controls->Add(this->label97);
            this->dockingpnl->Controls->Add(this->button37);
            this->dockingpnl->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dockingpnl->Location = System::Drawing::Point(287, 110);
            this->dockingpnl->MaximumSize = System::Drawing::Size(1270, 770);
            this->dockingpnl->Name = L"dockingpnl";
            this->dockingpnl->Size = System::Drawing::Size(1270, 760);
            this->dockingpnl->TabIndex = 20;
            // 
            // label98
            // 
            this->label98->AutoSize = true;
            this->label98->BackColor = System::Drawing::Color::Transparent;
            this->label98->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 39.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label98->ForeColor = System::Drawing::Color::Red;
            this->label98->Location = System::Drawing::Point(195, 299);
            this->label98->Name = L"label98";
            this->label98->Size = System::Drawing::Size(593, 68);
            this->label98->TabIndex = 20;
            this->label98->Text = L"Have a nice day!!!";
            // 
            // label97
            // 
            this->label97->AutoSize = true;
            this->label97->BackColor = System::Drawing::Color::Transparent;
            this->label97->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 40, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label97->ForeColor = System::Drawing::Color::Lime;
            this->label97->Location = System::Drawing::Point(219, 17);
            this->label97->Name = L"label97";
            this->label97->Size = System::Drawing::Size(547, 70);
            this->label97->TabIndex = 19;
            this->label97->Text = L"We welcome you ";
            // 
            // button37
            // 
            this->button37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->button37->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->button37->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button37->ForeColor = System::Drawing::Color::White;
            this->button37->Location = System::Drawing::Point(428, 488);
            this->button37->Name = L"button37";
            this->button37->Size = System::Drawing::Size(183, 62);
            this->button37->TabIndex = 17;
            this->button37->Text = L"Exit\r\n";
            this->button37->UseVisualStyleBackColor = false;
            this->button37->Click += gcnew System::EventHandler(this, &MyForm::button37_Click);
            // 
            // MyForm
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->AutoScroll = true;
            this->AutoScrollMargin = System::Drawing::Size(1270, 760);
            this->BackColor = System::Drawing::Color::White;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(1384, 681);
            this->Controls->Add(this->dockingpnl);
            this->Controls->Add(this->panel36);
            this->Controls->Add(this->panel35);
            this->Controls->Add(this->panel34);
            this->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->MaximumSize = System::Drawing::Size(1557, 820);
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Library application";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->returnpnl->ResumeLayout(false);
            this->returnpnl->PerformLayout();
            this->returndigitalpnl->ResumeLayout(false);
            this->returndigitalpnl->PerformLayout();
            this->returnarticlepnl->ResumeLayout(false);
            this->returnarticlepnl->PerformLayout();
            this->returnbookpnl->ResumeLayout(false);
            this->returnbookpnl->PerformLayout();
            this->viewupduepnl->ResumeLayout(false);
            this->viewupduepnl->PerformLayout();
            this->panel34->ResumeLayout(false);
            this->panel35->ResumeLayout(false);
            this->panel35->PerformLayout();
            this->borrow->ResumeLayout(false);
            this->borrow->PerformLayout();
            this->addeditdelete->ResumeLayout(false);
            this->addeditdelete->PerformLayout();
            this->deletesubpnl->ResumeLayout(false);
            this->deletesubpnl->PerformLayout();
            this->deletebookpnl->ResumeLayout(false);
            this->deletebookpnl->PerformLayout();
            this->dletearticlepnl->ResumeLayout(false);
            this->dletearticlepnl->PerformLayout();
            this->deletedigitalpnl->ResumeLayout(false);
            this->deletedigitalpnl->PerformLayout();
            this->deletelibrarypnl->ResumeLayout(false);
            this->deletelibrarypnl->PerformLayout();
            this->addlib->ResumeLayout(false);
            this->addlib->PerformLayout();
            this->bookadd->ResumeLayout(false);
            this->bookadd->PerformLayout();
            this->subadd->ResumeLayout(false);
            this->subadd->PerformLayout();
            this->digitaladd->ResumeLayout(false);
            this->digitaladd->PerformLayout();
            this->articleadd->ResumeLayout(false);
            this->articleadd->PerformLayout();
            this->editarticlepnl->ResumeLayout(false);
            this->editarticlepnl->PerformLayout();
            this->editsubscriberpnl->ResumeLayout(false);
            this->editsubscriberpnl->PerformLayout();
            this->editdigitalpnl->ResumeLayout(false);
            this->editdigitalpnl->PerformLayout();
            this->editlibpnl->ResumeLayout(false);
            this->editlibpnl->PerformLayout();
            this->editbookpnl->ResumeLayout(false);
            this->editbookpnl->PerformLayout();
            this->dockingpnl->ResumeLayout(false);
            this->dockingpnl->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
        ////definations starts here where we have written the control code
	//when the form loads
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        this->HorizontalScroll->Enabled;
        this->HorizontalScroll->Maximum=0;
	}
           //back butten addeditdelte
    private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e) {
        this->addeditdelete->Hide();
    }
           //add libarary ok butten 
    private: System::Void addlibbtn_Click(System::Object^ sender, System::EventArgs^ e) {
        string input = msclr::interop::marshal_as< std::string >(this->addlibtxt->Text);//String^ to string
        if (input != "")
        {
            stringstream in;
            in << input;
            //cin.ignore();
            string libraryid,
                name;
            getline(in, libraryid, ',');
            getline(in, name, '\n');
            //validation
            if (this->isValidLibraryId(libraryid) && this->isValidLibraryName(name))
            {
                bool x = 0;
                for (auto it : lib)
                {
                    if (it.getlibraryid() == libraryid)//if lib found with given id
                    {
                        x = 1;
                        break;
                    }
                }
                if (x == 0)
                {
                    lib.emplace_back(libraryid, name);//add library
                    string msg = "Library has been added successfully!";
                    string head = "Success";
                    message^ obj = gcnew message(this, msg, head);
                    this->addlibtxt->Text = "";
                    this->addlib->Hide();
                    obj->ShowDialog();
                }
                else
                {
                    string msg = "Library already exists with\n this " + libraryid + " id!";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    this->addlibtxt->Text = "";
                    this->addlib->Hide();
                    obj->ShowDialog();
                }
            }
        }
        else {
            string msg = "Please enter the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            this->addlibtxt->Text = "";
            obj->ShowDialog();
        }
    }
           //add library butten
    private: System::Void addliberary_Click(System::Object^ sender, System::EventArgs^ e) {
        this->addlib->Show();
    }
           //add book butten
    private: System::Void Addbook_Click(System::Object^ sender, System::EventArgs^ e) {
        this->bookadd->Show();
    }
           //add article butten
    private: System::Void AddArticle_Click(System::Object^ sender, System::EventArgs^ e) {
        this->articleadd->Show();
    }
           //add digital butten
    private: System::Void AddDigitalMedia_Click(System::Object^ sender, System::EventArgs^ e) {
        this->digitaladd->Show();
    }
           //add subscriber butten
    private: System::Void addsubscriber_Click(System::Object^ sender, System::EventArgs^ e) {
        this->subadd->Show();
    }
           //add subscriber ok butten
    private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {

        string input = msclr::interop::marshal_as< std::string >(this->addsubtxt->Text);//String^ to string
        if (input != "")
        {

            stringstream in;
            in << input;
            cin.ignore();
            string subscriber_ID, Type, Name, Address, Phone, Email;
            getline(in, subscriber_ID, ',');
            getline(in, Type, ',');
            getline(in, Name, ',');
            getline(in, Address, ',');
            getline(in, Phone, ',');
            getline(in, Email, '\n');
            if (this->isValidSubId(subscriber_ID) && this->isValidSubscriberType(Type) && this->isValidSubscriberName(Name) && this->isValidSubscriberPhone(Phone) && this->isValidSubscriberEmail(Email))
            {
                bool x = 0;
                for (auto it : sub)
                {
                    if (it.getsubsriberid() == subscriber_ID)//if subsriber found with given id
                    {
                        x = 1;
                        break;
                    }
                }
                if (x == 0)
                {
                    sub.emplace_back(subscriber_ID, Type, Name, Address, Phone, Email);//add subscriber
                    string msg = "Subscriber has been added successfully!";
                    string head = "Success";
                    message^ obj = gcnew message(this, msg, head);
                    this->addsubtxt->Text = "";
                    this->subadd->Hide();
                    obj->ShowDialog();
                }
                else
                {
                    string msg = "Subscriber already exists with \nthis " + subscriber_ID + " id!";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    this->addsubtxt->Text = "";
                    this->subadd->Hide();
                    obj->ShowDialog();
                }
            }
        }
        else
        {
            string msg = "Please enter  the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }


    }
           //add article ok butten
    private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
        string input = msclr::interop::marshal_as< std::string >(this->addarticleinputtxt->Text);//String^ to string
        if (input != "")
        {
            stringstream in;
            in << input;
            cin.ignore();
            string libraryid, name;
            string title, author, publisher, status,
                production_year, copies;
            getline(in, libraryid, ',');
            getline(in, name, ',');
            getline(in, title, ',');
            getline(in, author, ',');
            getline(in, publisher, ',');
            getline(in, status, ',');
            getline(in, production_year, ',');
            getline(in, copies, '\n');
            //validations
            if (this->isValidLibraryName(name) && this->isValidLibraryId(libraryid) && this->isValidAuthor(author) && this->isValidPublisher(publisher) && this->isValidProductionYear(production_year) && this->isValidCopies(copies))
            {
                auto it = find(lib.begin(), lib.end(), library(libraryid, name));//store given library in 'it' if found
                if (it != lib.end())
                {
                    //add article if library found
                    it->setarticle({ title, author, publisher, status, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10),global_iteamid });
                    global_iteamid += 1;
                    string msg = "Article has been added successfully!";
                    string head = "Success";
                    message^ obj = gcnew message(this, msg, head);
                    this->addarticleinputtxt->Text = "";
                    this->articleadd->Hide();
                    obj->ShowDialog();
                }
                else
                {
                    string msg = "No library found with this " + libraryid + " id!\nFirst add library than article";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    this->addarticleinputtxt->Text = "";
                    obj->ShowDialog();
                    this->articleadd->Hide();
                    this->addlib->Show();
                }
            }
        }
        else
        {
            string msg = "Please enter  the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
    }
           //delete sub pnl
    private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
        this->deletesubpnl->Show();

    }
           //deletesubscriber butten
    private: System::Void deletesubscriber_Click(System::Object^ sender, System::EventArgs^ e) {
        this->deletesubpnl->Show();
    }
           //delete library ok butten
    private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
        string input = msclr::interop::marshal_as< std::string >(this->deletelibtxt->Text);//String^ to string
        stringstream in;
        in << input;
        string libraryid,
            name;
        getline(in, libraryid, ',');
        getline(in, name, '\n');
        //validations
        if (this->isValidLibraryId(libraryid) && this->isValidLibraryName(name))
        {
            bool x = 0;
            auto it = find(lib.begin(), lib.end(), library(libraryid, name));
            if (it != lib.end())//if library is found
            {
                lib.erase(it);//erase libray
                deletelibraryinborrow(libraryid, name);//also delete from borrow record
                string msg = "Library has been deleted successfully";
                string head = "Success";
                message^ obj = gcnew message(this, msg, head);
                this->deletelibtxt->Text = "";
                obj->ShowDialog();
            }
            else
            {
                string msg = "No Library exists with given info";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                this->deletelibtxt->Text = "";
                obj->ShowDialog();
            }
            saveinfile();
            global_iteamid = 1;
            lib.clear();
            sub.clear();
            borr.clear();
            loadlibrraryfile();
            loaditemsfile();
            loadsubscriberfile();
            loadborrowfile();
            this->deletelibrarypnl->Hide();
        }

    }
           //delete library butten
    private: System::Void deletelib_Click(System::Object^ sender, System::EventArgs^ e) {
        this->deletelibrarypnl->Show();
    }
           //delete digital ok butten
    private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
        string input = msclr::interop::marshal_as< std::string >(this->deletedigitaltxt->Text);//String^ to string
        if (this->deletedigitaltxt->Text == "")
        {
            string msg = "Please enter  the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            stringstream in;
            in << input;

            string author, bookname;
            bool flag = 0;
            getline(in, bookname, ','); getline(in, author, '\n');
            //validayion
            if (this->isValidAuthor(author))
            {

                for (auto it = lib.begin(); it != lib.end(); it++)
                {
                    if (it->finddigitalmedia(bookname, author) != 0)//if digital is found
                    {
                        flag = 1;
                        int item_id = it->finddigitalmedia(bookname, author);
                        it->deletecontentitem(item_id);//delete in content
                        deletedigitalmediainborrow(item_id);//delte in borrow record
                        global_iteamid = global_iteamid - 1;
                        uniquekey(item_id);

                        string msg = "Digital media has been \ndeleted successfully";
                        string head = "Success";
                        message^ obj = gcnew message(this, msg, head);
                        this->deletedigitaltxt->Text = "";
                        obj->ShowDialog();
                        saveinfile();
                        global_iteamid = 1;
                        lib.clear();
                        sub.clear();
                        borr.clear();
                        loadlibrraryfile();
                        loaditemsfile();
                        loadsubscriberfile();
                        loadborrowfile();
                        break;
                    }
                }
                if (flag == 0)
                {
                    string msg = "No digitalmedia exists \nwith given info";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    this->deletedigitaltxt->Text = "";
                    obj->ShowDialog();
                }
                this->deletedigitalpnl->Hide();
            }
        }

    }
           //deletedigital butten
    private: System::Void deletedigital_Click(System::Object^ sender, System::EventArgs^ e) {
        this->deletedigitalpnl->Show();
    }
           //deletearticle ok butten
    private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->deletearticletxt->Text == "")
        {
            string msg = "Please enter  the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->deletearticletxt->Text + ",");//String^ to string
            stringstream in;
            in << input;
            string author, bookname;
            bool flag = 0;
            getline(in, bookname, ',');
            getline(in, author, ',');
            //validation
            if (this->isValidAuthor(author))
            {
                for (auto it = lib.begin(); it != lib.end(); it++)
                {
                    if (it->findarticle(bookname, author) != 0) // if found
                    {
                        flag = 1;
                        int item_id = it->findarticle(bookname, author);
                        it->deletecontentitem(item_id);//delete in content
                        deletearticleinborrow(item_id);//delete in borrow record
                        global_iteamid = global_iteamid - 1;
                        uniquekey(item_id);
                        string msg = "Article has been deleted successfully";
                        string head = "Success";
                        message^ obj = gcnew message(this, msg, head);
                        this->deletearticletxt->Text = "";
                        obj->ShowDialog();
                        saveinfile();
                        global_iteamid = 1;
                        lib.clear();
                        sub.clear();
                        borr.clear();
                        loadlibrraryfile();
                        loaditemsfile();
                        loadsubscriberfile();
                        loadborrowfile();
                        this->dletearticlepnl->Hide();
                        break;
                    }
                }
                if (flag == 0)
                {
                    string msg = "NO ARTICLE EXIST WITH GIVEN INFO";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    this->deletearticletxt->Text = "";
                    obj->ShowDialog();
                    this->dletearticlepnl->Hide();
                }

            }
        }
    }
           //deletarticle butten
    private: System::Void deletarticle_Click(System::Object^ sender, System::EventArgs^ e) {
        this->dletearticlepnl->Show();
    }
           //deletebook ok butten
    private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->deletebooktxt->Text == "")
        {
            string msg = "Please enter  the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->deletebooktxt->Text);//String^ to string
            stringstream in;
            in << input;
            string author, bookname;
            bool flag = 0;
            getline(in, bookname, ','); getline(in, author, '\n');
            //validation
            if (this->isValidAuthor(author))
            {
                for (auto it = lib.begin(); it != lib.end(); it++)
                {
                    if (it->findbook(bookname, author) != 0)//if book is found 
                    {
                        flag = 1;
                        int item_id = it->findbook(bookname, author);
                        it->deletecontentitem(item_id);//delete book in content
                        deletebookinborrow(item_id);//delete book in borrow record
                        global_iteamid = global_iteamid - 1;
                        uniquekey(item_id);

                        string msg = "Book has been deleted successfully";
                        string head = "Success";
                        message^ obj = gcnew message(this, msg, head);
                        this->deletebooktxt->Text = "";
                        obj->ShowDialog();
                        saveinfile();
                        global_iteamid = 1;
                        lib.clear();
                        sub.clear();
                        borr.clear();
                        loadlibrraryfile();
                        loaditemsfile();
                        loadsubscriberfile();
                        loadborrowfile();
                        this->deletebookpnl->Hide();
                        break;
                    }
                }
                if (flag == 0)
                {
                    string msg = "NO BOOK EXIST WITH GIVEN INFO";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    this->deletebooktxt->Text = "";
                    obj->ShowDialog();
                    this->deletebookpnl->Hide();
                }
            }
        }

    }
           //deletebook butten
    private: System::Void deletebook_Click(System::Object^ sender, System::EventArgs^ e) {
        this->deletebookpnl->Show();
    }
           //delete sub okbutten
    private: System::Void button10_Click_1(System::Object^ sender, System::EventArgs^ e) {
        if (this->deletesubtxt->Text == "")
        {
            string msg = "Please enter  the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->deletesubtxt->Text + ",");//String^ to string
            stringstream in;
            in << input;
            string subscriber_id, name;
            getline(in, subscriber_id, ',');
            getline(in, name, ',');
            //validations
            if (this->isValidSubId(subscriber_id) && this->isValidSubscriberName(name))
            {
                auto it = find(sub.begin(), sub.end(), subscribers(subscriber_id, name));
                if (it != sub.end())//if sub is found
                {
                    for (auto it2 = borr.begin(); it2 != borr.end(); it2++)
                    {//erase the borrow record with given data
                        if (!(_stricmp(name.c_str(), it2->getsubscribername().c_str())) && !(_stricmp(subscriber_id.c_str(), it2->getsubscriberid().c_str())))
                        {
                            borr.erase(it2);
                            break;
                        }
                    }
                    sub.erase(it);// delete sub
                    string msg = "Subscriber has been deleted successfully";
                    string head = "Success";
                    message^ obj = gcnew message(this, msg, head);
                    this->deletesubtxt->Text = "";
                    obj->ShowDialog();
                    saveinfile();
                    global_iteamid = 1;
                    lib.clear();
                    sub.clear();
                    borr.clear();
                    loadlibrraryfile();
                    loaditemsfile();
                    loadsubscriberfile();
                    loadborrowfile();
                    this->deletesubpnl->Hide();
                }
                else
                {
                    string msg = "No subscriber exist with given id/name";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    this->deletesubtxt->Text = "";
                    obj->ShowDialog();
                    this->deletesubpnl->Hide();
                }
            }
        }

    }
           //Editsub butten
    private: System::Void Editsub_Click(System::Object^ sender, System::EventArgs^ e) {
        this->editsubscriberpnl->Show();
    }
           //edit lib ok butten
    private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->editlibtxt->Text == "")
        {
            string msg = "Please enter  the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->editlibtxt->Text);//String^ to string
            stringstream in;
            in << input;
            cin.ignore();
            string libraryid,
                name;
            getline(in, libraryid, ',');
            getline(in, name, '\n');
            if (this->isValidLibraryId(libraryid) && this->isValidLibraryName(name))
            {
                bool x = 0;
                auto it = find(lib.begin(), lib.end(), library(libraryid, name));
                if (it != lib.end())
                {
                    string id, n;
                    if (this->newlibtxt->Text == "")
                    {
                        string msg = "Please enter  the info first!";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                    }
                    else
                    {
                        string inputt = msclr::interop::marshal_as< std::string >(this->newlibtxt->Text);//String^ to string
                        stringstream inp;
                        inp << inputt;
                        getline(inp, id, ','); getline(inp, n, '\n');
                        //validation
                        if (this->isValidLibraryId(id) && this->isValidLibraryName(n))
                        {
                            auto it2 = find(lib.begin(), lib.end(), library(id, n));
                            if (it2 != lib.end())
                            {
                                string msg = "Library already exists with given data";
                                string head = "Error!";
                                message^ obj = gcnew message(this, msg, head);
                                this->newlibtxt->Text = "";
                                obj->ShowDialog();
                            }
                            else
                            {
                                it->setlibrary(id, n);//update at that library id and name
                                edilibraryinborrow(libraryid, name, id, n);//also edit in borrow record
                                string msg = "Library has been updated successfully";
                                string head = "Success";
                                message^ obj = gcnew message(this, msg, head);
                                this->newlibtxt->Text = "";
                                obj->ShowDialog();
                                saveinfile();
                                global_iteamid = 1;
                                lib.clear();
                                sub.clear();
                                borr.clear();
                                loadlibrraryfile();
                                loaditemsfile();
                                loadsubscriberfile();
                                loadborrowfile();
                                this->editlibpnl->Hide();
                            }
                        }
                    }

                }
                else
                {
                    string msg = "No library exists with given data";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    this->editlibtxt->Text = "";
                    obj->ShowDialog();
                }
            }
        }


    }
           //edit lib butten
    private: System::Void Editlib_Click(System::Object^ sender, System::EventArgs^ e) {
        this->editlibpnl->Show();
    }
           //edit digital ok butten
    private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->editdigitaltxt->Text == "")
        {
            string msg = "Please enter  the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->editdigitaltxt->Text);//String^ to string
            stringstream in;
            in << input;
            cin.ignore();
            bool flag = 0;
            string author, bookname;
            getline(in, bookname, ','); getline(in, author, '\n');
            for (auto it = lib.begin(); it != lib.end(); it++)
            {
                if (it->finddigitalmedia(bookname, author) != 0)
                {
                    flag = 1;
                    if (this->newdigitaltxt->Text == "")
                    {
                        string msg = "Please enter  the info first!";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        break;
                    }
                    else
                    {
                        string inputt = msclr::interop::marshal_as< std::string >(this->newdigitaltxt->Text);//String^ to string
                        stringstream inp;
                        inp << inputt;
                        int itemid = it->finddigitalmedia(bookname, author);
                        string title, author, publisher, status,
                            production_year, copies;
                        getline(inp, title, ',');
                        getline(inp, author, ',');
                        getline(inp, publisher, ',');
                        getline(inp, status, ',');
                        getline(inp, production_year, ',');
                        getline(inp, copies, '\n');
                        if (this->isValidAuthor(author) && this->isValidPublisher(publisher) && this->isValidProductionYear(production_year) && this->isValidCopies(copies))
                        {
                            it->editdigital({ title,author,publisher,stoi(production_year,nullptr,10),status,stoi(copies,nullptr,10),itemid });
                            updatedigitalinborrow({ title,author,publisher,stoi(production_year,nullptr,10),status,stoi(copies,nullptr,10),itemid });
                            this->newdigitaltxt->Text = "";
                            string msg = "Your entered DIGITAL MEDIA is updated.";
                            string head = "Success";
                            message^ obj = gcnew message(this, msg, head);
                            obj->ShowDialog();
                            saveinfile();
                            global_iteamid = 1;
                            lib.clear();
                            sub.clear();
                            borr.clear();
                            loadlibrraryfile();
                            loaditemsfile();
                            loadsubscriberfile();
                            loadborrowfile();
                            this->editdigitalpnl->Hide();

                        }
                        break;
                    }
                }
            }
        }

    }
           //editdigital butten
    private: System::Void editdigital_Click(System::Object^ sender, System::EventArgs^ e) {
        this->editdigitalpnl->Show();
    }
           //edit article ok butten
    private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
        string input = msclr::interop::marshal_as< std::string >(this->editartricletxt->Text);//String^ to string
        stringstream in;
        in << input;
        bool flag = 0;
        string author, bookname;
        if (this->isValidAuthor(author))
        {
            getline(in, bookname, ','); getline(in, author, '\n');
            for (auto it = lib.begin(); it != lib.end(); it++)
            {
                if (it->findarticle(bookname, author) != 0)
                {
                    flag = 1;
                    if (this->newarticletxt->Text == "")
                    {
                        string msg = "Please enter  the info first!";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        break;
                    }
                    else
                    {
                        int itemid = it->findarticle(bookname, author);
                        string inputt = msclr::interop::marshal_as< std::string >(this->newarticletxt->Text);//String^ to string
                        stringstream inp;
                        inp << inputt;
                        string title, Author, publisher, status,
                            production_year, copies;
                        getline(inp, title, ',');
                        getline(inp, Author, ',');
                        getline(inp, publisher, ',');
                        getline(inp, status, ',');
                        getline(inp, production_year, ',');
                        getline(inp, copies, '\n');
                        if (this->isValidAuthor(Author) && this->isValidPublisher(publisher) && this->isValidProductionYear(production_year) && this->isValidCopies(copies))
                        {
                            it->editarticle({ title,Author,publisher,status,stoi(production_year,nullptr,10),stoi(copies,nullptr,10),itemid });
                            updatearticleinborrow({ title,Author,publisher,status,stoi(production_year,nullptr,10),stoi(copies,nullptr,10),itemid });
                            string msg = "Article has been updated successfully";
                            string head = "Success";
                            message^ obj = gcnew message(this, msg, head);
                            obj->ShowDialog();
                            saveinfile();
                            global_iteamid = 1;
                            lib.clear();
                            sub.clear();
                            borr.clear();
                            loadlibrraryfile();
                            loaditemsfile();
                            loadsubscriberfile();
                            loadborrowfile();
                            this->newarticletxt->Text = "";

                            this->editarticlepnl->Hide();

                        }
                        break;
                    }

                }
            }
        }
    }
           //editarticle butten
    private: System::Void editarticle_Click(System::Object^ sender, System::EventArgs^ e) {
        this->editarticlepnl->Show();
    }
           //edit book ok butten
    private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
        string input = msclr::interop::marshal_as< std::string >(this->editbooktxt->Text);//String^ to string
        stringstream in;
        in << input;
        cin.ignore();
        string author, bookname;
        bool flag = 0;
        getline(in, bookname, ','); getline(in, author, '\n');
        //validation
        if (this->isValidAuthor(author))
        {
            for (auto it = lib.begin(); it != lib.end(); it++)
            {
                if (it->findbook(bookname, author) != 0)//if book found
                {
                    if (this->newbooktxt->Text == "")
                    {
                        string msg = "Please enter  the info first!";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        break;
                    }
                    else
                    {
                        try
                        {

                            int itemid = it->findbook(bookname, author);
                            string title, author, publisher, status,
                                production_year, copies;

                            string inputt = msclr::interop::marshal_as< std::string >(this->newbooktxt->Text);//String^ to string
                            stringstream inp;
                            inp << inputt;
                            getline(inp, title, ',');
                            getline(inp, author, ',');
                            getline(inp, publisher, ',');
                            getline(inp, status, ',');
                            getline(inp, production_year, ',');
                            getline(inp, copies, '\n');
                            //validation
                            if (this->isValidAuthor(author) && this->isValidPublisher(publisher) && this->isValidProductionYear(production_year) && this->isValidCopies(copies))
                            {
                                //update book with given data
                                it->editbook({ title,author,publisher,stoi(production_year,nullptr,10),stoi(copies,nullptr,10),status,itemid });
                                updatebookinborrow({ title,author,publisher,stoi(production_year,nullptr,10),stoi(copies,nullptr,10),status,itemid });//update in borrow record
                                string msg = "Book has been updated sucessfully.";
                                string head = "Success";
                                message^ obj = gcnew message(this, msg, head);
                                obj->ShowDialog();
                                this->newbooktxt->Text = "";
                                saveinfile();
                                global_iteamid = 1;
                                lib.clear();
                                sub.clear();
                                borr.clear();
                                loadlibrraryfile();
                                loaditemsfile();
                                loadsubscriberfile();
                                loadborrowfile();
                                this->editbookpnl->Hide();


                            }
                            break;
                        }
                        catch (Exception^ e)
                        {
                            string msg = "Exception occured.Please check\nyour input(don't enter extra data)";
                            string head = "Exception!";
                            message^ obj = gcnew message(this, msg, head);
                            obj->ShowDialog();
                        }
                    }

                }
            }
        }

    }
           //editbook butten
    private: System::Void editBook_Click(System::Object^ sender, System::EventArgs^ e) {
        this->editbookpnl->Show();
    }
           //viewupdue back butten
    private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
        this->viewupduepnl->Hide();
    }
           //return back butten
    private: System::Void button21_Click_1(System::Object^ sender, System::EventArgs^ e) {
        this->returnpnl->Hide();
    }
           //editsub ok butten
    private: System::Void button15_Click_1(System::Object^ sender, System::EventArgs^ e) {
        string inputsb = msclr::interop::marshal_as< std::string >(this->editsubtxt->Text + ",");//String^ to string
        stringstream insb;
        insb << inputsb;
        string subscriber_id, name;
        getline(insb, subscriber_id, ',');
        getline(insb, name, ',');
        if (this->newsubtxt->Text == "")
        {
            string msg = "Please enter the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->newsubtxt->Text);//String^ to string
            stringstream in;
            in << input;
            if (this->isValidSubId(subscriber_id) && this->isValidSubscriberName(name))
            {
                auto it = find(sub.begin(), sub.end(), subscribers(subscriber_id, name));
                if (it != sub.end())
                {
                    string subscriber_ID, Type, Name, Address, Phone, Email;
                    getline(in, subscriber_ID, ',');
                    getline(in, Type, ',');
                    getline(in, Name, ',');
                    getline(in, Address, ',');
                    getline(in, Phone, ',');
                    getline(in, Email, '\n');
                    //Validations
                    if (this->isValidSubId(subscriber_ID) && this->isValidSubscriberName(Name) && this->isValidSubscriberEmail(Email) && this->isValidSubscriberPhone(Phone) && this->isValidSubscriberType(Type))
                    {
                        bool x = 0;
                        for (auto it = sub.begin(); it != sub.end(); it++)
                        {
                            //if sub exists with given data
                            if (it->getsubsriberid() == subscriber_ID && it->getsubsriberid() != subscriber_id)
                            {
                                x = 1;
                                break;
                            }
                        }
                        if (x == 0)
                        {
                            //if any sub does not exist with given data
                            it->setsubscriber(subscriber_ID, Type, Name, Address, Phone, Email);

                            string msg = "Subscriber has been updated succefully";
                            string head = "Success!";
                            message^ obj = gcnew message(this, msg, head);
                            this->newsubtxt->Text = "";
                            this->editsubtxt->Text = "";
                            obj->ShowDialog();
                            this->editsubscriberpnl->Hide();
                            //update also in borrow record
                            for (auto it2 = borr.begin(); it2 != borr.end(); it2++)
                            {
                                if (!(_stricmp(name.c_str(), it2->getsubscribername().c_str())) && !(_stricmp(subscriber_id.c_str(), it2->getsubscriberid().c_str())))
                                {
                                    it2->setsubscriber(subscriber_ID, Type, Name, Address, Phone, Email, subscriber_id);//subscriber_id

                                }
                            }




                        }
                        else
                        {
                            string msg = "ALREADY SUBSCRIBER EXIST WITH THIS " + subscriber_ID + " ID\n";
                            string head = "Error!";
                            message^ obj = gcnew message(this, msg, head);
                            this->newsubtxt->Text = "";
                            obj->ShowDialog();
                        }

                    }
                }
            }
        }

    }
           //return back butten
    private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
        this->returnsubinfotxt->Text = "";
        this->returnpnl->Hide();
    }
           //viewupdue back butten
    private: System::Void button22_Click_1(System::Object^ sender, System::EventArgs^ e) {
        this->listView3->Items->Clear();
        this->viewupduepnl->Hide();

    }
           //return book ok butten
    private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->returnbooktxt->Text == "")
        {
            string msg = "Please enter the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->returnsubinfotxt->Text);//String^ to string
            stringstream in;
            in << input;
            saveinfile();
            global_iteamid = 1;
            lib.clear();
            sub.clear();
            borr.clear();
            //load updated record
            loadlibrraryfile();
            loaditemsfile();
            loadsubscriberfile();
            loadborrowfile();
            stringstream sub2;
            string subscriber_id, name;
            getline(in, subscriber_id, ','); getline(in, name, '\n');

            if (this->isValidSubId(subscriber_id) && this->isValidSubscriberName(name))
            {
                auto it = find(sub.begin(), sub.end(), subscribers(subscriber_id, name));
                bool x = 0;
                if (it != sub.end())//if subscriber is found
                {
                    int update = 0;
                    string author, bookname;
                    string inputt = msclr::interop::marshal_as< std::string >(this->returnbooktxt->Text + ",");//String^ to string
                    stringstream inp;
                    inp << inputt;
                    getline(inp, bookname, ','); getline(inp, author, ',');
                    //validation
                    if (this->isValidAuthor(author))
                    {
                        bool found = false;
                        for (auto it = borr.begin(); it != borr.end(); it++)
                        {
                            //if the given info matches with any borrow record
                            if (it->getsubscriberid() == subscriber_id && !(_stricmp(it->getsubscribername().c_str(), name.c_str())))
                            {
                                bool found = true;
                                string id, dtl, data = it->findbook(bookname, author);
                                stringstream s;
                                s << data;
                                getline(s, id, ',');
                                getline(s, dtl, ',');
                                int x = stoi(id, nullptr, 10);
                                if (x == 0)//if that book not found in borrow record
                                {
                                    string msg = "The subscriber have not \nborrowed the given book...";
                                    string head = "Error!";
                                    message^ obj = gcnew message(this, msg, head);
                                    this->returnbookpnl->Hide();
                                    this->returnbooktxt->Text = "";
                                    obj->ShowDialog();
                                }
                                if (x != 0)
                                {
                                    string msg = "The book has been returned successfully!\nFine is Rs." + dtl;
                                    string head = "Success";
                                    message^ obj = gcnew message(this, msg, head);
                                    this->returnbookpnl->Hide();
                                    this->returnbooktxt->Text = "";
                                    obj->ShowDialog();
                                    saveinfile();
                                    global_iteamid = 1;
                                    lib.clear();
                                    sub.clear();
                                    borr.clear();
                                    loadlibrraryfile();
                                    loaditemsfile();
                                    loadsubscriberfile();
                                    loadborrowfile();
                                    update = x;
                                }
                                break;
                            }


                        }
                        if (update != 0) { increase(update); };
                    }
                }
            }
        }

    }
           //return book butten
    private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->returnsubinfotxt->Text == "")
        {
            string msg = "Please enter the subscriber \ninfo first";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
            this->returnbookpnl->Show();
    }
           //return article ok butten
    private: System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->returnarticletxt->Text == "")
        {
            string msg = "Please enter the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->returnsubinfotxt->Text);//String^ to string
            stringstream in;
            in << input;
            saveinfile();
            global_iteamid = 1;
            lib.clear();
            sub.clear();
            borr.clear();
            //load updated record
            loadlibrraryfile();
            loaditemsfile();
            loadsubscriberfile();
            loadborrowfile();
            stringstream sub2;
            string subscriber_id, name;
            getline(in, subscriber_id, ','); getline(in, name, '\n');
            //validations
            if (this->isValidSubId(subscriber_id) && this->isValidSubscriberName(name))
            {
                auto it = find(sub.begin(), sub.end(), subscribers(subscriber_id, name));
                bool x = 0;
                if (it != sub.end())
                {
                    int update = 0;
                    string author, bookname;
                    string inputt = msclr::interop::marshal_as< std::string >(this->returnarticletxt->Text);//String^ to string
                    stringstream inp;
                    inp << inputt;
                    getline(inp, bookname, ','); getline(inp, author, '\n');
                    if (this->isValidAuthor(author))
                    {
                        for (auto it = borr.begin(); it != borr.end(); it++)
                        {
                            //if the given info matches with any borrow record
                            if (it->getsubscriberid() == subscriber_id && !(_stricmp(it->getsubscribername().c_str(), name.c_str())))
                            {
                                string id, dtl, data = it->findarticle(bookname, author);
                                stringstream s;
                                s << data;
                                getline(s, id, ',');
                                getline(s, dtl, ',');
                                int x = stoi(id, nullptr, 10);
                                if (x == 0)//if that article not found in borrow record
                                {
                                    string msg = "The subscriber have not \nborrowed the given article...";
                                    string head = "Error!";
                                    message^ obj = gcnew message(this, msg, head);
                                    this->returnarticlepnl->Hide();
                                    this->returnarticletxt->Text = "";
                                    obj->ShowDialog();
                                }
                                if (x != 0)
                                {
                                    string msg = "The article has been returned successfully!\nFine is Rs." + dtl;
                                    string head = "Success";
                                    message^ obj = gcnew message(this, msg, head);
                                    this->returnarticlepnl->Hide();
                                    this->returnarticletxt->Text = "";
                                    obj->ShowDialog();
                                    saveinfile();
                                    global_iteamid = 1;
                                    lib.clear();
                                    sub.clear();
                                    borr.clear();
                                    loadlibrraryfile();
                                    loaditemsfile();
                                    loadsubscriberfile();
                                    loadborrowfile();
                                    update = x;
                                }
                                break;
                            }

                        }
                        if (update != 0) { increase(update); };//if record found
                    }
                }
            }
        }

    }
           //return article butten
    private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->returnsubinfotxt->Text == "")
        {
            string msg = "Please enter the subscriber \ninfo first";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
            this->returnarticlepnl->Show();
    }
           //return digital butten
    private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->returnsubinfotxt->Text == "")
        {
            string msg = "Please enter the subscriber \ninfo first";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
            this->returndigitalpnl->Show();
    }
           //edit sub initial ok butten
    private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->editsubtxt->Text == "")
        {
            string msg = "Please enter the subscriber \ninfo first";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->editsubtxt->Text + "\n");//String^ to string
            stringstream in;
            in << input;
            string subscriber_id, name;
            getline(in, subscriber_id, ',');
            getline(in, name, '\n');
            //check for validations
            if (this->isValidSubId(subscriber_id) && this->isValidSubscriberName(name))
            {
                auto it = find(sub.begin(), sub.end(), subscribers(subscriber_id, name));
                if (it != sub.end())//if sub is found
                {
                    string msg = "Your entered subscriber is found.Now \nenter the info required";
                    string head = "Success";
                    message^ obj = gcnew message(this, msg, head);
                    obj->ShowDialog();
                }
                else
                {
                    string msg = "NO SUBSCRIBER EXIST WITH THIS " + subscriber_id + " ID\n";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    this->editsubtxt->Text = "";
                    obj->ShowDialog();
                    this->editsubscriberpnl->Hide();
                }
            }
        }

    }
           //edit digital initial ok buten
    private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->editdigitaltxt->Text == "")
        {
            string msg = "Please enter the info first";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->editdigitaltxt->Text);//String^ to string
            stringstream in;
            in << input;
            cin.ignore();
            bool flag = 0;
            string author, bookname;
            getline(in, bookname, ','); getline(in, author, '\n');
            if (this->isValidAuthor(author))
            {
                for (auto it = lib.begin(); it != lib.end(); it++)
                {
                    if (it->finddigitalmedia(bookname, author) != 0)
                    {
                        flag = 1;
                        string msg = "Your entered DIGITAL MEDIA is found. Now enter\nrequired info";
                        string head = "Success";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        break;
                    }
                }
                if (flag == 0)
                {
                    flag = 1;
                    string msg = "NO DIGITAL MEDIA ITEM EXIST WITH GIVEN INFO";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    obj->ShowDialog();
                    this->editdigitalpnl->Hide();
                }
            }

        }

    }
           //edit book initial ok butten
    private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->editbooktxt->Text == "")
        {
            string msg = "Please enter the info first";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else {
            string input = msclr::interop::marshal_as< std::string >(this->editbooktxt->Text);//String^ to string
            stringstream in;
            in << input;
            cin.ignore();
            string author, bookname;
            bool flag = 0;
            getline(in, bookname, ','); getline(in, author, '\n');
            if (this->isValidAuthor(author))
            {
                for (auto it = lib.begin(); it != lib.end(); it++)
                {
                    if (it->findbook(bookname, author) != 0)
                    {
                        flag = 1;
                        int itemid = it->findbook(bookname, author);
                        string msg = "Your entered book is found";
                        string head = "Success";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        break;
                    }
                }
                if (flag == 0)
                {
                    string msg = "NO BOOK EXIST WITH GIVEN INFO";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    obj->ShowDialog();
                    this->editbooktxt->Text = "";
                    this->editbookpnl->Hide();
                }
            }
        }

    }
           //edit article initial ok butten
    private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->editartricletxt->Text == "")
        {//message show
            string msg = "Please enter the info first";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->editartricletxt->Text);//String^ to string
            stringstream in;
            in << input;
            bool flag = 0;
            string author, bookname;
            getline(in, bookname, ','); getline(in, author, '\n');
            //validation
            if (this->isValidAuthor(author))
            {
                for (auto it = lib.begin(); it != lib.end(); it++)
                {
                    if (it->findarticle(bookname, author) != 0)//if Article found
                    {
                        flag = 1;
                        int itemid = it->findarticle(bookname, author);
                        string msg = "Your entered Article is found";
                        string head = "Success";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        break;
                    }
                }
                if (flag == 0)
                {
                    string msg = "NO ARTICLE EXIST WITH GIVEN INFO";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    obj->ShowDialog();
                    this->editartricletxt->Text = "";
                    this->editarticlepnl->Hide();
                }
            }
        }


    }
           //edit book new text(when click on textbox to edit)
    private: System::Void newbooktxt_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        if (this->editbooktxt->Text == "")
        {
            string msg = "First enter book info to edit.";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
    }
           //edit article new text(when click on textbox to edit)
    private: System::Void newarticletxt_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        if (this->editartricletxt->Text == "")
        {
            string msg = "First enter article info to edit.";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
    }
           //edit digitalmedia new text(when click on textbox to edit)
    private: System::Void newdigitaltxt_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        if (this->editdigitaltxt->Text == "")
        {
            string msg = "First enter digitalmedia info to edit.";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
    }
           //edit subscriber new text(when click on textbox to edit)
    private: System::Void newsubtxt_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        if (this->editsubtxt->Text == "")
        {
            string msg = "First enter subscriber info to edit.";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
    }
           //editlib initial ok butten
    private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->editlibtxt->Text == "")
        {
            string msg = "First enter the info.";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->editlibtxt->Text);//String^ to string
            stringstream in;
            in << input;
            cin.ignore();
            string libraryid,
                name;
            getline(in, libraryid, ',');
            getline(in, name, '\n');
            //val
            if (this->isValidLibraryId(libraryid) && this->isValidLibraryName(name))
            {
                bool x = 0;
                auto it = find(lib.begin(), lib.end(), library(libraryid, name));
                if (it != lib.end())//if library is found
                {
                    string id, n;
                    string msg = "Your entered library is found. Enter\ninformation below";
                    string head = "Success";
                    message^ obj = gcnew message(this, msg, head);
                    obj->ShowDialog();
                }
                else
                {
                    string msg = "NO LIBRARY EXIST WITH GIVEN INFO";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    this->editlibpnl->Hide();
                    this->editlibtxt->Text = "";
                    obj->ShowDialog();
                }
            }
        }

    }
    private: System::Void newlibtxt_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        if (this->editlibtxt->Text == "")
        {
            string msg = "First enter libary info to edit.";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
    }
           //return sub info ok butten
    private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->returnsubinfotxt->Text == "")
        {//message show
            string msg = "Please enter the info first";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->returnsubinfotxt->Text);//String^ to string
            stringstream in;
            in << input;
            stringstream sub2;
            string subscriber_id, name;
            getline(in, subscriber_id, ','); getline(in, name, '\n');
            //validations
            if (this->isValidSubId(subscriber_id) && this->isValidSubscriberName(name))
            {

                auto it = find(sub.begin(), sub.end(), subscribers(subscriber_id, name));
                bool x = 0;
                if (it != sub.end())//if subscriber is found
                {
                    bool v = false;
                    for (auto it2 = borr.begin(); it2 != borr.end(); it2++)
                    {
                        //if the given info matches with any borrow record
                        if (it2->getsubscriberid() == subscriber_id && !(_stricmp(it2->getsubscribername().c_str(), name.c_str())))
                        {
                            v = true;
                            string msg = "The given subscriber is found. \nNow choose below";
                            string head = "Success";
                            message^ obj = gcnew message(this, msg, head);
                            obj->ShowDialog();
                            break;
                        }
                    }
                    if (!v)
                    {
                        string msg = "The subscriber have not borrow anything\nor the record has been deleted";
                        string head = "Notification!!!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                        this->returnsubinfotxt->Text = "";
                        this->returnpnl->Hide();
                    }

                }
                else
                {
                    string msg = "No subscriber exists with \ngiven name and id";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    this->returnsubinfotxt->Text = "";
                    this->returnpnl->Hide();
                    obj->ShowDialog();
                }
            }
        }

    }
           //return digital ok butten
    private: System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->returnsubinfotxt->Text == "")
        {//message show
            string msg = "Please enter the info first";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
        else
        {
            string input = msclr::interop::marshal_as< std::string >(this->returnsubinfotxt->Text);//String^ to string
            stringstream in;
            in << input;
            saveinfile();
            global_iteamid = 1;
            lib.clear();
            sub.clear();
            borr.clear();
            loadlibrraryfile();
            loaditemsfile();
            loadsubscriberfile();
            loadborrowfile();
            stringstream sub2;
            string subscriber_id, name;
            getline(in, subscriber_id, ','); getline(in, name, '\n');
            //validation
            if (this->isValidSubId(subscriber_id) && this->isValidSubscriberName(name)) {
                auto it = find(sub.begin(), sub.end(), subscribers(subscriber_id, name));
                bool x = 0;
                if (it != sub.end())
                {
                    if (this->returndigitaltxt->Text == "")
                    {//message show
                        string msg = "Please enter the info first";
                        string head = "Error!";
                        message^ obj = gcnew message(this, msg, head);
                        obj->ShowDialog();
                    }
                    else
                    {
                        int update = 0;
                        string author, digitalname;
                        string inputt = msclr::interop::marshal_as< std::string >(this->returndigitaltxt->Text + "\n");//String^ to string
                        stringstream inp;
                        inp << inputt;
                        getline(inp, digitalname, ','); getline(inp, author, '\n');
                        if (this->isValidAuthor(author))
                        {
                            for (auto it = borr.begin(); it != borr.end(); it++)
                            {
                                //if the given info matches with any borrow record
                                if (it->getsubscriberid() == subscriber_id && !(_stricmp(it->getsubscribername().c_str(), name.c_str())))
                                {
                                    string id, dtl, data = it->finddigitalmedia(digitalname, author);
                                    stringstream s;
                                    s << data;
                                    getline(s, id, ',');
                                    getline(s, dtl, ',');
                                    int x = stoi(id, nullptr, 10);//id convert to int
                                    cout << x;
                                    if (x == 0)//if that article not found in borrow record
                                    {
                                        string msg = "The subscriber have not \nborrowed the given digitalmedia...";
                                        string head = "Error!";
                                        message^ obj = gcnew message(this, msg, head);
                                        this->returndigitalpnl->Hide();
                                        this->returndigitaltxt->Text = "";
                                        obj->ShowDialog();
                                    }
                                    if (x != 0)
                                    {
                                        string msg = "The digital has been returned successfully!\nFine is Rs." + dtl;
                                        string head = "Success";
                                        message^ obj = gcnew message(this, msg, head);
                                        this->returndigitalpnl->Hide();
                                        this->returndigitaltxt->Text = "";
                                        obj->ShowDialog();
                                        saveinfile();
                                        global_iteamid = 1;
                                        lib.clear();
                                        sub.clear();
                                        borr.clear();
                                        loadlibrraryfile();
                                        loaditemsfile();
                                        loadsubscriberfile();
                                        loadborrowfile();
                                        update = x;
                                    }
                                    break;
                                }

                            }
                            if (update != 0) { increase(update); };//if record found
                        }
                    }

                }
            }
        }

    }
    //updue items ok butten
    private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
        bool b = 0;
        string data;
        for (auto it = borr.begin(); it != borr.end(); it++)
        {
            string libraryid, librartname, itemid;
            stringstream sub;
            sub << it->getlibrarysptostring();//store library string
            while (getline(sub, data, '\n'))
            {
                stringstream sub2;
                sub2 << data;
                getline(sub2, libraryid, ','); getline(sub2, librartname, ','); getline(sub2, itemid, ',');
                if (it->getreturndate(stoi(itemid, nullptr, 10)) == "----")//if returned date is not set
                {
                    //if the subscriber is find against that item then print
                    if (it->finecalcculationforadminview(stoi(itemid, nullptr, 10)) != 0)
                    {
                        stringstream str;
                        str << it->getsubscriberid() << "," << it->getsubscribername() << "," << itemid << "\n";
                        string subid, subname, itemid;
                        getline(str, subid, ',');
                        getline(str, subname, ',');
                        getline(str, itemid, '\n');
                        listview = gcnew Windows::Forms::ListViewItem(msclr::interop::marshal_as< String^ >(subid));
                        listview->SubItems->Add(msclr::interop::marshal_as< String^ >(subname));
                        listview->SubItems->Add(msclr::interop::marshal_as< String^ >(itemid));
                        this->listView3->Items->Add(listview);
                        b = 1;
                    }
                }
            }
        }
        if (b != 0)
        {
            this->listView3->Show();
        }
        else
        {
            string msg = "There is no updue item.";
            string head = "Sorry!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
            this->viewupduepnl->Hide();
        }
    }
           //add book ok butten
    private: System::Void btnbookadd_Click(System::Object^ sender, System::EventArgs^ e) {
        string input = msclr::interop::marshal_as< std::string >(this->addbooktext->Text);//String^ to string
        if (input != "")
        {
            stringstream in;
            in << input;
            string libraryid, name;
            string title, author, publisher, status,
                production_year, copies;
            getline(in, libraryid, ',');
            getline(in, name, ',');
            getline(in, title, ',');
            getline(in, author, ',');
            getline(in, publisher, ',');
            getline(in, status, ',');
            getline(in, production_year, ',');
            getline(in, copies, '\n');
            //check for validations
            if (this->isValidLibraryName(name) && this->isValidLibraryId(libraryid) && this->isValidAuthor(author) && this->isValidPublisher(publisher) && this->isValidProductionYear(production_year) && this->isValidCopies(copies))
            {
                auto it = find(lib.begin(), lib.end(), library(libraryid, name));//store given library in 'it' if found
                if (it != lib.end())
                {
                    //add book
                    it->setbook({ title, author, publisher, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), status,global_iteamid });
                    global_iteamid += 1;
                    string msg = "Book has been added successfully";
                    string head = "Success";
                    message^ obj = gcnew message(this, msg, head);
                    this->addbooktext->Text = "";
                    obj->ShowDialog();
                    this->bookadd->Hide();
                }
                else
                {
                    string msg = "NO LIBRARY FOUND WITH THIS " + libraryid + " ID \nFIRST ADD LIBRARY THAN BOOK";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    this->addbooktext->Text = "";
                    obj->ShowDialog();
                    this->bookadd->Hide();
                    this->addlib->Show();
                }
            }
        }
        else
        {
            string msg = "Please enter  the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
    }
           //view list butten (borrow)
    private: System::Void viewlistbtn_Click(System::Object^ sender, System::EventArgs^ e) {

        if (this->borrowsubinfoinput->Text != "")
        {

            string input = msclr::interop::marshal_as< std::string >(this->borrowsubinfoinput->Text);//String^ to string
            stringstream in;
            in << input;
            string subscriber_ID, Name;
            getline(in, subscriber_ID, ',');
            getline(in, Name, '\n');
            if (this->isValidSubId(subscriber_ID) && this->isValidSubscriberName(Name))
            {
                auto it = find(sub.begin(), sub.end(), subscribers(subscriber_ID, Name));
                map<int, library> search;
                int i = 1;
                if (it != sub.end())
                {
                    this->viewlistbtn->Hide();
                    this->listView1->Show();

                    this->borrowlistokbtn->Show();
                    string data;
                    for (auto it2 : lib)
                    {
                        stringstream sub2;
                        sub2 << it2.sptostring();
                        while (getline(sub2, data, '\n'))
                        {
                            stringstream sub3;
                            sub3 << data;
                            string title, catagory,
                                author,
                                publisher,
                                status,
                                production_year,
                                copies,
                                item_id;
                            getline(sub3, item_id, ','); getline(sub3, catagory, ',');	getline(sub3, title, ',');	getline(sub3, author, ',');	getline(sub3, publisher, ','), getline(sub3, production_year, ',');	getline(sub3, status, ',');	getline(sub3, copies, '\n');
                            if (catagory == "book")
                            {
                                search[i] = library(it2.getlibraryid(), it2.getlibrartname(), { title, author, publisher, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), status, stoi(item_id, nullptr, 10) });
                                i = i + 1;
                            }
                            if (catagory == "article")
                            {
                                search[i] = library(it2.getlibraryid(), it2.getlibrartname(), { title, author, publisher, status, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), stoi(item_id, nullptr, 10) });
                                i = i + 1;
                            }
                            if (catagory == "digital media")
                            {
                                search[i] = library(it2.getlibraryid(), it2.getlibrartname(), { title, author, publisher, stoi(production_year, nullptr, 10), status, stoi(copies, nullptr, 10), stoi(item_id, nullptr, 10) });
                                i = i + 1;
                            }
                        }
                    }
                    string choice;
                    string msg = "Choose below to borrow";
                    string head = "Success";
                    message^ obj = gcnew message(this, msg, head);
                    obj->ShowDialog();
                    int y = 0;
                    for (auto it2 : lib)
                    {
                        stringstream sub;
                        sub << it2.tostring();
                        while (getline(sub, data, '\n'))
                        {
                            y = y + 1;
                            stringstream mydta;
                            mydta << y << "," << it2.getlibraryid() << "," << data << endl;
                            string  Sr, LibraryID, Item_ID, Category, Title, Author,
                                Publisher, ProductionYear, Status, Copies;
                            getline(mydta, Sr, ',');
                            getline(mydta, LibraryID, ',');
                            getline(mydta, Item_ID, ',');
                            getline(mydta, Category, ',');
                            getline(mydta, Title, ',');
                            getline(mydta, Author, ',');
                            getline(mydta, Publisher, ',');
                            getline(mydta, ProductionYear, ',');
                            getline(mydta, Status, ',');
                            getline(mydta, Copies, '\n');
                            //convertion from string to String^
                            String^ sr = msclr::interop::marshal_as< String^ >(Sr);
                            String^ libraryID = msclr::interop::marshal_as< String^ >(LibraryID);
                            String^ item_ID = msclr::interop::marshal_as< String^ >(Item_ID);
                            String^ category = msclr::interop::marshal_as< String^ >(Category);
                            String^ title = msclr::interop::marshal_as< String^ >(Title);
                            String^ author = msclr::interop::marshal_as< String^ >(Author);
                            String^ publisher = msclr::interop::marshal_as< String^ >(Publisher);
                            String^ productionYear = msclr::interop::marshal_as< String^ >(ProductionYear);
                            String^ status = msclr::interop::marshal_as< String^ >(Status);
                            String^ copies = msclr::interop::marshal_as< String^ >(Copies);

                            listview = gcnew Windows::Forms::ListViewItem(sr);
                            listview->SubItems->Add(libraryID);
                            listview->SubItems->Add(item_ID);
                            listview->SubItems->Add(category);
                            listview->SubItems->Add(title);
                            listview->SubItems->Add(author);
                            listview->SubItems->Add(publisher);
                            listview->SubItems->Add(productionYear);
                            listview->SubItems->Add(status);
                            listview->SubItems->Add(copies);
                            this->listView1->Items->Add(this->listview);
                        }
                    }
                }
                else
                {
                    string msg = "No subscriber exists with \nthis " + subscriber_ID + " ID";
                    string head = "Error!";
                    message^ obj = gcnew message(this, msg, head);
                    obj->ShowDialog();
                    this->borrowsubinfoinput->Text = "";
                    this->borrow->Hide();
                }
            }
        }
        else
        {
            string msg = "Please fill the subscriber info!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
    }
           //borrowlist ok butten (after selection)
    private: System::Void borrowlistokbtn_Click(System::Object^ sender, System::EventArgs^ e) {
        //now store all contents in listview
        for (int i = 0; i < this->listView1->SelectedItems->Count; i++)
        {
            listview = gcnew Windows::Forms::ListViewItem(this->listView1->SelectedItems[i]->SubItems[0]->Text);
            listview->SubItems->Add(this->listView1->SelectedItems[i]->SubItems[1]->Text);
            listview->SubItems->Add(this->listView1->SelectedItems[i]->SubItems[2]->Text);
            listview->SubItems->Add(this->listView1->SelectedItems[i]->SubItems[3]->Text);
            listview->SubItems->Add(this->listView1->SelectedItems[i]->SubItems[4]->Text);
            listview->SubItems->Add(this->listView1->SelectedItems[i]->SubItems[5]->Text);
            listview->SubItems->Add(this->listView1->SelectedItems[i]->SubItems[6]->Text);
            listview->SubItems->Add(this->listView1->SelectedItems[i]->SubItems[7]->Text);
            listview->SubItems->Add(this->listView1->SelectedItems[i]->SubItems[8]->Text);
            listview->SubItems->Add(this->listView1->SelectedItems[i]->SubItems[9]->Text);
            this->listView2->Items->Add(this->listview);
        }
        this->listView1->Hide();
        this->borrowlistokbtn->Hide();
        this->selecteditempnl->Show();
        this->doneselection->Show();
        this->listView2->Show();
        this->reselect->Show();
    }
           //done selection butten
    private: System::Void doneselection_Click_1(System::Object^ sender, System::EventArgs^ e) {
        string input = msclr::interop::marshal_as< std::string >(this->borrowsubinfoinput->Text);//String^ to string
        stringstream in;
        in << input;
        string subscriber_ID, Name;
        getline(in, subscriber_ID, ',');
        getline(in, Name, '\n');
        auto it = find(sub.begin(), sub.end(), subscribers(subscriber_ID, Name));
        map<int, library> search;
        int i = 1;
        if (it != sub.end())
        {
            string data;
            for (auto it2 : lib)
            {
                stringstream sub2;
                sub2 << it2.sptostring();
                while (getline(sub2, data, '\n'))
                {
                    stringstream sub3;
                    sub3 << data;
                    string title, catagory,
                        author,
                        publisher,
                        status,
                        production_year,
                        copies,
                        item_id;
                    getline(sub3, item_id, ','); getline(sub3, catagory, ',');	getline(sub3, title, ',');	getline(sub3, author, ',');	getline(sub3, publisher, ','), getline(sub3, production_year, ',');	getline(sub3, status, ',');	getline(sub3, copies, '\n');
                    if (catagory == "book")
                    {
                        //store an object of library in search with above attributes
                        search[i] = library(it2.getlibraryid(), it2.getlibrartname(), { title, author, publisher, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), status, stoi(item_id, nullptr, 10) });
                        i = i + 1;
                    }
                    if (catagory == "article")
                        //store an object of library in search with above attributes
                    {
                        search[i] = library(it2.getlibraryid(), it2.getlibrartname(), { title, author, publisher, status, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), stoi(item_id, nullptr, 10) });
                        i = i + 1;
                    }
                    if (catagory == "digital media")
                    {
                        //store an object of library in search with above attributes
                        search[i] = library(it2.getlibraryid(), it2.getlibrartname(), { title, author, publisher, stoi(production_year, nullptr, 10), status, stoi(copies, nullptr, 10), stoi(item_id, nullptr, 10) });
                        i = i + 1;
                    }
                }
            }
            string choice;
            int y = 0;
            //Printing starts now
            choice = "";
            if (this->listView2->Items->Count != 0)
            {
                String^ choise;
                for (int i = 0; i < this->listView2->Items->Count; i++)
                {
                    choise = this->listView2->Items[i]->SubItems[0]->Text;
                    string item, ch;
                    item += msclr::interop::marshal_as< string >(choise);
                    stringstream ss;
                    ss << item;
                    ss >> ch;
                    choice = choice + ch + ",";
                }
                stringstream alpha;
                bool sorry = 0;
                alpha << choice;
                borrowingrecord cu;
                auto it = find(sub.begin(), sub.end(), subscribers(subscriber_ID, Name));
                while (getline(alpha, choice, ','))
               {
                    auto it5 = search.find(stoi(choice, nullptr, 10));
                    if (it5 != search.end())//if choice is present in menu
                    {
                        bool y = 0;
                        it5->second;
                        auto it6 = find(lib.begin(), lib.end(), library(it5->second.getlibraryid(), it5->second.getlibrartname()));
                        bool x = it6->equal(it5->second.sptostring());
                        if (x == 1)
                        {
                            //sets that content to the subscriber with borrow date(current date)
                            search.at(stoi(choice, nullptr, 10)).equal(search.at(stoi(choice, nullptr, 10)).sptostring());
                            cu.set({ it->getsubsriberid(),it->getsubsriberTYPE(),it->getsubscriberNAME(),it->getsubscriberaddress(),it->getsubscriberPHONE(),it->getsubscriberEMAIL() }, search.at(stoi(choice, nullptr, 10)));
                        }
                        else if (x == 0)
                        {
                            sorry = 1;
                            string msg = "Sorry there is no copy of \nthis " + choice + " Sr!";
                            string head = "Sorry!";
                            message^ obj = gcnew message(this, msg, head);
                            obj->ShowDialog();
                            this->viewlistbtn->Show();
                        }
                    }
                }
                borr.push_back(cu);//add that record in borrow
                if (sorry == 0)
                {
                    string msg = "You have borrowed the item(s)\nsuccessfully";
                    string head = "Success";
                    message^ obj = gcnew message(this, msg, head);
                    obj->ShowDialog();
                    //saveinfile();
                    this->viewlistbtn->Show();
                }
                this->borrow->Hide();
                this->listView2->Items->Clear();
                this->listView1->Items->Clear();
                this->borrowsubinfoinput->Text = "";
            }
            else
            {
                string msg = "Selected list is empty!";
                string head = "Error!";
                message^ obj = gcnew message(this, msg, head);
                obj->ShowDialog();
            }
        }
    }
           //reselect butten
    private: System::Void reselect_Click_1(System::Object^ sender, System::EventArgs^ e) {
        this->listView1->Show();
        this->borrowlistokbtn->Show();
        this->selecteditempnl->Hide();
        this->listView2->Items->Clear();
        this->listView2->Hide();
        this->reselect->Hide();
        this->doneselection->Hide();
    }
           //borrow back butten
    private: System::Void button9_Click_2(System::Object^ sender, System::EventArgs^ e) {
        this->listView1->Items->Clear();
        this->borrowsubinfoinput->Text = "";
        this->viewlistbtn->Show();
        this->borrow->Hide();
    }
           //add digital ok butten
    private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
        string input = msclr::interop::marshal_as< std::string >(this->adddigitaltxt->Text);//String^ to string
        if (input != "")
        {
            stringstream in;
            in << input;
            string libraryid, name;
            string title, author, publisher, status,
                production_year, copies;
            getline(in, libraryid, ',');
            getline(in, name, ',');
            getline(in, title, ',');
            getline(in, author, ',');
            getline(in, publisher, ',');
            getline(in, status, ',');
            getline(in, production_year, ',');
            getline(in, copies, '\n');
            //check for validations
            if (this->isValidLibraryName(name) && this->isValidLibraryId(libraryid) && this->isValidAuthor(author) && this->isValidPublisher(publisher) && this->isValidProductionYear(production_year) && this->isValidCopies(copies))
            {
                auto it = find(lib.begin(), lib.end(), library(libraryid, name));
                if (it != lib.end())
                {
                    //add digital if library found
                    it->setdigitalmedia({ title, author, publisher, stoi(production_year, nullptr, 10), status, stoi(copies, nullptr, 10),global_iteamid });
                    global_iteamid += 1;
                    string msg = "Digital has been added successfully";
                    string head = "Success";
                    message^ obj = gcnew message(this, msg, head);
                    this->adddigitaltxt->Text = "";
                    obj->ShowDialog();
                    this->digitaladd->Hide();
                }
                else
                {
                    string msg = "NO LIBRARY FOUND WITH THIS " + libraryid + " ID \nFIRST ADD LIBRARY THAN BOOK";
                    string head = "Error";
                    message^ obj = gcnew message(this, msg, head);
                    this->adddigitaltxt->Text = "";
                    obj->ShowDialog();
                    this->digitaladd->Hide();
                    this->addlib->Show();
                }
            }
        }
        else
        {
            string msg = "Please enter  the info first!";
            string head = "Error!";
            message^ obj = gcnew message(this, msg, head);
            obj->ShowDialog();
        }
    }
     
           //borrow load
    private: System::Void borrow_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        this->borrow->Dock = System::Windows::Forms::DockStyle::Fill;
    }
           //addeditdelete load
    private: System::Void addeditdelete_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        this->addeditdelete->Dock = System::Windows::Forms::DockStyle::Fill;
    }
           //viewupduepnl load
    private: System::Void viewupduepnl_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        this->viewupduepnl->Dock = System::Windows::Forms::DockStyle::Fill;
    }
           //returnpnl load
    private: System::Void returnpnl_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        this->returnpnl->Dock = System::Windows::Forms::DockStyle::Fill;
    }
           //Exit butten
    private: System::Void button37_Click(System::Object^ sender, System::EventArgs^ e) {
        string msg = "Thanks for visiting us";
        string head = "Thank you!";
        message^ obj = gcnew message(this, msg, head);
        obj->ShowDialog();
        fstream file;
        file.open("library.CSV", ios::out);
        file << "Library ID" << "," << "Name" << endl;
        //cout << setw(20) << left << "Library ID" << "Name" << endl;
        sort(lib.begin(), lib.end());
        for (auto it : lib)
        {

            file << it.sptostring_library() << endl;
            cout << it.tostring_library() << endl;
        }
        file.close();
        fstream file2;
        fstream file3;
        file3.open("items.CSV", ios::out);
        file3 << "Item ID" << "," << "LibraryID" << "," << "Category" << "," << "Title" << "," << "Author" << "," "Publisher" << "," "Production_Year" << "," << "Status" << "," << " Copies\n";
        //cout << setw(17) << left << "Item ID" << setw(19) << left << "LibraryID" << setw(18) << left << "Category" << setw(35) << left << "Title" << setw(16) << left << "Author" << setw(19) << left << "Publisher" << setw(20) << left << "Production_Year" << setw(16) << left << "Status" << " Copies\n";
        string data;
        sort(lib.begin(), lib.end());
        for (auto it = lib.begin(); it != lib.end(); it++)
        {
            it->sortinfo();
            stringstream sub;
            sub << it->sptostring();
            while (getline(sub, data, '\n'))
            {
                string Item_ID, Category, Title, Author, Publisher, prod_Year, Status, Copies;
                stringstream sub2;
                sub2 << data;
                getline(sub2, Item_ID, ','); getline(sub2, Category, ','); getline(sub2, Title, ','); getline(sub2, Author, ','); getline(sub2, Publisher, ','); getline(sub2, prod_Year, ','); getline(sub2, Status, ','); getline(sub2, Copies);
                cout << setw(17) << left << Item_ID << setw(19) << left << it->getlibraryid() << setw(18) << left << Category << setw(35) << left << Title << setw(16) << left << Author << setw(19) << left << Publisher << setw(20) << left << prod_Year << setw(18) << left << Status << Copies << "\n";
                file3 << Item_ID << "," << it->getlibraryid() << "," << Category << "," << Title << "," << Author << "," << Publisher << "," << prod_Year << "," << Status << "," << Copies << "\n";
            }

        }
        file3.close();
        fstream file4;
        file4.open("subscribers.CSV", ios::out);
        file4 << "Subscriber ID" << "," << "Type" << "," "Name" << "," << "Address" << "," << "Phone" << "," << "Email\n";
        //cout << setw(23) << left << "Subscriber ID" << setw(14) << left << "Type" << setw(30) << left << "Name" << setw(30) << left << "Address" << setw(20) << left << "Phone" << "Email\n";
        sort(sub.begin(), sub.end());
        for (auto it : sub)
        {
            file4 << it.sptostring();
            cout << it.tostring() << endl;
        }
        file4.close();
        fstream file5;
        file5.open("borrowing.CSV", ios::out);
        file5 << "SUBSCRIBER ID" << "," << "Borrow Date" << "," << "content id" << "," << "Return Date" << "," << "Fee\n";

        cout << setw(24) << left << "SUBSCRIBER ID" << setw(32) << left << "Borrow Date" << setw(24) << left << "content id" << setw(23) << left << "Return Date" << "Fee\n";
        for (auto it : borr)
        {
            file5 << it.sptostring();
            cout << it.tostring();
        }
        file5.close();
        Application::Exit();
    }
           //home butten
private: System::Void button38_Click(System::Object^ sender, System::EventArgs^ e) {
    this->viewupduepnl->Hide();
    this->borrow->Hide();
    this->returnpnl->Hide();
    this->addeditdelete->Hide();
}
       //add/edit/delete butten
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    this->addlib->Hide();
    this->bookadd->Hide();
    this->articleadd->Hide();
    this->digitaladd->Hide();
    this->subadd->Hide();
    this->deletesubpnl->Hide();
    this->deletelibrarypnl->Hide();
    this->deletedigitalpnl->Hide();
    this->dletearticlepnl->Hide();
    this->deletebookpnl->Hide();
    this->editsubscriberpnl->Hide();
    this->editlibpnl->Hide();
    this->editdigitalpnl->Hide();
    this->editarticlepnl->Hide();
    this->editbookpnl->Hide();

    this->viewupduepnl->Hide();
    this->borrow->Hide();
    this->returnpnl->Hide();


    this->addeditdelete->Show();
}
       //borrow btn
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    this->selecteditempnl->Hide();
    this->listView1->Hide();
    this->listView2->Hide();
    this->doneselection->Hide();
    this->borrowlistokbtn->Hide();
    this->reselect->Hide();
    this->viewupduepnl->Hide();
    this->returnpnl->Hide();
    this->addeditdelete->Hide();
    this->borrow->Show();
    this->viewlistbtn->Show();
}
       //return btn
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
    this->returnbookpnl->Hide();
    this->returnarticlepnl->Hide();
    this->returndigitalpnl->Hide();

    this->viewupduepnl->Hide();
    this->borrow->Hide();
    this->addeditdelete->Hide();

    this->returnpnl->Show();
}
       //viewoverdew btn
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
    this->listView3->Hide();
    //this->viewupduepnl->Dock = System::Windows::Forms::DockStyle::Fill;
    this->viewupduepnl->Show();

    this->borrow->Hide();
    this->addeditdelete->Hide();
    this->returnpnl->Hide();
}


}; 
}
//validation functions
string isValidLibraryId(string id)
{
Libraryid:
    for (int i = 0; i < id.length(); i++)
    {
        if (!(isdigit(id[i])))
        {
            cout << "Error! Library id must contain only digits. Please try again...\n";
            cout << "Enter Library id: ";
            cin >> id;
            goto Libraryid;
        }
    }

    return id;
}
string isValidSubscriberid(string id)
{
    //Subscriber:
    for (int i = 0; i < id.length(); i++)
    {
        if (!(isdigit(id[i])))
        {
            id = "Subscriber id must contain only digits.\nPlease try again...";
            return id;
            // cout << "Enter Subscriber id: ";
             //cin >> id;
             //goto Subscriber;
        }
    }

    return id = "valid";
}
string isValidSubscriberType(string stype)
{
sstype:
    if (stype == "regular" || stype == "Regular" || stype == "REGULAR" || stype == "golden" || stype == "Golden" || stype == "GOLDEN") {
        return stype;
    }
    else {
        cout << "Error! Subscriber type should be 'Golden' or 'Regular'. Please try again....\n";
        cout << "Enter Subscriber type: ";
        getline(cin, stype, '\n');
        goto sstype;
    }

}
string isValidSubscriberName(string sname) {
Subscribername:
    if (sname.length() > 30)
    {
        cout << "Error! Subscriber name length should be of 30 or less. Please try again....\n";
        cout << "Enter Subscriber name: ";
        getline(cin, sname, '\n');
        goto Subscribername;
    }
    for (int i = 0; i < sname.length(); i++)
    {
        if (!(isalpha(sname[i]) || sname[i] == 32))
        {
            cout << "Error! Subscriber name should consisit alphabet or space. Please try again....\n";
            cout << "Enter Subcsriber name: ";
            getline(cin, sname, '\n');
            goto Subscribername;
        }
    }
    return sname;

}

string isValidSubscriberPhone(string pNo) {
SubscriberPhone:
    if (pNo.length() == 11)
    {
        for (int i = 0; i < pNo.length(); i++)
        {
            if (!(isdigit(pNo[i])))
            {
                cout << "Error! Phone no must contain only digits. Please try again...\n";
                cout << "Enter Subscriber Phone no: ";
                getline(cin, pNo, '\n');
                goto SubscriberPhone;
            }
        }
    }
    else
    {
        cout << "Error! Subscriber Phone no length should be of 11. Please try again....\n";
        cout << "Enter Subscriber Phone no: ";
        getline(cin, pNo, '\n');
        goto SubscriberPhone;
    }

    return pNo;
}
string isValidSubscriberEmail(string semail)
{
email:
    size_t x = semail.find('@');
    if (x != string::npos)
    {
        string key;
        key = semail.substr(x + 1);
        if (!(key == "gmail.com" || key == "hotmail.com" || key == "yahoo.com"))
        {
            cout << "Error! email must contain 'gmail.com' or 'hotmail.com' or 'yahoo.com' as domain Please try again...\n";
            cout << "Enter email: ";
            getline(cin, semail, '\n');
            goto email;
        }
    }
    else {
        cout << "Error! email must contain domain Please try again...\n";
        cout << "Enter email: ";
        getline(cin, semail, '\n');
        goto email;
    }
    return semail;
}
string isValidAuthor(string auth) {
Author:
    for (int i = 0; i < auth.length(); i++)
    {
        if (!(isalpha(auth[i]) || auth[i] == 32))
        {
            cout << "Error! Author name should consisit alphabet or space. Please try again....\n";
            cout << "Enter Author name: ";
            getline(cin, auth, '\n');
            goto Author;
        }
    }
    return auth;
}
string isValidPublisher(string pub) {

Publisher:
    for (int i = 0; i < pub.length(); i++)
    {
        if (!(isalpha(pub[i]) || pub[i] == 32))
        {
            cout << "Error! Publisher name should consisit alphabet or space. Please try again....\n";
            cout << "Enter Publisher name: ";
            getline(cin, pub, '\n');
            goto Publisher;
        }
    }
    return pub;
}
string isValidProductionYear(string year) {
    int pyear;
    bool flag = 0;
    while (flag == 0)
    {
        try
        {
            pyear = stoi(year, nullptr, 10);
            flag = 1;
        }
        catch (invalid_argument ch)
        {
            cout << "entered numeric value for year\n";
            cin >> year;
            cin.ignore();
        }
    }
proyear:
    if (pyear > 2020 || pyear < 1800)
    {
        cout << "Error! Production year must be greater than 1800 and less or equal to 2020. Please try again....\n";
        cout << "Enter Production year: ";
        cin >> pyear;
        cin.ignore();
        goto proyear;
    }
    return std::to_string(pyear);
}
string isValidCopies(string copies)
{
    int copy;
    bool flag = 0;
    while (flag == 0)
    {
        try
        {
            copy = stoi(copies, nullptr, 10);
            flag = 1;
        }
        catch (invalid_argument ch)
        {
            cout << "entered numeric value for copies\n";
            cin >> copies;
            cin.ignore();
        }
    }
copies:
    if (copy < 0)
    {
        cout << "Error! No of copies must not be less than 0 or  Please try again....\n";
        cout << "Enter No of copies: ";
        cin >> copy;
        cin.ignore();
        goto copies;
    }

    return std::to_string(copy);
}
//
void increase(int itemid)
{
    for (auto it = lib.begin(); it != lib.end(); it++)
    {
        it->increscopies(itemid);
    }
}
void saveinfile()
{
    fstream file;
    file.open("library.CSV", ios::out);
    file << "Library ID" << "," << "Name" << endl;
    sort(lib.begin(), lib.end());
    for (auto it : lib)
    {

        file << it.sptostring_library() << endl;
    }
    file.close();
    fstream file2;
    fstream file3;
    file3.open("items.CSV", ios::out);
    file3 << "Item ID" << "," << "LibraryID" << "," << "Category" << "," << "Title" << "," << "Author" << "," "Publisher" << "," "Production_Year" << "," << "Status" << "," << " Copies\n";
    string data;
    sort(lib.begin(), lib.end());
    for (auto it = lib.begin(); it != lib.end(); it++)
    {
        it->sortinfo();
        stringstream sub;
        sub << it->sptostring();
        while (getline(sub, data, '\n'))
        {
            string Item_ID, Category, Title, Author, Publisher, prod_Year, Status, Copies;
            stringstream sub2;
            sub2 << data;
            getline(sub2, Item_ID, ','); getline(sub2, Category, ','); getline(sub2, Title, ','); getline(sub2, Author, ','); getline(sub2, Publisher, ','); getline(sub2, prod_Year, ','); getline(sub2, Status, ','); getline(sub2, Copies);
            file3 << Item_ID << "," << it->getlibraryid() << "," << Category << "," << Title << "," << Author << "," << Publisher << "," << prod_Year << "," << Status << "," << Copies << "\n";
        }

    }
    file3.close();
    fstream file4;
    file4.open("subscribers.CSV", ios::out);
    file4 << "Subscriber ID" << "," << "Type" << "," "Name" << "," << "Address" << "," << "Phone" << "," << "Email\n";
    sort(sub.begin(), sub.end());
    for (auto it : sub)
    {
        file4 << it.sptostring();

    }
    file4.close();
    fstream file5;
    file5.open("borrowing.CSV", ios::out);
    file5 << "SUBSCRIBER ID" << "," << "Borrow Date" << "," << "content id" << "," << "Return Date" << "," << "Fee\n";
    for (auto it : borr)
    {
        file5 << it.sptostring();

    }
    file5.close();
}
void  updatebookinborrow(books that)
{
    for (auto it = borr.begin(); it != borr.end(); it++)
    {
        it->editbook(that);
    }
}
void  updatearticleinborrow(articles that)
{
    for (auto it = borr.begin(); it != borr.end(); it++)
    {
        it->editarticle(that);
    }
}
void  updatedigitalinborrow(digitalmedia that)
{
    for (auto it = borr.begin(); it != borr.end(); it++)
    {
        it->editdigitalmedia(that);
    }
}
void deletebookinborrow(int itemid)
{
    for (auto it = borr.begin(); it != borr.end(); it++)
    {
        it->deleteitem(itemid);
    }
}
void deletearticleinborrow(int itemid)
{
    for (auto it = borr.begin(); it != borr.end(); it++)
    {
        it->deleteitem(itemid);
    }
}
void deletedigitalmediainborrow(int itemid)
{
    for (auto it = borr.begin(); it != borr.end(); it++)
    {
        it->deleteitem(itemid);
    }
}
void uniquekey(int itemid)
{
    for (auto it = lib.begin(); it != lib.end(); it++)
    {
        it->uniquekey(itemid);

    }
    for (auto it = borr.begin(); it != borr.end(); it++)
    {
        it->uniquekey(itemid);
    }
}
void edilibraryinborrow(string findid, string findname, string replaceid, string replacename)
{
    for (auto it = borr.begin(); it != borr.end(); it++)
    {
        it->editlibray(findid, findname, replaceid, replacename);
    }
}
void deletelibraryinborrow(string itemid, string name)
{
    for (auto it = borr.begin(); it != borr.end(); it++)
    {
        it->deletelibrary(itemid, name);
    }
}
void loadlibrraryfile()
{
    fstream file;
    string record;
    file.open("library.CSV", ios::in);
    if (!(file.fail()))
    {
        bool x = 0;
        getline(file, record, '\n');
        while (file)
        {
            if (x == 1)
            {
                string id, name;
                stringstream data;
                data << record;
                getline(data, id, ','); getline(data, name);
                lib.emplace_back(id, name);
            }
            x = 1;
            getline(file, record, '\n');
        }
    }
    file.close();
}
void loaditemsfile()
{
    fstream file;
    string record;
    file.open("items.CSV", ios::in);
    if (!(file.fail()))
    {
        bool x = 0;
        getline(file, record, '\n');
        while (file)
        {
            if (x == 1)
            {
                global_iteamid = global_iteamid + 1;
                stringstream sub;
                sub << record;
                string ItemID, Library_ID, Category, Title, Author, Publisher, prod_Year, Status, Copies;
                getline(sub, ItemID, ','); getline(sub, Library_ID, ','); getline(sub, Category, ','); getline(sub, Title, ','); getline(sub, Author, ','); getline(sub, Publisher, ','); getline(sub, prod_Year, ','); getline(sub, Status, ','); getline(sub, Copies, '\n');
                for (auto it = lib.begin(); it != lib.end(); it++)
                {
                    if (it->getlibraryid() == Library_ID)
                    {
                        if (Category == "book")
                        {
                            it->setbook({ Title,Author,Publisher,stoi(prod_Year,nullptr,10),stoi(Copies,nullptr,10),Status,stoi(ItemID,nullptr,10) });
                        }
                        if (Category == "article")
                        {

                            it->setarticle({ Title,Author,Publisher,Status,stoi(prod_Year,nullptr,10),stoi(Copies,nullptr,10),stoi(ItemID,nullptr,10) });
                        }
                        if (Category == "digital media")
                        {

                            it->setdigitalmedia({ Title,Author,Publisher,stoi(prod_Year,nullptr,10),Status,stoi(Copies,nullptr,10),stoi(ItemID,nullptr,10) });
                        }
                    }
                }

            }
            x = 1;
            getline(file, record, '\n');
        }
    }
    file.close();
}
void loadsubscriberfile()
{
    string record;
    fstream file;
    file.open("subscribers.CSV", ios::in);
    if (!(file.fail()))
    {
        bool x = 0;
        getline(file, record, '\n');
        while (file)
        {
            if (x == 1)
            {
                string SubscriberID, Type, Name, Address, Phone, Email;
                stringstream sub2;
                sub2 << record;
                getline(sub2, SubscriberID, ','); getline(sub2, Type, ','); getline(sub2, Name, ','); getline(sub2, Address, ','); getline(sub2, Phone, ','); getline(sub2, Email);
                sub.push_back({ SubscriberID,Type,Name,Address,Phone,Email });
            }
            x = 1;
            getline(file, record, '\n');
        }
    }

}
void loadborrowfile()
{
    string record;
    fstream file;
    file.open("borrowing.CSV", ios::in);
    if (!(file.fail()))
    {
        getline(file, record, '\n');
        bool x = 0;
        while (file)
        {
            if (x == 1)
            {

                string libraryid, libraryname;
                string subscriberID, BorrowDate, contentID, ReturnDate, Fee, subscribername;
                stringstream sub2;
                string iteminfo;
                sub2 << record;
                getline(sub2, subscriberID, ','); getline(sub2, BorrowDate, ','); getline(sub2, contentID, ','); getline(sub2, ReturnDate, ','); getline(sub2, Fee);
                for (auto it = lib.begin(); it != lib.end(); it++)
                {
                    if (it->getnameonid(stoi(contentID, nullptr, 10)) != "")
                    {
                        libraryid = it->getlibraryid();
                        libraryname = it->getlibrartname();
                        iteminfo = it->getnameonid(stoi(contentID, nullptr, 10));
                    }
                }
                stringstream all;
                all << iteminfo;
                string item_id, catagory, title, author, publisher, production_year, status, copies;
                getline(all, item_id, ','); getline(all, catagory, ','); getline(all, title, ','); getline(all, author, ','); getline(all, publisher, ','); getline(all, production_year, ','); getline(all, status, ','); getline(all, copies);
                bool flag = 0;
                for (auto it = borr.begin(); it != borr.end(); it++)
                {
                    if (it->getsubscriberid() == subscriberID)
                    {
                        flag = 1;
                        if (catagory == "book")
                        {
                            it->setlibrary({ libraryid,libraryname,{ title, author, publisher, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), status, stoi(item_id, nullptr, 10) } });
                            it->setborrowdate(stoi(item_id, nullptr, 10), BorrowDate);
                            it->setreturndate(stoi(item_id, nullptr, 10), ReturnDate);
                            it->setfine(stoi(item_id, nullptr, 10), stoi(Fee, nullptr, 10));
                        }
                        if (catagory == "article")
                        {
                            it->setlibrary({ libraryid,libraryname,{ title,author,publisher,status,stoi(production_year,nullptr,10),stoi(copies,nullptr,10),stoi(item_id,nullptr,10) } });
                            it->setborrowdate(stoi(item_id, nullptr, 10), BorrowDate);
                            it->setreturndate(stoi(item_id, nullptr, 10), ReturnDate);
                            it->setfine(stoi(item_id, nullptr, 10), stoi(Fee, nullptr, 10));
                        }
                        if (catagory == "digital media")
                        {
                            it->setlibrary({ libraryid,libraryname,{ title,author,publisher,stoi(production_year,nullptr,10),status,stoi(copies,nullptr,10),stoi(item_id,nullptr,10) } });
                            it->setborrowdate(stoi(item_id, nullptr, 10), BorrowDate);
                            it->setreturndate(stoi(item_id, nullptr, 10), ReturnDate);
                            it->setfine(stoi(item_id, nullptr, 10), stoi(Fee, nullptr, 10));
                        }

                    }
                }
                if (flag == 0)
                {
                    for (auto it = sub.begin(); it != sub.end(); it++)
                    {
                        if (it->getsubsriberid() == subscriberID)
                        {
                            subscribername = it->getsubscriberNAME();
                        }
                    }
                    auto it = find(sub.begin(), sub.end(), subscribers(subscriberID, subscribername));
                    if (catagory == "book")
                    {
                        subscribers s{ it->getsubsriberid(),it->getsubsriberTYPE(),it->getsubscriberNAME(),it->getsubscriberaddress(),it->getsubscriberPHONE(),it->getsubscriberEMAIL() };
                        library l{ libraryid,libraryname,{ title, author, publisher, stoi(production_year, nullptr, 10), stoi(copies, nullptr, 10), status, stoi(item_id, nullptr, 10) } };
                        borr.emplace_back(l, s, item_id, BorrowDate, ReturnDate, Fee);
                    }
                    if (catagory == "article")
                    {
                        subscribers s{ it->getsubsriberid(),it->getsubsriberTYPE(),it->getsubscriberNAME(),it->getsubscriberaddress(),it->getsubscriberPHONE(),it->getsubscriberEMAIL() };
                        library l{ libraryid,libraryname,{ title,author,publisher,status,stoi(production_year,nullptr,10),stoi(copies,nullptr,10),stoi(item_id,nullptr,10) } };
                        borr.emplace_back(l, s, item_id, BorrowDate, ReturnDate, Fee);

                    }
                    if (catagory == "digital media")
                    {
                        subscribers s{ it->getsubsriberid(),it->getsubsriberTYPE(),it->getsubscriberNAME(),it->getsubscriberaddress(),it->getsubscriberPHONE(),it->getsubscriberEMAIL() };
                        library l{ libraryid,libraryname,{ title,author,publisher,stoi(production_year,nullptr,10),status,stoi(copies,nullptr,10),stoi(item_id,nullptr,10) } };
                        borr.emplace_back(l, s, item_id, BorrowDate, ReturnDate, Fee);

                    }
                }

            }
            x = 1;
            getline(file, record, '\n');
        }
    }
    //
}