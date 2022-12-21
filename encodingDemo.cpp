#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode{
	//input character
	char data;
	//frequency of character
	int freq;
	// right and left child
	MinHeapNode *left,*right;
	MinHeapNode(char data,int freq){
		left=right=NULL;
		this->data=data;
		this->freq=freq;
	}
};

//Comparision for min and max nodes in heap
struct compare{
	bool operator()(MinHeapNode* l,MinHeapNode*r){
		return(l->freq > r->freq);
	}
};
//To Print Codes from tree
//0 for left and 1 for right in the tree
void printCodes(struct MinHeapNode* root, string str)
{

    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
//To build the actual huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;

    // Create a min heap & inserts all characters of data[] using priority queue.
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {

        // Extract the two minimum
        // freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();
  top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }
printCodes(minHeap.top(), "");
}
int main()
{

    char arr[] = { 'i', 'n', 't', 'e', 'g', 'r','a','l' };
    int freq[] = { 5, 9, 12, 13, 16, 45,10,9 };

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
