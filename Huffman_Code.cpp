/*
  File: Huffman_Code.cpp
  Author: Yanyan Zhou
  Date: May 2022
  Description: The Huffman coding of file streams is implemented using the priority_queue and the vector in Standard Template Library.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long int ll;
//typedef defines an alias for a data type. In this case, it defines "ll" as an alias for "long long int".

int a, b, root;

//Define a struct to store the information of each node in the Huffman tree.
struct Node {
	ll weight;  //The weight of the node, representing the frequency of the character in the input file.
	int left, right;  //The left and right children of the node.
	int character;  //The character stored in the node, with a value of 0 if the node is not a leaf node.
	Node() :weight(0), character(0) { left = right = -1; }  //Constructor to initialize the node.
	Node(ll _w, int _l, int _r, int _ch) :weight(_w), left(_l), right(_r), character(_ch) {}
};

ll number[550];  //Array to store the frequency of each character's occurrence.
vector<int> schedle[550], code;  //Arrays to store the encoding for each character.
vector<Node> t;  //Vector to store the nodes in the Huffman tree.

//Define a struct to compare the weight of two nodes in the Huffman tree.
struct compare {
	bool operator()(int a, int b)
	{
		return t[a].weight > t[b].weight;
	}
};

//Define a priority queue to store the nodes in the Huffman tree, sorted by their weight.
priority_queue<int, vector<int>, compare> q;

//Function to read the input file and store the frequency of each character's occurrence.
void input()
{
	FILE* fp = freopen("input.txt", "r", stdin);  //Open the input file.
	char x;
	while (scanf(" %c", &x) != EOF)  //Read the input file until the end of the file.
		number[x]++;  //Increment the frequency of the character.
	fclose(fp);  //Close the input file.
}

//Function to build the Huffman tree.
int BuildTree()
{
	for (int i = 1; i <= 500; i++)
	{
		if (number[i])
		{
			sum++;  //Increment the number of characters in the input file.
			t.push_back(Node(number[i], -1, -1, i));  //Add a leaf node to the Huffman tree.
			q.push(t.size() - 1);  //Put the node's index into the priority queue "q".
		}
	}
	while (q.size() > 1)  //While there are more than 1 node
	{
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		//Selecting the two nodes with the highest weight in "q", "a" and "b", and generating a parent node for both.
		t.push_back(Node(t[a].weight + t[b].weight, a, b, 0));
		q.push(t.size() - 1);
	}
	return q.top(); //The top of the priority queue "q" is the index of the root node.
}

//Using a recursive method to encode.
void HuffmanCoding(int index)
{
	int x = t[index].character;
	if (x)
	{
		schedle[x] = code;
		return;
	}
	//Termination condition: if the character is not a leaf node (character=0), exit the loop and record the encoding.

	code.push_back(0);
	HuffmanCoding(t[index].left);//Recursing to the left subtree.
	code.pop_back();
	code.push_back(1);
	HuffmanCoding(t[index].right);//Recursing to the right subtree.
	code.pop_back();
	return;
}

void output()
{
	FILE* fp1 = freopen("input.txt", "r", stdin);
	FILE* fp2 = freopen("output.txt", "w", stdout);
	printf("Character\tValue\tCode\n");
	for (int i = 0; i < 500; i++)
	{
		//output the code
		if (number[i])
		{
			printf("%c\t%lld\t", i, number[i]);
			for (int j = 0; j <= schedle[i].size() - 1; j++)
				cout << schedle[i][j];
			cout << endl;
		}
	}
	char y;
	//output the data after coding
	while (scanf(" %c", &y) != EOF)
	{
		for (int i = 0; i < schedle[y].size(); i++)
			cout << schedle[y][i];
	}
	fclose(fp1);
	fclose(fp2);
}



int main()
{
	t.clear();
	while (!q.empty()) q.pop();
	memset(number, sizeof(number), 0);
	code.clear();
	for (int i = 0; i < 550; i++)
		schedle[i].clear();

	input();
	root = BuildTree();
	HuffmanCoding(root);
	output();

	return 0;
}
