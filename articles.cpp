#include "articles.h"
#include<string>
#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
articles::articles() :title(""), author(""), publisher(""), status(""), production_year(0), copies(0), item_id(0)
{}//set default values
articles::articles(string t, string a) : title(t), author(a), publisher(""), status(""), production_year(0), copies(0), item_id(0)
{}//set two values and others to default
articles::articles(string t, string a, string p, string s, int prd, int c, int id) : title(t), author(isValidAuthor(a)), publisher(isValidPublisher(p)), status(s), production_year(isValidProductionYear(prd)), copies(isValidCopies(c)), item_id(id)
{}//set all the values
bool operator<(articles& left, articles& right)
{
	if (left.getarticleitemid() < right.getarticleitemid())
	{
		return true;//if id is smaller then return true
	}
	return false;
}
void articles::decreaseoneinitemid()
{
	this->item_id = this->item_id - 1;//decrease of 1 in id
}
void articles::increasecopies(int itemid)
{
	if (this->item_id = itemid)
	{
		this->copies += 1;//increment in copies if item id matches
	}
}
articles& articles::setarticle(string t, string a, string p, string s, int prd, int c, int id)
{
	//first check the validation of parameters and then set them
	title = t;  author = isValidAuthor(a);  publisher = isValidPublisher(p); status = s; production_year = isValidProductionYear(prd); copies = isValidCopies(c); item_id = id;
	return *this;//return the object of article
}

bool articles::copiesdecrement()
{
	if (this->copies == 0)
	{
		return false;//if copies are 0 then decrement is invalid so return false
	}
	else
	{
		this->copies = this->copies - 1;
		return true;//if copies>0 then decrease the copy and return true
	}

}

string articles::tostring()
{
	stringstream sub;
	string data;
	/*send data in required format to sub*/
	sub <<  std::to_string(this->item_id) << "," << "article" << ","<< this->title << ","<< this->author << "," << this->publisher << ","<< std::to_string(this->production_year) << "," << this->status <<","<< std::to_string(this->copies);
	getline(sub, data);//store data from sub to data 
	return data;//return data string
}

string articles::sptostring()const
{
	string data;
	/*store data in required format in data string*/
	data = std::to_string(this->item_id) + ',' + "article" + ',' + this->title + ',' + this->author + ',' + this->publisher + ',' + std::to_string(this->production_year) + ',' + this->status + ',' + std::to_string(this->copies);
	return data;//return string
}

bool operator == (const articles& left, const articles& right)
{
	/*if title is same*/                                    /*if author is same*/
	if (!(_stricmp(left.title.c_str(), right.title.c_str())) && !(_stricmp(left.author.c_str(), right.author.c_str())))
	{
		return true;//return true
	}
	else
	{
		return false;
	}
}
string articles::getarticletitle() const
{
	return this->title;//return title
}
string articles::getarticleauthor() const
{
	return this->author;
}
string articles::getarticlestatus() const
{
	return this->status;
}
string articles::getarticlepublisher() const
{
	return this->publisher;
}
int articles::getarticleprodyear() const
{
	return this->production_year;
}
int articles::getarticlecopies() const
{
	return this->copies;
}
int articles::getarticleitemid() const
{
	return this->item_id;
}
string articles::isValidAuthor(string auth)
{
Author:
	for (int i = 0; i < auth.length(); i++)
	{        /*if author not consists of alphabets and sapce*/
		if (!(isalpha(auth[i]) || auth[i] == 32))
		{
			cout << "Error! Author name should consisit alphabet or space. Please try again....\n";
			cout << "Enter Author name: ";
			getline(cin, auth, '\n');//take input again
			goto Author;//recheck the the validation 
		}
	}
	return auth;
}
string articles::isValidPublisher(string pub)
{
Publisher:

	for (int i = 0; i < pub.length(); i++)
	{/*if publisher not consists of alphabets and sapce*/
		if (!(isalpha(pub[i]) || pub[i] == 32))
		{
			cout << "Error! Publisher name should consisit alphabet or space. Please try again....\n";
			cout << "Enter Publisher name: ";
			getline(cin, pub, '\n');//take input again
			goto Publisher;//recheck the the validation
		}
	}
	return pub;
}
int articles::isValidProductionYear(int pyear)
{

proyear:
	/*if production year not between 2020 and 1800*/
	if (pyear > 2020 || pyear < 1800)
	{
		cout << "Error! Production year must be greater than 1800 and less or equal to 2020. Please try again....\n";
		cout << "Enter Production year: ";
		cin >> pyear;//take input again
		cin.ignore();
		goto proyear;//recheck the the validation
	}

	return pyear;
}
int articles::isValidCopies(int copy)
{

copies:
	/*if copy is less than 0*/
	if (copy < 0)
	{
		cout << "Error! No of copies must not  be less than 0. Please try again....\n";
		cout << "Enter No of copies: ";
		cin >> copy;//re input
		cin.ignore();
		goto copies;//recheck
	}

	return copy;
}
