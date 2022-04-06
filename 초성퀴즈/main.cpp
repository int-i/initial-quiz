//#define TEST
#include "initialQuiz.h"
#include <algorithm>

void test(InitialQuiz&);

int main() {
	InitialQuiz intiInitialQuiz{ };

	cout << "인트아이 초성퀴즈에 오신것을 환영합니다!" << endl;

#ifdef TEST
	test(intiInitialQuiz);
#endif // TEST

	string pw{ };
	while (true) {
		cout << intiInitialQuiz.get_splash() << endl << endl;

		cout << "시작하기 위해 비밀번호를 입력해주시길 바랍니다." << endl;
		cout << ">>> ";
		cin >> pw;
		if (intiInitialQuiz.get_pw() != pw) {
			cout << "비밀번호가 맞지 않습니다." << endl;
			system("pause");
			system("cls");
			continue;
		}

		cout << "5초 뒤 문제가 나오게 됩니다. 한/영키를 눌러 한/영 전환 확인해주세요!" << endl << endl;
		sleep_for(seconds{ 5 });

		intiInitialQuiz.stage();

		cout << "\n맞추신 문제는 총 " << intiInitialQuiz.get_numberOfRight() << "개 입니다!" << endl;
		system("pause");
		return 0;
	}

	return 0;
}


void test(InitialQuiz& intiInitialQuiz) {
	cout << "\n해당 퀴즈는 테스트 모드로 실행되었습니다." << endl;
	cout << "바로 문제 풀이로 넘어갑니다." << endl;
	cout << "각 문제는 " << intiInitialQuiz.get_fewSeconds() << "초 내에 풀어야 합니다." << endl << endl;

	string answer{ };

	for (auto iter{ intiInitialQuiz.get_question().begin() }; iter != intiInitialQuiz.get_question().end(); ++iter) {
		cout << distance(intiInitialQuiz.get_question().begin(), iter) + 1 << "번 문제 " << *iter << endl;

		intiInitialQuiz.guess_answer();
		std::cout << "\n입력 된 값 : " << intiInitialQuiz.get_input() << std::endl;
		intiInitialQuiz.match_answer();
	}
	system("pause");
	exit(EXIT_SUCCESS);
}
