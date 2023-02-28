#include <iostream>

using namespace std;

class Element
{
public:
    int i; // row num
    int j; // col num
    int x; // value itself
};

class Sparse
{
private:
    int m; // dimension
    int n; //
    int num;
    Element *ele;

public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }
    ~Sparse()
    {
        delete[] ele;
    }
    friend istream &operator>>(istream &is, Sparse &s);
    friend ostream &operator<<(ostream &is, Sparse &s);
    Sparse operator+(Sparse &s);
};
Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;
    // if they are not equal, return null
    if (m != s.m || n != s.n)
    {
        return Sparse(0, 0, 0);
    }
    Sparse *sum = new Sparse(m, n, num + s.num);
    i = j = k = 0;
    // while not over num
    while (i < num && j < s.num)
    {
        // if current row is smaller, store current
        if (ele[i].i < s.ele[j].i)
        {
            sum->ele[k++] = ele[i++];
        }
        else if (ele[i].i > s.ele[j].i)
        {
            sum->ele[k++] = s.ele[j++];
        }
        else
        {
            if (ele[i].j < s.ele[j].j)
            {
                sum->ele[k++] = ele[i++];
            }
            else if (ele[i].j > s.ele[j].j)
            {
                sum->ele[k++] = s.ele[j++];
            }
            else
            {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
                printf("addded");
            }
        }
    }
    for (; i < num; i++)
        sum->ele[k++] = ele[i];
    for (; j < s.num; j++)
        sum->ele[k++] = s.ele[j];
    sum->num = k;
    return *sum;
}
// store each ele, depending on num size
istream &operator>>(istream &is, Sparse &s)
{
    cout << "Enter non-zero elements";
    for (int i = 0; i < s.num; i++)
    {
        cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }
    return is;
}

ostream &operator<<(ostream &os, Sparse &s)
{
    // counter for element
    int k = 0;
    // loop through m and n
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            // if row and col are same, print value
            if (s.ele[k].i == i && s.ele[k].j == j)
            {
                cout << s.ele[k++].x << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return os;
}

int main()
{
    Sparse s1(5, 5, 5);
    Sparse s2(5, 5, 5);

    cin >> s1;
    cin >> s2;

    Sparse sum = s1 + s2;

    cout << "First matrix" << endl
         << s1;
    cout << "Second matrix" << endl
         << s2;
    cout << "Sum Matrix" << endl
         << sum;

    return 0;
}