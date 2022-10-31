#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct queue
{
    struct Node
    {
        Node * prev;
        int info;
    };
    Node * start, * end, * mid;
    int size;
    queue()
    {
        start = end = mid = NULL;
        size = 0;
    }
    void push(int a)
    {
        if(size == 0)
        {
            start = end = mid = new Node;
            start->info = a;
            start->prev = NULL;
        }
        else
        {
            Node * buffer = new Node;
            start->prev = buffer;
            buffer->prev = NULL;
            start = start->prev;
            start->info = a;
            if(size % 2 == 0)
                mid = mid->prev;
        }
        size++;
    }
    void vip_push(int a)
    {
        if(size == 0)
            push(a);
        else
        {
            Node * buffer = new Node;
            buffer->info = a;
            buffer->prev = mid->prev;
            mid->prev = buffer;
            if(size % 2 == 0)
                mid = mid->prev;
            size++;
        }
    }
    int pop()
    {
        Node * buffer = end;
        end = end->prev;
        int buffer_info = buffer->info;
        if(size % 2 == 0)
            mid = mid->prev;
        delete buffer;
        size--;
        return buffer_info;
    }
};
int main()
{
    int n, buffer1;
    char buffer;
    cin >> n;
    queue a;
    for(int i = 0; i < n; i++)
    {
        cin >> buffer;
        if(buffer == '-')
            cout << a.pop() << endl;
        else if(buffer == '*')
        {
            cin >> buffer1;
            a.vip_push(buffer1);
        }
        else if(buffer == '+')
        {
            cin >> buffer1;
            a.push(buffer1);
        }
    }
    return 0;
}