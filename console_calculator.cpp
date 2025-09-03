#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAX 10
//Functions
void operation();
void exp_trig();
void conversion();
void interest();
void gpacalc();
void matrix();
void guessno();
void dataentry(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int rowA, int colA, int rowB, int colB);


int main()
{
	int choice;

	do{
		cout<<"===================CALCULATOR===================="<<endl;
		cout<<"Choose option number"<<endl;
		cout<<"1. 4 Basic operations\n2. Exponent & Trig operations\n3. Number System Conversion"<<endl;
		cout<<"4. Interest Calculator\n5. Gpa calculator\n6. Matrix Calculations\n7. Guess number\n8. Exit"<<endl;
		cin>>choice;

		switch(choice){
			case 1:
			   	//4 operations
				cout<<"\n====================4 OPERATIONS==================="<<endl;
				operation();
				break;
			case 2:
				//Exp and trig
				cout<<"\n=================EXPONENTS & TRIGONOMETRY==================="<<endl;
				exp_trig();
				break;
			case 3:
				//no system conversion
				cout<<"\n==================NUMBER SYSTEM CONVERSION==================="<<endl;
				conversion();
				break;
			case 4:
				//Interest calculation
				cout<<"\n==================INTEREST CALCULATOR==================="<<endl;
				interest();
				break;
			case 5:
				//gpa calc
				cout<<"\n====================GPA CALCULATOR==================="<<endl;
				gpacalc();
				break;
			case 6:
				//matrix operations
				cout<<"\n====================MATRIX CALCULATOR==================="<<endl;
				matrix();
				break;
			case 7:
				//guess game
				cout<<"\n====================GUESS NUMBER==================="<<endl;
				guessno();
				break;
			case 8:
			   	cout<<"Thank you for using our calculator"<<endl;
				cout<<"Program Ending...."<<endl;
			 	return 0;
				break;
			default:
				cout<<"Invalid option"<<endl;
		}
	}while(choice != 8);
	return 0;
}

