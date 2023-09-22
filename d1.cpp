/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 //{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //struct ListNode *head=NULL;
        //ListNode* dummy = new ListNode();
        ListNode* dummy = new ListNode(0); // Dummy node to simplify the logic
        ListNode* curr = dummy;
        int r=0,n1=0,n2=0,temp=0;
        vector <int> v1,v2,v3;
        while(l1!=NULL){
            n1=l1->val;
             v1.push_back(n1);
             l1=l1->next;
        }   
        while(l2!=NULL){
            n1=l2->val;
            v2.push_back(n1);
            l2=l2->next;
        }
        int len1=v1.size(),len2=v2.size();
        if(len2>len1){
            while(len2>0){
                   while(len1>0){
                       temp= v1[len1-1]+v2[len2-1];
                       if(temp>9){
                           temp=temp-10;
                           v3.push_back(temp);
                           v2[len2-2]=v2[len2-2]+1;
                           

                       }else v3.push_back(temp);
                       len1--;
                       len2--;
                   }
                   v3.push_back(v2[len2-1]);
                   len2--;
            }
            }else{
            while(len1>0){
                   while(len2>0){
                       temp= v1[len1-1]+v2[len2-1];
                       if(temp>9){
                           temp=temp-10;
                           v3.push_back(temp);
                           v2[len1-2]=v2[len1-2]+1;
                           

                       }else v3.push_back(temp);
                       len1--;
                       len2--;
                   }
                   v3.push_back(v2[len1-1]);
                   len1--;                
            }
            }

            int i=0,l=v3.size();
            while(i<l){
            ListNode* newNode = new ListNode(v3[i]);
            curr->next = newNode;
            curr = curr->next;
                // ListNode *p=new ListNode(v3[i]);
                // p->next=NULL;
                // if(l1==NULL) l1=p;
                // else{
                //     p->next=l1;
                //     l1=p;
                // }
                i++;
            }
        
        return l1;
    }
};


int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        ListNode* newNode = new ListNode(v3[i]);
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        List
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 