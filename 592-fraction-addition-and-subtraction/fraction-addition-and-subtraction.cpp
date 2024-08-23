class Solution {
public:
    struct FRACTION
    {
        int numerator;
        int denominator;

        FRACTION(int x = 0)
        {
            this->numerator = x;
            this->denominator = 1;
        }

    };
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }

    void simplify(FRACTION& p)
    {
        int g = gcd(abs(p.numerator), abs(p.denominator));
        // int sign = (double(p.tu) / double(p.mau) >= 0) ? 1 : -1;

        p.numerator = p.numerator  / g ;
        p.denominator = p.denominator / g;
    }

    FRACTION addF(FRACTION a, FRACTION b)
    {
        FRACTION p;
        p.numerator = a.numerator * b.denominator + b.numerator * a.denominator; // tran so
        p.denominator = a.denominator * b.denominator;

        simplify(p);

        return p;
    }
    string fractionAddition(string expression) {
        queue<int> sign;
        string ans;
        FRACTION sum; 
        if (expression[0] == '-')
        {
            expression[0] = '0';
            sign.push(-1);
        }
        else
            sign.push(1);
        int size = expression.size();
        for (int i = 0; i < size; i++)
            if (expression[i] == '+' || expression[i] == '-')
            {
                if (expression[i] == '+')
                    sign.push(1);
                else
                    sign.push(-1);
                expression[i] = ',';
            }
        stringstream s(expression);
        while (sign.size() > 0)
        {
            string num, denom;
            getline(s, num, '/');
            getline(s, denom, ',');
            FRACTION tmpFraq;
            tmpFraq.numerator = stoi(num) * sign.front();
            sign.pop();
            tmpFraq.denominator = stoi(denom);
            simplify(tmpFraq);
            sum = addF(sum, tmpFraq);
        }
        ans = to_string(sum.numerator) + "/" + to_string(sum.denominator);
        return ans;
    }
};