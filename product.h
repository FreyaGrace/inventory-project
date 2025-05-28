#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
	using std::string;
class product{

	public:
		product();
		void add();
		void modify();
		void rem();
		void search_product();
		void transaction_report();
		void search_transaction();
		void logout();
		void list();
		void purchase();
		void show();
		void show_trans();
		
	private:
		int pcode;
		float price;
		float dis;
		char pname[30];
		int id;
		int qty;
		
};
#endif
