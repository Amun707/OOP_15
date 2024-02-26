#include <iostream>
#include <string>
#include <functional>//хранит описание классов функторов для программ
//функторы - классы объекты которых можно использовать вместо функций
//
// (ДОПОЛНИТЬ(раскрыть дописав определения))
// 0-pointer
// system-memory
// program-mem
// BSS/BRS
// HEAP
// STACK
// PROGRAM-ARGS 
//

int Sum(int a, int b) { return a + b; }
int Multyply(int a, int b) { return a * b; }

using		 FunctionName = int(*)(int, int);//переопределение типа
typedef int  (*NewName)(int, int);//тоже самое

//как выглядит функция принимающая в себя другую функцию
void	 PrintOperation(int Jane, int Jacob, FunctionName Alg) {
		std::cout << "Наша операция получила параметры:\n" << 
		"\tJane - " << Jane << '\n' <<
		"\tJacob - " << Jacob << '\n' <<
		"С результатом " << Alg(Jane, Jacob);
}

class Functor {
public:
	Functor(int val):num(val){ }
	void operator()(int& val) { 
		val = num;
	}

private:
	int num;
};

void OperateArray(int* arr, int length, std::function<void(int&)>alg) {//принимает ссылки на инты
	for (int i = 0; i < length; i++){
		alg(arr[i]);
	}
}

void f02(int& j) {
	j = 9;
}


int main() {
	system("chcp 1251>nul");

	int a{ 5 }, b{ 9 };
	int i;

	std::cout << Sum<<" with "<<a<<" "<<b<<" args - "<<Sum(a,b)<<"\n\n";
	std::cout << Multyply << " with " << a << " " << b << " args - " << Multyply(a, b) << "\n\n";

	auto pFunc = Sum;//выводит тип данных для переменных
	
	int(*pFunc2)(int, int);//другой вариант вывода типа данных для переменных

	pFunc = Multyply;
	pFunc2 = Sum;

	PrintOperation(2, 4, Multyply);
	std::cout << '\n';
	PrintOperation(a, b, pFunc2);
	std::cout << '\n';

	int* arr = new int[6] { };
	OperateArray(arr, 6, f02);
	for (size_t i = 0; i < 6; i++){
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';

	Functor funtic(4);
	OperateArray(arr, 6, funtic);
	for (size_t i = 0; i < 6; i++){
		std::cout << arr[i] << ' ';
	}



	return 0;
}