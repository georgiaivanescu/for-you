//we can not ovverload the operator :
//.  * :: ? sizeof()


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book {

	const string ISBN;
	string title;
	string author;
	int totalPages;
	int nbChapters;
	int* nbPagesPerChapter;

	static int nbBooks;

public:
	Book() : ISBN("1234") {
		this->title = "Def Title";
		this->author = "Def Author";
		this->totalPages = 0;
		this->nbChapters = 0;
		this->nbPagesPerChapter =NULL;

		this->nbBooks++;


	}

	Book(string ISBN, string title,string author,int totalPages,int nbChapters,int* nbPagesPerChapter) : ISBN(ISBN) {
		this->title =title;
		this->author =author;
		this->totalPages = totalPages;
		this->nbChapters = nbChapters;
		this->nbPagesPerChapter = new int[nbChapters];
		for (int i = 0; i < nbChapters; i++) {

			this->nbPagesPerChapter[i] = nbPagesPerChapter[i];
		}

		this->nbBooks++;


	}

	Book(const Book& b):ISBN(b.ISBN){
		this->title = b.title;
		this->author = b.author;
		this->totalPages = b.totalPages;
		this->nbChapters = b.nbChapters;
		this->nbPagesPerChapter = new int[b.nbChapters];
		for (int i = 0; i < b.nbChapters; i++) {

			this->nbPagesPerChapter[i] = b.nbPagesPerChapter[i];
		}

	}

	~Book() {
		if (this->nbPagesPerChapter != nullptr) {


			delete[] this->nbPagesPerChapter;
		}
		
	}

	Book& operator=(const Book& b) {
		if (this != &b) {
			if (this->nbPagesPerChapter != nullptr) {


				delete[] this->nbPagesPerChapter;
			}
			this->title = b.title;
			this->author = b.author;
			this->totalPages = b.totalPages;
			this->nbChapters = b.nbChapters;
			this->nbPagesPerChapter = new int[b.nbChapters];
			for (int i = 0; i < b.nbChapters; i++) {

				this->nbPagesPerChapter[i] = b.nbPagesPerChapter[i];
			}

		}

		return *this;
	}

	//getters
	string getTitle() {
		return this->title;
	}
	string getAuthor() {
		return this->author;
	}
	int getTotalPages() {
		return this->totalPages;
	}
	int getNbChapters() {
		return this->nbBooks;
	}
	int* getNbPagesPerChapter() {
		int* copy=nullptr;
		if (this->nbPagesPerChapter != nullptr) {
			copy = new int[this->nbChapters];
			for (int i = 0; i < this->nbChapters; i++) {

				copy[i]=this->nbPagesPerChapter[i];
			}
		}
		return copy;
		
	}

	//return if the total nb of pages is > 500

	bool operator!() {
		if (this->totalPages > 500) {
			return true;
		}
		else {
			return false;
		}
		return this->totalPages > 500;
	}

	//x++ post incrementation
	Book operator++(int i) {

		Book copy = *this;
		this->totalPages++;

		return copy;
	}

	//++x pre incrementation
	Book& operator++() {

	
		this->totalPages++;

		return *this;
	}

	//--pre decremenet the value of the nb of pages of the first chapter
		
	Book& operator--() {
		if (nbPagesPerChapter != NULL && nbChapters > 0) {
			--nbPagesPerChapter[0]; 
		}
		return *this;
	}
	//--post decremenet the value of the nb of pages of the first chapter
	Book operator--(int) {
		Book temp = *this; 
		if (nbPagesPerChapter != NULL && nbChapters > 0) {
			nbPagesPerChapter[0]--; 
		}
		return temp; 
	}

};
 int Book ::nbBooks=0;


int main() {


	int c1[]{120, 170, 200, 145, 90},c2[]{ 250, 100, 50 };

	Book b1("ISBN-1234-12334","Schita","I L C", 400 , 3, c2);
	Book b2("ISBN-2345-76432", "Povesti", "I L C", 725, 5, c1);
	Book b3 = b1;

	b3= b2;

	if (!b3 == 1) {
		cout << "greater than 500"<<endl;
	}
	else {
		cout << "is not greater than 500" << endl;
	}

	cout << b1.getAuthor() << endl;
	cout << b1.getNbChapters() << endl;
	cout << b1.getTitle() << endl;
	cout << b1.getTotalPages() << endl;
	for (int i = 0; i < b1.getNbChapters(); i++) {

		cout << b1.getNbPagesPerChapter()[i];
	}

	




	return 0;

}