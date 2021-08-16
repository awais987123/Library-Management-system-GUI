#pragma once
#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
class digitalmedia//declaration of class
{
private://members variables
	string title,
		author,
		publisher,
		status;
	int production_year,
		copies,
		item_id;
public://member functions
	digitalmedia();//default constructor
	digitalmedia(string t, string a, string p, int prd, string s, int c, int id);//parameterized constructor
	digitalmedia(string t, string a);//overloaded parameterized constructor for two parameters
	digitalmedia& setdigitalmedia(string t, string a, string p, int prd, string s, int c, int id);//setter for all variables
	string tostring();//return a string having all the values of member variables
	bool copiesdecrement();//to decrease one from no of copies
	string sptostring()const;//return a string having all the values of member variables seperated by ','
	friend bool operator == (const digitalmedia& left, const digitalmedia& right);//operator overload for comparison
	string getdigitalmediatitle() const;//getter for title
	string getdigitalmediaauthor() const;//getter for author
	string getdigitalmediastatus() const;//getter for status
	string getdigitalmediapublisher() const;//getter for publisher
	int getdigitalmediaprodyear() const;//getter for production year
	int getdigitalmediacopies() const;//getter for copies
	int getdigitalmediaitemid() const;//getter for item id
	string isValidAuthor(string);//validation check for author
	string isValidPublisher(string);//validation check for publisher
	int isValidProductionYear(int);//validation check for production year
	int isValidCopies(int);//validation check for copies
	void decreaseoneinitemid();//decrese in item id by one when an digital is deleted
	void incresecopies(int itemid);//increase the number of copies when an digital is returned
	friend bool operator<(digitalmedia& left, digitalmedia& right);//operater overload for '<'
};
#endif // !DIGITALMEDIA_H
