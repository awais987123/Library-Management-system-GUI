#pragma once
#ifndef CONTENTS_H
#define CONTENTS_H
#include"articles.h"
#include"books.h"
#include<iostream>
#include"digitalmedia.h"
#include<vector>
class contents//class declaration 
{
private://member variables
	vector<articles> article;
	vector<books> book;
	vector<digitalmedia> digital;
public://member functions 
	contents();//default cns
	contents(articles a);//parametrized cns having article as parameter
	contents(books b);//parametrized cns having book as parameter
	contents(digitalmedia d);//parametrized cns having digital as parameter
	contents(articles a, books b, digitalmedia d);//parametrized cns having book,article,digital as parameters
	contents& setarticle(articles a);//set article
	bool editcopies(articles a);//edit copies of articles
	bool editcopies(books b);//edit copies of books
	bool editcopies(digitalmedia d);//edit copies of digitalmedia
	contents& setbook(books b);//set book
	contents& setdigitalmedia(digitalmedia d);//set digital
	string tostring() const;//return the string of content having all data
	string sptostring() const;//return the string of content having all data sep by ','
	void deleteitem(int);//delete item
	int findbook(string, string);//return id of book if found
	int finddigitalmedia(string, string);//return id of digitalmedia if found
	int findarticle(string, string);//return id of book if article
	void increasecopies(int);//increase copies if when copy is returned
	void editbook(books);//edit book
	void editarticles(articles);//edit articles
	void editdigitalmedia(digitalmedia);//edit digital media
	void uniquekey(int);//set unique key
	void sort();//sort the members of library by calling librar::sort
	string getnameonid(int);//return the id of content against given name
};
#endif // !CONTENTS_H

