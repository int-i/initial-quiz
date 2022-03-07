#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

using std::cin;
using std::cout;
using std::endl;

using std::string;

using std::vector;

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

using std::chrono::duration_cast;
using std::chrono::system_clock;
using std::chrono::microseconds;
using std::chrono::seconds;

using std::thread;
using std::this_thread::sleep_for;



class InitialQuiz {
public:
	InitialQuiz() : input{ "�ƹ��͵� �Էµ��� �ʾҽ��ϴ�." }, fewSeconds{ 5 } {
		import_data();
	}

	void guessAnswer();
	void matchAnswer();
	void import_data();

	vector<string>& get_question() {
		return question;
	}
	vector<string> get_rightAnswer() {
		return rightAnswer;
	}
	string get_splash() {
		return splash[randomInt(gen)];
	}
	string get_input() {
		return input;
	}
	string get_pw() {
		return pw;
	}
	int get_fewSeconds() {
		return fewSeconds;
	}

	void set_fewSeconds(int sec) {
		fewSeconds = sec;
	}

private:
	// ���� ���� ����
	random_device rd{ };
	mt19937 gen{ rd() };
	// 0 ~ splash.size()���� �յ� ���� ����
	uniform_int_distribution<int> randomInt{ 0, static_cast<int>(splash.size()) };

	vector<string> question;
	vector<string> rightAnswer;
	vector<string> splash;

	string input;
	string pw;

	int fewSeconds;
};
