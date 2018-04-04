//
// Created by YuXiao on 4/4/18.
//

int rev(int a){
    int res=0;
    int b;
    while (a!=0){
        b = a%10;
        a = a/10;
        res+=b;
        if(a==0){
            break;
        }
        res*=10;
    }
    return res;
}

bool is_odd(int n){
    return (n&1)==1 ? true: false;
}
