#include<iostream>
#include<ctime>
using std::cout;
using std::cin;
using std::endl;

class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
#ifdef DEBUG
		cout << "TConstructor:\t" << this << endl;
#endif // DEBUG

	}
	Tree(const std::initializer_list<int>& il) : Tree()
	{
		for (int i : il)insert(i, Root);
	}
	~Tree()
	{
		Clear(Root);
#ifdef DEBUG
		cout << "TDestructor:\t" << this << endl;
#endif // DEBUG
	}

	void insert(int Data)
	{
		insert(Data, Root);		
	}
	void erase(int Data)
	{
		erase(Data, Root);
	}

	void Clear()
	{
		Clear(Root);
		Root = nullptr;
	}
	int count()const
	{
		return Count(Root);
	}
	
	int sum()const
	{
		return Sum(Root);
	}
	int minValue()const
	{
		return minValue(Root);
	}
	int maxValue()const
	{
		return maxValue(Root);
	}
	int Depth()const
	{
		return Depth(Root);
	}
	double avg()const
	{
		return (double)Sum(Root) / Count(Root);
	}
	void print()const
	{
		print(Root);
		cout << endl;
	}
	void depth_print(int depth)const
	{
		depth_print(Root, depth, 64);
	}
	void tree_print()const
	{
		tree_print(Root, 64);
	}
	void balance()
	{
		balance(Root);
	}
private:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr)return;
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->pLeft == Root->pRight)
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (Count(Root->pLeft) > Count(Root->pRight))
				{
					Root->Data = maxValue(Root->pLeft);
					erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = minValue(Root->pRight);
					erase(maxValue(Root->pRight), Root->pRight);
				}
			}
		}
	}

	void Clear(Element* Root)
	{
		if (Root == nullptr)return;
		Clear(Root->pLeft);
		Clear(Root->pRight);
		delete Root;
	}
	int Depth(Element* Root)const
	{
		if (Root == nullptr)return 0;
		int l_depth = Depth(Root->pLeft) + 1;
		int r_depth = Depth(Root->pRight) + 1;
		return l_depth < r_depth + 1 ? l_depth : r_depth;
	}	
	int Sum(Element* Root)const
	{
		return Root == nullptr ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}
	int Count(Element* Root)const
	{
		return Root == nullptr ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
	}
	int minValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		if (Root->pLeft) return Root->Data;
		else return minValue(Root->pLeft);
	}
	int maxValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		if (Root->pRight == nullptr)return Root->Data;
		else return maxValue(Root->pRight);
	}
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
	void depth_print(Element* Root, int depth, int width)const
	{
		if (Root == nullptr)
		{
			if(depth == 0)cout.width(width *pow(2, (this->Depth() - depth)/3));
			cout << "";
			return;
		}
		if (depth == 0)
		{
			cout.width(width);
			cout << Root->Data;
			cout.width(width);
			cout << " ";
		}
		depth_print(Root->pLeft, depth - 1, width);
		depth_print(Root->pRight, depth - 1, width);
	}
	void tree_print(Element* Root, int width, int depth = 0)const
	{
		if (Root == nullptr)return;
		if (depth >= this->Depth())return;
		depth_print(Root, depth, width);
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		tree_print(Root, width / 2, depth + 1);
	}
	void balance(Element* Root)
	{
		if (Root == nullptr)return;
		if (abs(Count(Root->pLeft) - Count(Root->pRight)) < 2)return;
		if (Count(Root->pLeft) < Count(Root->pRight))
		{
			if(Root->pLeft)insert(Root->Data, Root->pLeft);
			else Root->pLeft = new Element(Root->Data);
			Root->Data = minValue(Root->pRight);
			erase(minValue(Root->pRight), Root->pRight);
		}
		else
		{
			if (Root->pRight)insert(Root->Data, Root->pRight);
			else Root->pRight= new Element(Root->Data);
			Root->Data = maxValue(Root->pLeft);
			erase(maxValue(Root->pLeft), Root->pLeft);
		}
		balance(Root->pLeft);
		balance(Root->pRight);
		balance(Root);
	}
};

