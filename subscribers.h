#pragma once
#ifndef SUBSCRIBERS_H
#define SUBSCRIBERS_H
#include<string>
#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
class subscribers//class declaration
{
private://member variables
	string subscriber_ID,
		Type,
		Name,
		Address,
		Phone,
		Email;
public://member functions
	subscribers();//default cns
	subscribers(string id, string name);//parametrized cns with id&name
	subscribers(string i, string t, string n, string a, string p, string e);//parametrized cns with all member variables values
	subscribers& setsubscriber(string i, string t, string n, string a, string p, string e);//set all member variables values
	string  tostring() const;//return string of subscriber info
	string  sptostring() const;//return string of subscriber info seperated by ','
	friend bool operator<(const subscribers& left, const subscribers& right);//operator overload for '<'
	friend ostream& operator<<(ostream& strn, subscribers& right);//operaor overload for '<<'
	void setid(string id);//sets id
	void setname(string n);//sets name
	friend bool operator==(const subscribers& left, const subscribers& right);//operator overload for '=='
	string getsubsriberid() const;//return id
	string getsubsriberTYPE() const;//return type
	string getsubscriberNAME()const;//return name
	string getsubscriberaddress()const;//return address
	string getsubscriberPHONE()const;//return phone
	string getsubscriberEMAIL()const;//return email
	string isValidSubscriberType(string);//check for type
	string isValidSubscriberName(string);//check for name
	string isValidSubscriberPhone(string);//check for phone
	string isValidSubscriberEmail(string);//check for email
};
#endif // !SUBSCRIBERS_H

