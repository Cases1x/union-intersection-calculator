#include <iostream>
#include <string>
#include<algorithm>
#include<limits>
#include<cstdlib>
#include<stdlib.h>
using namespace std; 

/*
    Union Intersection Calculator
    Final Project
    Computer Programing 2
    


    BSM CS 1B
    Second Semester
    A.Y. 2022 - 2023

    Members:
    VARGAS, John Francis
    DE JESUS, Carlos JOhn
    DE GUZMAN, Richie Mae
    RODRIGUEZ, Samuel
    
*/
void Welcome();
void Menu();
void Input();
void Header();
void Union(string arrayA[], string arrayB[], int A, int B);
void Intersection(string arrayA[], string arrayB[], int A, int B);
bool Contains(string array[], int length, string value);
void Mode(string arrayA[], string arrayB[], int arrA, int arrB);
void PrintArray(string arrayA[], string arrayB[], int arrA, int arrB);
void PrintUnion(string arrayC[], int C);
void PrintIntersection(string arrayC[], int arrA);

int option = 0;
void Welcome()
{
    Header();
    Menu();
    if(cin.fail())
    {
        cout << "Invalid input. Try Again" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Welcome();
    }
    else
    {
        cin >> option;
    }

    switch(option)
    {
        case 1:
            Input();
            break;
        case 2:
            break;
        default:
            option = 0;
            Welcome();
            break;
    }
}
void Union(string arrayA[], string arrayB[], int arrA, int arrB)
{
    int C = arrA + arrB;
    string arrayUnion[C];
    int x = 0;
    for(int i = 0; i < arrA; i++)
    {
        if(arrayA[i] == arrayA[i+1])
        {
            continue;
        }
        else
        {
            arrayUnion[x] = arrayA[i];
            x++;
        }
    }
    for(int i = 0; i < arrB ; i++)
    {
        string value = arrayB[i];
        bool exists = Contains(arrayUnion, arrA, value);
        if(exists != true)
        {
            if(arrayUnion[x -1] == value)
            {
            }else
            {
                arrayUnion[x] = value;
                x++;
            } 
        }
    }
    PrintArray(arrayA, arrayB, arrA, arrB);
    PrintUnion(arrayUnion, x);
    Mode(arrayA, arrayB, arrA, arrB);
}
void Intersection(string arrayA[], string arrayB[], int arrA, int arrB)
{
    int arrC;
    if(arrA >= arrB)
    {
        arrC = arrB;
    }
    else
    {
        arrC = arrA;
    }
    string arrayIntersection[arrC];
    int x = 0;
    for(int i = 0; i< arrC; i++)
    {
        string value = arrayA[i];
        bool exists = Contains(arrayB, arrB, value);
        if(exists == true)
        {
            if(arrayIntersection[x - 1] == value)
            {    
            }else
            {
                arrayIntersection[x] = value;
                x++;
            } 
        }
    }
    PrintArray(arrayA, arrayB, arrA, arrB);
    PrintIntersection(arrayIntersection, arrC);
    Mode(arrayA, arrayB, arrA, arrB);
}
void PrintArray(string arrayA[], string arrayB[], int arrA, int arrB)
{
    cout << endl;
    cout << "Array 1: {";
    for(int i = 0; i< arrA; i++)
    {
        cout << arrayA[i] << ", ";
    }
    cout << "}" << endl;
    
    cout << "Array 2: {";
    for(int i = 0; i< arrB; i++)
    {
        cout << arrayB[i] << ", ";
    }
    cout << "}" << endl;
}
void PrintUnion(string arrayC[], int C)
{
    cout << "Union: { ";
    for(int i = 0; i< C; i++)
    {
        cout << arrayC[i] << ", ";
    }
    cout << "}" << endl;
}
void PrintIntersection(string arrayC[], int arrC)
{
    cout << "Intersection: { " ;
    for(int i = 0; i< arrC; i++)
    { 
        cout << arrayC[i] << ", ";
    }
    cout << "}" << endl;
}
void Menu()
{
    cout << "1. Start" << endl;
    cout << "2. Exit" << endl;
}
void Mode(string arrayA[], string arrayB[], int arrA, int arrB)
{
    cout << endl;
    cout << "Please choose a mode:" << endl;
    cout << "1. Union" << endl;
    cout << "2. Intersection" << endl;
    cout << "3. Back" << endl;

    cin >> option;
    
    switch (option)
    {
    case 1:
        Union(arrayA, arrayB, arrA, arrB);
        break;
    case 2:
        Intersection(arrayA, arrayB, arrA, arrB);
        break;
    case 3:
        
        Welcome();
        break;
    default:
        option = 0;
        Mode(arrayA, arrayB, arrA, arrB);
        break;
    }
}
void Input()
{
    int arrA, arrB;
    string input;
    cout << "Enter Size of Array 1 (or 'Q' to quit): ";
    cin >> input;
    
    if(input == "Q" )
    {
        Welcome();
    }
    else
    {
        try
        {
           arrA = stoi(input);
        }
        catch (const exception& ex)
        {
            cout << "Invalid Input. Please input an Integer" << endl;
            Input();
        }
    }
    string arrayA[arrA];
    for(int i = 0; i<arrA; i++)
    {
        cout << "Enter Element of Array 1:";
        string input;
        cin >> input;
        arrayA[i] = input; 
    }
    cout << "Enter Size of Array 2: ";
    cin >> input;
    if(input == "Q" )
    {
        Welcome();
    }
    else
    {
        try
        {
           arrB = stoi(input);
        }
        catch (const exception& ex)
        {
            cout << "Invalid Input. Please input an Integer" << endl;
            Input();
        }
    }
    string arrayB[arrB];
    for(int i = 0; i<arrB; i++)
    {
        cout << "Enter Element of Array 2:";
        string input;
        cin >> input;
        arrayB[i] = input; 
    }
    Mode(arrayA, arrayB, arrA, arrB);     
}
bool Contains(string array[], int length, string value) // Checks if an element exists in an array
{
    for(int i = 0; i< length; i++)
    {
        if(array[i] == value) return true; 
    }
    return false;
}
int main() 
{
    Welcome();
}
void Header()
{
    cout << "         Union and Intersection Calculator           " << endl << endl;
}