class UniqueTree :public Tree
{
public:
	void insert(int Data)
	{
		insert(Data, Root);
	}
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if(Data < Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
};

template<typename T>void measure(const char* message, const Tree& tree, T(Tree::*member_function)()const)
{
	cout << message;
	clock_t start = clock();
	T value = (tree.*member_function)();
	clock_t end = clock();
	cout << value << "��������� �� " << double(end-start) / CLOCKS_PER_SEC <<  "������ \n";
}

//#define BASE_CHECK
//#define OLD_PREFOREMANCE_CHECK
//#define DEPTH_CHECK
#define BALANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "������� ������ ������: "; cin >> n;
	Tree tree;
	clock_t start = clock();
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	clock_t end = clock();
	tree.print();
#ifdef OLD_PREFOREMANCE_CHECK
	cout << "������ ��������� �� " << double(end - start) / CLOCKS_PER_SEC << "������ \n";
	//tree.print();
	cout << endl;
	cout << "����������� �������� � ������: ";
	start = clock();
	int min = tree.minValue();
	end = clock();
	cout << min << ", ��������� �� " << double(end - start) / CLOCKS_PER_SEC << "������ \n";
	///////////////////////////////////////////////////////////////////
	cout << "������������ �������� � ������: ";
	start = clock();
	int max = tree.maxValue();
	end = clock();
	cout << max << ", ��������� �� " << double(end - start) / CLOCKS_PER_SEC << "������ \n";
	///////////////////////////////////////////////////////////////////
	cout << "����� ��������� ������\t\t";
	start = clock();
	int sum = tree.sum();
	end = clock();
	cout << sum << ", ��������� �� " << double(end - start) / CLOCKS_PER_SEC << "������ \n";
	///////////////////////////////////////////////////////////////////
	cout << "���������� ��������� ������: ";
	start = clock();
	int count = tree.count();
	end = clock();
	cout << clock << ", ��������� �� " << double(end - start) / CLOCKS_PER_SEC << "������ \n";
	/////////////////////////////////////////////////////////////////////
	cout << "������� ������: ";
	start = clock();
	int depth = tree.count();
	end = clock();
	cout << depth << ", ��������� �� " << double(end - start) / CLOCKS_PER_SEC << "������ \n";

#endif // OLD_PREFOREMANCE_CHECK

	measure("����������� �������� � ������: ", tree, &Tree::minValue);
	measure("������������ �������� � ������: ", tree, &Tree::maxValue);
	measure("����� ��������� ������\t\t, ", tree, &Tree::sum);
	measure("���������� ��������� ������: ", tree, &Tree::count);
	measure("������� ������: ", tree, &Tree::Depth);

	cout << "=====================   UniqueTree =================" << endl;
	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100);
	}
	/*u_tree.print();*/
	cout << "����������� �������� � ������: " << u_tree.minValue() << endl;
	cout << "������������ �������� � ������: " << u_tree.maxValue() << endl;
	cout << "����� ��������� ������\t\t " << u_tree.sum() << endl;
	cout << "���������� ��������� ������: " << u_tree.count() << endl;
	cout << "������� ������: " << u_tree.Depth() << endl;
#endif // BASE_CHECK
#ifdef DEPTH_CHECK

	Tree tree = { 50, 25, 75, 16, 32, 17, 64, 90, 28, 29 };
	tree.print();
	cout << "������� ������: " << tree.Depth() << endl;

	/*int value;
	cout << "������� ��������� ��������: "; cin >> value;
	tree.erase(value);
	tree.print();*/

	int depth;
	/*cout << "������� ������� ������: "; cin >> depth;
	tree.depth_print(depth);*/
	tree.tree_print();
#endif // DEPTH_CHECK

	Tree tree = { 89, 55, 34, 21, 13, 8, 5, 3 };
	tree.tree_print();
	tree.balance();
	tree.tree_print();

}
