#include "InitialQuiz.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::ios;
using std::locale;

using std::fstream;

void InitialQuiz::guessAnswer() {
	cout << "������ �Է��� �ּ���\n" << ">>> ";

	thread readInput{ [this] { cin >> input; } }; // cin�� �����ϴ� ���ٸ� �����ϴ� ������ ����
	readInput.detach(); // readInput �����尡 ���� �� ���� ���ν������ ��� ����(�񵿱�)
	sleep_for(seconds{ fewSeconds }); // fewSeconds�� ���� ���ν����� ����
	readInput.~thread(); // thread �Ҹ��ڸ� ȣ�������ν� �Է��� ������ �ߴ�
}

void InitialQuiz::matchAnswer() {
	if (find(rightAnswer.begin(), rightAnswer.end(), input)
		!= rightAnswer.end()) {
		cout << "�¾ҽ��ϴ�!" << endl;
	}
	else cout << "Ʋ�Ƚ��ϴ�..." << endl;
}

void InitialQuiz::import_data() {
	locale::global(locale{ "Korean" });

	fstream fin{ "data", ios::in };
	string temp{ };

	while (getline(fin, temp)) {
		size_t previous{ };
		size_t current{ temp.find(' ') };
		question.push_back(temp.substr(previous, current - previous));

		previous = current + 1;
		current = temp.find(' ');
		rightAnswer.push_back(temp.substr(previous, current - previous));
	}

	fin.close();
	fin.open("pw", ios::in);
	fin >> pw;
	fin.close();

	fin.open("splash", ios::in);
	while (getline(fin, temp)) {
		splash.push_back(temp);
	}
}
