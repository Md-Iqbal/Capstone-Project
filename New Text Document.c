#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


void choice_list ()
{


  int x;
  printf ("\n\t\t\t\t--->>Have an account already?\n");
  printf ("\n\t\t\t\t--->>Don't have an account yet?\n");
  printf ("\n\n\t\t\t\tPress 0 for signing you up here!!!");
  printf ("\n\n\t\t\t\tYour Choice Please: ");

  scanf ("%d", &x);

  switch (x)
    {
    case 1:
      log_in ();
      break;

    case 0:
      sign_in ();
      break;

    default:
      main ();

    }

}

void log_in ()
{

  system ("cls");
  char password[10], id[30];
  int c, i;
  char x;

  printf ("\n\t\t\t\tLog in you account to see details.\n");

  printf ("\n\t\t\t\tStudent ID: ");
  ///getchar ();
  ///gets (id);
  scanf("%s",id);

  printf ("\n\t\t\t\tPassword: ");
  for (i=0;i<8;i++)
    {
      x = getch ();
      password[i] = x;
      printf ("#");
    }
    welcome ();
}


void sign_in ()
{


  system ("cls");
  char firstname[20], lastname[20], id[30], mail[25], address[300],password[10], re_type_pass[10], contact[20], date[20];
  int c, i;
  char x;


  printf ("\t\t\tPlease Fill All the Information for signing in.\n");

  printf ("\n\t\t\tStudent ID: ");
  fflush(stdin);
  gets (id);
  printf ("\n\t\t\tFirst Name: ");
  gets (firstname);
  printf ("\n\t\t\tLast Name: ");
  gets (lastname);
  printf ("\n\t\t\tEmail: ");
  gets (mail);
  printf ("\n\t\t\tMobile No: ");
  gets (contact);
  printf ("\n\t\t\tBirthdate: ");
  gets (date);
  printf ("\n\t\t\tAddress: ");
  gets (address);
  printf ("\n\t\t\tPassword: ");
  for (i = 1; i <= 8; i++)
    {
      x = getch ();
      password[i] = x;
      x = '*';
      printf ("%c", x);
    }
  printf ("\n\t\t\tRe-enter Password: ");
  for (i = 1; i <= 8; i++)
    {
      x = getch ();
      re_type_pass[i] = x;
      x = '*';
      printf ("%c", x);
    }

  c = strcmp (password, re_type_pass);

  if (c == 0)
    welcome ();

  else
    {
      printf ("\n\t\t\tPassword did not match, try again.\n");
      sign_in ();
    }



}

record(){

    system("cls");

    int i, j;
    struct student{
        char name[30], id[20];
        int batch;
        float gpa;
    }ajaira;

    FILE *student_record=fopen("polapainer_gopon_totto.txt", "ab+");
    if(student_record == '/0') printf("\n\t\t\tError!!!");
    else {
        fputs("Name        Identification No        Batch No", student_record);
        while(1) {
            printf("\n\t\t\tRecord your Information to help DIU.\n");
            printf("\n\t\t\tName: ");
            fflush(stdin);
            gets(ajaira.name);
            ///fputs(ajaira.name, student_record);
            ///fputs("\t\t", student_record);
            printf("\n\t\t\tName: ");
            gets(ajaira.id);
            ///fputs(ajaira.id, student_record);
            ///fputs("\t\t", student_record);
            printf("\n\t\t\tName: ");
            scanf("%d", &ajaira.batch);
            ///fputs(ajaira.batch, student_record);
            ///fputs("\n", student_record);

            fwrite(&ajaira, sizeof(ajaira), 1, student_record);

            printf("\n\nDo You Want to Exit? Press 'n' otherwise, hit the ENTER.\n");
            char x=getch();
            if(x=='n') break;
        }
        fclose(student_record);

        char o;
        printf("\nTo continue press 'y' to exit press'n'.");
        scanf("%d", &o);
        switch(o) {
            case 'y':
            welcome();
            break;
            case 'n':
            exit(0);
            break;
            default:
            main();
        }
    }
}

