//The four adjacent digits in the 1000-digit number
//that have the greatest product are 9 × 9 × 8 × 9 = 5832.
//Find the thirteen adjacent digits in the 1000-digit number that have
//the greatest product. What is the value of this product?

//number is
//substr(start,end)-substracts a portion of a string (line)
//stoi(string,nullptr,10-for decimal) itconverts string
//(the part of the line) to integer
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
using namespace std;
pair<string,int> biggestNumberInLine(string line)
{
    string linePart,biggestNumber;
    int digits,div=10,sum=1,biggestSum=0;
    for (int i=0;i<line.size()-4;i++)
    {
        linePart=line.substr(i,4);//substracting part of the line
        digits=stoi(linePart,nullptr);//converting it to integer
        for (int n=0;n<=4;n++)
        {
            sum=sum*(digits%div);//multiplying the sum by the last digit
            digits=digits/10;//cutting of the last digit
            if (sum>biggestSum)
            {
                biggestSum=sum;
                biggestNumber=linePart;
            }
        }
        sum=1;
    }
    pair <string,int> factor ("biggestNumber",biggestSum);
    return factor;
}
int main()
{
    fstream numberFile;
    string line;
    numberFile.open("Number.txt");
    if (numberFile.good()==true)
    {
        for (int i=0;i<20;i++)
        {
        getline(numberFile,line);
        biggestNumberInLine(line);
        }
    }
    else
    {
        cout << "Error: File is not opening";
    }
    numberFile.close();
    return 0;
}
