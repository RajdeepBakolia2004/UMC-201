#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
 
#define zero UltraLargeNumber("0")
#define one UltraLargeNumber("1")
 
class UltraLargeNumber{
    UltraLargeNumber subtract(UltraLargeNumber num){
        UltraLargeNumber temp(this->val);
        UltraLargeNumber ans;
        int i=temp.val.size()-1,j=num.val.size()-1;
        while(j>=0){
            if(temp.val[i]-'0'>=num.val[j]-'0'){
                ans.val.push_back(temp.val[i]-num.val[j]+'0');
            }
            else{
                int k=i-1;
                while(temp.val[k]=='0'){
                    temp.val[k]='9';
                    k--;
                }
                temp.val[k]=char(temp.val[k]-1);
                ans.val.push_back((10+(temp.val[i]-'0')-(num.val[j]-'0'))+'0');
            }
            j--;
            i--;
        }
        while(i>=0){
            ans.val.push_back(temp.val[i]);
            i--;
        }
        int idx=ans.val.size()-1;
        while(idx>0 && ans.val[idx]=='0') idx--;
        ans.val=ans.val.substr(0,idx+1);
        reverse(ans.val.begin(),ans.val.end());
        return ans;
    }
    UltraLargeNumber add(UltraLargeNumber num){
        UltraLargeNumber ans;
        int n=num.val.size(),m=this->val.size(),j=n-1,i=m-1,c=0;
        while(i>=0 && j>=0){
            if((num.val[j]-'0')+(this->val[i]-'0')+c>9){
                ans.val.push_back(((num.val[j]-'0')+(this->val[i]-'0')+c)%10+'0');
                c=1;
            }
            else{
                ans.val.push_back((num.val[j]-'0')+(this->val[i]-'0')+c+'0');
                c=0;
            }
            i--;
            j--;
        }
        while(i>=0){
            if((this->val[i]-'0')+c>9){
                ans.val.push_back(((this->val[i]-'0')+c)%10+'0');
                c=1;
            }
            else{
                ans.val.push_back((this->val[i]-'0'+c)+'0');
                c=0;
            }
            i--;
        }
        while(j>=0){
            if((num.val[j]-'0')+c>9){
                ans.val.push_back(((num.val[j]-'0')+c)%10+'0');
                c=1;
            }
            else{
                ans.val.push_back((num.val[j]-'0'+c)+'0');
                c=0;
            }
            j--;
        }
        if(c) ans.val.push_back('1');
        reverse(ans.val.begin(),ans.val.end());
        return ans;
    }
    bool is_greater(UltraLargeNumber num){
        if(num.val.size()!=this->val.size()) return this->val.size()>num.val.size();
        int i=0,n=num.val.size()-1;
        while(i<n && num.val[i]==this->val[i]) i++;
        return this->val[i]>num.val[i];
    }
    bool is_lesser(UltraLargeNumber num){
        if(num.val.size()!=this->val.size()) return this->val.size()<num.val.size();
        int i=0,n=num.val.size()-1;
        while(i<n && num.val[i]==this->val[i]) i++;
        return this->val[i]<num.val[i];
    }
    bool is_greater_or_equal(UltraLargeNumber num){
        if(num.val.size()!=this->val.size()) return this->val.size()>num.val.size();
        int i=0,n=num.val.size()-1;
        while(i<n && num.val[i]==this->val[i]) i++;
        return this->val[i]>=num.val[i];
    }
    bool is_lesser_or_equal(UltraLargeNumber num){
        if(num.val.size()!=this->val.size()) return this->val.size()<num.val.size();
        int i=0,n=num.val.size()-1;
        while(i<n && num.val[i]==this->val[i]) i++;
        return this->val[i]<=num.val[i];
    }
    public:
        string val;
        bool is_negative;
    UltraLargeNumber(){
       is_negative=0;
    }
    UltraLargeNumber(string str){
        this->is_negative=0;
        if(str[0]=='-'){
            str=str.substr(1);
            this->is_negative=1;
        }
        int cnt=0;
        for(int i=0;i<str.size();i++){
            if(str[i]!='0') break;
            cnt++;
        }
        if(cnt==str.size()) this->val="0";
        else this->val=str.substr(cnt);
    }
    void print(){
        if(this->val=="0") cout<<"0\n";
        else if(this->is_negative) cout<<"-"<<this->val<<"\n";
        else cout<<this->val<<"\n";
    }
    void operator=(UltraLargeNumber num){
        this->val=num.val;
        this->is_negative=num.is_negative;
    }
    bool operator==(UltraLargeNumber num){
        return num.val==this->val && num.is_negative==this->is_negative;
    }
    bool operator!=(UltraLargeNumber num){
        return num.val!=this->val || num.is_negative!=this->is_negative;
    }
    bool operator>(UltraLargeNumber num){
        if(this->is_negative && num.is_negative) return this->is_lesser(num);
        else if(this->is_negative && !num.is_negative) return false;
        else if(!this->is_negative && num.is_negative) return true;
        else return this->is_greater(num);
        
    }
    bool operator<(UltraLargeNumber num){
        if(this->is_negative && num.is_negative) return this->is_greater(num);
        else if(this->is_negative && !num.is_negative) return true;
        else if(!this->is_negative && num.is_negative) return false;
        else return this->is_lesser(num);
    }
    bool operator>=(UltraLargeNumber num){
        return (*this)==num || (*this)>num;
    }
    bool operator<=(UltraLargeNumber num){
        return (*this)==num || (*this)<num;
    }
    UltraLargeNumber operator+(UltraLargeNumber num){
        UltraLargeNumber ans;
        if(num==zero) return (*this);
        if((*this)==zero) return num;
        if(this->is_negative && num.is_negative){
            ans=(this->add(num));
            ans.is_negative=1;
        }
        else if(this->is_negative && !num.is_negative){
            if(this->is_greater(num)){
                ans=this->subtract(num);
                ans.is_negative=1;
            }
            else ans=num.subtract((*this));
        }
        else if(!this->is_negative && num.is_negative){
            if(this->is_greater(num)) ans=this->subtract(num);
            else{
                ans=num.subtract((*this));
                ans.is_negative=1;
            }
        }
        else ans=this->add(num);
        return ans;
    }
    UltraLargeNumber operator-(UltraLargeNumber num){
        UltraLargeNumber ans;
        if(num==zero) return (*this);
        if((*this)==zero){
            num.is_negative=!num.is_negative;
            return num;
        }
        if(this->is_negative && num.is_negative){
            if(this->is_greater(num)){
                ans=this->subtract(num);
                ans.is_negative=1;
            }
            else ans=num.subtract((*this));
        }
        else if(this->is_negative && !num.is_negative){
            ans=this->add(num);
            ans.is_negative=1;
        }
        else if(!this->is_negative && num.is_negative) ans=this->add(num);
        else{
            if(this->is_greater(num)) ans=this->subtract(num);
            else{
                ans=num.subtract((*this));
                ans.is_negative=1;
            }
        }
        return ans;
    }
};