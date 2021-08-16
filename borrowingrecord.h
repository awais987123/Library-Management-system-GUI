#pragma once
#ifndef BORROWINGRECORD_H
#define BORROWINGRECORD_H
#include"library.h"
#include"subscribers.h"
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace std;
#include<iomanip>
#include<sstream>
#include<ctime>
class borrowingrecord//class declaration
{
private://class member variables
	subscribers subscriber;
	vector<library>lib;
	map<string, string> borrow_dates;
	map<string, string> returndates;
	map<string, int>fine;
public://clas member functions
	borrowingrecord();//default constructor
	borrowingrecord(subscribers that, library them);//parameterized constructer having two parameters
	borrowingrecord(library them, subscribers that, string, string, string, string);//parameterized constructer having all parameters
	borrowingrecord& add(subscribers that, library them);//to add subscriber and library against him
	void set(subscribers that, library them);//setter for subscriber and library
	string tostring();//return string consists of all member variables values
	string sptostring();//return string consists of all member variables values sep by ','
	string getsubscriberid();//to get subscriber id
	string getsubscribername();//return subscriber name
	borrowingrecord setsubscriber(string subscriber_ID, string Type, string Name, string Address, string Phone, string Email,string);//set subscriber in borrowing record
	void setreturndate(int, string);//set return date for content
	void setborrowdate(int, string); //set borrow date for content
	string getborrowdate(int);//return borrow date
	string getreturndate(int);//return return_date
	string dayafteraddingdays(int, int, int, int);//return days after adding days according to subscriber type
	bool isleapyear(int);//check for leap year
	int finecalcculation(int);//return fine
	string getlibrarysptostring();//call library::sptostring
	void deleteitem(int);//delete item record when returned or deleted
	string findbook(string, string);//return the book id if found
	string finddigitalmedia(string, string);//return the digital id if found
	string findarticle(string, string);//return the article id if found
	int finecalcculationforadminview(int item_id);//return fine 
	void editbook(books);//to id book in record
	void editarticle(articles);//to edit article
	void editdigitalmedia(digitalmedia);//edit digital
	void uniquekey(int);//assign unique key to item when a content is deleted
	void editlibray(string, string, string, string);//edit library
	void deletelibrary(string, string);//deletes library
	friend bool operator<(const borrowingrecord&, const borrowingrecord&);//compare record
	void sortinfo();//call lib::sortinfo
	void setlibrary(library);//setter for libray
	void setfine(int itemid, int fine);//setter for fine
};
#endif // !BORROWINGRECORD_H

