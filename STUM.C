#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void menu();
void add();
void view();

struct student {
    char name[20];
    char mobile[15];
    char rollno[10];
    char course[20];
    char branch[20];
};

void main() {
    clrscr();
    gotoxy(15,8);
    printf("<--:Student Record Management System:-->");
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
    menu();
}

void menu() {
    int choice;
    clrscr();
    gotoxy(10,3);
    printf("<--:MENU:-->");
    gotoxy(10,5);
    printf("1 : Add Record.");
    gotoxy(10,6);
    printf("2 : View Record.");
    gotoxy(10,7);
    printf("3 : Exit.");
    gotoxy(10,9);
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            add();
            break;
        case 2:
            view();
            break;
        case 3:
            exit(0);
        default:
            gotoxy(10,11);
            printf("Invalid Choice.");
            getch();
            menu();
    }
}

void add() {
    FILE *fp;
    struct student std;
    char another = 'y';
    clrscr();

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        getch();
        exit(0);
    }

    while(another == 'y') {
        clrscr();
        gotoxy(10,3); printf("<--:ADD RECORD:-->");
        gotoxy(10,5); printf("Enter Name: ");
        scanf("%s", std.name);
        gotoxy(10,6); printf("Enter Mobile No: ");
        scanf("%s", std.mobile);
        gotoxy(10,7); printf("Enter Roll No: ");
        scanf("%s", std.rollno);
        gotoxy(10,8); printf("Enter Course: ");
        scanf("%s", std.course);
        gotoxy(10,9); printf("Enter Branch: ");
        scanf("%s", std.branch);

        fwrite(&std, sizeof(std), 1, fp);
        gotoxy(10,11); printf("Add another record (y/n)? ");
        another = getch();
    }

    fclose(fp);
    gotoxy(10,13); printf("Press any key to return to menu...");
    getch();
    menu();
}

void view() {
    FILE *fp;
    struct student std;
    int i = 1, row = 7;
    clrscr();

    gotoxy(10,3);
    printf("<--:VIEW RECORDS:-->");
    gotoxy(10,5);
    printf("S.No  Name       Mobile        RollNo  Course   Branch");
    gotoxy(10,6);
    printf("------------------------------------------------------");

    fp = fopen("record.txt","rb");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        getch();
        return;
    }

    while(fread(&std, sizeof(std), 1, fp)) {
        gotoxy(10,row);
        printf("%-5d %-10s %-12s %-7s %-8s %-10s", i++, std.name, std.mobile, std.rollno, std.course, std.branch);
        row++;
    }

    fclose(fp);
    gotoxy(10,row+2);
    printf("Press any key to return to menu...");
    getch();
    menu();
}
