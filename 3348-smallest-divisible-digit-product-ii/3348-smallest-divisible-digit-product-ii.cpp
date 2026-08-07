class Solution {
public:
    string smallestNumber(string num, long long t) {
        int A=0,B=0,C=0,D=0;
        while(t%2==0){t/=2;A++;}
        while(t%3==0){t/=3;B++;}
        while(t%5==0){t/=5;C++;}
        while(t%7==0){t/=7;D++;}
        if(t!=1) return "-1";

        int n = (int)num.size();
        static const int E2[10]={0,0,1,0,2,0,1,0,3,0};
        static const int E3[10]={0,0,0,1,0,0,1,0,0,2};
        static const int E5[10]={0,0,0,0,0,1,0,0,0,0};
        static const int E7[10]={0,0,0,0,0,0,0,1,0,0};

        int dimB=B+1, dimC=C+1, dimD=D+1;
        vector<int> dp((size_t)(A+1)*dimB*dimC*dimD, 0);
        auto idx=[&](int i,int j,int k,int l){
            return ((i*dimB+j)*dimC+k)*dimD+l;
        };
        for(int i=0;i<=A;i++)
        for(int j=0;j<=B;j++)
        for(int k=0;k<=C;k++)
        for(int l=0;l<=D;l++){
            if(i==0&&j==0&&k==0&&l==0){ dp[idx(i,j,k,l)]=0; continue; }
            int best = INT_MAX;
            for(int dg=1; dg<=9; dg++){
                int ni = max(0,i-E2[dg]);
                int nj = max(0,j-E3[dg]);
                int nk = max(0,k-E5[dg]);
                int nl = max(0,l-E7[dg]);
                if(ni==i && nj==j && nk==k && nl==l) continue;
                int cand = 1 + dp[idx(ni,nj,nk,nl)];
                if(cand<best) best=cand;
            }
            dp[idx(i,j,k,l)] = best;
        }

        auto minDigitsNeeded=[&](int i,int j,int k,int l)->int{
            if(i<0)i=0; if(i>A)i=A;
            if(j<0)j=0; if(j>B)j=B;
            if(k<0)k=0; if(k>C)k=C;
            if(l<0)l=0; if(l>D)l=D;
            return dp[idx(i,j,k,l)];
        };

        {
            long long e2=0,e3=0,e5=0,e7=0;
            bool zerofree=true;
            for(char ch: num){
                int dgt = ch-'0';
                if(dgt==0){ zerofree=false; break; }
                e2+=E2[dgt]; e3+=E3[dgt]; e5+=E5[dgt]; e7+=E7[dgt];
            }
            if(zerofree && e2>=A && e3>=B && e5>=C && e7>=D) return num;
        }

        vector<int> P2(n+1,0), P3(n+1,0), P5(n+1,0), P7(n+1,0);
        for(int i=0;i<n;i++){
            int dgt = num[i]-'0';
            int e2 = (dgt==0)?0:E2[dgt];
            int e3 = (dgt==0)?0:E3[dgt];
            int e5 = (dgt==0)?0:E5[dgt];
            int e7 = (dgt==0)?0:E7[dgt];
            P2[i+1]=P2[i]+e2;
            P3[i+1]=P3[i]+e3;
            P5[i+1]=P5[i]+e5;
            P7[i+1]=P7[i]+e7;
        }

        int firstZero = n;
        for(int i=0;i<n;i++) if(num[i]=='0'){ firstZero=i; break; }

        int Lmin = max(1, n-firstZero);
        int foundL=-1, foundE=-1, foundP=-1;
        for(int L=Lmin; L<=n; L++){
            int p = n-L;
            int reqA = max(0, A-P2[p]);
            int reqB = max(0, B-P3[p]);
            int reqC = max(0, C-P5[p]);
            int reqD = max(0, D-P7[p]);
            int digit = num[p]-'0';
            int slots = L-1;
            bool ok=false;
            for(int e=digit+1; e<=9; e++){
                int la = max(0, reqA-E2[e]);
                int lb = max(0, reqB-E3[e]);
                int lc = max(0, reqC-E5[e]);
                int ld = max(0, reqD-E7[e]);
                if(minDigitsNeeded(la,lb,lc,ld) <= slots){
                    foundL=L; foundE=e; foundP=p; ok=true; break;
                }
            }
            if(ok) break;
        }

        if(foundL!=-1){
            string result = num.substr(0, foundP);
            result += char('0'+foundE);
            int reqA = max(0, A-P2[foundP]);
            int reqB = max(0, B-P3[foundP]);
            int reqC = max(0, C-P5[foundP]);
            int reqD = max(0, D-P7[foundP]);
            int la = max(0, reqA-E2[foundE]);
            int lb = max(0, reqB-E3[foundE]);
            int lc = max(0, reqC-E5[foundE]);
            int ld = max(0, reqD-E7[foundE]);
            int slots = foundL-1;
            for(int s=0; s<slots; s++){
                int remaining = slots-s-1;
                for(int dg=1; dg<=9; dg++){
                    int na = max(0, la-E2[dg]);
                    int nb = max(0, lb-E3[dg]);
                    int nc = max(0, lc-E5[dg]);
                    int nd = max(0, ld-E7[dg]);
                    if(minDigitsNeeded(na,nb,nc,nd) <= remaining){
                        result += char('0'+dg);
                        la=na; lb=nb; lc=nc; ld=nd;
                        break;
                    }
                }
            }
            return result;
        }

        int need = minDigitsNeeded(A,B,C,D);
        int Len = max(n+1, need);
        string result;
        int la=A, lb=B, lc=C, ld=D;
        for(int s=0; s<Len; s++){
            int remaining = Len-s-1;
            for(int dg=1; dg<=9; dg++){
                int na = max(0, la-E2[dg]);
                int nb = max(0, lb-E3[dg]);
                int nc = max(0, lc-E5[dg]);
                int nd = max(0, ld-E7[dg]);
                if(minDigitsNeeded(na,nb,nc,nd) <= remaining){
                    result += char('0'+dg);
                    la=na; lb=nb; lc=nc; ld=nd;
                    break;
                }
            }
        }
        return result;
    }
};