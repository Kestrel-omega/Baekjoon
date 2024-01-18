// #1

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <tuple>
using namespace std;

// 1. Template Method

class BaseBallGame
{
	typedef tuple<int, int, int> INPUT;
	typedef tuple<int, int> RESULT;
	vector<pair<INPUT, RESULT>> v;

public:
	virtual ~BaseBallGame() {}

	BaseBallGame() { srand((unsigned)time(0)); }

	void run()
	{
		while (1)
		{
			int x = 0, y = 0, z = 0;

			guess(x, y, z);

			cout << "당신이 생각한 숫자는 " << x << ", " << y << ", " << z << "입니까?" << endl;

			int strike = 0, ball = 0;

			cout << "strike 갯수 : ";
			cin >> strike;

			if (strike == 3)
			{
				cout << "성공!" << endl;
				break;
			}

			cout << "ball 갯수 : ";
			cin >> ball;

			feedback(strike, ball);

			v.push_back(make_pair(INPUT(x, y, z), RESULT(strike, ball)));
			dump();
		}
	}

	void dump()
	{
		printf("------------------------\n");
		printf("입력값 : s b\n");

		for (auto &p : v)
		{
			printf(" %d %d %d : %d %d\n", get<0>(p.first), get<1>(p.first), get<2>(p.first), get<0>(p.second), get<1>(p.second));
		}
		printf("------------------------\n");
	}

protected:
	virtual void guess(int &x, int &y, int &z) = 0;
	virtual void feedback(int s, int b) = 0;
};

class BaseBall_lv0 : public BaseBallGame
{
protected:
	void guess(int &x, int &y, int &z) override
	{
		cout << "초급" << endl;

		do
		{
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
			z = rand() % 9 + 1;
		} while (x == y || y == z || x == z);
	}

	void feedback(int s, int b) override
	{
		// 초급은 피드백 알고리즘 없음
		return;
	}
};

class BaseBall_lv1 : public BaseBallGame
{
protected:
	void guess(int &x, int &y, int &z) override
	{
		cout << "중급" << endl;
		// 중급 숫자 추측 알고리즘
	}

	void feedback(int s, int b) override
	{
		// 중급 피드백 알고리즘
		return;
	}
};

int main()
{
	BaseBall_lv0 basball;

	basball.run();

	return 0;
}

// 2. Strategy

struct IGuess
{
	virtual void guess(int &x, int &y, int &z) = 0;
	virtual void feedback(int s, int b) = 0;

	virtual ~IGuess() {}
};

class BaseBallGame
{
	IGuess *pGuesser = 0;

	typedef tuple<int, int, int> INPUT;
	typedef tuple<int, int> RESULT;
	vector<pair<INPUT, RESULT>> v;

public:
	BaseBallGame() { srand((unsigned)time(0)); }

	void SetGuesser(IGuess *p)
	{
		pGuesser = p;
	}

	void run()
	{
		while (1)
		{
			int x = 0, y = 0, z = 0;

			pGuesser->guess(x, y, z);

			cout << "당신이 생각한 숫자는 " << x << ", " << y << ", " << z << "입니까?" << endl;

			int strike = 0, ball = 0;
			cout << "strike 갯수 : ";
			cin >> strike;

			if (strike == 3)
			{
				cout << "성공!" << endl;
				break;
			}

			cout << "ball 갯수 : ";
			cin >> ball;

			pGuesser->feedback(strike, ball);

			v.push_back(make_pair(INPUT(x, y, z), RESULT(strike, ball)));
			dump();
		}
	}

	void dump()
	{
		printf("------------------------\n");
		printf("입력값 : s b\n");

		for (auto &p : v)
		{
			printf(" %d %d %d : %d %d\n", get<0>(p.first), get<1>(p.first), get<2>(p.first), get<0>(p.second), get<1>(p.second));
		}
		printf("------------------------\n");
	}
};

class Guess_Easy : public IGuess
{
public:
	virtual void guess(int &x, int &y, int &z)
	{
		cout << "초급" << endl;

		do
		{
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
			z = rand() % 9 + 1;
		} while (x == y || y == z || x == z);
	}

	virtual void feedback(int s, int b)
	{
		// 초급은 피드백 알고리즘 없음
		return;
	}
};

class Guess_Normal : public IGuess
{
public:
	virtual void guess(int &x, int &y, int &z)
	{
		// 중급 숫자 추측 알고리즘
	}

	virtual void feedback(int s, int b)
	{
		// 중급 피드백 알고리즘
		return;
	}
};

int main()
{
	BaseBallGame basball;
	Guess_Easy guesser;

	basball.SetGuesser(&guesser);

	basball.run();

	return 0;
}

// 3. Policy Base

class Guess_Easy
{
public:
	inline void guess(int &x, int &y, int &z)
	{
		cout << "초급" << endl;

		do
		{
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
			z = rand() % 9 + 1;
		} while (x == y || y == z || x == z);
	}

	inline void feedback(int s, int b)
	{
		// 초급은 피드백 알고리즘 없음.
		return;
	}
};

class Guess_Normal
{
public:
	inline void guess(int &x, int &y, int &z)
	{
		// 중급 숫자 추측 알고리즘
	}

	inline void feedback(int s, int b)
	{
		// 중급 피드백 알고리즘
	}
};

template <typename Guesser = Guess_Easy>
class BaseBallGame
{
	Guesser g;

