#include<stdio.h>

template<typename F, typename S> 
class pair {   
public:
    F first;
    S second;

    pair() {}
    pair(F __first, S __second) {
        first = __first;
        second = __second;
    }

    bool operator < (const pair &other) const {
        if(first < other.first) return first < other.first;
        return second < other.second;
    }   

};

namespace utility {
  
    template<typename T>
    class less {
    public:
        bool operator() (const T &first, const T &second) const {
            return first < second;
        }  
    };

    template<typename T>
    class greater {
    public:
        bool operator() (const T &first, const T &second) const {
            return first > second;
        }  

    };
    
    template<typename F, typename S>   
    pair<F,S> make_pair(F x, S y) {
        return pair<F, S>(x, y);
    }

    template<typename T>
    T min(T x, T y) {
        if(x < y) return x;
        return y;
    }

    template<typename T>
    T max(T x, T y) {
        if(x > y) return x;
        return y;
    }
    
};


template<typename T, typename Comparator>
class Heap {

    int size, capacity;
    T *storeNodes;
    Comparator compare = Comparator();    
    void doubleTheCapacity() {
        capacity = capacity * 2;
        T *tempNodes = new T[capacity];
        for(int i = 0; i < size; i++) {
            tempNodes[i] = storeNodes[i];
        }
        storeNodes = tempNodes;
    }

    void swapNodes(int first, int second) {
        T temp = storeNodes[first];
        storeNodes[first] = storeNodes[second];
        storeNodes[second] = temp;
    }

    void pushUp() {
        int curIndex = size - 1;
        while(curIndex > 0 && compare(storeNodes[curIndex], storeNodes[(curIndex - 1) / 2])) {
            swapNodes(curIndex, (curIndex - 1) / 2);
            curIndex = (curIndex - 1) / 2;
        }
    }

    void pushDown() {
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while(leftChildIndex < size) {
            int greaterChildIndex = leftChildIndex;
            if(rightChildIndex < size && compare(storeNodes[rightChildIndex], storeNodes[leftChildIndex])) {
                greaterChildIndex = rightChildIndex;
            }
            if(compare(storeNodes[greaterChildIndex], storeNodes[parentIndex])) {
                swapNodes(greaterChildIndex, parentIndex);
                parentIndex = greaterChildIndex;
                leftChildIndex = 2 * parentIndex + 1;
                rightChildIndex = 2 * parentIndex + 2;
            } else {
                break;
            }
            
        }
    }

public:

   Heap() {
       size = 0; 
       capacity = 1;
   }

    void push(T val) {
        if(size == capacity - 1) {
            doubleTheCapacity();
        }
        storeNodes[size++] = val;
        pushUp();
    }
    
    T pop() {

        if(size == 0) {
            printf("there is no element to pop\n");
        }
        T topElement = storeNodes[0];
        storeNodes[0] = storeNodes[size - 1];
        size = size - 1; pushDown();    
        return topElement;
    }

    T top() {
        if(size == 0) {
            printf("there is no element\n");
        }
        return storeNodes[0];
    }

    void clear() {
        delete storeNodes;
    }
};

using namespace utility;
int main() {

    Heap<int, greater<int>> heap;
    heap.push(1);
    heap.push(10);
    printf("%d\n", heap.top());
    return 0;
}