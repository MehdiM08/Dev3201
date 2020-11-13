#include<iostream>
#include<cstring>
#include<fstream>


using namespace std; 



unsigned long ToULong(string chaine) // Convertir un string "To" un "ULong (unsigned long).

{

	unsigned long resultat = 0;

	for (int i = 0; i < chaine.length(); i++)

		resultat = resultat * 10 + ((int)chaine[i] - (int)('0'));

	return resultat;

}


string toUpperFunction(string str)
{
    locale loc; 
    for(int i = 0; i<str.length(); i++)
    {
        str[i] = toupper(str[i], loc); 
    }
    return str;
}
bool conditionThenCheck(string str)
{
    string then = "THEN";
    for(int i =0; i<str.length(); i++)
    {
        if(str[i]!=then[i])return false; 
    }
    return true;
}
bool conditionIfCheck(string str)
{
    string IF = "IF";
    for(int i =0; i<str.length(); i++)
    {
        if(str[i]!=IF[i])return false; 
    }
    return true;
}

bool GOTOCheck(string str)
{
    string GO = "GO";
    for(int i =0; i<str.length(); i++)
    {
        if(str[i]!=GO[i])return false; 
    }
    return true;
}


int main(){

int indexE=0, j=0, n=0, z=0,i=0, MUXindex = 1, indexCond =0, indexDum=0, indexBr=2, indexDum2=0, nOfLines=0;
string nomDuFichier1, wordRead, wordRead2, dummy[8], dummyJeton, dummy2[8], dummyJeton2, dummy3[8], dummyJeton3, TabInstruction[25],TabInstruction2[25],TabInstruction3[25], TabEtiquette[25], tabCommentaires[25], MUX[25], MUXin[25], TabConditionIndex[25], branchement[25];
string TabInstructionConnue[9] = {"CLEAR", "LOAD", "ADD", "SUB", "AND", "XOR", "ASR", "DEC", "INC"};
cout<<"Veuillez entrer le nom du fichier contenant le programme: "<<endl;
cin>>nomDuFichier1;


int a=0;
    string nomDuFichier2, instru, tabC[25], tabInC[25], tabInstruction[25], jeton; 

    cout<<"Veuillez inscrire le nom du fichier contenant les instructions: "<<endl;
    cin>>nomDuFichier2;

    ifstream lectureIns; 
    lectureIns.open(nomDuFichier2, ios::in); 

       while(getline(lectureIns, instru))
       {
        int l =0;
        while(l<instru.length())
        {
            while(instru[l] != '=')
          {   
              while(instru[l]==' ')l++;
              jeton = instru[l];
              tabC[a] += toUpperFunction(jeton);
                l++;
                while(instru[l]==' ')l++;
            }
            if(instru[l] == '=') 
            {
                l++;
                while(instru[l]==' ')l++;
                while(instru[l] != ':') 
                {jeton = instru[l];
                    tabInC[a]+= toUpperFunction(jeton);
                l++;
                while(instru[l]==' ')l++;
                }
            }    
            if(instru[l] == ':')
            {
                l++;
                while(instru[l]==' ')l++;
                while(instru[l] != ';') 
                {jeton = instru[l];
                tabInstruction[a]+= toUpperFunction(jeton);
                l++;
                while(instru[l]==' ')l++;
                }
            }    
            if(instru[l] == ';')
            break;   
        }

        a++;
}

for(int time =0 ; time<a; time++)
{
    cout<<"'"<<tabC[time]<<"' '"<<tabInC[time]<<"' '"<<tabInstruction[time]<<"'"<<endl;

}

lectureIns.close();



ifstream lecture;												
lecture.open(nomDuFichier1, ios::in);
    
            while(j<50)
            {
            lecture>>wordRead;
            wordRead = toUpperFunction(wordRead);
            if(wordRead[0]=='$')
            {
                TabEtiquette[indexE] = wordRead;
            }
            else
            {
                
                
                for(int l =0 ;l<9; l++)
                {
                    wordRead = toUpperFunction(wordRead);
                    if(wordRead == TabInstructionConnue[l])
                    {
                        indexE++;
                        lecture>>wordRead2;

                                    if(wordRead2[0]!='!' && wordRead2[0]!=';')
                                    {
                                                            wordRead2 = toUpperFunction(wordRead2);
                                                            TabInstruction[n] = wordRead + wordRead2[0];
                                                            lecture>>wordRead2; 
                                    }
                                    else
                                    {
                                                            TabInstruction[n]=wordRead;
                                                            wordRead = wordRead2;
                                    }
                        wordRead2 = toUpperFunction(wordRead2);
                        nOfLines++;
                        if(wordRead2[0]=='!')
                        {
                            lecture>>wordRead2>>wordRead;
                            wordRead=toUpperFunction(wordRead);
                            wordRead2=toUpperFunction(wordRead2);
                                    if(wordRead[0]!='!' && wordRead[0]!=';')
                                    {
                                                            TabInstruction2[n]=wordRead2+ wordRead[0];
                                                            lecture>>wordRead;
                                                            wordRead = toUpperFunction(wordRead);
                                    }
                                    else
                                    {
                                                            TabInstruction2[n]=wordRead2;
                                    }

                            
                            if(wordRead[0]=='!')
                            {
                            lecture>>wordRead>>wordRead2;
                            wordRead=toUpperFunction(wordRead);
                            wordRead2=toUpperFunction(wordRead2);
                                    if(wordRead2[0]!='!' && wordRead2[0]!=';')
                                    {
                                                            TabInstruction3[n]=wordRead+ wordRead2[0];
                                                            wordRead = toUpperFunction(wordRead);
                                    }
                                    else
                                    {
                                                            TabInstruction3[n]=wordRead;
                                    }
                            }
                            lecture>>wordRead;
                        }
                        n++;
                       
                    }
                }
    
                for(int k =0; k<wordRead.length();k++)
                {
                    if(wordRead[k]=='%')
                    {
                        TabInstruction[n]=wordRead;
                        n++;
                        nOfLines++;
                        indexE++;
                    }
                }
    
                 for(int k=0; k<wordRead.length(); k++)
                {
                    if(wordRead[k] == ';')
                {
                    getline(lecture, wordRead); 
                    tabCommentaires[z] = wordRead;
                    z++;
                    break;
                }
    
                }


    
                if(GOTOCheck(wordRead))
                {
                        lecture>>wordRead>>wordRead2; 
                        wordRead2 = toUpperFunction(wordRead2); 
                        indexE++;
    
                      for(int k=0; k<wordRead2.length(); k++)
                    {
                        if(wordRead2[k] == ';')
                        {
                            getline(lecture, wordRead); 
                            tabCommentaires[z] = wordRead;
                            z++;
                           break;
                        }
                        else
                            {
                            dummy2[indexDum2]+=wordRead2[k];
                            }
    
                    }
                        dummyJeton2 = dummy2[indexDum2];
    
                        dummyJeton2 = toUpperFunction(dummyJeton2);
                        branchement[n]= dummyJeton2;
                        n++;
                        indexDum2++;
                        nOfLines++;
                }//IF END


    
                if(conditionIfCheck(wordRead))
                {
                    lecture>>wordRead; 
                    wordRead = toUpperFunction(wordRead);
                    MUX[MUXindex]= wordRead;
                    MUXin[n]=wordRead;
                    MUXindex++;
                    indexE++;
    
                    lecture>>wordRead;
                    wordRead = toUpperFunction(wordRead);
                        if(conditionThenCheck(wordRead))
                        {
                            lecture>>wordRead;
    
    
                            for(int k=0; k<wordRead.length(); k++)
                            {
                                    if(wordRead[k] == ';')
                                    {
                                        getline(lecture, wordRead); 
                                        tabCommentaires[z] = wordRead;
                                        nOfLines++;
                                        break;
                                    }
                                    else
                                        {
                                            dummy[indexDum]+=wordRead[k];
                                        }
    
                            }
                            dummyJeton = dummy[indexDum];
    
                            dummyJeton = toUpperFunction(dummyJeton);
                            TabConditionIndex[n]= dummyJeton;
                            indexCond++;
                            z++;
                            indexDum++;
                            n++;
                        }
                }
            }
            j++;
        }


/*
        for(int op=0; op<=nOfLines; op++)
        {
           cout<<" "<<op<<" "<<TabEtiquette[op]<<" "<<TabInstruction[op]<<" "<<TabInstruction2[op]<<" "<<TabInstruction3[op]<<" '"<<MUXin[op]<<"' "<<TabConditionIndex[op]<<" "<<branchement[op]<<" "<<tabCommentaires[op]<<endl;
        }
*/

lecture.close();

string nomDuFichier3, CTFU, CTFU2, CTFUIN, CTFUIN2, tableauSortie[14];
int testInt, testInt2, testIntIN, testIntIN2, arr[5];

for(int h =0 ; h<14; h++)
{tableauSortie[h]="0";}

cout<<"Entrez le nom du fichier de sortie: "<<endl;
cin>>nomDuFichier3;

ofstream ecriture;												
ecriture.open(nomDuFichier3, ios::out);
        string dummyJetonTabC, dummyJetonTabInC;
        ecriture<<"Adresses,"<<"Mot de Controle,";
        for(int q =0; q<=15; q++)
        {ecriture<<",";}
        ecriture<<"commentaires"<<endl;
        ecriture<<","<<"Condition selectionnee (MUX),"<<"Adresse de branchement,"<<"Fonction de controle,C0,C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11,C12,C13"<<endl;

        for(int oper =0; oper<=nOfLines; oper++)
        {
                    for(int h =0 ; h<14; h++)
                    {tableauSortie[h]="0";}


                    if(oper!=0)
                    {
                        int Toper = oper;
                    for(i=0; Toper>0; i++)    
                    {    
                    arr[i]=Toper%2;    
                    Toper= Toper/2;  
                    }    
                    for(i=i-1 ;i>=0 ;i--)    
                    {    
                    ecriture<<arr[i];    
                    }    
                    }else
                    {
                        ecriture<<oper;
                    }


            ecriture<<",";
            if(TabInstruction[oper]!="")
            {
                for(int i =0; i<14; i++)
                {
                    if(TabInstruction[oper]==tabInstruction[i])
                    {
                        dummyJetonTabC = tabC[i];
                        dummyJetonTabInC = tabInC[i];
                        if(dummyJetonTabC.length()>2)
                        {
                           CTFU = dummyJetonTabC[1]; 
                           testInt = ToULong(CTFU);
                           CTFU2 = dummyJetonTabC[3];
                           testInt2 = ToULong(CTFU2);
                           CTFUIN = dummyJetonTabInC[0];
                           testIntIN = ToULong(CTFUIN);
                           CTFUIN2 = dummyJetonTabInC[1];
                           testIntIN2 = ToULong(CTFUIN2);
                            for(int k = 0; k<14; k++)
                            {
                                if(k==testInt)
                                {
                                    tableauSortie[k] = CTFUIN[0];
                                }
                                else if(k==testInt2)
                                {
                                    tableauSortie[k]=CTFUIN2[0];
                                }
                            }
                        }
                        else
                        {
                            CTFU = dummyJetonTabC[1];
                            testInt = ToULong(CTFU);
                            CTFUIN = dummyJetonTabInC[0];
                            testInt2 = ToULong(CTFUIN);
                            for(int k = 0; k<14; k++)
                            {
                                if(k==testInt)
                                {
                                    tableauSortie[k]=CTFUIN[0];
                                }
                                
                            }
                        }
                        
                        
                    }






                    if(TabInstruction2[oper]==tabInstruction[i])
                    {
                        dummyJetonTabC = tabC[i];
                        dummyJetonTabInC = tabInC[i];
                        if(dummyJetonTabC.length()>2)
                        {
                           CTFU = dummyJetonTabC[1]; 
                           testInt = ToULong(CTFU);
                           CTFU2 = dummyJetonTabC[3];
                           testInt2 = ToULong(CTFU2);
                           CTFUIN = dummyJetonTabInC[0];
                           testIntIN = ToULong(CTFUIN);
                           CTFUIN2 = dummyJetonTabInC[1];
                           testIntIN2 = ToULong(CTFUIN2);
                            for(int k = 0; k<14; k++)
                            {
                                if(k==testInt)
                                {
                                    tableauSortie[k] = CTFUIN[0];
                                }
                                else if(k==testInt2)
                                {
                                    tableauSortie[k]=CTFUIN2[0];
                                }
                                
                            }
                        }
                        else
                        {
                            CTFU = dummyJetonTabC[1];
                            testInt = ToULong(CTFU);
                            CTFUIN = dummyJetonTabInC[0];
                            testInt2 = ToULong(CTFUIN);
                            for(int k = 0; k<14; k++)
                            {
                                if(k==testInt)
                                {
                                    tableauSortie[k]=CTFUIN[0];
                                }
                                
                            }
                        }
                        
                        
                    }





                    if(TabInstruction3[oper]==tabInstruction[i])
                    {
                        dummyJetonTabC = tabC[i];
                        dummyJetonTabInC = tabInC[i];
                        if(dummyJetonTabC.length()>2)
                        {
                           CTFU = dummyJetonTabC[1]; 
                           testInt = ToULong(CTFU);
                           CTFU2 = dummyJetonTabC[3];
                           testInt2 = ToULong(CTFU2);
                           CTFUIN = dummyJetonTabInC[0];
                           testIntIN = ToULong(CTFUIN);
                           CTFUIN2 = dummyJetonTabInC[1];
                           testIntIN2 = ToULong(CTFUIN2);
                            for(int k = 0; k<14; k++)
                            {
                                if(k==testInt)
                                {
                                    tableauSortie[k] = CTFUIN[0];
                                }
                                else if(k==testInt2)
                                {
                                    tableauSortie[k]=CTFUIN2[0];
                                }
                            }
                        }
                        else
                        {
                            CTFU = dummyJetonTabC[1];
                            testInt = ToULong(CTFU);
                            CTFUIN = dummyJetonTabInC[0];
                            testInt2 = ToULong(CTFUIN);
                            for(int k = 0; k<14; k++)
                            {
                                if(k==testInt)
                                {
                                    tableauSortie[k]=CTFUIN[0];
                                }
                            }
                        }
                        
                        
                    }






                }
                ecriture<<"0,0,,";
                for(int p =0; p<14;p++)
                {
                    ecriture<<tableauSortie[p]<<",";
                }
                
            }
   

            /////////

           
       
             else if(MUXin[oper]!="")
            {
                  for(int h =0 ; h<14; h++)
                    {tableauSortie[h]="X";}

                int d=0, s=0;
                while(MUXin[oper]!=MUX[d])d++;
                  if(d!=0)
                    {
                    for(i=0; d>0; i++)    
                    {    
                    arr[i]=d%2;    
                    d= d/2;  
                    }    
                    for(i=i-1 ;i>=0 ;i--)    
                    {    
                    ecriture<<arr[i];    
                    }    
                    }else
                    {
                        ecriture<<d;
                    }
                ecriture<<",";
                while(TabConditionIndex[oper]!=TabEtiquette[s])s++;
                  if(s!=0)
                    {
                    for(i=0; s>0; i++)    
                    {    
                    arr[i]=s%2;    
                    s= s/2;  
                    }    
                    for(i=i-1 ;i>=0 ;i--)    
                    {    
                    ecriture<<arr[i];    
                    }    
                    }else
                    {
                        ecriture<<s;
                    }
                ecriture<<",,";
                 for(int p =0; p<14;p++)
                {
                    ecriture<<tableauSortie[p]<<",";
                }
            }

            else if(branchement[oper]!="")
            {
                int d2=1, s2=0;
                 for(int h =0 ; h<14; h++)
                    {tableauSortie[h]="X";}

                while(MUX[d2]!="")d2++;
                  if(d2!=0)
                    {
                    for(i=0; d2>0; i++)    
                    {    
                    arr[i]=d2%2;    
                    d2= d2/2;  
                    }    
                    for(i=i-1 ;i>=0 ;i--)    
                    {    
                    ecriture<<arr[i];    
                    }    
                    }else
                    {
                        ecriture<<d2;
                    }
                ecriture<<",";
                while(branchement[oper]!=TabEtiquette[s2])s2++;
                  if(s2!=0)
                    {
                    for(i=0; s2>0; i++)    
                    {    
                    arr[i]=s2%2;    
                    s2= s2/2;  
                    }    
                    for(i=i-1 ;i>=0 ;i--)    
                    {    
                    ecriture<<arr[i];    
                    }    
                    }else
                    {
                        ecriture<<s2;
                    }
                ecriture<<",,";

                for(int p =0; p<14;p++)
                {
                    ecriture<<tableauSortie[p]<<",";
                }
            }
            ecriture<<tabCommentaires[oper];
            ecriture<<endl;
           


        }


ecriture.close();

    return 0;
}