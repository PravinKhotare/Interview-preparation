// strategy pattern
#include <iostream>

class IFlyStartegy
{
    public:
    virtual void fly() = 0;
};

class SlowFly : public IFlyStartegy
{
    public:
    virtual void fly()
    {
        std::cout << "flying slowly" << std::endl;
    }
};

class FastFly : public IFlyStartegy
{
    public:
    virtual void fly()
    {
        std::cout << "flying fastly" << std::endl;
    }
};

class ISwimStartegy
{
    public:
    virtual void swim() = 0;
};

class SlowSwim : public ISwimStartegy
{
    public:
    virtual void swim()
    {
        std::cout << "swiming slowly" << std::endl;
    }
};

class FastSwim : public ISwimStartegy
{
    public:
    virtual void swim()
    {
        std::cout << "swiming fastly" << std::endl;
    }
};


class Duck
{
    ISwimStartegy *_swim;
    IFlyStartegy *_fly;

    public:
    Duck(ISwimStartegy *swim = 0, IFlyStartegy *fly = 0) : _swim(swim)
                                                        , _fly(fly) 
                                                        {

                                                        }
    void fly()
    {
        _fly->fly();
    }
    void swim()
    {
        _swim->swim();
    }
};

int main()
{
    Duck NormalDuck(new FastSwim(), new SlowFly());
    std::cout << "Normal Duck : " << std::endl;
    NormalDuck.fly();
    
    NormalDuck.swim();

    Duck AbNormalDuck(new SlowSwim(), new SlowFly());
    std::cout << "AbNormal Duck : " << std::endl;
    AbNormalDuck.fly();
    AbNormalDuck.swim();

    return 0;
}