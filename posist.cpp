#include<bits/stdc++.h>
using namespace std;
int totalNodes=0;
class Owner{
public:
      string name,address,mobile,phone;
      int pass;
      int id;
//public:
      void infoEntry()
      {
            cout<<"Enter name";
            getline(cin,name);
            cout<<"Enter address";
            getline(cin,address);
            cout<<"Enter mobile";getline(cin,mobile);cout<<"Enter phone";getline(cin,phone);
            cout<<"Set a password in form of number";
            cin>>pass;
            cout<<"Re-enter password";
            int pass1;
            cin>>pass1;
            while(pass!=pass1)
            {
            	cout<<"password do not match";
            	cout<<"Set a password in form of number";
	            cin>>pass;
	            cout<<"Re-enter password";
	            cin>>pass1;
            }
            //save();
      }
      	void showData()
      	{
      		cout<<"Enter password";
      		int key;
      		cin>>key;
      		while(key!=pass)
      		{
      			cout<<"Wrong password, re-enter correct one";
      			cin>>key;
      		}
      		cout<<"Name,Address,mobile,phone are"<<endl;
      		cout<<decrypt(name,pass);
      		cout<<"    "<<decrypt(address,pass)<<"    "<<decrypt(mobile,pass)<<"    "<<decrypt(phone,pass)<<endl;
      	}
      	void save()
      	{
      		name=encrypt(name,pass);
      		address=encrypt(address,pass);
      		mobile=encrypt(mobile,pass);
      		phone=encrypt(phone,pass);
      	}
      	string encrypt( std::string text,int s )
		{
		      string result = "";

                      // traverse text
                      for (int i=0;i<text.length();i++)
                      {
                          // apply transformation to each character
                          // Encrypt Uppercase letters
                          if (isupper(text[i]))
                              result += char(int(text[i]+s-65)%26 +65);

                      // Encrypt Lowercase letters
                      else
                          result += char(int(text[i]+s-97)%26 +97);
                      }

                      // Return the resulting string
                      return result;
		}
		string decrypt(string text,int s)
		{
		      //cout<<"sa";
		      string result = "";

                      // traverse text
                      for (int i=0;i<text.length();i++)
                      {
                          // apply transformation to each character
                          // Encrypt Uppercase letters
                          if (isupper(text[i]))
                              result += char(int(text[i]-s+65)%26 -65);

                      // Encrypt Lowercase letters
                      else
                          result += char(int(text[i]-s+97)%26 -97);
                      }

                      // Return the resulting string
                      return result;
		}
};
class Node{
      private:
            int timestamp;
      public:
            int nodeNumber;
};
int main()
{
	Owner a;
	a.infoEntry();
	cout<<a.name<<" "<<a.address;
	a.showData();
	return 0;
}
