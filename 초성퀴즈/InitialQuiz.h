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
	InitialQuiz() : input{ "아무것도 입력되지 않았습니다." }, numberOfRight{ }, fewSeconds{ 15 } {
		import_data();
	}

	void stage();
	void guess_answer();
	void match_answer();
	void import_data();

	vector<string>& get_question() {
		return question;
	}
	vector<string> get_rightAnswer() {
		return rightAnswer;
	}
	string get_splash() {
		// 0 ~ splash.size()까지 균등 분포 정의
		uniform_int_distribution<int> randomInt{0, static_cast<int>(splash.size() - 1)};
		return splash[randomInt(gen)];
	}
	string get_input() {
		return input;
	}
	string get_pw() {
		return pw;
	}
	int get_numberOfRight() {
		return numberOfRight;
	}
	int get_fewSeconds() {
		return fewSeconds;
	}

	void set_fewSeconds(int sec) {
		fewSeconds = sec;
	}

private:
	random_device rd{ };
	mt19937 gen{ rd() };

	vector<string> question;
	vector<string> rightAnswer;
	vector<string> splash;

	string input;
	string pw;

	int stageNumber;
	int numberOfRight;
	int fewSeconds;
};
