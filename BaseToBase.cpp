///Tahmid Alavi Ishamam

///Please use c++11 or above......

#include<bits/stdc++.h>
using namespace std;


///Prototypes
bool check_number(string inputFromUser,int convertedFrom);
void split_mainArray(const vector<char> &mainArray,int placeOfPoint,int convertedFrom,int convertedTo);
void base_To_base_decide_function(const vector <char> &subArray_decPart, const vector <char> &subArray_pointPart,int convertedFrom,int convertedTo);
double base_To_dec(const vector <char> &subArray_decPart, const vector <char> &subArray_pointPart,int convertedFrom);
double base_To_dec(const vector <char> &mainArray,int convertedFrom);
void dec_To_base(long double dec_value,int convertedTo);
void dec_To_base_withoutFraction(long int dec_value,int convertedTo);
void base_To_base_decide_function(const vector<char> &mainArray,int convertedFrom,int convertedTo);


///Driver
int main(){

int bin=2;
int oct=8;
int dec=10;
int hex=16;
bool check=true;
int convertedTo,convertedFrom,placeOfPoint;
vector <char> mainArray;
string inputFromUser;

cout<<"Enter  your number:";
getline(cin,inputFromUser);




cout<<"Converted from (2/8/10/16) :";
cin>>convertedFrom;

while(convertedFrom!=bin && convertedFrom!=oct && convertedFrom!=dec && convertedFrom!=hex ){
    cout<<"Please enter 2 or 8 or 10 or 16"<<endl;
    cout<<"Converted from (2/8/10/16) :";
    cin>>convertedFrom;
}

cout<<"Converted to (2/8/10/16) :";
cin>>convertedTo;

while(convertedTo!=bin && convertedTo!=oct && convertedTo!=dec && convertedTo!=hex ){
    cout<<"Please enter 2 or 8 or 10 or 16"<<endl;
    cout<<"Converted to (2/8/10/16) :";
    cin>>convertedTo;
}

while(convertedFrom==convertedTo){
    cout<<"You entered same base"<<endl;
    cout<<endl;
    cout<<"Converted to (2/8/10/16) :";
    cin>>convertedTo;
}




check=check_number(inputFromUser,convertedFrom);

while(check==false){
    cout<<"Your number is not  Base "<<convertedFrom;
    cout<<endl;
    cout<<"Please enter a Base "<<convertedFrom<<" number :";
    cin>>inputFromUser;
    check=check_number(inputFromUser,convertedFrom);
}





for(unsigned i=0;i<inputFromUser.length();i++){
    mainArray.push_back(inputFromUser.at(i));
}

for(auto i=mainArray.begin();i!=mainArray.end();i++){
    cout<<*i;
}
cout<<" = ";

vector <char> ::iterator it= find(mainArray.begin(),mainArray.end(),'.');
if(it!=mainArray.end()){
    placeOfPoint=it-mainArray.begin();
    split_mainArray(mainArray,placeOfPoint,convertedFrom,convertedTo);
}
else {

        base_To_base_decide_function(mainArray,convertedFrom,convertedTo);
     }

     cout<<endl;
     system("pause");
     return 0;
}




void split_mainArray(const vector<char> &mainArray,int placeOfPoint,int convertedFrom,int convertedTo){

vector <char> subArray_decPart;
vector <char> subArray_pointPart;


///Populate Decimal part at subArray_decPart

for(unsigned i=0;i<placeOfPoint;i++){
    subArray_decPart.push_back(mainArray.at(i));
}

///Populate Point part at subArray_pointPart

for(unsigned i=placeOfPoint+1;i<mainArray.size();i++){
    subArray_pointPart.push_back(mainArray.at(i));
}

///Call function for which base to which base decide
  base_To_base_decide_function(subArray_decPart,subArray_pointPart,convertedFrom,convertedTo);

}


