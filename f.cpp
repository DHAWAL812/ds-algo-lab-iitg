#include<bits/stdc++.h> 
using namespace std; 
 
//Function to return precedence of operators 
int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
  
// The main function to convert infix expression 
//to postfix expression 
string infixToPostfix(string s) 
{ 
    std::stack<char> st; 
    st.push('N'); 
    int l = s.length(); 
    string ns; 
    long int i=0;
    while(i<l)
    { 
        
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        if(s[i] == '(') 
        {  
        st.push('('); 
        i++;
        }
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(s[i] == ')') 
        { 
            while(st.top() != 'N' && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
               ns += c; 
               ns+=',';
            } 
            if(st.top() == '(') 
            { 
                char c = st.top(); 
                st.pop(); 
            } 
            i++;
        } 
          
        //If an operator is scanned 
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
        { 
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
                ns+=',';
            } 
            st.push(s[i]); 
            i++;
        } 
        else
        {
            while(s[i]>'/'&&s[i]<':')
            {ns+=s[i];
            i++;}
            ns+=',';
        }
  
    } 
    //Pop all the remaining elements from the stack 
    while(st.top() != 'N') 
    { 
    
        char c = st.top(); 
        st.pop(); 
        ns += c; 
        ns+=',';
    } 
      
    return ns;
  
} 
struct et 
{ 
    string value; 
    et* left, *right; 
}; 
  
// A utility function to check if 'c' 
// is an operator 
bool isOperator(char c) 
{ 
    if (c == '+' || c == '-' || 
            c == '*' || c == '/' || 
            c == '^') 
        return true; 
    return false; 
} 
  
// A utility function to create a new node 
et* newNode(string v) 
{ 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
}; 
  
// Returns root of constructed tree for given 
// postfix expression 
et* constructTree(string ns) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2; 
  
    // Traverse through every character of 
    // input expression
    long int =0;
    while(i<ns.length())
    { 
        // If operand, simply push into stack 
        if (!isOperator(ns[i])) 
        { string fu="";
        	while(ns[i]!=',')
        	{
        		fu+=ns[i];
        		i++;
        	}
            t = newNode(ns[i]); 
            st.push(t); 
            i++;
        } 
        else // operator 
        { 
            t = newNode(ns[i]); 
  
            // Pop two top nodes 
            t1 = st.top(); // Store top 
            st.pop();      // Remove top 
            t2 = st.top(); 
            st.pop(); 
  
            //  make them children 
            t->right = t1; 
            t->left = t2; 
  
            // Add this subexpression to stack 
            st.push(t); 
            i+=2;
        } 
    } 
  
    //  only element will be root of expression 
    // tree 
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 
  
int toInt(string s)  
{  
    int num = 0;  
      
    // Check if the integral value is  
    // negative or not 
    // If it is not negative, generate the number  
    // normally 
    if(s[0]!='-') 
        for (int i=0; i<s.length(); i++)  
            num = num*10 + (int(s[i])-48);  
    // If it is negative, calculate the +ve number 
    // first ignoring the sign and invert the  
    // sign at the end 
    else
        for (int i=1; i<s.length(); i++)  
        { 
            num = num*10 + (int(s[i])-48);  
            num = num*-1; 
        } 
      
    return num;  
}  
int eval()
//Driver program to test above functions 
int main() 
{ 
    string exp;
    cin>>exp;
    string ns=infixToPostfix(exp); 
    et* dha=constructTree(ns);
    
    return 0; 
} 
