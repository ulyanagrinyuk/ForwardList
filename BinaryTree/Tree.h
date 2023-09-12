#pragma once
#include<iostream>
#include<ctime>
using std::cout;
using std::cin;
using std::endl;




template<class T> class Tree;
template<typename T> class UniqueTree;

template<typename T>class Tree
{
protected:
	class Element
	{
		T Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(T Data, Element* pLeft, Element* pRight);
		~Element();
		friend class Tree;
		friend class UniqueTree<T>;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree();
	Tree(const std::initializer_list<T>& il);
	~Tree();

	void insert(T Data);
	void erase(T Data);

	void Clear();
	int count()const;

	int sum()const;
	int minValue()const;
	int maxValue()const;
	int Depth()const;
	double avg()const;
	void print()const;
	void depth_print(int depth)const;
	void tree_print()const;
	void balance();
private:
	void insert(T Data, Element* Root);
	void erase(T Data, Element*& Root);

	void Clear(Element* Root);
	int Depth(Element* Root)const;
	int Sum(Element* Root)const;
	int Count(Element* Root)const;
	int minValue(Element* Root)const;
	int maxValue(Element* Root)const;
	void print(Element* Root)const;
	void depth_print(Element* Root, T depth, T width)const;
	void tree_print(Element* Root, T width, T depth = 0)const;
	void balance(Element* Root);

	template<typename T>friend class UniqueTree;
	template<typename T>void insert(T Data);
	template<typename T>void erase(T Data);
	template<typename T>friend void measure(Tree<T>* message, T(Tree<T>::* member_function)());
};