void base_To_base_decide_function(const vector <char> &subArray_decPart, const vector <char> &subArray_pointPart,int convertedFrom,int convertedTo){
int bin=2;
int oct=8;
int dec=10;
int hex=16;
long double dec_value;

if(convertedFrom==bin && convertedTo==dec ){
    cout<<base_To_dec(subArray_decPart, subArray_pointPart,convertedFrom);
}

else if(convertedFrom==bin && convertedTo==oct){
    dec_value=base_To_dec(subArray_decPart, subArray_pointPart,convertedFrom);
    dec_To_base(dec_value,convertedTo);

}

else if(convertedFrom==bin && convertedTo==hex){
        dec_value=base_To_dec(subArray_decPart, subArray_pointPart,convertedFrom);
        dec_To_base(dec_value,convertedTo);
}

else if(convertedFrom==dec && convertedTo==bin){
        dec_value=base_To_dec(subArray_decPart, subArray_pointPart,convertedFrom);
        dec_To_base(dec_value,convertedTo);
}

else if(convertedFrom==dec && convertedTo==oct){
        dec_value=base_To_dec(subArray_decPart, subArray_pointPart,convertedFrom);
        dec_To_base(dec_value,convertedTo);
}

else if(convertedFrom==dec && convertedTo==hex){
        dec_value=base_To_dec(subArray_decPart, subArray_pointPart,convertedFrom);
        dec_To_base(dec_value,convertedTo);
}

else if(convertedFrom==oct && convertedTo==bin){
        dec_value=base_To_dec(subArray_decPart, subArray_pointPart,convertedFrom);
        dec_To_base(dec_value,convertedTo);
}

else if(convertedFrom==oct && convertedTo==dec){
       cout<<base_To_dec(subArray_decPart, subArray_pointPart,convertedFrom);
}


else if(convertedFrom==oct && convertedTo==hex){
        dec_value=base_To_dec(subArray_decPart, subArray_pointPart,convertedFrom);
        dec_To_base(dec_value,convertedTo);
}

else if(convertedFrom==hex && convertedTo==bin){
        dec_value=base_To_dec(subArray_decPart, subArray_pointPart,convertedFrom);
        dec_To_base(dec_value,convertedTo);
}

else if(convertedFrom==hex && convertedTo==dec){
        cout<<base_To_dec(subArray_decPart, subArray_pointPart,convertedFrom);
}

else if(convertedFrom==hex && convertedTo==oct){
        dec_value=base_To_dec(subArray_decPart, subArray_pointPart,convertedFrom);
        dec_To_base(dec_value,convertedTo);
}


}

 void base_To_base_decide_function(const vector<char> &mainArray,int convertedFrom,int convertedTo){
 int bin=2;
 int oct=8;
 int dec=10;
 int hex=16;
 long int dec_value;

if(convertedFrom==bin && convertedTo==dec ){
    cout<<base_To_dec(mainArray,convertedFrom);
}

else if(convertedFrom==bin && convertedTo==oct){
    dec_value=base_To_dec(mainArray,convertedFrom);
    dec_To_base_withoutFraction(dec_value,convertedTo);

}

else if(convertedFrom==bin && convertedTo==hex){
        dec_value=base_To_dec(mainArray,convertedFrom);
        dec_To_base_withoutFraction(dec_value,convertedTo);
}

else if(convertedFrom==dec && convertedTo==bin){
        dec_value=base_To_dec(mainArray,convertedFrom);
        dec_To_base_withoutFraction(dec_value,convertedTo);

}

else if(convertedFrom==dec && convertedTo==oct){
        dec_value=base_To_dec(mainArray,convertedFrom);
        dec_To_base_withoutFraction(dec_value,convertedTo);
}

else if(convertedFrom==dec && convertedTo==hex){
        dec_value=base_To_dec(mainArray,convertedFrom);
        dec_To_base_withoutFraction(dec_value,convertedTo);

}

else if(convertedFrom==oct && convertedTo==bin){
        dec_value=base_To_dec(mainArray,convertedFrom);
        dec_To_base_withoutFraction(dec_value,convertedTo);

}

else if(convertedFrom==oct && convertedTo==dec){
       cout<<base_To_dec(mainArray,convertedFrom);
}


else if(convertedFrom==oct && convertedTo==hex){
        dec_value=base_To_dec(mainArray,convertedFrom);
        dec_To_base_withoutFraction(dec_value,convertedTo);

}

else if(convertedFrom==hex && convertedTo==bin){
        dec_value=base_To_dec(mainArray,convertedFrom);
        dec_To_base_withoutFraction(dec_value,convertedTo);
}

else if(convertedFrom==hex && convertedTo==dec){
        cout<<base_To_dec(mainArray,convertedFrom);
}

else if(convertedFrom==hex && convertedTo==oct){
        dec_value=base_To_dec(mainArray,convertedFrom);
        dec_To_base_withoutFraction(dec_value,convertedTo);

}

}









