#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


void SplitString(const string& s, vector<string>& v, const string& c)
{
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2)
    {
        
        v.push_back(s.substr(pos1, pos2-pos1));
        
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

int main(){


    ifstream in("scores");
    if (!in.is_open()) {
        return false;
    }
 
    string line;
    vector<int> midterm;
    vector<int> final;
    while (getline(in, line)) {
        vector<string> v;
        SplitString(line,v,"\t");
        midterm.push_back(stoi(v[1]));
        final.push_back(stoi(v[2]));
        
    }
 
    
    in.close();

    sort(midterm.begin(),midterm.end());
    sort(final.begin(),final.end());

    int midterm_max=midterm[midterm.size()-1];
    int final_max=final[final.size()-1];
    int midterm_min=midterm[0];
    int final_min=final[0];
    float midterm_median=(midterm[500]+midterm[499])/2;
    float final_median=(final[500]+final[499])/2;
    float midterm_Q1=(midterm[250]+midterm[249])/2;
    float final_Q1=(final[250]+final[249])/2;
    float midterm_Q3=(midterm[750]+midterm[749])/2;
    float final_Q3=(final[750]+final[749])/2;

    float midterm_sum;
    for(auto i:midterm){
        midterm_sum+=i;
    }
    float midterm_mean=midterm_sum/midterm.size();
    
    float final_sum;
    for(auto i:final){
        final_sum+=i;
    }
    float final_mean=final_sum/final.size();

    int number = midterm[0];
    vector<int> midterm_mode;
    midterm_mode.push_back(number);
    int count = 1;
    int countMode = 1;
    for (int i=1; i<midterm.size(); i++){
        if (midterm[i] == number) {
            ++count;
        }
        else{ 
            if (count > countMode) {
                countMode = count; 
                midterm_mode.clear();
                midterm_mode.push_back(number);
            }
            else if(count == countMode){
                midterm_mode.push_back(number);
            }
            count = 1; 
            number = midterm[i];
        }
    }
    number = final[0];
    //int final_mode = number;
    vector<int> final_mode;
    final_mode.push_back(number);
    count = 1;
    countMode = 1;
    for (int i=1; i<final.size(); i++){
        if (final[i] == number) {
            ++count;
        }
        else{ 
            if (count > countMode) {
                countMode = count;
                final_mode.clear(); 
                final_mode.push_back(number);
            }
            else if(count==countMode){
                final_mode.push_back(number);
            }
            count = 1; 
            number = final[i];
        }
    }

    float midsd_sum=0;
    for(auto i:midterm){
        //cout<<i<<"-"<<midterm_mean<<endl;
        midsd_sum+=((float)i-midterm_mean)*((float)i-midterm_mean);
    }
    float midterm_sd=sqrt(midsd_sum/(float)(midterm.size()-1));

    float finalsd_sum=0;
    for(auto i:final){
        finalsd_sum+=(i-final_mean)*(i-final_mean);
    }
    float final_sd=sqrt(finalsd_sum/(final.size()-1));


    cout<<"**********midterm********** "<<endl;
    cout<<"max: "<<midterm_max<<endl;
    cout<<"min: "<<midterm_min<<endl;
    cout<<"median: "<<midterm_median<<endl;
    cout<<"Q1: "<<midterm_Q1<<endl;
    cout<<"Q2: "<<midterm_Q3<<endl;
    cout<<"mean: "<<setprecision(3)<<fixed<<midterm_mean<<endl;
    cout<<"mode: ";
    for(auto i: midterm_mode)
        cout<<i<<" ";
     cout<<endl;   
    cout<<"standard seviation: "<<setprecision(3)<<fixed<<midterm_sd<<endl;
    cout<<" "<<endl;

    cout<<"**********final********** "<<endl;
    cout<<"max: "<<final_max<<endl;
    cout<<"min: "<<final_min<<endl;
    cout<<"median: "<<fixed<<setprecision(0)<<final_median<<endl;
    cout<<"Q1: "<<final_Q1<<endl;
    cout<<"Q2: "<<final_Q3<<endl;
    cout<<"mean: "<<setprecision(3)<<fixed<<final_mean<<endl;
    cout<<"mode: ";
    for(auto i: final_mode)
        cout<<i<<" ";
    cout<<endl;    
    cout<<"standard seviation: "<<setprecision(3)<<fixed<<final_sd<<endl;

    return 0;
}