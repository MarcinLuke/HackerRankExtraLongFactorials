#include <bits/stdc++.h>
#include <vector>
#include <list>
using namespace std;

vector<int> multiply(vector<int> vec, int divider){

    vector<int> resultUnity;
    vector<int>::reverse_iterator it = vec.rbegin();
    vector<int>::iterator itResU = resultUnity.end();

    int unity = divider;
    int rest = -1;
    int temp = -1;
    int accu = -1;

    for(;it != vec.rend();++it){
        temp = *it;
        if(rest != -1){
            temp = temp * unity + rest;
            rest = -1;
        }else{
            temp = temp * unity;
        }
        
        if(temp >= 10){
            rest = temp / 10;
            accu = temp % 10;
            itResU = resultUnity.insert(itResU,accu);
        } else{
            itResU = resultUnity.insert(itResU,temp);
        }

        if(resultUnity.size() == vec.size()){
            if(rest != -1)
                resultUnity.insert(itResU,rest);
            return resultUnity;
        }
    }

    return resultUnity;
}

vector<int> add(vector<int> a, vector<int> b, list<int> fin){
    int v = 0;
    int rest = -1;
    int j = b.size()-1;

    for(int i=a.size()-1; i >= 0;i--){
        if(j >= 0){
         if(rest != -1 && rest >= 10){
              v = a[i] + b[j] + rest;
              rest = -1;
            }else if(rest != -1){
                v = a[i] + b[j] + rest;
            }else{
                v = a[i] + b[j];
            }

            j--;
            if(j==0)
                rest = -1;
        }
        else{
            if(rest != -1 && rest >= 10){
              v = a[i] + rest;
                rest = -1;
            }else if(rest != -1){
                v = a[i] + rest;
                rest = -1;
            }else{
                v = a[i];
                rest = -1;
            }
        }

        if(v >= 10){
            fin.push_front(v%10);
            rest = v / 10;
            v=0;
        }else{
            fin.push_front(v);
            rest = -1;
            v = 0;
        }
    }

    if(rest != -1){
        fin.push_front(rest);
    }
    vector<int> result;
    list<int>::iterator it = fin.begin();
    for(; it!= fin.end();++it){
        result.push_back(*it);
    }

    return result;    
}

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    unsigned long long int res = 1;

    if(n < 20){
        for(int i=1; i<=n; i++){
            res *=i;
        }
        cout<<res<<endl;
        return;
    }

    vector<int> val1 = {1};
    vector<int> val2 = {1};
    list<int> fin;

    for(int i=1; i<=n; i++){
        if(i<10){
            val1 = multiply(val1,i);
        }else if( i % 10 == 0 ){
            val1.push_back(0);
            val2 = multiply(val1,i/10);
            val1 = val2;         

        }else{
            val2 = multiply(val2,i/10);
            val1 = multiply(val1,i%10);
            val2.push_back(0);
            val2 = add(val2,val1,fin);
            val1 = val2;
            
        }
    }
    
    for(int i=0; i<val2.size(); i++){
        cout<<val2[i];
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
