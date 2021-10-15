#include <stdio.h>

// ��ũ�� ��� 
#define LENGTH 3

// ����ü ���� 
typedef struct student {
	char name[31];  // 30 + �� ����
	int kor, eng, mat;
	int total;
	double average;
} Student;

// ����(global) �迭
Student students[LENGTH];


void inputInformation() {
	int i; 
	printf("�л� 3���� ������ ���ʴ�� �Է��ϼ���\n\n");
	for (i = 0; i < LENGTH; i++) {
		printf("�л� %d �̸� >>> ", i + 1);
		gets(students[i].name);  // ���� ���� �Է�
		// scanf("%s", students[i].name]);
		do {
			printf("���� >>> ");
			scanf("%d", &students[i].kor); 	
		} while (students[i].kor < 0 || students[i].kor > 100);
		do {
			printf("���� >>> ");
			scanf("%d", &students[i].eng); 	
		} while (students[i].eng < 0 || students[i].eng > 100);
		do {
			printf("���� >>> ");
			scanf("%d", &students[i].mat); 	
		} while (students[i].mat < 0 || students[i].mat > 100);
		// �Է� ���� ����
		fflush(stdin);
		// �հ�/���
		students[i].total = students[i].kor + students[i].eng + students[i].mat;
		students[i].average = (double)students[i].total / LENGTH; 
	}
}

void generateFile() {
	int i;
	FILE * fp = fopen("score.csv", "wt");
	if (fp == NULL) {
		fprintf(stderr, "file open error!");
		return;
	}
	fprintf(fp, "����,����,����,����,����,���\n");
	for (i = 0; i < LENGTH; i++) {
		fprintf(fp, "%s,%d,%d,%d,%d,%.2f\n", students[i].name
		                                   , students[i].kor
										   , students[i].eng
										   , students[i].mat
										   , students[i].total
										   , students[i].average);
	}
}

int main() {
	inputInformation();
	generateFile();
	return 0;
}

