#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
using namespace std;

class Person
{
public:
	// default constructor
	Person() : age(0) {}
	Person(int age, string name) {
		this->age = age; this->name = name;
	}

	int age;
	string name;
};

// function object
struct GreaterAge
{
public:
	bool operator()(const Person& a, const Person& b)
	{
		if(a.age == b.age)
			return a.name < b.name;

		return a.age > b.age;
	}
};


// template <class T>
// void Merge(T *a, int p, int q, int r , bool compare(const int& ,const string& ))
// {
// 	int i, j, k;
// 	const int n1 = q-p+1, n2 = r-q;
// 	int L[n1];
// 	int R[n1];

// 	for(i=0;i<n1;i++) L[i] = a[p+i];
// 	for(j=0;j<n2;j++) R[j] = a[q+j+1];
// 	for(k=p,i=j=0;k<=r;k++)
// 	{
// 		if(j>=n2 || (i<n1 && compare(L[i],R[j])))
// 			a[k] = L[i++];
// 		else //L[i]>R[j]
// 		{
// 			a[k] = R[j++];
// 		}
// 	}
// }

// template <class T>
// void Merge_Sort(T *a, int p, int r , bool compare(const T& ,const T& ))
// {
// 	if(p<r)
// 	{
// 		int q = (p+r)/2;
// 		Merge_Sort(a,p,q,compare);
// 		Merge_Sort(a,q+1,r,compare);
// 		Merge(a,p,q,r,compare);
// 	}
// }

class mergeSort {

public:

    template<typename T, typename Comparator> 
    void merge(T *arr, int left, int mid, int right, Comparator compare) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        T L[n1], R[n2]; 
        for(int i = 0; i < n1; i++) L[i] = arr[left + i];
        for(int j = 0; j < n2; j++) R[j] = arr[mid + j + 1];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) { 
            if (compare(L[i], R[j])) { 
                arr[k] = L[i]; 
                i++; 
            } 
            else { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } 
  
        while (i < n1) { 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 
  
        while (j < n2) { 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
    }    

    template<typename T, typename Comparator> 
    void divideAndConquer(T *arr, int left, int right, Comparator compare = new Comparator) {
        if(left < right) {
            int mid = (left + right) / 2;
            divideAndConquer(arr, left, mid, compare);
            divideAndConquer(arr, mid + 1, right, compare);
            merge(arr, left, mid, right, compare);
        }
    }
};
int compare(Person a, Person b) {
    if(a.age == b.age)
			return a.name < b.name;

		return a.age > b.age;
} 
int main()
{
    int arr[1000];

    arr[0]=5;
    arr[1]=4;
    arr[2]=3;
    arr[3]=2;
    arr[4]=1;

    mergeSort sorter;
    sorter.divideAndConquer(arr, 0, 4, less<int>());
    
    for(int i=0;i<5;i++)
		printf("%d\n", arr[i]);

	return 0;
}  