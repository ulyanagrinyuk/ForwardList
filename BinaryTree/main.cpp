#include"Tree.cpp"
#include"Tree.h"



//#define BASE_CHECK
//#define OLD_PREFOREMANCE_CHECK
//#define DEPTH_CHECK
//#define BALANCE_CHECK

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

	Tree<int> tree = { 50, 25, 75, 16, 32, 17, 64, 90, 28, 29 };
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
#ifdef BALANCE_CHECKDEBUG
	Tree<int> tree = { 89, 55, 34, 21, 13, 8, 5, 3 };
	tree.tree_print();
	tree.balance();
	tree.tree_print();
#endif // BALANCE_CHECKDEBUG
}
