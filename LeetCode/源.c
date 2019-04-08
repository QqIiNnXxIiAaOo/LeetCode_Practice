#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
#pragma warning(disable:4996)
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;	
};
struct ListNode {
	int val;
	struct ListNode *next;	
};

//T.169
int majorityElement(int* nums, int numsSize) {
	int result = nums[0], count = 1;
	for (int i = 1; i < numsSize; i++) {
		if (result!=nums[i]) 
			count--;
		else
			count++;
		if (count == 0) {
			result = nums[++i];
			count++;
		}
	}
	return result;
}
//T.204
int countPrimes(int n) {
	int count = 0, x;
	int temp = 0;
	if (n <= 2)
		return 0;
	for (int i = 3; i < n; i++)
	{
		x = 2;
		while (x < i) {
			if (i%x == 0)
				temp++;
			x++;
		}
		if (temp == 0)
			count++;
		temp = 0;
	}
	return count+1;
}
//T.104
int maxDepth(struct TreeNode* root) {
	
	return root == NULL ? 0 : (maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) : maxDepth(root->right)) + 1;

}
//T.125
bool isPalindrome1(char* s) {
	int len = strlen(s);
	int j = 0;
	char* array = (char*)malloc(sizeof(char)*(len + 1));
	for (int i = 0; i < len; i++) {
		if (isalnum(s[i])) {
			array[j] = tolower(s[i]);
			j++;
		}
	}
	array[j] = '\0';
	len = strlen(array);	
	for (int i = 0; i < len / 2; i++) {
		if (array[i] != array[len - i - 1])
			return false;
	}
	return true;
}
//T.231
bool isPowerOfTwo(int n) {
	while (n)
	{
		if (n == 2 || n == 1)
			return true;
		if (n % 2 == 1)
			return false;
		n = n / 2;
	}
	return false;
}
//T.258
int addDigits(int num) {
	int sum = 0;
	if (num > 9) {
		while (num !=0)
		{
			sum = num % 10 + sum;
			num = num / 10;
		}
		return addDigits(sum);
	}
	else
		return num;		
}
//T.344
void reverseString(char* s, int sSize) {
	char temp;
	for (int i = 0; i < sSize/2; i++)
	{
		temp = *(s + i);
		*(s + i) = *(s + sSize - i - 1);
		*(s + sSize - i - 1) = temp;
	}
}
//T.171
int titleToNumber(char* s) {
	int long sum = 0;
	int length = strlen(s); 
	for (int i = 0; i < length; i++)
	{
		sum = sum * 26 + s[i] - 64;
	}
	return sum;
}
//T.206
struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
	L->next = NULL;
	while (head!=NULL)
	{
		struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
		s->val = head->val;
		s->next = L->next;
		L->next = s;
		head = head->next;
	}
	return L->next;
}
//T.168
char* convertToTitle(int n) {
	int temp[100];
	int i = 0;
	while (n!=0)
	{
		temp[i++] = n % 26;
		n = n / 26;
	}
	temp[i] = '\0';
	int k;
	char* array = (char*)malloc(sizeof(char)*(i + 1));
	for (k = 0; k < i; k++)
		array[k] = temp[i - k - 1] + 'A';
	array[k] = '\0';
	return array;
}
//189.Time out
void rotate(int* nums, int numsSize, int k) {
	int temp;
	for (int j = 0; j < k; j++)
	{	
		int i;
		temp = nums[numsSize - 1];
		for ( i = 0; i < numsSize-1; i++)
		{			
			nums[numsSize - i-1] = nums[numsSize - i - 2];
		}
		nums[0] = temp;
	}	
}
//T.110
bool isBalanced(struct TreeNode* root) {
	if (root==NULL)
	{
		return true;
	}
	int right = binaryTreeDeep(root->right);
	int left = binaryTreeDeep(root->left);
	if (right - left > 1 || right - left < -1)
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}
int binaryTreeDeep(struct TreeNode* root) {
	if (root==NULL)
	{
		return 0;
	}
	else {
		int right = binaryTreeDeep(root->right);
		int left = binaryTreeDeep(root->left);
		return 1 + (left > right ? left : right);
	}
}
//T.292
bool canWinNim(int n) {
	if (n < 4)
		return true;
	else if (n / 4 == 0)
		return false;
	else
		return true;
}
int main() {

	getchar();
}