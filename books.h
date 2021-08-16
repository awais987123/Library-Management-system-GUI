#pragma once
#ifndef BOOKS_H
#define BOOKS_H
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
class books // declaration of class
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
	books();//default constructor
	books(string t, string a, string p, int prd, int c, string s, int i);//parameterized constructor
	books(string t, string a);//overloaded parameterized constructor for two parameters
	books& setbook(string t, string a, string p, int prd, int c, string s, int id);//setter for all variables
	string tostring() const;//return a string having all the values of member variables
	string sptostring()const;//return a string having all the values of member variables seperated by ','
	friend bool operator ==(const books& left, const books& right);//operator overload for comparison
	bool copiesdecrement();//to decrease one from no of copies
	string getbooktitle() const;//getter for title
	string getbookauthor() const;//getter for author
	string getbookstatus() const;//getter for status
	string getbookpublisher() const;//getter for publisher
	int getbookprodyear() const;//getter for production year
	int getbookcopies() const;//getter for copies
	int getbookitemid() const;//getter for item id
	string isValidAuthor(string);//validation check for author
	string isValidPublisher(string);//validation check for publisher
	int isValidProductionYear(int);//validation check for production year
	int isValidCopies(int);//validation check for copies
	void incresebookcopies(int itemid);//increase the number of copies when an book is returned
	void decreaseoneinitemid();//decrese in item id by one when an book is deleted
	friend bool operator<(books& left, books& right);//operater overload for '<'
};
#endif // !BOOKS_H

