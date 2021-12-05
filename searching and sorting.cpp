code
//DSA Assignment 1 
//4243 PRERNA YADAV
#include<bits/stdc++.h>
using namespace std;
struct student{
        int roll;
        string name;
        float sgpa;
}s;

void swap(student* a, student* b)
{
       student t = *a;
       *a = *b;
       *b = t;
}

//Sorting inputs(roll numbers) in ascending order using Bubble Sort
void BubbleSort(student* s,int n){
       int i,j;
       for(i=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++){
                 if(s[j].roll>s[j+1].roll){
                        swap(s[j],s[j+1]);
                 }
            } 
       }
}

//Sorting inputs(names) alphabetically using Insertion Sort
void InsertionSort(student* s,int n){
       int i,j;
       string key;
       for (i = 1; i < n; i++)
       {
             key = s[i].name;
             student temp= s[i];
             j = i - 1;
             while (j >= 0 and s[j].name > key)
             {
                     s[j + 1] = s[j];
                     j--;
            }
            s[j + 1] = temp;
        }
}

//Sorting inputs(sgpa) in descending order using Quick Sort
int partition(student* s,int low,int high);
void QuickSort(student* s,int low,int high){
        int pivot;
        if(low<high){
        pivot=partition(s,low,high);
        QuickSort(s,low,pivot-1);
        QuickSort(s,pivot+1,high);
        }
}
int partition(student* s,int low,int high){
       int left=low,right=high;
       float pivot_item=s[low].sgpa;
       while(left<right){
               while(s[left].sgpa>=pivot_item){ left++; }
               while(s[right].sgpa<pivot_item){ right--; } 
               if(left<right){
                      swap(s[left],s[right]);
               }
               if(right<=left){
                      swap(s[right],s[low]);
               } 
       }
       return right; 
}

//Linear Search to list out students having same sgpa
void LinearSearch(student* s,int n,float data){
        bool check = true;
        for(int i=0;i<n;i++)
        {
              if(s[i].sgpa==data)
             {
                  cout<<s[i].roll<<" ";
                  cout<<s[i].name<<" ";
                  cout<<s[i].sgpa<<'\n';
                  check = false;
             }
        }
        if(check){
                  cout<<"DATA NOT FOUND..."<<'\n';
        }
}

//Binary Search without Recursion 
void BinarySearch(student* s,int n,string key){
       int low=0;
       int high=n-1;
       while(low<=high){
              int mid=low+(high-low)/2;
              if(s[mid].name==key){
                       cout<<s[mid].roll<<" "<<s[mid].name<<" ";
                       cout<<s[mid].sgpa<<'\n';
                       break;
              }
              else if(s[mid].name<key){
                       low=mid+1;
              }
              else high=mid-1;
        }
        if(low>high) cout<<"DATA NOT FOUND...";
}


void PrintArray(student* s,int n){
      for(int i=0;i<n;i++){
             cout<<s[i].roll<<" "<<s[i].name<<" "<<s[i].sgpa;
             cout<<'\n'; 
      }
}


int main(){
          int n; 
          cout<<"Enter number of students: \n";
          cin>>n; 
          student s[n];
          for(int i=0;i<n;i++){
                  cin>>s[i].roll>> s[i].name>> s[i].sgpa;
          }

          BubbleSort(s,n);
          cout<<"\nAfter Bubble Sort :"<<'\n';
          PrintArray(s,n);
          cout<<'\n';

          InsertionSort(s,n);
          cout<<"\nAfter Insertion Sort :"<<'\n';
          PrintArray(s,n);
          cout<<'\n';

          string key;
       cout<<"\nEnter name in capital which you want to search : ";
          cin>>key;
          cout<<'\n';
          BinarySearch(s,n,key);
          QuickSort(s,0,n-1);
          cout<<"\nTop 10 Students Details : "<<'\n';
         for(int i=0;i<10;i++)
         {
                  cout<<s[i].roll<<" "<<s[i].name<<" ";
                  cout<<s[i].sgpa<<'\n';
         }

         float data;
         cout<<"\nEnter sgpa which you want to search :"<<'\n';
         cin>>data;
         LinearSearch(s,n,data);

         return 0;
}