	typedef tuple<int, int, int> INPUT;
	typedef tuple<int, int> RESULT;
	vector<pair<INPUT, RESULT>> v;

public:
	void run()
	{
		while (1)
		{
			int x = 0, y = 0, z = 0;

			g.guess(x, y, z);

			cout << "당신이 생각한 숫자는 " << x << ", " << y << ", " << z << "입니까?" << endl;

			int strike = 0, ball = 0;
			cout << "strike 갯수 : ";
			cin >> strike;

			if (strike == 3)
			{
				cout << "성공!" << endl;
				break;
			}

			cout << "ball 갯수 : ";
			cin >> ball;

			g.feedback(strike, ball);

			v.push_back(make_pair(INPUT(x, y, z), RESULT(strike, ball)));
			dump();
		}
	}

	void dump()
	{
		printf("------------------------\n");
		printf("입력값 : s b\n");

		for (auto &p : v)
		{
			printf(" %d %d %d : %d %d\n", get<0>(p.first), get<1>(p.first), get<2>(p.first), get<0>(p.second), get<1>(p.second));
		}
		printf("------------------------\n");
	}
};

int main()
{
	BaseBallGame<Guess_Easy> basball;

	basball.run();

	return 0;
}

// #2

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class File
{
public:
	File(){};
	File(string _fname, int _fsize) : fname(_fname), fsize(_fsize) {}

	virtual int getSize()
	{
		return fsize;
	}

	virtual void print(int lv = 0)
	{
		for (int i = 0; i < lv; i++) cout << " ";
		cout << "(" << fname << ", " << fsize << ")" << endl;
	}

private:
	string fname;
	int fsize;
};

class Folder : public File
{
public:
	Folder(string _Fname) : Fname(_Fname) {}
	~Folder()
	{
		for (auto &e : elements)
		{
			delete e;
		}
	}

	void add(File *input)
	{
		elements.push_back(input);
	}

	int getSize()
	{
		int folder_size = 0;

		for (const auto &e : elements)
		{
			folder_size += e->getSize();
		}

		return folder_size;
	}

	void print(int lv = 0)
	{
		for (int i = 0; i < lv; i++)
			cout << " ";

		cout << "[" << Fname << "]" << endl;
		for (const auto &e : elements)
		{
			e->print(lv + 1);
		}
		cout << endl;
	}

private:
	string Fname;
	vector<File *> elements;
};

int main()
{
	// 조건 1. Folder와 File의 객체를 생성할 수 있어야 합니다.
	Folder *rootFolder = new Folder("ROOT"); // 폴더는 이름만 있습니다.
	Folder *aaaaFolder = new Folder("AAAA");
	Folder *bbbbFolder = new Folder("BBBB");

	File *file1 = new File("a.txt", 10); // 파일은 이름과 크기가 있습니다.
	File *file2 = new File("b.txt", 20);
	File *file3 = new File("c.txt", 30);
	File *file4 = new File("d.txt", 40);

	// 조건 2. 폴더 안에 파일 및 다른 폴더를 넣을 수 있어야 합니다.
	rootFolder->add(aaaaFolder);
	rootFolder->add(bbbbFolder);
	rootFolder->add(file1);

	aaaaFolder->add(file2);
	aaaaFolder->add(file3);

	bbbbFolder->add(file4);

	// 조건 3. 파일과 폴더 크기를 출력할 수 있어야 합니다.
	//		  폴더는 자신만의 크기는 없지만 크기를 구할 수는 있습니다.
	cout << "getSize()" << endl;
	cout << file1->getSize() << endl;	   // 10
	cout << aaaaFolder->getSize() << endl; // 50
	cout << rootFolder->getSize() << endl; // 100
	cout << endl;

	// 조건 4. 화면 출력
	cout << "print()" << endl;
	file1->print(); // 파일이므로 이름과 크기만 출력해 주세요.
					// ex) (a.txt, 10)

	cout << endl;
	rootFolder->print(); // ROOT 폴더 전체의 모양을 보기좋게 출력해 주세요.
						 // [ROOT]
						 //			[AAAA]
						 //					(b.txt, 20)
						 //					(c.txt, 30)
						 //			[BBBB]
						 //					(d.txt, 40)
						 //			(a.txt, 10)

	// 조건 5. 폴더 제거시 폴더 안에 있는 모든 파일과 폴더가 제거 되게 해주세요.
	delete rootFolder;
}

// #3
#include <iostream>
#include <list>

using namespace std;

// 클래스 어답터
template <typename T, typename C = list<T>>

class Queue
{
	C queue;

public:
	inline void Push(const T &val)
	{
		queue.push_back(val);
	}

	inline T Pop()
	{
		T val = queue.front();
		queue.pop_front();

		return val;
	}
};

int main()
{
	Queue<int> queue;

	queue.Push(10);
	queue.Push(20);

	cout << queue.Pop() << endl; // 10
	cout << queue.Pop() << endl; // 20

	return 0;
}

// 객체 어답터
template <typename T, typename C = list<T>>
class Queue
{
	C *queue;

public:
	Queue(C *p) : queue(p) {}

	inline void Push(const T &val)
	{
		queue->push_back(val);
	}

	inline T Pop()
	{
		T val = queue->front();
		queue->pop_front();

		return val;
	}
};

int main()
{
	list<int> temp;
	Queue<int> queue(&temp);

	queue.Push(10);
	queue.Push(20);

	cout << queue.Pop() << endl; // 10
	cout << queue.Pop() << endl; // 20

	return 0;
}