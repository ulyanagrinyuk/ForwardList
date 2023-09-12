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
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;
	clock_t start = clock();
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	clock_t end = clock();
	tree.print();
#ifdef OLD_PREFOREMANCE_CHECK
	cout << "Дерево заполнено за " << double(end - start) / CLOCKS_PER_SEC << "секунд \n";
	//tree.print();
	cout << endl;
	cout << "Минимальное значение в дереве: ";
	start = clock();
	int min = tree.minValue();
	end = clock();
	cout << min << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << "секунд \n";
	///////////////////////////////////////////////////////////////////
	cout << "Максимальное значение в дереве: ";
	start = clock();
	int max = tree.maxValue();
	end = clock();
	cout << max << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << "секунд \n";
	///////////////////////////////////////////////////////////////////
	cout << "Сумма элементов дерева\t\t";
	start = clock();
	int sum = tree.sum();
	end = clock();
	cout << sum << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << "секунд \n";
	///////////////////////////////////////////////////////////////////
	cout << "Количество элементов дерева: ";
	start = clock();
	int count = tree.count();
	end = clock();
	cout << clock << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << "секунд \n";
	/////////////////////////////////////////////////////////////////////
	cout << "Глубина дерева: ";
	start = clock();
	int depth = tree.count();
	end = clock();
	cout << depth << ", вычислено за " << double(end - start) / CLOCKS_PER_SEC << "секунд \n";

#endif // OLD_PREFOREMANCE_CHECK

	measure("Минимальное значение в дереве: ", tree, &Tree::minValue);
	measure("Максимальное значение в дереве: ", tree, &Tree::maxValue);
	measure("Сумма элементов дерева\t\t, ", tree, &Tree::sum);
	measure("Количество элементов дерева: ", tree, &Tree::count);
	measure("Глубина дерева: ", tree, &Tree::Depth);

	cout << "=====================   UniqueTree =================" << endl;
	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100);
	}
	/*u_tree.print();*/
	cout << "Минимальное значение в дереве: " << u_tree.minValue() << endl;
	cout << "Максимальное значение в дереве: " << u_tree.maxValue() << endl;
	cout << "Сумма элементов дерева\t\t " << u_tree.sum() << endl;
	cout << "Количество элементов дерева: " << u_tree.count() << endl;
	cout << "Глубина дерева: " << u_tree.Depth() << endl;
#endif // BASE_CHECK
#ifdef DEPTH_CHECK

	Tree<int> tree = { 50, 25, 75, 16, 32, 17, 64, 90, 28, 29 };
	tree.print();
	cout << "Глубина дерева: " << tree.Depth() << endl;

	/*int value;
	cout << "Введите удаляемое значение: "; cin >> value;
	tree.erase(value);
	tree.print();*/

	int depth;
	/*cout << "Введите глубину дерева: "; cin >> depth;
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
