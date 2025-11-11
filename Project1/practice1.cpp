//#include<iostream>
//#include<sstream>
//#include<string>
//using namespace std;
//int main() {
//
//	string input;
//	cout << "enter a string";
//	getline(cin, input);
//	stringstream ss(input);
//	string word;
//	cout << "The words in the string are:\n";
//	while (ss >> word) {
//		cout << word << endl;
//	}
//	return 0;
//}

//
//int main() {
//
//	string input;
//	cout << "Enter comma spreaded words";
//	getline(cin, input);
//	stringstream ss(input);
//	string token;
//
//	cout << "Token:\n";
//	while (getline(ss,token,';')) {
//		cout << token << endl;
//
//
//	}
//	return 0;
//
//
//
//}

//
//bool isNumber(const string& s) {
//    for (char c : s) {
//        if (!isdigit(c)) return false;
//    }
//    return true;
//}
//
//int main() {
//    string input;
//    cout << "Enter a sentence: ";
//    getline(cin, input);
//
//    stringstream ss(input);
//    string token;
//    int totalFruits = 0;
//
//    while (ss >> token) {
//        if (ispunct(token.back())) {
//            token.pop_back();
//        }
//
//        if (isNumber(token)) {
//            totalFruits += stoi(token);
//        }
//    }
//
//    cout << "Total number of fruits: " << totalFruits << endl;
//
//    return 0;
//}

//int main() {
//	string mystring;
//	cout << "Please enter a string";
//	getline(cin, mystring);
//
//    char* pmystring = const_cast<char*>( mystring.c_str());
//	char* token;
//
//	token = strtok_s(pmystring, ";", &pmystring);
//	while (token) {
//
//		cout << token << endl;
//		token = strtok_s(pmystring, ";", &pmystring);
//	}
//	return 0;
//}

//int main() {
//
//	string MyString;
//	cout << "Please input a string";
//	getline(cin, MyString);
//	char* pMystring = const_cast<char*> (MyString.c_str());
//	char* token;
//	token = strtok_s(pMystring, " ", &pMystring);
//	while (token) {
//		cout << token << endl;
//		token = strtok_s(pMystring, " ", &pMystring);
//	}
//	return 0;
//}

//int main() {
//	string MyString;
//	cout << "please enter an input";
//	getline(cin, MyString);
//	char* pMyString = const_cast<char*>(MyString.c_str());
//	char* token;
//	token = strtok_s(pMyString, " ", &pMyString);
//	while (token) {
//		cout << token << endl;
//		token = strtok_s(pMyString, " ", &pMyString);
//	}
//	return 0;
//}

//#include <iostream>
////#include <sstream>
//#include <string>
//using namespace std;
//
//int main() {
//    string input;
//    cout << "Enter your sentence (use ';' to separate): ";
//    getline(cin, input);  // Example input: "2 bananas; 3 oranges; 5 apples"
//
//    stringstream ss(input);
//    string part;
//    int totalFruits = 0;
//
//    while (getline(ss, part, ';')) {
//        stringstream partStream(part);
//        string word;
//        while (partStream >> word) {
//            if (isdigit(word[0])) {
//                totalFruits += stoi(word);
//                break;
//            }
//        }
//    }
//
//    cout << "Total number of fruits: " << totalFruits << endl;
//    return 0;
//}

//
//int main() {
//    string input;
//    cout << "Enter your sentence (use ';' to separate): ";
//    getline(cin, input);  // Example input: "2 bananas; 3 oranges; 5 apples"
//
//    stringstream ss(input);
//    string part;
//    int totalFruits = 0;
//
//    while (getline(ss, part, ';')) {
//        stringstream partStream(part);
//        string word;
//        while (partStream >> word) {
//            if (isdigit(word[0])) {
//                totalFruits += stoi(word);
//                break;
//            }
//        }
//    }
//
//    cout << "Total number of fruits: " << totalFruits << endl;
//    return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main() {
//
//	int x = 10;
//	int y = 20;
//	int* a = &x;
//	int* b = &y;
//
//	swap(*a, *b);
//	cout << "x=" << x << "\ny=" << y << endl;
//
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    const int n=10;
// /*   cin >> n;*/
//    int arr[n];
//
//
//    for (int i = 0; i < n; ++i) {
//        cin >> arr[i];
//    }
//
//    for (int i = n - 1; i >= 0; --i) {
//        cout << arr[i];
//        if (i != 0) {
//            cout << " ";
//        }
//    }
//
//    return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main() {
//	vector<int> v;
//	cout << "PLease enter 10 values";
//	int n;
//	for (int i = 0;i<10; i++){
//		cin >> n;
//		v.push_back(n);
//	}
//	sort(v.begin(),v.end(), greater<int>());
//	for (int i : v) {
//		cout << i << " ";
//	}
//	
// }
//