result ()
{
    char id[15], o;
    int semester;
    float m1, m2, m3, m4, m5, wgpa, sgpa;
    FILE *result=fopen("result.txt","a");
    if(result=='/0') printf("Error!!!\n");
    else {
        fputs("ID No                Semester            Result\n", result);
        while(1) {
            printf("Enter your ID: ");
            scanf("%s", id);
            fwrite(&id, sizeof(id), 1, result);
            fprintf("\t\t\t", result);
            printf("Enter your semester: ");
            scanf("%d",&semester);
            fwrite(&semester, sizeof(semester),1, result);
            fprintf("\t\t\t", result);
            if(semester>=1 && semester<=11) {
                if(semester==1) {
                    printf("GPA of SE111: ");
                    scanf("%f", &m1);
                    printf("GPA of SE112: ");
                    scanf("%f", &m2);
                    printf("GPA of SE113: ");
                    scanf("%f", &m3);
                    printf("GPA of ENG 101: ");
                    scanf("%f", &m4);
                    printf("GPA of AOL 101: ");
                    scanf("%f", &m5);
                    wgpa=m1*3+m2+m3*3+m4*3+m5*3;
                    sgpa=wgpa/13.00;
                    printf("Your SGPA is %.2f\n", sgpa);
                    fwrite(&sgpa, sizeof(sgpa), 1, result);
                    fprintf("\n", result);
                    fclose(result);

                }
                if(semester==2) {
                    printf("GPA of SE121: ");
                    scanf("%f", &m1);
                    printf("GPA of SE122: ");
                    scanf("%f", &m2);
                    printf("GPA of SE123: ");
                    scanf("%f", &m3);
                    printf("GPA of MAT 101: ");
                    scanf("%f", &m4);
                    printf("GPA of PHY 101: ");
                    scanf("%f", &m5);
                    wgpa=m1*3+m2+m3*3+m4*3+m5*3;
                    sgpa=wgpa/13.00;
                    printf("Your SGPA is %.2f\n", sgpa);
                    fwrite(&sgpa, sizeof(sgpa),1, result);
                    fputs("\n", result);
                    fclose(result);
                }
                if(semester==3) {
                    printf("GPA of SE131: ");
                    scanf("%f", &m1);
                    printf("GPA of SE132: ");
                    scanf("%f", &m2);
                    printf("GPA of SE133: ");
                    scanf("%f", &m3);
                    printf("GPA of STA 101: ");
                    scanf("%f", &m4);
                    printf("GPA of MAT 102: ");
                    scanf("%f", &m5);
                    wgpa=m1*3+m2+m3*3+m4*3+m5*3;
                    sgpa=wgpa/13.00;
                    printf("Your SGPA is %.2f\n", sgpa);
                    fwrite(&sgpa, sizeof(sgpa), 1, result);
                    fputs("\n", result);
                    fclose(result);

                }
                if(semester==4) {
                    printf("GPA of SWE 132: ");
                    scanf("%f", &m1);
                    printf("GPA of SWE 213: ");
                    scanf("%f", &m2);
                    printf("GPA of SWE 211: ");
                    scanf("%f", &m3);
                    wgpa=m1*4+m2*4+m3*4;
                    sgpa=wgpa/12.00;
                    printf("Your SGPA is %.2f\n", sgpa);
                    fwrite(&sgpa, sizeof(sgpa), 1, result);
                    fputs("\n", result);
                    fclose(result);

                }
                if(semester==5) {
                    printf("GPA of SWE 233: ");
                    scanf("%f", &m1);
                    printf("GPA of SWE 222: ");
                    scanf("%f", &m2);
                    printf("GPA of SWE 223: ");
                    scanf("%f", &m3);
                    printf("GPA of SWE 224: ");
                    scanf("%f", &m4);
                    wgpa=m1*4+m2*3+m3*4+m4*3;
                    sgpa=wgpa/14.00;
                    printf("Your SGPA is %.2f\n", sgpa);
                    fwrite(&sgpa, sizeof(sgpa),1, result);
                    fputs("\n", result);
                    fclose(result);

                }
                if(semester==6) {
                    printf("GPA of SWE 131: ");
                    scanf("%f", &m1);
                    printf("GPA of SWE 232: ");
                    scanf("%f", &m2);
                    printf("GPA of SWE 132: ");
                    scanf("%f", &m3);
                    printf("GPA of SWE 435: ");
                    scanf("%f", &m4);
                    wgpa=m1*3+m2*4+m3*3+m4*3;
                    sgpa=wgpa/13.00;
                    printf("Your SGPA is %.2f\n", sgpa);
                    fwrite(&sgpa, sizeof(sgpa),1, result);
                    fputs("\n", result);
                    fclose(result);

                }
                if(semester==7) {
                    printf("GPA of SWE 323: ");
                    scanf("%f", &m1);
                    printf("GPA of SWE 312: ");
                    scanf("%f", &m2);
                    printf("GPA of SWE 322: ");
                    scanf("%f", &m3);
                    printf("GPA of SWE 313: ");
                    scanf("%f", &m4);
                    wgpa=m1*3+m2*3+m3*3+m4*4;
                    sgpa=wgpa/13.00;
                    printf("Your SGPA is %.2f\n", sgpa);
                    fwrite(&sgpa, sizeof(sgpa),1, result);
                    fputs("\n", result);
                    fclose(result);

                }
                if(semester==8) {
                    printf("GPA of SWE 321: ");
                    scanf("%f", &m1);
                    printf("GPA of SWE 333: ");
                    scanf("%f", &m2);
                    printf("GPA of SWE 311: ");
                    scanf("%f", &m3);
                    printf("GPA of SWE 413: ");
                    scanf("%f", &m4);
                    wgpa=m1*4+m2*4+m3*3+m4*3;
                    sgpa=wgpa/14.00;
                    printf("Your SGPA is %.2f\n", sgpa);
                    fwrite(&sgpa, sizeof(sgpa),1, result);
                    fputs("\n", result);
                    fclose(result);

                }
                if(semester==9) {
                    printf("GPA of SWE 412: ");
                    scanf("%f", &m1);
                    printf("GPA of SWE 331: ");
                    scanf("%f", &m2);
                    printf("GPA of SWE 422: ");
                    scanf("%f", &m3);
                    printf("GPA of SWE 424: ");
                    scanf("%f", &m4);
                    wgpa=m1*3+m2*3+m3*4+m4*4;
                    sgpa=wgpa/14.00;
                    printf("Your SGPA is %.2f\n", sgpa);
                    fwrite(&sgpa, sizeof(sgpa),1, result);
                    fputs("\n", result);
                    fclose(result);

                }
                if(semester==10) {
                    printf("GPA of SWE 423: ");
                    scanf("%f", &m1);
                    printf("GPA of SWE 425: ");
                    scanf("%f", &m2);
                    printf("GPA of SWE 426: ");
                    scanf("%f", &m3);
                    printf("GPA of SWE 332: ");
                    scanf("%f", &m4);
                    wgpa=m1*4+m2*4+m3*4+m4*3;
                    sgpa=wgpa/15.00;
                    printf("Your SGPA is %.2f\n", sgpa);
                    fwrite(&sgpa, sizeof(sgpa),1, result);
                    fputs("\n", result);
                    fclose(result);

                }
                if(semester==11) {
                    printf("GPA of SWE 411: ");
                    scanf("%f", &m1);
                    printf("GPA of SWE 439: ");
                    scanf("%f", &m2);
                    wgpa=m1*4+m2*3;
                    sgpa=wgpa/7.00;
                    printf("Your SGPA is %.2f\n", sgpa);
                    fwrite(&sgpa, sizeof(sgpa),1, result);
                    fputs("\n", result);
                    fclose(result);

                }
            }
            else if (semester==12) printf("\nContact your guide teacher please.");
            else printf("\nInvalid. Enter the correct one.");

            printf("\n\nDo You Want to Exit? Press 'n' otherwise, hit the ENTER.\n");
            char x=getch();
            if(x=='n') break;

        }
        printf("\nTo continue press 'y' to exit press'n'.");
        scanf("%d", &o);
        switch(o) {
            case 'y':
            welcome();
            break;
            case 'n':
            exit(0);
            break;
            default:
            main();
        }
    }
}

