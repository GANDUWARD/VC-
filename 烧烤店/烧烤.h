class barbecue 
{
  public:
      char name[20];
      char* Initname(char name[]);
      int benifit;
      int Initbenifit(int benifit);
      void print(char name[], int benifit);
};
char* barbecue::Initname(char name[])
{
    std::cin >> name;
    return name;
}
int barbecue::Initbenifit(int benifit)
{
    std::cin >> benifit;
    return benifit;
}
void barbecue::print(char name[], int benifit)
{
    std::cout << name << "\t" << benifit << "Ԫ" << std::endl;
}
