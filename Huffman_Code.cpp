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
//Testing revealed that the int data type may result in data overflow, so long long int are used instead.

int a, b, root;
struct Node {
	ll weight;
	int left, right;
	int character;
	Node() :weight(0), character(0) { left = right = -1; }
	Node(ll _w, int _l, int _r, int _ch) :weight(_w), left(_l), right(_r), character(_ch) {}
};

ll number[550], sum = 0;//Record the frequency of each character's occurrence. 
vector<int> schedle[550], code;//Record the encoding for each character
vector<Node> t;//Huffman Tree

struct compare {
	bool operator()(int a, int b)
	{
		return t[a].weight > t[b].weight;
	}
};

priority_queue<int, vector<int>, compare> q;
//The priority queue can sort the elements in the queue, allowing for the merging of nodes to create a parent node.

void input()
{
	FILE* fp = freopen("input.txt", "r", stdin);
	char x;
	while (scanf(" %c", &x) != EOF)
		number[x]++;
	fclose(fp);
}
int BuildTree()
{
	for (int i = 1; i <= 500; i++)
	{
		if (number[i])
		{
			sum++;
			t.push_back(Node(number[i], -1, -1, i));//Adding leaf nodes to the tree.
			q.push(t.size() - 1);
			//Putting the node's index into the priority queue "q" , and the nodes in "q" will be sorted according to the "compare" struct.
		}
	}
	while (q.size() > 1)
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
