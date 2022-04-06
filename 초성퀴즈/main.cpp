//#define TEST
#include "initialQuiz.h"
#include <algorithm>

void test(InitialQuiz&);

int main() {
	InitialQuiz intiInitialQuiz{ };

	cout << "��Ʈ���� �ʼ���� ���Ű��� ȯ���մϴ�!" << endl;

#ifdef TEST
	test(intiInitialQuiz);
#endif // TEST

	string pw{ };
	while (true) {
		cout << intiInitialQuiz.get_splash() << endl << endl;

		cout << "�����ϱ� ���� ��й�ȣ�� �Է����ֽñ� �ٶ��ϴ�." << endl;
		cout << ">>> ";
		cin >> pw;
		if (intiInitialQuiz.get_pw() != pw) {
			cout << "��й�ȣ�� ���� �ʽ��ϴ�." << endl;
			system("pause");
			system("cls");
			continue;
		}

		cout << "5�� �� ������ ������ �˴ϴ�. ��/��Ű�� ���� ��/�� ��ȯ Ȯ�����ּ���!" << endl << endl;
		sleep_for(seconds{ 5 });

		intiInitialQuiz.stage();

		cout << "\n���߽� ������ �� " << intiInitialQuiz.get_numberOfRight() << "�� �Դϴ�!" << endl;
		system("pause");
		return 0;
	}

	return 0;
}


void test(InitialQuiz& intiInitialQuiz) {
	cout << "\n�ش� ����� �׽�Ʈ ���� ����Ǿ����ϴ�." << endl;
	cout << "�ٷ� ���� Ǯ�̷� �Ѿ�ϴ�." << endl;
	cout << "�� ������ " << intiInitialQuiz.get_fewSeconds() << "�� ���� Ǯ��� �մϴ�." << endl << endl;

	string answer{ };

	for (auto iter{ intiInitialQuiz.get_question().begin() }; iter != intiInitialQuiz.get_question().end(); ++iter) {
		cout << distance(intiInitialQuiz.get_question().begin(), iter) + 1 << "�� ���� " << *iter << endl;

		intiInitialQuiz.guess_answer();
		std::cout << "\n�Է� �� �� : " << intiInitialQuiz.get_input() << std::endl;
		intiInitialQuiz.match_answer();
	}
	system("pause");
	exit(EXIT_SUCCESS);
}