payment_ledger ()
{

  system ("cls");

  int Pamount = 0, amount, Tamount;
  char x;

  printf ("\n\n\t\t\t\t\tInformation about yourPayment");
  printf ("\n\t\t\t****************************************************");
  printf ("\nTotal amount to pay in this semester: BDT 61150\n");
  printf ("The amount you paid: ");
  scanf ("%d", &Pamount);
  amount = 61150 - Pamount;
  printf ("\nThe amount you have to pay: %d", amount);
  Tamount = 137300 + Pamount;
  printf ("\n\nThe amount you have paid in total: ", Tamount);

  printf ("If you want to continue, press 'y'.");
  printf ("For exiting, press 'n'.");
  scanf ("%c", &x);
  switch (x){
    case 'y':
    welcome();
    break;
    case 'n':
    exit (0);
    break;
    default:
    main ();
  }
}

payment_scheme ()
{

  system ("cls");

  printf ("Payment Name\t\t\tAmount(BDT)\t\tMultiple\n");
  printf ("Admission Fee\t\t\t15000\t\tAdmission time\n");
  printf ("Campus Development Fee\t\t\t4500\t\tEvery semester\n");
  printf ("Extra Curriculam Fee\t\t\t1500\t\tEvery semester\n");
  printf ("Lab Fee\t\t\t2000\t\tEvery semester\n");
  printf ("Library Fee\t\t\t3000\t\tAdmission time\n");
  printf ("Rover Scout & BNCC Fee\t\t\t1000\t\tAdmission time\n");
  printf ("Semester Fee\t\t\t5500\t\tEvery semester\n");
  printf ("Student Life Insurance\t\t\t1600\t\tAdmission time\n");
  printf ("Smart Card\t\t\t1000\t\tAdmission time\n");
  printf ("Tuition Fee ( Core )\t\t\t3500\t\tEvery semester\n");
  printf ("Tuition Fee ( Core With Lab for 1 Credit )\t\t\t3600\t\tEvery semester\n");
  printf ("Tuition Fee ( Core With Lab for 2 Credit )\t\t\t3733\t\tEvery semester\n");
  printf ("Tuition Fee ( Core With Lab for 3 Credit )\t\t\t3467\t\tEvery semester\n");
  printf ("Tuition Fee ( Core With Lab for 4 Credit )\t\t\t3400\t\tEvery semester\n");
  printf ("Tuition Fee ( Dissertation/ Oral Assessment )\t\t\t4000\t\tEvery semester\n");
  printf ("Tuition Fee ( General Course )3200\t\tEvery semester\n");
  printf ("Tuition Fee ( Lab )\t\t\t4500\t\tEvery semester\n");
  printf ("Tuition Fee ( Major Course )\t\t\t5000\t\tEvery semester\n");
  printf ("Tuition Fee ( Major Lab )\t\t\t6000\t\tEvery semester\n");
  printf ("Tuition Fee ( Non Core )\t\t\t3200\t\tEvery semester\n");
  printf ("Tuition Fee ( Project/Thesis/Internship )\t\t\t3200\t\tEvery semester\n");

  char o;
    printf("\nTo continue press 'y' to exit press'n'.");
    scanf("%d", &o);
    switch(o) {
        case 'y':
        welcome();
        break;
        case 'n':
        exit(0);
        break;
        default:
        main();
    }
}

laptop ()
{
  system ("cls");

  int x;

  printf ("\n\t\t\tWhich semester do you read now?\n\t\t\t");
  scanf ("%d", &x);
  if (x > 6)
    printf ("\n\t\t\tYou have received your laptop. If not, contact your advisor or DIU Register office.");
  else if (x == 6)
    printf ("\n\t\t\tWelcome! You are eligible for the laptop campaign.");
  else
    printf ("\n\t\t\tSorry, you are not eligible for the laptop campaign.");

    char o;
    printf("\nTo continue press 'y' to exit press'n'.");
    scanf("%d", &o);
    switch(o) {
        case 'y':
        welcome();
        break;
        case 'n':
        exit(0);
        break;
        default:
        main();
    }
}

