#include<iostream>
#include"Tree.h"

template<class T>Tree<T>::Element::Element(T Data, Element* pLeft, Element* pRight) :Data(Data), pLeft(pLeft), pRight(pRight)
{
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

}
template<class T>Tree<T>::Element::~Element()
{
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T> Tree<T>::Tree() :Root(nullptr)
{
#ifdef DEBUG
	cout << "TConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T> Tree<T>::Tree(const std::initializer_list<T>& il) : Tree()
{
	for (T i : il)insert(i, Root);
}
template<typename T> Tree<T>::~Tree()
{
	Clear(Root);
#ifdef DEBUG
	cout << "TDestructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>void Tree<T>::insert(T Data)
{
	insert(Data, Root);
}
template<typename T>void Tree<T>::erase(T Data)
{
	erase(Data, Root);
}

template<typename T>void Tree<T>::Clear()
{
	Clear(Root);
	Root = nullptr;
}
template<typename T>int Tree<T>::count()const
{
	return Count(Root);
}

template<typename T>int Tree<T>::sum()const
{
	return Sum(Root);
}
template<typename T>int Tree<T>::minValue()const
{
	return minValue(Root);
}
template<typename T>int Tree<T>::maxValue()const
{
	return maxValue(Root);
}
template<typename T>int Tree<T>::Depth()const
{
	return Depth(Root);
}
template<typename T>double Tree<T>::avg()const
{
	return (double)Sum(Root) / Count(Root);
}
template<typename T>void Tree<T>::print()const
{
	print(Root);
	cout << endl;
}
template<typename T>void Tree<T>::depth_print(int depth)const
{
	depth_print(Root, depth, 64);
}
template<typename T>void Tree<T>::tree_print()const
{
	tree_print(Root, 64);
}
template<typename T>void Tree<T>::balance()
{
	balance(Root);
}


template<typename T>void Tree<T>::insert(T Data, Element* Root)
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
template<typename T>void Tree<T>::erase(T Data, Element*& Root)
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

template<typename T> void Tree<T>::Clear(Element* Root)
{
	if (Root == nullptr) return;
	Clear(Root->pLeft);
	Clear(Root->pRight);
	delete Root;
}
template<typename T>int Tree<T>::Depth(Element* Root)const
{
	if (Root == nullptr)return 0;
	T l_depth = Depth(Root->pLeft) + 1;
	T r_depth = Depth(Root->pRight) + 1;
	return l_depth < r_depth + 1 ? l_depth : r_depth;
}
template<typename T>int Tree<T>::Sum(Element* Root)const
{
	return Root == nullptr ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
}
template<typename T>int Tree<T>::Count(Element* Root)const
{
	return Root == nullptr ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
}
template<typename T>int Tree<T>::minValue(Element* Root)const
{
	if (Root == nullptr)return 0;
	if (Root->pLeft) return Root->Data;
	else return minValue(Root->pLeft);
}
template<typename T>int Tree<T>::maxValue(Element* Root)const
{
	if (Root == nullptr)return 0;
	if (Root->pRight == nullptr)return Root->Data;
	else return maxValue(Root->pRight);
}
template<typename T>void Tree<T>::print(Element* Root)const
{
	if (Root == nullptr)return;
	print(Root->pLeft);
	cout << Root->Data << "\t";
	print(Root->pRight);
}
template<typename T>void Tree<T>::depth_print(Element* Root, T depth, T width)const
{
	if (Root == nullptr)
	{
		if (depth == 0)cout.width(width * pow(2, (this->Depth() - depth) / 3));
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
template<typename T>void Tree<T>::tree_print(Element* Root, T width, T depth)const
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
template<typename T>void Tree<T>::balance(Element* Root)
{
	if (Root == nullptr)return;
	if (abs(Count(Root->pLeft) - Count(Root->pRight)) < 2)return;
	if (Count(Root->pLeft) < Count(Root->pRight))
	{
		if (Root->pLeft)insert(Root->Data, Root->pLeft);
		else Root->pLeft = new Element(Root->Data);
		Root->Data = minValue(Root->pRight);
		erase(minValue(Root->pRight), Root->pRight);
	}
	else
	{
		if (Root->pRight)insert(Root->Data, Root->pRight);
		else Root->pRight = new Element(Root->Data);
		Root->Data = maxValue(Root->pLeft);
		erase(maxValue(Root->pLeft), Root->pLeft);
	}
	balance(Root->pLeft);
	balance(Root->pRight);
	balance(Root);
}

template<typename T>class UniqueTree :public Tree<T>
{
public:
	void insert(T Data)
	{
		insert(Data, Tree<T>::Root);
	}
	void insert(T Data, Tree<T>::Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Tree::Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Tree::Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data < Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Tree::Element(Data);
			else insert(Data, Root->pRight);
		}
	}
};

template<typename T>void measure(const char* message, const Tree<T>& tree, T(Tree<T>::* member_function)()const)
{
	cout << message;
	clock_t start = clock();
	T value = (tree.*member_function)();
	clock_t end = clock();
	cout << value << "Выполнено за " << double(end - start) / CLOCKS_PER_SEC << "секунд \n";
}





