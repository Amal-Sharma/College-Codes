#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isbrackterbalanced(string expr)
{
    stack<int> heap;
    for(int i=0;i<5;i++)
    {
        heap.push(i);
    }
    stack<char> temp;
    for(int i=0;i<expr.length();i++)
    {
        if(temp.empty())
        {
            temp.push(expr[i]);
        }
        else if ((temp.top() == '(' && expr[i] == ')')
				|| (temp.top() == '{' && expr[i] == '}')
				|| (temp.top() == '[' && expr[i] == ']'))
                 {
                    temp.pop();
		         }
        else
        {
            temp.push(expr[i]);
        }
    }
    if(temp.empty())
    {
        return true;
    }
    return false;

}

int main()
{
    string expr = "{()}[]";
    if(isbrackterbalanced(expr))
    {
        cout<<"Balanced";
    }
    else 
    {
        cout<<"Not Balanced";
    }
    
    return 0;
}