smart_card ()
{

  system ("cls");

  int x;
  float balance, khoroc;
  printf ("Which semester do you read now?\n");
  scanf ("%d", &x);
  if (x >= 1 && x <= 12)
    {
      printf ("Your Smart Card is now: Active.\n");
      printf ("Enter the amount that you have spend form your card: ");
      scanf ("%f", &khoroc);
      balance = 200.00 - khoroc;
      printf ("Your Smart Card balance is now: %.2f", balance);
    }

  else
    printf ("Your Smart Card is now: Inactive.\n");

    char o;
    printf("\nTo continue press 'y' to exit press'n'.");
    scanf("%d", &o);
    switch(o) {
        case 'y':
        welcome();
        break;
        case 'n':
        exit(0);
        break;
        default:
        main();
    }

}

registered_course ()
{
    system ("cls");

  int x;
  printf ("Enter your semester: ");
  scanf ("%d", &x);
  printf ("Course Code\t\tCourse Title\t\t\tCourse Credit\n");
    if (x >= 1 && x <= 11)
    {
      if (x == 1)
	{
	  printf ("SE111\t\tComputer Fundamentals\t\t\t3\n");
	  printf ("SE113\t\tIntroduction to Software Engineering\t\t\t3\n");
	  printf ("SE112\t\tComputer Fundamentals Lab\t\t\t1\n");
	  printf ("ENG 101\t\tEnglish I\t\t\t3\n");
	  printf ("AOL 101\t\tArt of Living\t\t\t3\n");
	}
      else if (x == 2)
	{
	  printf ("SE122\t\tStructured Programming Lab\t\t\t1\n");
	  printf ("SE123\t\tDiscrete Mathematics\t\t\t3\n");
	  printf ("SE121\t\tStructured Programming\t\t\t3\n");
	  printf ("MAT 101\t\tMathematics I\t\t\t3\n");
	  printf ("PHY 101\t\tPhysics I\t\t\t3\n");
	}
      else if (x == 3)
	{
	  printf ("SE131\t\tData Structure\t\t\t3\n");
	  printf ("SE132\t\tData Structure Lab\t\t\t1\n");
	  printf("SE133\t\tSoftware Development Capstone Project\t\t\t3\n");
	  printf ("STA101\t\tStatistics I\t\t\t3\n");
	  printf ("MAT102\t\tMathematics II\t\t\t3\n");

	}
      else if (x == 4)
	{
	  printf ("SWE 132\t\tJava Programming With Lab\t\t\t4\n");
	  printf ("SWE 213\t\tComputer Algorithm With Lab\t\t\t4\n");
	  printf ("SWE 211\t\tIntroduction to Database wWith Lab\t\t\t4\n");
	}
      else if (x == 5)
	{
	  printf ("SWE 233\t\tObject Oriented Concept & Design With Lab\t\t\t4\n");
	  printf ("SWE 222\t\tSoftware Engineering Assurance & Testing\t\t\t3\n");
	  printf ("SWE 223\t\tDigital Electronics With Lab\t\t\t4\n");
	  printf ("SWE 224\t\tDiscrete Mathematics\t\t\t3\n");
	}
      else if (x == 6)
	{
	  printf("SWE 131\t\tDocumentation of Software Engineering\t\t\t3\n");
	  printf ("SWE 232\t\tOperating System With Lab\t\t\t4\n");
	  printf ("SWE 132\t\tSoftware Project Management\t\t\t3\n");
	  printf ("SWE 435\t\tBussiness Communication\t\t\t3\n");

	}
      else if (x == 7)
	{
	  printf ("SWE 323\t\tSystem Analysis and Design\t\t\t3\n");
	  printf ("SWE 312\t\tTheory of Computing\t\t\t3\n");
	  printf ("SWE 322\t\tSoftware Security\t\t\t3\n");
	  printf ("SWE 313\t\t.Net Programming With Lab\t\t\t4\n");
	}
      else if (x == 8)
	{
	  printf ("SWE 321\t\tData Communication With Lab\t\t\t4\n");
	  printf ("SWE 333\t\tDesktop and Web Programming With Lab\t\t\t4\n");
	  printf ("SWE 311\t\tComputer Architecture & Organization\t\t\t3\n");
	  printf ("SWE 413\t\tSoftware Engineering & Cyber Laws\t\t\t3\n");
	}
      else if (x == 9)
	{
	  printf ("SWE 412\t\tManagement Information System\t\t\t3\n");
	  printf ("SWE 331\t\tObject Oriented Software Development\t\t\t3\n");
	  printf ("SWE 422\t\tNumerical Analysis With Lab\t\t\t4\n");
	  printf ("SWE 424\t\tArtificial Intelligence With Lab\t\t\t4\n");
	}
      else if (x == 10)
	{
	  printf ("SWE 423\t\tAdvance Database Management System With Lab\t\t\t4\n");
	  printf ("SWE 425\t\tTelecommunication Engineering With Lab\t\t\t4\n");
	  printf ("SWE 426\t\tDistrubutive Computing and Network Security With Lab\t\t\t4\n");
	  printf ("SWE 332\t\tSoftware Engineering Project II (Web Programming)\t\t\t3\n");
	}
      else if (x == 11)
	{
	  printf ("SWE 411\t\tComputer Networking With Lab\t\t\t4\n");
	  printf ("SWE 439\t\tProject / Thesis\t\t\t3\n");
	}
    }
  else
    {
        printf ("Wrong option. Choice a correct one among 1 to 11.\n");
    }

    char o;
    printf("\nTo continue press 'y' to exit press'n'.");
    scanf("%d", &o);
    switch(o) {
        case 'y':
        welcome();
        break;
        case 'n':
        exit(0);
        break;
        default:
        main();
    }
}

