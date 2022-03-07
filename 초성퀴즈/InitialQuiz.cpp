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

void InitialQuiz::stage() {
	cout << "각 문제는 " << fewSeconds << "초 내에 풀어야 합니다." << endl << endl;

	string answer{ };

	for (auto iter{ question.begin() }; iter != question.end(); ++iter) {
		cout << distance(question.begin(), iter) + 1 << "번 문제 " << *iter << endl;

		guessAnswer();
		std::cout << "\n입력 된 값 : " << input << std::endl;
		matchAnswer();
	}
}

void InitialQuiz::guessAnswer() {
	cout << "정답을 입력해 주세요\n" << ">>> ";

	thread readInput{ [this] { input = "아무것도 입력되지 않았습니다."; cin >> input; } }; // cin을 수행하는 람다를 실행하는 스레드 생성
	readInput.detach(); // readInput 스레드가 실행 될 동안 메인스레드는 계속 진행(비동기)
	sleep_for(seconds{ fewSeconds }); // fewSeconds초 동안 메인스레드 멈춤
	readInput.~thread(); // thread 소멸자를 호출함으로써 입력을 강제로 중단
}

void InitialQuiz::matchAnswer() {
	if (rightAnswer[stageNumber++] == input) {
		cout << "맞았습니다!" << endl;
		++numberOfRight;
	}
	else cout << "틀렸습니다..." << endl;
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
	fin.close();
}
