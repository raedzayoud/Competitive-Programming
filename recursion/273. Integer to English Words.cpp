class Solution
{
public:
    // d = {
    //     0 : "Zero",
    //     1 : "One",
    //     2 : "Two",
    //     3 : "Three",
    //     4 : "Four",
    //     5 : "Five",
    //     6 : "Six",
    //     7 : "Seven",
    //     8 : "Eight",
    //     9 : "Nine",
    //     10 : "Ten",
    //     11 : "Eleven",
    //     12 : "Twelve",
    //     13 : "Thirteen",
    //     14 : "Fourteen",
    //     15 : "Fifteen",
    //     16 : "Sixteen",
    //     17 : "Seventeen",
    //     18 : "Eighteen",
    //     19 : "Nineteen",
    //     20 : "Twenty",
    //     30 : "Thirty",
    //     40 : "Forty",
    //     50 : "Fifty",
    //     60 : "Sixty",
    //     70 : "Seventy",
    //     80 : "Eighty",
    //     90 : "Ninety",
    //     100 : "Hundred",
    //     1000 : "Thousand",
    //     1000000 : "Million",
    //     1000000000 : "Billion"
    // } string
    std::map<int, std::string> d = {{1, "One"},
                                    {2, "Two"},
                                    {3, "Three"},
                                    {4, "Four"},
                                    {5, "Five"},
                                    {6, "Six"},
                                    {7, "Seven"},
                                    {8, "Eight"},
                                    {9, "Nine"},
                                    {10, "Ten"},
                                    {11, "Eleven"},
                                    {12, "Twelve"},
                                    {13, "Thirteen"},
                                    {14, "Fourteen"},
                                    {15, "Fifteen"},
                                    {16, "Sixteen"},
                                    {17, "Seventeen"},
                                    {18, "Eighteen"},
                                    {19, "Nineteen"},
                                    {20, "Twenty"},
                                    {30, "Thirty"},
                                    {40, "Forty"},
                                    {50, "Fifty"},
                                    {60, "Sixty"},
                                    {70, "Seventy"},
                                    {80, "Eighty"},
                                    {90, "Ninety"},
                                    {100, "Hundred"},
                                    {1000, "Thousand"},
                                    {1000000, "Million"},
                                    {1000000000, "Billion"}};
    string backtrack(int num)
    {
        if (num == 0)
            return "";
        if (num <= 20)
            return d[num];
        if (num < 100)
        {
            return d[num - num % 10] +
                   (num % 10 ? " " + backtrack(num % 10) : "");
        }
        if (num < 1000)
        {
            return backtrack(num / 100) + " Hundred" +
                   (num % 100 ? " " + backtrack(num % 100) : "");
        }
        if (num < 1000000)
        {
            return backtrack(num / 1000) + " Thousand" +
                   (num % 1000 ? " " + backtrack(num % 1000) : "");
        }
        if (num < 1000000000)
        {
            return backtrack(num / 1000000) + " Million" +
                   (num % 1000000 ? " " + backtrack(num % 1000000) : "");
        }
        return backtrack(num / 1000000000) + " Billion" +
               (num % 1000000000 ? " " + backtrack(num % 1000000000) : "");
    }

    string numberToWords(int num)
    {
        if (num == 0)
        {
            return "Zero";
        }
        return backtrack(num);
    }
};