#define ques1 printf("\nIs the lecture sheet provided by course teacher suffecient for your course?");
#define ques2 printf("\nDo you understand all the lecture of your course teacher?");
#define ques3 printf("\nAre you happy with your techer?");

CF() {
    system ("cls");

    int x;
    char ans1, ans2, ans3;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans1);
    fputs(ans1, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans2);
    fputs(ans2, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans3);
    fputs(ans3, evalution);
    fputs("\n", evalution);
    fclose(evalution);
}
SE() {
    system ("cls");

    int x;
    char ans4, ans5, ans6;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans4);
    fputs(ans4, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans5);
    fputs(ans5, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans6);
    fputs(ans6, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
CFlab() {
    system ("cls");

    int x;
    char ans7, ans8, ans9;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans7);
    fputs(ans7, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans8);
    fputs(ans8, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans9);
    fputs(ans9, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
ENG() {
    system ("cls");

    int x;
    char ans11, ans12, ans13;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans11);
    fputs(ans11, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans12);
    fputs(ans12, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans13);
    fputs(ans13, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
AOL() {
    system ("cls");

    int x;
    char ans14, ans15, ans16;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans16);
    fputs(ans16, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans15);
    fputs(ans15, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans14);
    fputs(ans14, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}

SPlab() {
    system ("cls");

    int x;
    char ans1, ans2, ans3;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans1);
    fputs(ans1, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans2);
    fputs(ans2, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans3);
    fputs(ans3, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
DE() {
    system ("cls");

    int x;
    char ans4, ans5, ans6;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans4);
    fputs(ans4, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans5);
    fputs(ans5, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans6);
    fputs(ans6, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
SP() {
    system ("cls");

    int x;
    char ans7, ans8, ans9;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans7);
    fputs(ans7, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans8);
    fputs(ans8, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans9);
    fputs(ans9, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
MATH() {
    system ("cls");

    int x;
    char ans11, ans12, ans13;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans11);
    fputs(ans11, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans12);
    fputs(ans12, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans13);
    fputs(ans13, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
PHY() {
    system ("cls");

    int x;
    char ans14, ans15, ans16;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans16);
    fputs(ans16, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans15);
    fputs(ans15, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans14);
    fputs(ans14, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
DS() {
    system ("cls");

    int x;
    char ans1, ans2, ans3;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans1);
    fputs(ans1, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans2);
    fputs(ans2, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans3);
    fputs(ans3, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
DSlab() {
    system ("cls");

    int x;
    char ans4, ans5, ans6;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans4);
    fputs(ans4, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans5);
    fputs(ans5, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans6);
    fputs(ans6, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
SDP() {
    system ("cls");

    int x;
    char ans7, ans8, ans9;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans7);
    fputs(ans7, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans8);
    fputs(ans8, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans9);
    fputs(ans9, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
STA() {
    system ("cls");

    int x;
    char ans11, ans12, ans13;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans11);
    fputs(ans11, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans12);
    fputs(ans12, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans13);
    fputs(ans13, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
MATH2() {
    system ("cls");

    int x;
    char ans14, ans15, ans16;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans16);
    fputs(ans16, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans15);
    fputs(ans15, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans14);
    fputs(ans14, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
JPlab() {
    system ("cls");

    int x;
    char ans1, ans2, ans3;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans1);
    fputs(ans1, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans2);
    fputs(ans2, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans3);
    fputs(ans3, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
IDlab() {
    system ("cls");

    int x;
    char ans4, ans5, ans6;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans4);
    fputs(ans4, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans5);
    fputs(ans5, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans6);
    fputs(ans6, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
CAlab() {
    system ("cls");

    int x;
    char ans7, ans8, ans9;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans7);
    fputs(ans7, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans8);
    fputs(ans8, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans9);
    fputs(ans9, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
OOCDlab() {
    system ("cls");

    int x;
    char ans1, ans2, ans3;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans1);
    fputs(ans1, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans2);
    fputs(ans2, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans3);
    fputs(ans3, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
SEAT(){
    system ("cls");

    int x;
    char ans4, ans5, ans6;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans4);
    fputs(ans4, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans5);
    fputs(ans5, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans6);
    fputs(ans6, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
DElab() {
    system ("cls");

    int x;
    char ans7, ans8, ans9;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans7);
    fputs(ans7, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans8);
    fputs(ans8, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans9);
    fputs(ans9, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
DM(){
    system ("cls");

    int x;
    char ans11, ans12, ans13;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans11);
    fputs(ans11, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans12);
    fputs(ans12, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans13);
    fputs(ans13, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
DSE(){
    system ("cls");

    int x;
    char ans1, ans2, ans3;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans1);
    fputs(ans1, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans2);
    fputs(ans2, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans3);
    fputs(ans3, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
OSlab() {
    system ("cls");

    int x;
    char ans4, ans5, ans6;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans4);
    fputs(ans4, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans5);
    fputs(ans5, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans6);
    fputs(ans6, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
SPM() {
    system ("cls");

    int x;
    char ans7, ans8, ans9;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans7);
    fputs(ans7, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans8);
    fputs(ans8, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans9);
    fputs(ans9, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
BC() {
    system ("cls");

    int x;
    char ans11, ans12, ans13;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans11);
    fputs(ans11, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans12);
    fputs(ans12, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans13);
    fputs(ans13, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
SAD() {
    system ("cls");

    int x;
    char ans1, ans2, ans3;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans1);
    fputs(ans1, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans2);
    fputs(ans2, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans3);
    fputs(ans3, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
TC() {
    system ("cls");

    int x;
    char ans4, ans5, ans6;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans4);
    fputs(ans4, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans5);
    fputs(ans5, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans6);
    fputs(ans6, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
SS(){
    system ("cls");

    int x;
    char ans7, ans8, ans9;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans7);
    fputs(ans7, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans8);
    fputs(ans8, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans9);
    fputs(ans9, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
NPlab() {
    system ("cls");

    int x;
    char ans11, ans12, ans13;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans11);
    fputs(ans11, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans12);
    fputs(ans12, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans13);
    fputs(ans13, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
DClab() {
    system ("cls");

    int x;
    char ans1, ans2, ans3;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans1);
    fputs(ans1, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans2);
    fputs(ans2, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans3);
    fputs(ans3, evalution);
    fputs("\n", evalution);
    fclose(evalution);
}
DWPlab() {
    system ("cls");

    int x;
    char ans4, ans5, ans6;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans4);
    fputs(ans4, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans5);
    fputs(ans5, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans6);
    fputs(ans6, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
CAO() {
    system ("cls");

    int x;
    char ans7, ans8, ans9;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans7);
    fputs(ans7, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans8);
    fputs(ans8, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans9);
    fputs(ans9, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
SECW() {
    system ("cls");

    int x;
    char ans11, ans12, ans13;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans11);
    fputs(ans11, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans12);
    fputs(ans12, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans13);
    fputs(ans13, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
MIS() {
    system ("cls");

    int x;
    char ans1, ans2, ans3;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans1);
    fputs(ans1, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans2);
    fputs(ans2, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans3);
    fputs(ans3, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
OOSD() {
    system ("cls");

    int x;
    char ans4, ans5, ans6;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans4);
    fputs(ans4, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans5);
    fputs(ans5, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans6);
    fputs(ans6, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
NAlab() {
    system ("cls");

    int x;
    char ans7, ans8, ans9;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans7);
    fputs(ans7, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans8);
    fputs(ans8, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans9);
    fputs(ans9, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
AIlab() {
    system ("cls");

    int x;
    char ans11, ans12, ans13;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans11);
    fputs(ans11, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans12);
    fputs(ans12, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans13);
    fputs(ans13, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
ADMSlab() {
    system ("cls");

    int x;
    char ans1, ans2, ans3;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans1);
    fputs(ans1, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans2);
    fputs(ans2, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans3);
    fputs(ans3, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
TElab() {
    system ("cls");

    int x;
    char ans4, ans5, ans6;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans4);
    fputs(ans4, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans5);
    fputs(ans5, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans6);
    fputs(ans6, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
DCNSlab() {
    system ("cls");

    int x;
    char ans7, ans8, ans9;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans7);
    fputs(ans7, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans8);
    fputs(ans8, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans9);
    fputs(ans9, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
SEP() {
    system ("cls");

    int x;
    char ans11, ans12, ans13;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans11);
    fputs(ans11, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans12);
    fputs(ans12, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans13);
    fputs(ans13, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
CNlab() {
    system ("cls");

    int x;
    char ans1, ans2, ans3;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans1);
    fputs(ans1, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans2);
    fputs(ans2, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans3);
    fputs(ans3, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}
POT() {
    system ("cls");

    int x;
    char ans4, ans5, ans6;
    printf("Evaluate your Course Teacher now::\n");
    printf("For all question, if your answer is positive press y and if negative press n\n");
    FILE *evalution=fopen("evalution.txt", "w");

    ques1
    scanf("%c", &ans4);
    fputs(ans4, evalution);
    fputs("\n", evalution);
    ques2
    scanf("%c", &ans5);
    fputs(ans5, evalution);
    fputs("\n", evalution);
    ques3
    scanf("%c", &ans6);
    fputs(ans6, evalution);
    fputs("\n", evalution);
    fclose(evalution);

}

teaching_evaluation ()
{
    system ("cls");

  int x, n;
  printf ("Enter your semester: ");
  scanf ("%d", &x);
  printf ("Subject serial\t\tCourse Title\n");
  if (x >= 1 && x <= 11)
    {
      if (x == 1)
	{
	    int s=5;
	  printf ("1. Computer Fundamentals\n");
	  printf ("2. Introduction to Software Engineering\n");
	  printf ("3. Computer Fundamentals Lab\n");
	  printf ("4. English I\n");
	  printf ("5. Art of Living\n");

	  while (s--)
	    {
	      printf("Enter your subject choice to evaluate your course teacher: ");
	      scanf ("%d", &n);
	      switch (n)
	{
	case 1:
	  CF ();
	  break;
	case 2:
	  SE ();
	  break;
	case 3:
	  CFlab ();
	  break;
	case 4:
	  ENG ();
	  break;
	case 5:
	  AOL ();
	  break;
	default:
	  teaching_evaluation ();
	}
	    }
	}
      else if (x == 2)
	{
	    int s=5;
	  printf ("1. Structured Programming Lab\n");
	  printf ("2. Discrete Mathematics\n");
	  printf ("3. Structured Programming\n");
	  printf ("4. Mathematics I\n");
	  printf ("5. Physics I\n");

	  while (s--)
	    {
	      printf("Enter your subject choice to evaluate your course teacher: ");
	      scanf ("%d", &n);
	      switch (n)
	{
	case 1:
	  SPlab ();
	  break;
	case 2:
	  DE ();
	  break;
	case 3:
	  SP ();
	  break;
	case 4:
	  MATH ();
	  break;
	case 5:
	  PHY ();
	  break;
	default:
	  teaching_evaluation ();
	}
	    }
	}
      else if (x == 3)
	{
	    int s=5;
	  printf ("1. Data Structure\n");
	  printf ("2. Data Structure Lab\n");
	  printf ("3. Software Development Capstone Project\n");
	  printf ("4. Statistics I\n");
	  printf ("5. Mathematics II\n");

	  while (s--)
	    {
	      printf("Enter your subject choice to evaluate your course teacher: ");
	      scanf ("%d", &n);
	      switch (n)
	{
	case 1:
	  DS ();
	  break;
	case 2:
	  DSlab ();
	  break;
	case 3:
	  SDP ();
	  break;
	case 4:
	  STA ();
	  break;
	case 5:
	  MATH2 ();
	  break;
	default:
	  teaching_evaluation ();
	}
	    }
	}
      else if (x == 4)
	{
	    int s=3;
	  printf ("1. Java Programming With Lab\n");
	  printf ("2. Computer Algorithm With Lab\n");
	  printf ("3. Introduction to Database wWith Lab\n");

	  while(s--) {
	      printf("Enter your subject choice to evaluate your course teacher: ");
            scanf("%d",&n);
            switch(n) {
                case 1:
                JPlab();
                break;
                case 2:
                CAlab();
                break;
                case 3:
                IDlab();
                break;
                default:
                teaching_evaluation();
            }
        }
	}
      else if (x == 5)
	{
	    int s=4;
	  printf ("1. Object Oriented Concept & Design With Lab\n");
	  printf ("2. Software Engineering Assurance & Testing\n");
	  printf ("3. Digital Electronics With Lab\n");
	  printf ("4. Discrete Mathematics\n");

	  while(s--) {
	      printf("Enter your subject choice to evaluate your course teacher: ");
          scanf("%d",&n);
          switch(n) {
                case 1:
                OOCDlab();
                break;
                case 2:
                SEAT();
                break;
                case 3:
                DElab();
                break;
                case 4:
                DM();
                break;
                default:
                teaching_evaluation();
            }
        }
	}
      else if (x == 6)
	{
	    int s=4;
	  printf ("1. Documentation of Software Engineering\n");
	  printf ("2. Operating System With Lab\n");
	  printf ("3. Software Project Management\n");
	  printf ("4. Bussiness Communication\n");

	  while(s--) {
	      printf("Enter your subject choice to evaluate your course teacher: ");
                scanf("%d",&n);
                switch(n) {
                    case 1:
                    DSE();
                    break;
                    case 2:
                    OSlab();
                    break;
                    case 3:
                    SPM();
                    break;
                    case 4:
                    BC();
                    break;
                    default:
                    teaching_evaluation();
                }
            }
	}
      else if (x == 7)
	{
	    int s=4;
	  printf ("1. System Analysis and Design\n");
	  printf ("2. Theory of Computing\n");
	  printf ("3. Software Security\n");
	  printf ("4. .Net Programming With Lab\n");

	  while(s--) {
	      printf("Enter your subject choice to evaluate your course teacher: ");
                scanf("%d",&n);
                switch(n) {
                    case 1:
                    SAD();
                    break;
                    case 2:
                    TC();
                    break;
                    case 3:
                    SS();
                    break;
                    case 4:
                    NPlab();
                    break;
                    default:
                    teaching_evaluation();
                }
            }
	}
      else if (x == 8)
	{
	    int s=4;
	  printf ("1. Data Communication With Lab\n");
	  printf ("2. Desktop and Web Programming With Lab\n");
	  printf ("3. Computer Architecture & Organization\n");
	  printf ("4. Software Engineering & Cyber Laws\n");

	  while(s--) {
	      printf("Enter your subject choice to evaluate your course teacher: ");
                scanf("%d",&n);
                switch(n) {
                    case 1:
                    DClab();
                    break;
                    case 2:
                    DWPlab();
                    break;
                    case 3:
                    CAO();
                    break;
                    case 4:
                    SECW();
                    break;
                    default:
                    teaching_evaluation();
                }
            }
	}
      else if (x == 9)
	{
	    int s=4;
	  printf ("1. Management Information System\n");
	  printf ("2. Object Oriented Software Development\n");
	  printf ("3. Numerical Analysis With Lab\n");
	  printf ("4. Artificial Intelligence With Lab\n");

	  while(s--) {
	      printf("Enter your subject choice to evaluate your course teacher: ");
                scanf("%d",&n);
                switch(n) {
                    case 1:
                    MIS();
                    break;
                    case 2:
                    OOSD();
                    break;
                    case 3:
                    NAlab();
                    break;
                    case 4:
                    AIlab();
                    break;
                    default:
                    teaching_evaluation();
                }
            }
	}
      else if (x == 10)
	{
	    int s=4;
	  printf ("1. Advance Database Management System With Lab\n");
	  printf ("2. Telecommunication Engineering With Lab\n");
	  printf("3. Distrubutive Computing and Network Security With Lab\n");
	  printf("4. Software Engineering Project II (Web Programming)\n");

	  while(s--) {
	      printf("Enter your subject choice to evaluate your course teacher: ");
                scanf("%d",&n);
                switch(n) {
                    case 1:
                    ADMSlab();
                    break;
                    case 2:
                    TElab();
                    break;
                    case 3:
                    DCNSlab();
                    break;
                    case 4:
                    SEP();
                    break;
                    default:
                    teaching_evaluation();
                }
            }
	}
      else if (x == 11)
	{
	    int s=2;
	  printf ("1. Computer Networking With Lab\n");
	  printf ("2. Project / Thesis\n");

	  while(s--) {
	      printf("Enter your subject choice to evaluate your course teacher: ");
                scanf("%d",&n);
                switch(n) {
                    case 1:
                    CNlab();
                    break;
                    case 2:
                    POT();
                    break;
                    default:
                    teaching_evaluation();
                }
            }
	}
    }
  else
    {
    printf ("Wrong option. Choice a correct one among 1 to 11.\n");

    }

    char o;
    printf("\nTo continue press 'y' to exit press'n'.");
    scanf("%d", &o);
    switch(o) {
        case 'y':
        welcome();
        break;
        case 'n':
        exit(0);
        break;
        default:
        main();
    }

}

information ()
{

  int x;
  printf
    ("Please set up Internet connection on your device to see information sector.");
  printf ("\npress 1 to see about Software Engineering Department");
  printf ("\npress 2 to see about Main Campus");
  printf ("\npress 3 to see about Permanent Campus");
  printf ("\npress 0 to exit");
  scanf ("%d", &x);
  if (x == 1)
    system ("explorer http://swe.daffodilvarsity.edu.bd/");
  else if (x == 2)
    system ("explorer https://daffodilvarsity.edu.bd/page/main_campus/main-campus");
  else if (x == 3)
    system ("explorer https://daffodilvarsity.edu.bd/campus/permanent-campus");
  else if (x == 0)
    exit (0);
  else
    printf ("Choice does not match. Please choice among 1 to 3 or 0 to exit.");

    char o;
    printf("\nTo continue press 'y' to exit press'n'.");
    scanf("%d", &o);
    switch(o) {
        case 'y':
        welcome();
        break;
        case 'n':
        exit(0);
        break;
        default:
        main();
    }
}

notice (){

      int x;
      printf ("Please set up Internet connection on your device to see the DIU central notice bord.\n");
      printf ("press 1 to see DIU central notice bord.\n");
      printf ("press 0 to exit.\n");
      scanf ("%d", &x);
      if (x == 1)
	  system ("explorer https://daffodilvarsity.edu.bd/noticeboard");
      else if (x == 0)
	  exit (0);
      else
	  printf ("Choice does not match. Please choice 1 or 0.\n");
}

void welcome (){

	system ("cls");
	int c;
	printf ("\n\n\t\t\tWelcome! You have logged in successfully.\n");
	printf ("\t\t\tChoice and browse your all records!");
	printf ("\n\t\t\t1. Record");
	printf ("\n\t\t\t2. Result");
	printf ("\n\t\t\t3. Payment ledger");
	printf ("\n\t\t\t4. Payment scheme");
	printf ("\n\t\t\t6. Laptop eligibility");
	printf ("\n\t\t\t7. Smart card");
	printf ("\n\t\t\t8. Registered course");
	printf ("\n\t\t\t9. Teaching evaluation");
	printf ("\n\t\t\t11. Information");
	printf ("\n\t\t\t12. Notice bord");
	printf ("\n\t\t\t**For exiting please press 0");

	printf ("\n\n\t\t\tEnter your choice please: ");
	scanf ("%d", &c);
	switch (c)
	  {
	  case 1:
	    record ();
	    break;
	  case 2:
	    result ();
	    break;
	  case 3:
	    payment_ledger ();
	    break;
	  case 4:
	    payment_scheme ();
	    break;
	  case 6:
	    laptop ();
	    break;
	  case 7:
	    smart_card ();
	    break;
	  case 8:
	    registered_course ();
	    break;
	  case 9:
	    teaching_evaluation ();
	    break;
	  case 11:
	    information ();
	    break;
	  case 12:
	    notice ();
	    break;
	  case 0:
	    exit (0);
	    break;
	  default:
	    main ();
	  }
}

      int main ()
      {

	printf ("\n\n\t\t\t\tDaffodil International University");
	printf ("\n\t\t\t   ------->>  Software Engineering  <<-------");
	printf ("\n\t\t\t\t      :::Student Portal:::");
	printf ("\n\t\t\t****************************************************");
	printf ("\n\t\t\t****************************************************\n\n\n");

	choice_list ();


	return 0;
      }

