class point{
    private:
        double x,y;
    public:
        void setx(double);
        void sety(double);
        double getx(){return x;}
        double gety(){return y;}
};

void point::setx(double X){x=X;}
void point::sety(double Y){y=Y;}

class point3d: public point{
    double z;
    public:
    void setz(double Z){z=Z;}
    double getz(){return z;}
};


