#include <stdio.h>
#include <string.h>

#define LENGTH 10

typedef struct book {  // ���� Ÿ���� struct book 
	int bookNo;
	char title[31];
	char author[31];
} Book;  // Book Ÿ���� ���� 

Book books[LENGTH];  // Book books[10];
int idx = 0;

void menu() {
	printf("1. ���\n");
	printf("2. ��ȸ\n");
	printf("3. ��ü\n");
	printf("0. ����\n");
}

void addBook() {
	int bookNo;
	char title[31];
	char author[31];
	// Book�� ������ �ε����� idx�̴�.
	// �ε��� ���� ���� : 0 ~ (LENGTH - 1)
	if (idx == LENGTH) {
		printf("�迭�� �� á���ϴ�.\n");
		return; 
	}
	// å ��ȣ : 1001 ~ 9999
	printf("å ��ȣ �Է� >>> ");
	scanf("%d", &bookNo);
	if (bookNo <= 1000 || bookNo >= 10000) {
		printf("�߸��� å ��ȣ �Դϴ�.\n");
		return;
	}
	printf("å ���� �Է� >>> ");
	scanf("%s", title);
	printf("å ���� �Է� >>> ");
	scanf("%s", author);
	books[idx].bookNo = bookNo;
	strcpy(books[idx].title, title);
	strcpy(books[idx].author, author);
	idx++;
} 

void queryBook() {
	int findNo;
	int i;
	if (idx == 0) {
		printf("å�� �����ϴ�.\n");
		return;
	}
	printf("��ȸ�� å ��ȣ >>> ");
	scanf("%d", &findNo);
	// Book�� books�迭�� idx��ŭ ����Ǿ� �ִ�.
	for (i = 0; i < idx; i++) {
		if (findNo == books[i].bookNo) {
			printf("����: %s, ����: %s\n", books[i].title, books[i].author);
			return;  // ã������ queryBook() �Լ��� ������. 
		}
	}
	// ��ȸ�� ������ ���� å�̴�.
	printf("å ��ȣ %d�� ���� å�Դϴ�.\n", findNo); 
}

void printBook() {
	int i;
	if (idx == 0) {
		printf("å�� �����ϴ�.\n");
		return;
	}
	for (i = 0; i < idx; i++) {
		printf("%d, %s, %s\n", books[i].bookNo, books[i].title, books[i].author);
	}
}

int main() {
	int choice;
	while (1) {
		menu();
		printf("�۾� ���� >>> ");
		scanf("%d", &choice);
		switch (choice) {
			case 1: addBook(); break;
			case 2: queryBook(); break;
			case 3: printBook(); break;
			case 0: printf("�����մϴ�.\n"); return 0;
			default: printf("���� �۾��Դϴ�. �ٽ� �Է��ϼ���\n");
		}
	}
}

