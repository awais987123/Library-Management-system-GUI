#include "contents.h"
#include"library.h"
#include"articles.h"
#include"books.h"
#include<iostream>
#include"digitalmedia.h"
#include<vector>
#include<algorithm>
contents::contents()
{}
contents::contents(articles a)
{
	article.push_back(a);//add an articles with given info
}
contents::contents(books b)
{
	book.push_back(b);//add an books with given info
}
contents::contents(digitalmedia d)
{
	digital.push_back(d);//add an digitalmedia with given info
}
contents::contents(articles a, books b, digitalmedia d)
{
	//add three items with given info
	article.push_back(a);
	book.push_back(b);
	digital.push_back(d);
}
contents& contents::setarticle(articles a)
{
	article.push_back(a);//add an article with given info
	return *this;
}
void contents::editdigitalmedia(digitalmedia that)
{
	for (auto it = digital.begin(); it != digital.end(); it++)
	{
		if (it->getdigitalmediaitemid() == that.getdigitalmediaitemid())//if item is found
		{
			//set a new value to that item (or simply edit)
			it->setdigitalmedia(that.getdigitalmediatitle(), that.getdigitalmediaauthor(), that.getdigitalmediapublisher(), that.getdigitalmediaprodyear(), that.getdigitalmediastatus(), that.getdigitalmediacopies(), that.getdigitalmediaitemid());
			break;
		}

	}
}
void contents::editarticles(articles that)
{
	for (auto it = article.begin(); it != article.end(); it++)
	{
		if (it->getarticleitemid() == that.getarticleitemid())//if item is found
		{
			//set a new value to that item (or simply edit)
			it->setarticle(that.getarticletitle(), that.getarticleauthor(), that.getarticlepublisher(), that.getarticlestatus(), that.getarticleprodyear(), that.getarticlecopies(), that.getarticleitemid());
			break;
		}

	}
}
void contents::editbook(books that)
{
	for (auto it = book.begin(); it != book.end(); it++)
	{
		if (it->getbookitemid() == that.getbookitemid())
		{
			//set a new value to that item (or simply edit)
			it->setbook(that.getbooktitle(), that.getbookauthor(), that.getbookpublisher(), that.getbookprodyear(), that.getbookcopies(), that.getbookstatus(), that.getbookitemid());
			break;
		}

	}
}
bool contents::editcopies(articles a)
{
	auto it = find(article.begin(), article.end(), a);
	if (it != article.end())
	{
		//decrease a copy from given article
		return (it->copiesdecrement());
	}
	return false;
}
bool contents::editcopies(books b)
{

	auto it = find(book.begin(), book.end(), b);
	if (it != book.end())
	{
		//decrease a copy from given book
		return (it->copiesdecrement());

	}
	return false;
}
bool contents::editcopies(digitalmedia d)
{
	auto it = find(digital.begin(), digital.end(), d);
	if (it != digital.end())
	{
		//decrease a copy from given digitalmedia
		return (it->copiesdecrement());

	}
	return false;
}
contents& contents::setbook(books b)
{
	//set a new book with given info
	book.push_back(b);
	return *this;
}
contents& contents::setdigitalmedia(digitalmedia d)
{
	//set a new digitalmedia with given info
	digital.push_back(d);
	return *this;
}
string contents::tostring() const
{
	string data;
	for (auto it : this->book)
	{
		//store all data of books
		data += it.books::sptostring();
		data += '\n';

	}
	for (auto it : this->article)
	{
		//store all data of article
		data += it.articles::sptostring();
		data += '\n';

	}
	for (auto it : this->digital)
	{
		//store all data of digital
		data += it.digitalmedia::sptostring();
		data += '\n';

	}
	return data;
}
void contents::uniquekey(int itemid)
{
	for (auto it = book.begin(); it != book.end(); it++)
	{
		if (it->getbookitemid() > itemid)
		{
			it->decreaseoneinitemid();//decrement in id of given book
		}
	}
	for (auto it = article.begin(); it != article.end(); it++)
	{
		if (it->getarticleitemid() > itemid)
		{
			it->decreaseoneinitemid();//decrement in id of given article
		}
	}
	for (auto it = digital.begin(); it != digital.end(); it++)
	{
		if (it->getdigitalmediaitemid() > itemid)
		{
			it->decreaseoneinitemid();//decrement in id of given digital
		}
	}
}
void contents::deleteitem(int item_id)
{
	for (auto it = article.begin(); it != article.end(); it++)
	{
		if (it->getarticleitemid() == item_id)
		{
			article.erase(it);//delete the given aricle
			break;

		}
	}
	for (auto it = book.begin(); it != book.end(); it++)
	{
		if (it->getbookitemid() == item_id)
		{
			book.erase(it);//delete the given book
			break;

		}
	}
	for (auto it = digital.begin(); it != digital.end(); it++)
	{
		if (it->getdigitalmediaitemid() == item_id)
		{
			digital.erase(it);//delete the given digital
			break;

		}
	}
}
void contents::increasecopies(int itemid)
{

	for (auto it = this->book.begin(); it != book.end(); it++)
	{
		if (it->getbookitemid() == itemid)
		{
			it->incresebookcopies(itemid);

		}

	}
	for (auto it = this->article.begin(); it != article.end(); it++)
	{
		if (it->getarticleitemid() == itemid)
		{
			it->increasecopies(itemid);
		}

	}
	for (auto it = this->digital.begin(); it != digital.end(); it++)
	{
		if (it->getdigitalmediaitemid() == itemid)
		{

			it->incresecopies(itemid);
		}
	}

}
string contents::getnameonid(int itemid)
{
	for (auto it = book.begin(); it != book.end(); it++)
	{
		if (it->getbookitemid() == itemid)
		{
			return it->sptostring();//return the book string

		}
	}
	for (auto it = article.begin(); it != article.end(); it++)
	{
		if (it->getarticleitemid() == itemid)
		{
			return it->sptostring();//return the article string

		}
	}
	for (auto it = digital.begin(); it != digital.end(); it++)
	{
		if (it->getdigitalmediaitemid() == itemid)
		{
			return it->sptostring();//return the digital string

		}
	}
	return "";
}
void contents::sort()
{
	//sorts the following record
	std::sort(book.begin(), book.end());
	std::sort(digital.begin(), digital.end());
	std::sort(article.begin(), article.end());
}
string contents::sptostring() const
{
	//return the string if full record in special formate(',')
	string data;
	for (auto it : this->book)
	{
		data += it.books::sptostring();
		data += '\n';

	}
	for (auto it : this->article)
	{
		data += it.articles::sptostring();
		data += '\n';

	}
	for (auto it : this->digital)
	{
		data += it.digitalmedia::sptostring();
		data += '\n';

	}
	return data;


}
int contents::findbook(string name, string author)
{

	auto it = find(book.begin(), book.end(), books(name, author));
	if (it != book.end())
	{
		return it->getbookitemid();
	}
	return 0;
}
int contents::finddigitalmedia(string name, string author)
{
	auto it = find(digital.begin(), digital.end(), digitalmedia(name, author));
	if (it != digital.end())
	{
		return it->getdigitalmediaitemid();
	}
	return 0;
}
int contents::findarticle(string name, string author)
{

	auto it = find(article.begin(), article.end(), articles(name, author));
	if (it != article.end())
	{
		return it->getarticleitemid();
	}
	return 0;
}