class Spreadsheet {
public:
    unordered_map<string,int>mp;

    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell]=0;
    }
    
    int getValue(string formula) {
        int n = formula.length();
        string x ="",y="";
        bool first  = false,second = false;
        int i=1;
        while(i<n and formula[i]!='+'){
            if(formula[i]>='A' and formula[i]<='Z') first = true;
            x+=formula[i];
            i++;
        }
        i++;
        while(i<n){
            if(formula[i]>='A' and formula[i]<='Z') second = true;
            y+= formula[i];
            i++;
        }
        int num1,num2;
        if(first) num1=mp[x];
        else num1=stoi(x);
        if(second) num2= mp[y];
        else num2 = stoi(y);
        return num1+num2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */