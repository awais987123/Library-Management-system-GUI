#pragma once
#ifndef ARTICLES_H
#define ARTICLES_H
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
class articles//declaration of class
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
	articles();//default constructor
	articles(string t, string a, string p, string s, int prd, int c, int id);//parameterized constructor
	articles(string t, string a);//overloaded parameterized constructor for two parameters
	articles& setarticle(string t, string a, string p, string s, int prd, int c, int id);//setter for all variables
	bool copiesdecrement();//to decrease one from no of copies
	string tostring();//return a string having all the values of member variables
	string sptostring()const;//return a string having all the values of member variables seperated by ','
	friend bool operator == (const articles& left, const articles& right);//operator overload for comparison
	string getarticletitle() const;//getter for title
	string getarticleauthor() const;//getter for author
	string getarticlestatus() const;//getter for status
	string getarticlepublisher() const;//getter for publisher
	int getarticleprodyear() const;//getter for production year
	int getarticlecopies() const;//getter for copies
	int getarticleitemid() const;//getter for item id
	string isValidAuthor(string);//validation check for author
	string isValidPublisher(string);//validation check for publisher
	int isValidProductionYear(int);//validation check for production year
	int isValidCopies(int);//validation check for copies
	void increasecopies(int);//increase the number of copies when an article is returned
	void decreaseoneinitemid();//decrese in item id by one when an article is deleted
	friend bool operator<(articles& left, articles& right);//operater overload for '<'
};
#endif // !ARTICLES_H