void operation(){
//variable declaration
	int operation;
	float v1, v2;

	do{
	//user promtps
	   cout<<"What operation you want to select? enter the respective number for operation"<<endl;
	   cout<<"1. Add \n2. Subtract \n3. Multiply \n4. Division \n5. Back to main menu"<<endl;
	   cin>>operation;

	   switch(operation){
        case 1:
        	cout<<"\n---------------=Addition=----------------\n";
			cout<<"Enter value 1: ";		cin>>v1;
			cout<<"Enter value 2: ";		cin>>v2;
			cout<<"Answer: "<<v1+v2<<endl;
	     	break;
	    case 2:
		    cout<<"\n--------------=Subtraction=-----------------\n";
			cout<<"Enter value 1: ";		cin>>v1;
			cout<<"Enter value 2: ";		cin>>v2;
			cout<<"Answer: "<<v1-v2<<endl;
	       	break;
		case 3:
			cout<<"\n--------------=Multiplication=-----------------\n";
			cout<<"Enter value 1: ";		cin>>v1;
			cout<<"Enter value 2: ";		cin>>v2;
			cout<<"Answer: "<<v1*v2<<endl;
	       	break;
		case 4:
			cout<<"\n----------------=Division=-----------------\n";
			do{
			   cout<<"Enter value 1: ";		cin>>v1;
			   cout<<"Enter value 2: ";		cin>>v2;
		    }while(v2 == 0);
			cout<<"Answer: "<<v1/v2<<endl;
	       	break;
		case 5:
			 return;
		default:
			cout<<"Invalid operation!"<<endl;
	   }
 	}while(operation != 5);
}
void exp_trig(){
	int operation, op;
	int power, base;
	double x;

	do{
	   cout<<"What operation you want to select? enter the respective number for operation"<<endl;
	   cout<<"1. Exponent \n2. Trigonometric functions \n3. Inverse trigonometric functions\n4. Hyperbolic Functions \n5. Back to main menu"<<endl;
	   cin>>operation;

	   switch(operation){
        case 1:
        	cout<<"\n---------------=Exponents=----------------\n";
			cout<<"Enter base: ";			cin>>base;
			cout<<"Enter exponent: ";		cin>>power;
			cout<<"Answer: "<<pow(base, power)<<endl;
	     	break;
	    case 2:
		    cout<<"\n--------------=Trigonometric functions=-----------------\n";
			do{
			cout<<"Choose option: \n1. Sin\n2. Cos\n3. Tan\n4. Back"<<endl;
			cin>>op;
			switch(op){
				case 1:
					cout<<"Enter value: ";		cin>>x;
					cout<<"Answer: "<<sin(x)<<endl;
					break;
				case 2:
					cout<<"Enter value: ";		cin>>x;
					cout<<"Answer: "<<cos(x)<<endl;
					break;
				case 3:
					cout<<"Enter value: ";		cin>>x;
					cout<<"Answer: "<<tan(x)<<endl;
					break;
				case 4:
					return;
				default:
					cout<<"Invalid operation!"<<endl;
			}
			}while(op != 4);
	       	break;
		case 3:
			cout<<"\n--------------=Inverse trigonometric functions=-----------------\n";
			do{
			cout<<"Choose option: \n1. arcSin\n2. arcCos\n3. arcTan\n4. Back"<<endl;
			cin>>op;
			switch(op){
				case 1:
					cout<<"Enter value within [-1,1]: ";		cin>>x;
					cout<<"Answer: "<<asin(x)<<endl;
					break;
				case 2:
					cout<<"Enter value within [-1,1]: ";		cin>>x;
					cout<<"Answer: "<<acos(x)<<endl;
					break;
				case 3:
					cout<<"Enter value: ";		cin>>x;
					cout<<"Answer: "<<atan(x)<<endl;
					break;
				case 4:
					return;
				default:
					cout<<"Invalid operation!"<<endl;
			}
			}while(op != 4);
	       	break;
		case 4:
			cout<<"\n----------------=Hyperbolic Functions=-----------------\n";
			do{
			cout<<"Choose option: \n1. hyperbolicSin\n2. hyperbolicCos\n3. hyperbolicTan\n4. Back"<<endl;
			cin>>op;
			switch(op){
				case 1:
					cout<<"Enter value: ";		cin>>x;
					cout<<"Answer: "<<sinh(x)<<endl;
					break;
				case 2:
					cout<<"Enter value: ";		cin>>x;
					cout<<"Answer: "<<cosh(x)<<endl;
					break;
				case 3:
					cout<<"Enter value: ";		cin>>x;
					cout<<"Answer: "<<tanh(x)<<endl;
					break;
				case 4:
					return;
				default:
					cout<<"Invalid operation!"<<endl;
			}
			}while(op != 4);
	       	break;
		case 5:
			 return;
		default:
			cout<<"Invalid operation!"<<endl;
	   }
 	}while(operation != 5);
}
void conversion(){
	int operation;
	float num;

	do{
	//user promtps
	   cout<<"Enter the respective number for conversion"<<endl;
	   cout<<"1. cm -> m \n2. m -> cm \n3. ml -> l"<<
	   " \n4. l -> ml \n5. g -> kg \n6. kg -> g \n7. Back to main menu"<<endl;
	   cin>>operation;

	   switch(operation){
        case 1:
        	cout<<"\n---------------= cm -> m =----------------\n";
			cout<<"Enter cm: ";			cin>>num;
			cout<<"Answer: "<<num/100<<"m"<<endl;
	     	break;
	    case 2:
		    cout<<"\n--------------= m -> cm =-----------------\n";
			cout<<"Enter m: ";			cin>>num;
			cout<<"Answer: "<<num*100<<"cm"<<endl;
	       	break;
		case 3:
			cout<<"\n--------------= ml -> l =-----------------\n";
			cout<<"Enter ml: ";			cin>>num;
			cout<<"Answer: "<<num/1000<<"l"<<endl;
	       	break;
		case 4:
			cout<<"\n----------------= l -> ml =-----------------\n";
			cout<<"Enter l: ";			cin>>num;
			cout<<"Answer: "<<num*1000<<"ml"<<endl;
	       	break;
		case 5:
			cout<<"\n--------------= g -> kg =-----------------\n";
			cout<<"Enter g: ";			cin>>num;
			cout<<"Answer: "<<num/1000<<"kg"<<endl;
	       	break;
		case 6:
			cout<<"\n----------------= kg -> g =-----------------\n";
			cout<<"Enter kg: ";			cin>>num;
			cout<<"Answer: "<<num*1000<<"g"<<endl;
	       	break;
		case 7:
			 return;
		default:
			cout<<"Invalid operation!"<<endl;
	}
	}while(operation != 7);
}
void interest(){
	float annualinterest, balance, month;
	float withdraw, amount, monthlyinterest;
	int count;

	cout<<"Enter the annual interest rate: "<<endl;
	cin>>annualinterest;
	cout<<"Enter your starting balance: "<<endl;
	cin>>balance;
	cout<<"Enter the number of months passed since account created: "<<endl;
	cin>>month;

	for(count = 1; count<=month; count++)
	{
		cout<<"Enter the amount deposited during this month: "<<endl;
		cin>>amount;
		if(amount>=0)
		{
			balance = balance + amount;
			amount++;
		}
		else
		{
			cout<<"Amount cannot be in negative!"<<endl;
			cout<<"Enter the amount deposited during this month: "<<endl;
			cin>>amount;
			balance = balance + amount;
			amount++;
		}
		cout<<"Enter the amount withdrawn: "<<endl;
		cin>>withdraw;
		if(withdraw>=0)
		{
			balance = balance - withdraw;
			withdraw++;
		}
		else if(withdraw<0)
		{
			cout<<"Withdraw amount cannot be in negative!"<<endl;
		}
		else if(withdraw>balance){
			cout<<"Withdraw amount can not be more than balance"<<endl;
		}
		monthlyinterest = annualinterest/12;
		balance = balance + (monthlyinterest* balance);
	}
	cout<<"Ending Balance: $"<<balance<<endl;
	cout<<"Total deposits: $"<<amount<<endl;
	cout<<"Total amount withdrawn: $"<<withdraw<<endl;
}
void gpacalc(){
	int size;
	cout<<"Enter the total theory and lab subjects you have: ";			cin>>size;

	float *mark = new float[size];
	float *crdt = new float[size];
	string *name = new string[size];
	float *grade = new float[size];
	float *gradepoint = new float[size];
	float coursegrade = 0.0;
	float gradeablecrdt = 0;

 	cout<<"\n\n";
	for(int i = 0; i<size; i++){
		cout<<"Enter the name for subject "<<i+1<<": ";
		cin>>name[i];
		cout<<"Enter the marks for subject (0-100 only)"<<i+1<<": ";
		cin>>mark[i];
		if(mark[i]<0 || mark[i]>100){
			cout<<"re-enter marks within range 0-100"<<endl;
			cin>>mark[i];
		}
		cout<<"Enter the credit hours for "<<i+1<<" subject: ";
		cin>>crdt[i];
		gradeablecrdt += crdt[i];
	}

	for(int i= 0; i<size; i++)
	{
		if (mark[i]>=90)		gradepoint[i] = 4.00;
		else if(mark[i]>=86)	gradepoint[i] = 4.00;
		else if(mark[i]>=82)	gradepoint[i] = 3.67;
		else if(mark[i]>=78)	gradepoint[i] = 3.33;
		else if(mark[i]>=74)	gradepoint[i] = 3.00;
		else if(mark[i]>=70)	gradepoint[i] = 2.67;
		else if(mark[i]>=66)	gradepoint[i] = 2.33;
		else if(mark[i]>=62)	gradepoint[i] = 2.00;
		else if(mark[i]>=58)	gradepoint[i] = 1.67;
		else if(mark[i]>=54)	gradepoint[i] = 1.33;
		else if(mark[i]>=50)	gradepoint[i] = 1.00;
		else gradepoint[i] = 0;

		cout<<"\n your "<<name[i]<<" gradepoint is "<<gradepoint[i]<<endl;
		cout<<"your "<<name[i]<<" grade letter is ";

		if(mark[i]>=90)				cout<<"A+\n";
		else if(mark[i]>=86)		cout<<"A\n";
 		else if(mark[i]>=82)		cout<<"A-\n";
		else if(mark[i]>=78)		cout<<"B+\n";
		else if(mark[i]>=74)		cout<<"B\n";
		else if(mark[i]>=70)		cout<<"B-\n";
		else if(mark[i]>=66)		cout<<"C+\n";
		else if(mark[i]>=62)		cout<<"C\n";
		else if(mark[i]>=58)		cout<<"C-\n";
		else if(mark[i]>=54)		cout<<"D+\n";
		else if(mark[i]>=50)		cout<<"D\n";
		else 						cout<<"F\n";
	}

	for(int i= 0; i<size; i++)
	{
		grade[i] = gradepoint[i]*crdt[i];	//course grade of each subject
		coursegrade += grade[i];	//sum of all course grades calculated above
	}

//gpa = sum of (course grade points*course credits)/sum of gradable credits
	float gpa = coursegrade/gradeablecrdt;

cout<<"\n\n";
//display gpa and special result messages
	(gpa == 4.00)
	?cout<<"\n Your gpa is "<<gpa<<". Congratulations! your name is placed on Rector List of honour.\n"
	:(gpa > 3.50)
		?cout<<"\n Your gpa is "<<gpa<<". Congratulations! your name is placed in the Dean's list of Honour.\n"
		:(gpa < 2.00)
			?cout<<"\n Your gpa is "<<gpa<<". We are sorry, your name is placed in Warning list."
			:cout<<"\n Your gpa is "<<gpa<<endl;

	delete []grade;
	delete []name;
	delete []crdt;
	delete []mark;
	delete []gradepoint;
}
void matrix(){
	int operation;
	int rowA, rowB, colA, colB;
	int matrixA[MAX][MAX];
	int matrixB[MAX][MAX];
	int matrixC[MAX][MAX];


	do{
	//user promtps
	   cout<<"What operation you want to select? enter the respective number for operation"<<endl;
	   cout<<"1. Add \n2. Subtract \n3. Multiply \n4. Transpose \n5. Back to main menu"<<endl;
	   cin>>operation;

	   switch(operation){
        case 1:
        	cout<<"\n---------------=Matrix Addition=----------------\n";
			//Matrix A inputs
			cout<<"Enter the number of rows and columns (maximum 10) for the first matrix: ";
			cin>>rowA>>colA;
			while(rowA>10 || colA>10)
			{
				cout<<"invalid size. maximum size must be  10."<<endl;
				cout<<"Enter the number of rows and columns for the first matrix: ";
				cin>>rowA>>colA;
			}

			 //Matrix B inputs
			cout<<"Enter the number of rows and columns (maximum 10) for the second matrix: ";
			cin>>rowB>>colB;
			while(rowB>10 || colB>10)
			{
				cout<<"invalid size. maximum size must be  10."<<endl;
				cout<<"Enter the number of rows and columns for the first matrix: ";
				cin>>rowB>>colB;
			}
			if(rowA == rowB && colA == colB){
        		dataentry(matrixA, matrixB, rowA, colA, rowB, colB);
				for(int i = 0; i<rowA; i++){
					for(int j =0; j<colA; j++){
						matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
					}
				}
				cout<<"Answer Matrix: "<<endl;
				for(int i = 0; i<rowA; i++){
					for(int j =0; j<colA; j++){
						cout<<matrixC[i][j]<<" ";
					}
					cout<<endl;
				}
			}
			else
				cout<<"Matrix addition is only possible for same dimension matrices"<<endl;
	     	break;
	    case 2:
		    cout<<"\n--------------=Matrix Subtraction=-----------------\n";
			//Matrix A inputs
			cout<<"Enter the number of rows and columns (maximum 10) for the first matrix: ";
			cin>>rowA>>colA;
			while(rowA>10 || colA>10)
			{
				cout<<"invalid size. maximum size must be  10."<<endl;
				cout<<"Enter the number of rows and columns for the first matrix: ";
				cin>>rowA>>colA;
			}

			 //Matrix B inputs
			cout<<"Enter the number of rows and columns (maximum 10) for the second matrix: ";
			cin>>rowB>>colB;
			while(rowB>10 || colB>10)
			{
				cout<<"invalid size. maximum size must be  10."<<endl;
				cout<<"Enter the number of rows and columns for the first matrix: ";
				cin>>rowB>>colB;
			}
			if(rowA == rowB && colA == colB){
        		dataentry(matrixA, matrixB, rowA, colA, rowB, colB);
				for(int i = 0; i<rowA; i++){
					for(int j =0; j<colA; j++){
						matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
					}
				}
				cout<<"Answer Matrix: "<<endl;
				for(int i = 0; i<rowA; i++){
					for(int j =0; j<colA; j++){
						cout<<matrixC[i][j]<<" ";
					}
					cout<<endl;
				}
			}
			else
				cout<<"Matrix Subtraction is only possible for same dimension matrices"<<endl;
	       	break;
		case 3:
			cout<<"\n--------------=Matrix Multiplication=-----------------\n";
			//Matrix A inputs
			cout<<"Enter the number of rows and columns (maximum 10) for the first matrix: ";
			cin>>rowA>>colA;
			while(rowA>10 || colA>10)
			{
				cout<<"invalid size. maximum size must be  10."<<endl;
				cout<<"Enter the number of rows and columns for the first matrix: ";
				cin>>rowA>>colA;
			}

			 //Matrix B inputs
			cout<<"Enter the number of rows and columns (maximum 10) for the second matrix: ";
			cin>>rowB>>colB;
			while(rowB>10 || colB>10)
			{
				cout<<"invalid size. maximum size must be  10."<<endl;
				cout<<"Enter the number of rows and columns for the first matrix: ";
				cin>>rowB>>colB;
			}
			if(colA == rowB){
        		dataentry(matrixA, matrixB, rowA, colA, rowB, colB);
				//matrix Multiplying
				for(int i = 0; i<rowA; i++){
					for(int j = 0; j<colB; j++){
						matrixC[i][j] = 0;
							for(int k = 0; k<colA; k++)
					 		    matrixC[i][j] += matrixA[i][k]*matrixB[k][j];
					}
				}
				cout<<"Answer Matrix: "<<endl;
				for(int i = 0; i<rowA; i++){
					for(int j =0; j<colB; j++){
						cout<<matrixC[i][j]<<" ";
					}
					cout<<endl;
				}
			}
			else
				cout<<"Matrix Multiplication is only possible if columns of 1st matrix are equal to the rows of 2nd matrix"<<endl;
	       	break;
		case 4:
			cout<<"\n----------------=Matrix Transpose=-----------------\n";
			cout<<"Enter the number of rows and columns (maximum 10) for the matrix: ";
			cin>>rowA>>colA;
			while(rowA>10 || colA>10)
			{
				cout<<"invalid size. maximum size must be  10."<<endl;
				cout<<"Enter the number of rows and columns for the matrix: ";
				cin>>rowA>>colA;
			}
			cout<<"enter the elements of first matrix:"<<endl;
			for(int i=0; i<rowA; i++)
			{
				for (int j=0; j<colA; j++)
				{
					cin>>matrixA[i][j];
				}
			}
			for(int i = 0; i<rowA; i++){
				for(int j = 0; j<colA; j++)
				matrixC[j][i] = matrixA[i][j];
			}
			cout<<"Answer Matrix: "<<endl;
			for(int i = 0; i<colA; i++){
				for(int j =0; j<rowA; j++){
					cout<<matrixC[i][j]<<" ";
				}
				cout<<endl;
			}
	       	break;
		case 5:
			 return;
		default:
			cout<<"Invalid operation!"<<endl;
	   }
 	}while(operation != 5);
}
void guessno(){
	int randomnum;
	int guess;

	srand(time(0));
	randomnum = rand()%(100-1+1)+1;

	cout<<"guess a number (1-100): "<<endl;
	cin>>guess;

	do
	{
		if(guess>randomnum)
		{
			cout<<"Too high! Try again!"<<endl;
			cin>>guess;
		}
		else
		{
			cout<<"Too low! try again!"<<endl;
			cin>>guess;
		}
	}
	while(guess!=randomnum);

	cout<<"you've guessed the right number!"<<endl;
}
void dataentry(int matrixA[MAX][MAX],int matrixB[MAX][MAX], int rowA,int colA,int rowB,int colB){
	cout<<"enter the elements of first matrix:"<<endl;
	for(int i=0; i<rowA; i++)
	{
		for (int j=0; j<colA; j++)
		{
			cin>>matrixA[i][j];
		}
	}

	cout<<"enter the elements of second matrix:"<<endl;
	for(int i=0; i<rowB; i++)
	{
		for (int j=0; j<colB; j++)
		{
			cin>>matrixB[i][j];
		}
	}
}