#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------\n"

class ForwardList;
ForwardList operator+(const ForwardList& left, const ForwardList& right);

class Element
{
	int Data;
	Element* pNext;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
	friend class Iterator;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};
class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) :Temp(Temp)
	{
		cout << "ItConstructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "ItDestructor:\t" << this << endl;
	}
	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}
	int operator* ()
	{
		return Temp->Data;
	}
};
class ForwardList
{
	Element* Head;
public:
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ForwardList()
	{
		Head = nullptr;
		cout << "LConstructor" << this << endl;
	}
	ForwardList(const std::initializer_list<int>& il):ForwardList()
	{
		cout << typeid(il.begin()).name() << endl;
		cout << typeid(int*).name() << endl;
		cout << typeid(const int*).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	ForwardList(const ForwardList& other):ForwardList()
	{
		/*for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);*/
		cout << "LConstructor: \t" << this << endl;
		*this = other;
	}
	/*ForwardList(ForwardList&& other)
	{
		cout << "MoveConstructor: \t" << this << endl;
	}*/
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}	

	//				Operators:
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "LConstructor: \t" << this << endl;
		return *this;
	}
	ForwardList& operator=(ForwardList&& other)
	{
		while (Head)pop_front();
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "LMoveAssignment:\t" << this << endl;
	return *this;
	}
	//					Adding element:
	void push_front(int Data)
	{
		Head = new Element(Data, Head);
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);				
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
		Temp->pNext = new Element(Data);
	}
	void insert(int Data, int Index)
	{
		if (Index == 0)return push_front(Data);
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
			if (Temp->pNext)
				Temp = Temp->pNext;
		Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;
	}
	//					Delete elements:
	void pop_front()
	{
		Element* erased = Head;
		Head = Head->pNext;
		delete erased;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
	}
	void erase(int Index)
	{
		if (Index == 0)return pop_front();
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
			if (Temp->pNext)Temp = Temp->pNext;
		Element* erased = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete erased;
	}	
	//					Methods:
	void print()const
	{
		/*Element* Temp = Head;
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}*/
		cout << "Head: " << Head << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	}	
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	for (Element* Temp = right.Head; Temp; Temp = Temp->pNext)cat.push_back(Temp->Data);
	return cat;
}

//#define BASE_CHECK
//#define OPERATOR_PLUS_CHECK
//#define RANGE_BASED_FOR_ARRAY
//#define RANGE_BASED_FOR_LIST
#define MOVE_SEMANTIC_CHECK


void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "������� ������ ������: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	//list.push_back(123);
	list = list;
	list.print();

	/*int value;
	int index;
	cout << "������� ����� ��������: "; cin >> index;
	cout << "������� �������� ��������: "; cin >> value;
	list.insert(value, index);
	list.print();

	cout << "������� ����� ��������: "; cin >> index;
	list.erase(index);
	list.print();*/

	//ForwardList list2 = list;

	ForwardList list2;
	list2 = list;		//Copy assigment
	list2.print();
#endif // BASE_CHECK
#ifdef OPERATOR_PLUS_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1.print();

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.print();

	ForwardList list3 = list1 + list2;
	list3.print();
#endif // OPERATOR_PLUS_CHECK
#ifdef RANGE_BASED_FOR_ARRAY
	int arr[] = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_FOR_ARRAY
#ifdef RANGE_BASED_FOR_LIST
	ForwardList list = { 3, 5, 8, 13, 21 }; 
	list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_FOR_LIST
#ifdef MOVE_SEMANTIC_CHECK
	ForwardList list1 = { 3, 5, 8, 13, 21 };
	for (int i : list1)cout << i << tab; cout << endl;
	
	ForwardList list2 = { 34, 55,89 };
	for (int i : list2)cout << i << tab; cout << endl;

	cout << delimiter << endl;
	ForwardList list3;
	list3 = list1 + list2;
	cout << delimiter << endl;
	for (int i : list3)cout << i << tab; cout << endl;
#endif // MOVE_SEMANTIC_CHECK

}