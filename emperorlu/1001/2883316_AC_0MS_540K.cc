#include <iostream>
#include <string>

#define _MAXL 100
#define _DSTEP 4
#define _M 10000

using namespace std;

char * int2str(int num,int radix,char *result);

class BigNumber
{
    public:
        //const static int _MAXL;// = 100;
        //const static int _DSTEP;// = 4;
        //const static int _M;// = 10000; // 10^_DSTEP

        BigNumber();
        BigNumber(std::string s);
        static void standalize(string & s) {
            // delete zeros like "0000000xxxx.xxxxx000000"
            int pos = s.find('.');
            if (pos==-1) pos = s.length();
            int i = 0;
            while ((i<s.length())&&(i<pos)) {
                if (s.at(i)!='0') break;
                ++i;
            }
            s.erase(0,i);
            i = s.length()-1;
            while((i>0)&&(i>pos)) {
                if (s.at(i)!='0') break;
                --i;
            }
            s.erase(i+1,s.length()-i+1);
            // Integer
            pos = s.find('.');
            if ((pos!=-1)&&(pos==(s.length()-1))) {
                s.erase(pos,1); // DELETE '.'
            }
        }
        /**//* 'plus' only suitable to Integer Number
         * Haven't considered the Float Number
         */
        static BigNumber * plus(BigNumber * A,BigNumber * B) {
            BigNumber * r = new BigNumber();
            if (A->_bnLen > B->_bnLen) {
                BigNumber * t = A;
                A = B;
                B = t;
            }
/**//////////////////Don't change i in the middle of each block/////////////////
            int i,nc=0;
            for (i=0;i<A->_bnLen;++i) {
                r->_bn[i] = A->_bn[i]+B->_bn[i] + nc;
                nc = r->_bn[i] / _M;
                r->_bn[i] = r->_bn[i] % _M;
            }
            for (;i<B->_bnLen;++i) {
                r->_bn[i] = B->_bn[i] + nc;
                nc = r->_bn[i] / _M;
                r->_bn[i] = r->_bn[i] % _M;
            }
            if (nc>0) {
                r->_bn[i] = nc;
                r->_bnLen = i+1;
            } else {
                r->_bnLen = i;
            }
/**//////////////////////////////////////////////////////////////////////////////
            return r;
        }
        static BigNumber * multiple(BigNumber * A,BigNumber * B) {
            BigNumber * t;
            if (A->_bnLen > B->_bnLen) {
                t = A;A = B;B = t;
            }
            BigNumber * r = new BigNumber();
            int i,j,k,nc;
            for (i=0;i<A->_bnLen;++i) {
                t = new BigNumber();
                nc = 0;
                for (j=0;j<B->_bnLen;++j) {
                    t->_bn[j+i] = B->_bn[j]*A->_bn[i] + nc;
                    nc = t->_bn[j+i] / _M;
                    t->_bn[j+i] = t->_bn[j+i] % _M;
                }
                if (nc>0) {
                    t->_bn[j+i] = nc;
                    t->_bnLen = j+i+1;
                } else {
                    t->_bnLen = j+i;
                }
//                t->Print();
                r = plus(r,t);
                delete t;
            }
            r->_pointPos = A->_pointPos + B->_pointPos;
            return r;
        }
        void Print();
    private:
        int _bn[_MAXL];
        int _bnLen;
        int _pointPos;
};
BigNumber::BigNumber(){
    memset(_bn,0,sizeof(_bn));
    _bnLen=0;
    _pointPos=0;
}
BigNumber::BigNumber(std::string s) {
    memset(_bn,0,sizeof(_bn));
    _bnLen=0;
    _pointPos=0;
    int i,j;
    // STANDIZE
    standalize(s);
    // delete _pointPos
    if (s.find('.')!=-1) {
        _pointPos = s.length() - s.find('.') - 1;
        s.erase(s.find('.'),1); // DELETE '.'
    }
//    cout<<s<<" ";
    // divide s & combine into _bn
    for (i=s.length()-1;i>=_DSTEP-1;i=i-_DSTEP) {
        for (j=_DSTEP-1;j>=0;--j) {
            _bn[_bnLen]=_bn[_bnLen]*10+s.at(i-j)-'0';
        }
        ++_bnLen;
    }
    if (i>=0) {
        for (j=0;j<=i;++j) {
            _bn[_bnLen]=_bn[_bnLen]*10+(s.at(j)-'0');
        }
        ++_bnLen;
    }
}
void BigNumber::Print() {
    if (_bnLen==0) {
        cout<<"0";
        return;
    }
    int i,k,l;
    string o="";
    char tc[_DSTEP+1];
    memset(tc,0,sizeof(tc));
    // i = _bnLen-1
    int2str(_bn[_bnLen-1],10,tc);
//    cout<<"*"<<tc<<" ";
    o.append(tc);
    // i < _bnLen-1
    tc[_DSTEP] = NULL;
    for (i=_bnLen-2;i>=0;--i) {
        k = _bn[i];l=_DSTEP-1;
        while (l>=0) {
            tc[l] = k % 10 + '0';
            k = k / 10;
            --l;
        }
//        cout<<tc<<" ";
        o.append(tc);
    }
    if (_pointPos!=0) {
        l = o.length() - _pointPos;
        if (l>=0) {
            o.insert(o.length()-_pointPos,".");
        } else {
            for (i=0;i<abs(l);++i) {
                o.insert(0,"0");
            }
            o.insert(0,"0.");
        }
    }
    standalize(o);
    cout<<o<<endl;
}

int main() {
    string s;
    int n,i;
    while (cin>>s>>n) {
        BigNumber * a = new BigNumber(s);
        BigNumber * r = new BigNumber("1");
        if (n>=0) {
            for (i=0;i<n;++i) {
                r = BigNumber::multiple(r,a);
//                r->Print();
            }
        }
        r->Print();
        delete r;
    }
    return 0;
}

char * int2str(int num,int radix,char *result) {
    if (num<0) {
        num=abs(num);
        int2str(num,radix,result);
        return result;
    }
    if (num%radix==0 && num/radix==0) return result;
    result=int2str(num/radix,radix,result);
    if (num%radix>10) 
        *result='A'+num%radix-10;
    else 
        *result='0'+num%radix;
    *(result+1)=NULL;
    return result+1;
}