//#include<iostream>
//#include<list>
//#include<string>
//using namespace std;
//int main() {
//	list<int>mylist;
//	cout << "please enter 10 values";
//	
//	int n;
//	for (int i = 0; i < 10; i++) {
//		cin >> n;
//		mylist.push_back(n);
//	}
//	for (int val : mylist) {
//		cout << val;
//	}
//	return 0;
//}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n, q;
//    cout << "Enter no of arrays and queries" << endl;
//    cin >> n >> q;
//
//    vector<vector<int>> arrays(n);
//
//    for (int i = 0; i < n; ++i) {
//        int k;
//        cout << "Enter array size" << endl;
//        cin >> k;
//
//        arrays[i].resize(k);
//        for (int j = 0; j < k; ++j) {
//            cout << "enter array elements" << i <<" "<< j << endl;
//            cin >> arrays[i][j];
//        }
//    }
//
//    for (int q_idx = 0; q_idx < q; ++q_idx) {
//        int i, j;
//        cout << "Enter ith and jth elemet to print" << endl;
//        cin >> i >> j;
//        cout << arrays[i][j] << endl;
//    }
//
//    return 0;
//}
//

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//void ConvertToBinary(int n)
//{
//	vector<int>v;
//	if (n == 0) {
//		cout << "0" << endl;
//	}
//	int remainder;
//	while (n > 0)
//	{
//		remainder = n % 2;
//		v.push_back(remainder);
//		n = n / 2;
//		if (n == 1) {
//			v.push_back(n);
//			break;
//		}
//	}
//	reverse(v.begin(), v.end());
//	for (int i : v) cout << i;
//}
//
//int main() {
//	int n;
//	cout << "Enter a number" << endl;
//	cin >> n;
//	ConvertToBinary(n);
//	return 0;
//}

//#include<vector>
//#include<iostream>
//#include<string>
//using namespace std;
//void ConvertToBinary(int n) {
//	vector<int>v;
//	if (n == 0) {
//		cout << "0";
//	}
//	while (n > 0) {
//		int remainder;
//		remainder = n % 2;
//		v.push_back(remainder);
//		n = n / 2;
//		if (n == 1) {
//			v.push_back(n);
//			break;
//		}
//	}
//	reverse(v.begin(), v.end());
//	for (int i : v) cout << i;
//}
//
//int main() {
//	int n;
//	cout << "Please enter a number for conversion" << endl;
//	cin >> n;
//	ConvertToBinary(n);
//	return 0;
//
//}

//
//#include<iostream>
//#include<string>
//using namespace std;

//int factorial(int n) {
//
//
//
//}
//int main() 
//{
//	int n;
//	cout << "Please enter a number";
//	cin >> n;
//	int fact = n;
//	for (int i = n - 1; i > 0; i--)
//	{
//		fact = fact * i;
//		
//	}
//	cout << fact;
//}

//int main() {
//	int n;
//	cout << "Please enter a number";
//	cin >> n;
//	int fact = 1;
//	for (int i = 1; i<=n; i++) {
//		fact = fact * i;
//	}
//
//	cout << fact;
//}
//
//while (true) {
//
//
//};
//
//#include<iostream>
//#include<string>
//using namespace std;

//int MyRecursive(int n) {
//	static int i = 0;
//	i++;
//	cout << i << endl;
//	if (i == n) {
//		return 0;
//	}
//	MyRecursive(n);
//	
//}