double base_To_dec(const vector <char> &subArray_decPart, const vector <char> &subArray_pointPart,int convertedFrom){



char charOfArray;
int convertedCharToInt;
long double decimal=0,power=0;
long double final_Decimal,decimal_pointPart=0.0;
int power_pointPart=-1;

///Convert Base to Decimal of decPart
for(auto i=subArray_decPart.size()-1;i!=-1;i--){

   charOfArray=subArray_decPart.at(i);
   if(charOfArray=='A') {convertedCharToInt=10; }
    else if(charOfArray=='B') {convertedCharToInt=11; }
     else if(charOfArray=='C') {convertedCharToInt=12; }
      else if(charOfArray=='D') {convertedCharToInt=13; }
       else if(charOfArray=='E') {convertedCharToInt=14; }
        else if(charOfArray=='F') {convertedCharToInt=15; }
         else{ convertedCharToInt=charOfArray-'0'; }
   decimal=decimal+((pow(convertedFrom,power))*convertedCharToInt);
   power++;
}

///Convert Base to Decimal of pointPart
for(auto i=0;i<subArray_pointPart.size();i++){
    charOfArray=subArray_pointPart.at(i);
     if(charOfArray=='A') {convertedCharToInt=10; }
      else if(charOfArray=='B') {convertedCharToInt=11; }
       else if(charOfArray=='C') {convertedCharToInt=12; }
        else if(charOfArray=='D') {convertedCharToInt=13; }
         else if(charOfArray=='E') {convertedCharToInt=14; }
          else if(charOfArray=='F') {convertedCharToInt=15; }
           else{ convertedCharToInt=charOfArray-'0'; }
    decimal_pointPart=decimal_pointPart+((pow(convertedFrom,power_pointPart))*convertedCharToInt);
    power_pointPart--;
}

///Combined decPart & pointPart
final_Decimal=decimal+decimal_pointPart;

return final_Decimal;
}



double base_To_dec(const vector <char> &mainArray,int convertedFrom){

char charOfArray;
int convertedCharToInt;
long double decimal=0,power=0;


///Convert Base to Decimal of decPart
for(auto i=mainArray.size()-1;i!=-1;i--){

   charOfArray=mainArray.at(i);
   if(charOfArray=='A') {convertedCharToInt=10; }
    else if(charOfArray=='B') {convertedCharToInt=11; }
     else if(charOfArray=='C') {convertedCharToInt=12; }
      else if(charOfArray=='D') {convertedCharToInt=13; }
       else if(charOfArray=='E') {convertedCharToInt=14; }
        else if(charOfArray=='F') {convertedCharToInt=15; }
         else{ convertedCharToInt=charOfArray-'0'; }
   decimal=decimal+((pow(convertedFrom,power))*convertedCharToInt);
   power++;
}

return decimal;

}

