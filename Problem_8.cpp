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

pair <string, long long> biggestNumberInLine(string line)
{
    string linePart,biggestNumber;
    long long digits,sum=1,biggestSum=0;
    for (int i=0;i<line.size()-13;i++)
    {
        linePart=line.substr(i,13);//substracting part of the line
        digits=stoll(linePart,nullptr);//converting it to integer
        for (int n=0;n<=13;n++)
        {
            sum=sum*(digits%10);//multiplying the sum by the last digit
            digits=digits/10;//cutting of the last digit
            if (sum>biggestSum)
            {
                biggestSum=sum;
                biggestNumber=linePart;
            }
        }
        sum=1;
    }
    pair <string,long long> factor (biggestNumber,biggestSum);
    return factor;
}
int main()
{
    string theNumber;
    long long theSum=0;
    fstream numberFile;
    string line;
    numberFile.open("Number.txt");
    if (numberFile.good()==true)
    {
        getline(numberFile,line);
        biggestNumberInLine(line);
        if (get<1>(biggestNumberInLine(line)) > theSum)
        {
            theNumber=get<0>(biggestNumberInLine(line));
            theSum=get<1>(biggestNumberInLine(line));
        }

    }

    else
    {
        cout << "Error: File is not opening";
    }
    cout << theNumber << " = " << theSum << '\n';
    numberFile.close();
    return 0;
}