//int MyRecursive(int n, int j) {
//	int i = j;
//	i++;
//	j = i;
//	cout << j << endl;
//	if (j == n) {
//		return 0;
//	}
//	MyRecursive(n, j);
//	
//}

//int MyRecursive(int n) {
//	static int i = 0;
//	i++;
//	cout << i << endl;
//	if (i == n) {
//		return 0;
//	}
//	MyRecursive(n);
//
//
//}

//int MyRecursive(int n, int j) {
//	int i = j;
//	i++;
//	j = i;
//	cout << j << endl;
//	if (j == n) {
//		return 0;
//	}
//	MyRecursive(n, j);
//
//}
//
//int main() {
//	int n;
//	cout << "Enter";
//	cin >> n;
//	MyRecursive(n,0);
//}
//

//swapping two arrays:
// 
//#include<iostream>
//#include<string>
//#include<utility>
//using namespace std;
//int main() {
//	int a[] = { 1,2,3,4 };
//	int b[] = { 5,6,7,8 };
//	int n = sizeof(a) / sizeof(a[0]);
//
//	swap(a, b);
//	cout << "a[] = ";
//	for (int i = 0; i < n; i++) {
//		cout << a[i] << ",";
//	}
//
//	cout << "b[]= ";
//	for (int i = 0; i < n; i++) {
//		cout << b[i] <<  ",";
//	}
//	return 0;
//}
//
//#include<iostream>
//#include<utility>
//using namespace std;
//
//int main() {
//	int a[] = {1,2,3,4,5};
//	int b[] = {2,3,4,5,8};
//	int n = sizeof(a)/sizeof(a[0]);
//	int m = sizeof(b) / sizeof(b[0]);
//	if (m == n)
//	{
//		swap(a, b);
//	}
//	else { cout << "error"; }
//	
//	cout << "a[]= ";
//	for (int i = 0; i < n; i++) {
//		cout << a[i] << ",";
//	}
//	cout << " b[]= ";
//	for (int i = 0; i < m; i++) {
//		cout << b[i] << ",";
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//void SortString(string& str) {
//	sort(str.begin(), str.end());
//		cout << str;
//}
//int main() {
//
//	string str;
//	cout << "Please enter a string";
//	cin >> str;
//	SortString(str);
//	return 0;
//}
//

