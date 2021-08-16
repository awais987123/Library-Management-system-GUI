#include"books.h"
#include<string>
#include<sstream>
#include<iomanip>
#include<iostream>
using namespace std;
books::books() :title(""), author(""), publisher(""), status(""), production_year(0), copies(0), item_id(0)
{}//set default values
books::books(string t, string a) : title(t), author(a), publisher(""), status(""), production_year(0), copies(0), item_id(0)
{}//set two values and others to default
books::books(string t, string a, string p, int prd, int c, string s, int i) : title(t), author(isValidAuthor(a)), publisher(isValidPublisher(p)), status(s), production_year(isValidProductionYear(prd)), copies(isValidCopies(c)), item_id(i)
{}//set all the values
books& books::setbook(string t, string a, string p, int prd, int c, string s, int id)
{
	//first check the validation of parameters and then set them
	title = t;  author = isValidAuthor(a);  publisher = isValidPublisher(p); status = s; production_year = isValidProductionYear(prd); copies = isValidCopies(c); item_id = id;
	return *this;//return the object of book
}
bool operator<(books& left, books& right)
{
	if (left.getbookitemid() < right.getbookitemid())
	{
		return true;//if id is smaller then return true
	}
	return false;
}
string books::tostring() const
{
	stringstream sub;
	string data;
	/*send data in required format to sub*/
	sub << setw(12) << left << std::to_string(this->item_id) << setw(18) << left << "book" << setw(31) << left << this->title << setw(15) << left << this->author << setw(18) << left << this->publisher << setw(19) << left << std::to_string(this->production_year) << setw(18) << left << this->status << std::to_string(this->copies);
	getline(sub, data);//store data from sub to data
	return data;//return data string
}
void books::incresebookcopies(int itemid)
{
	if (this->item_id = itemid)
	{
		this->copies += 1;//increase in copy
	}
}
void books::decreaseoneinitemid()
{
	this->item_id = this->item_id - 1;//decrease in id
}
string books::sptostring()const
{
	string data;
	/*store data in required format in data string*/
	data = std::to_string(this->item_id) + ',' + "book" + ',' + this->title + ',' + this->author + ',' + this->publisher + ',' + std::to_string(this->production_year) + ',' + this->status + ',' + std::to_string(this->copies);
	return data;//return string
}
bool operator == (const books& left, const books& right)
{
	/*if author is same*/                                  /*if title is same*/
	if (!(_stricmp(left.author.c_str(), right.author.c_str())) && !(_stricmp(left.title.c_str(), right.title.c_str())))
	{
		return true;//return true
	}
	else
	{
		return false;
	}
}
bool books::copiesdecrement()
{
	if (this->copies == 0)
	{
		return false;//decrement invalid
	}
	else
	{
		this->copies = this->copies - 1;
		return true;//true and decrease copy
	}

}
string books::getbooktitle() const
{
	return this->title;
}
string books::getbookauthor() const
{
	return this->author;
}
string books::getbookstatus() const
{
	return this->status;
}
string books::getbookpublisher() const
{
	return this->publisher;
}
int books::getbookprodyear() const
{
	return this->production_year;
}
int books::getbookcopies() const
{
	return this->copies;
}
int books::getbookitemid() const
{
	return this->item_id;
}
string books::isValidAuthor(string auth) {
Author:
	for (int i = 0; i < auth.length(); i++)
	{        /*if author not consists of alphabets and sapce*/
		if (!(isalpha(auth[i]) || auth[i] == 32))
		{
			cout << "Error! Author name should consisit alphabet or space. Please try again....\n";
			cout << "Enter Author name: ";
			getline(cin, auth, '\n');//reinput
			goto Author;//recheck
		}
	}
	return auth;
}
string books::isValidPublisher(string pub) {

Publisher:
	for (int i = 0; i < pub.length(); i++)
	{/*if publisher not consists of alphabets and sapce*/
		if (!(isalpha(pub[i]) || pub[i] == 32))
		{
			cout << "Error! Publisher name should consisit alphabet or space. Please try again....\n";
			cout << "Enter Publisher name: ";
			getline(cin, pub, '\n');//reinput
			goto Publisher;//recheck
		}
	}
	return pub;
}
int books::isValidProductionYear(int pyear) {


proyear:
	/*if production year not between 2020 and 1800*/
	if (pyear > 2020 || pyear < 1800)
	{
		cout << "Error! Production year must be greater than 1800 and less or equal to 2020. Please try again....\n";
		cout << "Enter Production year: ";
		cin >> pyear;//re enter
		cin.ignore();
		goto proyear;//recheck
	}

	return pyear;
}
int books::isValidCopies(int copy) {

copies:
	/*if copy is less than 0*/
	if (copy < 0)
	{
		cout << "Error! No of copies must not be less than 0 or  Please try again....\n";
		cout << "Enter No of copies: ";
		cin >> copy;//re enter
		cin.ignore();
		goto copies;//recheck
	}

	return copy;
}
