#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H
#include"contents.h"
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
class library//class declaration
{
private://member variables
	string Library_ID,
		Name;
	contents content;
public://members functons
	library();//default constructor 
	library(string i, string n, books b);//parameterized cns with a book as content
	library(string i, string n, articles a);//parameterized cns with a article as content
	library(string i, string n, digitalmedia d);//parameterized cns with a digital media as content
	library(string i, string n);//parameterized cns with two variables
	library(books b);//parameterized cns with a book 
	library(articles a);//parameterized cns with a article 
	library(digitalmedia d);//parameterized cns with a digital 
	bool equal(string input);//calls the edit fncs of book||article||digital
	string tostring_library();//return a string consisting all libraries info
	library& setlibrary(string i, string n);//set lib having id nd name
	library& setarticle(articles a);//set article 
	library& setbook(books b);//set book
	library& setdigitalmedia(digitalmedia d);//set digital
	string tostring() const;//return string of contents
	string sptostring() const;//return sptostring of contents(ep by ',')
	friend bool operator==(const library& left, const library& right);//comparison opr 
	string getlibraryid() const;//return id of current library
	string getlibrartname() const;//return name of current library
	string isValidLibraryName(string);//check for validation of lib name(alpha+space)
	void deletecontentitem(int);//delete content of given id
	int findbook(string, string);//return id of book if found
	int finddigitalmedia(string, string);//return id of digital if found
	int findarticle(string, string);//return id of article if found
	void increscopies(int);//increase one in copies when content is returned
	void editbook(books);//edit book 
	void editarticle(articles);//edits article
	void editdigital(digitalmedia);//edits digital
	void uniquekey(int);//assigns unique key
	void sortinfo();//sort the libraries
	friend bool operator<(const library& left, const library& right);//operater overload "<"
	string sptostring_library();//rerturn string consist of all libraries in "," formate
	string getnameonid(int);//return name against given id
};
#endif // !LIBRARY_H

