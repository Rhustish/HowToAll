int main(){
//     cout<<"Enter your password"<<endl;
//     string s; getline(cin,s);
//     bool length = 0 ,   chari = 0 , num = 0 , lletter = 0 , uletter = 0;
//     if(s.length() >= 6 && s.length() <= 16) length = 1;
//     for(int i = 0 ; s[i]!='\0' ; i++){
//         if(s[i] == '@' || s[i] == '#' || s[i] == '$') chari = 1;
//         if((s[i] >= 'a' && s[i] <= 'z')) lletter = 1;
//         if((s[i] >= 'A' && s[i] <= 'Z')) uletter = 1;
//         if(s[i] >= '0' && s[i] <= '9') num = 1;
//     }
//     if(length && num && chari && uletter && lletter)
//         cout<<"Valid"<<endl;
//     else
//         cout<<"Invalid"<<endl;
// }