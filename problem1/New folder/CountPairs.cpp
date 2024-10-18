#include<bits/stdc++.h>
#include<unordered_map>
#include <fstream> 
using namespace std;
#include "UltraLargeNumber.h"

extern "C" {
    void Count_Pairs(){
        unordered_map<string,string> nums;
        ifstream inputFile("inputs.txt");
        if (!inputFile.is_open()) {
            cerr << "Error:File Not Opened!!!\n";
            return;
        }
        string aim;
        getline(inputFile,aim);
        string length;
        getline(inputFile,length);
        UltraLargeNumber n(length);
        UltraLargeNumber target(aim);
        UltraLargeNumber ans=zero;
        while(n>zero){
            string a;
            getline(inputFile,a);
            UltraLargeNumber ele(a);
            UltraLargeNumber needed=ele+target;
            string str=needed.val;
            if(needed<zero) str.insert(0,"-");
            if(nums.count(str)) ans=ans+UltraLargeNumber(nums[str]);
            if(nums.count(a)) nums[a]=(UltraLargeNumber(nums[a])+one).val;
            else nums[a]="1";
            n=n-one;
        }
        ans.print();
    }
};
