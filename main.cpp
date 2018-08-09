#include <QCoreApplication>
//#include <stdio.h>
//#include <stdlib.h>
//#include <opencv2/opencv.hpp>
#include <iostream>
#include <csignal>
#include "astar.h"
using namespace std;


int main()
{
    std::vector< std::vector<int> > maze=
    {   {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,1,1,0,1,0,0,0,0,1},
        {1,0,0,1,1,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,1,1,1},
        {1,1,1,0,0,0,0,0,1,1,0,1},
        {1,1,0,1,0,0,0,0,0,0,0,1},
        {1,0,1,0,0,0,0,1,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1}};
    Astar astar;
    astar.InitAstar(maze);
    Point start(1,1);
    Point end(6,10);
    list<Point *> path = astar.GetPath(start, end, false);
    for(auto &p:path)
        cout << "<" << p->x << "," << p->y << ">" << endl;
    system("pause");
    return 0;
}
/*
void signalHandler(int signum)
{
    cout << "Interrupt signal (" << signum << ") received." << endl;
    exit(signum);
}

int main()
{
    signal(SIGINT, signalHandler);
    while(1)
    {
        cout << "Going to sleep..." << endl;
//        sleep(1);
    }
    return 0;
}
*/
//int main()
//{
//    cv::Mat temp1;
//    temp1 = cv::imread("home/liu/program/automapbuild/src/automapbuild/image/origin0.png", 1);
//    std::cout << "temp1.empty() " << temp1.empty() << std::endl;
//    return 0;
//}
/*void ShortestPath_DIJ()
{
    for(v = 0; v < n; v++)
    {
        final[v] = 0;
        D[v] = arcs[v0][v];
        for(w = 0; w < n; w++)
            p[v][w] = 0;
        if(D[v] < MAX)
        {
            p[v][v0] = 1;
            p[v][v] = 1;
        }
    }
    D[v0] = 0;
    final[v0] = 0;
    for(int i = 1; i < n; i++)
    {
        int min = MAX;
        for(w = 0;w < n; w++)
        {
            if(!final[w])
            {
                if(D[w] < min)
                {
                    v = w;
                    min = D[w];
                }
            }
        }
        final[v] = 1;
        for(w = 0; w < n; w++)
        {
            if(!final[w] && (min+arcs[v][w]) < D[w])
            {
                D[w] = min + arcs[v][w];
                p[w][w] = 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arcs[i][j];
        }

    }
    ShortestPath_DIJ();
    for(int i = 0; i < n; i++)
        cout << i << " " << D[i];
    return 0;
}
*/
/*void test_empty()
{
    queue<int> myqueue;
    int sum(0);
    for(int i=1; i <= 10; i++) myqueue.push(i);
    while(!myqueue.empty())
    {
        sum += myqueue.front();
        myqueue.pop();
    }
    cout << "total:" << sum << endl;
}

void test_pop()
{
    queue<int> myqueue;
    int myint;
    cout << "\nPlease enter some integers (enter 0 to end):\n" << endl;
    do
    {
        cin >> myint;
        myqueue.push(myint);
    }while(myint);

    cout << "myqueue contains:";
    while(!myqueue.empty())
    {
        cout << " " << myqueue.front();
        myqueue.pop();
    }
}

void test_size()
{
    queue<int> myints;
    cout << "0.size:" << (int)myints.size() << endl;
    for(int i=0; i<5; i++) myints.push(i);
    cout << "1.size:" << (int)myints.size() << endl;
    myints.pop();
    cout << "2.size:" << (int)myints.size() << endl;
}

int main()
{
    test_empty();
    cout << endl;
    test_pop();
    cout << endl;
    test_size();
    cout << endl;

    queue<string> q;
    q.push("These");
    q.push("are");
    q.push("more than");

    cout << q.front();
    q.pop();
    cout << q.front();
    q.pop();


}*/


