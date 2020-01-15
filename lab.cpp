#include<bits/stdc++.h>
using namespace std;

struct course
{
    int sem;
    int L, T, P, C;
    string title;
};

FILE* createfile(const char* s)
{
	FILE* fp;
	fp=fopen(s,"w");
	// fprintf(fp,"hello\n");
	return fp;
}
//fprintf(mfpi,"%d\n",iarr[j]);
map<string,double>gconv;
int main()
{
    fstream fin, fout;
    fin.open("students.csv", ios::in);
    map<string, string> students;
    map<string, course> courses;
    map<string, map<string, string>> grades;
    gconv["AA"]=10;
    gconv["AS"]=10;
    gconv["AB"]=9;
    gconv["BB"]=8;
    gconv["BC"]=7;
    gconv["CC"]=6;
    gconv["CD"]=5;
    gconv["DD"]=4;
    gconv["F"]=0;
    while(fin.good())
    {
        string roll_no, name;
        getline(fin, name, ',');
        getline(fin, roll_no, '\n');
        if(!name.empty())
            students[roll_no] = name;
    }
    fin.close();
    fin.open("courses.csv", ios::in);
    while(fin.good())
    {
        course temp;
        string sem, id, L, T, P, C;
        getline(fin, sem, ',');
        getline(fin, id, ',');
        getline(fin, temp.title, ',');
        getline(fin, L, ',');
        getline(fin, T, ',');
        getline(fin, P, ',');
        getline(fin, C, '\n');
        try
        {
            temp.sem = stoi(sem);
            temp.L = stoi(L);
            temp.T = stoi(T);
            temp.P = stoi(P);
            temp.C = stoi(C);
            if(!id.empty())
                courses[id] = temp;
        }
        catch(const exception& e)
        {
            break;
            std::cerr << e.what() << '\n';
        }
    }
    fin.close();
    fin.open("grades.csv", ios::in);
    while(fin.good())
    {
        string roll, id, g;
        getline(fin, roll, ',');
        getline(fin, id, ',');
        getline(fin, g, '\n');
        try
        {
            if(!roll.empty())
            {
                grades[roll][id] = g;
            }
        }
        catch(const exception& e)
        {
            break;
            std::cerr << e.what() << '\n';
        }
    }
    fin.close();

    // for(auto it = students.begin(); it != students.end(); it++)
    //     cout << it -> first << ':' << it -> second << endl;
    
    // for(auto x : courses)
    // {
    //     cout << x.first << ":" << x.second.L << " " << x.second.T << " "<< x.second.P << " "<< x.second.C << " " << x.second.title << " " << x.second.sem << '\n';
    // }
    // for(auto x : grades)
    // {
    //     cout << x.first << ":" << '\n';
    //     for(auto y : x.second)
    //         cout << y.first << "-" << y.second << '\n';
    // }
    
    // cout << "824383473847" << ":" << students[" 824383473847"] << '\n';
    
    // for(auto x : grades["824383473847"])
    // {
    //     for(int i = 1; i <= 4; i++)
    //     {
    //         cout << "Sem" << i << '\n';
    //         if(courses[x.first].sem == i)
    //         {
    //             cout << x.first << ":" << x.second << '\n';
    //         }
    //     }
    // }
    
     
     for(auto it = students.begin(); it != students.end(); it++)
     {  
         const char* rstud=(it->first +".txt").c_str();
         FILE* roll=createfile(rstud);
        //  double spiarr[8];
        //  double cpiarr[8];
        //  memset(spiarr,0,sizeof(spiarr));
        //  memset(cpiarr,0,sizeof(cpiarr));
         vector<double>tspi;
        vector<double>tcpi;    
         double cpi=0;
         double cptot=0;
         double cpst=0;
            const char* rollnum= (it->first).c_str();
            const char* name= (it->second).c_str();
            fprintf(roll,"Rol Number : %s\n",rollnum);
            fprintf(roll,"Name : %s\n",name);
            fprintf(roll,"\n");
            cout << it -> first << endl;
            cout<< it -> second << endl;
                for(int i=1;i<=8;i++)
                 {
                     fprintf(roll,"\n");
                    fprintf(roll,"Semester %d\n",i);
                    fprintf(roll,"\n");
                    cout<<"semester no "<< i<<endl;
                    double studt=0;
                    double tot=0;
                    double spi=0;
                    fprintf(roll,"Course Number |Course Name                                       | Credits | Grade \n");
                    for(auto it1=grades[it->first].begin();it1!=grades[it->first].end();it1++)
                    {
                       // cout<<it1->first<<":"<<it1->second<<endl;
                        string name=it1->first;
                        name.pop_back();
                      // cout<<courses[name].sem<<endl;
                       if(courses[name].sem == i)
                     {
                         const char* coursenum= (it1->first).c_str();
                         const char* grade= (it1->second ).c_str();
                         const char* coursename= (courses[name].title).c_str();
                         int credit= (courses[name].C);
                        fprintf(roll,"%s",coursenum);
                        for(int sp=(it1->first).length();sp<=14;sp++)fprintf(roll," ");
                        fprintf(roll,"%s",coursename);
                        for(int sp=(courses[name].title).length();sp<=50;sp++)fprintf(roll," "); 
                        fprintf(roll," %d",credit);
                        for(int sp=0;sp<=7;sp++)fprintf(roll," "); 
                        fprintf(roll," %s\n",grade);
                         //cout << it1->first << ":" << it1->second << ":"<<courses[name].title <<":"<<courses[name].C<<'\n';
                         tot+=(10*courses[name].C);
                         studt+=(gconv[it1->second]*(courses[name].C));

                     }
                     
                     }
                     spi=(studt*10)/tot;
                     cout<<studt<<" "<<tot<<" "<<spi<<endl;
                     tspi.push_back(spi);
                     cpst+=(spi*tot);
                     cptot+=(10*tot);
                     cpi=(cpst*10)/cptot;
                     tcpi.push_back(cpi);
                
             }
             fprintf(roll,"\n");
             fprintf(roll,"     | I  |   II  | III |  IV | V | VI | VII | VIII \n");
                    fprintf(roll,"SPI   ");
                    for(int k=0;k<8;k++)
                    {
                        fprintf(roll,"%0.2lf  ",tspi[k]);
                    }
                   fprintf(roll,"\n");
                   fprintf(roll,"CPI   ");
                   for(int k=0;k<8;k++)
                    {
                        fprintf(roll,"%0.2lf  ",tcpi[k]);
                    }
                    fprintf(roll,"\n");
                    fprintf(roll,"\n");
         
         
         fclose(roll);

     }
     }  
