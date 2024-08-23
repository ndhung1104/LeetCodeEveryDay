class Solution {
public:
    struct PHANSO
    {
        int tu;
        int mau;

        PHANSO(int x = 0)
        {
            this->tu = x;
            this->mau = 1;
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

    void rutGon(PHANSO& p)
    {
        int g = gcd(abs(p.tu), abs(p.mau));
        // int sign = (double(p.tu) / double(p.mau) >= 0) ? 1 : -1;

        p.tu = p.tu / g ;
        p.mau = p.mau / g;
    }

    PHANSO addPS(PHANSO a, PHANSO b)
    {
        PHANSO p;
        p.tu = a.tu * b.mau + b.tu * a.mau; // tran so
        p.mau = a.mau * b.mau;

        rutGon(p);

        return p;
    }
    string fractionAddition(string expression) {
        queue<int> sign;
        string ans;
        PHANSO sum; 
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
        // cout << expression << endl;
        while (sign.size() > 0)
        {
            string num, denom;
            getline(s, num, '/');
            getline(s, denom, ',');
            PHANSO tmpFraq;
            tmpFraq.tu = stoi(num) * sign.front();
            sign.pop();
            tmpFraq.mau = stoi(denom);
            // cout << tmpFraq.tu << "/" << tmpFraq.mau << endl;
            rutGon(tmpFraq);
            // cout << tmpFraq.tu << "/" << tmpFraq.mau << endl;
            sum = addPS(sum, tmpFraq);
            cout << sum.tu << "/" << sum.mau << endl;
        }
        ans = to_string(sum.tu) + "/" + to_string(sum.mau);
        return ans;
    }
};