//no. of unique characters in an array
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main() {
//	string str;
//	cout << "Please enter a string";
//	cin >> str;
//	cout << "The length of the sting is: " << str.length() << endl;
//}

//Mximum and minimum number from array 
//#include<iostream>
//using namespace std;
//int main() {
//	int n;
//	cout << "Enter number of elements: ";
//	cin >> n;
//
//	int arr[100];
//	cout << "Enter " << n << " elements:\n";
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//
//	int max = arr[0];
//	int min = arr[0];
//
//	for (int i = 0; i < n; i++) {
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//		else if (arr[i] < min)
//		{
//			min = arr[i];
//		}
//	}
//	cout << "Maximum element is:" << max;
//	cout << "\nMinimum element is: " << min;
//
//	return 0;
//}

//Greatest Number from the given array of digits
//#include <iostream>
//#include <algorithm> 
//    using namespace std;
//
//    int main() {
//        int n;
//        cout << "Enter the no. of elements: ";
//        cin >> n;
//
//        int arr[100];
//        cout << "Enter " << n << " elements:\n";
//        for (int i = 0; i < n; i++) {
//            cin >> arr[i];
//        }
//        sort(arr, arr + n, greater<int>());
//        for (int i = 0; i < n; i++) {
//            cout << arr[i] <<"";
//        }
//        return 0;
//    }

//Find first digit of each input number and also map it and tjhe find the greatest number
//#include<iostream>
//#include<algorithm>
//#include<map>
//using namespace std;
//
//int GetFirstDigit(int n) {
//	if (n < 10) {
//		return n;
//	}
//    int FDigit=0;
//	int quotient = n / 10;
//	while (quotient >= 10) {
//		quotient = quotient / 10;
//		FDigit=quotient;
//	}
//	if (quotient < 10) {
//		FDigit=quotient;
//	}
//	return FDigit;
//}
//int main() {
//	int n;
//	cout << "Enter the no. of elements: ";
//	cin >> n;
//	int arr[100];
//	cout << "Enter " << n << " elements:\n";
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	map<int,int,greater<int>> digitarray;
//	for (int i = 0; i < n; i++)
//	{
//		//cout << GetFirstDigit(arr[i]) << endl;
//		int digit = GetFirstDigit(arr[i]);
//		digitarray[digit] = arr[i];
//	}
//	cout << "Digit and the array mapped to it\n";
//	for (const auto& pair : digitarray) {
//		//cout << pair.first << " : " << pair.second << endl;
//		cout << pair.second;
//	}
//	return 0;
//}

//You are given a permutation with length 
//You will choose a subarray
//from the permutation.Then, ask Bob to find the maximum element in the rest of the numbers.
//You are given a permutation
//contains all numbers
//to
//.And, in
//queries, each query has two integers
//and
//
//For each query, you have to help Bob find the maximum value that does not exist in the subarray
//.*/

//#include <iostream>
//#include <vector>
//using namespace std;
//int main() {
//    int n, q;
//    cout << "Enter number of elements (n) and number of queries (q): ";
//    cin >> n >> q;
//    vector<int> a(n);
//    cout << "Enter the elements of the permutation:\n";
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    for (int i = 0; i < q; i++) {
//        int l, r;
//        cout << "Enter query ";
//        cin >> l >> r;
//        l--; r--;  
//
//        int max_val = 0;
//
//       
//        for (int j = 0; j < l; j++) {
//            if (a[j] > max_val)
//                max_val = a[j];
//        }
//
//       
//        for (int j = r + 1; j < n; j++) {
//            if (a[j] > max_val)
//                max_val = a[j];
//        }
//
//        cout << "Maximum value  " << max_val << "\n";
//    }
//
//    return 0;
//}
//rotate the array by d positions to the left sid
////#include <bits/stdc++.h>
//#include<vector>
//#include<iostream>
//using namespace std;
//
//// Function to left rotate array by d positions
//void rotateArr(vector<int>& arr, int d) {
//    int n = arr.size(); //no. of elements stored in the array
//    for (int i = 0; i < d; i++) { //repeates the roatation d times;
//        int first = arr[0]; //saveing the first element
//        for (int j = 0; j < n - 1; j++) {
//            arr[j] = arr[j + 1];
//        }
//        arr[n - 1] = first;//places the first saved element in the end
//    }
//}
//int main() {
//    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
//    int d = 2;
//    rotateArr(arr, d);
//    for (int i = 0; i < arr.size(); i++)
//        cout << arr[i] << " ";
//    return 0;
//}
//ouse Robber - Maximum possible stolen value
//Last Updated : 01 Oct, 2024
//There are n houses built in a line, each of which contains some money in it.A robber wants to steal money from these houses, but h
//e can�t steal from two adjacent houses.The task is to find the maximum amount of money which can be stolen.
//approach- the problem state ment is asking the following:
//1
// Given an unsorted array arr[] of distinct integers, construct another array countSmaller[] such that countSmaller[i] contains the count of smaller elements on the right side of each element arr[i] in the array.
// 
//Examples:
//Input:   arr[] = { 12, 1, 2, 3, 0, 11, 4 }
//Output:  countSmaller[] = { 6, 1, 1, 1, 0, 1, 0 }
//steps are as follows 
// 1. Take elements in an array as input
// 2. Make another array where we will store the values of the smaller variables
// 3. now take the first element of the original array and compare it with the rest of the elemets of the array;
// if a[i]>a[i+1] then we store the element in the vector. we continuew this till the end of the array
//when one iteration id done , we go to the next elemet and do the smae comparisons.
//when alll the iterations are done and we need to iterate the vctor where we stored everything and push in the values.
// 
//#include<iostream>
//#include<vector>
//using namespace std;
//int main() {
//    int n;
//    cout << "Enter the number of elements:\n";
//    cin >> n;
//    int arr[100];
//    cout << "Enter the elements:\n";
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//    vector<int> CountSmaller;
//
//    for (int i = 0; i < n; i++) {
//        int count = 0;
//        for (int j = i + 1; j < n; j++) {
//            if (arr[j] < arr[i]) {
//                count++;
//            }
//        }
//        CountSmaller.push_back(count);
//    }
//    for (int i : CountSmaller) {
//        cout << i << " ";
//    }
//
//    return 0;
//}
//
////DreamGrid recently went on a shopping spree for luxury items at an exclusive boutique. In this boutique, there were 
//distinct items to choose from.DreamGrid, known for his ample wealth, employed an interesting shopping strategy :
//He meticulously inspected all
//items in the store, starting from the
//item and ending with the
//item.
//Whenever he checked an item, he only made a purchase if he had enough funds to cover its price.If his available funds were sufficient, he bought the item and subtracted its cost from his total wealth.
//If, at any point, his remaining funds were insufficient to buy the item being considered, he would simply skip that particular item.
//Your task is to determine the maximum possible amount of wealth DreamGrid had at the beginning such that he can acquire some of these luxury items.You are provided with the prices of the
//items and the total number of items DreamGrid ultimately purchased(indicated as
//).
//Your objective is to find out DreamGrid's maximum wealth that DreamGrid has before this extravagant shopping spree such that he can purchase 
//luxury items, which will be a non - negative whole number.

//Steps for the algorithm
//1.INPOUT THE NUMBER OF ITEMS
//Inout the prices for each items and the no. of items (m) which he purchased

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main() {
//
//	string str1 = "hella";
//	string str2 = "hello";
//	if (str1 < str2) {
//		cout << "1st is samller than second";
//	}
//	
//	else cout << "Greater";
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//
//    // This is an infinite for loop as the condition
//    // expression is blank
//    for (;;) {
//        cout << "This loop will run forever.\n";
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//int Factorial(int n) {
//	if (n == 0 || n == 1) {
//		return 1;
//	}
//	else
//		return n * Factorial(n - 1);
//}
//
//int main() {
//
//	int n;
//	cout << "Pleas eneter a number:";
//	cin >> n;
//	cout << "Factorial is:" << Factorial(n) << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main() {
//	int n;
//	cout << "Enter n;";
//	cin >> n;
//	int space = n;
//	for (int i = 0; i < n; i++) 
//	{
//		for (int space = n; space > i; space--){
//			cout << " ";
//		}
//
//		for (int j = 0; j <= i; j++) {
//			cout << "*";
//		}
//		cout << endl;
//	}
//
//}

#include <stdio.h>
#include <stdlib.h>

// Function to sort processes based on Arrival Time (AT)
void sort(int at[], int bt[], int process[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp;

                // Swap arrival times
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process numbers
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], wt[n], tat[n], st[n], process[n];
    float awt = 0.0, avgtat = 0.0;

    // Input section
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter arrival time for P%d: ", process[i]);
        scanf("%d", &at[i]);
        printf("Enter burst time for P%d: ", process[i]);
        scanf("%d", &bt[i]);
    }

    // Sort processes by arrival time
    sort(at, bt, process, n);

    // First process
    st[0] = at[0];
    ct[0] = st[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];
    awt += wt[0];
    avgtat += tat[0];

    // Remaining processes
    for (int i = 1; i < n; i++) {
        if (at[i] > ct[i - 1]) {
            st[i] = at[i]; // CPU idle until this process arrives
        } else {
            st[i] = ct[i - 1]; // starts immediately after previous one
        }
        ct[i] = st[i] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        awt += wt[i];
        avgtat += tat[i];
    }

    // Calculate averages
    awt /= n;
    avgtat /= n;

    // Print results in a clean table format
    printf("\n\n-------------------------------------------------------------\n");
    printf("Process\tAT\tBT\tST\tCT\tWT\tTAT\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               process[i], at[i], bt[i], st[i], ct[i], wt[i], tat[i]);
    }
    printf("-------------------------------------------------------------\n");

    // Display averages
    printf("Average Waiting Time     = %.2f\n", awt);
    printf("Average Turnaround Time  = %.2f\n", avgtat);

    // Gantt chart
    printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) {
        printf("  P%d  |", process[i]);
    }

    printf("\n%d", at[0]);
    for (int i = 0; i < n; i++) {
        printf("     %d", ct[i]);
    }
    printf("\n");

    return 0;
}
