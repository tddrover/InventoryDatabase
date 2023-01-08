class LinkNode{
	private:
		string name;
		float price;
		int quant;
		LinkNode *next;
		
	public:
		LinkNode(){name="";price=0.0;quant=0;; next=nullptr;}
		LinkNode(string s, float p, int q, LinkNode * n){name=s;price=p,quant=q;next = n;}
		void setNext(LinkNode *n){next = n;}
		void setName(string s){name = s;}
		void setPrice(float p){ price=p;}
		void setQuant(int q){ quant=q;}

		LinkNode *getNext(){return next;}
		string getName(){return name;}
		float getPrice(){return price;}
		string getKey(){return name;}
		int getQuant(){return quant;}
		void printInfo();
};

void LinkNode::printInfo()
{
	cout << fixed << setprecision(2) << showpoint;
	cout << "\n\n\t\t\tLinkNode Name            : " << name << endl;
	cout << "\t\t\tLinkNode Price               : " << price << endl;
	cout << "\t\t\tLinkNode Quant               : " << quant << endl;
	cout << "\t\t\tLinkNode Link Address        : " << next << endl;
}