void dec_To_base_withoutFraction(long int dec_value,int convertedTo){

    vector<char>convertedTo_intPart;
    vector<char>final_Part;

    while(dec_value>0){
        int x=dec_value%convertedTo;
        if(x==10){convertedTo_intPart.push_back('A');}
         else if(x==11){convertedTo_intPart.push_back('B');}
          else if(x==12){convertedTo_intPart.push_back('C');}
           else if(x==13){convertedTo_intPart.push_back('D');}
            else if(x==14){convertedTo_intPart.push_back('E');}
             else if(x==15){convertedTo_intPart.push_back('F');}
                else{convertedTo_intPart.push_back(x+'0');}
        dec_value=dec_value/convertedTo;
    }

    for(auto i=convertedTo_intPart.size()-1;i!=-1;i--){
        final_Part.push_back(convertedTo_intPart.at(i));
    }

    for(auto i=final_Part.begin();i!=final_Part.end();i++){
    cout<<*i;
}
}




void dec_To_base(long double dec_value,int convertedTo){
    int int_Part=dec_value;
    double int_Part_doubleCasting=int_Part;
    double pointPart=dec_value-int_Part_doubleCasting;
    int count=0;

    vector<char>convertedTo_intPart;
    vector<char>convertedTo_pointPart;
    vector<char>final_Part;

    while(int_Part>0){
        int x=int_Part%convertedTo;
        if(x==10){convertedTo_intPart.push_back('A');}
         else if(x==11){convertedTo_intPart.push_back('B');}
          else if(x==12){convertedTo_intPart.push_back('C');}
           else if(x==13){convertedTo_intPart.push_back('D');}
            else if(x==14){convertedTo_intPart.push_back('E');}
             else if(x==15){convertedTo_intPart.push_back('F');}
                else{convertedTo_intPart.push_back(x+'0');}
        int_Part=int_Part/convertedTo;
    }

    for(auto i=convertedTo_intPart.size()-1;i!=-1;i--){
        final_Part.push_back(convertedTo_intPart.at(i));
    }
   final_Part.push_back('.');

  while(pointPart>0.0 && count<5){
    dec_value=pointPart*convertedTo;
    int_Part=dec_value;
     if(int_Part==10){convertedTo_pointPart.push_back('A');}
         else if(int_Part==11){convertedTo_pointPart.push_back('B');}
          else if(int_Part==12){convertedTo_pointPart.push_back('C');}
           else if(int_Part==13){convertedTo_pointPart.push_back('D');}
            else if(int_Part==14){convertedTo_pointPart.push_back('E');}
             else if(int_Part==15){convertedTo_pointPart.push_back('F');}
                else{convertedTo_pointPart.push_back(int_Part+'0');}
    int_Part_doubleCasting=int_Part;
    pointPart=dec_value-int_Part_doubleCasting;
    count++;
  }
   for(auto i=convertedTo_pointPart.begin();i!=convertedTo_pointPart.end();i++){
    final_Part.push_back(*i);
}
  for(auto i=final_Part.begin();i!=final_Part.end();i++){
    cout<<*i;
}
}



bool check_number(string inputFromUser,int convertedFrom){

vector<char>x;

 for(unsigned i=0;i<inputFromUser.length();i++){
        x.push_back(inputFromUser.at(i));
 }
 for(auto i=x.begin();i!=x.end();i++){
 if(convertedFrom==2){
        if((int)*i<46 || (int)*i==47  || (int)*i>49){
            return false;
        }

}
else if(convertedFrom==8){
    if((int)*i<46 || (int)*i==47 || (int)*i>55){
            return false;
        }
}
else if(convertedFrom==10){
    if((int)*i<46 || (int)*i==47  || (int)*i>57){
            return false;
        }
}
else if(convertedFrom==16){
    if((int)*i<48 || ((int)*i>57 && (int)*i<65) || (int)*i>70 ){
            return false;
        }
}
 }
return true;

}























