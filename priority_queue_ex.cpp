// Priority queues are used when we want the container to be automatically 
// sorted either in the ascending or descending order. It does it based on the comparator opeartor used.
// By default it uses vectors as containers. But we can use deque or list for that purpose.
// BY default the order of arrangement is decesnding order and it is similar to heaps.
// constructing priority queues
// methods for print queues:
// .top() -> internally it is similar to front() of vector. To peek the top element.
// .pop() -> internally it uses pop_back() of the container.
// .push() -> pushes it uses push_back() the elements into the container from behind
// .size() -> returns the number of elements it is holding.
// .empty() -> to check if the container is empty or not


#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

using namespace std;



void print(int x){
    cout << x << ',';    
}
void print_vector(vector<int> & vec, string msg=""){
    cout << msg;
    // for(int i =0; i<vec.size(); i++)
    // {
    //     cout << vec[i] << ",";
    // }
    // for_each(vec.begin(), vec.end(), print);
    // cout << endl;

    for (const int &s : vec)
    {
        cout << s << ", ";
    }
    cout << endl;
}

// void print_queue(priority_queue<int> &q){


// }

template<typename T> void print_queue(T &q, const string msg=" "){
    cout << msg;
    while(! q.empty()){
        cout << q.top() << ",";
        q.pop();
    }
    cout << endl;
}

class mycomparison
{
    bool reverse;
public:
    mycomparison(const bool& revparam=false)
        {reverse=revparam;}
    bool operator() (const int& lhs, const int&rhs) const
    {
        if (reverse) return (lhs>rhs);
        else return (lhs<rhs);
    }
};

int main ()
{
    int myints[]= {10,60,50,20};
    vector<int> vec(myints, myints+4);
    print_vector(vec, "my vec:");
    // std::priority_queue<int> first;
    // std::priority_queue<int> second (myints,myints+4);
    // std::priority_queue<int, std::vector<int>, std::greater<int> >
    //                         third (myints,myints+4);
    // // using mycomparison:
    // typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;

    // print_vector(second, "sec: ");
    // print_vector(third, "third: ");
    // mypq_type fourth;                       // less-than comparison
    // mypq_type fifth (mycomparison(true));   // greater-than comparison
    {
        priority_queue<int> q1;
        for(int ele:{10,60,50,20}){ q1.push(ele); } // by default this will be sorted in descending order
        print_queue(q1, "q1: ");
    }
    {
        priority_queue<int, vector<int>, greater<int> > q2;
        for(int ele:{10,60,50,20}){ q2.push(ele); }
        print_queue(q2, "q2: ");
    }
    {
        auto cmp =[](int left, int right){ return left < right ; };
        priority_queue<int, vector<int>, decltype(cmp)> q3(cmp);
        for(int ele:{10,60,50,20}){ q3.push(ele); }
        print_queue(q3, "q3: ");

    }

    return 0;
}