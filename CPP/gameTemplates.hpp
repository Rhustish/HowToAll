class Human{
    public:
    int age;
    Human(){
        std::cout<<"Human called"<<std::endl;
        age = 1;
    }
    void hi(){
        std::cout<<"Human hi"<<std::endl;
    }
};
class Humans : public Human{
    public:
    int age;
    Humans(){
        std::cout<<"Human called"<<std::endl;
        age = 1;
    }
    void hi(){
        std::cout<<"Human hi"<<std::endl;
    }
};
class Male : public Human , public Humans{ 
    public:
    int height;
    Male(){
        std::cout<< " Male called " << std:: endl;
        height = 1;
    }

};